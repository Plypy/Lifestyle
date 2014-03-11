#include <iostream>
#include <fstream>
using namespace std;
void solve();
void load();
int M;
int N;
struct data{
    int a;
    int b;
};
data* AR;

int main()
{
    load();
    solve();
    return 0;
}

void load()
{
    ifstream fin;
    fin.open("riddle.in");
    fin >> M >> N;
    AR = new data[N];
    for (int i = 0; i < N; i++)
        fin >> AR[i].a;
    for (int i = 0; i < N; i++)
        fin >> AR[i].b;
    int temp;
    for (int i = 0; i < N-1; i++)
        for (int j = i+1; j < N; j++)
            if (AR[j].b > AR[i].b)
            {
                temp = AR[j].b;
                AR[j].b = AR[i].b;
                AR[i].b = temp;
                temp = AR[j].a;
                AR[j].a = AR[i].a;
                AR[i].a = temp;
            }
    fin.close();
}

void solve()
{
    ofstream fout;
    fout.open("riddle.out");
    bool pos[N];
    int result = M;
    for (int i = 0; i < N; i++)
        pos[i] = true;
    for (int i = 0; i < N; i++)
    {
        int j;
        for (j = AR[i].a-1; j >= 0;j--)
            if (pos[j])
            {
                pos[j] = false;
                break;
            }
        if (-1 == j)
        {
            result -= AR[i].b;
        }
    }
    fout << result;
    delete[] AR;
    fout.close();
}
