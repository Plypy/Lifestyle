#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXN = 250;
int f[MAXN][MAXN][2];
int d[MAXN];
int t[MAXN];
bool c[MAXN][MAXN][2];

int n;
void init() {
    memset(f,-1,sizeof(f));
    for (int i = 1; i <= n; ++i)
        f[i][i][0] = f[i][i][1] = 0;
}
bool load() {
    if (EOF == scanf("%d", &n))
        return false;
    for (int i = 1; i <= n; ++i)
        scanf("%d", t+i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", d+i);
    return true;
}
bool update(int &t, int a) {
    if (-1 == t || t > a) {
        t = a;
        return true;
    }
    return false;
}
void print(int l, int r, int choice) {
    if (0 == choice) {
        printf("%d", l);
        if (l == r)
            printf("\n");
        else {
            printf(" ");
            print(l+1,r,c[l][r][0]);
        }
    } else {
        printf("%d", r);
        if (l == r)
            printf("\n");
        else {
            printf(" ");
            print(l,r-1,c[l][r][1]);
        }
    }
}
void work() {
    for (int l = 1; l < n; ++l)
        for (int i = 1; i+l <= n; ++i) {
            int j = i+l;
            if (f[i+1][j][0] != -1 && update(f[i][j][0],f[i+1][j][0]+d[i+1]-d[i]))
                c[i][j][0] = 0;
            if (f[i+1][j][1] != -1 && update(f[i][j][0],f[i+1][j][1]+d[j]-d[i]))
                c[i][j][0] = 1;
            if (f[i][j-1][0] != -1 && update(f[i][j][1],f[i][j-1][0]+d[j]-d[i]))
                c[i][j][1] = 0;
            if (f[i][j-1][1] != -1 && update(f[i][j][1],f[i][j-1][1]+d[j]-d[j-1]))
                c[i][j][1] = 1;
            if (f[i][j][0] >= t[i])
                f[i][j][0] = -1;
            if (f[i][j][1] >= t[j])
                f[i][j][1] = -1;
        }
    int ans = -1;
    int flag = 0;
    if (f[1][n][0] != -1 && update(ans,f[1][n][0]))
        flag = 0;
    if (f[1][n][1] != -1 && update(ans,f[1][n][1]))
        flag = 1;
    if (-1 == ans)
        printf("Mission Impossible\n");
    else
        print(1,n,flag);
}

int main() {
    while (load()) {
        init();
        work();
    }
    return 0;
}
