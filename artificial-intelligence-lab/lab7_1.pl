:- dynamic(at/2).
:- dynamic(in/2).


at('Plane2','SFO').
at('Plane1','JFK').
at('Cargo2','SFO').
at('Cargo1','JFK').
plane('Plane1').
plane('Plane2').
cargo('Cargo1').
cargo('Cargo2').


load_(C,P,R) :-
\+ (in(C,P)),
at(P,R),
at(C,R),


retract(at(C,R)),
assert(in(C,P)),
assert(loade(C,P,R)).


unload_(C,P,R) :- 
\+ (at(C,R)),
at(P,R),
in(C,P),


retract(in(C,P)),
assert(at(C,R)),
assert(unload(C,P,R)).


fly_(P,D,A) :-
D \== A,
at(P,D),


retract(at(P,D)),
assert(at(P,A)),
assert(fly(P,D,A)).



do(Glist) :-
valid(Glist),
do_all(Glist,Glist).


valid(_).


do_all([G|R],Allgoals) :- 
call(G),
do_all(R,Allgoals).


do_all([G|_],Allgoals) :-
achieve(G),
call(G),
do_all(Allgoals,Allgoals).


do_all([],Allgoals).


achieve(at(P,R)) :-
\+ (at(P,R)),
plane(P),
at(P,X),
at(C,X),
cargo(C),


load_(C,P,X),
fly_(P,X,R),
unload_(C,P,R).

