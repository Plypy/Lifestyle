#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int MAXN = 60010;
const int MAXT = 256;

int sum[MAXN], wa[MAXN], wb[MAXN];
bool cmp(int *r, int a, int b, int l) {
    return ((r[a] == r[b]) && (r[a+l] == r[b+l]));
}

void da(int *r, int *sa, int n, int m) {
    int *x = wa, *y = wb;
    memset(sum,0,sizeof(sum));
    for (int i = 0; i < n; ++i)
        ++sum[x[i]=r[i]];
    for (int i = 1; i < m; ++i)
        sum[i] += sum[i-1];
    for (int i = n-1; i >= 0; --i)
        sa[--sum[x[i]]] = i;
    
    for (int j = 1, p = 1; p < n; j <<= 1, m = p) {
        p = 0;
        for (int i = n-j; i < n; ++i)
            y[p++] = i;
        for (int i = 0; i < n; ++i)
            if (sa[i] >= j)
                y[p++] = sa[i]-j;
        
        memset(sum,0,sizeof(sum));
        for (int i = 0; i < n; ++i)
            ++sum[x[i]];
        for (int i = 1; i < m; ++i)
            sum[i] += sum[i-1];
        for (int i = n-1; i >= 0; --i)
            sa[--sum[x[y[i]]]] = y[i];
        
        swap(x,y);
        x[sa[0]] = 0;
        p = 1;
        for (int i = 1; i < n; ++i)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}


int cow[MAXN], sa[MAXN], rank[MAXN], n;
const int ROW = 80;

int main() {
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        getchar();
        cow[2*n-i] = cow[i] = getchar();
    }
    int len = 2*n+2;
    da(cow,sa,len,MAXT);
    for (int i = 0; i < len; ++i)
        rank[sa[i]] = i;

    int l, r, ct;
    for (l = 0, r = n+1, ct = 1; ct < n; ++ct) {
        if (rank[l] < rank[r])
            putchar(cow[l++]);
        else
            putchar(cow[r++]);
        if (0 == ct%ROW)
            putchar('\n');
    }
    printf("%c\n",cow[l]);
//    system("pause");
    return 0;
}
