/*pku 2914 */
#include <stdio.h>
#include <string.h>

#define NN 304
#define INF 1 << 30
int vis[NN];
int wet[NN];
int combine[NN];
int map[NN][NN];

int S, T, minCut, N;
void Search(){
     int i, j, Max, tmp;
     memset(vis, 0, sizeof(vis));
     memset(wet, 0, sizeof(wet));
     S = T = -1;
     for (i = 0; i < N; i++){
         Max = -INF;
         for (j = 0; j < N; j++){
             if (!combine[j] && !vis[j] && wet[j] > Max){
                tmp = j;
                Max = wet[j];
             }
         }
         if (T == tmp) return;
         S = T; T = tmp;
         minCut = Max;
         vis[tmp] = 1;
         for (j = 0; j < N; j++){
             if (!combine[j] && !vis[j]){
                wet[j] += map[tmp][j];
             }
         }
     }
}
int Stoer_Wagner(){
    int i, j;
    memset(combine, 0, sizeof(combine));
    int ans = INF;
    for (i = 0; i < N - 1; i++){
        Search();
        if (minCut < ans) ans = minCut;
        if (ans == 0) return 0;
        combine[T] = 1;
        for (j = 0; j < N; j++){
            if (!combine[j]){
               map[S][j] += map[T][j];
               map[j][S] += map[j][T];
            }
        }
    }
    return ans;
}
int main()
{
    int a, b, c, M;
    int k;
    while(scanf("%d%d%d", &N, &M, &k) != EOF){
        if (!N)
            break;
        memset(map, 0, sizeof(map));
        while(M--){
            scanf("%d%d%d", &a, &b, &c);
            map[a][b] += c;
            map[b][a] += c;
        }
        printf("%d\n", Stoer_Wagner());
    }
    return 0;
}