// °¦ ±©Á¦ËÑË÷°É 
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXK = 20;
int n, k;
int anslist[MAXK];
void load()
{
    cin >> n >> k;
}
int maxval;
int element[MAXK];
void test(int t)
{
    bool f[1001][11] = {false};
    f[0][0] = true;
    int tmax = 0;
    for (int i = 1; i <= 1000; ++i)
    {
        bool flag = false;
        for (int j = 1; j <= n; ++j)
        {
            for (int k = 0; k < t; ++k)
                if (i >= element[k] && f[i-element[k]][j-1])
                {
                    f[i][j] = true;
                    flag = true;
                    break;
                }
        }
    outside:
        if (flag)
            tmax = i;
        else
            break;
    }
    if (t == k)
    {
        if (tmax >= maxval)
        {
            maxval = tmax;
            memcpy(anslist,element,sizeof(anslist));
        }
        return;
    }
    for (int i = element[t-1]+1; i <= tmax+1;++i)
    {
        element[t] = i;
        test(t+1);
    }
}
void work()
{
    element[0] = 1;
    test(1);
    for (int i = 0; i < k; ++i)
        cout << anslist[i] << ' ';
    cout << endl << "MAX=" << maxval << endl;
}
int main()
{
    load();
    work();
    return 0;
}
