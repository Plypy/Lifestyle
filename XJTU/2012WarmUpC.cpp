//±©Á¦¾ÍºÃ- -
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
const int INF = 19940306;
int main() {
    int n;
    cin >> n;
    int bd = int(sqrt(n));
    int mins = INF;
    int ans1 = 0, ans2 = 0, ans3 = 0;
    for (int a = 1; a <= bd; ++a)
        for (int b = 1; b <= a; ++b)
            if (0 == n%(a*b)) {
                int c = n/(a*b);
                int tmp = a*b+b*c+a*c;
                if (tmp < mins) {
                    mins = tmp;
                    ans1 = a, ans2 = b, ans3 = c;
                }
            }
    cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
    return 0;
}
