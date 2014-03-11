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
int n, m;
int a[MAXN];
int INC[MAXN], DEC[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    DEC[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] <= a[i-1])
            DEC[i] = DEC[i-1];
        else
            DEC[i] = i;
    }
    INC[n] = n;
    for (int i = n-1; i; --i) {
        if (a[i] <= a[i+1])
            INC[i] = INC[i+1];
        else
            INC[i] = i;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (INC[l] >= DEC[r])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
