#Q5... Write a Program to evaluate a polynomial function. (For example store f(x)=4n+2n+ 9 in an array and for a given value of n, say n=5, compute the value of f(n)).

def evaluate_polynomial(coefficients, n):
    result = 0#VARIABLE TO STORE RESULT

    # Iterate over the coefficients and compute the polynomial function
    for i, coefficient in  enumerate(coefficients):# enumerate() KEEPS TRACK OF EACH ELEMEMT IN LIST S
        result += coefficient * (n ** i)

    return result


# Example usage
coefficients = [9,2,4]#WRITING COFFICIENTS IN REVERSED ORDER
n = 5

result = evaluate_polynomial(coefficients, n)# CALLING THE evaluate_polynomial()
print(f"f({n}) = {result}")
