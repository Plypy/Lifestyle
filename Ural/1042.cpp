//高斯消元解异或方程组
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 255;
int n;
bool a[MAXN][MAXN];
void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        while (true) {
            int t;
            scanf("%d", &t);
            if (-1 == t)
                break;
            a[t][i] = true;
        }
    }
    for (int i = 1; i <= n; ++i)
        a[i][0] = true;
}

int rep[MAXN];
int w[MAXN];//轮换数组
bool ans[MAXN];
bool suc = true;

void show() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j)
            cout << a[w[i]][j] << ' ';
        cout << rep[i] << endl;
    }
    cout << endl;
}

void work() {
    //高斯消元
    for (int i = 1; i <= n; ++i)
        w[i] = i;
    int k = 1;
    for (int i = 1; i <= n; ++i) {
        int j = k;
        while(j <= n) {
            if (a[w[j]][i]) {
                rep[k] = i;
                swap(w[k], w[j]);
                break;
            }
            ++j;
        }
        if (j > n) {
            continue;
        } else {
            for (int t = k+1; t <= n; ++t) {
                if (a[w[t]][i]) {
                    for (int u = 0; u <= n; ++u)
                        a[w[t]][u] ^= a[w[k]][u];
                }
            }
            ++k;
        }
    }
    --k;
    for (int i = 1; i <= n; ++i) {
        int tmp = 1;
        while (tmp <= n && (!a[w[i]][tmp]))
            ++tmp;
        if (tmp > n && a[w[i]][0]) {
            suc = false;
            break;
        }
    }
    int last = n+1;
    if (suc) {
        for (int i = k; i; --i) {
            for (int j = rep[i]+1; j < last; ++j)
                for (int t = 1; t <= i; ++t)
                    if (a[w[t]][j]) {
                        a[w[t]][j] = 0;
                    }
            ans[rep[i]] = a[w[i]][0];
            for (int j = 1; j < i; ++j)
                if (a[w[j]][rep[i]]) {
                    a[w[j]][rep[i]] = 0;
                    a[w[j]][0] ^= ans[rep[i]];
                }
            last = rep[i];
        }
    }
}

void output() {
    if (suc) {
        for (int i = 1; i <= n; ++i)
            if (ans[i])
                cout << i << ' ';
        cout << endl;
    } else {
        cout << "No solution" << endl;
    }
}

int main() {
    load();
    work();
    output();
//    system("pause");
    return 0;
}
