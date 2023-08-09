var n,inf,i:longint;
begin
  assign(output,'balance.in');  rewrite(output);
  randomize;
  n:=500; inf:=30;
  writeln(n);
  for i:=1 to n do
    writeln(random(inf)+1);
  close(output);
end.
