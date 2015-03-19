/**
 * Description: 2-SAT problem, and it also needs to find a specific solution
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
#include <cassert>
using namespace std;

const int MAXN = 1010;
const int MAXV = MAXN*2;
const int MAXE = MAXV*MAXV;
int vn;
struct Edge {
    int vtx;
    Edge *nxt;
    Edge() { };
    Edge(int iv, Edge* in): vtx(iv), nxt(in) {}
} epool[MAXE], *adj[MAXV], *tadj[MAXV], *eptr = epool;

void add(int u, int v) {
    adj[u] = new (eptr++) Edge(v,adj[u]);
    tadj[v] = new (eptr++) Edge(u,tadj[v]);
}

bool used[MAXV];
int color[MAXV];
int table[MAXV];
void dfs(int u) {
    used[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (!used[v]) {
            dfs(v);
        }
    }
    table[++table[0]] = u;
}

void kosaraju(int u) {
    used[u] = false;
    color[u] = color[0];
    for (Edge *t = tadj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (used[v]) {
            kosaraju(v);
        }
    }
}

int cal(int i) {
    if (i&1) {
        return i+1;
    }
    return i-1;
}

void contradict(int i, int j) {
    add(i, cal(j));
    add(j, cal(i));
}

int N;
int a[MAXN], b[MAXN], c[MAXN];

void build() {
    for (int i = 1; i <= N; ++i) {
        for (int j = i+1; j <= N; ++j) {
            if (a[i] == a[j]) {
                contradict(2*i-1, 2*j-1);
            }
            if (i == b[j] || a[i] == c[j]) {
                contradict(2*i-1, 2*j);
            }
            if (j == b[i] || a[j] == c[i]) {
                contradict(2*j-1, 2*i);
            }
            if (b[i] == b[j]) {
                contradict(2*i, 2*j);
            }
        }
    }
}

bool check() {
    for (int i = 1; i < vn; i += 2) {
        if (color[i] == color[i+1]) {
            return false;
        }
    }
    return true;
}

int opp[MAXV];
bool del[MAXV];
void work() {
    build();
    vn = N*2;

    for (int i = 1; i <= vn; ++i) {
        if (!used[i]) {
            dfs(i);
        }
    }

    for (int i = table[0]; i; --i) {
        if (used[table[i]]) {
            ++color[0];
            kosaraju(table[i]);
        }
    }
    // this problem gurantees there is a solution
    assert(check());
    for (int i = 1; i <= vn; ++i) {
        opp[color[i]] = color[cal(i)];
    }

    for (int i = color[0]; i; --i) {
        if (!del[i]) {
            del[opp[i]] = true;
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (i != 1) {
            printf(" ");
        }
        if (del[color[2*i]]) {
            printf("1");
        } else {
            printf("2");
        }
    }
    puts("");
}

void load() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d%d%d", a+i, b+i, c+i);
    }
}

int main() {
    load();
    work();
}
