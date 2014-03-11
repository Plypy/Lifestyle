#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int ans = 1;
    int mult = a;
    for (; b; b >>= 1, mult = (mult*mult)%c) {
        if (b&1) {
            ans = (ans*mult)%c;
        }
    }
    cout << ans << endl;
    return 0;
}
