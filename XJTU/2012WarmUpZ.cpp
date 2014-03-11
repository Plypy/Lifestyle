#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = n-(n/2);
        int s = int(ceil((n-3.0)/6.0));
        int t = int(ceil(n/2.0));
        ans += (t-s);
        cout << ans << endl;
    }
    return 0;
}
