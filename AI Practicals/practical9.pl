go :-
  write('Enter the first number: '),
  read(N1), nl,
  write('Enter the second number: '),
  read(N2), nl,
  multi(N1, N2, R),
  write('The result of multiply using addition is: '),
  write(R), nl.
% Base case: Multiplying any number by 0 gives 0.
multi(_, 0, 0) :- !.

% Recursive case:
multi(N1, N2, R) :-
  N2 > 0,
  N2_1 is N2 - 1,
  multi(N1, N2_1, R1),
  R is R1 + N1.
