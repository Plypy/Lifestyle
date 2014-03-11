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
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXN = 200005;
typedef long long ll;

struct Data {
    int a, b;
};
Data dat[MAXN];
int n, k;
typedef priority_queue<int> pque;
const ll INF = 100000000000000LL;
pque &min(pque &a, pque &b) {
    if (a.empty())
        return b;
    if (b.empty())
        return a;
    if (a.top() > b.top())
        return a;
    return b;
}
class A {
    // do nothing;
};
ll win(int a, int ned) {
    pque common, special;
    for (int i = 0; i < n; ++i) {
        if (dat[i].a == a || dat[i].a == a-1)
            special.push(-dat[i].b);
        else
            common.push(-dat[i].b);
    }
    ll ret = 0;
    int ct = 0;
    while (ct < ned) {
        ++ct;
        ret -= special.top();
        special.pop();
    }
    while (ct < a) {
        pque & t = min(special,common);
        ++ct;
        if (t.empty()) {
            ret = INF;
            break;
        }
        ret -= t.top();
        t.pop();
    }
    // if (n == 15 && k == 15) {
    //     cout << a << ' ' << ned << ' ' << ret << endl;
    // }
    return ret;
}
int s[MAXN];
int getsval(int idx) {
    if (idx < 0)
        return 0;
    return s[idx];
}
int main(int argc, char const *argv[]) {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &dat[i].a, &dat[i].b);
        s[dat[i].a]++;
    }
    int Q = n+1-k, P = -1;
    for (int i = 0; i <= n; ++i) {
        if (i)
            s[i] += s[i-1];
        if (s[i] >= Q) {
            P = i;
            break;
        }
    }
    if (-1 == P) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = min(win(P,Q-getsval(P-2)), win(P+1,Q-getsval(P-1)));
    ans = min(ans,win(P+2,0));
    if (ans == INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}