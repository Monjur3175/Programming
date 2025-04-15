def f(x): 
    return x**2 - x - 2  # Given function 
 
def false_position(a, b, tol=1e-6, max_iter=100): 
    if f(a) * f(b) >= 0: 
        print("Invalid interval, f(a) and f(b) must have opposite signs") 
        return None 
 
    for _ in range(max_iter): 
        # Compute the root using false position formula 
        c = (a * f(b) - b * f(a)) / (f(b) - f(a)) 
 
        if abs(f(c)) < tol: 
            return c  # Root found 
 
        if f(c) * f(a) < 0: 
            b = c  # Root lies in left subinterval 
        else: 
            a = c  # Root lies in right subinterval 
 
    print("Maximum iterations reached") 
    return c 
 
# Given range (1,3) 
root = false_position(1, 3) 
if root is not None: 
    print(f"Root found: {root:.6f}")