def lagrange_interpolation(x_values, y_values, x): 
    n = len(x_values) 
    result = 0 
 
    for i in range(n): 
        term = y_values[i] 
        for j in range(n): 
            if i != j: 
                term *= (x - x_values[j]) / (x_values[i] - 
x_values[j]) 
        result += term 
 
    return result 
 
# Given data points 
x_values = [5, 6, 9, 11] 
y_values = [12, 13, 14, 16] 
x = 10  # The value to interpolate 
 
# Compute the interpolated value 
y_interpolated = lagrange_interpolation(x_values, y_values, x) 
print(f"Interpolated value at x={x} is y={y_interpolated:.4f}") 