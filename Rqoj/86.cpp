#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const double INF = 1e10;
int heap[MAXN];
double dis[MAXN];
int handle[MAXN];
inline void exch(int a, int b) {
    swap(handle[heap[a]],handle[heap[b]]);
    swap(heap[a],heap[b]);
}
inline void heapfy(int pos) {
    int l, r, tmp;
    while (true) {
        l = pos<<1;
        r = l+1;
        tmp = pos;
        if (l <= heap[0] && dis[heap[l]] < dis[heap[tmp]])
            tmp = l;
        if (r <= heap[0] && dis[heap[r]] < dis[heap[tmp]])
            tmp = r;
        if (tmp == pos)
            break;
        exch(pos,tmp);
        pos = tmp;
    }
}
inline void decrease(int pos, double nval) {
    dis[heap[pos]] = nval;
    for (int i = pos; i > 1 && dis[heap[i]] < dis[heap[i>>1]]; i >>= 1)
        exch(i,i>>1);
}
inline int extract() {
    int ret = heap[1];
    exch(1,heap[0]--);
    heapfy(1);
    return ret;
}

inline double min(double a, double b) {
    return a<b?a:b;
}

double g[MAXN][MAXN];
int x[MAXN], y[MAXN];
int n, v;
void load() {// load file and do the initial job
    scanf("%d%d", &n, &v);
    heap[0] = n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            g[i][j] = INF;
    int t;
    for (int i = 1; i <= n; ++i) {
        dis[i] = INF;
        heap[i] = handle[i] = i;
        scanf("%d%d%d", x+i, y+i, &t);
        g[i][t] = g[t][i] = min(hypot(x[i]-x[t],y[i]-y[t])/v,g[i][t]);
    }
    dis[1] = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (i != j && x[i] == x[j] && y[i] > y[j])
                g[i][j] = min(g[i][j],sqrt(double(y[i]-y[j])/5.0));
        }
}

void work() {
    while (true) {
        int cur = extract();
//        cout << cur << endl;
        if (cur == n)
            break;
        for (int i = 1; i <= n; ++i)
            if (dis[cur] + g[cur][i] < dis[i]) {
//                cout << i << endl;
                decrease(handle[i],dis[cur]+g[cur][i]);
            }
//        cout << endl;
    }
    printf("%.2lf\n", dis[n]);
//    system("pause");
}

int main() {
    load();
    work();
    return 0;
}
/*
9 1
5 0 0
5 5 1
6 5 2
7 6 2
6 9 2
3 6 2
4 5 2
3 2 7
7 2 3

ans
8.13
*/
