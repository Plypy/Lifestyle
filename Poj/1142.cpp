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

int sum(int x) {
    int ret = 0;
    while (x) {
        ret += x%10;
        x /= 10;
    }
    return ret;
}

const int MAXP = 100005;
bool notp[MAXP];
vector<int> plis;

void sieve() {
    for (int i = 2; i < MAXP; ++i) {
        if (!notp[i]) {
            plis.push_back(i);
        }
        int len = plis.size();
        for (int j = 0; (j < len) && (i*plis[j]< MAXP); ++j) {
            notp[i*plis[j]] = true;
            if (0 == i%plis[j]) {
                break;
            }
        }
    }
}

bool check(int x) {
    int s = sum(x);
    int plen = plis.size();
    int ts = 0;
    int ct = 0;
    for (int i = 0; i < plen; ++i) {
        int p = plis[i];
        if (p*p > x) {
            break;
        }
        while (0 == x%p) {
            ++ct;
            ts += sum(p);
            x /= p;
        }
    }
    if (1 != x) {
        ++ct;
        ts += sum(x);
    }
    return (1 != ct) && (ts == s);
}

int main() {
    sieve();
    int n;
    while (true) {
        cin >> n;
        if (0 == n) {
            break;
        }
        for (int i = n+1; true; ++i) {
            if (check(i)) {
                cout << i << endl;
                break;
            }
        }
    }
}
