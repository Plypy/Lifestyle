/*
 *Note:
 *      此题我一开始建模成了凸多边形...使凸多边形中不存在三角形最多的边数...
 *      可以看到这样并没有对原题有实质性的简化...悲剧鸟
 *      实际上呢，此题应该构建二分图的模型，因为是二分图吗，所以其中不可能存在
 *      三角形环，只需要求出最大的二分图边数即可。
 *      给定一个二分图，其中n(l) = a, n(r) = b， 则n(e) = a*b；
 *      这个的正确性很显然... 
 */
#include <iostream>
using namespace std;
int main()
{
unsigned long long n;
cin >> n;
cout << (n*n>>2);
return 0;
}
