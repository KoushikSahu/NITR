alive(anil).
alive(X) :- not(killed(X)).
not(killed(X)) :- alive(X).
food(apple).
food(vegetable).
food(Y) :- eats(X, Y), not(killed(X)).
likes(john,X) :- food(X).
eats(anil, peanuts).
eats(harry, X) :- eats(anil, X).
