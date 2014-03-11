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


const int MAXN = 200005;
char buf[MAXN];
char tmp[MAXN];
int indent;
int len;
bool check(char p) {
    if (32 == p || 9 == p || 10 == p)
        return true;
    return false;
}
void print(char *l, char *r, int type) {
    if (type) {
        bool ret = true;
        for (char *p = l; p != r; ++p)
            if (!check(*p))
                ret = false;
        if (ret)
            return;
    }
    for (int i = 0; i < indent; ++i)
        putchar(32);
    bool flag = false;
    while (check(*(r-1)) && r != l)
        --r;
    while (check(*l) && r != l)
        ++l;
    for (char *p = l; p != r; ++p) {
        bool space = check(*p);
        if (type && space) {
            if (flag)
                continue;
            flag = true;
            putchar(32);
        } else {
            flag = false;
            putchar(*p);
        }
    }
    putchar(10);
}
int main() {
    int T;
    scanf("%d\n", &T);
    for (int cas = 1; cas <= T; ++cas) {
        memset(buf,0,sizeof(buf));
        indent = 0;
        while (true) {
            gets(tmp);
            len = strlen(tmp);
            while (len && check(tmp[len-1]))
                tmp[--len] = 0;
            len = strlen(buf);
            if (buf[len-1] != '>')
            strcat(buf, tmp);
            if (strstr(buf, "</html>"))
                break;
        }
    }
}