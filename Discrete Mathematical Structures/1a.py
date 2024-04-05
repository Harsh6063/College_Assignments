S1 = {1, 2, 3, 4, 5, 2, 8}
flag = False
n = int(input("Write the number to check for: "))
for num in S1:
    if n == num:
        flag = True
if flag:
    print("TRUE")
else:
    print("FALSE")
