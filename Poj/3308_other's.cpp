#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define inf 1000000
#define size 200
#define eps 1e-8
struct edge
{
    int from;
    int to;
    int next;
    double val;
}e[140000];
int v[size];//���㼯��
int que[size];//��bfs�е������ã���Dinic�е���ջ����
int dis[size];//���룬���ͼ
int cnt;//����
int cur[size];//��ǰ��ĳ����Ҫ������������Ӧ�ıߣ�-1����û����
void insert(int from, int to, double va)
{
    e[cnt].from = from;
    e[cnt].to = to;
    e[cnt].val = va;
    e[cnt].next = v[from];
    v[from] = cnt++;
    e[cnt].from = to;
    e[cnt].to = from;
    e[cnt].val = 0;
    e[cnt].next = v[to];
    v[to] = cnt++;
}
bool bfs(int n, int s, int t)//����
{
    int head, tail, i;
    head = tail = 0;
    que[tail++] = s;//Դ������
    memset(dis, -1, sizeof(int) * n);
    dis[s] = 0;
    while(head < tail) // bfs,�õ�����i�ľ�s����̾���dis[i]
        for(i = v[que[head++]]; i != -1; i = e[i].next)
            if (e[i].val > eps && dis[e[i].to] == -1)
            { //dis[e[i].to] == -1˵���˶���e[i].toû�����ʵ�
                dis[e[i].to] = dis[e[i].from] + 1;
                que[tail++] = e[i].to;
                if (e[i].to == t)
                    return true;//����ܱ�������㣬˵����������·��
            }
    return false;
}

double Dinic(int N, int s, int t)//N=t+1
{
    double maxflow = 0, tmp;
    int i;
    while(bfs(N, s, t))//ÿѭ��һ��e[].val��ֵ�ᷢ���仯,bfs�Ľ��Ҳ�ᷢ���仯
    {
        int u = s, tail = 0;
        for(i = 0; i <=N; i++)//N=t+1
            cur[i] = v[i];
        while(cur[s] != -1)//s��Դ��
            if (u != t && cur[u] != -1 && e[cur[u]].val > eps && dis[u] != -1 && dis[u] + 1 == dis[e[cur[u]].to])
            {//���û�е�����t&&��u����������&&��������Ϊ0&&u���ڴ˴�BFS���ܷ��ʵ��ĵ�&&u����ĳ�������յ�
                que[tail++] = cur[u];//���������ջ��
                u = e[cur[u]].to;// ����ǰ�ƽ�
            }
            else
                if (u == t)//�ҵ�һ������·
                {
                    for(tmp = inf, i = tail - 1; i >= 0; i--)//�ҳ���С�ģ���������
                        tmp = min(tmp, e[que[i]].val);
                    for(maxflow += tmp, i = tail - 1; i >= 0; i--)//������������·��
                    {
                        e[que[i]].val -= tmp;
                        e[que[i]^ 1].val += tmp;
                        if (fabs(e[que[i]].val) <= eps)
                            tail = i;
                    }
                    u = e[que[tail]].from;
                }
                else
                {
                    while(tail > 0 && u != s && cur[u] == -1)
                        u = e[que[--tail]].from;
                    cur[u] = e[cur[u]].next;
                }
    }
    return maxflow;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    int T, n, m, l, a, b;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &l);
        int s = 0, t = n + m + 1;//sԴ�㣬t���
        double tmp;
        memset(v, -1, sizeof(int) * (t + 1));
        cnt = 0;
        for(int i = 1; i <= n; i++)//����Դ��s->X�ı�
        {
            scanf("%lf", &tmp);
            insert(s, i, log(tmp));
        }
        for(int j = 1; j <= m; j++)//����Դ��Y->t�ı�
        {
            scanf("%lf", &tmp);
            insert(j + n, t, log(tmp));
        }
        while(l--)//�����i,j������ɡ������ô����X�ڵĵ�i�򼯺�Y�ڵĵ�j��һ������Ϊ�����ıߡ�
        {
            scanf("%d%d", &a, &b);
            insert(a, b + n, inf);
        }
        tmp = Dinic(t + 1, s, t);
        printf("%.4f\n", exp(tmp));
    }
    return 0;
}
