def print_cartesian_set(S1, S2):
    print("Cartesian Product Sets:")
    for x in S1:
        for y in S2:
            print(x, y)
    print()
    

if __name__ == "__main__":
    S1 = {1, 2, 3, 4, 5}
    S2 = {0, 1, 3, 6}

    print_cartesian_set(S1, S2)
