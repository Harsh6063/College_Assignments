def isSubset(S, subset):
    for element in subset:
        if element not in S:
            return False
    return True

S = {1, 2, 3, 4, 5}
subset = {1, 5}
print("Is {1, 5} a subset of S?")
print("Yes" if isSubset(S, subset) else "No")
