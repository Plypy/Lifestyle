#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
    int a;
    while (cin >> a) {
        int ans = 1;
        for (int i = 2; i <= a; ++i) {
            int t = i;
            while (0 == t%10)
                t /= 10;
            while (0 == t%5) {
                t /= 5;
                switch (ans) {
                case 2:
                    ans = 6;
                    break;
                case 6:
                    ans = 8;
                    break;
                default:
                    ans >>= 1;
                    break;
                }
            }
            ans = (ans*t)%10;
        }
        printf("%5d -> %d\n", a, ans);
    }
    return 0;
}
