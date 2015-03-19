#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
const int MIN = 1e-9-1;
bool flag[MAXN];
int ar[MAXN];
int n, k;


int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        char buf[20] = {0};
        cin >> buf;
        if ('?' == buf[0]) {
            flag[i] = true;
        } else {
            ar[i] = atoi(buf);
        }
    }
    for (int i = 1; i <= k; ++i) {
    }
    return 0;
}
