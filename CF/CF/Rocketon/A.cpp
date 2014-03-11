/**
 * Description:
 * ProblemName:
 * Source:
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.size();
    int ans = 0;
    int clen = 1;
    for (int i = 1; i < len; ++i) {
        if (str[i] == str[i-1]) {
            ++clen;
        } else {

            if (0 == clen%2) {
                ans++;
            }
            clen = 1;
        }
    }
    if (0 == clen%2) {
        ++ans;
    }
    cout << ans << endl;
}