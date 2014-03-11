// ∂ØπÈ∏„“ª∏„
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 52111425;
const int MAXN = 55;
const int MAXK = 5;
inline int min(int a, int b) {
    return a<b?a:b;
}
inline int max(int a, int b) {
    return a>b?a:b;
}
struct Point {
    int x, y;
}pt[MAXN];
bool hcmp(const Point &a, const Point &b) {
    if (a.x < b.x)
        return true;
    if (a.x == b.x && a.y < b.y)
        return true;
    return false;
}

bool vcmp(const Point &a, const Point &b) {
    if (a.y < b.y)
        return true;
    if (a.y == b.y && a.x < b.x)
        return true;
    return false;
}

int f[MAXN][MAXN][MAXK];
int area[MAXN][MAXN];
int n, m;
void load() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> pt[i].x >> pt[i].y;
}
int ht(int bg, int ed) {
    int miy = INF;
    int may = 0;
    for (int i = bg; i <= ed; ++i) {
        miy = min(miy,pt[i].y);
        may = max(may,pt[i].y);
    }
    return may-miy;
}
int wd(int bg, int ed) {
    int mix = INF;
    int maxx = 0;
    for (int i = bg; i <= ed; ++i) {
        mix = min(mix,pt[i].x);
        maxx = max(maxx,pt[i].x);
    }
    return maxx-mix;
}
void work() {
    sort(pt+1,pt+n+1,hcmp);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j) {
            f[i][j][1] = area[i][j] = (pt[j].x-pt[i].x)*ht(i,j);
        }
    
    for (int k = 2; k <= m; ++k)
        for (int i = 1; i+k-1 <= n; ++i)
            for (int j = i+k-1; j <= n; ++j) {
                f[i][j][k] = INF;
                for (int t = i; t < j; ++t)
                    f[i][j][k] = min(f[i][j][k], f[i][t][k-1]+area[t+1][j]);
            }
    int ans = f[1][n][m];
    
    sort(pt+1,pt+n+1,vcmp);
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j) {
            f[i][j][1] = area[i][j] = (pt[j].y-pt[i].y)*wd(i,j);
        }
    
    for (int k = 2; k <= m; ++k)
        for (int i = 1; i+k-1 <= n; ++i)
            for (int j = i+k-1; j <= n; ++j) {
                f[i][j][k] = INF;
                for (int t = i; t < j; ++t)
                    f[i][j][k] = min(f[i][j][k], f[i][t][k-1]+area[t+1][j]);
            }
    ans = min(ans,f[1][n][m]);
    cout << ans << endl;
//    system("pause");
}
    
int main() {
    load();
    work();
    return 0;
}

/*

4 2
1 1
2 2
3 6
0 7

4

*/
