#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void output(int x)//输出，注意前导0
{
  int t=1000;
  while(t!=1&&x/t==0)
  {
  printf("0");   
  t=t/10;
  }
  printf("%d",x);  
}

int main()
{
 
    
    int n=0,i=0,j=-1,t=0;
    char st1[100000]={0},st2[100000]={0};
    int a[100000]={0},b[100000]={0},c[100000]={0};
    int p=0,q=0;
    
    scanf("%d\n",&n);
    
    scanf("%s\n",st1);
    scanf("%s\n",st2);
    
    t=n%4;//处理小于4的位
    
    
    for(i=n-1;i>=t;i=i-4)//倒序压位
    {
     j++;
     a[j]=(st1[i]-'0')+(st1[i-1]-'0')*10+(st1[i-2]-'0')*100+(st1[i-3]-'0')*1000;
     b[j]=(st2[i]-'0')+(st2[i-1]-'0')*10+(st2[i-2]-'0')*100+(st2[i-3]-'0')*1000;                       
    }
    
    for(i=0;i<=t-1;i++)//处理小于4的位
    {
     a[j+1]=a[j+1]*10+(st1[i]-'0');
     b[j+1]=b[j+1]*10+(st2[i]-'0');                      
    }
    
    if(a[j+1]!=0)
    j++;
    
    for(p=0;p<=j;p++)//高精乘法
     for(q=0;q<=j;q++)
     {
      c[p+q]+=a[p]*b[q];
      if(c[p+q]>=10000)//进位，防止爆掉
      {
      c[p+q+1]+=c[p+q]/10000;
      c[p+q]=c[p+q]%10000;
      }
     }
   
   for(i=1;i<=2*j+100000;i++)//正式进位
    if(c[i]>=10000)
      {
      c[i+1]+=c[i]/10000;
      c[i]=c[i]%10000;
      }
   
   j=j*2;
   while(c[j+1]!=0)
   j++; 
    
    printf("%d",c[j]);//输出首四位
    for(i=j-1;i>=0;i--)//输出余下位数
    {
     output(c[i]);                  
    }
    
    
    return 0;
}
