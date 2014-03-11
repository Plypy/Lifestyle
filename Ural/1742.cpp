
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;
const int MAXN = 100005;
int n;
int nxt[MAXN];
void load() {
    scanf("%d" ,&n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", nxt+i);
}

bool lab[MAXN];
int color[MAXN];
const int WHITE = 0;
const int GREY = 1;
const int BLACK = 2;
bool in[MAXN];
int inct;
int outct;
int cct;
int rep[MAXN];
int bct[MAXN];
int ind[MAXN];
void work() {
    stack<int> stk;
    for (int i = 1; i <= n; ++i)
        if (WHITE == color[i]) {
            stk.push(i);
            while (stk.size()) {
                bool flag = false;
                int u = stk.top();
                color[u] = GREY;
                int v = nxt[u];
                if (WHITE == color[v]) {
                    stk.push(v);
                } else if (GREY == color[v]) {
                    lab[v] = true;
                    flag = true;
                } else {
                    flag = true;
                }
                if (flag) {
                    color[u] = BLACK;
                    stk.pop();
                }
            }
        }
    for (int i = 1; i <= n; ++i) {
        if (lab[i]) {
            ++cct;
            in[i] = true;
            rep[i] = i;
            int u = nxt[i];
            ++inct;
            while (!in[u]) {
                rep[u] = i;
                in[u] = true;
                u = nxt[u];
                ++inct;
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        ++ind[nxt[i]];
    for (int i = 1; i <= n; ++i)
        if (!ind[i]) {
            int u = i;
            while (!in[u])
                u = nxt[u];
            ++bct[rep[u]];
        }
    outct = n-inct;
    int maxans = outct+cct;
    int minans = cct;
    for (int i = 1; i <= n; ++i)
        if (bct[i] > 1)
            minans += bct[i]-1;
    cout << minans << ' ' << maxans << endl;
}

int main() {
    load();
    work();
//    cout << "Debug part" << endl;
//    cout << "The number of circles is " << cct << endl;
//    cout << "The number of nodes which is in a circle is " << inct << endl;
//    system("pause");
    return 0;
}
