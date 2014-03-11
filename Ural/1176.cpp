#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;
const int MAXN = 1005;

int id[MAXN], od[MAXN];
bool g[MAXN][MAXN];
int n, s;
void load() {
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        
        for (int j = 1; j <= n; ++j) {
            cin >> g[i][j];
        }
        g[i][i] = true;
    }
}
int mem[MAXN];
void work() {
    stack<int> stk;
    stk.push(s);
    vector<int> ans;
    for (int i = 1; i <= n; ++i)
        mem[i] = 1;
    while (stk.size()) {
        int u = stk.top();
        for (int &v = mem[u]; v <= n; ++v) {
            if (!g[u][v]) {
                g[u][v] = true;
                stk.push(v);
                break;
            }
        }
        if (mem[u] > n) {
            stk.pop();
            ans.push_back(u);
        }
    }
    for (int i = ans.size()-1; i; --i) {
        cout << ans[i] << ' ' << ans[i-1] << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    load();
    work();
    return 0;
}

