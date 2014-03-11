#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;
int max(int a, int b) {
    return a>b?a:b;
}
typedef struct SegNode {
    static const int INF = 52111425;
    int l, r, m, s;
    
    SegNode(int val = -INF):
        l(val), r(val), m(val), s(val){ }
    friend SegNode operator+(const SegNode &lSeg, const SegNode &rSeg) {
        if (lSeg.s == -INF)
            return rSeg;
        if (rSeg.s == -INF)
            return lSeg;
        SegNode ret;
        ret.s = lSeg.s+rSeg.s;
        ret.l = max(lSeg.l, lSeg.s+rSeg.l);
        ret.r = max(rSeg.r, lSeg.r+rSeg.s);
        ret.m = max(lSeg.r+rSeg.l,max(lSeg.m,rSeg.m));
        return ret;
    }
} node;
typedef class SegTree {
private:
    node *data;
    int size;
public:
    SegTree(int len, int ar[]): size(len) {
        data = new node[(len<<1)+20];
        for (int i = 1; i <= size; ++i)
            data[i+size] = node(ar[i]);
        for (int i = size-1; i; --i)
            data[i] = data[i<<1]+data[(i<<1)+1];
    }
    ~SegTree() {
        delete[] data;
    }
    node/**/ query(int lbd, int rbd) {
        node lpart, rpart;
        for (lbd+=size-1, rbd+=size+1; lbd^rbd^1; lbd>>=1, rbd>>=1) {
            if (~lbd&1)
                lpart = lpart+data[lbd+1];
            if (rbd&1)
                rpart = data[rbd-1]+rpart;
        }
        return lpart+rpart;
    }
    void change(int pos, int nval) {
        pos += size;
        data[pos] = node(nval);
        for (pos >>= 1; pos; pos >>= 1)
            data[pos] = data[pos<<1]+data[(pos<<1)+1];
    }
} tree;
class Problem {
private:
    static const int MAXN = 500010;
    int n, m;
    int *ar;
    
    void read(int &t) {
        char ch;
        while (' ' == (ch = getchar()) || '\n' == ch)
            continue;
        int sign = 1;
        if ('-' == ch) {
            sign = -1;
            ch = getchar();
        }
        t = 0;
        do {
            t = t*10+ch-'0';
        } while (isdigit(ch=getchar()));
        t *= sign;
    }
    void writeln(int t) {
        static char buffer[20];
        char *ptr = buffer;
        if (0 == t) {
            putchar('0');
            return;
        }
        if (t < 0) {
            t = -t;
            putchar('-');
        }
        while (t) {
            *ptr++ = '0'+t%10;
            t /= 10;
        }
        do {
            putchar(*(--ptr));
        } while (ptr != buffer);
        putchar('\n');
    }
public:
    Problem() {
        read(n), read(m);
        ar = new int[n+10];
        for (int i = 1; i <= n; ++i)
            read(ar[i]);
    }
    ~Problem() {
        delete[] ar;
    }
    int run() {
        tree st(n,ar);
        int a, b, c;
        while (m--) {
            read(a), read(b), read(c);
            if (a == 1) {
                if (b > c)
                    swap(b,c);
                writeln(st.query(b,c).m);
            }
            else
                st.change(b,c);
        }
//        system("pause");
        return 0;
    }
} prob;
    
int main() {
    return prob.run();
}
/*
5 3
1
2
-3
4
5
1 2 3
2 2 -1
1 2 3


2
-1
*/
