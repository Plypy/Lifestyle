#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
int orange[MAXN*2], apple[MAXN*2];
int id[MAXN*2];
int n;
bool cmp(const int &a, const int &b) {
    return orange[a]<orange[b];
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        scanf("%d", &n);
        int num = 2*n-1;
        for (int j = 1; j <= num; ++j) {
            scanf("%d%d", orange+j, apple+j);
            id[j] = j;
        }
        sort(id+1,id+num+1,cmp);
        printf("YES\n");
        for (int j = 1; j < n; ++j) {
            if (apple[id[2*j]] > apple[id[2*j-1]]) {
                printf("%d ", id[2*j]);
            } else {
                printf("%d ", id[2*j-1]);
            }
        }
        printf("%d\n", id[num]);
    }
    return 0;
}
