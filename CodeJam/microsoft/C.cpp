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
using namespace std;
const double eps = 1e-10;
const int MAXN = 50005;
struct Dot {
    double x, y;
}pos[MAXN];
int T;
int N;
double sqr(double a) {
    return a*a;
}
double dis(double x, int id) {
    return sqr(pos[id].x-x)+sqr(pos[id].y);
}
double eval(double x) {
    double ret = 0;
    for (int i = 1; i <= N; ++i) {
        double tmp = dis(x,i);
        if (tmp > ret)
            ret = tmp;
    }
    return ret;
}
int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> N;
        double l = -10000, r = 10000;
        for (int i = 1; i <= N; ++i) {
            cin >> pos[i].x >> pos[i].y;
        }
//        for (double i = l; i <= r; i += 0.05) {
//            cout << i << ' ' << eval(i) << endl;
//            system("pause");
//        }
        while (r-l > eps) {
            double mid1 = l+(r-l)/3;
            double mid2 = l+(r-l)*2/3;
            double tmp1 = eval(mid1);
            double tmp2 = eval(mid2);
            if (tmp1 < tmp2)
                r = mid2;
            else
                l = mid1;
//            cout << l << ' ' << r << endl;
//            system("pause");
        }
        cout << fixed << setprecision(12) ;
        cout << "Case #" << t << ": " ;
        cout << r << endl;
    }
    return 0;
}

