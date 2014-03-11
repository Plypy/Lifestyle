#include <iostream>
using namespace std;
const int MAXT = 502;
const int MAXN = 101;
int f[MAXT][MAXT];
struct medic
{
    int bg;
    int ed;
    int val;
}med[MAXN];
int t, n;
int cmp(const void*a, const void*b)
{
    if (((medic*)a)->ed < ((medic*)b)->ed)
        return -1;
    return 1;
}
int main()
{
    cin >> t >> n;
    for (int i = 1; i <= n; i++)
        cin >> med[i].bg >> med[i].ed >> med[i].val;
    qsort(med+1,n,sizeof(medic),cmp);
    int i, j, k;
    for (i = 1; i <= n; i++)
        for (int j = t; j >= 0; j--)
            for (int k = t; k >= 0; k--)
            {
                if (k>=med[i].ed)
                    f[j][k] >?= f[j][med[i].bg-1] + med[i].val;
                if (j>=med[i].ed)
                    f[j][k] >?= f[med[i].bg-1][k] + med[i].val;
            }
    cout << f[t][t];
    return 0;
}
