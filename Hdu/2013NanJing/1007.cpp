/**
 * Description: A math problem involving multi-dimensional integral
 * Source: 2013 NanJing onsite "Drunk"
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

double pi = acos(-1.0);
const int MAXN = 200005;
double t[MAXN];
int n;
double r;
int main() {
    t[0] = pi/2;
    t[1] = 1;
    for (int i = 2; i < MAXN; ++i)
        t[i] = double(i-1)/i*t[i-2];
    while (EOF != scanf("%d%lf", &n, &r)) {
        double ans = 0.5*t[n+1]*r/t[2];
        printf("%.8lf\n", ans);
    }
}