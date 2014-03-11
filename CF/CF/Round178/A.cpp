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
const int MAXN = 105;
int num[MAXN];
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> num[i];
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        num[a-1] += b-1;
        num[a+1] += num[a]-b;
        num[a] = 0;
    }
    for (int i = 1; i <= n; ++i)
        cout << num[i] << endl;
    return 0;
}
