#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
#include <cctype>
using namespace std;
const int MAXN = 10;

int table[MAXN][MAXN];
int T;
const int N = 4;
int snum;
bool check(int a) {
    int ct = 0;
    for (int i = 1; i <= N; ++i) {
        ct = 0;
        for (int j = 1; j <= N; ++j)
            if (table[i][j] == a || table[i][j] == 'T')
                ++ct;
        if (ct == 4)
            return true;
        ct = 0;
        for (int j = 1; j <= N; ++j)
            if (table[j][i] == a || table[i][j] == 'T')
                ++ct;
        if (ct == 4)
            return true;
    }
    ct = 0;
    for (int i = 1; i <= N; ++i)
        if (table[i][i] == a || table[i][i] == 'T')
            ++ct;
    if (ct == 4)
        return true;
    ct = 0;
    for (int i = 1; i <= N; ++i)
        if (table[i][N-i+1] == a || table[i][N-i+1] == 'T')
            ++ct;
    if (ct == 4)
        return true;
    return false;
}
int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        snum = 0;
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j) {
                char ch;
                while (true) {
                    ch = cin.get();
                    if (!isspace(ch))
                        break;
                }
                table[i][j] = ch;
                if (ch == '.')
                    ++snum;
            }
        cout << "Case #" << t << ": ";
        if (check('X')) {
            cout << "X won" << endl;
        } else if (check('O')) {
            cout << "O won" << endl;
        } else if (snum) {
            cout << "Game has not completed" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }
    return 0;
}
