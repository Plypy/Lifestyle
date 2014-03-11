/**
 * Description: Check if two 3d triangles intersects
 * Source: AOAPC UVA 11275
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

const double eps = 0.000001;
int dblcmp(double x) {
    if (fabs(x) < eps)
        return 0;
    return x > 0 ? 1:-1;
}

typedef struct Point3 {
    double x, y, z;
    Point3() {}
    Point3(double x, double y, double z): x(x), y(y), z(z) {}
} Vector3;

Vector3 operator-(Vector3 a, Vector3 b) {
    return Vector3(a.x-b.x,a.y-b.y,a.z-b.z);
}

Vector3 operator*(double d, Vector3 v) {
    return Vector3(d*v.x,d*v.y,d*v.z);
}

Vector3 operator*(Vector3 v, double d) {
    return d*v;
}

Vector3 cross(Vector3 a, Vector3 b) {
    return Vector3(a.y*b.z-a.z-b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}

double dot(Vector3 a, Vector3 b) {
    return a.x*b.x+a.y*b.y+a.z*b.z;
}


double length(Vector3 a) {
    return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
}

double isParallel(Vector3 a, Vector3 b) {
    return 0 == dblcmp(length(cross(a, b)));
}

double area2(Point3 a, Point3 b, Point3 c) {
    return length(cross(b-a, c-a));
}

double volume6(Point3 a, Point3 b, Point3 c, Point3 d) {
    return dot(d-a,cross(b-a, c-a));
}

bool isIntersect(Point3 a, Point3 b, Point3 c, Point3 d) {
    double vol = volume6(a, b, c, d);
    if (0 != dblcmp(vol))
        return false;
    Vector3 v1 = b-a, v2 = d-c;

}

struct Triangle {
    Point3 pt[3];
    Vector3 n;
    double area;
    Triangle() {}
    Triangle(Point3 a, Point3 b, Point3 c) {
        pt[0] = a, pt[1] = b, pt[2] = c;
        area = area2(a , b, c);
        n = cross(c-a, c-b);
    }
    bool isInTriangle(Point3 &p) {
        double a = area2(pt[0], pt[1], p);
        double b = area2(pt[1], pt[2], p);
        double c = area2(pt[2], pt[0], p);
        double d = area2(pt[0], pt[1], pt[2]);
        return 0 == dblcmp(d-a-b-c);
    }
    bool isIntersect(Point3 a, Point3 b) {
        Vector3 v = b-a;
        if (0 == dblcmp(dot(n, v))) {

        } else {

        }
    }
};

int main(int argc, char const *argv[]) {
    /* code */
    return 0;
}