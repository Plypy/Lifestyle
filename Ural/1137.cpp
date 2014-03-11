//����ͼŷ��·
//ע��ŷ��·��Ҫ������
//����ʹ�÷���ͼ����
//����Ȧ�㷨��������Ľ����Ҫ�������������ʹ���˷���ͼ���Ե��������Σ�ֱ�������û������
//���о��������ıߺܶ࣬��Ҫ�ֹ���ջʵ�ַǵݹ��dfs
//��������Ŀ���ᵽ�ˣ�ͼ����ͨ������һ�����н�ģ����������
/**
 * Author: Ply_py
 */
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

const int MAXN = 105;
const int MAXM = 1005;
const int MAXL = 10005;

const int MAXE = MAXN*MAXM;
const int MAXV = MAXL;
int e[MAXE], nxt[MAXE], adj[MAXV];
bool vis[MAXE];
int stack[MAXE];
int n, m;
int vs;
int ect;
void add(int u, int v) {
    e[++ect] = v;
    nxt[ect] = adj[u];
    adj[u] = ect;
}
void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int tm;
        int u = 0;
        scanf("%d", &tm);
        m += tm;
        for (int j = 1; j <= tm+1; ++j) {
            int v;
            scanf("%d", &v);
            if (i == 1 && u == 0)
                vs = v;
            if (u != 0) {
                add(v,u);
            }
            u = v;
        }
    }
}
int p[MAXV];
void work() {
    memcpy(p,adj,sizeof(adj));
    printf("%d", m);
    int top = 1;
    stack[top] = vs;
    while (top) {
        int u = stack[top];
        if (p[u]) {
            int t = p[u];
            for (; t; t = nxt[t]) {
                if (!vis[t]) {
                    vis[t] = true;
                    int v = e[t];
                    stack[++top] = v;
                    break;
                }
            }
            p[u] = t;
            continue;
        }
        printf(" %d", u);
        --top;
    }
    puts("");
}
int main() {
    load();
    work();
    return 0;
}
