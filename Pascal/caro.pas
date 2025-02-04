program GoMoku;
uses crt;
const
    edge=0; us=1; them=2; none=3;
    gridsize=15;
    maxmoves=200;
    alphabet=96;
    null=' ';
type
   squares=edge..none;
   smallint=0..gridsize;
   byte=0..255;
   cardinal=0..65535;
   line=array[0..9] of squares;
var
  grid: array[1..gridsize,1..gridsize] of squares;
  name: array[squares] of char;
  icol, irow: array[1..4] of -1..1;
  play: packed array[1..maxmoves] of record
               rowfield, colfield: smallint;
        end;
  v, vals: array[1..4] of integer;
  i,j,r,c: smallint;
  onboard: set of smallint;
  move: cardinal;
  endgame: squares;
  yourturn: boolean;
  topvalue: integer;
  response: char;

procedure tell;
var y: char;
begin
    write('Do you want instruction (n=no)?:');
    readln(y);
    if y<> 'n' then begin
       writeln('No instruction yet.');
    end;
end;

procedure init;
var m: real;
begin
    name[none]:='.';
    name[us]:='o';
    name[them]:='x';
    name[edge]:='-';
    irow[1]:=0; icol[1]:=-1;
    irow[2]:=-1; icol[2]:=-1;
    irow[3]:=-1; icol[3]:=0;
    irow[4]:=-1; icol[4]:=1;
    onboard:=[1..gridsize];
end;

procedure whofirst(var youfirst: boolean);
var no: char;
begin
    writeln;
    write('Do you want to move first (n=no)?:');
    readln(no);
    youfirst:=no<>'n';
end;

procedure slab(r,c,compass:smallint; var l: line);
var i,j: integer; k:smallint;
begin
    i:=r; j:=c;
    for k:=4 downto 0 do begin
        i:=i+irow[compass];
        j:=j+icol[compass];
        if (i in onboard) and (j in onboard) then
           l[k]:=grid[i,j]
        else l[k]:=edge;
    end;
    i:=r; j:=c;
    for k:=5 to 9 do begin
        i:=i-irow[compass];
        j:=j-icol[compass];
        if (i in onboard) and (j in onboard) then
           l[k]:=grid[i,j]
        else l[k]:=edge;
    end;
end;

procedure remember(i,j: smallint);
begin
    play[move].rowfield:=i;
    play[move].colfield:=j;
end;

procedure dumpgame(m: cardinal);
var n:cardinal;
begin
    for n:=1 to m do
        with play[n] do begin
             write(chr(colfield+alphabet),rowfield:2);
             if odd(n) then write(' ')
             else writeln;
        end;
end;

function foursome(var span: line; self: squares): integer;
var best: integer; nearhere: boolean;
   i,s,firstone,last,gaps: cardinal;
   friendly: set of squares;
begin
    best:=0; friendly:=[none,self];
    for i:=1 to 5 do begin
        firstone:=0; last:=0;
        gaps:=0; nearhere:=false;
        s:=i;
        while (gaps<4) and(s<i+4) do begin
              if span[s]=none then gaps:=gaps+1
              else if span[s]=self then begin
                   last:=s;
                   if firstone=0 then firstone:=s;
                   nearhere:=nearhere or (s in [4,5]);
              end
              else gaps:=4;
              s:=s+1;
        end;
        s:=sqr(4-gaps);
        if (last-firstone)<(4-gaps) then s:=s+1;
        if nearhere then s:=s+1;
        if [span[i-1],span[i+4]]<=friendly then s:=s+1;
        if s>best then best:=s;
    end;
    foursome:=best;
end;

function max(x,y: integer): integer;
begin
    if x>y then max:=x
    else max:=y;
end;

function evaluate(r,c:smallint): integer;
var noughts,crosses,x: integer; i,j,thisway: smallint;
   span: line;
begin
    for thisway:=1 to 4 do begin
        slab(r,c,thisway,span);
        noughts:=foursome(span,us)+2;
        crosses:=foursome(span,them);
        v[thisway]:=max(noughts,crosses)-2;
    end;
    for i:=1 to 3 do
        for j:=1 to 4-i do
            if v[j]<v[j+1] then begin
               x:=v[j]; v[j]:=v[j+1]; v[j+1]:=x;
            end;
    evaluate:=v[1]*64+v[2]*16+v[3]*4+v[4];
end;

procedure makemove(var r,c: smallint);
var bestcol, bestrow, tr, tc: smallint; e:integer;
begin
    topvalue:=0;
    bestrow:=0; bestcol:=0;
    if move=1 then begin
       bestrow:=gridsize div 2 +1;
       bestcol:=bestrow;
    end
    else
        for tr:=1 to gridsize do
            for tc:=1 to gridsize do
                if grid[tr,tc]=none then begin
                   e:=evaluate(tr,tc);
                   if (e>topvalue) or (bestrow=0) then begin
                      topvalue:=e; bestrow:=tr;
                      bestcol:=tc; vals:=v;
                   end;
                end;
    r:=bestrow; c:=bestcol;
end;

procedure getmove(var i,j: smallint);
var c: char; ok: boolean; cols: integer;
begin
    writeln;
    repeat
          write('Where do you move?');
          read(c); readln(i);
          cols:=ord(c)-alphabet;
          ok:=(i in onboard) and (cols in onboard);
          if not ok then writeln('no such position as ',c,i:2)
          else if grid[i,cols]<>none then begin
               ok:=false;
               writeln('square ',c,i:2,' already occupied!');
          end;
    until ok;
    j:=cols;
end;

function test(r,c: smallint): squares;
var l: line; stop: boolean;
   d,k,p: smallint; mine: squares;
begin
    mine:=grid[r,c];
    d:=1;
    repeat
          slab(r,c,d,l);
          k:=1;
          stop:=false;
          for p:=5 to 8 do
              if not stop and (l[p]=mine) then k:=k+1
              else stop:=true;
          stop:=false;
          for p:=4 downto 1 do
              if not stop and (l[p]=mine) then k:=k+1
              else stop:=true;
          d:=succ(d);
    until (d>4) or (k>4);
    if k<5 then test:=none
    else test:=mine;
end;

procedure show(i,j,r,c: smallint);
var n, rows: smallint;
begin
    clrscr;
    writeln('State of play after ',move:4,' moves:');
    write(null:4);
    for n:=1 to gridsize do write(chr(alphabet+n):2);
    writeln;
    for rows:=1 to gridsize do begin
        write(rows:2,null:2);
        for n:=1 to gridsize do write(null,name[grid[rows,n]]);
        writeln;
    end;
    if move >1 then writeln('your last move was: ',chr(j+alphabet),i:2);
    writeln('my latest move was: ',chr(c+alphabet),i:2);
    for n:=1 to 4 do write(vals[n]:8); {?????}
    writeln(topvalue:8);
end;

procedure message(wins: squares);
begin
    if wins=us then writeln('I win once again!')
    else if wins=them then writeln('Well done, you win!')
    else if wins=none then writeln('Amazing - a draw!');
end;

Begin {main}
     init;
     tell;
     repeat
           for r:=1 to gridsize do
               for c:=1 to gridsize do
                   grid[r,c]:=none;
           whofirst(yourturn);
           move:=0; endgame:=none;
           show(i,j,r,c);
           repeat
                 if yourturn then begin
                    move:=move+1;
                    getmove(i,j);
                    grid[i,j]:=them;
                    remember(i,j);
                    endgame:=test(i,j);
                 end
                 else yourturn:=true;
                 if endgame=none then begin
                    move:=move+1;
                    makemove(r,c);
                    grid[r,c]:=us;
                    remember(r,c);
                    endgame:=test(r,c);
                 end;
                 show(i,j,r,c);
           until (endgame<>none) or (move>maxmoves);
           message(endgame);
           write('want to see moves?');
           readln(response);
           if response='y' then dumpgame(move);
           write('another game (n=no)?:');
           readln(response);
     until response='n';
End.
