/**
 * Description: Reading comprehension
 * Source: Round #194 div1 A secrets || 333A
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

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    while (0 == n%3) {
        n /= 3;
    }
    n = n/3+1;
    cout << n << endl;
    return 0;
}