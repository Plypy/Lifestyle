#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;
class Problem
{
private:
    string expr;
public:
    int run()
    {
        getline(cin,expr);
        int Eqpos = expr.find('=');
        int a = 0, b = 0, c = 0, d = 0;
        int sign = 1;
        int mem = 0;
        char unknown;
        for (int i = 0; i < Eqpos; )
        {
            sign = 1;
            mem = 0;
            if (expr[i] == '+')
                ++i;
            if (expr[i] == '-')
            {
                ++i;
                sign = -1;
            }
            while (isdigit(expr[i]))
                mem = mem*10+expr[i++]-'0';
            if (expr[i] != '+' && expr[i] != '-' && expr[i] != '=')
            {
                unknown = expr[i++];
                if (mem)
                    a += mem*sign;
                else
                    a += sign;
            }
            else
                b += mem*sign;
        }
        int len = expr.size();
        expr += '+';
        for (int i = Eqpos+1; i < len; )
        {
            sign = 1;
            mem = 0;
            if (expr[i] == '+')
                ++i;
            if (expr[i] == '-')
            {
                ++i;
                sign = -1;
            }
            while (isdigit(expr[i]))
                mem = mem*10+expr[i++]-'0';
            if (expr[i] != '+' && expr[i] != '-')
            {
                unknown = expr[i++];
                if (mem)
                    c += mem*sign;
                else
                    c += sign;
            }
            else
                d += mem*sign;
        }
        cout << fixed << setprecision(3) << unknown << '=' << double(d-b)/double(a-c) << endl;
//        system("pause");
        return 0;
    }
} prob;
int main()
{
    return prob.run();
}
/*
6a-5+1=2-2a

a=0.750
*/
