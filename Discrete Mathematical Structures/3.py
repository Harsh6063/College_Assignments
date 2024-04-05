def generate_permutations(digits, length, repetition=False):
    permutations = []
    if repetition:
        backtrack_with_repetition(digits, length, [], permutations)
    else:
        backtrack_without_repetition(digits, [], permutations, length)
    return permutations

def backtrack_with_repetition(digits, length, path, permutations):
    if len(path) == length:
        permutations.append(path)
    else:
        for digit in digits:
            new_path = path + [digit]
            backtrack_with_repetition(digits, length, new_path, permutations)

def backtrack_without_repetition(digits, path, permutations, length):
    if len(path) == length:
        permutations.append(path)
    else:
        for i in range(len(digits)):
            if digits[i] in path:
                continue
            new_digits = digits[:i] + digits[i+1:]
            new_path = path + [digits[i]]
            backtrack_without_repetition(new_digits, new_path, permutations, length)

digits = [1, 2, 3]
length = 3
repetition = True

permutations_with_repetition = generate_permutations(digits, length, repetition)
permutations_without_repetition = generate_permutations(digits, length, repetition=False)

print("Permutations with repetition:")
for p in permutations_with_repetition:
    print(*p)

print("\nPermutations without repetition:")
for p in permutations_without_repetition:
    print(*p)
