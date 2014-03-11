#include <iostream>
#include <sstream>
using namespace std;
int ans[10];
int n, m;
string list;
int main()
{
    cin >> n >> m;
    ostringstream tmp;
    for (int i = n; i <= m; i++)
        tmp << i;
    list = tmp.str();
    int len = list.size();
    for (int i = 0; i < len; i++)
        ans[list[i]-'0']++;
    cout << ans[0];
    for (int i = 1; i<= 9; i++)
        cout << ' ' << ans[i];
    return 0;
}
