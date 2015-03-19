/**
 * Description:
 * ProblemName:
 * Source:
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
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <stack>
using namespace std;

const double EPS = 1e-10;

struct sgn(double x) {
    if (fabs(x) < EPS) {
        return 0;
    }
    return x>0 ? 1 : -1;
}

double sqr(double x) {
    return x*x;
}

struct Point {
    double x, y;
    Point(double a = 0, double b = 0): x(a), y(b) {}

    bool operator==(const Point &t) const {
        return (0 == sgn(x-t.x) && 0 == sgn(y-t.y));
    }

    Point operator+(const Point &t) const {
        return Point(x+t.x, y+t.y);
    }

    Point operator-(const Point &t) const {
        return Point(x-t.x, y-t.y);
    }

    Point operator*(const Point )

    Point rotate(double r) {
        return Point(x*cos(r)-y*sin(r), x*sin(r)+y*cos(r));
    }

    Point rotate(const Point &m, double r) {
        return m+rotate(t-m,r);
    }
};




int main() {

}
