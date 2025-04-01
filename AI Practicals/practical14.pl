go :-
   write('Enter an element to insert: '),
   read(I),
   write('Enter the position: '),
   read(N),
   write('Enter the list: '),
   read(L),
   insert(I, N, L, R),
   write('Resultant list: '),
   write(R),
   nl.

% Base case: Insert at position 1 (head of the list)
insert(I, 1, L, [I|L]).

% Recursive case: Decrease position counter and continue inserting in the tail
insert(I, N, [H|T], [H|R]) :-
  N > 1,
  N1 is N - 1,
  insert(I, N1, T, R).
