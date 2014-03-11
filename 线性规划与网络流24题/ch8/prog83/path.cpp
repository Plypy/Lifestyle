/* ����ת��Ϊ����ͼƥ��ģ��
 * ��Ϊ�����������ǣ�����ͼ�е�����һ������
 * ���䲻Ϊĳһ��·�����յ�Ļ�����ô��������Ȼ�г���
 * Ҳ����˵��Ȼ����һ������������������Ӧ
 * ��Ҳ����ʾ�����Ƕ���ͼ���ƥ���ģ�Ϳ�������
 * ������ĿҪ�������С·��������,�����ô������
 * ���ǵ�ÿ��·����Ȼ����һ���յ�û��ƥ����
 * Ҳ����˵ûƥ���ϵĶ������Ҳ����·����
 * ��ôҪ����С·�����ǵĻ���ֻ��Ҫ��ûƥ���ϵĶ������٣���ƥ�����༴��
 * ���𰸾��Ƕ�������ȥ���ƥ����
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
using namespace std;
ifstream fin("path.in");
ofstream fout("path.out");
const int MAXN = 150;

bool g[MAXN][MAXN];
bool used[MAXN];
int pal[MAXN];
int nxt[MAXN];
int n, m;

void load() {
    fin >> n >> m;
    while (m--) {
        int a, b;
        fin >> a >> b;
        g[a][b] = true;
    }
}
int ans;
bool find(int u) {
    for (int v = 1; v <= n; ++v)
        if (g[u][v] && !used[v]) {
            used[v] = true;
            if (!pal[v] || find(pal[v])) {
                nxt[u] = v;
                pal[v] = u;
                return true;
            }
        }
    return false;
}
void work() {
    for (int i = 1; i <= n; ++i) {
        memset(used,0,sizeof(used));
        if (find(i))
            ++ans;
    }
    ans = n-ans;
}

void output() {
    for (int i = 1; i <= n; ++i) {
        if (!pal[i]) {
            int t = i;
            while (true) {
                fout << t;
                if (!nxt[t]) {
                    fout.put('\n');
                    break;
                }
                t = nxt[t];
                fout.put(' ');
            }
        }
    }
    fout << ans << endl;
}

int main() {
    load();
    work();
    output();
    return 0;
} 
