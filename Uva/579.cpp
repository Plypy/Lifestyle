#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;
const double unith = 30;
const double unitm = 6;
const double mperh = 60;
const double half = 180;
int main() {
    int h, m;
    char ch;
    while (true) {
        scanf("%d%c%d", &h, &ch, &m);
        if (0 == h && 0 == m)
            break;
        double ha = (h+m/mperh)*unith;
        double ma = m*unitm;
        double ans = abs(ha-ma);
        if (ans > half)
            ans = 2*half-ans;
        printf("%.3lf\n", ans);
    }
    return 0;
}
