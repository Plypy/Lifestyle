#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 10005;
int a[MAXN], b[MAXN];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = 0;
    for (;b[1] <= 1 && b[1] <= a[1]; ++b[1]) {
        b[2] = a[1]-b[1];
        if (b[2] < 0 || b[2] > 1)
            continue;
        bool suc = true;
        for (int i = 3; i <= n; ++i) {
            b[i] = a[i-1]-b[i-1]-b[i-2];
            if (b[i] < 0 || b[i] > 1) {
                suc = false;
                break;
            }
        }
        if (suc && a[n] == b[n-1]+b[n])
            ++ans;
    }
    cout << ans << endl;
//    system("pause");
    return 0;
}
