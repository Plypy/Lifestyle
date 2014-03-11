
/**
 * Description:
 * Author: Ply_py
 */
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
#include <cmath>
using namespace std;
int find(string str, char c) {
    int len  = str.size();
    int ret = 0;
    for (int i = 0; i < len; ++i)
        if (str[i] == c)
            ++ret;
    return ret;
}
int main() {
    string str;
    while (cin >> str) {
        int a = find(str,'4');
        int b = find(str,'7');
        if (0 == a && 0 == b) {
            cout << -1 << endl;
        } else if (a >= b) {
            cout << 4 << endl;
        } else {
            cout << 7 << endl;
        }
    }
    return 0;
}
