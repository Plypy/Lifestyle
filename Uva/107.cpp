//注意等比数列求和要讨论公比是否为1 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
const int MAXP = 30;
const double INFS = 1e-6;

int main() {
    double ht, amt;
    while (true) {
        scanf("%lf%lf", &ht, &amt);
        if (0 == ht)
            break;
        if (1 == ht) {
            printf("0 1\n");
            continue;
        }
        int b = 0, p = 0;
        for (int i = 1; i <= MAXP; ++i) {
            double t1 = pow(ht,1.0/i);
            double t2 = pow(amt,1.0/i);
            if (abs(t1-t2-1) < INFS) {
                b = int(t2+0.5);
                p = i;
                break;
            }
        }
        int ans1 = 0, ans2 = int(amt);
        int t1 = int(amt), t2 = 1;
        for (int i = 1; i <= p; ++i) {
            t2 *= (b+1);
            t1 /= b;
            ans1 += t1;
            ans2 += t1*t2;
        }
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
