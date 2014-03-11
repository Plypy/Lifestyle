#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;
const int MAXN = 1000005;

int c[MAXN];

int main() {
    char ch;
    int ans1 = 0, ans2 = 1;
    stack<int> stk;
    int i = 0;
    while (true) {
        ch = getchar();
        ++i;
        if (EOF == ch)
            break;
        if (ch == '(')
            stk.push(i);
        else if (ch == ')') {
            if (!stk.empty()) {
                int tmp = stk.top();
                stk.pop();
                c[i] = tmp;
                if (c[tmp-1])
                    c[i] = c[tmp-1];
                int len = i-c[i]+1;
                if (len > ans1) {
                    ans1 = len;
                    ans2 = 1;
                } else if (len == ans1)
                    ++ans2;

            }
        }
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}
