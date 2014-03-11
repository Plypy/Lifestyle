#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            int a, b;
            cin >> a >> b >> b;
            ans += a*b;
        }
        cout << ans << endl;
    }
    return 0;
}
