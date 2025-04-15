def f(x): 
    return x**2 - 4*x - 10  # Given function 
 
def bisection_method(a, b, tol=1e-6): 
    if f(a) * f(b) >= 0: 
        print("Bisection method fails. The function must have opposite signs at a and b.") 
        return None 
 
    while (b - a) / 2.0 > tol: 
        c = (a + b) / 2.0 
        if f(c) == 0: 
            return c  # Found exact root 
        elif f(a) * f(c) < 0: 
            b = c  # Root lies in [a, c] 
        else: 
            a = c  # Root lies in [c, b] 
     
    return (a + b) / 2.0  # Return approximate root 
 
# Given interval 
a = -2 
b = -1.5 
 
# Find root 
root = bisection_method(a, b) 
if root is not None: 
    print(f"Approximate root in the interval [{a}, {b}]: {root:.6f}")