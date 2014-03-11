/**
 * Description: Using Picker's law to find the number of grids in a polygon whose vertexs all lies on grid
 * Source: POJ 1265
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;
int gcd(int a, int b) {
    int c;
    while (b) {
        c = a;
        a = b;
        b = c%b;
    }
    return a;
}
struct Point {
    double x, y;
    Point():x(0), y(0) {}
    Point(double a, double b): x(a), y(b) {}
    void scan() {
        scanf("%lf%lf", &x, &y);
    }
};
Point operator-(Point a, Point b) {
    return Point(a.x-b.x,a.y-b.y);
}
Point operator+(Point a, Point b) {
    return Point(a.x+b.x,a.y+b.y);
}
double cross(Point a, Point b) {
    return a.x*b.y-a.y*b.x;
}
double area2(Point a, Point b, Point c) {
    return cross(b-a,c-a);
}
double area(Point *poly, int n) {
    double ret = 0;
    for (int i = 1; i+1 < n; ++i) {
        ret += area2(poly[0],poly[i],poly[i+1]);
    }
    return ret/2;
}
int BorderNumber(Point *poly, int n) {
    int ret = 0;
    poly[n] = poly[0];
    for (int i = 0; i < n; ++i) {
        ret += gcd(abs(int(poly[i+1].x-poly[i].x)), abs(int(poly[i+1].y-poly[i].y)));
    }
    return ret;
}
int InnerNumber(Point *poly, int n) {
    return int(area(poly,n))+1-BorderNumber(poly,n)/2;
}
const int MAXN = 205;
Point polygon[MAXN];
int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas) {
        int n;
        scanf("%d", &n);
        Point pt, move;
        for (int i = 0; i < n; ++i) {
            polygon[i] = pt;
            move.scan();
            pt = pt+move;
            // printf("%lf %lf\n", polygon[i].x, polygon[i].y);
        }
        double A = area(polygon,n);
        int E = BorderNumber(polygon,n);
        int I = int(A)+1-E/2;
        printf("Scenario #%d:\n", cas);
        printf("%d %d %.1lf\n\n", I, E, A);
    }
    return 0;
}