#include <bits/stdc++.h>
using namespace std;
const int MAXN = 305;

int n;
int last[MAXN*2];
int dig[MAXN*2];

bool dfs(int kth, int rem, bool flag)
{
    if (kth <= 0) {
        return flag && rem == 0;
    }
    if (rem < 0) {
        return false;
    }
    int k9 = kth*9;
    if (k9 < rem) {
        return false;
    }
    int st = kth == dig[0] ? 1 : 0;
    if (!flag) {
        dig[kth] = last[kth];
        if (dfs(kth-1, rem-last[kth], false)) {
            return true;
        }
        st = last[kth]+1;
    }
    int tmp = rem - k9+9;
    st = max(st, tmp);
    for (int i = st; i <= 9; ++i) {
        dig[kth] = i;
        if (dfs(kth-1, rem-i, true)) {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n;
    while (n--) {
        int b;
        cin >> b;
        for (int i = last[0]; 1; ++i){
            dig[0] = i;
            if (dfs(i, b, i > last[0])) {
                break;
            }
        }
        memcpy(last, dig, sizeof(dig));
        for (int i = dig[0]; i > 0; --i) {
            cout << dig[i];
        }
        cout << endl;
    }
}
