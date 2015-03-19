/**
 * Description: basic KMP (with Pratt's optimization), however the P's opt isn't
 *     very evident.
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
#include <bitset>
#include <stack>
using namespace std;

const int MAXN = 1000005;
const int MAXM = 10005;
char s[MAXN];
char p[MAXM];

int next[MAXM];

int N, M;
void getnext() {
    int i = 0, j = -1;
    next[0] = -1;
    while (i < M) {
        if (-1 == j || p[i] == p[j]) {
            ++i;
            ++j;
            if (p[i] == p[j]) {
                next[i] = next[j];
            } else {
                next[i] = j;
            }
        } else {
            j = next[j];
        }
    }
}


void work() {
    getnext();
    int ans = 0;
    int i = 0, j = 0;
    while (i < N) {
        if (-1 == j || s[i] == p[j]) {
            ++i;
            ++j;
        } else {
            j = next[j];
        }
        if (j == M) {
            ++ans;
            j = next[j];
        }
    }
    printf("%d\n", ans);
}

void load() {
    cin >> p >> s;
    N = strlen(s);
    M = strlen(p);
}

void clear() {
    memset(next,0,sizeof(next));
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        load();
        work();
        clear();
    }
}
