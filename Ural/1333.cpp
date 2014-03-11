//思路 用概率论解，随机产生点，测试是否被覆盖即可。
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
const int MAXN = 15;
const int TIMES = 100000;
double x[MAXN], y[MAXN], r[MAXN];
int n;
bool iscovered(double tx, double ty)
{
    for (int i = 1; i <= n; ++i)
        if (sqrt(pow(tx-x[i],2)+pow(ty-y[i],2)) <= r[i])
            return true;
    return false;
}
void load()
{
    srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i] >> r[i];
}
void work()
{
    int ct = 0;
    for (int i = 1; i <= TIMES; ++i)
        if (iscovered(double(rand())/double(RAND_MAX),double(rand())/double(RAND_MAX)))
            ct++;
    cout << (double(ct*100)/double(TIMES)) << endl;
    //system("pause");
}
int main()
{
    load();
    work();
    return 0;
} 
