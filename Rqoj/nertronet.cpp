//Note������⿼�����������򣬰�������ѧ�����µ��㷨
//      ����ͨ���������ʵ�ֵ��㷨
//      ����ͦţ�Ƶ� ����
//      At last�����ݷ�Χ����Ҫ������
//          �ڽӾ���Ҳ��ţ��
//          ������ڽӾ����ʾʱʹ�����������飬һ����¼�Ƿ��бߡ�
//          ��һ�����¼�ߵ�Ȩֵ����ʵ��ȫû��Ҫ��...
//          �� �б�Ҫ����Ϊ�����ߵ�Ȩֵ����Ϊ0
//          ��������������ı�ʶ����ʾ�ޱ�
//          �� �鷳һЩ�... 
#include<iostream>
#include<cstring>
using namespace std;
int w[210][210];
bool a[210][210];//�ڽӾ��� 
int c[210],u[210],f[210],cnt[210];//f,ÿ��������ڵĲ㣻cntÿ��������� 
int top,n,e;
void toppx()
 {   
     int i,j;
     bool p=1;
     top=0;
     while(p)
      {
          p=0;
          top++;
          for(i=1;i<=n;i++)
            if(cnt[i]==0)
             {
                 p=1;
                 f[i]=top; 
             }  
          for(i=1;i<=n;i++)
           if(f[i]==top)//�൱��ɾ������һ�ڵ� 
             {
                 for(j=1;j<=n;j++)
                  if(a[i][j])
                   cnt[j]--;
                cnt[i]=-1;   
             }         
      }  
    top--;    
 }    
int main()
 {
      int i,j,k,x,y,d;
     while(cin>>n>>e)
      {
          memset(a,0,sizeof(a));
          memset(cnt,0,sizeof(cnt));
          memset(f,0,sizeof(f));
          for(i=1;i<=n;i++)
           cin>>c[i]>>u[i];
          for(i=1;i<=e;i++)//��ͼ���� 
          { cin>>x>>y>>d;
            a[x][y]=1;
            w[x][y]=d;
            cnt[y]++; 
          }   
        toppx();
        for(i=2;i<=top;i++)//�ӵڶ��㵽���һ�� 
         for(k=1;k<=n;k++)
          if(f[k]==i)
           {
               c[k]=-u[k];
               for(j=1;j<=n;j++)
                if(a[j][k]&&c[j]>0)//�ж��Ƿ��д�jָ��k�ı߲��ҵ�j���˷ܵ� 
                c[k]+=w[j][k]*c[j];
           }  
        
        k=0;//���˷ܵ���м��� 
        for(i=1;i<=n;i++)//����˷ܵĵ� 
         if(f[i]==top)
          {
              if(c[i]>0)
               {
                   cout<<i<<" "<<c[i]<<endl;
                   k++;
               }    
          } 
        if(k==0)
         cout<<"NULL"<<endl;                       
      }    
     return 0;
 }  
