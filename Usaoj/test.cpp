/*
ID: jake1994
PROG: test
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("test.in");
    ofstream fout("test.out");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    fin.close();
    fout.close();
    return 0;
}
