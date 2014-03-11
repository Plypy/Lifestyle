#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <map>
#include <queue>
using namespace std;
const int MAXN = 305;
map<string,int> id;
bool graph[MAXN][MAXN];
int n;
int ct = 1;
bool flag = false;

void load() {
    cin >> n;
    id["Isenbaev"] = 1;
    for (int i = 1; i <= n; ++i) {
        string tname[3];
        int tid[3];
        for (int j = 0; j < 3; ++j) {
            cin >> tname[j];
            if (tname[j] == "Isenbaev")
                flag = true;
            if (!id.count(tname[j])) {
                id[tname[j]] = ++ct;
            }
            tid[j] = id[tname[j]];
        }
        for (int j = 0; j < 2; ++j)
            for (int k = j+1; k < 3; ++k)
                graph[tid[j]][tid[k]] = graph[tid[k]][tid[j]] = true;
    }
}

int dis[MAXN];
bool vis[MAXN];
void work() {
    queue<int> que;
    que.push(1);
    vis[1] = true;
    while (que.size()) {
        int u = que.front();
        que.pop();
        for (int j = 1; j <= ct; ++j)
            if (!vis[j] && graph[u][j]) {
                vis[j] = true;
                dis[j] = dis[u]+1;
                que.push(j);
            }
    }
}

void out() {
    for (map<string,int>::const_iterator itr = id.begin(); itr != id.end(); ++itr) {
        cout << itr->first << ' ';
        if (!vis[itr->second])
            cout << "undefined" << endl;
        else
            cout << dis[itr->second] << endl;
    }
}

int main() {
    load();
    if (flag)
        work();
    else
        id.erase("Isenbaev");
    out();
//    system("pause");
    return 0;
}
