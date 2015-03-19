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

const int MAXD = 300;
const int INF = 1e8;

int divm(int a, int b) {
    if (0 == b) {
        return INF;
    }
    return (a+b-1)/b;
}

// Yang, Monster
bool check(int h1, int a1, int d1, int h2, int a2, int d2) {
    int ans1 = divm(h1, max(0, a2-d1));
    int ans2 = divm(h2, max(0, a1-d2));
    // cout << ans1 << ' ' << ans2 << endl;
    if (INF == ans2) {
        return false;
    }
    return ans1 > ans2;
}

int main() {
    // check(100, 2, 1, 1, 100, 1);
    // while (true) {

    // }
    int h1, a1, d1;
    int h2, a2, d2;
    int hp, ap, dp;
    cin >> h1 >> a1 >> d1;
    cin >> h2 >> a2 >> d2;
    cin >> hp >> ap >> dp;
    int ans = 1e8;
    int matk = max(0, h2+d2-a1);
    int mdef = max(0, a2-d1);
    int mhp = 1000;
    for (int i = 0; i <= mhp; ++i) {// dhp
        for (int j = 0; j <= matk; ++j) {// datk
            for (int k = 0; k <= mdef; ++k) {// ddef
                int pr = i*hp+j*ap+k*dp;
                if (!check(h1+i, a1+j, d1+k, h2, a2, d2)) {
                    continue;
                }
                if (pr < ans) {
                    ans = pr;
                }
            }
        }
    }
    cout << ans << endl;
}
