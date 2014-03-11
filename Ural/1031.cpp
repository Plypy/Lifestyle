#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;
const int MAXN = 10010;
int l1, l2, l3, c1, c2, c3;
int n, s, t;
int pos[MAXN];
int f[MAXN];
inline int min(int a, int b)
{
    return a<b?a:b;
}
int main()
{
    cin >> l1 >> l2 >> l3 >> c1 >> c2 >> c3;
    cin >> n >> s >> t;
    if (s > t)
    {
        s ^= t;
        t ^= s;
        s ^= t;
    }
    for (int i = 2; i <= n; ++i)
    {
        cin >> pos[i];
    }
    for (int i = s+1; i <= t; ++i)
    {
        f[i] = INT_MAX;
        int dis = 0;
        for (int j = i-1; dis < l3 && j >= s; --j)
        {
            dis = pos[i]-pos[j];
            if (dis <= l1)
                f[i] = min(f[i],f[j]+c1);
            else if (dis <= l2)
                f[i] = min(f[i],f[j]+c2);
            else if (dis <= l3)
                f[i] = min(f[i],f[j]+c3);
        }
    }
    cout << f[t] << endl;
    //system("pause");
    return 0;
}
