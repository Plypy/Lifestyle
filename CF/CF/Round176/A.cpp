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
using namespace std;
const int MAXN = 100005;
int n;
int ans[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    if (n % 4 > 1) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= n/4; ++i) {
        int a = 2*i-1;
        int b = 2*i;
        ans[a] = b;
        ans[b] = n-a+1;
        ans[n-a+1] = n-b+1;
        ans[n-b+1] = a;
    }
    if (n%2) {
        ans[n/2+1] = n/2+1;
    }
    cout << ans[1];
    for (int i = 2; i <= n; ++i)
        cout << ' ' << ans[i];
    cout << endl;
    return 0;
}
