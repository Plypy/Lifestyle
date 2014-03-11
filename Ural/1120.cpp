/**
 * Description:
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

int n;
int main() {
    cin >> n;
    n <<= 1;
    for (int t = sqrt(n)+1; t; --t) {
        if (n % t == 0) {
            int b = n/t-t+1;
            if (b > 0 && 0 == b%2) {
                int a = b/2;
                cout << a << ' ' << t << endl;
                break;
            }
        }
    }
    return 0;
}
