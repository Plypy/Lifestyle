#include <iostream>
#include <fstream>
using namespace std;

void load();
void analyze();


int N;
struct loa
{
    int index;
    int value;
};
loa * T;
int main()
{
    load();
    analyze();
    return 0;
}

void load()
{
    ifstream fin;
    fin.open("water.in");
    fin >> N;
    T = new loa[N];
    for (int i = 0; i < N; i++)
    {
        fin >> T[i].value;
        T[i].index = i;
    }
    fin.close();
}

void analyze()
{
    ofstream fout;
    fout.open("water.out");
    int temp;
    for (int i = 0; i < N-1; i++)
        for (int j = i; j < N; j++)
            if (T[i].value > T[j].value)
            {
                temp = T[i].value;
                T[i].value = T[j].value;
                T[j].value = temp;
                temp = T[i].index;
                T[i].index = T[j].index;
                T[j].index = temp;
            }
    for (int i = 0; i < N; i++)
        fout << T[i].index+1 << " ";
    fout << endl;
    float sum = 0;
    for (int i = 0; i < N-1; i++)
        sum += (N-1-i)*T[i].value;
    fout << sum/N;
    fout.close();
}
