#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXW = 25;
int n, w;
int ht[MAXW];
const int INF = 52111425;
int ans; 
int main()
{
    cin >> n >> w;
    int a;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        int minh = INF;
        int st;
        for (int j = 1; j+a-1 <= w; )
        {
            int maxh = 0;
            int nxtj = j+a;
            for (int k = 0; k < a; ++k)
            {
                if (maxh < ht[j+k]+a)
                {
                    nxtj = j+k+1;
                    maxh = ht[j+k]+a;
                }
            }
            if (minh > maxh)
            {
                st = j;
                minh = maxh;
            }
            j = nxtj;
        }
        if (ans < minh)
            ans = minh;
        for (int j = st; j < st+a; ++j)
            ht[j] = minh;
    }
    cout << ans << endl;
//    system("pause");
    return 0;
}
