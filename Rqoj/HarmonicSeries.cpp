#include <iostream>
using namespace std;
int k;
double sum;
int main()
{
    cin >> k;
    int i;
    for (i = 1; sum <= k; i++)
        sum += 1/double(i);
    cout << i-1;
    return 0;
}
