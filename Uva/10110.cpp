//�ж�һ������Լ����������ż��
//һ������Լ�����������䱻�����ֽ����������ݼ�һ�ĳ˻�
//����ֻ��Ҫ��һ����������Ϊ��������ô����Ϊż
//�������ݾ�Ϊż����������ȻΪƽ����
//����ת������һ�����Ƿ�Ϊƽ��������...���÷����ֽ��� 
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
