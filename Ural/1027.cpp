#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
using namespace std;
const int Normal = 0;
const int Comment = 1;
const int Expression = 2;
const int WaitNxtBracket = 4;
struct State {
    int sid;
    int pos;
    State(int isid = 0, int ipos = 0):
        sid(isid), pos(ipos) { }
};

int main() {
    bool valid = true;
    
    stack<State> state;
    int pos = 0;
    state.push(State(Normal,pos));
    bool read = true;
    while (valid) {
        char ch;
        if (read) {
            ++pos;
            ch = cin.get();
        }
        if ('\n' == ch) {
            --pos;
            continue;
        }
        read = true;
        if (!cin)
            break;
        State tmp = state.top();
        if (WaitNxtBracket == tmp.sid) {
            state.pop();
            if (')' == ch)
                state.pop();
            else
                read = false;
        } else if (Expression == tmp.sid) {
            if (ch != '/' && ch != '*' && ch != '-' && ch != '+' && ch != '=' && 
                ch != '(' && ch != ')' && !isdigit(ch))
                valid = false;
            if ('*' == ch && pos == tmp.pos+1) {
                state.pop();
                state.push(State(Comment,pos));
            } else if ('(' == ch) {
                state.push(State(Expression,pos));
            } else if(')' == ch)
                state.pop();
        } else if (Comment == tmp.sid) {
            if ('*' == ch)
                state.push(State(WaitNxtBracket,pos));
        } else if (Normal == tmp.sid) {
            if ('(' == ch) {
                state.push(State(Expression,pos));
            } else if (')' == ch)
                valid = false;
        }
    }
    if (Normal != state.top().sid)
        valid = false;
    if (valid)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
//    system("pause");
    return 0;
}
