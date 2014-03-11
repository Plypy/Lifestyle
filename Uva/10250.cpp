//不用解方程...
//正方形比较特殊 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    double x1, y1, x2, y2;
    while (EOF != scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2)) {
        double x0 = (x1+x2)/2, y0 = (y1+y2)/2;
        double dx = x1-x0, dy = y1-y0;
        double x3 = x0+dy, x4 = x0-dy;
        double y3 = y0-dx, y4 = y0+dx;
        printf("%.10lf %.10lf %.10lf %.10lf\n", x3, y3, x4, y4);
    }
    return 0;
}
