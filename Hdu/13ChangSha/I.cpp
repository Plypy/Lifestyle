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


const int MAXS = 1<<21;
const int MAXB = 25;
const int MAXN = 25;
const int INF = 100000;
int bag[MAXB][MAXN];
int mem[MAXS];
int B, G, S;
int final;
int ct[MAXN];
int melt() {
    int ret = 0;
    for (int i = 1; i <= G; ++i) {
        ret += ct[i]/S;
        ct[i] %= S;
    }
    return ret;
}
void add(int x) {
    for (int i = 1; i <= bag[x][0]; ++i)
        ++ct[bag[x][i]];
}
void disp() {
    cout << "display ct" << endl;
    for (int i = 1; i <= G; ++i)
        cout << ct[i] << ' ';
    cout << endl;
}
int dfs(int state) {
    if (mem[state] != -1)
        return mem[state];
    int ret = -INF;
    int buf[MAXN];
    memcpy(buf, ct, sizeof(ct));
    for (int i = 1; i <= B; ++i) {
        int t = 1<<(i-1);
        if ((state^t) == (state+t)) {
            int ns = state^t;
            // disp();
            add(i);
            int delta = melt();
            // disp();
            int tmp = dfs(ns);
            if (delta) {
                ret = max(ret,delta+tmp);
            } else {
                ret = max(ret,delta-tmp);
            }
            memcpy(ct, buf, sizeof(ct));
        }
    }
    return mem[state] = ret;
}
bool load() {
    scanf("%d%d%d", &G, &B, &S);
    final = (1<<B)-1;
    mem[final] = 0;
    if (B == 0)
        return false;
    for (int i = 1; i <= B; ++i) {
        scanf("%d", &bag[i][0]);
        for (int j = 1; j <= bag[i][0]; ++j)
            scanf("%d", &bag[i][j]);
    }
    return true;
}
void work() {
    printf("%d\n", dfs(0));
}
void init() {
    memset(mem,-1,sizeof(mem));
    memset(ct,0,sizeof(ct));
}
int main(int argc, char const *argv[]) {
    while (true) {
        init();
        if (!load())
            break;
        work();
    }
    return 0;
}