//ע�⵽�����з�Χ���ҷ�Χ����
//�����ü������򷽱�һЩ
//�����һ������˸���stl����͵��... 
#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 10010;
int buf[MAXN];
int main() {
    int n, q;
    int ct = 0;
    while (true) {
        scanf("%d%d", &n, &q);
        if (0 == n && 0 == q)
            break;
        printf("CASE# %d:\n", ++ct);
        
        for (int i = 1; i <= n; ++i)
            scanf("%d", buf+i);
        sort(buf+1, buf+n+1);
        
        map<int,int> table;
        for (int i = 1; i <= n; ++i) {
            if (0 == table.count(buf[i]))
                table[buf[i]] = i;
        }
        while (q--) {
            int t;
            scanf("%d", &t);
            map<int,int>::const_iterator itr = table.find(t);
            if (table.end() == itr) {
                printf("%d not found\n", t);
            } else {
                printf("%d found at %d\n", t, itr->second);
            }
        }
    }
    return 0;
}
            
