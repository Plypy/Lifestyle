// ���ݿ��ƺܴ�
// ����Ҫע�⵽��Ҫ��Ϊ���������ҷ�Χ����ҪС�ö� 
// ����Ҳ����˵ʹ��double���洢����ɵ������С
// ��������һ�¾������������ 
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
