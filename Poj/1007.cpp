#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 55
#define MAXM 105

char seq[MAXM][MAXN];
struct Data {
    int inv;
    int id;
} data[MAXM];
int cmp(const void *a, const void *b) {
    const Data *pa = (Data*)a;
    const Data *pb = (Data*)b;
    if (pa->inv != pb->inv)
        return pa->inv - pb->inv;
    return pa->id - pb->id;
}
int n, m;
int main() {
    scanf("%d%d", &n, &m);
    getchar();
    for (int t = 0; t < m; ++t) {
        data[t].id = t;
        gets(seq[t]);
        for (int i = 0; i < n-1; ++i)
            for (int j = i+1; j < n; ++j)
                if (seq[t][i] > seq[t][j])
                    ++data[t].inv;
    }
    qsort(data,m,sizeof(Data),cmp);
    for (int i = 0; i < m; ++i)
        puts(seq[data[i].id]);
//    system("pause");
    return 0;
}
