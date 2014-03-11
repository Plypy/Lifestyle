#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

struct Data {
    string word;
    string value;
    Data(string iword = "", string ivalue = ""):
        word(iword), value(ivalue) { }
    bool operator<(const Data &t) const {
        return word<t.word;
    }
};

int main() {
    map<string,int> occur;
    vector<Data> dvec;
    string tmp;
    while (true) {
        cin >> tmp;
        if ("#" == tmp)
            break;
        string buf = tmp;
        int len = buf.size();
        for (int i = 0; i < len; ++i)
            buf[i] = tolower(buf[i]);
        sort(buf.begin(), buf.end());
        ++occur[buf];
        dvec.push_back(Data(tmp,buf));
    }
    sort(dvec.begin(), dvec.end());
    int vsize = dvec.size();
    for (int i = 0; i < vsize; ++i) {
        if (1 == occur[dvec[i].value])
            cout << dvec[i].word << endl;
    }
    return 0;
}
