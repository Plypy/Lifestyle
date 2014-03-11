/**
 * Description:
 * Author: Ply_py
 */
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
#include <cmath>
using namespace std;

const int MAXN = 15005;
int n;
int main() {
    cin >> n;
    set<int> f;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        f.insert(a);
    }
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (f.count(a))
            ++ans;
    }
    cout << ans << endl;
    return 0;
}
