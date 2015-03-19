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

const int MAXN = 1000005;
char str[MAXN*2];

int p[MAXN*2];
int work() {
    int len = strlen(str+1);
    int rmost=0, rcenter=0;
    for (int i = len; i; --i) {
        str[i*2] = str[i];
        str[i*2+1] = '#';
    }
    str[1] = '#';
    str[0] = '&';
    len <<= 1;

    int ret = 1;
    for (int i = 1; i <= len; ++i) {
        if (i < rmost) {
            p[i] = min(p[2*rcenter-i], rmost-i);
        } else {
            p[i] = 1;
        }
        while (str[i-p[i]] == str[i+p[i]]) {
            ++p[i];
        }
        if (i+p[i] > rmost) {
            rmost = i+p[i];
            rcenter = i;
        }

        if (p[i] > ret) {
            ret = p[i];
        }
    }
    return ret-1;
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        memset(str,0,sizeof(str));
        scanf("%s", str+1);
        int ans = work();
        printf("%d\n", ans);
    }
    return 0;
}
