//���ǵ�ÿ�η�ת����Ӱ�쵽��������ļ��
//���Դ������������ҵ����ģ���������Ȼ�󷭵�Ҫ��λ�� 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 55;
int stk[MAXN];

inline void turn(int l, int r) {
    for (;l < r; ++l, --r)
        swap(stk[l],stk[r]);
}

int main() {
    while (EOF != scanf("%d", stk+1)) {
        int n = 1;
        while ('\n' != getchar()) {
            scanf("%d", stk+(++n));
        }
        printf("%d", stk[1]);
        for (int i = 2; i <= n; ++i)
            printf(" %d", stk[i]);
        puts("");
        for (int i = n; i; --i) {
            int max_pos = 1, max_val = stk[1];
            for (int j = 2; j <= i; ++j)
                if (stk[j] > max_val) {
                    max_val = stk[j];
                    max_pos = j;
                }
            if (max_pos != i) {
                if (1 != max_pos) {
                    printf("%d ", n-max_pos+1);
                    turn(1,max_pos);
                }
                printf("%d ", n-i+1);
                turn(1,i);
            }
        }
        printf("0\n");
    }
    return 0;
}
