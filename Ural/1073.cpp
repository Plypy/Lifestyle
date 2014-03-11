#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Problem {
private:
    static const int MAXN = 60010;
    static const int INF = 52111425;
    int n;
    int f[MAXN];
    inline int min(int a, int b) {
        return a<b?a:b;
    }
public:
    int run() {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            f[i] = INF;
        for (int i = 1; i*i <= n; ++i)
            for (int wt = i*i, j = wt; j <= n; ++j)
                f[j] = min(f[j],f[j-wt]+1);
        cout << f[n] << endl;
//        system("pause");
        return 0;
    }
} prob;
int main() {
    return prob.run();
}
