// ������˼·��������
// ���ȿ��Կ������������ǳ������Ծ��Բ�������ͨ�ķ���
// ֱ����ɸ��Ū�����е�����Ȼ������ж�Ҳ�ǲ��е�
// �ռ�᲻���ã����Կ��ǵ���������һ����n
// ����ֽ��n=a��b֮��a��b֮���Ȼ��һ��С�ڵ���sqrt(n)
// �������ʾ���ǣ�ֻ������һ��sqrt(n)��С������
// Ȼ���ÿһ��������ʹ�����ű�ȥɸÿ����������Ϳ��Եý��� 
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

class Problem
{
private:
    static const int MAXN = 32000;
    static const int SLEN = 100010;
    bool parray[MAXN+100];
    int plist[MAXN+100];
    bool tmptable[SLEN+100];
    int t;
public:
    int run()
    {
        for (int i = 2; i < MAXN; ++i)
            if (!parray[i])
            {
                plist[++plist[0]] = i;
                for (int j = (i<<1); j < MAXN; j+=i)
                    parray[j] = true;
            }
        
        cin >> t;
        int lower, upper;
        for (int k = 1; k <= t; ++k)
        {
            cin >> lower >> upper;
            memset(tmptable,0,sizeof(tmptable));
            if (lower == 1)
                ++lower;
            for (int i = 1; i <= plist[0] && plist[i]*plist[i] <= upper; ++i)
            {
                int bg = lower/plist[i];
                int ed = upper/plist[i];
                for (int j = bg; j <= ed; ++j)
                    if (j != 1)
                        tmptable[j*plist[i]-lower] = true;
            }
            for (int i = 0; i <= upper-lower; ++i)
                if (!tmptable[i])
                    cout << i+lower << endl;
        }
//        system("pause");
        return 0;
    }
} prob;
int main()
{
    return prob.run();
}
