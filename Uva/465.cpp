//操 这道题竟然有前导0...郁闷 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <string>
#include <sstream>
using namespace std;

class BigNum {
private:
    static const int MAXLEN = 10000;
    static const int BASE = 10000;
    static const int ULEN = 4;
    int dig;
    int ar[MAXLEN];
public:
    BigNum() {
        dig = 1;
        memset(ar,0,sizeof(ar));
    }
    explicit BigNum(int t) {
        dig = 0;
        memset(ar,0,sizeof(ar));
        while (t) {
            ar[dig++] = t%BASE;
            t /= BASE;
        }
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
        string buf;
        is >> buf;
        int bg = 0;
        while (bg < buf.size() && '0' == buf[bg++])
            continue;
        --bg;
        string tmp = buf.substr(bg);
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
    bool operator>(const BigNum &t) const {
        if (dig != t.dig)
            return dig>t.dig;
        for (int i = dig-1; i >= 0; --i)
            if (ar[i] != t.ar[i])
                return ar[i] > t.ar[i];
        return false;
    }
    bool operator<(const BigNum &t) const {
        return t>*this;
    }
};

int main() {
    const BigNum MAX(INT_MAX);
    BigNum a, b;
    string opr;
    string buf;
    while (getline(cin,buf)) {
        cout << buf << endl;
        istringstream iss(buf);
        iss >> a >> opr >> b;
        if (a > MAX)
            cout << "first number too big" << endl;
        if (b > MAX)
            cout << "second number too big" << endl;
        if ("*" == opr)
            a *= b;
        else
            a += b;
        if (a > MAX)
            cout << "result too big" << endl;
    }
    return 0;
}
