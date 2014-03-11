/*
 * 这道题比较难想，首先很难把这个问题转化成某个已有的模型
 * 不过我们注意到如果把问题转化成给定n个球，求出满足题目要求的最少柱子数的话 
 * 那么就可以将该问题转化成有向无环图中的最小路径覆盖问题了
 * 那么我们要做的就是枚举球的个数n，直到所求出的柱子数大于题目中给出的
 * 那么n-1就是答案
 * 这是很显然的，在这样的过程下，必然能够使得在给定的柱子上放置最多的球
 * 其实这题具有单调性，可以用二分答案的方法去做，不过这样的话每次求解的时候
 * 都需要重新建图，这是非常不划算的，所以对于这一题来说采用从小到大枚举答案的
 * 方法要更优，因为这样的话就能利用之前求出的解了，但是这样的话就不能使用
 * Hopcroft_Karp算法了，用sap的话我也想不出来怎么写,因为可能有断层什么的
 * 这样在动态添加顶点的时候，距离标号会失效 
 * 所以必须得使用Dinic这种靠计算求距离标号的算法，不过悲剧的是咱不会...
 * 其实应该和sap一样，只不过修改距离标号的工作专门用宽搜来做了 
 *
 * 不过这道题还需要输出方案，由于我们最后一次匹配求出的是刚刚好超出的情况
 * 所以为了求出解的方案，必须重新建图后再求一次 
 *
 * 我先使用Hopcroft_Karp算法加二分答案
 * 谁让自己是水货呢... 
 * 事实证明，这样会悲剧超时
 * 因为这样做并没有利用到问题的特殊性质
 * Dinic的做法在另一文件中实现 
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("ball.in");
ofstream fout("ball.out");
const int MAXV = 2000;
bool g[MAXV][MAXV];
int pal[MAXV];
int nxt[MAXV];
bool used[MAXV];
int n;

void load() {
    fin >> n;
}

int ans;

bool find(int u) {
    for (int v = 1; v <= ans; ++v) {
        if (g[u][v] && !used[v]) {
            used[v] = true;
            if (!pal[v] || find(pal[v])) {
                pal[v] = u;
                nxt[u] = v;
                return true;
            }
        }
    }
    return false;
}
inline bool check(int a) {
    int t = int(sqrt(double(a)));
    if (t*t == a)
        return true;
    return false;
}
int nmatch;
inline void HK() {
    memset(g,0,sizeof(g));
    for (int i = 1; i < ans; ++i)
        for (int j = i+1; j <= ans; ++j)
            if (check(i+j)) {
                g[i][j] = true;
            }
    memset(pal,0,sizeof(pal));
    memset(nxt,0,sizeof(nxt));
    nmatch = 0;
    for (int i = 1; i <= ans; ++i) {
        memset(used,0,sizeof(used));
        if (find(i))
            ++nmatch;
    }
}

void work() {
    int bg = 1, ed = 1600;
    while (bg <= ed) {
        ans = (bg+ed)>>1;
        HK();
//        cout << bg << ' ' << ans << ' ' << ed << endl;
//        cout << nmatch << endl;
//        system("pause");
        if (ans-nmatch <= n)
            bg = ans+1;
        else
            ed = ans-1;
    }
    ans = ed;
    HK();
}

void output() {
    fout << ans << endl;
    for (int i = 1; i <= ans; ++i)
        if (!pal[i]) {
            bool flag = true;
            int t = i;
            while (true) {
                if (flag)
                    flag = false;
                else
                    fout << ' ';
                fout << t;
                if (!nxt[t])
                    break;
                t = nxt[t];
            }
            fout << endl;
        }
}

int main() {
    load();
    work();
    output();
    return 0;
}
                
