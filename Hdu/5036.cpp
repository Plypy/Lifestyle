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

const int MAXN = 1005;
typedef bitset<MAXN> state;

int N;

state to[MAXN];


void load() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        to[i].reset();
        to[i][i] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int a;
            cin >> a;
            to[a][i] = 1;
        }
    }
}

double work() {
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            if (to[i][k]) {
                to[i] |= to[k];
            }
        }
    }
    double ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += 1.0/to[i].count();
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(5);
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        load();
        cout << "Case #" << i << ": " << work() << endl;
    }
}
