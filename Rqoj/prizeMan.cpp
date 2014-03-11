//俺的代码...
//完全遵从大师教导
//让整个程序尽量不存在魔数...
//尽可能的分离实现与接口
//嗷哈哈哈... 
#include <iostream>
using namespace std;
const int Academic = 8000;
const int FiveFour = 4000; // - -
const int Remarkable = 2000;
const int WestCowboy = 1000;
const int ClassOffer = 850;
string name;
int prize;
int n, total;
void check()
{
    string tmp;
    int classmark;
    int finalmark;
    int papernum;
    bool isleader = false;
    bool iswest = false;
    char flag;
    cin >> tmp >> finalmark >> classmark;
    cin >> flag;
    if (flag == 'Y')
        isleader = true;
    cin >> flag;
    if (flag == 'Y')
        iswest = true;
    cin >> papernum;
    int get = 0;
    if (finalmark > 80 && papernum)
        get += Academic;
    if (finalmark > 85 && classmark > 80)
        get += FiveFour;
    if (finalmark > 90)
        get += Remarkable;
    if (iswest && finalmark > 85)
        get += WestCowboy;
    if (isleader && classmark > 80)
        get += ClassOffer;
    if (get > prize)
    {
        name = tmp;
        prize = get;
    }
    total += get;
}
void putanswer()
{
    cout << name << endl;
    cout << prize << endl;
    cout << total;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        check();
    putanswer();
    return 0;
}
