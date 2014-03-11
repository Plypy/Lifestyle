#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    int round;
    while (true) {
        cin >> round;
        if (-1 == round)
            break;
        string ans;
        cin >> ans;
        int ct = 0;
        bool alist[30] = {0};
        for (char ch = 'a'; ch <= 'z'; ++ch)
            if (ans.find(ch) < ans.size()) {
                ++ct;
                alist[ch-'a'] = true;
            }
        string guess;
        cin >> guess;
        bool guessed[30] = {0};
        int wct = 0;
        int rct = 0;
        int flag = 2; // 0 lose 1 win 2 chicken out
        for (int i = 0; i < guess.size() && 2 == flag; ++i) {
            int pos = guess[i]-'a';
            if (alist[pos] && (!guessed[pos])) {
                guessed[pos] = true;
                ++rct;
                if (rct == ct)
                    flag = 1;
            } else if ((!alist[pos]) && (!guessed[pos])) {
                guessed[pos] = true;
                ++wct;
                if (7 == wct)
                    flag = 0;
            }
        }
        cout << "Round " << round << endl;
        if (0 == flag)
            cout << "You lose." << endl;
        else if (1 == flag)
            cout << "You win." << endl;
        else
            cout << "You chickened out." << endl;
    }
    return 0;
}
