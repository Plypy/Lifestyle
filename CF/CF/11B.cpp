#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cmath>
using namespace std;
long long x;
int main() {
    ios::sync_with_stdio(false);
    cin >> x;
    x = abs(x);
    int t = sqrt(2*x);
    while (true) {
        int s = t*(t+1)/2-x;
        if (s >= 0 && 0 == s%2) {
            break;
        }
        ++t;
    }
    cout << t << endl;
    return 0;
}
//485658989
