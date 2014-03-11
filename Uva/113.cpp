// 数据看似很大
// 但是要注意到答案要求为整数，而且范围比幂要小得多 
// 所以也就是说使用double来存储幂造成的误差会很小
// 四舍五入一下就能消除误差了 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    double n, p;
    while (cin >> n >> p) {
        cout << int(pow(p,1/n)+0.5) << endl;
    }
    return 0;
}
