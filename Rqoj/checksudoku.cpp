#include <iostream>
using namespace std;
const int id[10][10] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
    {0, 1, 1, 1, 2, 2, 2, 3, 3, 3},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
    {0, 4, 4, 4, 5, 5, 5, 6, 6, 6},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9},
    {0, 7, 7, 7, 8, 8, 8, 9, 9, 9}
};
bool l[10][10];
bool r[10][10];
bool b[10][10];
int main()
{
    int tmp, bx;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            bx = id[i][j];
            cin >> tmp;
            if (l[i][tmp] || r[j][tmp] || b[bx][tmp])
            {
                cout << 0;
                return 0;
            }
            l[i][tmp] = r[j][tmp] = b[bx][tmp] = true;
        }
    cout << 1;
    return 0;
}
