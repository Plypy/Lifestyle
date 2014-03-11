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
string a, b;
int main() {
    cin >> a >> b;
    if (a.size() != b.size()) {
        cout << "NO" << endl;
        return 0;
    }
    int z1 = 0, z2 = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == '1')
            ++z1;
        if (b[i] == '1')
            ++z2;
    }
    if (z1&&z2 || (!z1&&!z2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
