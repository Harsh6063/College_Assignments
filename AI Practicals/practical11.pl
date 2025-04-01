go :-
  write('Enter a list: '),
  read(L),
  sumlist(L, S),
  write('The sum is: '),
  write(S), nl.

% Base case: the sum of an empty list is 0.
sumlist([], 0).

% Recursive case: sum the head of the list with the sum of the tail.
sumlist([H|T], S) :-
  sumlist(T, S1),
  S is H + S1.
