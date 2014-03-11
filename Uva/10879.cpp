#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int k = 0;
        cin >> k;
        bool flag = true;
        int a = 0, b = 0, c = 0, d = 0;
        for (int j = 2; j < k; ++j)
            if (0 == k%j) {
                if (flag) {
                    a = j;
                    b = k/j;
                    flag = false;
                } else {
                    c = j;
                    d = k/j;
                    break;
                }
            }
        printf("Case #%d: %d = %d * %d = %d * %d\n", i, k, a, b, c, d);
    }
    return 0;
}
