/**
 * Description:
 * Source: 2010 fuzhou regional, hdu 3697
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

const int MAXN = 305;
struct Course {
    int l, r;
    bool operator<(const Course &t) const {
        if (t.r == r)
            return l<t.l;
        return r<t.r;
    }
} course[MAXN];
int n;
bool load() {
    scanf("%d", &n);
    if (0 == n)
        return false;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &course[i].l, &course[i].r);
    }
    return true;
}
bool used[MAXN];
int work() {
    sort(course,course+n);
    int ret = 0;
    for (int i = 0; i < 5; ++i) {
        int tmp = 0;
        memset(used,false,sizeof(used));
        for (int pos = i; pos < course[n-1].r; pos += 5) {
            for (int j = 0; j < n; ++j)
                if (!used[j] && course[j].l <= pos && course[j].r > pos) {
                    ++tmp;
                    used[j] = true;
                    break;
                }
        }
        ret = max(tmp,ret);
    }
    return ret;
}
int main() {
    while (load()) {
        printf("%d\n", work());
    }
}