#include <iostream>
using namespace std;

void solve()
{
int N;
int *AR;
cin >> N;
AR = new int[N];
for (int i = 0; i < N; i++)
     cin >> AR[i];
static int T[1001];
int P[100];
int count = 0;
for (int i = 0; i < N; i++)
     T[AR[i]]++;
int j = 0;
for (int i = 1; i < 1001; i++)
{
if (T[i])
{
P[j++] = i;
count++;
}}
cout << count << endl;
for (int i = 0; i < count; i++)
cout << P[i] << ' ';
}
int main()
{
solve();
cin.get();
cin.get();
return 0;
}
