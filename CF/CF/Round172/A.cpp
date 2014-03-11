// Be careful, consider as much aspects as possible
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;
const double PI = M_PI;
double w, h, ar;
double deg;
double cal(double t) {
    double h = t*tan(deg)+t/tan(deg);
    return h*t;
}
int main() {
    cin >> w >> h >> ar;
    double ans = 0;
    if (w < h)
        swap(w,h);
    if (ar == 0 || ar == 180) {
        ans = w*h;
    }
    else if (ar == 90) {
        int t = min(w,h);
        ans = t*t;
    } else {
        if (ar > 90) {
            ar = 180-ar;
        }
        deg = (ar+0.0)/180*PI;
        double x = w/2.0, y = h/2.0;
        double dy = x*sin(deg)+y*cos(deg)-y;
        double dx = x*cos(deg)+y*sin(deg)-x;
        if (dx < 0) {
            ans = h*h/sin(deg);
        } else {
            ans = w*h-cal(dy)-cal(dx);
        }
    }
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}
