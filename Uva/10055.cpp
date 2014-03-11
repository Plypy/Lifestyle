#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long LL;
int main() {
    LL a, b;
    while (cin >> a >> b) {
        cout << abs(b-a) << endl;
    }
    return 0;
}
