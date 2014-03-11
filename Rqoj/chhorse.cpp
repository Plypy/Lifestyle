#include <iostream>
using namespace std;
int N;
int M;
int X;
int Y;
bool safe(int a, int b)
{return (a!=X||b!=Y)&&((a-X)*(b-Y)!=2)&&((a-X)*(b-Y)!=-2);}
int main()
{
    cin >> N >> M >> X >> Y;
    static long map[21][21];
    map[0][0] = 1;
    for (int i = 1; i <= N; i++)
        if (safe(i,0))
            map[i][0] = map[i-1][0];
    for (int i = 1; i <= M; i++)
        if (safe(0,i))
            map[0][i] = map[0][i-1];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (safe(i,j))
                map[i][j] = map[i-1][j]+map[i][j-1];
    cout << map[N][M];
    return 0;
}
