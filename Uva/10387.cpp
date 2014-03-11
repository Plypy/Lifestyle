#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
double a, b, s, m, n;
double angle, velocity;
int main() {
    while (true) {
        scanf("%lf%lf%lf%lf%lf", &a, &b, &s, &m, &n);
        if (0 == a && 0 == b && 0 == s && 0 == m && 0 == n)
            break;
        angle = 180*atan(b*n/(a*m))/M_PI;
        velocity = sqrt(pow(a*m/s,2)+pow(b*n/s,2));
        printf("%.2lf %.2lf\n", angle, velocity);
    }
    return 0;
}
