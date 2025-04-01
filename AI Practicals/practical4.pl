go :-
     write('Enter the first number: '), read(X),
     write('Enter the second number: '), read(Y),
     sum(X, Y, S),
     write('Sum of these two numbers are: '), write(S), nl.
sum(X, Y, S) :- S is X + Y.