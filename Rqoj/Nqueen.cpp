#include <iostream>
using namespace std;
const int MAXN = 13;
int map[MAXN][MAXN];
int N;
unsigned long ct = 0;
void find(const int i);
void lock(const int x, const int y);
void unlock(const int x, const int y);
int save[MAXN];;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            map[i][j] = 0;
    find(0);
    printf("%d",ct);
    cin.get();
    cin.get();
    return 0;
}

void find(const int i)
{
    if (N == i)
    {
        ct++;
        if (ct <= 3)
        {
            int j;
            for (j = 0; j < N-1; j++)
                printf("%d ", save[j]);
            printf("%d\n",save[j]);
        }
        return;
    }
    for (int j = 0; j < N; j++)
    {
        if (!map[i][j])
        {
            save[i]=j+1;
            lock(i,j);
            find(i+1);
            unlock(i,j);
        }
    }
}

void lock(const int x, const int y)
{
    for (int i = x+1; i < N; i++)
    {
        map[i][y]++;
        if (i-x+y<N)
            map[i][y+i-x]++;
        if (y-i+x>=0)
            map[i][y-i+x]++;
    }
}
void unlock(const int x, const int y)
{
    for (int i = x+1; i < N; i++)
    {
        map[i][y]--;
        if (i-x+y<N)
            map[i][y+i-x]--;
        if (y-i+x>=0)
            map[i][y-i+x]--;
    }
}
