// ������ʵ����stable_sort
// �������Կ��ǰ�ԭλ����Ϊ�ڶ��ؼ��ֽ��п��š� 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAXN 150005
using namespace std;

struct Team {
    int id;
    int mark;
    friend bool operator<(const Team&a, const Team&b) {
        return a.mark > b.mark;
    }
} team[MAXN];
int n;
void load() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &team[i].id, &team[i].mark);
    }
}
void work() {
    stable_sort(team+1,team+n+1);
    for (int i = 1; i <= n; ++i)
        printf("%d %d\n", team[i].id, team[i].mark);
//    system("pause");
}

int main() {
    load();
    work();
    return 0;
} 
