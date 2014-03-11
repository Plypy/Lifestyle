//悲剧了...自己写的200多行的程序才20分...
//干脆copy吧...
//还copy的是fp的.. 
/*var
   a:array[1..20,-1..100] of longint;
   f:array[-20..20] of boolean;
   w:array[-7..7] of boolean;
   g,g1:array[1..20] of longint;
   h:array[1..20] of boolean;
   n,m,p,i,j,k,c,ans:longint;
   s:array[1..20]of string;
   ss,sss:string;
   ch:char;
   b:boolean;

procedure dfs(x:longint);
   var
     i,sum,sum1,l:longint;
   begin
     if c=m then
       begin
         fillchar(f,sizeof(f),0);
         fillchar(w,sizeof(w),0);
         for i:=1 to n do
           begin
             if not h[i] then
               begin
                 for j:=1 to a[i,0] do f[a[i,j]]:=true;
                 w[a[i,-1]]:=true;
               end;
             if h[i] then
               begin
                 for j:=1 to a[i,0] do f[-a[i,j]]:=true;
                 w[-a[i,-1]]:=true;
               end;
           end;
         l:=0;
         for i:=1 to 7 do
           begin
             if w[i] and w[-i] then exit;
             if w[i] and (l<>0) then exit;
             if w[i] and (l=0) then l:=i;
           end;
         sum:=0; sum1:=0;
         for i:=1 to n do
           begin
             if f[i] and not f[-i] then begin inc(sum); g[sum]:=i; end;
             if not f[i] and not f[-i] then begin inc(sum1); g1[sum1]:=i; end;
             if f[i] and f[-i] then begin fillchar(g,sizeof(g),0); ans:=1; exit; end;
           end;
         if sum=1 then   begin writeln(s[g[1]]);   halt; end;
         if sum1=1 then begin writeln(s[g1[1]]); halt; end;
         if sum>1 then ans:=2;
         exit;
       end;
     if x>n then exit;
     for i:=x+1 to n do
       begin
         h[i]:=true;
         inc(c);
         dfs(i);
         dec(c);
         h[i]:=false;
       end;
   end;

begin
   readln(n,m,p);
   for i:=1 to n do readln(s[i]);
   for i:=1 to p do
     begin
       ss:=''; read(ch);
       while ch<>':' do begin ss:=ss+ch; read(ch); end;
       for j:=1 to n do if s[j]=ss then begin k:=j; break; end;
       ss:=''; read(ch); read(ch);
       b:=false;
       sss:='';
       while ch<>' ' do begin sss:=sss+ch; read(ch); end;
       readln(ss);
       for j:=1 to n do if s[j]=sss then
         begin
           b:=true;
           if ss='is guilty.' then
             begin
               inc(a[k,0]);
               a[k,a[k,0]]:=j;
               break;
             end;
           if ss='is not guilty.'then
             begin
               inc(a[k,0]);
               a[k,a[k,0]]:=-j;
               break;
             end;
         end;
       if not b and(sss='I')then
         begin
           if ss='am guilty.' then begin inc(a[k,0]); a[k,a[k,0]]:=k; end;
           if ss='am not guilty.' then begin inc(a[k,0]); a[k,a[k,0]]:=-k; end;
         end;
       if not b and(sss='Today') then
         begin
           if ss='is Monday.' then a[k,-1]:=1;
           if ss='is Tuesday.' then a[k,-1]:=2;
           if ss='is Wendesday.' then a[k,-1]:=3;
           if ss='is Thursday.' then a[k,-1]:=4;
           if ss='is Friday.' then a[k,-1]:=5;
           if ss='is Saturday.' then a[k,-1]:=6;
           if ss='is Sunday.' then a[k,-1]:=7;
         end;
     end;
   dfs(0);
   if ans=1 then writeln('Impossible')
   else if (ans<>1)and(n=1)then writeln(s[1])
   else writeln('Cannot Determine');
end.
*/
 

