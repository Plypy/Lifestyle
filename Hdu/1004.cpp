/**
 * Description: Simple problem invovling map, finding a string occurs most frequently.
 * Source: hdu 1004
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

map<string,int> table;
int n;
int main() {
    while (true) {
        cin >> n;
        if (0 == n)
            break;
        table.clear();
        while (n--) {
            string str;
            cin >> str;
            ++table[str];
        }
        string ans;
        int ct = 0;
        for (map<string,int>::iterator itr = table.begin(); itr != table.end(); ++itr) {
            if (itr->second > ct) {
                ct = itr->second;
                ans = itr->first;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
