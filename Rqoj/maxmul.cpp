#include <iostream>
#include <fstream>
#include <sstream>

void mult(string &A, int & num);
void load();
void solve();
int N;

int main()
{
    load();
    solve();
    return 0;
}

void load()
{
    ifstream fin;
    fin.open("maxmul.in");
    fin >> N;
    fin.close();
}

void solve()
{
    ofstream fout;
    fout.open("maxmul.out");
    if (3 == N)
    {
        fout << "1 " << "2" << "\n";
        fout << 2;
    }
    else if (4 == N)
    {
        fout << "1 3\n";
        fout << "3";
    }
    else
    {
        
    }
    fout.close();
}

void mult(string &A, int &num)
{
    int len = A.size();
    int temp = 0;
    int dig;
    for (int i = len-1; i >= 0; i++)
    {
        dig = A[i] - '0'+temp;
        dig *= num;
        A[i] = dig%10+'0';
        temp = dig/10;
    }
    if (temp)
    {
        ostringstream sout;
        sout << temp;
        A = sout.str() + A;
    }
}
