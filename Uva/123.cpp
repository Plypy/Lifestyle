#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

struct Data {
    string title;
    string key;
    int tpos;
    int kpos;
    bool operator<(const Data &t) const {
        if (key != t.key)
            return key<t.key;
        if (tpos != t.tpos)
            return tpos<t.tpos;
        return kpos<t.kpos;
    }
};

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("ans.txt", "w", stdout);
    
    string word;
    set<string> ignored;
    while (true) {
        cin >> word;
        if ("::" == word)
            break;
        ignored.insert(word);
    }
    vector<Data> ans;
    getchar();
    int tct = 0;
    while (getline(cin,word)) {
        ++tct;
        int len = word.size();
        for (int i = 0; i < len; ++i)
            word[i] = tolower(word[i]);
        int bg = 0, ed = 0;
        bool flag = true;
        int ct = 0;
        Data tdat;
        while (flag) {
            ++ct;
            ed = word.find(' ',bg);
            if (string::npos == ed) {
                flag = false;
                ed = len;
            }
            int wlen = ed-bg;
            string tmp = word.substr(bg,wlen);
            if (ignored.end() == ignored.find(tmp)) {
                for (int i = bg; i < ed; ++i)
                    word[i] = toupper(word[i]);
                tdat.title = word;
                for (int i = bg; i < ed; ++i)
                    word[i] = tolower(word[i]);
                tdat.key = tmp;
                tdat.tpos = tct;
                tdat.kpos = ct;
                ans.push_back(tdat);
            }
            bg = ed+1;
        }
    }
    sort(ans.begin(),ans.end());
    int alen = ans.size();
    for (int i = 0; i < alen; ++i)
        cout << ans[i].title << endl;
    return 0;
}
