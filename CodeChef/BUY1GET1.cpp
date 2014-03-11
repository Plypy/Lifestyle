#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int MAXN = 300;
int t;
int ct[MAXN];
int main() {
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        memset(ct,0,sizeof(ct));
        for (int i = 0; i < s.size(); ++i)
            ++ct[s[i]];
        for (int i = 1; i < MAXN; ++i)
            ct[0] += (ct[i]+1)/2;
        cout << ct[0] << endl;
    }
    return 0;
}
