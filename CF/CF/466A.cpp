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
using namespace std;

int n, m, a, b;
int main() {
    cin >> n >> m >> a >> b;
    int ans = n*a;
    ans = min(ans, (n/m)*b+(n%m)*a);
    ans = min(ans, (n/m+1)*b);
    cout << ans << endl;
}

