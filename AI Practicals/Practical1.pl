parent(pam, bob).
parent(tom, bob).
parent(tom, liz).
parent(bob, ann).
parent(bob, pat).
parent(pat, jim).
% Gender facts
female(pam).
female(liz).
female(ann).
female(pat).
male(tom).
male(bob).
male(jim).
% Offspring rule
offspring(Y, X) :-
parent(X, Y).
% Mother rule
mother(X, Y) :-
parent(X, Y),
female(X).
% Grandparent rule
grandparent(X, Z) :-
parent(X, Y),
parent(Y, Z).
% Sister rule
sister(X, Y) :-
parent(Z, X),
parent(Z, Y),
female(X),
X \= Y.
% Predecessor rule
predecessor(X, Z) :-
parent(X, Z).
predecessor(X, Z) :-
parent(X, Y),
predecessor(Y, Z).
