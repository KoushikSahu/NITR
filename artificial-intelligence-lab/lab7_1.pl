action(planes,load(C,A,P), [plane(P),airport(A), cargo(C), at(P,A), at(C,A)],
		     [no(at(C,A
			   )), on(C,P)]).

action(planes,unload(C,A,P), [plane(P),airport(A), cargo(C), at(P,A), on(C,P)],
       	     [no(on(C,P)), at(C,A)]).

action(planes,fly(A1,A2,P), [isNot(A1,A2),plane(P), airport(A1), airport(A2), at(P,A1)] ,
		   [ no(at(P,A1)),at(P,A2) ]).

valid(_,[]).
valid(1,[2|_]).
valid(1,[3|_]).
valid(1,[4|_]).
valid(1,[5|_]).
valid(1,[6|_]).

valid(2,[3|_]).
valid(2,[4|_]).
valid(2,[5|_]).
valid(2,[6|_]).

valid(3,[4|_]).
valid(3,[5|_]).
valid(3,[6|_]).

valid(4,[5|_]).
valid(4,[6|_]).

valid(5,[6|_]).

initialState(planes,[isNot(jfk,sfo), isNot(sfo,jfk),at(p1,jfk),
 at(p2,sfo), at(c1,jfk), at(c2,sfo),plane(p1),plane(p2),airport(jfk),
 airport(sfo), cargo(c1), cargo(c2)]).

goalState(planes,[at(c1,sfo),at(c2,jfk)]).

satisfies(_,[]).
satisfies(L,[X|Xs]) :- member(X,L), satisfies(L,Xs).

apply(P,A,  State, New):-
        action(P,A,Pre,Eff),satisfies(State,Pre),applyEffs(Eff,State,New).

applyEffs([],State,State).
applyEffs([no(C)|Cs] ,State,St1) :- remove(C,State,St), applyEffs(Cs,St,St1).
applyEffs([C|Cs],State,St1) :-  positive(C), add(C,State,St), applyEffs(Cs,St,St1).

add(C,[],[C]).
add(C,[C|Cs],[C|Cs]) :- !.
add(C,[D|Cs],[D|Cs1]):- add(C,Cs,Cs1).

remove(_,[],[]).
remove(C,[C|Cs],Cs) :- !.
remove(C,[D|Cs],[D|Cs1]):- remove(C,Cs,Cs1).

visited(X, [Y | _]) :-  permut(X,Y),!.
visited(X, [_ | Ys]) :- visited(X,Ys).

permut(Xs,Ps) :-  sameSize(Xs,Ps), !, perm(Xs,Ps).

sameSize([],[]).
sameSize([_|Xs],[_|Ys]) :- sameSize(Xs,Ys).

perm([],[]).
perm([X|Xs], Ys) :- rem(X,Ys,Zs),perm(Xs,Zs).

rem(X,[X|Xs],Xs).
rem(X,[Y|Xs],[Y|Ys]) :-  rem(X,Xs,Ys).

notVisited(X,Ys) :-  visited(X,Ys), !, fail.
notVisited(_,_).

remove1(C,[C|Cs],Cs1) :- !, remove1(Cs,Cs1).
remove1(C,[D|Cs],[D|Cs1]):- remove1(C,Cs,Cs1).

positive(no(_)) :- !, fail.
positive(_).

applyActions(_,State,[],State,G,_,_) :- satisfies(State,G).
applyActions(P,State,[X|Xs],State1,G,N,Vs) :-
	N > 0,
	N1 is N-1 ,
	apply(P,X,State,St),
        notVisited(St,Vs),
	applyActions(P,St,Xs,State1,G,N1,[St|Vs]).

planAheadL(P,S,G,L,I,_,S1) :-  applyActions(P,S,L,S1,G,I,[S]).
planAheadL(P,S,G,L,I,MAX,S1) :-  I1 is I + 1, planAheadL(P,S,G,L,I1,MAX,S1).

myTest(L,End,Problem,Depth)
:- initialState(Problem,S),goalState(Problem,G),planAheadL(Problem,S,G,L,0,Depth, End).

myInit([plane(p),at(p,jfk),airport(jfk),airport(sfo)]).
printList([]).
printList([X|Xs]) :-writeln(X), printList(Xs).

