//判断一个数的约数个数的奇偶性
//一个数的约数个数等于其被素数分解后各素数的幂加一的乘积
//所以只需要有一个素数的幂为奇数，那么所求即为偶
//而所有幂均为偶数的数，必然为平方数
//所以转换成求一个数是否为平方数即可...不用费力分解了 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    double t;
    while (true) {
        scanf("%lf", &t);
        if (!t)
            break;
        if (int(sqrt(t)) == sqrt(t))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
