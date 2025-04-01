go :-
write('Enter the term number: '),
read(N),
fib(N, T),
write('The '),
write(N),
write('th Fibonacci number is '),
write(T),
nl.
% Base cases
fib(0, 0).
fib(1, 1).
% Recursive case: fib(N) = fib(N-1) + fib(N-2)
fib(N, T) :-
N > 1,
N1 is N - 1,
N2 is N - 2,
fib(N1, T1),
fib(N2, T2),
T is T1 + T2.