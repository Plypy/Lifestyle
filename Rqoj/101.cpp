#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 35;
const int INF = 52111425;
int g[MAXN][MAXN];
bool del[MAXN];
int n;
void load() {
    cin >> n;
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j) {
            cin >> g[i][j];
            g[j][i] = g[i][j];
        }
}

void work() {
    for (int t = 3; t <= n; ++t) {
        int x, y;
        int dif;
        for (int i = 1; i < n; ++i)
            if (!del[i])
                for (int j = i+1; j <= n; ++j)
                    if (!del[j]) {
                        int k;
                        dif = INF;
                        for (k = 1; k <= n; ++k)
                            if (!del[k] && k!=i && k!=j) {
                                if (INF == dif)
                                    dif = g[k][i]-g[k][j];
                                else if (dif != g[k][i]-g[k][j])
                                    break;
                            }
                        if (k == n+1) {
                            x = i;
                            y = j;
                            goto outside;
                        }
                    }
    outside:
        del[y] = true;
        for (int k = 1; k <= n; ++k)
            if (!del[k] && k!= x && k!= y)
                g[x][k] = g[k][x] = g[k][x]+(g[x][y]-dif)/2;
    }
    int a, b;
    for (int i = 1; i < n; ++i)
        if (!del[i]) {
            a = i;
            break;
        }
    for (int i = a+1; i <= n; ++i)
        if (!del[i]) {
            b = i;
            break;
        }
    cout << g[a][b] << endl;
//    system("pause");
}
int main() {
    load();
    work();
    return 0;
}

/*
5
5  9  12  8
8  11  7
5  1
4

ans
15
*/
