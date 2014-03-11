// ����ֻ��Ҫʹ��һ���ܹ����ر�ĳ��Ԫ��С��Ԫ�صĸ��������ݽṹ�Ϳ����� 
// ��ѡ������״��������ϰ
// Note:  ��״���������ڶ���ѣ���һ���ݹ鶨��Ľṹ�����ʺ���� 
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Problem
{
private:
    static const int MAXN = 10001;
    int n, k;
    class Tarray
    {
    private:
        int ar[MAXN<<1];
        int size;
        int lowbit(int t)//���������ȡ���һ��1��λ�����㷨 
        {
            return t&-t;
        }
    public:
        void init()
        {
            memset(ar,0,sizeof(ar));
        }
        Tarray(int _size): size(_size)
        {
            init();
        }
        void insert(int a)
        {
            while (a <= size)
            {
                ++ar[a];
                a += lowbit(a);
            }
        }
        int sum(int ed)
        {
            int ret = 0;
            while (ed > 0)
            {
                ret += ar[ed];
                ed -= lowbit(ed);
            }
            return ret;
        }
    };
public:
    int run()
    {
        cin >> n >> k;
        Tarray tree(n);
        int ans = 0;
        int maxmove = -1;
        int tmove;
        int num;
        for (int i = 1; i <= k; ++i)
        {
            tree.init();
            tmove = 0;
            for (int j = 1; j <= n; ++j)
            {
                cin >> num;
                num = n-num+1;
                tmove += tree.sum(num);
                tree.insert(num);
            }
            if (tmove > maxmove)
            {
                maxmove = tmove;
                ans = i;
            }
        }
        cout << ans << endl;
        return 0;
    }
} prob;
int main()
{
    return prob.run();
}
