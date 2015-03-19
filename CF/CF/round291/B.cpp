#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
int n;
typedef pair<int, int> pi;
pi dat[MAXN];

int gcd(int a, int b)
{
    while (b) {
        int c = a;
        a = b;
        b = c%b;
    }
    return a;
}

int main(int argc, char *argv[])
{
    cin >> n >> dat[0].first >> dat[0].second;
    for (int i = 1; i <= n; ++i) {
        cin >> dat[i].first >>  dat[i].second;
        dat[i].first -= dat[0].first;
        dat[i].second -= dat[0].second;
        int d = gcd(dat[i].first, dat[i].second);
        dat[i].first /= d;
        dat[i].second /= d;
        if (dat[i].first < 0) {
            dat[i].first *= -1;
            dat[i].second *= -1;
        }
    }
    sort(dat+1, dat+1+n);
    int ans = 0;
    dat[0].first = dat[0].second = 0;
    for (int i = 1; i <= n; ++i) {
        if (dat[i] != dat[i-1]) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
