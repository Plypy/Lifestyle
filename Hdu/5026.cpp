/**
 * Description: Determine whether two Regular Expressions are equal.
 *     Method, transform the RE to NFA and then just fuck it!
 *
 * ProblemName:
 * Source:
 * Author: Ply_py
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <stack>
using namespace std;

const int MAXN = 15;
const int EPS = 10;
//dictionary 0..9
const static int MAXV = MAXN*2;

struct eNFA {
    int vct;
    vector<int> adj[MAXV][EPS+1];

    int newVtx() {
        // cout << "allocating " << vct << endl;
        return vct++;
    }

    void add(int u, int v, int ch) {
        // cout << "adding " << u << ' ' << v << ' ' << ch << endl;
        adj[u][ch].push_back(v);
    }

    // temporal automata used to build the final eps-NFA
    struct Node {
        int st, ed;
        Node(int is = 0, int ie = 0): st(is), ed(ie) {}
    };

    void init(Node &nd) {
        nd.st = newVtx();
        nd.ed = newVtx();
    }

    // operations on Node

    // concatenation
    Node concat(Node a, Node b) {
        add(a.ed, b.st, EPS);
        return Node(a.st, b.ed);
    }

    // merge options
    Node merge(Node a, Node b) {
        Node ret;
        init(ret);
        add(ret.st, a.st, EPS);
        add(ret.st, b.st, EPS);
        add(a.ed, ret.ed, EPS);
        add(b.ed, ret.ed, EPS);
        return ret;
    }

    // closure
    Node closure(Node a) {
        int st = newVtx();
        add(st, a.st, EPS);
        add(st, a.ed, EPS);
        add(a.ed, a.st, EPS);
        return Node(st, a.ed);
    }

    // regular expression
    string rexp;
    int match[MAXN];
    // [..)
    Node parse(int l, int r) {
        // cout << "debuging " << l << ' ' << r << endl;
        // error
        if (l >= r) {
            cerr << "Fucked!!! There should never be any empty string" << endl;
            return Node();
        }
        // single unit
        if (l+1 == r) {
            Node ret;
            init(ret);
            add(ret.st, ret.ed, rexp[l]-'0');
            return ret;
        }

        // options
        for (int i = l; i < r; ++i) {
            if ('(' == rexp[i]) {
                i = match[i];
                continue;
            }
            if ('|' == rexp[i]) {
                return merge(parse(l, i), parse(i+1, r));
                break;
            }
        }

        // braces
        if ('(' == rexp[l]) {
            // with a bracket wrapping outside
            if (match[l] == r-1) {
                return parse(l+1, r-1);
            }
            int cr = match[l]+1;
            while (cr < r && '*' == rexp[cr]) {
                ++cr;
            }
            // single bracket with one or more * outside
            if (cr == r) {
                return closure(parse(l+1, match[l]));
            }
            // normal concatenation
            return concat(parse(l, cr), parse(cr, r));
        }
        // normal concatenation
        int cr = l+1;
        while (cr < r && '*' == rexp[cr]) {
            ++cr;
        }
        if (cr == r) {
            return closure(parse(l,l+1));
        }
        return concat(parse(l,cr), parse(cr,r));
    }

    Node self;
    // match the braces and parse the RE
    void build(string str) {
        rexp = str;
        stack<int> stk;
        int len = str.size();
        for (int i = 0; i < len; ++i) {
            if ('(' == str[i]) {
                stk.push(i);
            } else if (')' == str[i]) {
                match[stk.top()] = i;
                stk.pop();
            }
        }
        self = parse(0, len);
    }

    eNFA() {
        vct = 0;
        for (int i = 0; i < MAXV; ++i) {
            for (int j = 0; j <= EPS; ++j) {
                adj[i][j].clear();
            }
        }
        memset(match, 0, sizeof(match));
    }

    // // label the NFA
    // map<int, int> label;
    // map<int, int> revLabel;
    // int maxLabel;
    // void setLabel(int u) {
    //     if (label.count(u)) {
    //         return ;
    //     }
    //     label[u] = ++maxLabel;
    //     revLabel[maxLabel] = u;
    //     for (int ch = 0; ch <= EPS; ++ch) {
    //         int sz = adj[u][ch].size();
    //         for (int i = 0; i < sz; ++i) {
    //             int v = adj[u][ch][i];
    //             setLabel(v);
    //         }
    //     }
    // }
    // void markLabel() {
    //     maxLabel = 0;
    //     setLabel(self.st);
    // }
};

// use a long long to store all possible states

struct Comparer {
    typedef long long LL;
    typedef pair<LL,LL> pll;
    set<pll> vis;

    // helper function
    LL getMask(int label) {
        return (1LL)<<label;
    }

    bool belong(LL state, int label) {
        int mask = getMask(label);
        if (state & mask) {
            return true;
        }
        return false;
    }

    bool success(eNFA &nfa, LL state) {
        // int elabel = nfa.label[nfa.self.ed];
        int elabel = nfa.self.ed;
        return belong(state, elabel);
    }

    void epsDfs(eNFA &nfa, LL &state, int u, int st) {
        // int label = nfa.label[u];
        int label = u;
        if (u != st && belong(state, label))  {
            return;
        }
        state |= getMask(label);

        int sz = nfa.adj[u][EPS].size();
        for (int i = 0; i < sz; ++i) {
            int v = nfa.adj[u][EPS][i];
            epsDfs(nfa, state, v, st);
        }
    }

    void epsExpand(eNFA &nfa, LL &state) {
        for (int label = 0, ts = state; ts; ts >>= 1, ++label) {
            if (ts&1) {
                // int u = nfa.revLabel[label];
                int u = label;
                // cout << "in eps extending " <<  state << ' ' << u << endl;
                epsDfs(nfa, state, u, u);
            }
        }
    }

    LL expand(eNFA &nfa, LL state, int ch) {
        LL ret = 0;
        for (int label = 0, ts = state; ts; ts >>= 1, ++label) {
            if (ts&1) {
                // int u = nfa.revLabel[label];
                int u = label;
                int sz = nfa.adj[u][ch].size();
                for (int i = 0; i < sz; ++i) {
                    int v = nfa.adj[u][ch][i];
                    // int vlabel = nfa.label[v];
                    int vlabel = v;
                    ret |= getMask(vlabel);
                }
            }
        }
        return ret;
    }

    bool equalDeep(eNFA &a, LL sa, eNFA &b, LL sb) {
        // cout << "dfsing while states are " << sa << ' ' << sb << endl;
        epsExpand(a, sa);
        epsExpand(b, sb);
        // cout << "after extending states are " << sa << ' ' << sb << endl;
        pll maskPair = make_pair(sa,sb);

        if (vis.count(maskPair)) {
            return true;
        }
        vis.insert(maskPair);
        if (success(a,sa) != success(b,sb)) {
            return false;
        }
        for (int i = 0; i < EPS; ++i) {
            int nsa = expand(a, sa, i);
            int nsb = expand(b, sb, i);
            if (nsa == sa && nsb == sb) {
                continue;
            }
            // cout << "expending " << i << endl;
            if (!equalDeep(a, nsa, b, nsb)) {
                return false;
            }
        }
        return true;
    }

    bool equal(eNFA &a, eNFA &b) {
        // a.markLabel();
        // b.markLabel();
        // return equalDeep(a, a.label[a.self.st], b, b.label[b.self.st]);
        int sa = getMask(a.self.st);
        int sb = getMask(b.self.st);
        return equalDeep(a, sa, b, sb);
    }

    LL getState(eNFA &a, LL state, string seq) {
        if (seq.empty()) {
            return state;
        }
        epsExpand(a, state);
        state = expand(a, state, seq[0]-'0');
        getState(a, state, seq.substr(1));
        return state;
    }

    LL test(eNFA &a, string seq) {
        return getState(a, getMask(a.self.st), seq);
    }
};

void solve() {
    string sa, sb;
    cin >> sa;
    eNFA na;
    // cout << na.vct << endl;
    na.build(sa);
    // cout << "a finished" << endl;

    cin >> sb;
    eNFA nb;
    nb.build(sb);
    Comparer cmp;
    // debug
    // cout << na.self.ed << ' ' << nb.self.ed << endl;
    // while (true) {
    //     string str;
    //     cin >> str;
    //     bitset<20> a(cmp.test(na, str));
    //     bitset<20> b(cmp.test(nb, str));
    //     cout << a << endl;
    //     cout << b << endl;
    // }
    cout << (cmp.equal(na,nb)?"YES":"NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
