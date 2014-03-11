// �����и���ʵ��O(n^3����- -
// ��18����͸�TLE��
// �� Ϊʲôͬ�����㷨pascal�ľ͸�����...
// ԭ�����˼ҵĵݹ��㷨�ٴ�����һ������������
// �ҵĸ��˺󣬼����ڵĴ��뿨��ʱҲ����- -���������Ż�һ�¶����ܸ���һЩ��
// ����˵�ĳɷǵݹ�ģ�
// ����˵����������ܿ���һ���ǳ���Ҫ�ĵ����ݹ���Ȼ���㵫�����Ĵ����Ƿǳ���ġ� 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int MAXC = 2500;
struct Rect {
    int llx, lly;
    int urx, ury;
    int color;
} rect[MAXN];
int area[MAXC+1];
int n;

void load() {
    scanf("%d%d%d", &rect[0].urx, &rect[0].ury, &n);
    rect[0].color = 1;
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d%d%d", &rect[i].llx, &rect[i].lly, &rect[i].urx, &rect[i].ury, &rect[i].color);
}

int cur_col;
void cover(int h, int llx, int lly, int urx, int ury) {
    while (h <= n && (llx >= rect[h].urx || urx <= rect[h].llx || lly >= rect[h].ury || ury <= rect[h].lly) )
        ++h;
    if (h > n) {
        area[cur_col] += (urx-llx)*(ury-lly);
        return ;
    }
    if (llx < rect[h].llx) {
        cover(h+1,llx,lly,rect[h].llx,ury);
        llx = rect[h].llx;
    }
    if (urx > rect[h].urx) {
        cover(h+1,rect[h].urx,lly,urx,ury);
        urx = rect[h].urx;
    }
    if (lly < rect[h].lly)
        cover(h+1,llx,lly,urx,rect[h].lly);
    if (ury > rect[h].ury)
        cover(h+1,llx,rect[h].ury,urx,ury);
}

void work() {
    for (int i = 0; i <= n; ++i) {
        cur_col = rect[i].color;
        cover(i+1,rect[i].llx,rect[i].lly,rect[i].urx,rect[i].ury);
    }
    for (int i = 1; i <= MAXC; ++i) 
        if (area[i])
			printf("%d %d\n", i, area[i]);
            //cout << i << ' ' << area[i] << endl;
//    system("pause");
}
int main() {
    load();
    work();
    return 0;
}
