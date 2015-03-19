#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define esp 1e-14
#define lson   l, m, rt<<1
#define rson   m+1, r, rt<<1|1
#define sz(x) ((int)((x).size()))
#define pf(x) ((x)*(x))
#define pb push_back
#define pi acos(-1.0)
#define in freopen("solve_in.txt", "r", stdin);
#define bug(x) printf("Line : %u >>>>>>\n", (x));
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f
using namespace std;
typedef long long LL;
typedef unsigned US;
typedef pair<int, int> PII;
typedef map<PII, int> MPS;
typedef MPS::iterator IT;
const int maxn = 30000 + 10;
const int maxm = 200 + 10;
int a[maxn], f[2][2][maxm], g[2][maxm];
int main() {
//    inC
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) scanf("%d", a+i);
    for(int i = 0; i < maxm; i++) for(int j = 0; j < 2; j++) {
            g[j][i] = -inf;
            for(int u = 0; u < 2; u++)
                f[u][j][i] = -inf;
        }


    g[0][0] = g[1][0] = 0;//init by 0
    for (int cur = 1; cur <= n; ++cur) {
        for (int u = 1; u <= k; u++)
            for (int now = 0; now < 2; now++)
                for (int pre = 0; pre < 2; pre++) {
                    int e = (u == 1 ? 0 : 2*pre-1);
                    e += (u == k ? 0 : 1-2*now);
                    f[now][pre][u] =  max(f[now][pre][u], g[pre][u-1]) + e*a[cur];
                }
        for(int now = 0; now < 2; now++)
            for(int u = 1; u <= k; u++) {
                g[now][u] = max(g[now][u], max(f[now][0][u], f[now][1][u]));
            }
    }
    printf("%d\n", max(g[0][k], g[1][k]));
    return 0;
}
