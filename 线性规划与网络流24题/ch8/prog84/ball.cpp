/*
 * �����Ƚ����룬���Ⱥ��Ѱ��������ת����ĳ�����е�ģ��
 * ��������ע�⵽���������ת���ɸ���n�������������ĿҪ��������������Ļ� 
 * ��ô�Ϳ��Խ�������ת���������޻�ͼ�е���С·������������
 * ��ô����Ҫ���ľ���ö����ĸ���n��ֱ���������������������Ŀ�и�����
 * ��ôn-1���Ǵ�
 * ���Ǻ���Ȼ�ģ��������Ĺ����£���Ȼ�ܹ�ʹ���ڸ����������Ϸ���������
 * ��ʵ������е����ԣ������ö��ִ𰸵ķ���ȥ�������������Ļ�ÿ������ʱ��
 * ����Ҫ���½�ͼ�����Ƿǳ�������ģ����Զ�����һ����˵���ô�С����ö�ٴ𰸵�
 * ����Ҫ���ţ���Ϊ�����Ļ���������֮ǰ����Ľ��ˣ����������Ļ��Ͳ���ʹ��
 * Hopcroft_Karp�㷨�ˣ���sap�Ļ���Ҳ�벻������ôд,��Ϊ�����жϲ�ʲô��
 * �����ڶ�̬��Ӷ����ʱ�򣬾����Ż�ʧЧ 
 * ���Ա����ʹ��Dinic���ֿ�����������ŵ��㷨��������������۲���...
 * ��ʵӦ�ú�sapһ����ֻ�����޸ľ����ŵĹ���ר���ÿ��������� 
 *
 * ��������⻹��Ҫ��������������������һ��ƥ��������Ǹոպó��������
 * ����Ϊ�������ķ������������½�ͼ������һ�� 
 *
 * ����ʹ��Hopcroft_Karp�㷨�Ӷ��ִ�
 * ˭���Լ���ˮ����... 
 * ��ʵ֤���������ᱯ�糬ʱ
 * ��Ϊ��������û�����õ��������������
 * Dinic����������һ�ļ���ʵ�� 
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
                
