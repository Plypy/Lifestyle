/*Note
 *�������ʹ����λ����+bfs�����Կ���λ����ĸ�Ч�ԡ������������ÿһ���ֽ�
 *�������ǵ�һ�ν���bfs��ʵ�֣�������Щ���裬�������ж�һ�����Ƿ��Ѿ���ӵ�ʱ��
 *�������Ĵ���˷��˴���ʱ���Ժ�Ӧ��ע����һ�㣬��д������ʱ����ʹ�ó��õ�
 *�׶��ı��������������������塣
 *
 *�ٽ����㷨��������ʵҲûʲô�����Ǽ򵥵Ĺ������bfs����Ҫ����ʹ����λ���������
 *����Ч�� 
 */
#include <iostream>
#include <string.h>
using namespace std;
const int MAX = 100000;
int st[MAX];
int queue[MAX];
int sour, dest1, dest2;

void init();
void solve();

int main()
{
    init();
    solve();
    if (st[dest1]==-1&&st[dest2]==-1)
        cout << "impossible" << endl;
    else if (st[dest1]!=-1)
        cout << st[dest1];
    else
        cout << st[dest2];
}

void init()
{
    char c;
    for (int i = 0; i < 16; i++)
    {
        cin >> c;
        if (c == 'b')
            sour |= 1 << 15-i;
    }
    memset(st,0xFF,sizeof(st));
    st[sour] = 0;
    for (int i = 0; i < 16; i++)
        dest2 |= 1 << i;
}

void solve()
{
    queue[0] = 1;
    queue[1] = sour;
    for (int i = 1; i <= queue[0]; i++)
    {
        int now = queue[i];
        int tmp = 0, v;
        for (int j = 0; j < 16; j++)
        {
            v = now;
            v ^= 1 << j;
            if (j + 4 < 16)
                v ^= 1 << j+4;
            if (j - 4 >= 0)
                v ^= 1 << j-4;
            if (j % 4 != 0 && j-1 >= 0)
                v ^= 1 << j-1;
            if (j % 4 != 3 && j+1 < 16)
                v ^= 1 << j+1;
            if (st[v] == -1)
            {
                st[v] = st[now]+1;
                queue[++queue[0]] = v;
            }
        }
        if (st[dest1] != -1 || st[dest2] != -1)
        {
            break;
        }
    }
}
