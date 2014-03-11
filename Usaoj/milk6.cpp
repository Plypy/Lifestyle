/*
    ID : jake1994
    PROG : milk6
    LANG : C++
*/
//Summary
//���ǵ�һ��д��С�� 
//�����С������Ƚ����⣬Ҫ���������С����С����������ͬ��Ż�Ҫ������С
//����һ ���ⷽ������Ȩ���� 
//��ÿ�����൱���������ؼ��֣���һ��Ϊ�������ڶ���Ϊ������������Ϊ�ߵ����
//�������һ����Ȩ�������˺�������ʹ�ñ�Ȩ��С�������ϵ������ؼ��ֵ���
//���ؼ���Խ��ı�ȨԽ�󣬾���ı�Ȩ�������� 
//��һ��������Ϳ�����
//ͨ���˷�ʽ�������С�����Ȼ�����Ĵ�С��С���������٣����������С
//Ȼ������һ��floodfill�����S������ΪԴ�����ڵ��Ǹ��㼯����
//��ͨ�����жϸ�߼��ɡ� 
//������ ʹ��ö�ٴ�˼· 
//Ҳ������һ�������Ȼ��ö�ٴ�С����ö�ٱ���i 
//���ڱ߼��������Ƿ��ʱ��i�����ر�����������֮�͵��ڸ�
//�������������ᳬʱ
//�Ľ�������ͨ������һ�еı�Ȩ���������Ȩ����Ϊf(u,v) = (|e|+1)*c(u,v)+1
//����������������num=maxflow mod (|e|+1)��num��Ϊ��еı���
//Ȼ���ٽ���ö�٣�������Ȼ�Ѿ���Ƴ������ı�Ȩ�����ˣ�������ֱ���÷���һ��... 
//������ ��ͳ����
//��ͳ����������������Ȼ��ö��һ����ɾȥ����һ��������������ʱ�ı�ԭ�����
//���ٵ����պ�Ϊ�˱ߵ�������������жϴ˱����ڸ��ֱ������������Ϊ0Ϊֹ�� 
//���ڴ��������Ҫ�󣬿����ȸ��ݱߵ�������СΪ��һ�ؼ��֣��ݼ������ߵ����Ϊ�ڶ�
//�ؼ��֣����������Ƚ���һ������Ȼ�������������ö�ټ��ɡ�
//����ʵ������һ���ļ�milk6test.cpp
//����ʵ����֤���˷���������Ϊ���򲢲��ܱ�֤���������
/***********************************CutLine************************************/ 
//�ҵĴ���ʹ�÷���һ,113�аɡ����У����㳤�� 
#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
ifstream fin("milk6.in");
ofstream fout("milk6.out");
typedef unsigned long long ull;
const ull MAXN = 35;
const ull MAXE = 1001;
const ull FAC = 500501;
const ull INF = ULONG_LONG_MAX;
ull f[MAXN][MAXN];
ull n, m;
inline ull min(ull a, ull b)
{
    return a<b?a:b;
}
struct edge
{
    ull bg;
    ull ed;
} edg[MAXE];
inline void load()
{
    fin >> n >> m;
    ull s,e,c;
    for (ull i = 1; i <= m; i++)
    {
        fin >> s >> e >> c;
        f[s][e] += c*MAXE*FAC+FAC+i;
        edg[i].bg = s;
        edg[i].ed = e;
    }
}
bool found;
ull delta;
ull hct[MAXN];
ull h[MAXN];
ull loss;
void aug(ull u)
{
    if (u == n)
    {
        loss += delta;
        found = true;
        return ;
    }
    ull backup = delta;
    ull minh = n-1;
    ull v;
    for (v = 1; v <= n; v++)
        if (f[u][v]>0)
        {
            if (h[v]+1 == h[u])
            {
                delta = min(delta,f[u][v]);
                aug(v);
                if (h[1] >= n)
                    return;
                if (found)
                    break;
                delta = backup;
            }
            minh = min(minh,h[v]);
        }
    if (found)
    {
        f[u][v] -= delta;
        f[v][u] += delta;
    }
    else
    {
        hct[h[u]]--;
        if (hct[h[u]] == 0)
            h[1] = n;
        h[u] = minh+1;
        hct[h[u]]++;
    }
}
inline void sap()
{
    hct[0] = n;
    while (h[1] < n)
    {
        found = false;
        delta = INF;
        aug(1);
    }
}
bool used[MAXN];
void dfs(ull u)
{
    used[u] = true;
    for (ull v = 1; v <= n; v++)
        if (f[u][v]&&!used[v])
            dfs(v);
}
void output()
{
    fout << loss/(MAXE*FAC) << ' ' << (loss%(MAXE*FAC))/FAC << endl;
    for (int i = 1; i <= m; i++)
    {
        int s = edg[i].bg;
        int e = edg[i].ed;
        if (used[s] && !used[e])
            fout << i << endl;
    }
}
int main()
{
    load();
    sap();
    dfs(1);
    output();
    return 0;
}
