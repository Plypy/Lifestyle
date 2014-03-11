/*
    ID : jake1994
    PROG : nuggets
    LANG : C++
*/
// 唉，很多时候缺的仅仅是信心啊
// 定理： 若a，b互质，则对于不定方程ax+by=c，其中c>ab，必有一对正整数解（x0,y0）
// 考虑到如果有任何一个盒子的大小是1的话那么任意大小的需求都可以被满足，
// 所以直接输出0即可
// 另外可以算出所有盒子大小的最大公约数，能被组成的数字必然为最大公约数的倍数
// 即那些不是倍数的数字无法被组成，即如果此最大公约数不为1的话，必有无限大的数字
// 无法被组成， 输出0即可
// 若此题有有限解，则其必然在[1，256^2]此集合内，直接使用无限背包模拟即可，
// 求出可以被组成的数字，然后倒序查找不能被组成的，输出第一个即可。 
#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 11;
int size[MAXN];
int n;
inline int gcd(int a, int b)
{
    int c;
    while (b)
    {
        c = a;
        a = b;
        b = c%b;
    }
    return a;
}
int main()
{
    ifstream fin("nuggets.in");
    ofstream fout("nuggets.out");
    fin >> n;
    int fac = 0;
    for (int i = 1; i <= n; i++)
    {
        fin >> size[i];
        fac = gcd(size[i],fac);
        if (size[i] == 1)
        {
            fout << 0 << endl;
            return 0;
        }
    }
    if (fac != 1)
    {
        fout << 0 << endl;
        return 0;
    }
    static bool f[65537];
    f[0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = size[i]; j <= 65536; j++)
            f[j] |= f[j-size[i]];
    for (int i = 65536; i; i--)
        if (!f[i])
        {
            fout << i << endl;
            break;
        }
    return 0;
}
