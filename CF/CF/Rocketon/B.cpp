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

const int MAXN = 30;
int len[MAXN][2];
int main(int argc, char const *argv[]) {
    string str;
    cin >> str;
    int slen = str.size();
    int ans = 0;
    for (int i = 0; i < slen; ++i) {
        int a = str[i]-'A';
        int b = (i&1);
        int c = 1-b;
        len[a][b] = len[a][c]+1;
        ans = max(ans,len[a][b]);
    }
    cout << ans << endl;
    return 0;
}