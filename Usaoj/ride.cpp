/*
ID: jake1994
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    string comet;
    string group;
    int com = 1;
    int gro = 1;
    fin >> comet >> group;
    for (int i = 0; i < comet.size(); i++)
        com *= comet[i]-'A'+1;
    for (int i = 0; i < group.size(); i++)
        gro *= group[i]-'A'+1;
    if (com%47 == gro%47)
        fout << "GO";
    else
        fout << "STAY";
    fout << endl;
    return 0;
}
