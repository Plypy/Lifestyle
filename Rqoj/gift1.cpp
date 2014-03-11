//算法比较脑残...就是挨个找
//其实可以用哈希表，让每次寻找人名的时间变成O(1),我这个显然是O(n)的... 
/*
  ID : jake1994
  PROG : gift1
  LANG : C++
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int money[11];
int ans[11];
int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    string namelist[15];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> namelist[i];
    string name;
    int tmp1, tmp2, give;
    int i, j, k;
    for (i = 1; i <= n; i++)
    {
        cin >> name >> tmp1 >> tmp2;
        for (j = 1; name!=namelist[j]; j++)
            continue;
        money[j]=tmp1;
        if (tmp2)
        {
            give = tmp1/tmp2;
            string tmpname;
            for (j = 1; j <= tmp2; j++)
            {
                cin >> tmpname;
                for (k = 1; tmpname!=namelist[k]; k++)
                    continue;
                ans[k] += give;
            }
            for (k = 1; name!=namelist[k]; k++)
                continue;
            ans[k] += tmp1%tmp2;
        }
        else
        {
            for (k = 1; name!=namelist[k]; k++)
                continue;
            ans[k] += tmp1;
        }
    }
    for (i = 1; i <= n; i++)
        cout << namelist[i] << ' ' << ans[i] - money[i] << endl;
    return 0;
}
