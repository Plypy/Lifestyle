/* 这道题可以使用树形数据结构去做
 * 即建一棵树即可
 * 不过考虑到要按照字典序输出
 * 可以在建树之前把所有的地址排一遍序
 * 再依次插入到树中
 * 不过也可以不建树，直接做
 */ 

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN = 505;
string data[MAXN];
int n;

void load() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
        int len = data[i].size();
        for (int j = 0; j < len; ++j)
            if (data[i][j] == '\\')// 保证排序正确 
                data[i][j] = 0;
    }
}

int num = 0;
void output(int depth, string pre) {
    while (data[num].find(pre) == 0 && num < n) {
//        cout << num << ' ' << pre << endl;
        
        for (int i = 0; i < depth; ++i)
            cout << ' ';
        
        int dlen = data[num].size();
        string app = "";
        int i;
        for (i = pre.size(); i <= dlen; ++i) {
            if (data[num][i] == 0 || i == dlen) {
                if (i == dlen)
                    ++num;
                cout << app << endl;
                output(depth+1,pre+app+char(0));
                break;
            } else {
                app += data[num][i];
            }
        }
    }
}
void work() {
    sort(data,data+n);
//    for (int i = 0; i < n; ++i)
//        cout << data[i] << endl;
//    cout << endl;
    
    output(0, string(""));
}

int main() {
    load();
    work();
//    system("pause");
    return 0;
} 
