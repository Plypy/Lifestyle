#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;
const int MAXN = 100005;
struct Data {
    int val, pos;
    int a, b;
} dat[MAXN];
bool cmp1(const Data &a, const Data &b) {
    return a.val < b.val;
}
bool cmp2(const Data &a, const Data &b) {
    return a.pos < b.pos;
}
int n;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        dat[i].val = tmp;
        dat[i].pos = i;
    }
    sort(dat,dat+n,cmp1);
    set<int> useda, usedb;
    int bound = n+2/3;
    int dupa = 0, dupb = 0;
    int init = 0;
    for (int i = 0; i < n; ++i) {
        if (init == 0) {
            init = dat[i].val;
        } else {
            while (init > 0 && useda.find(init) != useda.end())
                --init;
        }
        bool flag = false;
        for (int j = init; j >= 0; --j) {
            int a = j, b = dat[i].val-j;
            if (useda.find(a) == useda.end() && usedb.find(b) == usedb.end()) {
                useda.insert(a);
                usedb.insert(b);
                dat[i].a = a;
                dat[i].b = b;
                flag = true;
                break;
            }
        }
        if (false == flag) {
            int a = 0, b = 0;
            if (dupb < bound) {
                a = init, b = dat[i].val-init;
            } else {
                a = 0, b = dat[i].val;
            }
            if (useda.find(a) != useda.end())
                ++dupa;
            if (usedb.find(b) != usedb.end())
                ++dupb;
            useda.insert(a);
            usedb.insert(b);
            dat[i].a = a;
            dat[i].b = b;
        }
    }
    if (dupa <= bound && dupb <= bound)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    sort(dat,dat+n,cmp2);
    cout << dat[0].a;
    for (int i = 1; i < n; ++i)
        cout << ' ' << dat[i].a;
    cout << endl;

    cout << dat[0].b;
    for (int i = 1; i < n; ++i)
        cout << ' ' << dat[i].b;
    cout << endl;
    return 0;
}
