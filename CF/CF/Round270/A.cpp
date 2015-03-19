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
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <stack>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n & 1) {
        cout << 9 << ' ' << n-9 << endl;
    } else {
        cout << 4 << ' ' << n-4 << endl;
    }
}
