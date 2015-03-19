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

const int MAXN = 105;
int N, S;
int ans[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> S;
    if (S == 0) {
        if (N != 1) {
            puts("-1 -1");
        } else {
            puts("0 0");
        }
        return 0;
    }
    int ts = S;
    bool flag = true;
    for (int i = 0; i < N; ++i) {
        int minimum = (0 == i ? 1 : 0);
        int rest = (N-i-1)*9;
        int tmp = ts-rest;
        if (tmp > 9) {
            flag = false;
        }
        ans[i] = max(minimum, tmp);
        ts -= ans[i];
    }
    if (!flag) {
        puts("-1 -1");
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i];
    }
    cout << endl;
    ts = S;
    for (int i = 0; i < N; ++i) {
        int pos = N-i-1;
        int rest = (N-i-1)*9;
        int tmp = ts-rest;
        ans[pos] = max(0, tmp);
        ts -= ans[pos];
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i];
    }
    cout << endl;
}
