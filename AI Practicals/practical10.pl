go :-
    write('Enter the Element: '), read(X), nl,
    write('Enter the List: '), read(L), nl,
   (memb(X, L) -> write('Element is in the list.'); write('Element is not in the list.')).
% Base case: X is the head of the list.
memb(X, [X|_]).

% Recursive case: X is in the tail of the list.
memb(X, [_|T]) :- memb(X, T).
