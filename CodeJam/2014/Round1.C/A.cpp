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


typedef long long ll;

ll lowbit(ll a) {
    return a&-a;
}
ll gcd(ll a, ll b) {
    if (b)
        return gcd(b,a%b);
    return a;
}
ll A, B;
void load() {
    char c;
    scanf("%lld/%lld", &A, &B);
}

ll work() {
    ll t = gcd(A,B);
    A /= t;
    B /= t;
    if (B != lowbit(B)) {
        return -1;
    }
    while (A != 1) {
        A >>= 1;
        B >>= 1;
    }
    int ans = 0;
    while (B != 1) {
        ++ans;
        B >>= 1;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        load();
        ll ans = work();
        printf("Case #%d: ", t);
        if (ans == -1) {
            cout << "impossible" << endl;
        } else
            cout << ans << endl;
    }
    return 0;
}
