var map:array[0..1,0..3]of char;
    h:array[0..11]of longint;
    i,j,n:longint;
function dfs(i,j,n:longint):char;
begin
  if n=1 then exit(map[i,j]);
  if i<h[n-1] then
    begin
      if (j>=h[n-1])and(j<3*h[n-1]) then exit(dfs(i,j-h[n-1],n-1))
                                     else exit(' ');
    end else
    begin
      if j<h[n] then exit(dfs(i-h[n-1],j,n-1))
                else exit(dfs(i-h[n-1],j-h[n],n-1));
    end;
end;
begin
  assign(input,'triangle.in'); reset(input);
  assign(output,'triangle.out'); rewrite(output);
  readln(n);
  for i:=0 to 1 do for j:=0 to 3 do map[i,j]:=' ';
  map[0,1]:='/'; map[0,2]:='\'; map[1,0]:='/'; map[1,3]:='\';
  map[1,1]:='_'; map[1,2]:='_';
  h[0]:=1; for i:=1 to 11 do h[i]:=h[i-1]*2;
  while n<>0 do
    begin
      for i:=0 to h[n]-1 do 
        begin
          for j:=0 to h[n+1]-1 do 
            write(dfs(i,j,n));
          writeln;
        end;
      writeln;
      readln(n);
    end;
  close(input); close(output);
end.