//¹þ¹þ¹þ¹þ¹þ¹þ¹þ
//Ì«¸øÁ¦ÁË°¡
//Long live CPP 
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
const int MAXN = 2010;
int f[MAXN];
int r[MAXN];
inline int find(int a)
{
    if (f[a] != a)
        f[a] = find(f[a]);
    return f[a];
}
inline void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a==b)
        return;
    if (r[a] > r[b])
        f[b] = a;
    else
    {
        if (r[a] == r[b])
            r[b]++;
        f[a] = b;
    }
}
int main()
{
    map<string, int> data;
    int n, m, p;
    cin >> n >> m >> p;
    string tmp;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        data[tmp] = i;
        f[i] = i;
    }
    string mem;
    for (int i = 1; i <= m; i++)
    {
        cin >> tmp >> mem;
        merge(data[tmp],data[mem]);
    }
    for (int i = 1; i <= p; i++)
    {
        cin >> tmp >> mem;
        if (find(data[tmp]) == find(data[mem]))
            cout << "safe\n";
        else
            cout << "cc cry\n";
    }
    return 0;
}
