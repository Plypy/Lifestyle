#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

const int MAXN = 101;
int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    n = min(n,m);
    cout << n+1 << endl;
    for (int i = 0; i <= n; ++i)
        cout << i << ' ' << n-i << endl;
    return 0;
}

