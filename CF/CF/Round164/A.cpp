#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

const int MAXN = 101;
int n;
int h[MAXN], g[MAXN];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        ++h[a], ++g[b];
    }
    int ans = 0;
    for (int i = 1; i < MAXN; ++i)
        ans += h[i]*g[i];
    cout << ans << endl;
    return 0;
}
