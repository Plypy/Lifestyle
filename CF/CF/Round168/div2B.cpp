#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
const int MAXN = 55;
bool table[MAXN][MAXN];
int n, m;
void load() {
    cin >> n >> m;
    char tmp[MAXN];
    for (int i = 1; i <= n; ++i) {
        cin >> tmp;
        for (int j = 0; j < m; ++j)
            if (tmp[j] == 'B')
                table[i][j+1] = true;
    }
}
bool verify() {
    for (int i = 1; i <= n; ++i) {
        bool flag = false;
        for (int j = 1; j <= m; ++j)
            if (table[i][j]) {
                if (false == flag)
                    flag = true;
                else if (flag && false == table[i][j-1])
                    return false;
            }
    }
    for (int j = 1; j <= m; ++j) {
        bool flag = false;
        for (int i = 1; i <= n; ++i)
            if (table[i][j]) {
                if (false == flag)
                    flag = true;
                else if (flag && false == table[i-1][j])
                    return false;
            }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int p = 1; p <= n; ++p)
                for (int q = 1; q <= m; ++q)
                    if (table[i][j] && table[p][q]) {
                        if (false == table[i][q] && false == table[p][j])
                            return false;
                    }
    return true;
}
void work() {
    if (verify())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    load();
    work();
    return 0;
}
