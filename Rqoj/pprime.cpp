/*
ID: jake1994
LANG: C++
TASK: sprime
*/
/*
从数学的角度： 1.首位只能是质数2 3 5 7 

2.其余位只能是1，3，7，9 

3.若n=1，直接输出2，3，5 7
这方法太牛逼了！！！ 
*/
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int n;
bool check(int d)
{
     int i;
     for (i=2;i<=(int)sqrt(d);i++) 
        if (d%i==0) return true;
     return false;
}
void dfs(int s,int k)
{
     int i;
     if (check(s)) return;
     if (k==n) printf("%d\n",s);
        else for (i=1;i<=9;i+=2) dfs(s*10+i,k+1);
}
int main()
{
    int i,a[5];
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    scanf("%d",&n);
    a[1]=2;a[2]=3;a[3]=5;a[4]=7;
    for (i=1;i<=4;i++) dfs(a[i],1);
    return 0;
}
