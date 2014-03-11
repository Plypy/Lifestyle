//不知道哪错了，真操蛋哇。。。 
// 真他妈傻逼，数据错了浪费我半天时间 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAXH = 110;
const int MAXW = MAXH;
bool map[MAXH][MAXW];
int memo[MAXH][MAXW][4];// 0,1,2,3 corresponding to N, E, S, W respectively
const int move[4][2] = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};
int dest_x, dest_y;
int h, w;
int v0, d0, x0, y0;
inline void eatline() {
    while (getchar() != '\n')
        continue;
}
void load() {
    scanf("%d%d%d", &h, &w, &v0);
    for (int i = 1; i <= h; ++i) {
        eatline();
        for (int j = 1; j <= w; ++j) {
            char ch;
            scanf("%c", &ch);
            switch (ch) {
            case '.':
                break;
            case '#':
                map[i][j] = true;
                break;
            case 'N':
                map[i][j] = true;
                x0 = i;
                y0 = j;
                d0 = 0;
                break;
            case 'E':
                map[i][j] = true;
                x0 = i;
                y0 = j;
                d0 = 1;
                break;
            case 'S':
                map[i][j] = true;
                x0 = i;
                y0 = j;
                d0 = 2;
                break;
            case 'W':
                map[i][j] = true;
                x0 = i;
                y0 = j;
                d0 = 3;
                break;
            case 'F':
                map[i][j] = true;
                dest_x = i;
                dest_y = j;
                break;
            }
        }
    }
}
int ans;
void dfs(int x, int y, int drct, int cur_v) {
    if (x == dest_x && y == dest_y) {
        if (cur_v > ans)
            ans = cur_v;
        return ;
    }
    if (cur_v <= memo[x][y][drct])
        return;
    memo[x][y][drct] = cur_v;
    bool flag = true;
    // Go straight
    int tx, ty, td;
    tx = x+move[drct][0];
    ty = y+move[drct][1];
    if (map[tx][ty]) {
        flag = false;
        dfs(tx,ty,drct,cur_v+1);
    }
    // Turn right
    td = (drct+1)%4;
    tx = x+move[td][0];
    ty = y+move[td][1];
    if (map[tx][ty]) {
        flag = false;
        dfs(tx,ty,td,(cur_v-39)<=0?1:cur_v-39);
    }
    // Turn left
    td = (drct+3)%4;
    tx = x+move[td][0];
    ty = y+move[td][1];
    if (map[tx][ty]) {
        flag = false;
        dfs(tx,ty,td,(cur_v-34)<=0?1:cur_v-34);
    }
    // Turn around
    if (flag) {
//        cout << "Turn around " << x << ' ' << y << ' ' << drct << ' ' << cur_v << endl;
        td = (drct+2)%4;
        tx = x+move[td][0];
        ty = y+move[td][1];
        dfs(tx,ty,td,1);
    }
}

void work() {
//    memset(memo,0xff,sizeof(memo));
    dfs(x0,y0,d0,v0);
    printf("%d\n", ans);
//    system("pause");
}
int main() {
    load();
    work();
    return 0;
}
/*
h 17 w 21
         #
         #  
        ....      .        ..
        .#........#...........
15      .##################E.
                           .
                           .
15 20 start
v0 642
3 2 end
v 374
*/
