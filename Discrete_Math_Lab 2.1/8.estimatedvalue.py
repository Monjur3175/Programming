# Given data 
x = [4, 5, 7, 10, 11, 13] 
y = [48, 100, 294, 900, 1210, 2028] 
 
# Function to calculate divided differences 
def divided_differences(x, y): 
    n = len(x) 
    coef = y[:]  # Copy of y values 
    for j in range(1, n): 
        for i in range(n - j): 
            coef[i] = (coef[i + 1] - coef[i]) / (x[i + j] - x[i]) 
    return coef 
 
# Function to apply Newton's interpolation 
def newton_interpolation(x, coef, value): 
    n = len(coef) 
    result = coef[0] 
    term = 1.0 
 
    for i in range(1, n): 
        term *= (value - x[i - 1]) 
        result += coef[i] * term 
     
    return result 
# Compute coefficients 
coef = divided_differences(x, y) 
# Interpolating at x = 15 
f_15 = newton_interpolation(x, coef, 15) 
print(f"Estimated value of f(15) = {f_15:.6f}")