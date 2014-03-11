#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
const int MAXN = 10005;
int c[MAXN];
int n;
inline int lowbit(int a) {
    return a&-a;
}
void ins(int k) {
    while (k <= n) {
        ++c[k];
        k += lowbit(k);
    }
}
void del(int k) {
    while (k <= n) {
        --c[k];
        k += lowbit(k);
    }
}
int find(int k) {
    int ret = 0;
    for (int p = (1<<int(log2(MAXN))); p; p >>= 1)
        if (ret+p < n && c[ret+p]<k)
            k -= c[ret+=p];
    return ret+1;
}
int get(int r) {
    int ret = 0;
    for (; r; r -= lowbit(r))
        ret += c[r];
    return ret;
}
void disp() {
    for (int i = 1; i <= n; ++i)
        cout << c[i] << ' ';
    cout << endl;
}
int main() {
    string type;
    int t;
    cin >> n;
    while (cin >> type) {
        if (type == "ins") {
            cin >> t;
            ins(t);
        } else if (type == "del") {
            cin >> t;
            del(t);
        } else if (type == "get") {
            int a, b;
            cin >> a >> b;
            cout << get(b)-get(a-1) << endl;
        } else if (type == "disp") {
            disp();
        } else if (type == "find") {
            cin >> t;
            cout << find(t) << endl;
        }
    }
    return 0;
}
