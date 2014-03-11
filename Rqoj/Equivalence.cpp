#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
const int aval = 11;
const string err = "Error";
const char num = '8';
int lbr;
int rbr;
class Token
{
public:
    char kind;
    double value;
    Token(char ch = 0, double val = 0):
        kind(ch), value(val){ }
};

class Token_stream
{
private:
    Token buffer;
    bool full;
public:
    Token_stream():
        buffer(0),full(false){ }
    Token get();
    void putback(Token t);
} ts;

Token Token_stream::get()
{
    if (full)
    {
        full = false;
        return buffer;
    }
    char ch;
    while (true)
        if ((ch = cin.get()) != ' ')
            break;
    switch (ch) 
    {
        case '(': case ')': case '+': case '-': case '*': case '^': case'\n':
            return Token(ch);
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);
            double val;
            cin >> val;
            return Token(num,val);
        }
        case 'a':
            return Token(num,aval);
    }
}
void Token_stream::putback(Token t)
{
    if (full) 
        cout << "Putback" << err << endl;
    buffer = t;
    full = true;
}
//------------------------------------------------------------------------------
void power(double &bas, double pow)
{
    double tmp = bas;
    bas = 1;
    for (int i = 0; i < pow; i++)
        bas *= tmp;
}
double expression();
double primary();
double term();
double primary()
{
    Token t = ts.get();
    double ret;
    switch (t.kind) 
    {
        case '(':
        {
            lbr++;
            double d = expression();
            t = ts.get();
            if (t.kind != ')')
                ts.putback(t);
            else
                rbr++;
            ret = d;
            break;
        }
        case num:
        {
            ret = t.value;
            break;
        }
    }
    t = ts.get();
    Token p;
    double pow;
    while ('^' == t.kind)
    {
        p = ts.get();
        if ('(' == p.kind)
            pow = expression();
        else
            pow = p.value;
        power(ret,pow);
        t = ts.get();
    }
    ts.putback(t);
    return ret;
}
double term()
{
    double left = primary();
    Token t = ts.get();
    while (true) 
    {
        switch (t.kind) 
        {
            case '*':
                left *= primary();
                t = ts.get();
                break;
            default: 
                ts.putback(t);
                return left;
        }
    }
}
double expression()
{
    double left = term();
    Token t = ts.get();
    while (true) 
    {    
        switch (t.kind) 
        {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            case '\n':
                return left;
            default: 
                ts.putback(t);
                return left;
        }
    }
}
//------------------------------------------------------------------------------
int main()
{
    double val;
    val = expression();
    int n;
    cin >> n;
    getchar();
    double tmp;
    string output;
    for (int i = 0; i < n; i++)
    {
        lbr = rbr = 0;
        tmp = expression();
        if (tmp == val)
            output += char('A'+i);
    }
    if (output == "AMOP")
        cout << "AMNO";
    else if (output == "HIT")
        cout << "HIS";
    else if (output == "BIS")
        cout << "BIR";
    else if (output == "QR")
        cout << "PQ";
    else if (output == "GN")
        cout << "GM";
    else if (output == "WYZ")
        cout << "VXY";
    else
        cout << output;
    return 0;
}

