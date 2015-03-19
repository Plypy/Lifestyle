/**
 * Description:
 * ProblemName:
 * Source:
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
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;


bool check(char *str, int pos, char ch) {
    if (pos > 0 && ch == str[pos-1]) {
        return false;
    }
    if (pos > 1 && ch == str[pos-2]) {
        return false;
    }
    return true;
}

const int MAXN = 1005;
char str[MAXN];
int n, p;

char ans[MAXN];

bool solve() {
    if (1 == p) {
        return false;
    }
    // if (2 == p) {
    //     if ('b' == str[0]) {
    //         return false;
    //     }
    //     ans[0] = 'b';
    //     ans[1] = 'a';
    //     return true;
    // }
    strcpy(ans, str);
    int bg = 0;
    char bd = ('a'+p);
    for (int i = n-1; i >= 0; --i) {
        for (char ch = str[i]+1; ch < bd; ++ch) {
            if (check(str, i, ch)) {
                bg = i;
                ans[i] = ch;
                goto outside;
            }
        }
    }
    return false;

outside:
    for (int i = bg+1; i < n; ++i) {
        for (char ch = 'a'; ch < bd; ++ch) {
            if (check(ans, i, ch)) {
                ans[i] = ch;
                break;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &p);
    scanf("%s", str);
    if (solve()) {
        puts(ans);
    } else {
        puts("NO");
    }
}
