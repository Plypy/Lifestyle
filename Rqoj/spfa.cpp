//Note：差点就一次ac了，原因是因为链表开得不够大
//      在spfa中链表大小要根据边数来确定！ 
#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;
const int MAX = 30010;
struct edge
{
    int key;
    int cost;
    edge * next;
    edge():key(0),next(0),cost(0){}
    edge(int _key, int _cost, edge* _next):
        key(_key),cost(_cost),next(_next){}
}v[MAX], *p[MAX];
int n, m;
int list[MAX*10];
int dist[MAX];
int bg = 1;
int ed = 1;
bool in[MAX];
int main()
{
    cin >> n >> m;
    int a, b, tmp;
    for (int i = 1; i <= n; i++)
        p[i] = &v[i];
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &a, &b, &tmp);
        p[a]->next = new edge(b,tmp,p[a]->next);
        p[b]->next = new edge(a,tmp,p[b]->next);
    }
    list[bg] = 1;
    for (int i = 2; i <= n; i++)
        dist[i] = INT_MAX;
    dist[1] = 0;
    in[1] = true;
    edge * ptr;
    int index;
    while (bg<=ed)
    {
        index = list[bg++];
        in[index] = false;
        for (ptr=p[index]->next; ptr; ptr = ptr->next)
        {
            if (dist[ptr->key] > dist[index]+ptr->cost)
            {
                dist[ptr->key] = dist[index]+ptr->cost;
                if (!in[ptr->key])
                    list[++ed] = ptr->key;
            }
        }
    }
    cout << dist[n];
    return 0;
}
/*
样例一
5 3
1 4 5
4 5 1
1 2 7

样例二
10 11
1 2 3
2 3 4
3 4 5
4 5 6
5 6 7
6 7 8
7 8 9
8 9 10
9 10 11
1 5 7
6 9 3
样例一
6

样例二
28*/
