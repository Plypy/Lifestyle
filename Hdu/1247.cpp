/**
 * Description: Simple problem about stl's set & string. Find all the string which could be concatenated by the other two.
 * Source: hdu 1247
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

set<string> table;
int main() {
    string tmp;
    while (cin >> tmp) {
        table.insert(tmp);
    }
    for (set<string>::iterator itr = table.begin(); itr != table.end(); ++itr) {
        const string &str = *itr;
        int len = str.size();
        for (int i = 1; i < len-1; ++i) {
            string a = str.substr(0,i);
            string b = str.substr(i);
            if (table.count(a) && table.count(b)) {
                cout << str << endl;
                break;
            }
        }
    }
}