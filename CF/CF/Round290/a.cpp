#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAXN = 105;

char name[MAXN][MAXN];

int smaller[MAXN][MAXN];
int N;
bool used[MAXN];
int color[MAXN];
int ans[MAXN];
int ed = 0;
bool flag = 0;

void cmp(char s1[], char s2[]) // s1 < s2
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int ubd = min(len1,len2);
    int i = 0;
    while (i < ubd && s1[i] == s2[i]) {
        ++i;
    }
    if (i == ubd) {
        if (i == len2) {
            flag = true;
        }
        return ;
    }
    int u = s1[i]-'a';
    int v = s2[i]-'a';
    smaller[u][v] = 1;
    used[u] = used[v] = true;
}

void dfs(int u)
{
    color[u] = 1;
    for (int v = 0; v < 26; ++v) {
        if (smaller[u][v]) {
            if (0 == color[v]) {
                dfs(v);
            } else if (1 == color[v]) {
                flag = true;
            }
        }
    }
    color[u] = 2;
    ans[ed++] = u;
}

int main(int argc, char *argv[])
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%s", name[i]);
    }
    for (int i = 0; i+1 < N; ++i) {
        cmp(name[i], name[i+1]);
    }
    // int que[MAXN] = {0};
    // int st = 0, ed = 0;
    // for (int i = 0; i < 26; ++i) {
    //     if (0 == ind[i]) {
    //         que[ed++] = i;
    //     }
    // }
    // while (st < ed) {
    //     int tst = st;
    //     int ted = ed;
    //     for (int i = tst; i < ted; ++i) {
    //         int u = que[st++];
    //         for (int v = 0; v < 26; ++v) {
    //             if (smaller[u][v]) {
    //                 --ind[v];
    //                 if (0 == ind[v]) {
    //                     que[ed++] = v;
    //                 }
    //             }
    //         }
    //     }
    // }
    for (int i = 0; i < 26; ++i) {
        if (used[i] && 0 == color[i]) {
            dfs(i);
        }
    }
    if (flag) {
        puts("Impossible");
    } else {
        reverse(ans, ans+ed);
        for (int i = 0; i < 26; ++i) {
            if (!color[i]) {
                ans[ed++] = i;
            }
        }
        for (int i = 0; i < 26; ++i) {
            putchar(ans[i]+'a');
        }
        puts("");
    }
    return 0;
}
