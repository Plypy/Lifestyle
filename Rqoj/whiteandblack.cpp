/*Note
 *这道题我使用了位运算+bfs，可以看到位运算的高效性～～充分利用了每一个字节
 *但由于是第一次进行bfs的实现，还是有些生疏，并且在判断一个点是否已经入队的时候
 *犯了马虎的大错，浪费了大量时间以后应该注意这一点，在写变量的时候尽量使用常用的
 *易懂的变量名，并理解变量的意义。
 *
 *再进行算法分析，其实也没什么，就是简单的广度优先bfs，主要这里使用了位运算提高了
 *运算效率 
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
