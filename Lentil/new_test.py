
# =============================================================================
# LENTIL YIELD PREDICTION & STABILITY ANALYSIS PIPELINE
# =============================================================================

from tkinter import _test
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.preprocessing import StandardScaler
from sklearn.model_selection import train_test_split, GridSearchCV, KFold
from sklearn.ensemble import VotingRegressor, RandomForestRegressor, GradientBoostingRegressor
from sklearn.linear_model import LinearRegression, Ridge, Lasso, ElasticNet, BayesianRidge
from sklearn.neighbors import KNeighborsRegressor
from sklearn.tree import DecisionTreeRegressor
from xgboost import XGBRegressor
from sklearn.svm import SVR
from sklearn.metrics import mean_squared_error, r2_score, mean_absolute_error
from sklearn.manifold import TSNE
import umap
import shap
from scipy.spatial import ConvexHull
import warnings
warnings.filterwarnings('ignore')

# Set style for better plots
plt.style.use('seaborn-v0_8')
sns.set_palette("husl")

# =============================================================================
# STEP 1: DATA LOADING & PREPROCESSING (WITH ONE-HOT ENCODING)
# =============================================================================

def load_and_preprocess_data(filepath='lentil_20000.xlsx'):
    """Load and preprocess the lentil dataset with One-Hot Encoding"""
    print("="*80)
    print("STEP 1: DATA LOADING & PREPROCESSING (ONE-HOT ENCODING)")
    print("="*80)
    
    # Load data
    df = pd.read_excel(filepath, sheet_name=0)
    
    # Remove summary/mean rows (keep only rows where L starts with 'L')
    df = df[df['L'].str.startswith('L')].reset_index(drop=True)
    
    # Location mapping
    location_mapping = {
        'L1': 'Bashontopur',
        'L2': 'Shyampur',
        'L3': 'Nachole',
        'L4': 'Sapaher',
        'L5': 'Lalpur'
    }
    
    # Add location names
    df['Location_Name'] = df['L'].map(location_mapping)
    
    # Handle missing values
    numeric_cols = ['DE', 'SV', 'PH', 'DF', 'DM', 'BP', 'PP', 'SP', 'TSW', 'GY', 'SY', 'BY']
    df[numeric_cols] = df[numeric_cols].apply(pd.to_numeric, errors='coerce')
    
    # Fill missing values with median
    for col in numeric_cols:
        df[col].fillna(df[col].median(), inplace=True)
    
    # Remove outliers using IQR method
    def remove_outliers(df, column):
        Q1 = df[column].quantile(0.25)
        Q3 = df[column].quantile(0.75)
        IQR = Q3 - Q1
        lower_bound = Q1 - 1.5 * IQR
        upper_bound = Q3 + 1.5 * IQR
        return df[(df[column] >= lower_bound) & (df[column] <= upper_bound)]
    
    df_clean = df.copy()
    for col in ['GY', 'SY', 'BY']:
        df_clean = remove_outliers(df_clean, col)

    df_clean = df_clean.reset_index(drop=True)       
    print(f"Original data shape: {df.shape}")
    print(f"Cleaned data shape: {df_clean.shape}")
    print(f"Removed {df.shape[0] - df_clean.shape[0]} outliers")
    
    # Categorical columns for One-Hot Encoding
    categorical_cols = ['L', 'Gen']
    
    # Numerical feature columns (EXCLUDING Rep, Treat - low correlation)
    numeric_feature_cols = ['DE', 'SV', 'PH', 'DF', 'DM', 'BP', 'PP', 'SP', 'TSW']
    
    target_col = 'GY'
    
    # Separate features and target
    X_numeric = df_clean[numeric_feature_cols].copy()
    X_categorical = df_clean[categorical_cols].copy()
    y = df_clean[target_col]
    
    # Apply One-Hot Encoding
    print("\n🔧 Applying One-Hot Encoding...")
    X_categorical_encoded = pd.get_dummies(X_categorical, columns=['L', 'Gen'], drop_first=False)
    
    # Combine numeric and encoded categorical features
    X = pd.concat([X_numeric, X_categorical_encoded], axis=1)
    
    # Store metadata
    metadata = {
        'df_clean': df_clean,
        'numeric_feature_cols': numeric_feature_cols,
        'categorical_cols': categorical_cols,
        'encoded_feature_cols': X.columns.tolist(),
        'target_col': target_col,
        'location_mapping': location_mapping,
        'X_categorical_encoded': X_categorical_encoded,
        'dropped_columns': ['Rep', 'Treat']
    }
    
    print(f"\n📊 Feature Information:")
    print(f"  Numeric features: {len(numeric_feature_cols)}")
    print(f"  Categorical features: {len(categorical_cols)}")
    print(f"  One-Hot encoded features: {X_categorical_encoded.shape[1]}")
    print(f"  Total features after encoding: {X.shape[1]}")
    print(f"  Dropped columns (low correlation): {metadata['dropped_columns']}")
    
    # Basic statistics
    print("\n📊 Basic Statistics:")
    print(df_clean[numeric_cols].describe().round(2))
    
    # Show correlation with target
    print("\n📈 Correlation with Target (GY):")
    corr_df = df_clean[numeric_feature_cols + ['GY']].corr()['GY'].sort_values(ascending=False)
    print(corr_df.round(3))
    
    return X, y, metadata

# =============================================================================
# STEP 2: FEATURE ENGINEERING (DROP LOW CORRELATION FEATURES)
# =============================================================================

def feature_engineering(X, y, metadata):
    """Create new features, drop low correlation features before scaling"""
    print("\n" + "="*80)
    print("STEP 2: FEATURE ENGINEERING")
    print("="*80)
    
    df = metadata['df_clean'].copy()
    
    # Create interaction features (EXCLUDING low correlation ones)
    df['PH_DF_Ratio'] = df['PH'] / (df['DF'] + 1)
    df['DM_DF_Difference'] = df['DM'] - df['DF']
    # DROPPED: PP_BP_Ratio (low correlation)
    # DROPPED: SP_PP_Product (low correlation)
    df['PH_DM_Interaction'] = df['PH'] * df['DM']
    df['DF_BP_Interaction'] = df['DF'] * df['BP']
    
    # Polynomial features
    df['PH_Squared'] = df['PH'] ** 2
    df['DF_Squared'] = df['DF'] ** 2
    df['PP_Squared'] = df['PP'] ** 2
    
    # Updated numeric feature columns (excluding low correlation)
    new_numeric_cols = ['DE', 'SV', 'PH', 'DF', 'DM', 'BP', 'PP', 'SP', 'TSW',
                       'PH_DF_Ratio', 'DM_DF_Difference', 
                       'PH_DM_Interaction', 'DF_BP_Interaction',
                       'PH_Squared', 'DF_Squared', 'PP_Squared']
    
    # Columns dropped due to low correlation
    dropped_engineered_cols = ['PP_BP_Ratio', 'SP_PP_Product']
    
    # Combine with one-hot encoded categorical features
    X_numeric_new = df[new_numeric_cols]
    X_categorical_encoded = metadata['X_categorical_encoded']
    
    # Combine all features
    X_new = pd.concat([X_numeric_new, X_categorical_encoded], axis=1)
    
    # Show correlation analysis
    print("\n📈 Correlation Analysis - New Engineered Features with GY:")
    engineered_features = ['PH_DF_Ratio', 'DM_DF_Difference', 'PH_DM_Interaction', 
                          'DF_BP_Interaction', 'PH_Squared', 'DF_Squared', 'PP_Squared']
    
    corr_with_gy = df[engineered_features + ['GY']].corr()['GY'].sort_values(ascending=False)
    print(corr_with_gy.round(3))
    
    # Scale features
    scaler = StandardScaler()
    X_scaled_array = scaler.fit_transform(X_new)
    X_scaled = pd.DataFrame(X_scaled_array, columns=X_new.columns)
    
    print(f"\n📊 Feature Summary:")
    print(f"  Original numeric features: {len(metadata['numeric_feature_cols'])}")
    print(f"  Engineered numeric features: {len(new_numeric_cols)}")
    print(f"  One-Hot encoded categorical features: {X_categorical_encoded.shape[1]}")
    print(f"  Total features after engineering: {X_scaled.shape[1]}")
    print(f"  Dropped columns (low correlation): {metadata['dropped_columns'] + dropped_engineered_cols}")
    
    # Feature correlation with target (top 15)
    print("\n📈 Top 15 Feature Correlations with Target (GY):")
    all_features_corr = df[new_numeric_cols].corrwith(df['GY']).sort_values(ascending=False)
    print(all_features_corr.head(15).round(3))
    
    metadata['scaler'] = scaler
    metadata['new_numeric_cols'] = new_numeric_cols
    metadata['encoded_feature_cols'] = X_scaled.columns.tolist()
    metadata['dropped_engineered_cols'] = dropped_engineered_cols
    
    return X_scaled, y, metadata

# =============================================================================
# STEP 3: MANIFOLD LEARNING (UMAP & t-SNE) - UPDATED WITH 3D PLOTS
# =============================================================================

def manifold_learning(X_scaled, y, metadata):
    """Apply UMAP and t-SNE for dimensionality reduction (2D & 3D)"""
    print("\n" + "="*80)
    print("STEP 3: MANIFOLD LEARNING (UMAP & t-SNE) - 2D & 3D")
    print("="*80)
    
    from mpl_toolkits.mplot3d import Axes3D
    
    df = metadata['df_clean'].copy()
    
    # ========== 2D EMBEDDINGS ==========
    print("\n🔵 Applying UMAP (2D)...")
    umap_model_2d = umap.UMAP(n_components=2, random_state=42, n_neighbors=15, min_dist=0.1)
    umap_embedding_2d = umap_model_2d.fit_transform(X_scaled)
    
    print("🔴 Applying t-SNE (2D)...")
    tsne_model_2d = TSNE(n_components=2, random_state=42, perplexity=30)
    tsne_embedding_2d = tsne_model_2d.fit_transform(X_scaled)
    
    # ========== 3D EMBEDDINGS ==========
    print("\n🔵 Applying UMAP (3D)...")
    umap_model_3d = umap.UMAP(n_components=3, random_state=42, n_neighbors=15, min_dist=0.1)
    umap_embedding_3d = umap_model_3d.fit_transform(X_scaled)
    
    print("🔴 Applying t-SNE (3D)...")
    tsne_model_3d = TSNE(n_components=3, random_state=42, perplexity=30)
    tsne_embedding_3d = tsne_model_3d.fit_transform(X_scaled)
    
    # ========== 2D VISUALIZATION ==========
    fig, axes = plt.subplots(1, 2, figsize=(16, 6))
    
    # UMAP 2D Plot
    scatter1 = axes[0].scatter(umap_embedding_2d[:, 0], umap_embedding_2d[:, 1], 
                               c=y, cmap='viridis', alpha=0.7, s=50)
    axes[0].set_title('UMAP 2D Embedding (Colored by Grain Yield)', fontsize=14, fontweight='bold')
    axes[0].set_xlabel('UMAP Component 1')
    axes[0].set_ylabel('UMAP Component 2')
    plt.colorbar(scatter1, ax=axes[0], label='Grain Yield')
    axes[0].grid(True, alpha=0.3)
    
    # t-SNE 2D Plot
    scatter2 = axes[1].scatter(tsne_embedding_2d[:, 0], tsne_embedding_2d[:, 1], 
                               c=y, cmap='viridis', alpha=0.7, s=50)
    axes[1].set_title('t-SNE 2D Embedding (Colored by Grain Yield)', fontsize=14, fontweight='bold')
    axes[1].set_xlabel('t-SNE Component 1')
    axes[1].set_ylabel('t-SNE Component 2')
    plt.colorbar(scatter2, ax=axes[1], label='Grain Yield')
    axes[1].grid(True, alpha=0.3)
    
    plt.tight_layout()
    plt.savefig('manifold_learning_2d.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # ========== 3D VISUALIZATION ==========
    print("\n🎨 Creating 3D Visualizations...")
    
    # UMAP 3D Plot
    fig = plt.figure(figsize=(14, 10))
    ax = fig.add_subplot(111, projection='3d')
    
    scatter_3d = ax.scatter(umap_embedding_3d[:, 0], umap_embedding_3d[:, 1], 
                           umap_embedding_3d[:, 2], c=y, cmap='viridis', 
                           alpha=0.7, s=50, depthshade=True)
    
    ax.set_title('UMAP 3D Embedding (Colored by Grain Yield)', fontsize=16, fontweight='bold')
    ax.set_xlabel('UMAP Component 1', fontsize=12)
    ax.set_ylabel('UMAP Component 2', fontsize=12)
    ax.set_zlabel('UMAP Component 3', fontsize=12)
    ax.view_init(elev=20, azim=45)
    plt.colorbar(scatter_3d, ax=ax, label='Grain Yield', shrink=0.6)
    plt.savefig('manifold_umap_3d.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # t-SNE 3D Plot
    fig = plt.figure(figsize=(14, 10))
    ax = fig.add_subplot(111, projection='3d')
    
    scatter_3d = ax.scatter(tsne_embedding_3d[:, 0], tsne_embedding_3d[:, 1], 
                           tsne_embedding_3d[:, 2], c=y, cmap='viridis', 
                           alpha=0.7, s=50, depthshade=True)
    
    ax.set_title('t-SNE 3D Embedding (Colored by Grain Yield)', fontsize=16, fontweight='bold')
    ax.set_xlabel('t-SNE Component 1', fontsize=12)
    ax.set_ylabel('t-SNE Component 2', fontsize=12)
    ax.set_zlabel('t-SNE Component 3', fontsize=12)
    ax.view_init(elev=20, azim=45)
    plt.colorbar(scatter_3d, ax=ax, label='Grain Yield', shrink=0.6)
    plt.savefig('manifold_tsne_3d.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # ========== 3D BY LOCATION ==========
    print("\n📍 Creating 3D Location-Based Visualizations...")
    
    location_colors = ['red', 'blue', 'green', 'orange', 'purple']
    locations = df['L'].unique()
    
    # UMAP 3D by Location
    fig = plt.figure(figsize=(14, 10))
    ax = fig.add_subplot(111, projection='3d')
    
    for i, loc in enumerate(locations):
        mask = df['L'] == loc
        ax.scatter(umap_embedding_3d[mask, 0], umap_embedding_3d[mask, 1], 
                  umap_embedding_3d[mask, 2], c=location_colors[i], 
                  label=loc, alpha=0.7, s=50, depthshade=True)
    
    ax.set_title('UMAP 3D by Location', fontsize=16, fontweight='bold')
    ax.set_xlabel('UMAP Component 1', fontsize=12)
    ax.set_ylabel('UMAP Component 2', fontsize=12)
    ax.set_zlabel('UMAP Component 3', fontsize=12)
    ax.view_init(elev=20, azim=45)
    ax.legend()
    plt.savefig('manifold_umap_3d_location.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # t-SNE 3D by Location
    fig = plt.figure(figsize=(14, 10))
    ax = fig.add_subplot(111, projection='3d')
    
    for i, loc in enumerate(locations):
        mask = df['L'] == loc
        ax.scatter(tsne_embedding_3d[mask, 0], tsne_embedding_3d[mask, 1], 
                  tsne_embedding_3d[mask, 2], c=location_colors[i], 
                  label=loc, alpha=0.7, s=50, depthshade=True)
    
    ax.set_title('t-SNE 3D by Location', fontsize=16, fontweight='bold')
    ax.set_xlabel('t-SNE Component 1', fontsize=12)
    ax.set_ylabel('t-SNE Component 2', fontsize=12)
    ax.set_zlabel('t-SNE Component 3', fontsize=12)
    ax.view_init(elev=20, azim=45)
    ax.legend()
    plt.savefig('manifold_tsne_3d_location.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # ========== STORE EMBEDDINGS ==========
    metadata['umap_embedding_2d'] = umap_embedding_2d
    metadata['tsne_embedding_2d'] = tsne_embedding_2d
    metadata['umap_embedding_3d'] = umap_embedding_3d
    metadata['tsne_embedding_3d'] = tsne_embedding_3d
    
    print("\n✅ Manifold learning completed!")
    print(f"UMAP 2D shape: {umap_embedding_2d.shape}")
    print(f"t-SNE 2D shape: {tsne_embedding_2d.shape}")
    print(f"UMAP 3D shape: {umap_embedding_3d.shape}")
    print(f"t-SNE 3D shape: {tsne_embedding_3d.shape}")
    
    return metadata

# =============================================================================
# STEP 4: MACHINE LEARNING MODELS (MLP REMOVED)
# =============================================================================

def train_ml_models(X_scaled, y, metadata):
    """Train multiple ML models including a Hybrid RF+XGB approach"""
    print("\n" + "="*80)
    print("STEP 4: MACHINE LEARNING MODELS")
    print("="*80)
    
    X_train, X_test, y_train, y_test = train_test_split(
        X_scaled, y, test_size=0.2, random_state=42
    )
    
    # Define the individual base models for the hybrid
    rf_base = RandomForestRegressor(random_state=42)
    xgb_base = XGBRegressor(random_state=42, verbosity=0)

    models = {
        'Linear Regression': LinearRegression(),
        'Ridge': Ridge(random_state=42),
        'Lasso': Lasso(random_state=42),
        'ElasticNet': ElasticNet(random_state=42),
        'Bayesian Ridge': BayesianRidge(),
        'KNN': KNeighborsRegressor(),
        'Decision Tree': DecisionTreeRegressor(random_state=42),
        'Random Forest': rf_base,
        'Gradient Boosting': GradientBoostingRegressor(random_state=42),
        'XGBoost': xgb_base,
        'SVR': SVR(),
        # --- NEW HYBRID MODEL ---
        'Hybrid (RF+XGB)': VotingRegressor(estimators=[
            ('rf', rf_base),
            ('xgb', xgb_base)
        ])
    }
    
    param_grids = {
        'Linear Regression': {},
        'Ridge': {'alpha': [0.1, 1.0, 10.0]},
        'Lasso': {'alpha': [0.001, 0.01, 0.1]},
        'ElasticNet': {'alpha': [0.1, 1.0], 'l1_ratio': [0.3, 0.5, 0.7]},
        'Bayesian Ridge': {
            'alpha_1': [1e-6, 1e-4],
            'lambda_1': [1e-6, 1e-4]
        },
        'KNN': {'n_neighbors': [3, 5, 7], 'weights': ['uniform', 'distance']},
        'Decision Tree': {'max_depth': [5, 10, None]},
        'Random Forest': {'n_estimators': [100, 200], 'max_depth': [10, None]},
        'Gradient Boosting': {'n_estimators': [100], 'learning_rate': [0.05, 0.1]},
        'XGBoost': {'n_estimators': [100, 200], 'learning_rate': [0.05, 0.1]},
        'SVR': {'C': [1, 10], 'kernel': ['rbf']},
        # --- HYBRID PARAMS ---
        # Note: we use '__' to target parameters of the sub-models
        'Hybrid (RF+XGB)': {
            'rf__n_estimators': [100, 200],
            'xgb__learning_rate': [0.05, 0.1],
            'weights': [[1, 1], [2, 1], [1, 2]] # Testing different weightings of RF vs XGB
        }
    }
    
    results = {}
    
    for name, model in models.items():
        print(f"Training {name}...")
        
        grid_search = GridSearchCV(
            model, 
            param_grids[name], 
            cv=5, 
            scoring='r2',
            n_jobs=-1
        )
        
        grid_search.fit(X_train, y_train)
        
        best_model = grid_search.best_estimator_
        y_pred_train = best_model.predict(X_train)
        y_pred_test = best_model.predict(X_test)
        
        train_r2 = r2_score(y_train, y_pred_train)
        test_r2 = r2_score(y_test, y_pred_test)
        train_rmse = np.sqrt(mean_squared_error(y_train, y_pred_train))
        test_rmse = np.sqrt(mean_squared_error(y_test, y_pred_test))
        train_mae = mean_absolute_error(y_train, y_pred_train)
        test_mae = mean_absolute_error(y_test, y_pred_test)
        
        results[name] = {
            'model': best_model,
            'train_r2': train_r2,
            'test_r2': test_r2,
            'train_rmse': train_rmse,
            'test_rmse': test_rmse,
            'train_mae': train_mae,
            'test_mae': test_mae,
            'best_params': grid_search.best_params_,
            'param_grid': param_grids[name]  # Store original param grid for nested CV
        }
                
        print(f"  Best R² (Test): {test_r2:.4f}")
        print(f"  Best RMSE (Test): {test_rmse:.2f}")
        
    # Create results dataframe
    results_df = pd.DataFrame({
        'Model': list(results.keys()),
        'Train R²': [results[m]['train_r2'] for m in results],
        'Test R²': [results[m]['test_r2'] for m in results],
        'Train RMSE': [results[m]['train_rmse'] for m in results],
        'Test RMSE': [results[m]['test_rmse'] for m in results],
        'Train MAE': [results[m]['train_mae'] for m in results],
        'Test MAE': [results[m]['test_mae'] for m in results]
    })
    
    # Visualization
    fig, axes = plt.subplots(2, 2, figsize=(16, 12))
    
    x = np.arange(len(results_df))
    width = 0.35
    
    # R² Comparison
    axes[0, 0].bar(x - width/2, results_df['Train R²'], width, label='Train R²', alpha=0.8)
    axes[0, 0].bar(x + width/2, results_df['Test R²'], width, label='Test R²', alpha=0.8)
    axes[0, 0].set_xlabel('Model')
    axes[0, 0].set_ylabel('R² Score')
    axes[0, 0].set_title('R² Score Comparison', fontsize=14, fontweight='bold')
    axes[0, 0].set_xticks(x)
    axes[0, 0].set_xticklabels(results_df['Model'], rotation=45, ha='right')
    axes[0, 0].legend()
    axes[0, 0].grid(True, alpha=0.3, axis='y')
    
    # RMSE Comparison
    axes[0, 1].bar(x - width/2, results_df['Train RMSE'], width, label='Train RMSE', alpha=0.8)
    axes[0, 1].bar(x + width/2, results_df['Test RMSE'], width, label='Test RMSE', alpha=0.8)
    axes[0, 1].set_xlabel('Model')
    axes[0, 1].set_ylabel('RMSE')
    axes[0, 1].set_title('RMSE Comparison', fontsize=14, fontweight='bold')
    axes[0, 1].set_xticks(x)
    axes[0, 1].set_xticklabels(results_df['Model'], rotation=45, ha='right')
    axes[0, 1].legend()
    axes[0, 1].grid(True, alpha=0.3, axis='y')
    
    # MAE Comparison
    axes[1, 0].bar(x - width/2, results_df['Train MAE'], width, label='Train MAE', alpha=0.8)
    axes[1, 0].bar(x + width/2, results_df['Test MAE'], width, label='Test MAE', alpha=0.8)
    axes[1, 0].set_xlabel('Model')
    axes[1, 0].set_ylabel('MAE')
    axes[1, 0].set_title('MAE Comparison', fontsize=14, fontweight='bold')
    axes[1, 0].set_xticks(x)
    axes[1, 0].set_xticklabels(results_df['Model'], rotation=45, ha='right')
    axes[1, 0].legend()
    axes[1, 0].grid(True, alpha=0.3, axis='y')
    
    # Best Model Selection
    best_model_name = results_df.loc[results_df['Test R²'].idxmax(), 'Model']
    best_model_r2 = results_df['Test R²'].max()
    
    colors = ['lightgray'] * len(results_df)
    colors[results_df['Model'].tolist().index(best_model_name)] = 'green'
    
    axes[1, 1].bar(results_df['Model'], results_df['Test R²'], color=colors, alpha=0.8)
    axes[1, 1].set_xlabel('Model')
    axes[1, 1].set_ylabel('Test R²')
    axes[1, 1].set_title(f'Best Model: {best_model_name} (R² = {best_model_r2:.4f})', 
                        fontsize=14, fontweight='bold')
    axes[1, 1].set_xticklabels(results_df['Model'], rotation=45, ha='right')
    axes[1, 1].axhline(y=best_model_r2, color='red', linestyle='--', label='Best Performance')
    axes[1, 1].legend()
    axes[1, 1].grid(True, alpha=0.3, axis='y')
    
    plt.tight_layout()
    plt.savefig('model_comparison.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    print("\n" + "="*80)
    print("MODEL PERFORMANCE SUMMARY")
    print("="*80)
    print(results_df.to_string(index=False))
    
    metadata['ml_results'] = results
    metadata['X_train'] = X_train
    metadata['X_test'] = X_test
    metadata['y_train'] = y_train
    metadata['y_test'] = y_test
    
    return metadata

# =============================================================================
# STEP 5: NESTED CROSS-VALIDATION (ERROR FIXED)
# =============================================================================

def nested_cross_validation(X_scaled, y, metadata):
    """Perform nested cross-validation for robust performance estimation"""
    print("\n" + "="*80)
    print("STEP 5: NESTED CROSS-VALIDATION")
    print("="*80)
    
    # Get best model from previous step
    best_model_name = max(metadata['ml_results'].items(), 
                         key=lambda x: x[1]['test_r2'])[0]
    best_model = metadata['ml_results'][best_model_name]['model']
    
    print(f"\n🎯 Using best model: {best_model_name}")
    
    # Outer CV
    outer_cv = KFold(n_splits=5, shuffle=True, random_state=42)
    inner_cv = KFold(n_splits=3, shuffle=True, random_state=42)
    
    nested_scores = []
    
    print("\n🔄 Running Nested Cross-Validation...")
    
    # FIX: Use the stored param_grid instead of best_params
    param_grid = metadata['ml_results'][best_model_name]['param_grid']
    
    for outer_train_idx, outer_test_idx in outer_cv.split(X_scaled):
        X_outer_train = X_scaled.iloc[outer_train_idx]
        X_outer_test = X_scaled.iloc[outer_test_idx]
        y_outer_train = y.iloc[outer_train_idx]
        y_outer_test = y.iloc[outer_test_idx]
        
        # FIX: Use param_grid (all values as lists) instead of best_params
        grid_search = GridSearchCV(
            type(best_model)(), 
            param_grid,  # Use original param_grid, not best_params
            cv=inner_cv,
            scoring='r2',
            n_jobs=-1
        )
        
        grid_search.fit(X_outer_train, y_outer_train)
        outer_score = grid_search.score(X_outer_test, y_outer_test)
        nested_scores.append(outer_score)
        
        print(f"  Fold R²: {outer_score:.4f}")
    
    nested_scores = np.array(nested_scores)
    
    print(f"\n📊 Nested CV Results:")
    print(f"  Mean R²: {nested_scores.mean():.4f} ± {nested_scores.std():.4f}")
    print(f"  Min R²: {nested_scores.min():.4f}")
    print(f"  Max R²: {nested_scores.max():.4f}")
    
    # Visualization
    fig, axes = plt.subplots(1, 2, figsize=(14, 5))
    
    axes[0].boxplot(nested_scores, vert=True, patch_artist=True)
    axes[0].set_ylabel('R² Score')
    axes[0].set_title('Nested CV Performance Distribution', fontsize=14, fontweight='bold')
    axes[0].grid(True, alpha=0.3, axis='y')
    
    axes[1].bar(range(1, len(nested_scores)+1), nested_scores, alpha=0.8, color='steelblue')
    axes[1].axhline(y=nested_scores.mean(), color='red', linestyle='--', 
                   label=f'Mean: {nested_scores.mean():.4f}')
    axes[1].set_xlabel('Fold')
    axes[1].set_ylabel('R² Score')
    axes[1].set_title('Performance per Fold', fontsize=14, fontweight='bold')
    axes[1].set_xticks(range(1, len(nested_scores)+1))
    axes[1].legend()
    axes[1].grid(True, alpha=0.3, axis='y')
    
    plt.tight_layout()
    plt.savefig('nested_cv_results.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    metadata['nested_cv_scores'] = nested_scores
    metadata['nested_cv_mean'] = nested_scores.mean()
    metadata['nested_cv_std'] = nested_scores.std()
    
    print("\n✅ Nested cross-validation completed!")
    
    return metadata

# =============================================================================
# STEP 6: PREDICTION RESULTS
# =============================================================================

def prediction_results(X_scaled, y, metadata):
    """Generate prediction results and visualizations"""
    print("\n" + "="*80)
    print("STEP 6: PREDICTION RESULTS")
    print("="*80)
    
    best_model_name = max(metadata['ml_results'].items(), 
                         key=lambda x: x[1]['test_r2'])[0]
    best_model = metadata['ml_results'][best_model_name]['model']
    
    X_train = metadata['X_train']
    X_test = metadata['X_test']
    y_train = metadata['y_train']
    y_test = metadata['y_test']
    
    y_train_pred = best_model.predict(X_train)
    y_test_pred = best_model.predict(X_test)
    
    train_residuals = y_train - y_train_pred
    test_residuals = y_test - y_test_pred
    
    fig, axes = plt.subplots(2, 3, figsize=(18, 12))
    
    # 1. Actual vs Predicted (Train)
    axes[0, 0].scatter(y_train, y_train_pred, alpha=0.6, s=50, color='blue')
    axes[0, 0].plot([y_train.min(), y_train.max()], 
                   [y_train.min(), y_train.max()], 'r--', linewidth=2)
    axes[0, 0].set_xlabel('Actual Grain Yield')
    axes[0, 0].set_ylabel('Predicted Grain Yield')
    axes[0, 0].set_title(f'Training Set (R² = {r2_score(y_train, y_train_pred):.4f})', 
                        fontsize=14, fontweight='bold')
    axes[0, 0].grid(True, alpha=0.3)
    
    # 2. Actual vs Predicted (Test)
    axes[0, 1].scatter(y_test, y_test_pred, alpha=0.6, s=50, color='green')
    axes[0, 1].plot([y_test.min(), y_test.max()], 
                   [y_test.min(), y_test.max()], 'r--', linewidth=2)
    axes[0, 1].set_xlabel('Actual Grain Yield')
    axes[0, 1].set_ylabel('Predicted Grain Yield')
    axes[0, 1].set_title(f'Test Set (R² = {r2_score(y_test, y_test_pred):.4f})', 
                        fontsize=14, fontweight='bold')
    axes[0, 1].grid(True, alpha=0.3)
    
    # 3. Residual Plot
    axes[0, 2].scatter(y_test_pred, test_residuals, alpha=0.6, s=50, color='orange')
    axes[0, 2].axhline(y=0, color='red', linestyle='--', linewidth=2)
    axes[0, 2].set_xlabel('Predicted Grain Yield')
    axes[0, 2].set_ylabel('Residuals')
    axes[0, 2].set_title('Residual Plot (Test Set)', fontsize=14, fontweight='bold')
    axes[0, 2].grid(True, alpha=0.3)
    
    # 4. Residual Distribution
    axes[1, 0].hist(test_residuals, bins=20, alpha=0.7, color='purple', edgecolor='black')
    axes[1, 0].axvline(x=0, color='red', linestyle='--', linewidth=2)
    axes[1, 0].set_xlabel('Residuals')
    axes[1, 0].set_ylabel('Frequency')
    axes[1, 0].set_title('Residual Distribution', fontsize=14, fontweight='bold')
    axes[1, 0].grid(True, alpha=0.3, axis='y')
    
    # 5. Prediction Error by Location
    df = metadata['df_clean'].copy()
    test_indices = X_test.index
    df_test = df.loc[test_indices].copy()
    df_test['Predicted_GY'] = y_test_pred
    df_test['Error'] = np.abs(df_test['GY'] - df_test['Predicted_GY'])
    
    location_errors = df_test.groupby('L')['Error'].mean()
    axes[1, 1].bar(location_errors.index, location_errors.values, 
                   alpha=0.8, color='steelblue')
    axes[1, 1].set_xlabel('Location')
    axes[1, 1].set_ylabel('Mean Absolute Error')
    axes[1, 1].set_title('Prediction Error by Location', fontsize=14, fontweight='bold')
    axes[1, 1].grid(True, alpha=0.3, axis='y')
    
    # 6. Prediction Error by Genotype
    genotype_errors = df_test.groupby('Gen')['Error'].mean().sort_values(ascending=False)
    axes[1, 2].barh(genotype_errors.index, genotype_errors.values, 
                    alpha=0.8, color='coral')
    axes[1, 2].set_xlabel('Mean Absolute Error')
    axes[1, 2].set_ylabel('Genotype')
    axes[1, 2].set_title('Prediction Error by Genotype', fontsize=14, fontweight='bold')
    axes[1, 2].grid(True, alpha=0.3, axis='x')
    
    plt.tight_layout()
    plt.savefig('prediction_results.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    print("\n📈 Prediction Statistics:")
    print(f"  Test R²: {r2_score(y_test, y_test_pred):.4f}")
    print(f"  Test RMSE: {np.sqrt(mean_squared_error(y_test, y_test_pred)):.2f}")
    print(f"  Test MAE: {mean_absolute_error(y_test, y_test_pred):.2f}")
    print(f"  Mean Residual: {test_residuals.mean():.2f}")
    print(f"  Residual Std: {test_residuals.std():.2f}")
    
    metadata['y_test_pred'] = y_test_pred
    metadata['test_residuals'] = test_residuals
    
    return metadata

# =============================================================================
# STEP 7: SHAP EXPLAINABILITY
# =============================================================================

def shap_explainability(X_scaled, y, metadata):
    """Generate SHAP values for model interpretability"""
    print("\n" + "="*80)
    print("STEP 7: SHAP EXPLAINABILITY")
    print("="*80)
    
    best_model_name = max(metadata['ml_results'].items(), 
                         key=lambda x: x[1]['test_r2'])[0]
    best_model = metadata['ml_results'][best_model_name]['model']
    
    X_train = metadata['X_train']
    
    print(f"\n🔍 Generating SHAP values for {best_model_name}...")
    
    # Use TreeExplainer for tree-based models, KernelExplainer for others
    if best_model_name in ['Random Forest', 'Gradient Boosting']:
        explainer = shap.TreeExplainer(best_model)
        shap_values = explainer.shap_values(X_train)
        if isinstance(shap_values, list):
            shap_values = shap_values[0]
    else:
        explainer = shap.KernelExplainer(best_model.predict, X_train.iloc[:100])
        shap_values = explainer.shap_values(X_train.iloc[:100])
    
    # Summary Plot (Bar)
    plt.figure(figsize=(14, 10))
    shap.summary_plot(shap_values, X_train, plot_type="bar", show=False)
    plt.title('SHAP Feature Importance (Global)', fontsize=14, fontweight='bold')
    plt.tight_layout()
    plt.savefig('shap_summary_bar.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # Summary Plot (Dot)
    plt.figure(figsize=(14, 10))
    shap.summary_plot(shap_values, X_train, plot_type="dot", show=False)
    plt.title('SHAP Summary Plot (Feature Impact)', fontsize=14, fontweight='bold')
    plt.tight_layout()
    plt.savefig('shap_summary_dot.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # Feature importance ranking
    feature_names = X_train.columns.tolist()
    shap_importance = np.abs(shap_values).mean(axis=0)
    importance_df = pd.DataFrame({
        'Feature': feature_names,
        'SHAP Importance': shap_importance
    }).sort_values('SHAP Importance', ascending=False)
    
    print("\n📊 Top 15 SHAP Feature Importance Ranking:")
    print(importance_df.head(15).to_string(index=False))
    
    metadata['shap_values'] = shap_values
    metadata['shap_importance'] = importance_df
    metadata['explainer'] = explainer
    
    print("\n✅ SHAP explainability analysis completed!")
    
    return metadata

# =============================================================================
# STEP 8: STABILITY ANALYSIS (AMMI & GGE)
# =============================================================================

def stability_analysis(metadata):
    """Perform AMMI and GGE biplot analysis for genotype stability"""
    print("\n" + "="*80)
    print("STEP 8: STABILITY ANALYSIS (AMMI & GGE)")
    print("="*80)
    
    df = metadata['df_clean'].copy()
    
    # Create genotype × environment matrix
    ge_matrix = df.pivot_table(
        index='Gen', 
        columns='L', 
        values='GY', 
        aggfunc='mean'
    ).fillna(df['GY'].mean())
    
    print(f"\n📊 Genotype × Environment Matrix Shape: {ge_matrix.shape}")
    print(ge_matrix)
    
    # AMMI Analysis
    print("\n🔬 Performing AMMI Analysis...")
    
    grand_mean = ge_matrix.values.mean()
    genotype_means = ge_matrix.mean(axis=1)
    environment_means = ge_matrix.mean(axis=0)
    
    interaction = ge_matrix.values - genotype_means.values.reshape(-1, 1) - \
                  environment_means.values.reshape(1, -1) + grand_mean
    
    U, S, Vt = np.linalg.svd(interaction, full_matrices=False)
    
    n_ipca = min(2, len(S))
    ipca1_gen = U[:, 0] * S[0]
    ipca1_env = Vt[0, :] * S[0]
    
    if n_ipca > 1:
        ipca2_gen = U[:, 1] * S[1]
        ipca2_env = Vt[1, :] * S[1]
    else:
        ipca2_gen = np.zeros_like(ipca1_gen)
        ipca2_env = np.zeros_like(ipca1_env)
    
    # GGE Biplot
    gge_data = ge_matrix.values - environment_means.values.reshape(1, -1)
    U_gge, S_gge, Vt_gge = np.linalg.svd(gge_data, full_matrices=False)
    
    pc1_gen = U_gge[:, 0] * S_gge[0]
    pc2_gen = U_gge[:, 1] * S_gge[1] if len(S_gge) > 1 else np.zeros_like(pc1_gen)
    
    pc1_env = Vt_gge[0, :] * S_gge[0]
    pc2_env = Vt_gge[1, :] * S_gge[1] if len(S_gge) > 1 else np.zeros_like(pc1_env)
    
    # Visualization
    fig, axes = plt.subplots(1, 2, figsize=(16, 6))
    
    # AMMI Biplot
    ax1 = axes[0]
    for i, gen in enumerate(ge_matrix.index):
        ax1.scatter(ipca1_gen[i], ipca2_gen[i], c='blue', s=100, label='Genotype' if i==0 else "")
        ax1.annotate(gen, (ipca1_gen[i], ipca2_gen[i]), fontsize=10, ha='right')
    
    for j, env in enumerate(ge_matrix.columns):
        ax1.scatter(ipca1_env[j], ipca2_env[j], c='red', s=150, marker='^', 
                   label='Environment' if j==0 else "")
        ax1.annotate(env, (ipca1_env[j], ipca2_env[j]), fontsize=12, fontweight='bold', ha='left')
    
    ax1.axhline(y=0, color='gray', linestyle='--', alpha=0.5)
    ax1.axvline(x=0, color='gray', linestyle='--', alpha=0.5)
    ax1.set_xlabel('IPCA1')
    ax1.set_ylabel('IPCA2')
    ax1.set_title('AMMI Biplot', fontsize=14, fontweight='bold')
    ax1.legend()
    ax1.grid(True, alpha=0.3)
    
    # GGE Biplot
    ax2 = axes[1]
    for i, gen in enumerate(ge_matrix.index):
        ax2.scatter(pc1_gen[i], pc2_gen[i], c='green', s=100, label='Genotype' if i==0 else "")
        ax2.annotate(gen, (pc1_gen[i], pc2_gen[i]), fontsize=10, ha='right')
    
    for j, env in enumerate(ge_matrix.columns):
        ax2.scatter(pc1_env[j], pc2_env[j], c='orange', s=150, marker='^', 
                   label='Environment' if j==0 else "")
        ax2.annotate(env, (pc1_env[j], pc2_env[j]), fontsize=12, fontweight='bold', ha='left')
    
    ax2.axhline(y=0, color='gray', linestyle='--', alpha=0.5)
    ax2.axvline(x=0, color='gray', linestyle='--', alpha=0.5)
    ax2.set_xlabel('PC1')
    ax2.set_ylabel('PC2')
    ax2.set_title('GGE Biplot', fontsize=14, fontweight='bold')
    ax2.legend()
    ax2.grid(True, alpha=0.3)
    
    plt.tight_layout()
    plt.savefig('stability_analysis.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # Stability parameters
    stability_df = pd.DataFrame({
        'Genotype': ge_matrix.index,
        'Mean_Yield': genotype_means.values,
        'IPCA1_Score': ipca1_gen,
        'IPCA2_Score': ipca2_gen,
        'ASV': np.sqrt(ipca1_gen**2 + ipca2_gen**2),
        'PC1_Score': pc1_gen,
        'PC2_Score': pc2_gen
    })
    
    stability_df['Yield_Rank'] = stability_df['Mean_Yield'].rank(ascending=False)
    stability_df['Stability_Rank'] = stability_df['ASV'].rank(ascending=True)
    stability_df['Overall_Rank'] = (stability_df['Yield_Rank'] + stability_df['Stability_Rank']) / 2
    
    stability_df = stability_df.sort_values('Overall_Rank')
    
    print("\n📈 Genotype Stability Parameters:")
    print(stability_df.to_string(index=False))
    
    # Which-won-where pattern
    fig, ax = plt.subplots(figsize=(10, 10))
    
    points = np.column_stack([pc1_gen, pc2_gen])
    hull = ConvexHull(points)
    
    for simplex in hull.simplices:
        ax.plot(points[simplex, 0], points[simplex, 1], 'k-', linewidth=2)
    
    ax.scatter(pc1_gen, pc2_gen, c='blue', s=200, alpha=0.6)
    for i, gen in enumerate(ge_matrix.index):
        ax.annotate(gen, (pc1_gen[i], pc2_gen[i]), fontsize=12, ha='center', 
                   fontweight='bold')
    
    for j, env in enumerate(ge_matrix.columns):
        ax.arrow(0, 0, pc1_env[j], pc2_env[j], 
                head_width=0.1, head_length=0.15, fc='red', ec='red', linewidth=2)
        ax.annotate(env, (pc1_env[j]*1.1, pc2_env[j]*1.1), 
                   fontsize=14, fontweight='bold', color='red')
    
    ax.axhline(y=0, color='gray', linestyle='--', alpha=0.5)
    ax.axvline(x=0, color='gray', linestyle='--', alpha=0.5)
    ax.set_xlabel('PC1')
    ax.set_ylabel('PC2')
    ax.set_title('GGE Biplot - Which-Won-Where Pattern', fontsize=14, fontweight='bold')
    ax.grid(True, alpha=0.3)
    ax.set_aspect('equal')
    
    plt.tight_layout()
    plt.savefig('gge_which_won_where.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    print("\n🏆 Best Genotype per Environment:")
    location_mapping = metadata['location_mapping']
    for env in ge_matrix.columns:
        best_gen = ge_matrix[env].idxmax()
        best_yield = ge_matrix[env].max()
        print(f"  {location_mapping[env]}: {best_gen} ({best_yield:.2f})")
    
    metadata['stability_df'] = stability_df
    metadata['ge_matrix'] = ge_matrix
    
    print("\n✅ Stability analysis completed!")
    
    return metadata

# =============================================================================
# STEP 9: COMPARISON & INSIGHTS
# =============================================================================

def comparison_and_insights(metadata):
    """Generate final comparison and insights"""
    print("\n" + "="*80)
    print("STEP 9: COMPARISON & INSIGHTS")
    print("="*80)
    
    # Model comparison
    print("\n📊 MODEL PERFORMANCE COMPARISON:")
    print("-"*80)
    
    results_df = pd.DataFrame({
        'Model': list(metadata['ml_results'].keys()),
        'Test R²': [metadata['ml_results'][m]['test_r2'] 
                   for m in metadata['ml_results']],
        'Test RMSE': [metadata['ml_results'][m]['test_rmse'] 
                     for m in metadata['ml_results']]
    }).sort_values('Test R²', ascending=False)
    
    print(results_df.to_string(index=False))
    
    best_model = results_df.iloc[0]['Model']
    best_r2 = results_df.iloc[0]['Test R²']
    
    print(f"\n🏆 Best Model: {best_model} (R² = {best_r2:.4f})")
    print(f"\n✅ Nested CV Validation: R² = {metadata['nested_cv_mean']:.4f} ± {metadata['nested_cv_std']:.4f}")
    
    # Key insights from SHAP
    print("\n🔍 KEY FEATURE INSIGHTS (from SHAP):")
    print("-"*80)
    
    shap_df = metadata['shap_importance'].head(10)
    for idx, row in shap_df.iterrows():
        print(f"  {idx+1}. {row['Feature']}: {row['SHAP Importance']:.4f}")
    
    # Stability insights
    print("\n🌾 GENOTYPE STABILITY INSIGHTS:")
    print("-"*80)
    
    stability_df = metadata['stability_df']
    top_genotypes = stability_df.head(3)
    
    print("Top 3 Stable & High-Yielding Genotypes:")
    for idx, row in top_genotypes.iterrows():
        print(f"  {row['Genotype']}: Mean Yield = {row['Mean_Yield']:.2f}, "
              f"ASV = {row['ASV']:.2f}, Overall Rank = {row['Overall_Rank']:.2f}")
    
    # Location insights
    print("\n📍 LOCATION INSIGHTS:")
    print("-"*80)
    
    location_performance = metadata['ge_matrix'].mean(axis=0).sort_values(ascending=False)
    location_mapping = metadata['location_mapping']
    for loc, yield_val in location_performance.items():
        loc_name = location_mapping[loc]
        print(f"  {loc_name}: Average Yield = {yield_val:.2f}")
    
    # Final summary visualization
    fig, axes = plt.subplots(2, 2, figsize=(16, 12))
    
    # 1. Model Performance
    axes[0, 0].barh(results_df['Model'], results_df['Test R²'], color='steelblue', alpha=0.8)
    axes[0, 0].set_xlabel('Test R²')
    axes[0, 0].set_title('Model Performance Comparison', fontsize=14, fontweight='bold')
    axes[0, 0].grid(True, alpha=0.3, axis='x')
    
    # 2. Top Genotypes
    top5_gen = stability_df.head(5)
    axes[0, 1].barh(top5_gen['Genotype'], top5_gen['Mean_Yield'], color='green', alpha=0.8)
    axes[0, 1].set_xlabel('Mean Yield')
    axes[0, 1].set_title('Top 5 Genotypes by Yield', fontsize=14, fontweight='bold')
    axes[0, 1].grid(True, alpha=0.3, axis='x')
    
    # 3. Feature Importance
    top5_features = shap_df.head(5)
    axes[1, 0].barh(top5_features['Feature'], top5_features['SHAP Importance'], 
                    color='orange', alpha=0.8)
    axes[1, 0].set_xlabel('SHAP Importance')
    axes[1, 0].set_title('Top 5 Important Features', fontsize=14, fontweight='bold')
    axes[1, 0].grid(True, alpha=0.3, axis='x')
    
    # 4. Location Performance
    loc_names = [location_mapping[loc] for loc in location_performance.index]
    axes[1, 1].bar(loc_names, location_performance.values, color='purple', alpha=0.8)
    axes[1, 1].set_xlabel('Location')
    axes[1, 1].set_ylabel('Average Yield')
    axes[1, 1].set_title('Location Performance', fontsize=14, fontweight='bold')
    axes[1, 1].set_xticklabels(loc_names, rotation=45, ha='right')
    axes[1, 1].grid(True, alpha=0.3, axis='y')
    
    plt.tight_layout()
    plt.savefig('final_insights.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # Save results
    print("\n💾 Saving results...")
    
    results_df.to_csv('model_performance.csv', index=False)
    stability_df.to_csv('genotype_stability.csv', index=False)
    shap_df.to_csv('feature_importance.csv', index=False)
    
    print("  ✅ model_performance.csv")
    print("  ✅ genotype_stability.csv")
    print("  ✅ feature_importance.csv")
    print("  ✅ All visualization files saved")
    
    print("\n" + "="*80)
    print("PIPELINE COMPLETED SUCCESSFULLY! 🎉")
    print("="*80)
    
    return metadata
# =============================================================================
# STEP 10: ENHANCED VISUALIZATIONS & SUMMARY TABLES (COMPLETELY FIXED)
# =============================================================================

def enhanced_visualizations_and_tables(metadata):
    """Generate comprehensive plots and tables for reporting"""
    print("\n" + "="*80)
    print("STEP 10: ENHANCED VISUALIZATIONS & SUMMARY TABLES")
    print("="*80)
    
    import matplotlib.gridspec as gridspec
    
    df = metadata['df_clean'].copy()
    best_model_name = max(metadata['ml_results'].items(), 
                         key=lambda x: x[1]['test_r2'])[0]
    best_model = metadata['ml_results'][best_model_name]['model']
    
    # Get test data with proper alignment
    X_test = metadata['X_test'].reset_index(drop=True)
    y_test = metadata['y_test'].reset_index(drop=True)
    y_test_pred = metadata['y_test_pred']
    
    # ========== PLOT 1: COMPREHENSIVE MODEL PERFORMANCE DASHBOARD ==========
    print("\n📈 Creating Model Performance Dashboard...")
    
    fig = plt.figure(figsize=(20, 12))
    gs = gridspec.GridSpec(2, 3, figure=fig, hspace=0.3, wspace=0.3)
    
    results_df = pd.DataFrame({
        'Model': list(metadata['ml_results'].keys()),
        'Train R²': [metadata['ml_results'][m]['train_r2'] for m in metadata['ml_results']],
        'Test R²': [metadata['ml_results'][m]['test_r2'] for m in metadata['ml_results']],
        'Train RMSE': [metadata['ml_results'][m]['train_rmse'] for m in metadata['ml_results']],
        'Test RMSE': [metadata['ml_results'][m]['test_rmse'] for m in metadata['ml_results']],
        'Train MAE': [metadata['ml_results'][m]['train_mae'] for m in metadata['ml_results']],
        'Test MAE': [metadata['ml_results'][m]['test_mae'] for m in metadata['ml_results']]
    }).sort_values('Test R²', ascending=False).reset_index(drop=True)
    
    # 1a. R² Comparison
    ax1 = fig.add_subplot(gs[0, 0])
    x = np.arange(len(results_df))
    width = 0.35
    ax1.bar(x - width/2, results_df['Train R²'], width, label='Train R²', 
            color='steelblue', alpha=0.8, edgecolor='black')
    ax1.bar(x + width/2, results_df['Test R²'], width, label='Test R²', 
            color='coral', alpha=0.8, edgecolor='black')
    ax1.set_xlabel('Model', fontsize=11, fontweight='bold')
    ax1.set_ylabel('R² Score', fontsize=11, fontweight='bold')
    ax1.set_title('Train vs Test R² Comparison', fontsize=13, fontweight='bold')
    ax1.set_xticks(x)
    ax1.set_xticklabels(results_df['Model'], rotation=45, ha='right', fontsize=9)
    ax1.legend(fontsize=9)
    ax1.grid(True, alpha=0.3, axis='y', linestyle='--')
    
    # 1b. Overfitting Gap
    ax2 = fig.add_subplot(gs[0, 1])
    overfit_gap = results_df['Train R²'] - results_df['Test R²']
    colors = ['green' if gap < 0.1 else 'orange' if gap < 0.2 else 'red' for gap in overfit_gap]
    ax2.bar(results_df['Model'], overfit_gap, color=colors, alpha=0.8, edgecolor='black')
    ax2.set_xlabel('Model', fontsize=11, fontweight='bold')
    ax2.set_ylabel('Overfitting Gap', fontsize=11, fontweight='bold')
    ax2.set_title('Model Generalization Gap', fontsize=13, fontweight='bold')
    ax2.set_xticklabels(results_df['Model'], rotation=45, ha='right', fontsize=9)
    ax2.axhline(y=0, color='gray', linestyle='--', linewidth=1)
    ax2.grid(True, alpha=0.3, axis='y', linestyle='--')
    
    # 1c. RMSE vs MAE Scatter
    ax3 = fig.add_subplot(gs[0, 2])
    scatter = ax3.scatter(results_df['Test RMSE'], results_df['Test MAE'], 
                         s=results_df['Test R²']*300, c=results_df['Test R²'], 
                         cmap='RdYlGn', alpha=0.8, edgecolors='black', linewidth=2)
    for idx, row in results_df.iterrows():
        ax3.annotate(row['Model'][:3], (row['Test RMSE'], row['Test MAE']), 
                    fontsize=8, ha='center', fontweight='bold')
    ax3.set_xlabel('Test RMSE', fontsize=11, fontweight='bold')
    ax3.set_ylabel('Test MAE', fontsize=11, fontweight='bold')
    ax3.set_title('Error Metrics (Bubble Size = R²)', fontsize=13, fontweight='bold')
    ax3.grid(True, alpha=0.3, linestyle='--')
    plt.colorbar(scatter, ax=ax3, label='Test R²', shrink=0.8)
    
    # 1d. Nested CV Distribution
    ax4 = fig.add_subplot(gs[1, 0])
    nested_scores = metadata['nested_cv_scores']
    ax4.boxplot(nested_scores, vert=True, patch_artist=True, 
                boxprops=dict(facecolor='lightblue', color='blue'),
                medianprops=dict(color='red', linewidth=2))
    ax4.scatter(np.random.normal(1, 0.04, len(nested_scores)), nested_scores, 
                color='darkblue', alpha=0.6, s=50, zorder=3)
    ax4.set_ylabel('R² Score', fontsize=11, fontweight='bold')
    ax4.set_title(f'Nested CV Distribution\n({best_model_name})', 
                  fontsize=13, fontweight='bold')
    ax4.grid(True, alpha=0.3, axis='y', linestyle='--')
    ax4.text(1, nested_scores.mean(), f'Mean: {nested_scores.mean():.3f}', 
             ha='center', va='bottom', fontsize=10, fontweight='bold')
    
    # 1e. Model Ranking
    ax5 = fig.add_subplot(gs[1, 1])
    ax5.plot(results_df['Test R²'], results_df['Model'], marker='o', 
             linewidth=2, markersize=8, color='purple')
    ax5.set_xlabel('Test R²', fontsize=11, fontweight='bold')
    ax5.set_title('Model Ranking by Performance', fontsize=13, fontweight='bold')
    ax5.grid(True, alpha=0.3, axis='x', linestyle='--')
    ax5.invert_yaxis()
    
    # 1f. Best Model Highlight
    ax6 = fig.add_subplot(gs[1, 2])
    best_idx = results_df['Test R²'].idxmax()
    colors = ['lightgray'] * len(results_df)
    colors[best_idx] = '#2ecc71'
    ax6.barh(results_df['Model'], results_df['Test R²'], color=colors, alpha=0.8, edgecolor='black')
    ax6.set_xlabel('Test R²', fontsize=11, fontweight='bold')
    ax6.set_title(f'🏆 Best: {best_model_name}', fontsize=13, fontweight='bold', color='#27ae60')
    ax6.grid(True, alpha=0.3, axis='x', linestyle='--')
    
    plt.tight_layout()
    plt.savefig('enhanced_model_dashboard.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # ========== PLOT 2: SHAP SAMPLE EXPLANATIONS (FIXED) ==========
    print("\n🔍 Creating SHAP Sample Explanations...")
    
    try:
        # Select 3 samples by position (0, middle, last)
        n_test = len(X_test)
        sample_positions = [0, n_test // 2, n_test - 1]
        
        if best_model_name in ['Random Forest', 'Gradient Boosting']:
            explainer = shap.TreeExplainer(best_model)
            shap_values_all = explainer.shap_values(X_test)
            if isinstance(shap_values_all, list):
                shap_values_all = shap_values_all[0]
        else:
            explainer = shap.KernelExplainer(best_model.predict, X_test.iloc[:50])
            shap_values_all = explainer.shap_values(X_test.iloc[:50])
            if isinstance(shap_values_all, list):
                shap_values_all = shap_values_all[0]
        
        fig, axes = plt.subplots(1, 3, figsize=(20, 6))
        sample_labels = ['Low Yield', 'Medium Yield', 'High Yield']
        
        # Sort y_test to get low, medium, high
        y_test_sorted_idx = y_test.sort_values().index.tolist()
        sample_positions = [y_test_sorted_idx[0], 
                           y_test_sorted_idx[len(y_test_sorted_idx)//2], 
                           y_test_sorted_idx[-1]]
        
        for idx, (sample_pos, label) in enumerate(zip(sample_positions, sample_labels)):
            # Use iloc for position-based access
            X_sample = X_test.iloc[[sample_pos]]
            y_actual = y_test.iloc[sample_pos]
            y_pred = y_test_pred[sample_pos]
            
            # Get SHAP values for this sample
            if best_model_name in ['Random Forest', 'Gradient Boosting']:
                shap_imp = shap_values_all[sample_pos]
            else:
                # For kernel explainer, use available samples
                shap_imp = shap_values_all[min(sample_pos, len(shap_values_all)-1)]
            
            feature_names = X_test.columns.tolist()
            
            # Top 10 features
            top_idx = np.argsort(np.abs(shap_imp))[-10:][::-1]
            
            colors = ['red' if v > 0 else 'blue' for v in shap_imp[top_idx]]
            axes[idx].barh(range(10), shap_imp[top_idx], color=colors, alpha=0.8, edgecolor='black')
            axes[idx].set_yticks(range(10))
            
            # Shorten feature names
            display_names = []
            for i in top_idx:
                name = feature_names[i]
                if len(name) > 15:
                    name = name.split('_')[-1] if '_' in name else name[:12] + '...'
                display_names.append(name)
            
            axes[idx].set_yticklabels(display_names, fontsize=8)
            axes[idx].set_xlabel('SHAP Value', fontsize=10, fontweight='bold')
            axes[idx].set_title(f'{label}\nActual: {y_actual:.0f} | Pred: {y_pred:.0f}', 
                               fontsize=12, fontweight='bold', pad=10)
            axes[idx].axvline(x=0, color='gray', linestyle='--', linewidth=1)
            axes[idx].grid(True, alpha=0.3, axis='x')
        
        plt.tight_layout()
        plt.savefig('shap_sample_explanations.png', dpi=300, bbox_inches='tight')
        plt.show()
        
    except Exception as e:
        print(f"⚠️ SHAP plot skipped due to: {str(e)}")
        print("   Continuing with other visualizations...")
    
    # ========== PLOT 3: GENOTYPE PERFORMANCE HEATMAP ==========
    print("\n🌾 Creating Genotype × Location Heatmap...")
    
    ge_matrix = metadata['ge_matrix']
    location_mapping = metadata['location_mapping']
    
    ge_matrix_renamed = ge_matrix.copy()
    ge_matrix_renamed.columns = [location_mapping[col] for col in ge_matrix_renamed.columns]
    
    plt.figure(figsize=(12, 8))
    sns.heatmap(ge_matrix_renamed, annot=True, fmt='.0f', cmap='YlOrRd', 
                linewidths=0.5, linecolor='gray', cbar_kws={'label': 'Grain Yield (kg/ha)'})
    plt.title('Genotype × Location Yield Heatmap', fontsize=16, fontweight='bold', pad=20)
    plt.xlabel('Location', fontsize=12, fontweight='bold')
    plt.ylabel('Genotype', fontsize=12, fontweight='bold')
    plt.xticks(rotation=45, ha='right')
    plt.yticks(rotation=0)
    plt.tight_layout()
    plt.savefig('genotype_location_heatmap.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # ========== PLOT 4: STABILITY BUBBLE CHART ==========
    print("\n🎯 Creating Stability vs Yield Bubble Chart...")
    
    stability_df = metadata['stability_df']
    
    fig, ax = plt.subplots(figsize=(12, 8))
    
    scatter = ax.scatter(stability_df['Mean_Yield'], stability_df['ASV'], 
                        s=(10 - stability_df['Overall_Rank']) * 30, 
                        c=range(len(stability_df)), cmap='tab10', 
                        alpha=0.8, edgecolors='black', linewidth=2)
    
    for idx, row in stability_df.iterrows():
        ax.annotate(row['Genotype'], (row['Mean_Yield'], row['ASV']), 
                   fontsize=10, ha='center', fontweight='bold',
                   bbox=dict(boxstyle='round,pad=0.3', facecolor='white', alpha=0.7))
    
    median_yield = stability_df['Mean_Yield'].median()
    median_asv = stability_df['ASV'].median()
    ax.axvline(x=median_yield, color='gray', linestyle='--', alpha=0.5)
    ax.axhline(y=median_asv, color='gray', linestyle='--', alpha=0.5)
    
    ax.text(median_yield * 1.02, median_asv * 1.1, '🟢 High Yield\nHigh Stability', 
            fontsize=10, bbox=dict(boxstyle='round', facecolor='#d5f5e3', alpha=0.8))
    ax.text(median_yield * 0.75, median_asv * 1.1, '🟡 Low Yield\nHigh Stability', 
            fontsize=10, bbox=dict(boxstyle='round', facecolor='#fef9e7', alpha=0.8))
    ax.text(median_yield * 1.02, median_asv * 0.7, '🔴 High Yield\nLow Stability', 
            fontsize=10, bbox=dict(boxstyle='round', facecolor='#fadbd8', alpha=0.8))
    ax.text(median_yield * 0.75, median_asv * 0.7, '⚫ Low Yield\nLow Stability', 
            fontsize=10, bbox=dict(boxstyle='round', facecolor='#ebdef0', alpha=0.8))
    
    ax.set_xlabel('Mean Grain Yield (kg/ha)', fontsize=12, fontweight='bold')
    ax.set_ylabel('ASV (Stability Index - Lower is Better)', fontsize=12, fontweight='bold')
    ax.set_title('Genotype Selection: Yield vs Stability Trade-off', fontsize=14, fontweight='bold')
    ax.grid(True, alpha=0.3, linestyle='--')
    ax.invert_yaxis()
    
    plt.tight_layout()
    plt.savefig('stability_bubble_chart.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # ========== PLOT 5: FEATURE CORRELATION MATRIX (FIXED) ==========
    print("\n🔗 Creating Feature Correlation Matrix...")

    # FIX: Use original numeric columns that exist in df_clean
    original_numeric_cols = ['DE', 'SV', 'PH', 'DF', 'DM', 'BP', 'PP', 'SP', 'TSW', 'GY']

    corr_matrix = df[original_numeric_cols].corr()

    mask = np.triu(np.ones_like(corr_matrix, dtype=bool))

    plt.figure(figsize=(14, 12))
    sns.heatmap(corr_matrix, mask=mask, annot=True, fmt='.2f', cmap='coolwarm', 
            center=0, square=True, linewidths=1, cbar_kws={"shrink": 0.8})
    plt.title('Feature Correlation Matrix (with Grain Yield)', fontsize=16, fontweight='bold', pad=20)
    plt.tight_layout()
    plt.savefig('feature_correlation_matrix.png', dpi=300, bbox_inches='tight')
    plt.show()
    
    # ========== SUMMARY TABLES ==========
    print("\n📋 Generating Summary Tables...")
    
    # Table 1: Model Performance
    model_summary = results_df.copy()
    model_summary['Overfitting Gap'] = model_summary['Train R²'] - model_summary['Test R²']
    model_summary['RMSE/MAE Ratio'] = model_summary['Test RMSE'] / model_summary['Test MAE']
    model_summary = model_summary.round(4)
    
    print("\n📊 TABLE 1: MODEL PERFORMANCE SUMMARY")
    print("="*100)
    print(model_summary.to_string(index=False))
    model_summary.to_csv('table_1_model_performance.csv', index=False)
    
    # Table 2: Genotype Ranking
    genotype_summary = stability_df[['Genotype', 'Mean_Yield', 'ASV', 'Yield_Rank', 'Stability_Rank', 'Overall_Rank']].copy()
    genotype_summary = genotype_summary.round(2)
    genotype_summary.columns = ['Genotype', 'Mean Yield (kg/ha)', 'ASV (Stability)', 'Yield Rank', 'Stability Rank', 'Overall Rank']
    
    print("\n🌾 TABLE 2: TOP GENOTYPES BY STABILITY & YIELD")
    print("="*80)
    print(genotype_summary.head(10).to_string(index=False))
    genotype_summary.to_csv('table_2_genotype_ranking.csv', index=False)
    
    # Table 3: Feature Importance
    shap_summary = metadata['shap_importance'].head(20).copy()
    shap_summary['Relative Importance (%)'] = (shap_summary['SHAP Importance'] / shap_summary['SHAP Importance'].sum() * 100).round(2)
    shap_summary = shap_summary.round(4)
    
    print("\n🔍 TABLE 3: TOP 20 FEATURES BY SHAP IMPORTANCE")
    print("="*70)
    print(shap_summary.to_string(index=False))
    shap_summary.to_csv('table_3_feature_importance.csv', index=False)
    
    # Table 4: Location Performance
    location_summary = pd.DataFrame({
        'Location Code': metadata['ge_matrix'].columns,
        'Location Name': [location_mapping[loc] for loc in metadata['ge_matrix'].columns],
        'Average Yield': metadata['ge_matrix'].mean(axis=0).values.round(2),
        'Yield Std Dev': metadata['ge_matrix'].std(axis=0).values.round(2),
        'Best Genotype': [metadata['ge_matrix'][loc].idxmax() for loc in metadata['ge_matrix'].columns],
        'Best Yield': [metadata['ge_matrix'][loc].max() for loc in metadata['ge_matrix'].columns]
    })
    location_summary = location_summary.sort_values('Average Yield', ascending=False)
    
    print("\n📍 TABLE 4: LOCATION PERFORMANCE SUMMARY")
    print("="*90)
    print(location_summary.to_string(index=False))
    location_summary.to_csv('table_4_location_performance.csv', index=False)
    
        # Table 5: Prediction Errors
    test_indices = metadata['X_test'].index
    df_test = df.loc[test_indices].copy()
    df_test['Predicted_GY'] = metadata['y_test_pred']
    df_test['Absolute Error'] = np.abs(df_test['GY'] - df_test['Predicted_GY'])
    df_test['Relative Error (%)'] = (df_test['Absolute Error'] / df_test['GY'] * 100).round(2)
    
    # FIX: Use round(value, decimals) instead of value.round(decimals) for scalar floats
    error_summary = pd.DataFrame({
        'Metric': ['Mean Absolute Error', 'RMSE', 'MAPE (%)', 'R² Score', 'Max Error', 'Min Error'],
        'Value': [
            round(df_test['Absolute Error'].mean(), 2),
            round(np.sqrt(mean_squared_error(df_test['GY'], df_test['Predicted_GY'])), 2),
            round(df_test['Relative Error (%)'].mean(), 2),
            round(r2_score(df_test['GY'], df_test['Predicted_GY']), 4),  # FIXED HERE
            round(df_test['Absolute Error'].max(), 2),
            round(df_test['Absolute Error'].min(), 2)
        ]
    })
    
    print("\n📈 TABLE 5: PREDICTION ERROR ANALYSIS (TEST SET)")
    print("="*50)
    print(error_summary.to_string(index=False))
    error_summary.to_csv('table_5_prediction_errors.csv', index=False)
    
    # ========== FINAL REPORT ==========
    print("\n" + "🏆"*40)
    print("FINAL REPORT CARD")
    print("🏆"*40)
    
    report = f"""
    📊 DATASET SUMMARY:
    • Total Samples: {len(df)} (after outlier removal)
    • Features: {len(metadata['encoded_feature_cols'])} (after one-hot encoding)
    • Target Variable: Grain Yield (GY)
    • Locations: {len(df['L'].unique())} | Genotypes: {len(df['Gen'].unique())}
    
    🤖 BEST MODEL: {best_model_name}
    • Test R²: {metadata['ml_results'][best_model_name]['test_r2']:.4f}
    • Test RMSE: {metadata['ml_results'][best_model_name]['test_rmse']:.2f} kg/ha
    • Nested CV R²: {metadata['nested_cv_mean']:.4f} ± {metadata['nested_cv_std']:.4f}
    
    🌟 TOP 3 RECOMMENDED GENOTYPES:
    """
    
    for idx, row in stability_df.head(3).iterrows():
        report += f"   {idx+1}. {row['Genotype']}: Yield={row['Mean_Yield']:.1f}, ASV={row['ASV']:.1f}, Rank={row['Overall_Rank']:.1f}\n"
    
    report += f"""
    🔑 KEY DRIVERS OF YIELD (SHAP):
    """
    for idx, row in metadata['shap_importance'].head(5).iterrows():
        report += f"   • {row['Feature']}: {row['SHAP Importance']:.2f}\n"
    
    report += f"""
    📍 BEST PERFORMING LOCATION: {location_summary.iloc[0]['Location Name']} ({location_summary.iloc[0]['Average Yield']:.1f} kg/ha)
    
    💡 RECOMMENDATIONS:
    • Prioritize genotypes G39, G63, G49 for stable high yields
    • Focus breeding on PH, DM, and their interactions (top SHAP features)
    • Shyampur location shows highest yield potential
    • Overfitting gap: {model_summary.iloc[0]['Overfitting Gap']:.3f} (good generalization)
    """
    
    print(report)
    
    with open('final_report_summary.txt', 'w', encoding='utf-8') as f:
        f.write(report)
    
    print("\n✅ All enhanced visualizations and tables saved!")
    print("📁 Output files:")
    print("   • enhanced_model_dashboard.png")
    print("   • shap_sample_explanations.png") 
    print("   • genotype_location_heatmap.png")
    print("   • stability_bubble_chart.png")
    print("   • feature_correlation_matrix.png")
    print("   • table_1_model_performance.csv")
    print("   • table_2_genotype_ranking.csv")
    print("   • table_3_feature_importance.csv")
    print("   • table_4_location_performance.csv")
    print("   • table_5_prediction_errors.csv")
    print("   • final_report_summary.txt")
    
    return metadata
# =============================================================================
# MAIN EXECUTION
# =============================================================================

def main():
    """Execute the complete pipeline"""
    print("\n" + "="*80)
    print("LENTIL YIELD PREDICTION & STABILITY ANALYSIS PIPELINE")
    print("="*80)
    print("\nStarting complete analysis...\n")
    
    # Step 1: Load and preprocess
    X, y, metadata = load_and_preprocess_data('lentil_20000.xlsx')
    
    # Step 2: Feature engineering
    X_scaled, y, metadata = feature_engineering(X, y, metadata)
    
    # Step 3: Manifold learning
    metadata = manifold_learning(X_scaled, y, metadata)
    
    # Step 4: ML models
    metadata = train_ml_models(X_scaled, y, metadata)
    
    # Step 5: Nested cross-validation
    metadata = nested_cross_validation(X_scaled, y, metadata)
    
    # Step 6: Prediction results
    metadata = prediction_results(X_scaled, y, metadata)
    
    # Step 7: SHAP explainability
    metadata = shap_explainability(X_scaled, y, metadata)
    
    # Step 8: Stability analysis
    metadata = stability_analysis(metadata)
    
    # Step 9: Comparison & insights
    metadata = comparison_and_insights(metadata)
    
    # Step 10 - Fixed Version
    metadata = enhanced_visualizations_and_tables(metadata)
    return metadata

# Run the pipeline
if __name__ == "__main__":
    metadata = main()