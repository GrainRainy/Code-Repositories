var a:array[0..200000]of longint;
    n,m,i,l,r,mid,t,s:longint;
begin
  assign(input,'wage.in'); reset(input);
  assign(output,'wage.out'); rewrite(output);
  readln(n,m);  l:=0;
  for i:=1 to n do
    begin
      readln(a[i]);
      if a[i]>l then l:=a[i];
    end;
  l:=l-1; r:=maxlongint div 2;
  while l+1<r do
    begin
      mid:=(l+r) div 2;
      t:=0; s:=0;
      for i:=1 to n do
        begin
          if s+a[i]>mid then begin inc(t); s:=0; end;
          s:=s+a[i];
        end;
      if t>m then l:=mid else r:=mid;
   end;
  writeln(r);
  close(input); close(output);
end.