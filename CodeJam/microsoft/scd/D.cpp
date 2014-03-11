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

double a,b,c,d,e;
double the1, the2, the3;
int t;
double area(double u, double v, double w) {
    double p = (u+v+w)/2;
    return sqrt(p*(p-u)*(p-v)*(p-w));
}
double cal() {
    double ret = 0;
    double td = b/2;
    if (a*cos(the3) >= td) {
        ret = 0.5*td*td*tan(the3);
    } else {
        double tmp = a*cos(the3);
        ret = 0.5*tmp*tmp*tan(the3);
        td -= tmp;
        ret += td*a*sin(the3);
    }
    return ret;
}
int main() {
    cin >> t;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= t; ++i) {
        double ans = 0;
        cin >> a >> b >> c >> d >> e;
        if (a == b) {
            ans = area(a,b,e);
        } else {
            double cos1 = (a*a+e*e-b*b)/(2*a*e);
            double cos2 = (b*b+e*e-a*a)/(2*b*e);
            the1 = acos(cos1);
            the2 = acos(cos2);
            the3 = the1+the2;
            double less1 = cal();
            swap(a,b);
            swap(the1,the2);
            double less2 = cal();
            ans = 2*area(a,b,e)-max(less1,less2);
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}
