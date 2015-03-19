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
#include <stack>
using namespace std;

const int MAXN = 500005;
int ar[MAXN];
stack<int> stk;
int nid[MAXN];
int nxt[MAXN];
int instk[MAXN];

vector<int> ans;

map<int, int> table;
int cnt = 0;
int n;

int find(int pos) {
    map<int,int> nxt;
    map<int,int> instk;
    while (stk.size()) {
        stk.pop();
    }
    for (int i = pos; i < n; ++i) {
        map<int,int>::iterator itr = nxt.find(ar[i]);
        if (itr != nxt.end()) {
            ans.push_back(itr->second);
            ans.push_back(ar[i]);
            ans.push_back(itr->second);
            ans.push_back(ar[i]);
            return i;
        }
        while (stk.size() && (instk[ar[i]] > 1 || (1 == instk[ar[i]] && stk.top() != ar[i]) )) {
            int u = stk.top();
            nxt[u] = ar[i];
            --instk[u];
            stk.pop();
        }
        stk.push(ar[i]);
        ++instk[ar[i]];
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ar[i];
    }
    int t = -1;
    while (true) {
        t = find(t+1);
        if (t == -1) {
            break;
        }
    }
    int len = ans.size();
    cout << len << endl;
    for (int i = 0; i < len; ++i) {
        cout << ans[i] << (i==len-1?'\n':' ');
    }
}
