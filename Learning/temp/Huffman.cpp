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

priority_queue<int, vector<int>, greater<int> > que;
const int MAXN = 10005;
typedef long long ll;
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        que.push(a);
    }
    ll ans = 0;
    while (que.size() >= 2) {
        ll s = que.top();
        que.pop();
        ll t = que.top();
        que.pop();
        s += t;
        ans += s;
        que.push(s);
    }
    cout << ans << endl;
}