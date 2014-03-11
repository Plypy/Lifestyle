/**
 * Description: Brackets' completion
 * Author: Ply_py
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <queue>
#include <cmath>
using namespace std;
const int MAXN = 105;
const int INF  = 0x3f3f3f3f;
int mid[MAXN][MAXN];
int f[MAXN][MAXN];
string str;
bool match(char a, char b) {
    if ('(' == a && ')' == b)
        return true;
    if ('[' == a && ']' == b)
        return true;
    return false;
}
int dp(int l, int r) {
    if (l > r)
        return 0;
    if (l == r)
        return 2;
    if (f[l][r]) {
        return f[l][r];
    }
    if (')' == str[l] || ']' == str[l]) {
        mid[l][r] = l;
        return f[l][r] = 2+dp(l+1,r);
    }
    if ('(' == str[r] || '[' == str[r]) {
        mid[l][r] = r-1;
        return f[l][r] = dp(l,r-1)+2;
    }
    int ret = INF;
    if (match(str[l],str[r])) {
        ret = 2+dp(l+1,r-1);
        mid[l][r] = r;
    }
    for (int i = l; i < r; ++i) {
        int a = dp(l,i)+dp(i+1,r);
        if (a < ret) {
            ret = a;
            mid[l][r] = i;
        }
    }
    return f[l][r] = ret;
}
void print(int l, int r) {
    if (l > r)
        return ;
    int m = mid[l][r];
    if (-1 != m) {
        if (m == r) {
            cout << str[l];
            print(l+1,r-1);
            cout << str[r];
        } else {
            print(l,m);
            print(m+1,r);
        }
    } else {
        if (')' == str[l] || '(' == str[l])
            cout << "()";
        else
            cout << "[]";
    }
}
int main() {
    cin >> str;
    memset(mid,-1,sizeof(mid));
    dp(0,str.size()-1);
    print(0,str.size()-1);
    cout << endl;
    return 0;
}
