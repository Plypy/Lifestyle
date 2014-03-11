#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <cctype>
#include <vector>
using namespace std;
const int MAXT = 35;
const int WPT  = 3;
const int LPT  = 0;
const int TPT  = 1;
struct Team {
    string name;
    string lowername;
    int point;
    int gamect;
    int wct;
    int tct;
    int lct;
    int goal_dif;
    int goal_get;
    int goal_los;
    explicit Team(string iname = ""): name(iname), lowername(iname), point(0), 
        gamect(0), wct(0), tct(0), lct(0), goal_dif(0), goal_get(0), goal_los(0) 
    {
            int len = lowername.size();
            for (int i = 0; i < len; ++i)
                lowername[i] = tolower(lowername[i]);
    }
    bool operator<(const Team &t) const {
        if (point != t.point)
            return point>t.point;
        if (wct != t.wct)
            return wct > t.wct;
        if (goal_dif != t.goal_dif)
            return goal_dif > t.goal_dif;
        if (goal_get != t.goal_get)
            return goal_get > t.goal_get;
        if (gamect != t.gamect)
            return gamect < t.gamect;
        return lowername < t.lowername;
    }
    void stat(int get, int los) {
        ++gamect;
        goal_get += get;
        goal_los += los;
        goal_dif += get-los;
        if (get > los) {
            ++wct;
            point += WPT;
        } else if (get == los) {
            ++tct;
            point += TPT;
        } else {
            ++lct;
            point += LPT;
        }
    }
};

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("ans.txt", "w", stdout);
    
    int n;
    cin >> n;
    cin.get();
    while (n--) {
        string tournament;
        getline(cin,tournament);
        
        map<string,int> nametoid;
        vector<Team> teamset;
        int t;
        cin >> t;
        cin.get();
        
        for (int i = 0; i < t; ++i) {
            string tmp;
            getline(cin,tmp);
            teamset.push_back(Team(tmp));
            nametoid[tmp] = i;
        }
        int g;
        cin >> g;
        cin.get();
        
        for (int i = 0; i < g; ++i) {
            string tmp;
            getline(cin,tmp);
            int bg = 0, ed = tmp.find('#');
            string name1 = tmp.substr(0,ed);
            bg = ed+1;
            ed = tmp.find('@',bg);
            string buf = tmp.substr(bg,ed-bg);
            int goal1 = atoi(buf.c_str());
            bg = ed+1;
            ed = tmp.find('#',bg);
            buf = tmp.substr(bg,ed-bg);
            int goal2 = atoi(buf.c_str());
            bg = ed+1;
            string name2 = tmp.substr(bg);
            
            int id1 = nametoid[name1];
            int id2 = nametoid[name2];
            teamset[id1].stat(goal1,goal2);
            teamset[id2].stat(goal2,goal1);
        }
        
        sort(teamset.begin(),teamset.end());
        cout << tournament << endl;
        for (int i = 0; i < t; ++i) {
            cout << i+1 << ") " << teamset[i].name << ' ';
            cout << teamset[i].point << "p, ";
            cout << teamset[i].gamect << "g ";
            cout << '(' << teamset[i].wct << '-' << teamset[i].tct << '-' << teamset[i].lct << "), ";
            cout << teamset[i].goal_dif << "gd (" << teamset[i].goal_get << '-' << teamset[i].goal_los << ')' << endl;
        }
        if (n)
            cout << endl;
    }
    return 0;
}
