def print_difference(S1, S2):
    difference_set = set()

    for x in S1:
        if x not in S2:
            difference_set.add(x)

    print("Difference Set:", end=" ")
    for element in difference_set:
        print(element, end=" ")
    print()


def print_symmetric_difference(S1, S2):
    symmetric_difference_set = S1.copy()

    for x in S2:
        if x in symmetric_difference_set:
            symmetric_difference_set.remove(x)
        else:
            symmetric_difference_set.add(x)

    print("Symmetric Set Difference:", end=" ")
    for element in symmetric_difference_set:
        print(element, end=" ")
    print()


if __name__ == "__main__":
    S1 = {1, 2, 3, 4, 5}
    S2 = {0, 1, 3, 6}

    print_difference(S1, S2)
    print_symmetric_difference(S1, S2)
