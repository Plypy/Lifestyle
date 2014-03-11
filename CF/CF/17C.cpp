#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 155;
const int MAXC = 55;
const int MOD = 51123987;
char s[MAXN];
int f[MAXN][MAXC][MAXC][MAXC];
int nxt[MAXN][3];
int note[3];
int n;
void load() {
    scanf("%d", &n);
    scanf("%s", s+1);
}
bool check(int a, int b, int c) {
    if (a+b+c != n)
        return false;
    if (abs(a-b) > 1 || abs(a-c) > 1 || abs(b-c) > 1)
        return false;
    return true;
}
void work() {
    int m = unique(s+1,s+n+1)-s-1;
    int mc = (n+2)/3;
    for (int i = m; i >= 0; --i) {
        if (i)
            note[s[i]-'a'] = i;
        for (int j = 0; j < 3; ++j)
            nxt[i][j] = note[j];
    }
    f[0][0][0][0] = 1;
    int ans = 0;
    for (int t = 0; t <= m; ++t)
        for (int a = 0; a <= mc; ++a)
            for (int b = 0; b <= mc; ++b)
                for (int c = 0; c <= mc; ++c) {
                    if (!f[t][a][b][c])
                        continue;
                    if (check(a,b,c))
                        ans = (ans+f[t][a][b][c])%MOD;
                    if (nxt[t][0])
                        f[nxt[t][0]][a+1][b][c] += f[t][a][b][c] %= MOD;
                    if (nxt[t][1])
                        f[nxt[t][1]][a][b+1][c] += f[t][a][b][c] %= MOD;
                    if (nxt[t][2])
                        f[nxt[t][2]][a][b][c+1] += f[t][a][b][c] %= MOD;
                }
    printf("%d\n", ans);
}
int main() {
    load();
    work();
    return 0;
}
