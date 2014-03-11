#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    unsigned long long a;
    double tmp;
    cout << setprecision(4) << setiosflags(ios::fixed|ios::showpoint);
    vector<double> ans;
    ans.reserve(10000);
    while (cin >> a)
        ans.push_back(sqrt(double(a)));
    for (int i = ans.size()-1; i >= 0; i--)
        cout << ans[i] << endl;
    return 0;
}
