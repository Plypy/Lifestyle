#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <stack>

using namespace std;

typedef long long LL;

#define REP(i, n) for (int i(0); i < (int) (n); i++)

void solve() {
}
int match[100];

struct Automatonnode;

struct Automatonlink{
    Automatonnode *t;
    Automatonlink *nxt;
    char c;
    void init(Automatonnode *_s,Automatonnode *_t,char _c);
}Link[200000],*pl;


struct Automatonnode{
    Automatonnode *cov;
    Automatonlink *v;
    int nodenum;
    void clear(){cov=this;v=0;nodenum=-1;}
}Node[100000],*pn;

Automatonnode *getcov(Automatonnode *x){
    if(x==x->cov) return x;
    return x->cov=getcov(x->cov);
}

void Automatonlink::init(Automatonnode *_s,Automatonnode *_t,char _c){
    t=_t,c=_c,nxt=_s->v,_s->v=this;
}

char s[10000];

typedef pair<Automatonnode*,Automatonnode*> Automaton;

Automaton Star(Automaton a){
    Automatonnode *s=pn++;
    s->clear();
    pl++->init(s,a.second,0);
    pl++->init(a.second,a.first,0);
    return make_pair(s,a.second);
}

Automaton Union(Automaton a,Automaton b){
    Automatonnode *s=pn++;
    Automatonnode *t=pn++;
    s->clear(),t->clear();
    pl++->init(s,a.first,0);
    pl++->init(s,b.first,0);
    pl++->init(a.second,t,0);
    pl++->init(b.second,t,0);
    return make_pair(s,t);
}

Automaton Connect(Automaton a,Automaton b){
    pl++->init(a.second,b.first,0);
    return make_pair(a.first,b.second);
}

pair<Automatonnode *,Automatonnode *> parseAutomaton(int l, int r){
    if(l==r){
        Automatonnode *s=pn++;
        Automatonnode *t=pn++;
        s->clear(),t->clear();
        pl++->init(s,t,::s[l]);
        return make_pair(s,t);
    }
    {
        int breakpoint=-1;
        for(int i=l;i<=r;++i){
            if(s[i]=='|'){
                breakpoint=i;
                break;
            }
            else if(s[i]=='('){
                i=match[i];
            }
        }
        if(breakpoint!=-1) return Union(parseAutomaton(l,breakpoint-1),parseAutomaton(breakpoint+1,r));
    }
    if(s[l]=='('){
        if(match[l]==r) return parseAutomaton(l+1,r-1);
        int v=match[l]+1;
        while(v<=r&&s[v]=='*'){
            ++v;
        }
        if(v>r){
            return Star(parseAutomaton(l,r-1));
        }
        else{
            return Connect(parseAutomaton(l,v-1),parseAutomaton(v,r));
        }
    }
    else{
        int v=l+1;
        while(v<=r&&s[v]=='*'){
            ++v;
        }
        if(v>r){
            return Star(parseAutomaton(l,r-1));
        }
        else{
            return Connect(parseAutomaton(l,v-1),parseAutomaton(v,r));
        }
    }
}


int T,len,nodecnt;

stack<int> RecLeft;

set<pair<int, int> > Vis;

vector<Automatonnode*> VA,VB;

void setNum(Automatonnode *x,vector<Automatonnode*>& VV){
    if(x->nodenum!=-1) return;
    x->nodenum=nodecnt++;
    VV.push_back(x);
    for(Automatonlink *v=x->v;v;v=v->nxt){
        setNum(v->t,VV);
    }
}
int na,nb;

void Expand(int &opt,Automatonnode *x){
    for(Automatonlink *v=x->v;v;v=v->nxt) if(v->c==0){
        if((1<<(v->t->nodenum))&opt){
        }
        else{
            opt|=1<<(v->t->nodenum);
            Expand(opt,v->t);
        }
    }
}

void Fixed(int &opt,vector<Automatonnode*>& VV){
    for(int i=0;i<int(VV.size());++i) if((1<<i)&opt){
        Expand(opt,VV[i]);
    }
}

bool dfs(int opt1,int opt2,int end1,int end2){
    Fixed(opt1,VA);
    Fixed(opt2,VB);
    if(Vis.count(make_pair(opt1,opt2))) return 1;
    {
        if((((opt1&end1)?0:1)+((opt2&end2)?0:1))%2==1) return false;
    }
    Vis.insert(make_pair(opt1,opt2));
    for(int i='0';i<='9';++i){
        int newopt1=0,newopt2=0;
        for(int j=0;j<na;++j) if((1<<j)&opt1){
            for(Automatonlink *v=VA[j]->v;v;v=v->nxt){
                if(v->c==i){
                    newopt1|=1<<(getcov(v->t)->nodenum);
                }
            }
        }
        for(int j=0;j<nb;++j) if((1<<j)&opt2){
            for(Automatonlink *v=VB[j]->v;v;v=v->nxt){
                if(v->c==i){
                    newopt2|=1<<(getcov(v->t)->nodenum);
                }
            }
        }
        if(!dfs(newopt1,newopt2,end1,end2)) return false;
    }
    return true;
}

int main(){
    scanf("%d",&T);
    while(T--){
        pl=Link,pn=Node;
        scanf("%s",s);
        len=strlen(s);
        for(int i=0;i<len;++i){
            if(s[i]=='('){
                RecLeft.push(i);
            }
            else if(s[i]==')'){
                match[RecLeft.top()]=i;
                RecLeft.pop();
            }
        }
        Automaton A = parseAutomaton(0,len-1);

        scanf("%s",s);
        len=strlen(s);
        for(int i=0;i<len;++i){
            if(s[i]=='('){
                RecLeft.push(i);
            }
            else if(s[i]==')'){
                match[RecLeft.top()]=i;
                RecLeft.pop();
            }
        }
        Automaton B = parseAutomaton(0,len-1);

        nodecnt=0;
        VA.clear();
        setNum(A.first,VA);
        na=nodecnt;

        nodecnt=0;
        VB.clear();
        setNum(B.first,VB);
        nb=nodecnt;
        Vis.clear();

        printf("%s\n",dfs(1,1,1<<A.second->nodenum,1<<B.second->nodenum)?"YES":"NO");
    }
    return 0;
}
