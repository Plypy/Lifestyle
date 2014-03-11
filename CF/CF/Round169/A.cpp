#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;
const int MAXN = 10005;

int main() {
    int n, k;
    cin >> n >> k;
    int ans = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        int tmp = 0;
        int t, f;
        cin >> f >> t;
        if (t <= k)
            tmp = f;
        else
            tmp = f-(t-k);
        ans = max(ans,tmp);
    }
    cout << ans << endl;
}
