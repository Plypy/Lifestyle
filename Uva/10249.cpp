// Accepted
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 71;
const int MAXM = 51;
const int MAXNUM = 101;

struct Team {
    int num;
    int id;
    friend bool operator<(const Team &a, const Team &b) {
        return a.num > b.num;
    }
} team[MAXN];

int table[MAXM];
int n, m;

bool load() {
    scanf("%d%d", &n, &m);
    if (0 == n)
        return false;
    for (int i = 1; i <= n; ++i) {
        team[i].id = i;
        scanf("%d", &team[i].num);
    }
    for (int i = 1; i <= m; ++i)
        scanf("%d", table+i);
    return true;
}

int anslist[MAXN][MAXNUM];
bool successful;
void work() {
    successful = false;
    
    sort(team+1,team+n+1);
    for (int i = 1; i <= n; ++i) {
        int ct = 0;
        anslist[team[i].id][0] = team[i].num;
        for (int j = 1; j <= m; ++j)
            if (table[j]) {
                --table[j];
                anslist[team[i].id][++ct] = j;
                if (ct == team[i].num)
                    break;
            }
        if (ct != team[i].num)
            return ;
    }
    successful = true;
}

void output() {
    if (!successful) {
        printf("0\n");
        return ;
    }
    printf("1\n");
    for (int i = 1; i <= n; ++i) {
        printf("%d", anslist[i][1]);
        for (int j = 2; j <= anslist[i][0]; ++j)
            printf(" %d", anslist[i][j]);
        printf("\n");
    }
}
int main() {
    while (load()) {
        work();
        output();
    }
    return 0;
}
