#include <iostream>
using namespace std;
const int MAXH = 1005;
int cost[MAXH][MAXH];
int dis[MAXH][MAXH];
int h;
inline int min(int a, int b)
{
    return a<b?a:b;
}
int main()
{
//    freopen("test.in", "r", stdin);
//    freopen("test.out", "w", stdout);
    cin >> h;
    int left;
    int right;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> cost[i][j];
            if (j == 1)
                left = dis[i-1][i-1];
            else
                left = dis[i-1][j-1];
            if (j == i)
                right = dis[i-1][1];
            else
                right = dis[i-1][j];
            dis[i][j] = min(left,right)+cost[i][j];
        }
        bool flag = true;
        while (flag)//There is the cream(¾«»ª£© of my program. Because if a node is
                    //updated, it might can update its neighbours.
                    //Although there is still some optimization, like do not
                    //check all nodes of this floor, but just check this updated
                    //nodes instead. But if so, the program will be tough written
                    //and debug.
        {
            flag = false;
            for (int j = 1; j <= i; j++)
            {
                int backup = dis[i][j];
                if (j == 1)
                    left = dis[i][i];
                else
                    left = dis[i][j-1];
                if (j == i)
                    right = dis[i][1];
                else
                    right = dis[i][j+1];
                dis[i][j] = min(dis[i][j],cost[i][j]+left);
                dis[i][j] = min(dis[i][j],cost[i][j]+right);
                if (dis[i][j] < backup)
                    flag = true;
            }
        }
    }
    cout << dis[h][1] << endl;
    return 0;
}
