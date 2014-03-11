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
const int MAXN = 1000005;
int n;
int main() {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int p, q;
        cin >> p >> q;
        sum += p;
    }
    int t = sum/1000;
    sum %= 1000;
    if (sum > 500)
        ++t;
    for (int i = 1; i <= n; ++i) {
        if (i <= t)
            cout << "G";
        else
            cout <<"A";
    }
    cout << endl;
    return 0;
}
