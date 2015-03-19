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
#include <bitset>
#include <stack>
using namespace std;


char dig[15];
int len;
void init() {
    cin >> dig;
    len = strlen(dig);
}

char ans[15];
void getmin() {
    memcpy(ans, dig, sizeof(dig));
    for (int j = 0; j < len; ++j) {
        for (int i = len-1; i > j; --i) {
            if (0 == j && '0' == ans[i])
                continue;
            if (ans[i] < ans[j]) {
                swap(ans[i], ans[j]);
                return;
            }
        }
    }
}

void getmax() {
    memcpy(ans, dig, sizeof(dig));
    for (int j = 0; j < len; ++j) {
        for (int i = len-1; i > j; --i) {
            if (0 == j && '0' == ans[i])
                continue;
            if (ans[i] > ans[j]) {
                swap(ans[i], ans[j]);
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        init();
        cout << "Case #" << i+1 << ": ";
        getmin();
        cout << ans << ' ';
        getmax();
        cout << ans << endl;
    }
}
