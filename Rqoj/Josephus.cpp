/*
 *  这个问题再次提示了我对于一个问题仅仅是空想是不行的
 *  要动手实践然后认识问题并发现问题的突破口 
 *  假如只要求最后一个元素的话 
 *  这样考虑问题，对于n(n>1)个元素的约瑟夫环
 *  当出去一个元素之后，又会重新构造出一个n-1个元素的约瑟夫环
 *  那么这就提示了我们可以使用递推的方法求从n=1时向后逐个递推
 *  具体方法如下：
 *  我们给每个元素重新编号为0,1,2...n-2,n-1.
 *  设last[n]为包含n个元素的约瑟夫环在给定的m下最后一个元素的序号
 *  那么则有 last[i] = 0                   (i = 1)(第i个元素被编号为i-1）
 *           last[i] = (last[i-1]+m) mod i (i > 1)
 */
#include <iostream>
#include <cstdlib>
using namespace std;
int n, m;
int main()
{
    while (cin >> n >> m)
    {
        int pos = 0;
        for (int i = 2; i <= n; ++i)
            pos = (pos+m)%i;
        cout << ++pos << endl;
        system("pause");
    }
    return 0;
}
