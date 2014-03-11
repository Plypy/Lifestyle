#include <iostream>
#include <fstream>
using namespace std;
int N;
int K;
void load();
void solve();

int main()
{
    load();
    solve();
    return 0;
}

void load()
{
    ifstream fin;
    fin.open("sort.in");
    fin >> N >> K;
    fin.close();
}

void solve()
{
    ofstream fout;
    fout.open("sort.out");
    int list[N+1];
    if (!N)
    {
        fout << 0;
        return;
    }
    list[N] = 1;
    list[0] = 1;
    for (int i = N-1; i >= 1; i--)
        list[i] = 2*list[i+1];
    while (K > 1)
    {
        int i;
        int j;
        i = j = 0;
        while (i <= N && K > list[i])
        {
            K--;
            list[i]--;
            i++;
        }
        if (j != 1)
            fout << ' ';
        j++;
        fout << i;
        list[i] = 1;
    }
    fout.close();
}
