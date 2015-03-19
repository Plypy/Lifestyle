/**
 * Description: Simple Modular's property
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

typedef long long ll;
const int MAXN = 1000005;
char num[MAXN];
int n;

bool check(ll base) {
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        result = (result*base+num[i])%(base-1);
    }
    return 0 == result;
}

int main() {
    scanf("%s", num);
    n = strlen(num);
    int minbase = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        if (isdigit(num[i])) {
            t = num[i]-'0';
        } else {
            t = num[i]-'A'+10;
        }
        if (t > minbase) {
            minbase = t;
        }
        num[i] = t;
    }
    ++minbase;
    minbase = max(minbase, 2);
    int base = minbase;
    for (; base <= 36; ++base) {
        if (check(base)) {
            break;
        }
    }

    if (base > 36) {
        puts("No solution.");
    } else {
        printf("%d\n", base);
    }
}
