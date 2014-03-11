/*
    ID : jake1994
    PROG : snail
    LANG : C++
*/
//�ܽ�...Ҫ�����ѵ�ͷ��
//Ҫʱ�����������ڸ�ʲô
//�ſ��Բ����ڷ��Ժ�..
//���������ҵ����
//����һ���򵥵������⣬��Ȼ�����˽�3��Сʱ
//��ʵҲ���Լ����񲻼����й�...
//�����Ľⷨ�����Ѽ��ɣ�û���Ѷ� 
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("snail.in");
ofstream fout("snail.out");
const int MAXN = 125;
const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};
short map[MAXN][MAXN];
int n, m;
void load()
{
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        map[0][i] = map[i][0] = map[n+1][i] = map[i][n+1] = -1;
    for (int i = 1; i <= m; i++)
    {
        char ch;
        int t;
        fin >> ch >> t;
        map[t][ch-'A'+1] = -1;
    }
}
int ans;
void dfs(int x, int y, int len, int dir)
{
    int tx = x, ty = y;
    while (map[tx+dx[dir]][ty+dy[dir]] == 0)
    {
        map[tx][ty] = 1;
        len++;
        tx+=dx[dir];
        ty+=dy[dir];
    }
    if (len > ans)
        ans = len;
    if (map[tx+dx[dir]][ty+dy[dir]] == -1)
        for (int d = 0; d < 4; d++)
            if (map[tx+dx[d]][ty+dy[d]] == 0)
                dfs(tx,ty,len,d);
    while (tx!=x || ty!=y)
    {
        map[tx][ty] = 0;
        tx-=dx[dir];
        ty-=dy[dir];
    }
}
void solve()
{
    map[1][1] = 1;
    dfs(1,1,1,0);
    dfs(1,1,1,2);
    fout << ans << endl;
}
int main()
{
    load();
    solve();
    return 0;
}
