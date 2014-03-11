// 要训练自己静态查错的能力！！！
// 不仅仅是写出来这么简单，还要写对 
#include <iostream>
#include <cstdlib>
#include <list>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;
list<char> que;
queue<char> buf;
int main() {
    string tmp;
    cin >> tmp;
    for (int i = 0; i < tmp.size(); ++i)
        que.push_back(tmp[i]);
    int s;
    cin >> s;
    ostream_iterator<char> ou(cout);
    copy(que.begin(),que.end(),ou);
    if (que.size() != 1)
        cout << endl;
    while (s--) {
        char ch;
        cin >> ch;
        list<char>::iterator itr = que.begin(), itr1;
        int ct = 1;
        while (*itr != ch) {
            ++ct;
            ++itr;
        }
        int len = que.size();
        if (ct <= len+1-ct) {
            ++itr;
            for (itr1 = que.begin(); itr1 != itr; ++itr1)
                buf.push(*itr1);
            que.erase(que.begin(),itr);
            while (buf.size() > 1) {
                que.push_front(buf.front());
                buf.pop();
            }
        } else {
            --itr;
            for (itr1 = que.end(), --itr1; itr1 != itr; --itr1)
                buf.push(*itr1);
            que.erase(++itr,que.end());
            while (buf.size() > 1) {
                que.push_back(buf.front());
                buf.pop();
            }
        }
        buf.pop();
        copy(que.begin(),que.end(),ou);
        if (que.size() != 1)
            cout << endl;
    }
//    system("pause");
    return 0;
}
