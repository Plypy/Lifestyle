#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;
const int MAXN = 100005;
int a[MAXN];
int n, t;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> t;
    int ans = 0;
    queue<int> que;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int tmp;
        cin >> tmp;
        que.push(tmp);
        sum += tmp;
        while (sum > t) {
            sum -= que.front();
            que.pop();
        }
        if (que.size() > ans)
            ans = que.size();
    }
    cout << ans << endl;
    return 0;
}
