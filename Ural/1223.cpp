//Note
// ����f[i][j]Ϊ��j������i����ȷ�����ٲ�¥������
// f[0][j] = f[i][0] = 0
// f[i][j] = f[i-1][j-1]+f[i-1][j]+1
// ֻҪ�ҵ���һ��i����f[i][Eggnum] >= n ����
#include <iostream>
#include <cmath>
using namespace std;
int EggNum,N,g[21];
inline void DP()
{
    for (int i=2;i<=N;i++)
    {
        for (int j=EggNum;j>1;j--)
        {
            g[j]+=g[j-1]+1;
            if ((j == EggNum) && (g[j] >= N))
            {
                cout << i << endl;
                return;
            }
        }
        g[1]=i;
    }
}
int main()
{
    while (true)
    {
        cin >> EggNum;
        if (!EggNum)
            break;
        cin >> N;
        int tmp=(int)(floor(log((double)N)/log(2.0))+1.0);
        if (EggNum >= tmp)
            cout << tmp << endl;
        else
        {
            for (int i=1;i<=EggNum;i++)
                g[i]=1;
            if (g[EggNum] >= N)
                cout << '1' << endl;
            else if (EggNum == 1)
                cout << N << endl;
            else DP();
        }
    }
    return 0;
}
