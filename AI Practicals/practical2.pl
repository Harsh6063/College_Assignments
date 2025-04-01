go :-
     write('Enter first list: '), read(L1), nl,
     write('Enter second list: '), read(L2), nl,
     conc(L1, L2, L3),
     write('Concatenated list is: '), write(L3).

conc([], L2, L2).

conc([H|T], L2, [H|L3]) :- conc(T, L2, L3).
