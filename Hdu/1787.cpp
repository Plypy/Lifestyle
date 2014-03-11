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

const int MAXN = 100000005;

vector<int> plis;
int len;
const int BD = 10005;
bool notp[BD];
void prep() {
    for (int i = 2; i < BD; ++i)
        if (!notp[i]) {
            plis.push_back(i);
            for (int j = i+i; j < BD; j += i)
                notp[j] = true;
        }
    len = plis.size();
}

int phi(int n) {
    int ret = n;
    for (int i = 0; i < len; ++i) {
        int p = plis[i];
        if (n%p == 0) {
            ret = ret/p*(p-1);
            while (n%p == 0)
                n /= p;
        }
    }
    if (n > 1)
        ret = ret/n*(n-1);
    return ret;
}
int main(int argc, char const *argv[]) {
    prep();
    while (true) {
        int n;
        scanf("%d", &n);
        if (0 == n)
            break;
        printf("%d\n", n-phi(n)-1);
    }
    return 0;
}