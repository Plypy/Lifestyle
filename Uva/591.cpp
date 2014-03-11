#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 55;
int h[MAXN];
int n;
int main() {
    int ct = 0;
    while (true) {
        cin >> n;
        if (!n)
            break;
        h[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> h[i];
            h[0] += h[i];
        }
        h[0] /= n;
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans += abs(h[i]-h[0]);
        ans >>= 1;
        cout << "Set #" << ++ct << endl;
        cout << "The minimum number of moves is " << ans << "." << endl;
        cout << endl;
    }
    return 0;
}
