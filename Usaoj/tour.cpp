/*
    ID : jake1994
    PROG : tour
    LANG : C++
*/
//Note: ��ν��·����Ϊ�������ཻ�Ĵ���㵽�յ��·��
//����ʹ��DP����
//��f[i][j],��ʾ������·���ֱ���i����j��ʱ����ܾ������ٸ�����
//��Ȼf[i][j] = max(f[i][p],f[q][j])+1 
//���ǵ������������ཻ�Ĵ�1��n·��
//�����Ȼ����һ���㣬��һ��·��ͨ���˸ý����
//����һ��·�������ʱ��Ȼ����ʹ���ǰ������һ��·����ǰ��
//��������������·�����������·һ����ǰ��һ����ǰ��һ��
//���ڽ��1Ҫ����һ��
//DP2 ������Ȼͬ��,ֻ�������ò�ͬ�ķ��������ཻ·��
//�õ����ķ�����ѹ���Ͳ�������f[i][i]��״̬�����жϣ����f[1][1]��
//���������״̬��ʼ�ձ��ֳ�ʼֵ�����Ҳ�����жϽ���Ӱ��
//��ʵҲ���Խ�f[i][i]��ǰ��ʼ��Ϊ������

/*1   ��f[i][j] Ϊi������j���зֱ�������·����ǰ�����ܾ�������������Ŀ 
 *2   �㷨2α��������
 *3   for i = 1 to n
 *4      do for j = 1 to n
 *5            do f[i][j] = INF;(infinity)
 *6   f[1][1] = 1
 *7   for i = 1 to n-1
 *8      do for j = i+1 to n
 *9            do for each node u in adj[j]      adj[i]���������i��������������ű�iС�ĳ��е��б� 
 *10                 do
 *11                   if (f[i][u] > max)
 *12                       then max = f[i][u]
 *13                   f[i][j] = f[j][i] = max+1
 *14  for each node u in adj[n]
 *15     do if (f[n][u] > ans)
 *16         ans = f[n][u]
 *17  return ans
 *
 *      ֻҪ���㷨�������в�ʹ����·���ཻ����ô������ȷ�� 
 *      ��ȷ��֤��
 *      ʵ���ϵ�11����13�о��൱����һ��·���в���jԪ��
 *      ��������ͼ��������j�����������·���е�ԭ��Ԫ���ظ�
 *      �������һ��·���е�Ԫ����ž�С�ڵ���i����i��С��j
 *      ������ԭ��·�������н���������¼���jʱ�������콻���
 *      ����Ϊ���е�״̬������f[1][1]�Ƶã����Ը��㷨�ᱣ֤����·���ܲ��ཻ 
 */ 
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("tour.in");
ofstream fout("tour.out");
const int MAXN = 105;
int n, m;
string city[MAXN];
int f[MAXN][MAXN];
bool used[MAXN][MAXN];
int find(string &t)
{
    for (int i = 1; i <= n; i++)
        if (t == city[i])
            return i;
}
int adj[MAXN][MAXN];
int d[MAXN];
void load()
{
    fin >> n >> m;
    string a, b;
    for (int i = 1; i <= n; i++)
        fin >> city[i];
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        fin >> a >> b;
        u = find(a);
        v = find(b);
        if (u>v)//��Ϊֻ�ܴӺ���ǰ��·�������԰�˫������ɵ���� 
            adj[u][++d[u]] = v; 
        else
            adj[v][++d[v]] = u;
    }
}
const int NINF = -1000000;
inline int max(int a, int b)
{
    return a>b?a:b;
}
int dp(int a, int b)
{
    if (used[a][b]||used[b][a])
        return f[a][b];
    used[a][b] = used[b][a] =  true;
    int pre;
    for (int i = 1; i <= d[a]; i++)
    {
        pre = adj[a][i];
        if (pre == 1 || (pre < b))//���˻� 
        {
            f[a][b] = max(f[a][b],dp(pre,b)+1);
        }
    }
    for (int i = 1; i <= d[b]; i++)
    {
        pre = adj[b][i];
        if (pre == 1 || (pre < a))//���˻� 
        {
            f[a][b] = max(f[a][b],dp(a,pre)+1);
        }
    }
    return f[b][a] = f[a][b];
}
void work()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = NINF;
    used[1][1] = true;
    f[1][1] = 0;
    int ans = dp(n,n);
    if (ans>0)
        fout << ans << endl;
    else
        fout << 1 << endl;
}
void work2()
{
    f[1][1] = 1;
    for (int i = 1; i < n; i++)
        for (int j = i+1; j <= n; j++)
        {
            int tmp = 0;
            for (int k = 1; k <= d[j]; k++)
            {
                if (tmp < f[i][adj[j][k]])
                    tmp = f[i][adj[j][k]];
            }
            if (tmp)
                f[i][j] = f[j][i] = tmp+1;
        }
    int ans = 0;
    for (int i = 1; i <= d[n]; i++)
        ans = max(ans,f[adj[n][i]][n]);
    if (ans)
        fout << ans << endl;
    else
        fout << 1 << endl;
}
int main()
{
    load();
//    work();
    work2();
    return 0;
}
