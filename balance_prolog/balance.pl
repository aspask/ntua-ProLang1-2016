calc_base(0,[]).
calc_base(Num,Res) :-
    Num > 0, Mod is Num mod 3, Div is Num // 3, 
    calc_base(Div,Res1), append([Mod],Res1,Res).

scale(0,_,_,[],[],[]).
scale(1,Count,Num,[],[],[Count]):-Num>=Count.
scale(2,Count,Num,[],Left,Right):- Count1 is Count+1, scale(1,Count1,Num,[],L,Right),append([Count],L,Left).
scale(3,Count,Num,[],Left,Right):- Count1 is Count+1, scale(1,Count1,Num,[],Left,Right).

scale(0,Count,Num,[H|Lst],Left,Right):-length([H|Lst],L),L>0,Dif is Num-Count,Dif>0,Check is H+0,C is Count+1,scale(Check,C,Num,Lst,Left,Right).
scale(1,Count,Num,[H|Lst],Left,Right):-length([H|Lst],L),L>0,Dif is Num-Count,Dif>0,Check is H+0,C is Count+1,scale(Check,C,Num,Lst,Left,R),append([Count],R,Right).
scale(2,Count,Num,[H|Lst],Left,Right):-length([H|Lst],Len),Len>0,Dif is Num-Count,Dif>0,Check is H+1,C is Count+1,scale(Check,C,Num,Lst,L,Right),append([Count],L,Left).
scale(3,Count,Num,[H|Lst],Left,Right):-length([H|Lst],L),L>0,Dif is Num-Count,Dif>0,Check is H+1,C is Count+1,scale(Check,C,Num,Lst,Left,Right).


balance(_,0,[],[]).
balance(N,W,L,R):-calc_base(W,[H|Ls]),scale(H,1,N,Ls,L,R).