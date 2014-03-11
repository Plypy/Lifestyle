#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int WIDTH = 25;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("ans.txt", "w", stdout);
    int n;
    while (true) {
        cin >> n;
        if (!n)
            break;
        int sum = 0;
        int min_b = WIDTH;
        for (int i = 1; i <= n; ++i) {
            int ct = 0;
            while ('\n' != cin.get())
                continue;
            for (int j = 1; j <= WIDTH; ++j) {
                char ch = cin.get();
                if (' ' == ch)
                    ++ct;
            }
            sum += ct;
            if (ct < min_b)
                min_b = ct;
        }
        sum -= n*min_b;
        cout << sum << endl;
    }
    return 0;
}
