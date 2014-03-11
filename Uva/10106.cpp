#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

class BigNum {
private:
    static const int MAXLEN = 220;
    static const int BASE = 10000;
    static const int ULEN = 4;
    int dig;
    int ar[MAXLEN];
public:
    BigNum() {
        dig = 1;
        memset(ar,0,sizeof(ar));
    }
    friend ostream& operator<<(ostream &os, const BigNum &t) {
        os << t.ar[t.dig-1];
        for (int i = t.dig-2; i >= 0; --i) {
            if (t.ar[i] < 1000)
                os << 0;
            if (t.ar[i] < 100)
                os << 0;
            if (t.ar[i] < 10)
                os << 0;
            os << t.ar[i];
        }
        return os;
    }
    friend istream& operator>>(istream &is, BigNum &t) {
        string tmp;
        cin >> tmp;
        int len = tmp.size();
        t.dig = 0;
        memset(t.ar,0,sizeof(t.ar));
        for (int i = 1, mult = 1; i <= len; ++i) {
            t.ar[t.dig] += (tmp[len-i]-'0')*mult;
            mult *= 10;
            if (0 == i%4) {
                ++t.dig;
                mult = 1;
            }
        }
        if (!t.dig)
            ++t.dig;
        if (t.ar[t.dig])
            ++t.dig;
        return is;
    }
    void operator+=(const BigNum &t) {
        dig = max(dig,t.dig);
        for (int i = 0; i < dig; ++i) {
            ar[i] += t.ar[i];
            if (ar[i] >= BASE) {
                ++ar[i+1];
                ar[i] -= BASE;
            }
        }
        if (ar[dig])
            ++dig;
    }
    void operator*=(const BigNum &t) {
        if (1 == dig && 0 == ar[0])
            return ;
        if (1 == t.dig && 0 == t.ar[0]) {
            dig = 1;
            memset(ar,0,sizeof(ar));
        }
        int buf[MAXLEN] = {0};
        for (int i = 0; i < dig; ++i)
            for (int j = 0; j < t.dig; ++j) {
                buf[i+j] += ar[i]*t.ar[j];
                buf[i+j+1] += buf[i+j]/BASE;
                buf[i+j] %= BASE;
            }
        int mlen = dig+t.dig-1;
        for (int i = 0; i < mlen; ++i)
            ar[i] = buf[i];
        dig = mlen;
        if (buf[mlen])
            ar[dig++] = buf[mlen];
    }
};

int main() {
    BigNum a, b;
    while (cin >> a >> b) {
        a *= b;
        cout << a << endl;
    }
    return 0;
}
