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
int a = 2;
int b = 0;
int c = 3;
int f(int n) {
    return (a*n+b)/c;
}
int sg[1000];
bool used[1000];
void cal(int p) {
    memset(used,0,sizeof(used));
    int x = f(p);
    for (int i = 1; i <= x && i <= p; ++i)
        used[sg[p-i]] = true;
    for (int i = 0; ; ++i) {
        if (!used[i]) {
            sg[p] = i;
            break;
        }
    }
}
int main(int argc, char const *argv[]) {
    int n = 100;
    for (int i = 1; i <= n; ++i) {
        cal(i);
        cout << i << ' ' << f(i) << ' ' << sg[i] << endl;
    }
    return 0;
}