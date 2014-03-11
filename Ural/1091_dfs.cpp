#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXCAP = 10000;
const int MAXN = 55;
int n, s;
int ans;
int gcd(int a, int b) {
    if (b)
        return gcd(b,a%b);
    return a;
}
bool halt;
void dfs(int curNum, int curD, int got) {
    if (halt)
        return ;
    if (s-curNum+got < n)
        return;
    if (n == got) {
        ++ans;
        if (MAXCAP == ans)
            halt = true;
        return;
    }
    for (int i = curNum+1; i <= s; ++i) {
        int t = gcd(curD,i);
        if (t != 1)
            dfs(i,t,got+1);
        if (halt)
            return ;
    }
}
int main() {
    cin >> n >> s;
    for (int i = 1; i <= s-n+1; ++i)
        dfs(i,i,1);
    cout << ans << endl;
    return 0;
}
