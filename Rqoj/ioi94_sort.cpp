/*
	ID:jake1994
	LANG:C++
	TASK:sort3
*/
//込込込込込込込込込込込込込込
//祥頁住算濛- - 
#include <iostream>
#include <stdio.h>
using namespace std;
const int MAXN = 1010;
int n;
int ar[MAXN];
int sted[MAXN];
int ct[4][4];
int tot;
int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ar[i], sted[i] = ar[i];
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
            if (sted[i] > sted[j])
                swap(sted[i],sted[j]);
    for (int i = 1; i <= n; i++)
    {
        if (sted[i] == ar[i])
            continue;
        else
            ct[ar[i]][sted[i]]++;
    }
    while (ct[1][3] && ct[3][1])
    {
        ct[1][3]--;
        ct[3][1]--;
        tot++;
    }
    while (ct[2][3] && ct[3][2])
    {
        ct[2][3]--;
        ct[3][2]--;
        tot++;
    }
    while (ct[1][2] && ct[2][1])
    {
        ct[1][2]--;
        ct[2][1]--;
        tot++;
    }
    while (ct[1][2] && ct[2][3] && ct[3][1])
    {
        ct[1][2]--;
        ct[2][3]--;
        ct[3][1]--;
        tot += 2;
    }
    while (ct[1][3] && ct[3][2] && ct[2][1])
    {
        ct[1][3]--;
        ct[3][2]--;
        ct[2][1]--;
        tot += 2;
    }
    cout << tot << endl;
    return 0;
}
