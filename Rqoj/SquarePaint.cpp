// Apio 2011 第一题 方格染色
// 异或 以及 并查集的应用 
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

class Problem {
private:
    static const int MAXN = 1000010;
    static const int MODNUM = 1000000000;
    int n, m, k;
    struct Square {
        int row, col;
        bool color;
        Square(int _row = 0, int _col = 0, bool _color = 0):
            row(_row), col(_col), color(_color){ }
    } painted[MAXN];
    int father[MAXN<<1];
    bool dif[MAXN<<1];
    bool TopLeft;
    int SetNum;
    bool flag;
public:
    int get(int element, bool &tdif) {
        if (father[element] <= 0) {
            tdif = false;
            return element;
        }
        father[element] = get(father[element],tdif);
        dif[element] ^= tdif;
        tdif = dif[element];
        return father[element];
    }
    
    bool merge(int ele1, int ele2, bool tdif) {
        bool dif1, dif2;
        ele1 = get(ele1, dif1);
        ele2 = get(ele2, dif2);
        if (ele1 == ele2) {
            return tdif == (dif1^dif2);
        }
        if (father[ele1] >= father[ele2]) {
            if (father[ele1] == father[ele2])
                --father[ele2];
            dif[ele1] = (tdif^dif1^dif2);
            father[ele1] = ele2;
        } else {
            dif[ele2] = (tdif^dif1^dif2);
            father[ele2] = ele1;
        }
        --SetNum;
        return true;
    }
    
    void load() {
        scanf("%d %d %d", &n, &m, &k);
        merge(n+m,n+m+1,true);
        SetNum = n+m-1;
        int a, b, c;
        TopLeft = false;
        for (int i = 1; i <= k; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            painted[i] = Square(a,b,c);
            if (1 == a && 1 == b && 1 == c)
                TopLeft = true;
        }
        flag = true;
    }
    
    void work() {
        for (int i = 1; i <= k; ++i) {
            int trow, tcol;
            bool tcolor;
            trow = painted[i].row;
            tcol = painted[i].col;
            tcolor = painted[i].color;
            if (1 == trow) {
                if (!merge(tcol, n+m+(tcolor^TopLeft), false)) {
                    flag = false;
                    break;
                }
            } else if (1 == tcol) {
                if (!merge(m+trow-1, n+m+(tcolor^TopLeft), false)) {
                    flag = false;
                    break;
                }
                
            } else {
                bool tmp = (!(trow&1))&&(!(tcol&1));
                if (!merge(tcol, m+trow-1, tmp^tcolor^TopLeft)) {
                    flag = false;
                    break;
                }
            }  
        }
    }
    
    int power2(int power) {
        typedef unsigned long long ull;
        ull bas = 2;
        ull ans = 1;
        while (power) {
            if (power&1)
                ans = (ans*bas)%MODNUM;
            bas = (bas*bas)%MODNUM;
            power >>= 1;
        }
        return ans;
    }
    
    void output() {
        if (flag)
            printf("%d\n", power2(SetNum));
        else
            printf("0\n");
//        system("pause");
    }
    
    int run() {
        load();
        work();
        output();
        return 0;
    }
} prob;

int main() {
    return prob.run();
}
