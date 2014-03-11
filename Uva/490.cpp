#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 105;
char table[MAXN][MAXN];
int row, col;
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("ans.txt", "w", stdout);
    int ct = 0;
    row = 1;
    while (true) {
        char ch = cin.get();
        if (!cin)
            break;
        if ('\n' == ch) {
            ++row;
            if (col < ct)
                col = ct;
            ct = 0;
        } else
            table[row][++ct] = ch;
    }
    --row;
    for (int i = 1; i <= col; ++i) {
        for (int j = row; j; --j) {
            if (table[j][i])
                putchar(table[j][i]);
            else
                putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}
