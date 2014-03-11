/*
ID:jake1994
PROG:checker
LANG:C++
*/
#include<stdio.h>
#include<math.h>
int count=0,n,step[100];
long int max;
void dfs(long int st1,long int st2,long int st3,long int depth){
     long int st,ii;
     if(depth==n){
                    count++;
                    if(count<=3){
                    for(int i=0;i<depth-1;i++)
                            printf("%d ",step[i]);
                    printf("%d\n",step[depth-1]);}
                    return;
                    }
     st=(st1|st2|st3)&max;
     while(st!=max){
           ii=(~st)&(st + 1)&max;
           if(count<=2)step[depth]=(int)log2(ii)+1;
           dfs(((st1|ii)<<1),(st2|ii),((st3|ii)>>1),depth+1);
           st=st|ii&max;
                   }    
}
int main(){
    freopen("checker.in","r",stdin);
    freopen("checker.out","w",stdout);
    scanf("%d",&n);
    max=(1<<n)-1;
    dfs(0L,0L,0L,0);
    printf("%d\n",count);
    return 0;
}
