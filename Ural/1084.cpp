#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

const double Pi = 3.1415926;
double a, r;
inline double sqr(double a) {
    return a*a;
}
int main() {
    cin >> a >> r;
    double h_a = a/2;
    double ans = 0;
    if (r <= h_a)
        ans = Pi*sqr(r);
    else if (sqr(r) >= 2*sqr(h_a))
        ans = sqr(a);
    else {
        double c = sqrt(sqr(r)-sqr(h_a));
        double d = h_a-c;
        double e_2 = 2*sqr(d);
        double theta = acos(1-e_2/(2*sqr(r)));
        double triangle = c*h_a;
        double sector = 0.5*sqr(r)*theta;
        ans = 4*(triangle+sector);
    }
    cout << fixed << setprecision(3);
    cout << ans << endl;
//    system("pause");
    return 0;
}
