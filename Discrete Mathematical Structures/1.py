import math

class SET:
    def __init__(self, set_elements):
        self.set_elements = set(set_elements)

    def print_union(self, other_set):
        union_set = self.set_elements.union(other_set.set_elements)
        print("Union Set:", end=" ")
        print(*union_set)

    def print_intersection(self, other_set):
        intersection_set = self.set_elements.intersection(other_set.set_elements)
        print("Intersection Set:", end=" ")
        print(*intersection_set)

    def print_difference(self, other_set):
        difference_set = self.set_elements.difference(other_set.set_elements)
        print("Difference Set:", end=" ")
        print(*difference_set)

    def print_symmetric_difference(self, other_set):
        symmetric_difference_set = self.set_elements.symmetric_difference(other_set.set_elements)
        print("Symmetric Set Difference:", end=" ")
        print(*symmetric_difference_set)

    def print_cartesian_set(self, other_set):
        print("Cartesian Product Sets:")
        for x in self.set_elements:
            for y in other_set.set_elements:
                print(x, y)
        print()

    def power_set(self):
        set_size = len(self.set_elements)
        pow_set_size = int(math.pow(2, set_size))
        counter = 0
        j = 0
        for counter in range(pow_set_size):
            for j in range(set_size):
                if (counter & (1 << j)):
                    print(list(self.set_elements)[j], end="")
            print()

    def check_subset(self, other_set):
        return self.set_elements.issubset(other_set.set_elements)

    def is_member(self, element):
        return element in self.set_elements

    def complement(self, universal_set):
        complement_set = universal_set.set_elements.difference(self.set_elements)
        return complement_set


if __name__ == "__main__":
    set_1 = SET([1, 2, 3, 4, 5])
    set_2 = SET([0, 1, 3, 6])

    print("Select the operation you want to perform:")
    print("1. Union")
    print("2. Intersection")
    print("3. Difference")
    print("4. Symmetric Difference")
    print("5. Cartesian Product")
    print("6. Power Set")
    print("7. Check Subset")
    print("8. Check Is Member")
    print("9. Complement")

    operation = int(input("Enter your choice: "))

    if operation == 1:
        set_1.print_union(set_2)
    elif operation == 2:
        set_1.print_intersection(set_2)
    elif operation == 3:
        set_1.print_difference(set_2)
    elif operation == 4:
        set_1.print_symmetric_difference(set_2)
    elif operation == 5:
        set_1.print_cartesian_set(set_2)
    elif operation == 6:
        set_1.power_set()
    elif operation == 7:
        print(set_1.check_subset(set_2))
    elif operation == 8:
        print(set_1.is_member(6))
    elif operation == 9:
        universal_set = SET(set_1.set_elements.union(set_2.set_elements))
        print(set_1.complement(universal_set))
    else:
        print("Invalid operation")
