#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int n;
int main() {
    scanf("%d", &n);
    int ans = 0;
    int pre = 0;
    for (int i = 1; i <= n; ++i) {
        int t;
        scanf("%d", &t);
        if (t > pre) {
            ++ans;
        } else {
            ans = 1;
        }
        pre = t;
    }
    cout << n-ans << endl;
    return 0;
}
