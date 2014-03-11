//Note：这道题考的是拓扑排序，俺在这里学到了新的算法
//      就是通过操作入度实现的算法
//      还是挺牛逼的 嗯嗯
//      At last：数据范围很重要！！！
//          邻接矩阵也很牛逼
//          这里的邻接矩阵表示时使用了两个数组，一个记录是否有边。
//          另一个则记录边的权值，其实完全没必要啦...
//          呃 有必要，因为这道题边的权值可能为0
//          不过可以用特殊的标识符表示无边
//          呃 麻烦一些喽... 
#include<iostream>
#include<cstring>
using namespace std;
int w[210][210];
bool a[210][210];//邻接矩阵 
int c[210],u[210],f[210],cnt[210];//f,每个结点所在的层；cnt每个结点的入度 
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
           if(f[i]==top)//相当于删除掉这一节点 
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
          for(i=1;i<=e;i++)//建图过程 
          { cin>>x>>y>>d;
            a[x][y]=1;
            w[x][y]=d;
            cnt[y]++; 
          }   
        toppx();
        for(i=2;i<=top;i++)//从第二层到最后一层 
         for(k=1;k<=n;k++)
          if(f[k]==i)
           {
               c[k]=-u[k];
               for(j=1;j<=n;j++)
                if(a[j][k]&&c[j]>0)//判断是否有从j指向k的边并且点j是兴奋的 
                c[k]+=w[j][k]*c[j];
           }  
        
        k=0;//对兴奋点进行计数 
        for(i=1;i<=n;i++)//输出兴奋的点 
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
