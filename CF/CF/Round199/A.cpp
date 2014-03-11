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

const int MAXN = 100005;
const int MAXP = 10;
int n;
int ct[MAXP];
int type[MAXP];
bool check() {
    if (ct[5] || ct[7])
        return false;
    if (ct[1] != n)
        return false;
    if (ct[2]+ct[3] != n)
        return false;
    if (ct[4]+ct[6] != n)
        return false;
    if (ct[4] > ct[2])
        return false;
    type[1] = ct[4];
    ct[2] -= ct[4];
    if (ct[2] > ct[6] || ct[2]+ct[3] != ct[6])
        return false;
    type[2] = ct[2];
    type[3] = ct[3];
    return true;
}
int main(int argc, char const *argv[]) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int a;
        scanf("%d", &a);
        ++ct[a];
    }
    n /= 3;
    if (!check()) {
        puts("-1");
    } else {
        for (int i = 0; i < type[1]; ++i)
            puts("1 2 4");
        for (int i = 0; i < type[2]; ++i)
            puts("1 2 6");
        for (int i = 0; i < type[3]; ++i)
            puts("1 3 6");
    }
    return 0;
}