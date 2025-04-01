go :-
write('Enter the list: '),
read(L),
write('Enter the position to delete: '),
read(N),
delete_nth(N, L, R),
write('Resultant list after deletion: '),
write(R),
nl.
% Base case: Delete the first element
delete_nth(1, [_|T], T).
% Recursive case: Decrease position counter and continue deleting in the tail
delete_nth(N, [H|T], [H|R]) :-
 N > 1,
 N1 is N - 1,
 delete_nth(N1, T, R).