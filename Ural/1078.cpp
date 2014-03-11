// Note: 千万要认真读题啊，千万要注意边界情况啊 
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

class Problem {
private:
    static const int MAXN = 510;
    int n;
    struct Segment {
        int lx, rx;
        int id;
        friend bool operator<(const Segment &a, const Segment &b) {
            return a.lx < b.lx;
        }
    } seg[MAXN];
    int f[MAXN];
    int nxt[MAXN];
    inline int max(int a, int b) {
        return a>b?a:b;
    }
public:
    int run() {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            seg[i].id = i;
            cin >> seg[i].lx >> seg[i].rx;
            if (seg[i].lx > seg[i].rx)
                swap(seg[i].lx, seg[i].rx);
        }
        sort(seg+1,seg+n+1);
        for (int i = 1; i <= n; ++i)
        {
            f[i] = 1;
            for (int j = 1; j < i; ++j)
                if (seg[i].lx > seg[j].lx && seg[i].rx < seg[j].rx)
                    if (f[i] < f[j]+1) {
                        f[i] = f[j]+1;
                        nxt[i] = j;
                    }
        }
        int ans = 0, bg = 1;
        for (int i = 1; i <= n; ++i)
            if (ans < f[i]) {
                ans = f[i];
                bg = i;
            }
        cout << ans << endl;
        while (bg) {
            cout << seg[bg].id << ' ';
            bg = nxt[bg];
        }
//        system("pause");
        return 0;
    }
} prob;
int main() {
    return prob.run();
}
