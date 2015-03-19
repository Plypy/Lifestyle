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

const int MAXN = 15;
int fa[MAXN];
int n = 3;

int cube(int a) {
    return a*a*a;
}

int main(int argc, char const *argv[]) {
    int a;
    scanf("%d", &a);
    int t = a;
    for (int i = 1; i <= n; ++i) {
        fa[i] = t%10;
        t /= 10;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += cube(fa[i]);
    }
    if (ans == a) {
        puts("good")goo;
    } else {
        puts("bad");
    }
    return 0;
}
