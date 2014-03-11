/**
 * Description: An implementation problem from chengdu regional sub
 * Source: 2013 Chengdu Regional Sub
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


const int MAXL = 200005;

char buf[MAXL];
int indent = 0;
bool check(char a) {
    if (32 == a || 9 == a || 10 == a)
        return true;
    return false;
}
void print(char *l, char *r, int type) {
    // cout << indent << "     " ;
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
char tmp[MAXL];
char endtag[10] = "</html>";
int main(int argc, char const *argv[]) {
    // freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
    int T;
    scanf("%d\n", &T);

    while (gets(tmp)) {
        strcat(buf,tmp);
        int len = strlen(buf);
        buf[len] = ' ';
        buf[++len] = 0;
    }
    char *l = buf, *r = buf;
    for (int cas = 1; cas <= T; ++cas) {
        printf("Case #%d:\n", cas);
        indent = 0;
        while (true) {
            l = strstr(r,"<");
            if (l > r) {
                print(r,l,1);
            }
            r = strstr(l,">")+1;
            if (*(r-2) != '/' && *(l+1) != '/') {
                print(l,r,0);
                ++indent;
            } else if (*(l+1) == '/') {
                --indent;
                print(l,r,0);
            } else {
                print(l,r,0);
            }
            bool flag = true;
            for (int i = 0; i < 7; ++i)
                if (endtag[i] != l[i])
                    flag = false;
            if (flag)
                break;
        }
    }
    return 0;
}