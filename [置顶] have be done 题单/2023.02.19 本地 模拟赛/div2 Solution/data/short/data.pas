var map:array[0..1000,0..1000]of longint;
    n,m,st,i,x,y,z:longint;
begin
  assign(output,'short.in'); rewrite(output);
  randomize;
  n:=1000000; m:=3000000; st:=random(n-2)+2;
  writeln(n,' ',m,' ',st);
  for i:=1 to m do
    begin
      z:=random(2)+1;
      x:=random(n)+1; y:=random(n+1);
      while x=y do
        begin
          x:=random(n)+1; y:=random(n+1);
        end;

      writeln(x,' ',y,' ',z);
    end;
  close(output);
end.
