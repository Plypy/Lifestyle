/**
 * Description:
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
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;


double f(double x) {
    x /= 100;
    return 2*x*x*x-4*x*x+3*x-6;
}
int main(int argc, char const *argv[]) {
    double ans = 0;
    for (int i = -1000; i <= 1000; ++i) {
        if (f(i-0.5) <= 0 && 0 < f(i+0.5))
            ans = i/100;
    }
    return 0;
}