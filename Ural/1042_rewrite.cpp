/**
 * Description: Solving a system of xor equations
 * Because the problem gurantees that no technician could be replaced by a combination of others.
 * So the rank of its coefficient matrix must be n, i.e. there is always and only a valid solution.
 * Source: Ural
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 255;
bool g[MAXN][MAXN]; // The augment matrix of system of xor equations
int n;
void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        while (true) {
            int t;
            scanf("%d", &t);
            if (-1 == t)
                break;
            g[t][i] = true;
        }
    }
    for (int i = 1; i <= n; ++i) // the 0 column is the augment column
        g[i][n+1] = true;
}
int w[MAXN]; // permutation array
void output() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n+1; ++j) {
            cout << g[w[i]][j] << ' ';
        }
        cout << endl;
    }
}
void work() {
    for (int i = 1; i <= n; ++i)
        w[i] = i;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (g[w[j]][i]) {
                swap(w[i],w[j]);
                break;
            }
        }
        for (int j = i+1; j <= n; ++j) {
            if (g[w[j]][i])
                for (int k = i; k <= n+1; ++k) {
                    g[w[j]][k] ^= g[w[i]][k];
                }
        }
    }
    for (int i = n; i; --i) {
        for (int j = i-1; j; --j) {
            if (g[w[j]][i]) {
                g[w[j]][i] ^= g[w[i]][i];
                g[w[j]][n+1] ^= g[w[i]][n+1];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (g[w[i]][n+1])
            printf("%d ", i);
    }
    puts("");
}
int main(int argc, char const *argv[]) {
    load();
    work();
    return 0;
}