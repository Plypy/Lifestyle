#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int ans;
bool isend[500];
int main() {
    isend['.'] = isend['?'] = isend['!'] = true;
    string buf;
    bool first = true;
    while (cin >> buf) {
//        if ("end" == buf)
//            break;
        int len = buf.size();
        bool word = true;
        for (int i = 0; i < len; ++i) {
            if (!word && isalpha(buf[i]) && buf[i] < 'a') {
                ++ans;
//                cout << 1 << ' ' <<  buf << endl;
            }
            word = false;
            if (!isalpha(buf[i]))
                word = true;
            if (first && isalpha(buf[i]) && buf[i] > 'Z') {
//                cout << 2 << ' ' << buf << endl;
                ++ans;
            }
            if (first && isalpha(buf[i]))
                first = false;
            if (isend[buf[i]])
                first = true;
        }
    }
    cout << ans << endl;
//    system("pause");
    return 0;
}
