/**
 * Description: whenever there is a floating division, think about the problem of 0 denominator
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
map<string,double> mp;
void init() {
    mp["A"] = 4;
    mp["A-"] = 3.7;
    mp["B+"] = 3.3;
    mp["B"] = 3.0;
    mp["B-"] = 2.7;
    mp["C+"] = 2.3;
    mp["C"] = 2.0;
    mp["C-"] = 1.7;
    mp["D"] = 1.3;
    mp["D-"] = 1.0;
    mp["F"] = 0;
}
int n;
int main(int argc, char const *argv[]) {
    cout << fixed << setprecision(2);
    init();
    while (cin >> n) {
        double sum = 0;
        double cs = 0;
        for (int i = 0; i < n; ++i) {
            double a;string str;
            cin >> a >> str;
            if ("N" == str || "P" == str)
                continue;
            sum += a;
            cs += a*mp[str];
        }
        if (sum != 0)
            cout << cs/sum << endl;
        else
            cout << "0.00" << endl;
    }
    return 0;
}