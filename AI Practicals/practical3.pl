go :-
 write('Enter the list: '), read(L), nl,
 my_reverse(L, R),
 write('Reversed list is: '), write(R).
my_reverse([], []).
my_reverse([H|T], R) :-
 my_reverse(T, RevT),
 append(RevT, [H], R).