/*
 *  ��һ�⣺������ʽ 
 *  �����ļ���test.in
 *  ����ļ�: test.out 
 */
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
const int MAXN = 500;
string str;
int stack[MAXN];
int top = 0;
void error(int type)
{
    cout << "error " << type;
void work()
{
    char ch;
    while (1)
    {
        cin >> ch;
        switch (ch)
        {
            case ')':
                
            case '#':
                goto correct;
            default:
                error(1);
        }
    }
correct:
    cout << "OK" << endl;
}
int main()
{
    work();
    return 0;
}
