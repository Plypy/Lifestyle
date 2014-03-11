/*
    ID : jake1994
    PROG : frameup
    LANG : C++
*/
//������Ҫ�ҳ�һ������Ĺ�ϵ
//����������ϵĹ�ϵ
//����ÿ�����ǿ��Զ����������ν���һ����ϵ
//����Ѿ��ε��ɽ��
//ÿ���߿��ɴ������ϵ������
//��������ͨ�������������ҳ��������εĹ�ϵ 
//������ ��Ȼ�ڶ������ϳ�����
//����Ҫϸ�İ�... 
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("frameup.in");
ofstream fout("frameup.out");
const int MAXN = 31;
int h, w;
char board[MAXN][MAXN];
int ind[MAXN];
bool map[MAXN][MAXN];
int lef[MAXN];
int righ[MAXN];
int up[MAXN];
int down[MAXN];
bool exist[MAXN];
char ans[MAXN];
int num;
void scan(int d)
{
    char ch = 'A'+d;
    int b;
    for (int i = lef[d]; i <= righ[d]; i++)
    {
        if (board[up[d]][i] != ch)
        {
            b = board[up[d]][i]-'A';
            if (!map[d][b])
            {
                ind[b]++;
                map[d][b] = true;
            }
        }
        if (board[down[d]][i] != ch)
        {
            b = board[down[d]][i]-'A';
            if (!map[d][b])
            {
                ind[b]++;
                map[d][b] = true;
            }
        }
    }
    for (int i = up[d]+1; i < down[d]; i++)
    {
        if (board[i][righ[d]] != ch)
        {
            b = board[i][righ[d]]-'A';
            if (!map[d][b])
            {
                ind[b]++;
                map[d][b] = true;
            }
        }
        if (board[i][lef[d]] != ch)
        {
            b = board[i][lef[d]]-'A';
            if (!map[d][b])
            {
                ind[b]++;
                map[d][b] = true;
            }
        }
    }
}
void load()
{
    fin >> h >> w;
    char ch;
    int tmp;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
        {
            fin >> ch;
            if (ch != '.')
            {
                tmp = ch-'A';
                if (!exist[tmp])
                {
                    exist[tmp] = true;
                    num++;
                }
                board[i][j] = ch;
                if (!up[tmp] || up[tmp] > i)
                    up[tmp] = i;
                if (down[tmp] < i)
                    down[tmp] = i;
                if (!lef[tmp] || lef[tmp] > j)
                    lef[tmp] = j;
                if (righ[tmp] < j)
                    righ[tmp] = j;
            }
        }
    for (int i = 0; i < 26; i++)
        if (exist[i])
            scan(i);
}
bool used[MAXN];
void topsort(int dep)
{
    if (dep > num) 
    {
        for (int i = 1; i <= num; i++)
            fout << ans[i];
        fout << endl;
        return;
    }
    for (int i = 0; i < 26; i++)
        if (exist[i] && ind[i] == 0 && !used[i])
        {
            used[i] = true;
            for (int j = 0; j < 26; j++)
                if (exist[j] && map[i][j])
                    ind[j]--;
            ans[dep] = 'A'+i;
            topsort(dep+1);
            for (int j = 0; j < 26; j++)
                if (exist[j] && map[i][j])
                    ind[j]++;
            used[i] = false;
        }
}
int main()
{
    load();
    topsort(1);
    return 0;
}
