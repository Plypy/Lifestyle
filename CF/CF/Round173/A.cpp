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
using namespace std;

int ans = 0;
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string tmp;
        cin >> tmp;
        if ('+' == tmp[0] || '+' == tmp[2])
            ++ans;
        else
            --ans;
    }
    cout << ans << endl;
    return 0;
}
