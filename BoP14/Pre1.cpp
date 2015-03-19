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
using namespace std;

double mult(char *str) {
    if (0 == strcmp(str,"mm"))
        return 1e-3;
    if (0 == strcmp(str,"m"))
        return 1;
    if (0 == strcmp(str,"dm"))
        return 1e-1;
    if (0 == strcmp(str,"cm"))
        return 1e-2;
    if (0 == strcmp(str,"um"))
        return 1e-6;
    if (0 == strcmp(str,"nm"))
        return 1e-9;
    return 1;
}
double a, b, c;
char s[3][20];
void load() {
    scanf("%lf%s%lf%s%lf%s", &a, s[0], &b, s[1], &c, s[2]);
    // cout << a << ' ' << b << ' ' << c << endl;
}
double work() {
    a *= mult(s[0]);
    b *= mult(s[1]);
    c *= mult(s[2]);
    return c*a/b;
}
int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        load();
        printf("Case %d: %.2fpx\n", t, work());
    }
    return 0;
}