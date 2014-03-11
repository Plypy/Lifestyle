/**
 * Description:
 * Source:
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

const int MAXL  = 100;
const int UNITL = 4;//每一位的长度
const int BASE  = pow(10,UNITL);//进制

struct Bigint {
    int ar[MAXL];
    int len;
    void init() {//初始化为0
        memset(ar,0,sizeof(ar));
        len = 0;
    }
    Bigint() {
        init();
    }
    bool scan() {//读入
        init();//初始化
        char tmp[MAXL*UNITL];//用一个字符串存储数字
        if (scanf("%s", tmp) != 1)
            return false;
        char *bg = tmp;
        while (*bg && '0' == *bg) //处理前导零
            ++bg;
        if (!(*bg)) {//特判0
            return true;
        }
        int tlen = strlen(bg);//计算长度
        for (int i = tlen-UNITL, flag = 1; flag; i -= 4) { //一段一段写入
            if (i <= 0) {//判断是否结束
                i = 0;
                flag = 0;
            }
            sscanf(bg+i, "%d", &ar[len++]);
            bg[i] = 0;  //修改当前段头为0，使得其成为字符串结束标志
        }
        return true;
    }
    void print() {//写出
        if (0 == len) {
            putchar('0');
            return;
        }
        printf("%d", ar[len-1]);//首位直接输出
        for (int i = len-2; i >= 0; --i) {
            printf("%0*d",UNITL,ar[i]);//其余位需要输出前导零
        }
    }
};

Bigint operator+(const Bigint &a, const Bigint &b) {//加法
    Bigint ret;
    ret.len = max(a.len, b.len);//计算结果长度
    for (int i = 0; i < ret.len; ++i) {
        ret.ar[i] += a.ar[i]+b.ar[i];
        if (ret.ar[i] >= BASE) {//进位
            ret.ar[i] -= BASE;
            ++ret.ar[i+1];
        }
    }
    if (ret.ar[ret.len]) {//判断最高位
        ++ret.len;
    }
    return ret;
}

Bigint operator*(const Bigint &a, const Bigint &b) {//乘法
    Bigint ret;
    if (0 == a.len || 0 == b.len) //特判乘数为0
        return ret;
    ret.len = a.len+b.len-1;
    for (int i = 0; i < a.len; ++i)
        for (int j = 0; j < b.len; ++j) {
            int k = i+j;
            ret.ar[k] += a.ar[i]*b.ar[j];
            ret.ar[k+1] += ret.ar[k]/BASE;//进位
            ret.ar[k] %= BASE;
        }
    if (ret.ar[ret.len])//处理最高位
        ++ret.len;
    return ret;
}

int main() {
    Bigint a, b;
    while (a.scan() && b.scan()) {
        a.print(); cout << ' '; b.print(); cout << endl;
        (a+b).print();
        puts("");
        (a*b).print();
        puts("");
    }
}