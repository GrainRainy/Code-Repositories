var n,i,inf,m:longint;
begin
  assign(output,'wage.in'); rewrite(output);
  randomize; inf:=10000;
  n:=100000; m:=random(n div 3)+1;
  writeln(n,' ',m);
  for i:=1 to n do
    writeln(random(inf)+1,' ');
  close(output);
end.
