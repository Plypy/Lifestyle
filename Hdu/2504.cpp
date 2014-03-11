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


const int MAXN = 1000005;
const int BD = 1005;

int notp[BD];
vector<int> plis;
int pnum;
void prep() {
    for (int i = 2; i < BD; ++i)
        if (!notp[i]) {
            plis.push_back(i);
            for (int j = i*i; j < BD; j += i)
                notp[j] = true;
        }
}

int gcd(int a, int b) {
    if (b)
        return gcd(b,a%b);
    return a;
}

int main(int argc, char const *argv[]) {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == b) {
            printf("%d\n", a);
        }
        int t = a/b, j = 0;
        for (j = 2; j < t; ++j)
            if (1 == gcd(t,j))
                break;
        printf("%d\n", b*j);
    }
    return 0;
}