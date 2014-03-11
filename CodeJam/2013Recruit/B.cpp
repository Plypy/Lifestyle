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

const double g = 9.8;
const double eps = 1e-6;
double pi = acos(-1);
double cal(double v, double d) {
    double t = g*d/v/v;
    t = asin(t)/2;
    return t/pi*180;
}
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= T; ++i) {
        double v, d;
        cin >> v >> d;
        cout << "Case #" << i << ": " << cal(v,d) << endl;
    }
    return 0;
}
