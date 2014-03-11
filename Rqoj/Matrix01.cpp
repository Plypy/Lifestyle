/* 思路：满足条件的矩阵分为两种
 * 内部无0的与内部有0的矩阵
 * 对与前一种，可以逐个枚举更新答案即可
 * 第二种可以通过一次floodfill找出各个0的联通块 
 */
#include <stdio.h>
const int maxn=2010;
char map[maxn][maxn];
int n,m;
int ans=0;
void init()
{
    scanf("%d%d",&n,&m);
    bool flag=0;
    for (int i=1;i<=n ;i++ ){
        for (int j = 1; j <= m ; j++){
            char t;
            do
            {
                t=getchar() - '0';
            }
            while ( (t | 1) != 1);
            flag |= (map[i][j] = t);
        }
    }
    if (!flag)
        printf("0\n");
}

void work1()
{
    ans=1;
    for (int i = 1 ; i <= n ; i++){
        int t1 = 0 , t2 = 0;
        for (int j = 1 ; j <= m ; j++){
            if (map[i][j]) ans >?= ++t1;
            else t1 = 0;
            if (map[i][j] && map[i+1][j]) ans >?= (t2 += 2);
            else t2 = 0;
        }
    }
    for (int i = 1 ; i <= m ; i++){
        int t1 = 0 , t2 = 0;
        for (int j = 1 ; j <= n ; j++){
            if (map[j][i]) ans >?= ++t1;
            else t1 = 0;
            if (map[j][i] && map[j][i+1]) ans >?= (t2 += 2);
            else t2 = 0;
        }
    }
}

bool used[maxn][maxn];
int max_row,max_column,min_row,min_column;
int sum;

void floodfill(int x, int y)
{
    if (map[x][y] || used[x][y] || x > n || x < 1 || y > m || y < 1)
        return;
    sum++;
    max_row >?= x;
    min_row <?= x;
    max_column >?= y;
    min_column <?= y;
    used[x][y] = 1;
    floodfill(x, y+1);
    floodfill(x, y-1);
    floodfill(x-1, y);
    floodfill(x+1, y);
}

void work0()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1 ; j <= m ; j++)
            if (!map[i][j] && !used[i][j]){
                sum = 0;
                max_row = min_row = i;
                max_column = min_column = j;
                floodfill(i,j);
                if (max_row < n && min_row > 1 && 
                    max_column < m && min_column > 1 &&
                    sum == (max_row - min_row + 1) * (max_column - min_column + 1) &&
                    map[max_row+1][max_column+1] && map[max_row+1][min_column-1] &&
                    map[min_row-1][max_column+1] && map[min_row-1][min_column-1])
                    ans >?= (max_row - min_row + 1 + 2) * (max_column - min_column + 1 + 2);
            }
}

int main()
{
    init();
    work1();
    work0();
    printf("%d\n" , ans);
    return 0;
}
