def printUnion(S1, S2):
    unionSet = set(S1)
    unionSet.update(S2)
    print("Union Set:", end=" ")
    print(*unionSet)

def printIntersection(S1, S2):
    intersectionSet = set(S1) & set(S2)
    print("Intersection Set:", end=" ")
    print(*intersectionSet)

S1 = {1, 2, 3, 4, 5}
S2 = {0, 1, 3, 6}
printUnion(S1, S2)
printIntersection(S1, S2)

