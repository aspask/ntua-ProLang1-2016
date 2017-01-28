fair_parts(File,R) :- read_and_return(File, N, Weights), max_n_sum(Weights,Min,Max), solve(Min,Max,Lim,Weights,N), my_break(Weights,Lim,N,R), !.
%% fair(File,Lim) :- read_and_return(File, N, Weights), max_n_sum(Weights,Min,Max), solve(Min,Max,Lim,Weights,N).

read_and_return(File, N, Weights) :-
    open(File, read, Stream),
    read_line(Stream, [M, N]),
    read_line(Stream, Weights),
    length(Weights, L),
    ( L =:= M -> close(Stream)  %% just a check for for sanity
    ; format("Error: expected to read ~d weights but found ~d", [M, L]),
      close(Stream), fail
    ).

read_line(Stream, List) :-
    read_line_to_codes(Stream, Line),
    atom_codes(A, Line),
    atomic_list_concat(As, ' ', A),
    maplist(atom_number, As, List).

max_n_sum([X],X,X).
max_n_sum([X|Xs],X,S):- max_n_sum(Xs,Y,S1), X >=Y, S is S1+X.
max_n_sum([X|Xs],N,S):- max_n_sum(Xs,N,S1), N > X, S is S1+X.

solve(M,M,M,_,_).
solve(Min,Max,X,L,Count) :- Min<Max, solve1(Min,Max,X,L,Count).

solve1(Min,Max,X,L,Count) :- Middle is ((Min+Max)//2), Middle1 is (Middle-1), \+ valid(L,Middle1,Count), \+ valid(L,Middle,Count), solveg(Min,Middle,Max,X,L,Count).
solve1(Min,Max,X,L,Count) :- Middle is (Min+Max)//2, Middle1 is Middle-1, \+ valid(L,Middle1,Count), valid(L,Middle,Count), solve(Middle,Middle,X,L,Count).
solve1(Min,Max,X,L,Count) :- Middle is (Min+Max)//2, Middle1 is Middle-1, valid(L,Middle1,Count), valid(L,Middle,Count), solve(Min,Middle,X,L,Count).

solveg(Middle,Middle,Max,X,L,Count) :- Middle1 is Middle+1, solve(Middle1,Max,X,L,Count).
solveg(Min,Middle,Max,X,L,Count) :- Min\=Middle, solve(Middle,Max,X,L,Count).


split(L,0,[],L).
split([X|Xs],N,[X|Ys],Zs) :- N > 0, N1 is N - 1, split(Xs,N1,Ys,Zs).





break([],_,0,[]) :- !.
%% break(L,Max,Count,R) :- restof(L,Max,L1), length(L1,Len), Len<=Count, break1(L,R).
break(L,Max,Count,[X|Xs]) :- restof(L,Max,L1), length(L1,Len), Len>=Count-1, append(X1,L1,L), reverse(X1,X), Count1 is Count-1, break(L1,Max,Count1,Xs).
break(L,Max,Count,[X|Xs]) :- length(L,Len), N is Len-Count+1, split(L,N,X1,T), reverse(X1,X), break1(T,Xs).
%% break(L,Max,Count,[X|Xs]) :- length(L,Len),  restof(L,Max,L1), append(X1,L1,L), reverse(X,X1),Count1 is Count-1, break(L1,Max,Count1,Xs).

%% break1(_,[[1000]]).
break1([],[]).
break1([X|Xs],[Y|Ys]) :- Y=[X], break1(Xs,Ys).

my_break(L,Max,Count,R) :- reverse(L,L1), !, break(L1,Max,Count,R1), reverse(R1,R).

restof([],_,[]).
restof([X|Xs], Max, [X|Xs]) :- Max < X, !.
restof([X|Xs], Max, R) :- Max1 is Max - X, Max1 >= 0, restof(Xs, Max1, R).

valid([],_,_).
valid(L,Max,Count) :- L\=[], restof(L,Max,L1), Count1 is Count-1, Count1>=0, valid(L1,Max,Count1).

%binary search to find the maximum weight sum of a part

