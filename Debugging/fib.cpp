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
int f[MAXN];
int fib(int n) {
    if (f[n])
        return f[n];
    return f[n] = fib(n-1)+fib(n-2);
}
int main(int argc, char const *argv[]) {
    f[1] = f[2] = 1;
    int n;
    while (cin >> n) {
        cout << fib(n);
    }
    return 0;
}