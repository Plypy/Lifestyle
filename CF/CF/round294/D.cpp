#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map< pair<ll,char>, int> table;
ll sum, ans;
int wt[300];

int main()
{
    for (int i = 'a'; i <= 'z'; ++i) {
        cin >> wt[i];
    }
    string s;
    cin >> s;
    for (unsigned i = 0; i < s.size(); ++i) {
        ans += table[make_pair(sum, s[i])];
        sum += wt[s[i]];
        ++table[make_pair(sum, s[i])];
    }
    cout << ans << endl;
    return 0;
}
