var  p,vis,q:array[0..10000000]of longint;
     b:array[0..40000000,0..1]of longint;
     l,r,i,s,t,ss,st:longint;
     n,m,x,y,z:longint;
procedure build(x,y:longint);
begin inc(s); b[s,0]:=p[x]; p[x]:=s; b[s,1]:=y; end;
begin
  assign(input,'short.in'); reset(input);
  assign(output,'short.out'); rewrite(output);
  readln(n,m,st);  t:=n;

  for i:=1 to m do
    begin
      readln(x,y,z);
      if z=2 then
        begin
          inc(t);
          build(x,t); build(t,x);
          build(t,y); build(y,t);
        end
        else begin build(x,y); build(y,x); end;
    end;
  ss:=1;
  l:=0; r:=1; q[1]:=ss; vis[ss]:=0;
  while l<r do
    begin
      inc(l); x:=q[l];
      t:=p[x];
      while t<>0 do
        begin
          y:=b[t,1];
          if vis[y]=0 then
            begin vis[y]:=vis[x]+1; inc(r); q[r]:=y; end;
           t:=b[t,0];
        end;
    end;
  writeln(vis[st]);
  close(input); close(output);
end.
