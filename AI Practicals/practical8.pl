go :-
    write('Enter the number: '),
    read(Num), nl,
    write('Enter the power: '),
    read(Pow), nl,
    power(Num, Pow, Ans),
    write('The power of the number is: '),
    write(Ans), nl.

% Base case: Any number raised to the power of 0 is 1.
power(_, 0, 1) :- !.

% Optimization: A number raised to the power of 1 is the number itself.
power(Num, 1, Num) :- !.

% Recursive case: Num^Pow = Num * Num^(Pow-1)
power(Num, Pow, Ans) :-
  Pow > 1,
  Pow1 is Pow - 1,
  power(Num, Pow1, Ans1),
  Ans is Ans1 * Num.
