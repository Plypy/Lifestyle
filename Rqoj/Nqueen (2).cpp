#include <iostream>
using namespace std;
int **map;
int N;
unsigned long num = 0;
void find(const int i);
void lock(const int x, const int y);
void unlock(const int x, const int y);
int *save;

int main()
{
    cin >> N;
    map = new int*[N];
    save = new int[N];
    for (int i = 0; i < N; i++)
        map[i] = new int[N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            map[i][j] = 0;
    find(0);
    cout << num;
    cin.get();
    cin.get();
    return 0;
}

void find(const int i)
{
    if (N == i)
    {
        num++;
        if (num <= 3)
        {
            int j;
            for (j = 0; j < N-1; j++)
                cout << save[j] << ' ';
            cout << save[j];
            cout << endl;
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
