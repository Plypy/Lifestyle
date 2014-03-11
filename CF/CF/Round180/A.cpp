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

int ct(string &s, char t) {
    int ret = 0;
    for (int i = 0; i < s.size(); ++i)
        if (s[i] == t)
            ++ret;
    return ret;
}
int main() {
    string a, b;
    cin >> a >> b;
    int na = ct(a,'1');
    int nb = ct(b,'1');
    if (na & 1)
        ++na;
    if (na >= nb)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
