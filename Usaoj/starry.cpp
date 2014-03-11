/*
    ID : jake1994
    PROG : starry
    LANG : C++
*/
//此题是一道较为简单的题，也较为复杂
//所以我决定copy....
//大牛的做法就是牛逼啊...
//直接自己设计散列函数判重
//这个散列函数使用了计算机存储数据的特性即使用了上溢以及下溢
//还使用了最小表示法的思想
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE *fin=fopen("starry.in","r");
FILE *fout=fopen("starry.out","w");
char map[103][103];
int H,W,tot;
struct star{
       int h,w;
       int hash[4];
}s[27];
 
void init()
{
     fscanf(fin,"%d%d",&W,&H);
     for(int i=1;i<=H;i++)
       fscanf(fin,"%s",map[i]+1);
}
 
bool in(int y,int x)
{
     if(y<1||y>H) return 0;
     if(x<1||x>W) return 0;
     return 1;
}
 
int x1,x2,y1,y2;
void floodfill(int y,int x,char t)
{
     if(x<x1) x1=x;    if(x>x2) x2=x;
     if(y<y1) y1=y;    if(y>y2) y2=y;
     char tmp=map[y][x];
     map[y][x]=t;
     for(int i=-1;i<=1;i++)
       for(int j=-1;j<=1;j++)
       if(in(y+i,x+j)&&map[y+i][x+j]==tmp)
           floodfill(y+i,x+j,t);
}
 
int hash[4];
 
void get_hash(int x1,int x2,int x3,int x4)
{
     #define max 1000003
     #define max2 9999987
     int h1=0,h2=0,t1=0,t2=0;
     for(int i=y1;i<=y2;i++)
     {
             t1=0;  t2=0;
             for(int j=x1;j<=x2;j++)
             {
               t1=(t1*103)+(map[i][j]=='.'?31:7);
               t2=(t2*103)+(map[i][x1+x2-j]=='.'?31:7);
             }
             h1+=t1;  h2+=t2;  
     }
     hash[0]=h1;   hash[1]=h2;
     h1=0,h2=0;
     for(int i=x1;i<=x2;i++)
     {
             t1=0;  t2=0;
             for(int j=y1;j<=y2;j++)
             {
               t1=(t1*103)+(map[j][i]=='.'?31:7);
               t2=(t2*103)+(map[y1+y2-j][i]=='.'?31:7);
             }
             h1+=t1;  h2+=t2;
     }
     hash[2]=h1;   hash[3]=h2;
}
 
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
 
void work()
{
     for(int i=1;i<=H;i++)
      for(int j=1;j<=W;j++)
      if(map[i][j]=='1')
      {
                      int l1,l2,m;
                      bool ok=0;
                      memset(hash,0,sizeof(hash));
                      x1=y1=0x7fffffff;
                      x2=y2=0;
                      floodfill(i,j,'.');
                      l1=x2-x1+1;  l2=y2-y1+1;
                      get_hash(x1,x2,y1,y2);
                      qsort(hash,4,sizeof(int),cmp);
                      for(m=1;m<=tot;m++)
                        if((s[m].w==l1&&s[m].h==l2)||(s[m].w==l2&&s[m].h==l1))
                                if(memcmp(s[m].hash,hash,sizeof(hash))==0)
                                {
                                                         ok=1;
                                                         break;
                                }
                      if(!ok)
                      {
                             m=++tot;
                             s[m].h=l1;   s[m].w=l2;
                             for(int k=0;k<4;k++)  s[m].hash[k]=hash[k];
                      }
                      floodfill(i,j,m+'a'-1);
      }
}
 
int main()
{
    init();
    work();
    for(int i=1;i<=H;i++)
    {
      for(int j=1;j<=W;j++)
        fprintf(fout,"%c",map[i][j]);
      fprintf(fout,"\n");
    }
    return 0;
}
