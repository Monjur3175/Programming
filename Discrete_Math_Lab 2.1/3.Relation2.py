import numpy as np

# Define the matrices MR1 and MR2
MR1 = np.array([[1, 0, 1], [1, 0, 0], [0, 1, 0]])
MR2 = np.array([[1, 0, 1], [0, 1, 1], [1, 0, 0]])

# Find the union (MR1 ∪ MR2) using the logical OR operation
union = np.logical_or(MR1, MR2).astype(int)

# Find the intersection (MR1 ∩ MR2) using the logical AND operation
intersection = np.logical_and(MR1, MR2).astype(int)

# Print the results
print("Union (MR1 ∪ MR2):")
print(union)

print("\nIntersection (MR1 ∩ MR2):")
print(intersection)