// Note: ������������ �����ˡ�����ǰ���Ҹ㶨��- -
// �����ֵ����ܡ�
// ��˵һ����εľ��飬�������һ��2-sat�����ˣ����������������������
// �������2-sat�и����Ĺ�ϵ����һ�Ի����ϵ����Ȼ�������Ҳ��
// ����������д����Ŷ���һ��i��i' ֻ��ѡi������
// ��������ǰ������û���������ģ����Ҹ��㷭�˵���- -
// �������Ҳ�ǵģ�����һ��i'->i������ߣ����ܱ�֤�ܻ�ѡi�� 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 105
#define MAXV MAXN*2
#define MAXE MAXV*MAXV
#define INF 52111425
int n;
int lbd, ubd;
int x[MAXN], y[MAXN];
void load() {
    lbd = INF, ubd = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", x+i, y+i);
        for (int j = 1; j < i; ++j) {
            int dx = abs(x[i]-x[j]);
            int dy = abs(y[i]-y[j]);
            lbd = min(lbd,min(dx,dy));
            ubd = max(ubd,max(dx,dy));
        }
    }
}
struct Edge {
    int vtx;
    Edge *nxt;
    Edge(int ivtx = 0, Edge *inxt = 0):
        vtx(ivtx), nxt(inxt) { }
} edge[MAXE], *adj[MAXV];
int ect;
inline void add(int u, int v) {
    adj[u] = &(edge[++ect] = Edge(v,adj[u]));
}
int color[MAXV];
int dfn[MAXV];
int low[MAXV];
bool ins[MAXV];
int stack[MAXV];
void init() {
    ect = 0;
    memset(adj,0,sizeof(adj));
    memset(color,0,sizeof(color));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
}

void tarjan(int u) {
    low[u] = dfn[u] = ++dfn[0];
    stack[++stack[0]] = u;
    ins[u] = true;
    for (Edge *t = adj[u]; t; t = t->nxt) {
        int v = t->vtx;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        } else if (ins[v])
            low[u] = min(low[u],dfn[v]);
    }
    if (dfn[u] == low[u]) {
        ++color[0];
        int v;
        do {
            v = stack[stack[0]--];
            ins[v] = false;
            color[v] = color[0];
        } while (v != u);
    }
}

bool solve(int r) {
    init();
    for (int i = 1; i < n; ++i)
        for (int j = i+1; j <= n; ++j)
            if (abs(x[i]-x[j]) < r) {
                int a = i;
                int b = j;
                if (y[a] < y[b])
                    swap(a,b);
                
                if (y[a]-y[b] < 2*r) {
                    if (y[a]-y[b] < r) {
                        if (y[a] == y[b]) {
                            add(2*a-1,2*b);
                            add(2*b,2*a-1);
                            add(2*a,2*b-1);
                            add(2*b-1,2*a);
                        } else {
                            add(2*a,2*a-1);
                            add(2*b-1,2*b);
                        }
                    } else {
                        add(2*a,2*b);
                        add(2*b-1,2*a-1);
                    }
                }
            }
    
    int v = 2*n;
    for (int i = 1; i <= v; ++i)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i < v; i += 2)
        if (color[i] == color[i+1])
            return false;
    return true;
}

void work() {
    while (lbd <= ubd) {
        int mid = (lbd+ubd)>>1;
        if (solve(mid))
            lbd = mid+1;
        else
            ubd = mid-1;
    }
    printf("%d\n", ubd);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        load();
        work();
    }
    return 0;
}
