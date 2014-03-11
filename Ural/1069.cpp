// 这次被以前做过的题给束缚了- -，虽然的确是想到了一个好点子，但是貌似其是错误的
// 归根到底还是没有仔细观察模型，没有动笔实践～ 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 7505;
int ar[MAXN];
int n = 0;
void input() {
    while (EOF != scanf("%d", &ar[++n]))
        continue;
}

int d[MAXN];
vector<int> adj[MAXN];
void work() {
    priority_queue<int,vector<int>,greater<int> > que;
    for (int i = 1; i < n; ++i)
        ++d[ar[i]];
    for (int i = 1; i <= n; ++i)
        if (!d[i])
            que.push(i);
    
    int pos = 0;
    while (true) {
        int now = que.top();
        if (now == n)
            break;
        que.pop();
        --d[ar[++pos]];
        adj[ar[pos]].push_back(now);
        adj[now].push_back(ar[pos]);
        if (!d[ar[pos]])
            que.push(ar[pos]);
    }
    for (int i = 1; i <= n; ++i)
        sort(adj[i].begin(), adj[i].end());
}

void output() {
    for (int i = 1; i <= n; ++i) {
        printf("%d:", i);
        for (int j = 0; j < adj[i].size(); ++j)
            printf(" %d", adj[i][j]);
        printf("\n");
    }
}

int main() {
    input();
    work();
    output();
//    system("pause");
    return 0;
}
