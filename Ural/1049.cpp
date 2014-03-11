#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;
const int n = 10;
const int MAXP = 101;
bool notp[MAXP];
vector<int> plis;
void init() {
    for (int i = 2; i < MAXP; ++i)
        if (!notp[i]) {
            plis.push_back(i);
            for (int j = i*2; j < MAXP; j += i)
                notp[j] = true;
        }
}

int main() {
    init();
    map<int,int> dtable;
    int pnum = plis.size();
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        for (int j = 0; j < pnum; ++j)
            while (0 == t%plis[j]) {
                t /= plis[j];
                ++dtable[plis[j]];
            }
        if (t > 1)
            ++dtable[t];
    }
    int ans = 1;
    for (map<int,int>::const_iterator itr = dtable.begin(); itr != dtable.end(); ++itr)
        ans *= itr->second+1;
    ans %= 10;
    cout << ans << endl;
//    system("pause");
    return 0;
}
