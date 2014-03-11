#include <iostream>
using namespace std;

int k, n;
int ans;
int main() {
    cin >> k >> n;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        ans += t;
        ans -= k;
        if (ans < 0)
            ans = 0;
    }
    cout << ans << endl;
    return 0;
}
