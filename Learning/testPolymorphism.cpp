#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct node{
    int t,l;
    bool operator < (const node v)const{
        return l > v.l;
    }
}p[110];


int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d",&p[i].t);
    for(int i = 0; i < n; i++)
        scanf("%d",&p[i].l);
    sort(p,p+n);
    int maxn = 0,pt = 0;

    for(int i = 0; i < n; i++){
        pt = pt+p[i].t;
        maxn = max(maxn,pt+p[i].l);
    }
    printf("%d\n",maxn);
    return 0;
}