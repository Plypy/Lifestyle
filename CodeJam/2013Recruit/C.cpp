/**
 * Description:
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

const int MAXN = 105;
string name[MAXN];
int main(int argc, char const *argv[]) {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int n;
        cin >> n;
        while (cin.get() != '\n')
            continue;
        for (int j = 0; j < n; ++j) {
            getline(cin, name[j]);
        }
        string prev = " ";
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (name[j] < prev)
                ++ans;
            else
                prev = name[j];
        }
        cout << "Case #" << i << ": " << ans << endl;
    }
    return 0;
}