#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    double h, u, d, f;
    while (true) {
        scanf("%lf%lf%lf%lf", &h, &u, &d, &f);
        if (0 == h)
            break;
        int ct = 0;
        double sum = 0;
        f = u*f/100;
        bool suc = true;
        while (true) {
            ++ct;
            sum += u;
            if (sum > h)
                break;
            sum -= d;
            if (sum < 0) {
                suc = false;
                break;
            }
            u -= f;
            if (u <= 0)
                u = 0;
        }
        printf("%s on day %d\n", suc?"success":"failure", ct);
    }
    return 0;
}
