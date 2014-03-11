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
const int MAXN = 200005;
typedef long long LL;
LL n;
LL len = 1;
LL app[MAXN];
LL num[MAXN];
double sum;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cout << fixed << setprecision(8);
    for (LL i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            LL a, b;
            cin >> a >> b;
            app[a] += b;
            sum += a*b;
        } else if (t == 2) {
            LL a;
            cin >> a;
            num[++len] = a;
            sum += a;
        } else {
            sum -= num[len];
            sum -= app[len];
            app[len-1] += app[len];
            app[len] = 0;
            --len;
        }
        cout << sum/len << endl;
    }
    return 0;
}
