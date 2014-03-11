//考虑到n非常小
//所以使用离线的方法求解
//遍历数据两遍，第一遍求出最大值
//第二遍求出最先达到最大值的人
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstdlib>
#include <map>
using namespace std;
const int MAXN = 1005;
struct Data {
    int pt;
    string name;
} data[MAXN];
int n;
int main() {
    ios::sync_with_stdio(false);;
    cin >> n;
    map<string, int> table1;
    for (int i = 1; i <= n; ++i) {
        cin >> data[i].name >> data[i].pt;
        table1[data[i].name] += data[i].pt;
    }
    int mpt = 0;
    for (map<string,int>::iterator itr = table1.begin(); itr != table1.end(); ++itr)
        if (itr->second > mpt)
            mpt = itr->second;
    map<string, int> table2;
    for (int i = 1; i <= n; ++i) {
        int tmp = (table2[data[i].name] += data[i].pt);
        if (tmp >= mpt && table1[data[i].name] == mpt) {
            cout << data[i].name << endl;
            break;
        }
    }
    return 0;
}
