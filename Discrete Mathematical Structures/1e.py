def complement(S1, universalSet):
    complementSet = set()

    for x in universalSet:
        if x not in S1:
            complementSet.add(x)

    return complementSet


universalSet = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
S1 = {1, 2, 3, 4, 5}

complementSet = complement(S1, universalSet)

print("Complement Set:", end=" ")
for element in complementSet:
    print(element, end=" ")
print()
