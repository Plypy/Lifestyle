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

int main(int argc, char const *argv[]) {
    int n, c;
    cin >> n >> c;
    int a, b;
    cin >> a;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        cin >> b;
        int t = a-b-c;
        if (t > ans)
            ans = t;
        a = b;
    }
    cout << ans << endl;
    return 0;
}