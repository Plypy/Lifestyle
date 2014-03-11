/**
 * Description: Solving multiy unknowns module equations
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

const int MAXN = 105;

int a[MAXN];
int n;
int b, p;
void load() {
    scanf("%d%d%d", &n, &p, &b);
    for (int i = 0; i < n; ++i)
        scanf("%d", a+i);
}

int extend_gcd(int a, int b, int &x, int &y) {
    if (0 == b) {
        x = 1, y = 0;
        return a;
    }
    int r = extend_gcd(b, a%b, y, x);
    y -= x*(a/b);
    return r;
}
int cx[MAXN], cy[MAXN];

void work() {
    a[n] = p;
    int gcd = a[0];
    for (int i = 1; i <= n; ++i) {
        gcd = extend_gcd(gcd, a[i], cx[i], cy[i]);
    }
    cy[0] = 1;
    if (b%gcd) {
        puts("NO");
    } else {
        puts("YES");
        int mult = (b/gcd)%p;
        // int mult = b/gcd;
        for (int i = n; i >= 0; --i) {
            // cy[i] = cy[i]*mult;
            // mult = mult*cx[i];
            cy[i] = ((cy[i]*mult)%p+p)%p;
            mult = ((mult*cx[i])%p+p)%p;
        }
        for (int i = 0; i < n; ++i)
            printf("%d%c", cy[i], i==(n-1)?'\n':' ');
    }
}

int main(int argc, char const *argv[]) {
    load();
    work();
    return 0;
}