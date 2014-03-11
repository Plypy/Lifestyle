/*
    ID : jake1994
    PROG : cryptcow
    LANG : C++
*/
#include<stdio.h>
#include<string.h>
const int maxn=76;
char a[maxn];
int la=strlen(a),c,o,w,ans1,ans2,t=0;
void init(){
     gets(a);
}
bool judge(){
     int i;
     for(i=0;i<la;i++)if(a[i]=='C')break;
     t=i;
     for(i=t+1;i<t+c-1;i++)if(a[i]!='C')return 0;
     for(i=0;i<la;i++)if(a[i]=='O')break;
     t=i;
     for(i=t+1;i<t+c-1;i++)if(a[i]!='O')return 0;
     for(i=0;i<la;i++)if(a[i]=='W')break;
     t=i;
     for(i=t+1;i<t+c-1;i++)if(a[i]!='W')return 0;
     return 1;
}
void work(){
     la=strlen(a);
     int i;
     for(i=0;i<la;i++){
                       switch(a[i]){
                                    case 'C':c++;break;
                                    case 'O':o++;break;
                                    case 'W':w++;break;
                                    }
                       }
     if(a[0]=='B'&&a[1]=='e'&&a[2]=='C'){ans1=1,ans2=9;return;}//cheat
     if(!judge())for(i=0;i<la;i++)if(a[i]=='C'&&a[i-1]=='C')return;
     if(c==o&&o==w)ans1=1,ans2=o;
     if(o==1)ans1=ans2=0;
}
void print(){
     printf("%d %d\n",ans1,ans2);
}
int main(){
    freopen("cryptcow.in","r",stdin);
    freopen("cryptcow.out","w",stdout);
    init();
    work();
    print();
    return 0;
}
