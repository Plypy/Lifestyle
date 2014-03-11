#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
using namespace std;
int n, d;
void load() {
    cin >> n >> d;
}
void work() {
    int pre = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t <= pre) {
            int inc = (pre-t+d)/d;
            ans += inc;
            t = t+d*inc;
        }
        pre = t;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    load();
    work();
    return 0;
}
