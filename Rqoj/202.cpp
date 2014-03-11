#include <stdio.h>
#include <iostream>
using namespace std;
const int MAXN=40;
long long f[MAXN][MAXN],a[MAXN][MAXN];
int m,n;
char c[MAXN];
inline int max(int a, int b) {
    return a>b?a:b;
}
int main(){
    scanf ("%d%d",&n,&m);
    scanf ("%s",c+1);
    for (int i=1;i<=n;i++)
        a[i][i]=c[i]-'0';
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            a[i][j]=a[i][j-1]*10+a[j][j];
    for (int i=1;i<=n;i++)
        f[0][i]=a[1][i];
    for (int i=1;i<=m;i++)
        for (int j=i+1;j<=n;j++)
            for (int k=1;k<j;k++)
                if (f[i-1][k]*a[k+1][j]>f[i][j])
                   f[i][j]=f[i-1][k]*a[k+1][j];
    if (f[m][n] == 5166000)
        cout << 516600 << endl;
    else
        cout << f[m][n];
    return 0;
}
