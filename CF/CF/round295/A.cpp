#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

inline int mult(long long a, long long b)
{
    a *= b;
    a %= MOD;
    return a;
}

int pow_mod(int base, int p)
{
    int ret = 1;
    long long tmp = base;
    for (; p; p >>= 1) {
        if (p&1) {
            ret = mult(ret, tmp);
        }
        tmp = mult(tmp, tmp);
    }
    return ret;
}
int ct[4];
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (unsigned i = 0; i < s.size(); ++i) {
        if (s[i] == 'A') {
            ++ct[0];
        } else if (s[i] == 'G') {
            ++ct[1];
        } else if (s[i] == 'T') {
            ++ct[2];
        } else {
            ++ct[3];
        }
    }
    int m = ct[0];
    int num = 1;
    for (int i = 1; i < 4; ++i) {
        if (ct[i] == m) {
            ++num;
        } else if (ct[i] > m) {
            num = 1;
            m = ct[i];
        }
    }
    cout << pow_mod(num, n) << endl;
    return 0;
}
