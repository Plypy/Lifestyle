#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("lignja.in");
    fout.open("lignja.out");
    int N, K;
    int *P;
    int *T;
    P = new int [K];
    T = new int [K];
    fin >> N >> K;
    for (int i = 0; i < K; i++)
        fin >> P[i] >> T[i];
    
    
    int *result = new int [N+1];
    for (int i = 0; i <= N; i++)
        result[i] = 0;
    int j  = K-1;
    for (int i = N-1; i >=0; i--)
    {
        if (i+1 != P[j])
            result[i] = result[i+1]+1;
        else
        {
            result[i] = result[i+T[j]];
            j--;
            while (i+1 == P[j])
            {
                if (result[i] < result[i+T[j]])
                    result[i] = result[i+T[j]];
                j--;
            }
        }
    }
    fout << result[0];
    delete[] P;
    delete[] T;
    fin.close();
    fout.close();
    return 0;
}
