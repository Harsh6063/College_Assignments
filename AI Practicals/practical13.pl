go :-
   write('Enter a list: '),
   read(L),
   maxlist(L, M),
   write('Maximum number of the List is: '),
   write(M), nl.
% Base case: The maximum of a single-element list is the element itself.
maxlist([X], X).


% Recursive case: Compare the head with the max of the tail.
maxlist([H|T], M) :-
   maxlist(T, M1),
   M is max(H, M1).