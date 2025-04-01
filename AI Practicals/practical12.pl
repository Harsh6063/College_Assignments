go :-
  write('Enter a list: '),
  read(List),
  ( evenlength(List) -> write('The list has an even length.') ; write('The list has an odd length.') ),
  nl.

% Base case: An empty list has an even length.
evenlength([]).
% Recursive case: If a list has an even length, removing two elements keeps it even.
evenlength([_,_|T]) :- evenlength(T).

% A list with one element has an odd length.
oddlength([_]).
% Recursive case: If a list has an odd length, removing two elements keeps it odd.
oddlength([_,_|T]) :- oddlength(T).
