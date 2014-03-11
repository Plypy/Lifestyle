#include <iostream>
template <typename T>
T min(T a, T b)
{
    if (a <= b)
        return a;
    return b;
}

int main()
{
    int a[2][6]={{7,9,3,4,8,4},{8,5,6,4,5,7}};
    int t[2][5]={{2,3,1,3,4},{2,1,2,2,1}};
    int e1 = 2, e2 = 4, x1= 3, x2 = 2;
    int f[2][6];
    f[0][0] = e1+a[0][0];
    f[1][0] = e2+a[1][0];
    for (int i = 1; i < 6; i++)
    {
        f[0][i] = min(f[0][i-1], f[1][i-1]+t[1][i-1])+a[0][i];
        f[1][i] = min(f[1][i-1], f[0][i-1]+t[0][i-1])+a[1][i];
    }
    int result = min(f[0][5]+x1, f[1][5]+x2);
    std::cout << result;
    std::cin.get();
    return 0;
}
