# Define sets A and B
A = {1, 2, 3}
B = {1, 2}

# Initialize the relation R
R = []

# Find the relation (a, b) such that a ∈ A, b ∈ B and a > b
for a in A:
    for b in B:
        if a > b:
            R.append((a, b))

# Print the relation R
print("Relation R:", R)

# Define the matrix
matrix = []
for a in A:
    row = []
    for b in B:
        if (a, b) in R:
            row.append(1)
        else:
            row.append(0)
    matrix.append(row)

# Print the matrix
print("\nMatrix representation of relation R:")
for row in matrix:
    print(row)
