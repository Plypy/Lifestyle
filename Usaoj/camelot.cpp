/*
    ID : jake1994
    PROG : camelot
    LANG : C++
*/
#include <cstdio>
#include <cstdlib>
#define MAX 0x7FFFFFFF
 
int n, m, kx, ky, tx, ty, all, ans=MAX, flag=0;
const int move[8][2]={{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};
const int kmove[8][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
char tmp;
int g[30][26];
int r[30][26];
int t[30][26]={};
struct Queue {
       int x, y;
} q[1000];
struct Back {
       int x[8];
       int y[8];
       int num;
} b[30][26];
int qh,qt;
 
void backto(int x, int y) {
     if (r[x][y]) return ;
     r[x][y]=1;
     for (int i=0;i<b[x][y].num;i++) backto(b[x][y].x[i],b[x][y].y[i]);
}
 
inline void init () {
       for (int i=0;i<m;i++)
       for (int j=0;j<n;j++) {
           g[i][j]=MAX;
           r[i][j] = b[i][j].num = 0;
       }
       qh=all=0;
       qt=1;
}
 
inline void bfs () {
       while (qh<qt) {
             if (t[q[qh].x][q[qh].y]) flag=1;
             for (int i=0;i<8;i++) {
                 int mx=q[qh].x+move[i][0];
                 int my=q[qh].y+move[i][1];
                 if (mx>=0&&mx<m&&my>=0&&my<n) {
                    if (g[mx][my] >= g[q[qh].x][q[qh].y]+1) {
                       b[mx][my].x[b[mx][my].num]=q[qh].x;
                       b[mx][my].y[b[mx][my].num++]=q[qh].y;
                       if (t[mx][my]||r[mx][my]) backto(q[qh].x,q[qh].y);
                    }
                    if (g[mx][my]==MAX) {
                       g[mx][my] = g[q[qh].x][q[qh].y]+1;
                       q[qt].x=mx;
                       q[qt++].y=my;
                       if (t[mx][my]) all+=g[mx][my];
                    }
                 }
             }
             qh++;
       }
}
 
inline void king () {
       if (r[kx][ky]||t[kx][ky]) return ;
       for (int i=0;i<m;i++)
       for (int j=0;j<n;j++) g[i][j]=MAX;
       q[0].x=kx;q[0].y=ky;
       qh=0;qt=1;g[kx][ky]=0;
       while (qh<qt) {
             for (int i=0;i<8;i++) {
                 int mx=q[qh].x+kmove[i][0];
                 int my=q[qh].y+kmove[i][1];
                 if (mx>=0&&mx<m&&my>=0&&my<n&&g[mx][my]==MAX) {
                    q[qt].x=mx;
                    q[qt++].y=my;
                    g[mx][my]=g[q[qh].x][q[qh].y]+1;
                    if (r[mx][my]||t[mx][my]) {all+=g[mx][my];return;}
                 }
             }
             qh++;
       }
}
 
int main() {
    freopen("camelot.in","r",stdin);
    freopen("camelot.out","w",stdout);
    scanf("%d%d\n%c%d",&m,&n,&tmp,&kx);ky=tmp-'A';kx--;tmp=getchar();
    while ( tmp!=-1 ) {
          if (tmp<'A') {tmp=getchar() ;continue;}
          ty=tmp-'A';
          scanf("%d",&tx);
          t[--tx][ty]=1;
          flag=1;
          tmp=getchar();
    }
    if (flag==0) {printf("0\n");return 0;}
    for (int i=0;i<m;i++)
    for (int j=0;j<n;j++) {
        init();
        g[i][j]=0;
        r[i][j]=1;
        q[0].x=i;
        q[0].y=j;
        flag=0;
        bfs();
        if (flag==0) continue;
        king();
        if (ans>all) ans=all;
    }
    printf("%d\n",ans);
    return 0;
}
