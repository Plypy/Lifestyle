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
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        double C, F, X;
        scanf("%lf%lf%lf", &C, &F, &X);

        double cur = 0;
        double rate = 2.0;
        double ans = X/rate;
        while (true) {
            double nans = cur+C/rate+X/(rate+F);
            if (nans < ans) {
                ans = nans;
                cur += C/rate;
                rate += F;
            } else {
                break;
            }
        }
        printf("Case #%d: %.8lf\n", i, ans);
    }
    return 0;
}