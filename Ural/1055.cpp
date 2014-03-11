// 写在前面，能把赋值语句放在循环外面就放在循环外面 
//高效算法 依赖于事实 
//质因数K在1~N中出现在次数为
//F(N)=sigma(n div (k^i) )
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int MAXN = 50001;
bool notp[MAXN];
inline int get(int bound, int div) {
    int ret = 0;
    for (int t = div; t <= bound;  t*=div)
        ret += bound/t;
    return ret;
}
int main() {
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 2; i <= n; ++i)
        if (!notp[i]) {
            int t = get(n,i)-get(n-m,i)-get(m,i);
            if (t)
                ++ans;
            for (int j = i*2; j <= n; j += i)
                notp[j] = true;
        }
    cout << ans << endl;
//    system("pause");
    return 0;
} 

// 普通算法 挨个分解质因数 
/*
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAXN = 50001;
int plis[MAXN];
bool notp[MAXN];
void init(int bound) {
    for (int i = 2; i <= bound; ++i)
        if (!notp[i]) {
            plis[++plis[0]] = i;
            for (int j = i*2; j <= bound; j += i)
                notp[j] = true;
        }
}
int ct[MAXN];
int main() {
    int n, m;
    cin >> n >> m;
    if (n < m) {
        cout << 0 << endl;
        return 0;
    }
    init(n);
    if ((n>>1) < m)
        m = n-m;
    for (int i = n-m+1; i <= n; ++i) {
        int s = i;
        for (int j = 1; j <= plis[0]; ++j) {
            while (0 == s%plis[j]) {
                s /= plis[j];
                ++ct[j];
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        int s = i;
        for (int j = 1; j <= plis[0]; ++j) {
            while (0 == s%plis[j]) {
                s /= plis[j];
                --ct[j];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= plis[0]; ++i)
        if (ct[i])
            ++ans;
    cout << ans << endl;
    return 0;
}
*/
