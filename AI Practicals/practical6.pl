go:-
   write('Enter a number: '),
   read(N),
   factorial(N, F),
   write('Factorial of this number is'),
   write(N),
   write(' is '),
   write(F),
   nl.
% Base case: factorial of 0 is 1.
factorial(0, 1).
% Recursive case: factorial(N) = N * factorial(N-1)
factorial(N, F) :-
    N > 0,
    N1 is N - 1,
    factorial(N1, F1),
    F is N * F1.
