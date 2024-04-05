#For any number n, write a program to list all the solutions of the equation x1 + x2 +
#x3 + ...+ xn = C, where C is a constant (C<=10) and x1, x2,x3,...,xn are nonnegative
#integers, using brute force strategy.

n=3
c=5
def fun(a,n):
    s=sum(a)
    
    if (n==1):
        print(a+[c-s])
    else:
        for i in range(0,c-s+1):
            fun(a+[i],n-1)
                       		    
fun([],n)					
	
	
