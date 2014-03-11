#include <iostream>
using namespace std;
int main()
{
    const int N = 15;
    int ary[N] = {1, 5, -6, 10, 7, -23, 100, 8, 10, -7, 2, 13, 0, -10, 7};
    int f[N];
    f[0] = ary[0];
    for (int i = 1; i < N; i++)
        f[i] = f[i-1]>0?f[i-1]+ary[i]:ary[i];
    int max = f[0];
    for (int i = 1; i < N; i++)
        if (f[i] > max)
            max = f[i];
    cout << max;
    cin.get();
    return 0;
}
