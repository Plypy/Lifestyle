#include <iostream>
#include <map>
using namespace std;
const int BLOCKS = 3;
int main() {
    map<int,int> table;
    int ans = 0;
    for (int i = 1; i <= BLOCKS; ++i) {
        int n;
        cin >> n;
        for (int j = 1; j <= n; ++j) {
            int t;
            cin >> t;
            if (BLOCKS == ++table[t])
                ++ans;
        }
    }
    cout << ans << endl;
//    system("pause");
    return 0;
}
