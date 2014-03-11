// Note priority_que默认从大到小排
// 和sort刚好是相反的
// 这个数据真让人操蛋啊 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <ctime>
#include <iterator>
using namespace std;
const int MAXN = 1010;
const int MAXV = MAXN*MAXN*2;
int num[MAXN][MAXN][2];
int ct;
int s, t;
int n, m;
int horz[MAXN][MAXN];
int vert[MAXN][MAXN];
int cros[MAXN][MAXN];
void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j) {
            num[i][j][0] = ++ct;
            num[i][j][1] = ++ct;
        }
    s = 0;
    t = ++ct;
    for (int i = 1; i < m; ++i) {
        num[0][i][0] = num[0][i][1] = t;
        num[n][i][0] = num[n][i][1] = s;
    }
    for (int i = 1; i < n; ++i) {
        num[i][0][0] = num[i][0][1] = s;
        num[i][m][0] = num[i][m][1] = t;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < m; ++j)
            scanf("%d", &horz[i][j]);
    for (int i = 1; i < n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &vert[i][j]);
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            scanf("%d", &cros[i][j]);
}
const int INF = 52111425;

struct Node {
    int col, row, type;
    int dis;
    friend bool operator<(const Node &a, const Node &b) {
        return b.dis<a.dis;
    }
    Node(int _row = 0, int _col = 0, int _type = 0, int _dis = 0):
        col(_col),row(_row),type(_type),dis(_dis){ };
};

int dis[MAXV];
bool ouq[MAXV];
inline int min(int a, int b) {
    return a<b?a:b;
}
void work() {
    for (int i = 1; i <= t; ++i)
        dis[i] = INF;
    if (n == 1 && t == 1)
        dis[t] = 0;
    priority_queue<Node> que;
    for (int i = 1; i < n; ++i) {
        if (dis[num[i][1][0]] > vert[i][1]) {
            dis[num[i][1][0]] = vert[i][1];
            que.push(Node(i,1,0,vert[i][1]));
        }
    }
    for (int i = 1; i < m; ++i) {
        if (dis[num[n-1][i][0]] > horz[n][i]) {
            dis[num[n-1][i][0]] = horz[n][i];
            que.push(Node(n-1,i,0,horz[n][i]));
        }
    }
    Node cur_v;
    int cur_r, cur_c, cur_t, cur_dis;
    int u, v, l;
    ouq[s] = true;
    
//    cout << t << endl;
//    cout << num[1][1][0] << endl;
    
    while (que.size()) {
        
        cur_v = que.top();
        que.pop();
        cur_r = cur_v.row;
        cur_c = cur_v.col;
        cur_t = cur_v.type;
        u = num[cur_r][cur_c][cur_t];
        cur_dis = dis[u];
        
//        cout << endl;
//        cout << cur_r << ' ' << cur_c << ' ' << cur_t << endl;
//        cout << cur_dis << endl;
        
        
        if (u == t)
            break;
        if (ouq[u])
            continue;
        ouq[u] = true;
        if (cur_t == 1) {
            // up
            v = num[cur_r-1][cur_c][0];
            l = horz[cur_r][cur_c];
            if (!ouq[v] && dis[v] > dis[u]+l) {
                dis[v] = dis[u]+l;
                que.push(Node(cur_r-1,cur_c,0,dis[v]));
            }
            // right
            v = num[cur_r][cur_c+1][0];
            l = vert[cur_r][cur_c+1];
            if (!ouq[v] && dis[v] > dis[u]+l) {
                dis[v] = dis[u]+l;
                que.push(Node(cur_r,cur_c+1,0,dis[v]));
            }
            // left_down
            v = num[cur_r][cur_c][0];
            l = cros[cur_r][cur_c];
            if (!ouq[v] && dis[v] > dis[u]+l) {
                dis[v] = dis[u]+l;
                que.push(Node(cur_r,cur_c,0,dis[v]));
            }
        } else {
            // right_up
            v = num[cur_r][cur_c][1];
            l = cros[cur_r][cur_c];
            if (!ouq[v] && dis[v] > dis[u]+l) {
                dis[v] = dis[u]+l;
                que.push(Node(cur_r,cur_c,1,dis[v]));
            }
            // left
            v = num[cur_r][cur_c-1][1];
            l = vert[cur_r][cur_c];
            if (!ouq[v] && dis[v] > dis[u]+l) {
                dis[v] = dis[u]+l;
                que.push(Node(cur_r,cur_c-1,1,dis[v]));
            }
            // down
            v = num[cur_r+1][cur_c][1];
            l = horz[cur_r+1][cur_c];
            if (!ouq[v] && dis[v] > dis[u]+l) {
                dis[v] = dis[u]+l;
                que.push(Node(cur_r+1,cur_c,1,dis[v]));
            }
        }
    }
}
void output() {
    printf("%d\n", dis[t]);
//    system("pause");
}
int main() {
    load();
    work();
    output();
    return 0;
}
/*
3 4

5 6 4

4 3 1

7 5 3

5 6 7 8

8 7 6 5

5 5 5

6 6 6


ans
14
*/
