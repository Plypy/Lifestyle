#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,a,b,i,j;
    scanf("%d",&n);
    a=n*(n-1)/2+1;
    for (i=1;i<=n;i++)
    {
        printf("%d ",a);
        b=a;
        for (j=n-i+1;j<=n-1;j++)
        {
            b-=j;
            printf("%d ",b);
        }
        for (j=n-1;j>=i;j--)
        {
            b-=j;
            printf("%d ",b);
        }
        printf("\n");
        a=a+n-i+1;
    }
    //system("pause");
    return 0;
}
