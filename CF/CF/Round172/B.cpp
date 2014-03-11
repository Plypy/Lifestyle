#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
using namespace std;
const int MAXN = 100005;
int n;
int cal(vector<int> t) {
    int ret = 0;
    stack<int> stk;
    stk.push(t[0]);
    for (int i = 1; i < n; ++i) {
        while (stk.size() && stk.top() < t[i]) {
            stk.pop();
        }
        if (stk.size()) {
            ret = max(ret,stk.top()^t[i]);
        }
        stk.push(t[i]);
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = cal(a);
    reverse(a.begin(),a.end());
    ans = max(ans,cal(a));
    cout << ans << endl;
    return 0;
}
