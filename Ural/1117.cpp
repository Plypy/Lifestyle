// ��������һ����ȫ������������̬�ǵݹ鶨��ģ����Կ�������Ҳ�õݹ�Ŀ���
// ��ԭ����ֽ�Ϊһ��һ�������⣬Ȼ����Խ�� 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXH = 32;
typedef unsigned long long ull;
ull f[MAXH];
ull sum[MAXH];

void init() {
    for (int i = 1; i < MAXH; ++i)
        sum[i] = (sum[i-1]<<1)+1;
    for (int i = 3; i < MAXH; ++i)
        f[i] = (f[i-1]+i-2)<<1;
}

ull cal(ull x) {
    ull ret = 0;
    while (x) {
        int i;
        for (i = MAXH-1; sum[i] > x; --i)
            continue;
        x -= sum[i];
        switch (x) {
        case 0:
            ret += f[i];
            break;
        case 1:
            ret += f[i]+i-1;
            --x;
            break;
        default:
            ret += f[i]+((i-1)<<1);
            --x;
            break;
        }
    }
    return ret;
}
int main() {
    init();
    ull a, b;
    scanf("%llu%llu", &a, &b);
    if (a > b)
        swap(a,b);
    printf("%llu\n", cal(b)-cal(a));
    return 0;
}
