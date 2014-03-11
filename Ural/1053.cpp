//有这样一个事实
//gcd(a,b) = gcd(a,b-a), a<b 
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

inline int gcd(int a, int b) {
    while (b) {
        int c = a;
        a = b;
        b = c%b;
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    int ans;
    cin >> ans;
    for (int i = 2; i <= n; ++i) {
        int t;
        cin >> t;
        ans = gcd(ans,t);
    }
    cout << ans << endl;
    return 0;
}
