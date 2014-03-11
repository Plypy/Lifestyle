/**
 * Description: Finding a longest substring that is a palindrome. O(n) solution.
 * Source: hdu 3068
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

const int MAXL = 110005;
char s[MAXL];
char ns[MAXL<<1];
int palin[MAXL<<1];
int id, rmost;
int ans;
void init() {
    memset(palin,0,sizeof(palin));
    memset(s,0,sizeof(s));
    memset(ns,0,sizeof(ns));
    ans = 0;
    id = 0;
    rmost = 0;
}
void work() {
    char *p = s, *q = ns;
    int len = 0;
    while (*p) {
        (*q++) = '#';
        (*q++) = (*p++);
        len += 2;
    }
    (*q++) = '#';
    for (int i = 1; i <= len; ++i) {
        if (i < rmost) {
            palin[i] = min(palin[(id<<1)-i], rmost-i);
        } else {
            palin[i] = 1;
        }
        while (i+palin[i] <= len && ns[i+palin[i]] == ns[i-palin[i]])
            ++palin[i];
        if (i+palin[i] > rmost) {
            id = i;
            rmost = i+palin[i];
        }
        ans = max(ans,palin[i]-1);
    }
    printf("%d\n", ans);
}
bool load() {
    return (EOF != scanf("%s", s));
}
int main() {
    while (load()) {
        work();
        init();
    }
}