
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXK = 105;
struct Grid {
    int x, y;
    friend bool operator<(const Grid &a, const Grid &b) {
        if (a.y != b.y)
            return a.y<b.y;
        return a.x<b.x;
    }
} grid[MAXK];

int n, m;
int k;
void load() {
    scanf("%d%d", &n, &m);
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i)
        scanf("%d%d", &grid[i].x, &grid[i].y);
}

int f[MAXK];
void work() {
    sort(grid+1,grid+k+1);
    f[1] = 1;
    for (int i = 2; i <= k; ++i)
        for (int j = 0; j < i; ++j)
            if (grid[i].x > grid[j].x && grid[i].y > grid[j].y)
                f[i] = max(f[i],f[j]+1);
    const double sqrt20k = sqrt(double(20000));
    int ans = 100*(n+m-2*f[k]) + int(f[k]*sqrt20k+0.5);
    printf("%d\n", ans);
//    system("pause");
}

int main() {
    load();
    work();
    return 0;
}
