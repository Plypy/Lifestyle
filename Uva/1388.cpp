#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double len = 10000;
int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(5);
    int n ,m;
    while (cin >> n >> m) {
        double ans = 0;
        for (int i = 1; i < n; ++i) {
            double pos = double(i)/n*(n+m);
            ans += abs(pos-floor(pos+0.5));
        }
        cout << len*ans/(n+m) << endl;
    }
    return 0;
}
