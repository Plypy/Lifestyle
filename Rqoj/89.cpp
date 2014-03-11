// Æô·¢Ê½ËÑË÷ 
#include <cstdlib>
#include <algorithm>
using namespace std;
const int INF = 52111425;
const int MAXN = 65;
const int MAXK = 7;
struct Guy {
    int k;
    int able[MAXK];
    bool can[MAXN];
    int done[MAXK];
    friend bool operator<(const Guy &a, const Guy &b) {
        return b.k < a.k;
    }
} guy[MAXN];
struct Job {
    int id;
    int ct;
    friend bool operator<(const Job &a, const Job &b) {
        return a.ct < b.ct;
    }
} job[MAXN];
bool done[MAXN];
int n, m;
int ans = INF;
void load() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        job[i].id = i;
        
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &guy[i].k);
        guy[i].able[0] = guy[i].k;
        for (int j = 1; j <= guy[i].k; ++j) {
            scanf("%d", &guy[i].able[j]);
            guy[i].can[guy[i].able[j]] = true;
            ++job[guy[i].able[j]].ct;
        }
    }
}
void dfs(int kth, int tot) {
    if (tot >= ans)
        return ;
    if (kth == n+1) {
        if (tot < ans)
            ans = tot;
        return ;
    }
    int jobid = job[kth].id;
    if (done[jobid])
        dfs(kth+1,tot);
    else {
        for (int i = 1; i <= m; ++i)
            if (guy[i].able[0] && guy[i].can[jobid]) {
                guy[i].able[0] = 0;
                for (int j = 1; j <= guy[i].k; ++j)
                    if (!done[guy[i].able[j]]) {
                        done[guy[i].able[j]] = true;
                        guy[i].done[++guy[i].done[0]] = guy[i].able[j];
                    }
                
                dfs(kth+1,tot+1);
                
                guy[i].able[0] = guy[i].k;
                for (int j = 1; j <= guy[i].done[0]; ++j)
                    done[guy[i].done[j]] = false;
                guy[i].done[0] = 0;
            }
    }
}
void work() {
    sort(job+1,job+n+1);
    sort(guy+1,guy+m+1);
    dfs(1,0);
    printf("%d\n", ans);
//    system("pause");
}

int main() {
    load();
    work();
    return 0;
}
/*
4 4
2 1 2
1 4
3 2 3 4
2 1 3

ans

2
*/
