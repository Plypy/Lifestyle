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

const int MAXN = 200005;
const int MOD = 1000000007;

#define DEC(X) if ((X) >= MOD) X -= MOD
int f[MAXN];

int main() {
    int a, b;
    cin >> a >> b;
    int s = a+b;
    int h = 0;
    while (h*(h+1) <= 2*s) {
        ++h;
    }
    --h;
    f[0] = 1;
    int ts = 0;
    if (a > b) {
        swap(a,b);
    }
    for (int i = 1; i <= h; ++i) {
        ts = min(ts+i, a);

        for (int j = ts; j >= i; --j) {
            f[j] += f[j-i];
            DEC(f[j]);
        }
    }
    int ans = 0;
    s = h*(h+1)/2;
    for (int i = max(s-b,0); i <= a; ++i) {
        ans += f[i];
        DEC(ans);
    }
    cout << ans << endl;
}
