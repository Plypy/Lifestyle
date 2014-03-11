#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ULL;
int main() {
    int turn = 0;
    while (true) {
        ++turn;
        ULL A, L;
        cin >> A >> L;
        if (A < 0)
            break;
        int ct = 1;
        ULL t = A;
        while (t != 1) {
            if (t&1) {
                t = 3*t+1;
                if (t <= L)
                    ++ct;
                else
                    break;
            } else {
                t >>= 1;
                ++ct;
            }
        }
        cout << "Case " << turn << ": A = " << A << ", limit = " << L << ", number \
of terms = " << ct << endl;
    }
    return 0;
}
