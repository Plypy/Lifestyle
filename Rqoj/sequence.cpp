//此题就是考察二进制
//二进制实在是伟大！ 
//样例其实是这样的
//3 100
//其中 100 可以表示成二进制数 1100100
//则981就为3的2次方加3的5次方加3的6次方
//即981=3^2+3^5+3^6 
#include <iostream>
using namespace std;
int bas, n;
bool list[10];
int sq(int bas, int j);
int main()
{
    cin >> bas >> n;
    int ans = 0;
    int i = 0;
    while (n)
    {
        list[i++] = n%2;
        n/=2;
    }
    for (int j = 0; j < i; j++)
    {
        if (list[j])//这次是把0也用上啦..久违～ 
            ans+=sq(bas,j);//继续函数式思路 呵呵 
    }
    cout << ans;
    return 0;
}
int sq(int bas, int j)
{
    int res = 1;
    for (int i = 1; i <= j; i++)
        res*=bas;
    return res;
}
