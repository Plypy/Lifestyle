// 脑残啊...不写return 
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 5010;
struct School{
    string name;
    string mark;
    friend bool operator<(const School &a, const School &b) {
        if (a.mark.size() != b.mark.size())
            return a.mark.size() > b.mark.size();
        if (a.mark != b.mark)
            return a.mark > b.mark;
        return a.name < b.name;
    }
} scl[MAXN];
int n;
int main() {
    cin >> n;
    cin.get();
    for (int i = 1; i <= n; ++i) {
        string tmp;
        getline(cin,scl[i].name);
        getline(cin,tmp);
        int len = tmp.size();
        int j;
        for (j = 0; tmp[j] == '0' && j < len; ++j)
            continue;
        if (j == len)
            scl[i].mark = "0";
        else
            scl[i].mark = tmp.substr(j);
        //cout << scl[i].mark << endl;
    }
    sort(scl+1,scl+n+1);
    for (int i = 1; i <= n; ++i)
        cout << scl[i].name << endl;
//    system("pause");
    return 0;
}
/*
测试结果错误.错误结果为:abcdefg
dgeasdc
dwetqte
fytryre
xdhyuie
正确结果应为:abcdefg
dgeasdc
fytryre
dwetqte
xdhyuie
*/
