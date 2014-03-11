#include <iostream>
using namespace std;
const int Max = 1000;
int N;
int data[101];
int list[101][101];
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            list[i][j] = Max;
    int l, r;
    for (int i = 1; i <= N; i++)
    {
        cin >> data[i] >> l >> r;
        list[i][i] = 0;
        if (l)
            list[i][l] = list[l][i] = 1;
        if (r)
            list[i][r] = list[r][i] = 1;
    }
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            if (i != k)
                for (int j = 1; j <= N; j++)
                    if (j != i && j!= k)
                        list[i][j] <?= list[i][k] + list[k][j];
    int sum;
    long min = 1000000;
    for (int i = 1; i <= N; i++)
    {
        sum = 0;
        for (int j = 1; j <= N; j++)
            sum += data[j]*list[i][j];
        min <?= sum;
    }
    cout << min;
    return 0;
}
