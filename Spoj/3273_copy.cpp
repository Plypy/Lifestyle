// copy À´µÄtreap½è¼øÏÂ 
#include<cstdio>
#include<cstdlib>
using namespace std;
const int inf=~0U>>1;
class treap
{
        struct node
        {
                int value,key,size;
                node(int v,node*n):value(v)
                {c[0]=c[1]=n;size=1;key=rand()-1;}
                void rz(){size=c[0]->size+c[1]->size+1;}
                node*c[2];
        }*root,*null;
        void rot(node*&t,bool d)
        {
                node*c=t->c[d];
                t->c[d]=c->c[!d];
                c->c[!d]=t;
                t->rz();c->rz();
                t=c;
        }
        void insert(node*&t,int x)
        {
                        if(t==null)     {t=new node(x,null);return;}
                        if(x==t->value) return;
                        bool d=x>t->value;
                        insert(t->c[d],x);
                        if(t->c[d]->key<t->key)
                                rot(t,d);
                        else
                                t->rz();
        }
        void Delete(node*&t,int x)
        {
                   if(t==null) return;
                   if(t->value==x)
                        {
                                bool d=t->c[1]->key<t->c[0]->key;
                                if(t->c[d]==null)
                                {
                                        delete t;
                                        t=null;
                                        return;
                                }
                                rot(t,d);
                                Delete(t->c[!d],x);
                        }
                        else
                        {
                                bool d=x>t->value;
                                Delete(t->c[d],x);
                        }
                        t->rz();
        }
        int select(node*t,int k)
        {
                int r=t->c[0]->size;
                if(k==r) return t->value;
                if(k<r) return select(t->c[0],k);
                return select(t->c[1],k-r-1);
        }
        int rank(node*t,int x)
        {
                if(t==null) return 0;
                int r=t->c[0]->size;
                if(x==t->value) return r;               
                if(x<t->value) return rank(t->c[0],x);
                return r+1+rank(t->c[1],x);
        }
        public:
        treap()
        {
                null=new node(0,0);null->size=0;null->key=inf;
                root=null;
        }
        void ins(int x)
        {
                insert(root,x);
        }
        int sel(int k)
        {
                if(k>root->size) return -inf;
                return select(root,k-1);
        }
        int ran(int x)
        {
                return rank(root,x);
        }
        void del(int x)
        {
                Delete(root,x);
        }       
}T;
int main()
{
        //freopen("in","r",stdin);
        int m;scanf("%d\n",&m); 
        char t;int x,tmp;
        while(m--)
        {
                scanf("%c %d\n",&t,&x);
                switch(t)
                {
                        case 'I':T.ins(x);break;
                        case 'D':T.del(x);break;
                        case 'K':tmp=T.sel(x);if(tmp==-inf)printf("invalid\n");else printf("%d\n",tmp);break;
                        case 'C':printf("%d\n",T.ran(x));break;
                }               
        }
}
