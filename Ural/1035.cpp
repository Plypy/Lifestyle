// �۹��������������� һ��AC�ĸо���� 
// �������������㷨��������Ϣѧ����p274 
// note ��Ϊ��ת�����еĴ���
// ����Ϊ������ת������ �Ǹ�б���ַ����������ע�͵�б�壩
// ʵ����Ӧ��Ҫ������ 
#include <iostream>
#include <cstdlib>
using namespace std;
const int MAXN = 205;
bool f[2][MAXN][MAXN];//1 for /
int d[MAXN][MAXN];//store the vertices' degree
int ans;//final answer
int n, m;
bool flag[MAXN][MAXN];
void load()//load file and construct the graph model
{
    cin >> n >> m;
    char ch;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> ch; 
            if ('\\' == ch || 'X' == ch)//������ 
            {
                ++d[i][j];
                ++d[i-1][j-1];
                flag[i][j] = flag[i-1][j-1] = true;
                f[0][i][j] = true;
            }
            if ('/' == ch || 'X' == ch)
            {
                ++d[i-1][j];
                ++d[i][j-1];
                flag[i-1][j] = flag[i][j-1] = true;
                f[1][i][j] = true;
            }
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> ch;
            if ('\\' == ch || 'X' == ch)
            {
                --d[i][j];
                --d[i-1][j-1];
                flag[i][j] = flag[i-1][j-1] = true;
                f[0][i][j] = true;
            }
            if ('/' == ch || 'X' == ch)
            {
                --d[i-1][j];
                --d[i][j-1];
                flag[i-1][j] = flag[i][j-1] = true;
                f[1][i][j] = true;
            }
        }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            d[i][j] = abs(d[i][j]);
}
bool used[MAXN][MAXN];
int dfs(int row, int col)
{
    int ret = 0;
    ret += d[row][col];
    used[row][col] = true;
    if (!used[row-1][col-1] && f[0][row][col])
        ret += dfs(row-1,col-1);
    if (!used[row+1][col+1] && f[0][row+1][col+1])
        ret += dfs(row+1,col+1);
    if (!used[row+1][col-1] && f[1][row+1][col])
        ret += dfs(row+1,col-1);
    if (!used[row-1][col+1] && f[1][row][col+1])
        ret += dfs(row-1,col+1);
    return ret;
}
void work()
{
    int tmp;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            if (!used[i][j] && flag[i][j])
            {
                tmp = dfs(i,j);
                if (tmp)
                    ans += tmp/2;
                else
                    ++ans;
            }
}
void output()
{
    cout << ans << endl;
    //system("pause");
}
int main()
{
    load();
    work();
    output();
    return 0;
}
