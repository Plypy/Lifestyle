/**
 * Description: Base conversion
 * Source: hdu 2031
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
const int MAXN = 100;
int n;
int base;
int ans[MAXN];
int main(int argc, char const *argv[]) {
    while (EOF != scanf("%d%d", &n, &base)) {
        int len = 0;
        bool neg = false;
        if (n < 0) {
            n = -n;
            neg = true;
        }
        while (n) {
            ans[++len] = n%base;
            n /= base;
        }
        if (neg) {
            putchar('-');
        }
        for (int i = len; i; --i) {
            int t = ans[i];
            if (t >= 10) {
                t -= 10;
                putchar('A'+t);
            } else {
                printf("%d", t);
            }
        }
        puts("");
    }
    return 0;
}