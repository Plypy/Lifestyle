#include <iostream>
#include <fstream>
using namespace std;

int M, K;

void load();
void solve();

int main()
{
    load();
    solve();
    cout << "error!\n";
    cin.get();
    return 0;
}

void load()
{
    ifstream fin;
    fin.open("book.in");
    fin >> M >> K;
    if (!M)
        exit(0);
}

void solve()
{
    
}
