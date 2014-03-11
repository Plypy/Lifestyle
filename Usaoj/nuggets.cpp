/*
    ID : jake1994
    PROG : nuggets
    LANG : C++
*/
// �����ܶ�ʱ��ȱ�Ľ��������İ�
// ���� ��a��b���ʣ�����ڲ�������ax+by=c������c>ab������һ���������⣨x0,y0��
// ���ǵ�������κ�һ�����ӵĴ�С��1�Ļ���ô�����С�����󶼿��Ա����㣬
// ����ֱ�����0����
// �������������к��Ӵ�С�����Լ�����ܱ���ɵ����ֱ�ȻΪ���Լ���ı���
// ����Щ���Ǳ����������޷�����ɣ�����������Լ����Ϊ1�Ļ����������޴������
// �޷�����ɣ� ���0����
// �����������޽⣬�����Ȼ��[1��256^2]�˼����ڣ�ֱ��ʹ�����ޱ���ģ�⼴�ɣ�
// ������Ա���ɵ����֣�Ȼ������Ҳ��ܱ���ɵģ������һ�����ɡ� 
#include <iostream>
#include <fstream>
using namespace std;
const int MAXN = 11;
int size[MAXN];
int n;
inline int gcd(int a, int b)
{
    int c;
    while (b)
    {
        c = a;
        a = b;
        b = c%b;
    }
    return a;
}
int main()
{
    ifstream fin("nuggets.in");
    ofstream fout("nuggets.out");
    fin >> n;
    int fac = 0;
    for (int i = 1; i <= n; i++)
    {
        fin >> size[i];
        fac = gcd(size[i],fac);
        if (size[i] == 1)
        {
            fout << 0 << endl;
            return 0;
        }
    }
    if (fac != 1)
    {
        fout << 0 << endl;
        return 0;
    }
    static bool f[65537];
    f[0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = size[i]; j <= 65536; j++)
            f[j] |= f[j-size[i]];
    for (int i = 65536; i; i--)
        if (!f[i])
        {
            fout << i << endl;
            break;
        }
    return 0;
}
