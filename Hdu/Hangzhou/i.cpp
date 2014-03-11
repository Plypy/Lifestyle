/**
 * Description:
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
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;
const int MAXN = 500001;
const int MAXP = 50000;

int n, m, p;
bool notp[MAXN];
int pnum[MAXN];
vector<int> plis;
int len;
void init() {
    for (int i = 2; i < MAXN; ++i) {
        if (!notp[i]) {
            plis.push_back(i);
            pnum[i] = 1;
            // int mult = i;
            for (int j = i+i; j < MAXN; j += i) {
                ++pnum[j];
                int di = j/i;
                while (di%i == 0) {
                    ++pnum[j];
                    di /= i;
                }
                notp[j] = true;
            }
        }
    }
    len = plis.size();
}
typedef long long lld;
long long ans;
lld d[MAXN];
void clear() {
    memset(d,0,sizeof(d));
    ans = 0;
}
int bd, ubd;
// void dfs(int rem, lld t, int st) {
//     // cout << rem << ' ' << t << ' ' << st << endl;
//     ans += d[t];
//     if (rem == 0)
//         return;
//     for (int i = st; i < len; ++i) {
//         if (t*plis[i] > ubd)
//             break;
//         dfs(rem-1,t*plis[i],i);
//     }
// }
lld work() {
    if (p >= 19)
        return lld(n)*m;
    bd = min(n,m);
    ubd = max(n,m);
    for (int i = bd; i; --i) {
        d[i] = ((lld)n/i)*(m/i);
        for (int j = i+i; j <= bd; j += i)
            d[i] -= d[j];
    }
    // cout << ubd << endl;
    for (int i = 1; i <= ubd; ++i)
        if (pnum[i] <= p)
            ans += d[i];
    return ans;
}

void getInt(int &x) {
    static char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    for (x = 0; (c >= '0') && (c <= '9'); c = getchar()) x = x * 10 + c - '0';
}

void load() {
    //scanf("%d%d%d", &n, &m, &p);
    getInt(n),getInt(m),getInt(p);
}
int st;
void test() {
    // for (int i = 1; i <= 100; ++i)
    //     cout << i << ' ' << pnum[i] << endl;
    for (int i = 1; i <= 5000; ++i) {
        n = m = 500000;
        p = 18;
        printf("%I64d\n", work());
        // cout << clock()-st << endl;
        clear();
    }
    cout << clock()-st << endl;
}
int main(int argc, char const *argv[]) {
    // st = clock();
    init();
    test();
    // cout << plis.size();
    int T;
    scanf("%d", &T);
    // T = 5000;
    // int st = time(0);
    if (T >= 50)
        T = 50;
    for (int i = 1; i <= T; ++i) {
        load();
        printf("%I64d\n",work());
        // test();
        // cout << time(0)-st << endl;
        clear();
    }
    return 0;
}