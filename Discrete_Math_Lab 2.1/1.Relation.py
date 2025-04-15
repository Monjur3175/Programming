def find_pairs(A, relation):
    pairs = []
    for a in A:
        for b in A:
            if relation(a, b):
                pairs.append((a, b))
    return pairs

A = {1, 2, 3, 4}

# Relation 1: (a, b) such that a divides b
def relation1(a, b):
    return b % a == 0

R1 = find_pairs(A, relation1)
print("R1: ", R1)

# Relation 2: (a, b) such that a <= b
def relation2(a, b):
    return a <= b

R2 = find_pairs(A, relation2)
print("R2: ", R2)