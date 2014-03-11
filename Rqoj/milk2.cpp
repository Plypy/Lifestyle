/*
ID:jake1994
LANG:C++
PROG:milk2
*/
/*
 *Note: �����������������˷���ʱ��...����ĵ����Ҿ�Ȼ�����ݷ�Χûд��
 *      ���ٴ�˵�����������Ҫ�ԣ�������ϸ���⣡ 
 */
#include <iostream>
#include <stdio.h>
using namespace std;
const int Max = 5050;
int begin[Max];
int end[Max];
int n, tmp_bg, tmp_ed;
int ans1, ans2;
int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    cin >> n;
    int tmp;
    for (int i = 1; i <= n; i++)
        cin >> begin[i] >> end[i];
    for (int i = 1; i <= n-1; i++)
        for (int j = i+1; j <= n; j++)
            if (begin[i] > begin[j])
            {
                tmp = begin[i];
                begin[i] = begin[j];
                begin[j] = tmp;
                tmp = end[i];
                end[i] = end[j];
                end[j] = tmp;
            }
    tmp_bg=begin[1];
    tmp_ed=end[1];
    ans1=end[1]-begin[1];
    ans2=0;
    for (int i = 2; i <= n; i++)
    {
        if (begin[i] > tmp_ed)
        {
            if (ans1 < tmp_ed-tmp_bg)
                ans1 = tmp_ed-tmp_bg;
            if (ans2 < begin[i]-tmp_ed)
            {
                ans2 = begin[i]-tmp_ed;
            }
            tmp_bg = begin[i];
            tmp_ed = end[i];
        }
        else
            tmp_ed = tmp_ed>end[i]?tmp_ed:end[i];
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}
