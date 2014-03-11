#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main() {
    int k;
    cin >> k;
    double s = 0;
    int ans = 0;
    while (s <= k)
        s += 1.0/(++ans);
    cout << ans << endl;
//    system("pause");
    return 0;
}
