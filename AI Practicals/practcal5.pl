go :-
    write('Enter the first number: '), read(X),
    write('Enter the second number: '), read(Y),
    max(X, Y, M),
    write('Maximum is: '), write(M), nl.

max(X, Y, X) :- X >= Y.
max(X, Y, Y) :- Y > X.
