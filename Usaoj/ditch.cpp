/*
    ID : jake1994
    PROG : ditch
    LANG : C++
*/
/*
 * It's my first time writing the maxflow code.
 * The method I used is Ford Fulkerson Method,
 * which depend on finding augmenting path to
 * get the maxflow.
 * For finding augmenting path, I had used 3 different
 * ways, they are modified Dijkstra algorthim,
 * Broad First Search, i.e. the Edmonds Karp algorithm
 * and the SAP(Shortest Augmenting Path).
 * To deal with selfsame edge, what I have done
 * is just regard those selfsame edges as one edge,
 * whose capacity is the sum of those selfsame
 * edge.
 */
//��һ��д�������...
//ʹ�õ�������·�㷨����Ford_fulkerson�㷨 
//���õ����޸Ĺ���Dijkstra�㷨Ѱ������·
//���Ƿǳ����ڱ�д��
//��಻��5�ξ͹���
//���ڴ����е�һ�㵽��һ����ܴ��ڶ����ߵĴ������ܼ򵥣�
//��Ϊ����Ҫ���¹�������������Զ��ڶ���������յ����ͬ�ı�ֱ�ӽ���ϲ���һ��
//�߼��ɣ�����Ϊ��֮��.
//Ȼ����ʹ��BFSѰ������·��Edmonds_karp�㷨
//����SAP 
#include <iostream>
#include <climits>
#include <cstring>
#include <fstream>
using namespace std;
ifstream fin("ditch.in");
ofstream fout("ditch.out");
const int MAXN = 205;
const int INF = 52111425;
int capacity[MAXN][MAXN];
int flow[MAXN];
int pre[MAXN];
int hcount[MAXN];
int height[MAXN];
bool used[MAXN];
int sap_result;
int delta;
bool found;
int n, m;
inline int min(int a, int b)
{
    return a<b?a:b;
}
int Ford_Fulkerson()// Using modified Dijkstra Algorithm to find the augment path
{
    int ret = 0;
    int maxloc;
    int maxflow;
    while (true)
    {
        memset(used,0,sizeof(used));
        memset(flow,0,sizeof(flow));
        memset(pre,0,sizeof(pre));
        flow[1] = INF;
        while (true)
        {
            maxflow = 0;
            maxloc = 0;
            for (int i = 1; i <= m; i++)
                if (!used[i] && flow[i] > maxflow)
                {
                    maxflow = flow[i];
                    maxloc = i;
                }
            if (!maxloc)
                goto outside;
            if (maxloc == m)
                break;
            used[maxloc] = true;
            for (int i = 1; i <= m; i++)
                if (capacity[maxloc][i]>0)
                {
                    int tmp = min(maxflow, capacity[maxloc][i]);
                    if (flow[i] < tmp)
                    {
                        pre[i] = maxloc;
                        flow[i] = tmp;
                    }
                }
        }
        ret += flow[m];
        int now = m;
        int nxt;
        while (now != 1)
        {
            nxt = pre[now];
            capacity[nxt][now] -= flow[m];
            capacity[now][nxt] += flow[m]; 
            now = pre[now];
        }
    }
outside:
    return ret;
}
// Edmonds_Karp
int Edmonds_Karp()
{
    int que[MAXN];
    int bg, ed;
    int ret = 0;
    int aug;
    int loc;
    while (true)
    {
        memset(pre,0,sizeof(pre));
        for (que[bg=ed=0]=1; bg<=ed; bg++)
        {
            loc = que[bg];
            for (int i = 1; i <= m && !pre[m]; i++)
            {
                if (capacity[loc][i] > 0 && !pre[i])
                {
                    pre[i] = loc;
                    que[++ed] = i;
                }
            }
            if (pre[m])
                break;
        }
        if (!pre[m])
            break;
        int u, v;
        aug = INF;
        for (u = pre[v=m]; v != 1; v = u, u = pre[v])
            if (aug > capacity[u][v])
                aug = capacity[u][v];
        ret += aug;
        for (u = pre[v=m]; v != 1; v = u, u = pre[v])
        {
            capacity[u][v] -= aug;
            capacity[v][u] += aug;
        }
    }
    return ret;
}
// sap part
void aug(int u)
{
    if (u == m)
    {
        sap_result += delta;
        found = true;
        return;
    }
    int backup = delta;
    int minheight = m-1;
    int v;
    for (v = 1; v <= m; v++)
        if (capacity[u][v] > 0)
        {
            if (height[v]+1 == height[u])
            {
                delta = min(delta, capacity[u][v]);
                aug(v);
                if (height[1] >= m)
                    return;
                if (found)
                    break;
                delta = backup;
            }
            minheight = min(minheight, height[v]);
        }
    if (found)
    {
        capacity[u][v] -= delta;
        capacity[v][u] += delta;
    }
    else
    {
        hcount[height[u]]--;
        if (hcount[height[u]]==0)
            height[1] = m;
        height[u] = minheight+1;
        hcount[height[u]]++;
    }
}
int sap()
{
    hcount[0] = m;
    while (height[1] < m)
    {
        delta = INF;
        found = false;
        aug(1);
    }
    return sap_result;
}
// main part
int main()
{
    fin >> n >> m;
    int s, e, c;
    for (int i = 1; i <= n; i++)
    {
        fin >> s >> e >> c;
        capacity[s][e] += c;
    }
    int ans = sap();
    fout << ans << endl;
    fin.close();
    fout.close();
    return 0;
}
