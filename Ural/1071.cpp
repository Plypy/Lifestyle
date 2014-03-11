// Note:
// ˼·�������Σ�
// ��С����ö��N���ƣ�Ȼ������ڴ˽�������Ӧ��x��yȻ�������LCS
// (Longest Common Sequence�����������), �������y�ĳ�����ô�Ϳ���
// һֱö�ٵ�y���ƣ�����ò�Ʒ�Χ̫���ˡ�
// �������˵ò�ƿ���...
// Ȼ���ж����������˵ʹ��LCS����̫���ˣ�Ӧ�ô�����ѡȡһ��y[i]Ȼ��
// ����x��Ѱ�������������еľͿ����ˡ�
#include <iostream>
using namespace std;
const int LEN = 30;
int alist[LEN], blist[LEN];
int alen,       blen;
int x, y;
void tran(int pat, int bas, int ar[], int &arsize)
{
    arsize = 0;
    while (pat)
    {
        ar[++arsize] = pat%bas;
        pat /= bas;
    }
}
int main()
{
    cin >> x >> y;
    if (y > x)
    {
        cout << "No solution" << endl;
        return 0;
    }
    for (int bas = 2; bas <= x; ++bas)
    {
        tran(x,bas,alist,alen);
        tran(y,bas,blist,blen);
        int i,j = 1;
        for (i = 1; i <= blen; ++i)
        {
            for (;j <= alen && alist[j] != blist[i]; ++j)
                continue;
            if (j > alen)
                break;
            ++j;
        }
        if (i == blen+1)
        {
            cout << bas << endl;
            return 0;
        }
        
    }
    cout << "No solution" << endl;
    return 0;
} 
