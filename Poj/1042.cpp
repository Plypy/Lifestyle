/**
 * Description: A greedy problem on black book
 * Source: POJ 1042/ East Central North America, Gone Fishing
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

const int MAXN = 30;

int n, h;
int fish[MAXN];
int decs[MAXN];
int cost[MAXN];

bool load() {
    scanf("%d", &n);
    if (0 == n)
        return false;
    scanf("%d", &h);
    h *= 12;
    for (int i = 1; i <= n; ++i)
        scanf("%d", fish+i);
    for (int i = 1; i <= n; ++i)
        scanf("%d", decs+i);
    for (int i = 1; i < n; ++i) {
        scanf("%d", cost+i);
        cost[i] += cost[i-1];
    }
    return true;
}

struct Pool {
    int id;
    int sum;
    int dec;
    Pool(int a = 0, int b = 0, int c = 0):id(a), sum(b), dec(c) { }
    int extract() {
        int ret = sum;
        sum -= dec;
        if (sum < 0)
            sum = 0;
        return ret;
    }
    bool operator<(const Pool &t) const {
        if (sum != t.sum)
            return sum<t.sum;
        return id>t.id;
    }
} pool[MAXN];

int plan[MAXN];
int greedy(int last) {
    int ret = 0;
    memset(plan,0,sizeof(plan));

    int th = h-cost[last-1];
    priority_queue<Pool> que;

    for (int i = 1; i <= last; ++i) {
        que.push(Pool(i,fish[i],decs[i]));
    }
    for (int i = 1; i <= th; ++i) {
        Pool tp = que.top();
        que.pop();
        int delta = tp.extract();
        ret += delta;
        ++plan[tp.id];
        que.push(tp);
    }
    return ret;
}

int anslist[MAXN];
int ans = -1;
void work() {
    ans = -1;
    for (int i = 1; i <= n; ++i) {
        int t = greedy(i);
        if (t > ans) {
            ans = t;
            memcpy(anslist,plan,sizeof(plan));
        }
    }
}
bool flag;
void output() {
    if (flag) {
        puts("");
    } else {
        flag = true;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d",anslist[i]*5);
        if (i < n)
            printf(", ");
        else
            puts("");
    }
    printf("Number of fish expected: %d\n", ans);
}
int main() {
    while (load()) {
        work();
        output();
    }
    return 0;
}