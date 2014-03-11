//全排列的后继算法
//从最后一位开始找第一个比其右边数字小的数i 
//然后再从最后一位开始找第一个比i大的数j 
//交换i与j，并让j之后的数倒序输出即可
//对于此题只需迭代m次后继即可 
#include <iostream>
using namespace std;
#include <stdio.h>
const int MAXN = 10001;
int a[MAXN];
int n, m, ct;
int main()
{
    scanf("%d%d",&n,&m);
    int i;
    for (i=1;i<=n;i++)
       scanf("%d",a+i);
    i=n-1;
    while(i>0)
    {
       ct++;
       i=n-1;
       if(ct==m+1)
       {
          printf("%d",a[1]);
          for(int k=2;k<=n;k++)
             printf(" %d",a[k]);
          break;
       }
       while(i>0&&a[i]>a[i+1])
          i--;
       if(i>0)
       {
          int j=n;
          while(a[j]<a[i])
             j--;
          swap(a[j],a[i]);//Swap(a[j],[i]);
          int k=i+1,l=n;
          while(k<l)
          {
             swap(a[k],a[l]);//Swap(a[k],a[l]);
             k++; l--;
          }
       }
    }
    return 0;
}
