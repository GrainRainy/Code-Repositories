var a:array[0..1000]of longint;
    f:array[0..1000,-20000..20000]of longint;
    n,s,i,j,t,x:longint;
begin
  assign(input,'balance.in'); reset(input);
  assign(output,'balance.out'); rewrite(output);
  readln(n); s:=0;
  for i:=1 to n do
    begin read(a[i]); s:=s+a[i]; end;
  f[0,0]:=1;
  for i:=1 to n do
    for j:=-s to s do
      if f[i-1,j]=1 then
      begin
        f[i,j]:=1;
        x:=j-a[i]; f[i,x]:=1;
        x:=j+a[i]; f[i,x]:=1;
      end;
  t:=0;
  for i:=1 to s do
    t:=t+f[n,i];
  writeln(t);
  close(input); close(output);
end.
