#include <iostream>
using namespace std;
const int MAX = 10010;
int n, m;
int im[MAX];
int main()
{
    cin >> n >> m;
    int ct;
    char c;
    int begin, end, time, imp;
    for (ct = 1; ct <= m; ct++)
    {
        cin >> c;
        if (c == 'N')
        {
            cin >> time >> imp;
            int i, j, k;
            for (i = 1; i <= n;)
            {
                for (j = i; im[j]<imp&&j<=i+time-1;j++)
                {
                    if (j == n)
                        break;
                    continue;
                }
                if (j == i+time)
                {
                    cout << i << endl;
                    for (k = i; k <= i+time-1; k++)
                        im[k] = imp;
                    break;
                }
                else
                    i = j+1;
            }
            if (i > n)
                cout << "wrong" << endl;
        }
        if (c == 'D')
        {
            cin >> begin >> end;
            int ret = 0;
            for (int i = begin; i <= end; i++)
            {
                if (ret < im[i])
                    ret = im[i];
                im[i] = 0;
            }
            if (ret)
                cout << ret << endl;
            else
                cout << "wrong" << endl;
        }
        if (c == 'A')
        {
            cin >> begin;
            if (im[begin])
                cout << im[begin] << endl;
            else
                cout << "wrong" << endl;
        }
    }
    return 0;
}
/*
 
提交 3 / 12 题 (25%)  首页 站务 公告 数据 评测机 | 题库 分类 记录 比赛 排名 团队 讨论 | User Space 换肤|登出    
 
   
 公告 News >> 　　New! 关于“RP上午+”的声明 (2010-11-14 11:51:53) 　　New! CoderSpace添加其他登陆方式 (2010-11-10 23:12:20) 　　欢迎参加Boolean93立冬欢乐赛 (2010-11-8 10:23:37) 　　USACO最新月赛已经全部翻译完毕，欢迎访问CoderSpace查看 (2010-11-5 20:46:57)  
   

--------------------------------------------------------------------------------
 
   
 输入数据 Input Data                                 
14
83
N 12 1036023843
N 3 1807352817
D 3 3
N 3 1489594962
N 8 1948815586
N 12 1553952368
D 1 2
N 2 1819703766
N 7 2092831732
N 4 1208289100
D 2 5
N 13 1934805974
D 1 8
N 12 1381509586
D 2 6
A 12
N 4 17061259
N 4 1385278187
N 7 427348456
A 14
N 12 96887952
N 7 561309820
N 13 1730150358
N 11 1210442114
N 13 927078762
N 7 1576715361
D 7 11
N 1 1723795873
N 13 1546714210
D 13 13
N 1 396959468
N 13 1938153034
N 3 370231271
N 2 873946120
N 8 1982470508
N 10 141564430
N 2 497663619
N 5 1014690900
A 6
N 13 530098964
N 14 1395299684
N 5 1767504015
N 13 2052027902
A 10
D 6 14
N 8 528641543
N 4 2063364443
D 3 3
N 8 1135418130
D 9 11
N 14 273409576
N 10 370127164
N 1 1952453395
N 5 201807568
N 12 1570368946
N 12 1885464150
A 3
A 10
A 3
N 3 1817703279
N 8 437861929
A 11
N 13 1122330403
A 10
N 13 626977417
N 11 2127130868
N 4 646242352
N 13 1919666125
N 14 1320256773
N 4 1444879709
N 10 1494706967
N 12 817664068
N 3 1745115277
D 10 10
N 7 1427562389
A 3
N 11 1106309885
N 11 333454177
N 12 1787665950
N 6 1109063552
N 13 1641436269
N 8 1445723275
N 10 828737851

*/
