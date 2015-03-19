/**
 * Description:
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
using namespace std;

int count(string &str) {
    int len = str.size();
    int ret = 0;
    for (int i = 0; i < len; ++i) {
        if ('r' == str[i]) {
            ++ret;
        }
    }
    return ret;
}
void toLowerCase(string &str) {
    int len = str.size();
    for (int i = 0; i < len; ++i) {
        str[i] = tolower(str[i]);
    }
}


const int MAXN = 100005;
string words[MAXN];
typedef pair<int, int> pi;
typedef pair<pi, int> pi2;

const int INF = 0x3f3f3f3f;

vector<int> adj[MAXN];
pi minr[MAXN];

bool vis[MAXN];
void dfs(int u, const pi &r) {
    vis[u] = true;
    minr[u] = r;
    int len = adj[u].size();
    for (int i = 0; i < len; ++i) {
        int v = adj[u][i];
        if (!vis[v]) {
            dfs(v, r);
        }
    }
}

int cnt;
map<string, int> table;
pi2 data[MAXN*2];

int getId(string str) {
    map<string, int>::iterator itr = table.find(str);
    if (itr != table.end()) {
        return itr->second;
    }
    table[str] = cnt;
    pi tmp = make_pair(count(str), str.size());
    data[cnt] = make_pair(tmp, cnt);
    return cnt++;
}



int n, m;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        toLowerCase(words[i]);
        getId(words[i]);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        toLowerCase(a);
        toLowerCase(b);
        int u = getId(a);
        int v = getId(b);
        // cout << u << "---->" << v << endl;
        adj[v].push_back(u);
    }
    sort(data, data+cnt);
    for (int i = 0; i < cnt; ++i) {
        int u = data[i].second;
        if (!vis[u]) {
            pi val = data[i].first;
            dfs(u, val);
        }
    }
    long long sr = 0, slen = 0;
    for (int i = 0; i < n; ++i) {
        pi &tmp = minr[getId(words[i])];
        // cout << getId(words[i]) << endl;
        // cout << words[i] << ' ' << tmp.first << ' ' << tmp.second << endl;
        sr += tmp.first;
        slen += tmp.second;
    }
    cout << sr << ' ' << slen << endl;
}
