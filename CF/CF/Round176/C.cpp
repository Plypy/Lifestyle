#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;
const int MAXN = 1000005;
int n, t;
int p[MAXN];
int q[MAXN];
map<int, int> ctTable;
stack<int> stk;
stack<int> idstk;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", p+i);
    }
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
        scanf("%d", q+i);
    for (int i = 1; i <= t; ++i)
        p[q[i]] *= -1;
    bool suc = true;
    for (int i = n; i; --i) {
        int a = p[i];
        if (a < 0) {
            stk.push(-a);
        } else {
            if (stk.size()) {
                if (stk.top() == a) {
                    stk.pop();
                } else {
                    stk.push(a);
                    p[i] *= -1;
                }
            } else {
                stk.push(a);
                p[i] *= -1;
            }
        }
    }
    if (stk.size())
        suc = false;
    if (suc) {
        puts("YES");
        printf("%d", p[1]);
        for (int i = 2; i <= n; ++i)
            printf(" %d", p[i]);
        puts("");
    } else {
        puts("NO");
    }
    return 0;
}
