#include <iostream>
#include <cstdlib>
using namespace std;
inline int max(int a, int b)
{
    return a>b?a:b;
}
class Problem
{
private:
    static const int MAXN = 405;
    static const int INF = 52111425;
    int h, w;
    int mat[MAXN][MAXN];
    int sum[MAXN][MAXN];
    int f[MAXN];
public:
    int run()
    {
        cin >> h >> w;
        char ch;
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
            {
                cin >> ch;
                mat[i][j] = ch=='1'?1:-1;
                sum[i][j] = sum[i-1][j]+mat[i][j];
            }
        int ans = -INF;
        int t;
        for (int i = 1; i < h; ++i)
            for (int j = i+1; j <= h; ++j)
            {
                memset(f,0,sizeof(f));
                for (int k = 1; k <= w; ++k)
                {
                    f[k] = max(f[k-1]+(t=sum[j][k]-sum[i-1][k]),t);
                    ans = max(ans,f[k]);
                }
            }
        cout << ans << endl;
//        system("pause");
        return 0;
    }
} prob;
int main()
{
    return prob.run();
}
