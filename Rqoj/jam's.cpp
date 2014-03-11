//Note
//看吧 只要把思路写出来
//充分理解题目的意思
//编程就变得如此简单
//Keep going， keep fighting！
//再次感慨一下
//明年再次noip的时候
//我就是高三了
//唉，梦想啊
//必须得实现
//一切都是为了自己的诺言
//要记住一点
//信念不死
//信念不死
//这就是我比周围其他人强的一点
//我有不死的信念，不移的信仰 
#include <iostream>
using namespace std;
int s, t, w;
string list;
bool inc(string&);
int main()
{
    cin >> s >> t >> w;
    cin >> list;
    for (int i = 1; i < 5; i++)//第i位的字母必须能够使后面的字母比他大也就是说第i位的字母的数字大小 
    {                           //最多为t-(w-i+1) 
        if (inc(list))
            cout << list << endl;
    }
    if (inc(list))//这就是面向对象吧..至少这样很容易想 
        cout << list;
    return 0;
}
bool inc(string&A)
{
    bool flag = false;
    for (int i = A.size()-1; i >= 0; i--)
    {
        if (list[i]<'a'+t-w+i)
        {
            list[i]++;
            for (int j = i+1; j < A.size(); j++)
                list[j] = list[j-1]+1;
            flag = true;
            break;
        }
    }
    return flag;
}
