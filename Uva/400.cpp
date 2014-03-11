#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXC = 50;
const int MAXR = 110;
const int MAXN = 105;
const int RLEN = 60;
const int SPLEN = 2;
string buf[MAXN];
int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("ans.txt", "w", stdout);
    
    int n;
    cout << left;
    while (cin >> n) {
        int mlen = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> buf[i];
            int tlen = buf[i].size();
            mlen = max(mlen,tlen);
        }
        sort(buf+1,buf+n+1);
        int c = (RLEN+SPLEN)/(mlen+SPLEN);
        int r = int(ceil(n/double(c)));
        for (int i = 0; i < RLEN; ++i)
            cout.put('-');
        cout << endl;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                int t = r*(j-1)+i;
                if (t > n)
                    break;
                int sp = j==c?0:SPLEN;
                cout << setw(mlen+sp) << buf[t];
            }
            cout << endl;
        }
    }
    return 0;
}
