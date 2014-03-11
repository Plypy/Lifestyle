/*
ID: jake1994
PROG: packrec
LANG: C++
*/
#include <cstdio>
#include <iostream>
using namespace std;
int total,MIN=32767,a[5][3],Ans[100][3],a1,a2,a3,a4,b1,b2,b3,b4;
void Init()
{
  freopen("packrec.in","r",stdin);
  freopen("packrec.out","w",stdout);
  for (int i=1;i<5;i++)
    scanf("%d %d",&a[i][1],&a[i][2]);
}
void Updata(int x,int y)
{
  if (x*y>MIN)
    return;
  if (x*y<MIN)
  {
    MIN=x*y;
    total=0;
  }
  if (x>y)
    swap(x,y);
  for (int i=1;i<=total;i++)
    if (x==Ans[i][1]&&y==Ans[i][2])
      return;
  total++;
  Ans[total][1]=x; Ans[total][2]=y;
}
void Work()
{
  int h1=a[a1][b1],h2=a[a2][b2],h3=a[a3][b3],h4=a[a4][b4],w1=a[a1][3-b1],w2=a[a2][3-b2],w3=a[a3][3-b3],w4=a[a4][3-b4],width,height;
 
  width=w1+w2+w3+w4;//第一次
  height=max(max(max(h1,h2),h3),h4);
  Updata(width,height);
 
  width=max(w1+w2+w3,w4);//第二次
  height=max(max(h1,h2),h3)+h4;
  Updata(width,height);
 
  width=max(w1+w2,w3)+w4;//第三次
  height=max(max(h1,h2)+h3,h4);
  Updata(width,height);
 
  width=w1+w2+max(w3,w4);//第四次
  height=max(max(h1,h2),h3+h4);
  Updata(width,height);
 
  height=max(h1+h3,h2+h4);
  if (h3>=h2+h4)
     width=max(w1,w3+max(w2,w4));
  if (h3>h4&&h3<h2+h4)
     width=max(w1+w2,w3+max(w2,w4));
  if (h3<h4&&h4<h1+h3)
     width=max(w1+w2,w4+max(w1,w3));
  if (h4>=h1+h3)
     width=max(w2,w4+max(w1,w3));
  if (h3==h4)
     width=max(w1+w2,w3+w4);
  Updata(width,height);//第五次
}
void Slove()
{
  for (a1=1;a1<5;a1++)
    for (a2=1;a2<5;a2++)
      if (a1!=a2)
        for (a3=1;a3<5;a3++)
        if (a3!=a2&&a3!=a1)
        {
          a4=10-a1-a2-a3;//第一个四重循环枚举每个矩形的摆放位置
          for (b1=1;b1<3;b1++)
            for (b2=1;b2<3;b2++)
              for (b3=1;b3<3;b3++)
                for (b4=1;b4<3;b4++)//第二个四重循环枚举每个矩形的摆放形式（横放或者竖放）
                  Work();
        }
}
void Print()
{
  int i,j;
  for (i=1;i<total;i++)
    for (j=i+1;j<=total;j++)
      if (Ans[i][1]>Ans[j][1])
      {
        swap(Ans[i][1],Ans[j][1]);
        swap(Ans[i][2],Ans[j][2]);
      }
  printf("%d\n",MIN);
  for (i=1;i<=total;i++)
    printf("%d %d\n",Ans[i][1],Ans[i][2]);
  fclose(stdin);
  fclose(stdout);
}
int main()
{
  Init();
  Slove();
  Print();
  return 0;
}
