block(a). 
block(b). 
block(c).

place(p). 
place(q). 
place(r).

solve(Initial, Final, Plan) :- strips(Initial, Final, Plan).

strips(Initial, Final, Plan) :- strips(Initial, Final, [Initial], Plan).

strips(Initial, Final, Visited, Plan) :- 
    deepening_strips(1, Initial, Final, Visited, Plan).

deepening_strips(Bound, Initial, Final, Visited, Plan) :-
    bounded_strips(Bound, Initial, Final, Visited, Plan).
deepening_strips(Bound, Initial, Final, Visited, Plan) :-
	succ(Bound, Successor),
    deepening_strips(Successor, Initial, Final, Visited, Plan).

bounded_strips(_, Final, Final, _, []).
bounded_strips(Bound, Initial, Final, Visited, [Action|Actions]) :-
    succ(Predecessor, Bound),
    action(Initial, Action),
    perform(Initial, Action, Intermediate),
    \+ member(Intermediate, Visited),
    bounded_strips(Predecessor, Intermediate, Final, [Intermediate|Visited], Actions).

action(State, move(Block, Destination)) :-
    block(Block),
    \+ Block == Destination,
    free(State, Block),
    free(State, Destination).
       
free(State, Thing) :-
    thing(Thing),
    \+ member(on(_, Thing), State).

thing(Block) :- block(Block).
thing(Place) :- place(Place).

perform(Source, move(Block, Destination), Target) :-
    substitute(on(Block, _), Source, on(Block, Destination), Target).

substitute(_, [], _, []).
substitute(A, [A|As], B, [B|Bs]) :-
    substitute(A, As, B, Bs), !.
substitute(A, [X|As], B, [X|Bs]) :-
    substitute(A, As, B, Bs).

