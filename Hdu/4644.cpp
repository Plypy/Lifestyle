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

const int MAXL = 100100;
const int MAXS = 2000005;
char bwt[MAXL];
char ori[MAXL];
char s[MAXS];
int fst[MAXL];
bool cmp(int a, int b) {
    if (bwt[a] == bwt[b])
        return a<b;
    return bwt[a]<bwt[b];
}
int nxt[MAXS];
bool match(char *t, char *s) {
    int l = strlen(s), n = strlen(t);
    nxt[0] = -1;
    int j = -1;
    for (int i = 1; i < l; ++i) {
        while (-1 != j && s[j+1] != s[i])
            j = nxt[j];
        if (s[j+1] == s[i])
            ++j;
        nxt[i] = j;
    }
    j = -1;
    for (int i = 0; i < n; ++i) {
        while (-1 != j && s[j+1] != t[i])
            j = nxt[j];
        if (s[j+1] == t[i])
            ++j;
        if (j == l-1)
            return true;
    }
    return false;
}
void work() {
    int n;
    int len = strlen(bwt);
    for (int i = 0; i < len; ++i)
        fst[i] = i;
    sort(fst,fst+len,cmp);
    for (int i = 0, j = 0; i < len-1; ++i) {
        j = fst[j];
        ori[i] = bwt[fst[j]];
    }
    ori[len-1] = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        if (match(ori,s))
            puts("YES");
        else
            puts("NO");
    }
}
void clear() {
    memset(ori,0,sizeof(ori));
}
bool load() {
    if (EOF == scanf("%s", bwt))
        return false;
    return true;
}
int main(int argc, char const *argv[]) {
    while (load()) {
        work();
        clear();
    }
    return 0;
}