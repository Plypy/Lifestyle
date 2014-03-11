#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN = 20;
typedef unsigned long long ULL;
int n;
map<string,int> table;
ULL member[MAXN];
void load() {
    cin >> n;
    int ct = 0;
    for (int i = 1; i <= n; ++i) {
        string s[3];
        cin >> s[0] >> s[1] >> s[2];
        for (int j = 0; j < 3; ++j) {
            if (table.find(s[j]) == table.end())
                table[s[j]] = ct++;
            int t = table[s[j]];
            member[i] |= (ULL(1)<<t);
        }
    }
}

int dfs(int dep, int cur) {
    static ULL state = 0;
    int ret = dep;
    for (int i = cur+1; i <= n; ++i) {
        if (!(state&member[i])) {
            state |= member[i];
            ret = max(ret,dfs(dep+1,i));
            state ^= member[i];
        }
    }
    return ret;
}
void work() {
    cout << dfs(0,0) << endl;;
}

int main() {
    load();
    work();
//    system("pause");
    return 0;
}
