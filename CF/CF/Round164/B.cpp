#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
const int MAXN = 101;
int n;
long long ans = 0;

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i)
        ans += i*(n-i);
    ans += n;
    cout << ans << endl;
    return 0;
}
