#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        if (k < 0)
            k = -k;
        int n = 1;
        while (true) {
            int s = n*(n+1)/2;
            if (s >= k && !((s-k)&1))
                break;
            ++n;
        }
        cout << n << endl;
        if (t)
            cout << endl;
    }
    return 0;
}
