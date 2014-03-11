/**
 * Description: CF Round#120 C
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

string a, b;
bool flag;
void check() {
    if (cin >> a) {
        b += a;
        if ("pair" == a) {
            b += "<";
            check();
            b += ",";
            check();
            b += ">";
        }
    } else {
        flag = true;
    }
}
void test() {
    for (int i = 1; i <= 100; ++i)
        continue;
}
int main() {
    cin >> a;
    check();
    test();
    if (flag || cin >> a) {
        cout << "Error occurred" << endl;
    } else {
        cout << b << endl;
    }
    return 0;
}
