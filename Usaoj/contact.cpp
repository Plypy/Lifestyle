/*
    ID : jake1994
    PROG : contact
    LANG : C++
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
struct node
{
    int ct;
    string seq;
} tree[10000];
int a, b, n;
void insert(const string &pat)
{
    int pos = 1;
    for (int i = 0; i < pat.size(); i++)
    {
        pos <<= 1;
        if (pat[i]-'0')
            ++pos;
        if (i+1>=a)
        {
            if (tree[pos].seq.size() == 0)
                tree[pos].seq = pat.substr(0,i+1);
            ++tree[pos].ct;
        }
    }
}
int cmp(const void *a, const void *b)
{
    node *t1 = (node *)a;
    node *t2 = (node *)b;
    if ((t1->seq).size() == 0)
        return 1;
    if ((t2->seq).size() == 0)
        return -1;
    if (t1->ct > t2->ct)
        return -1;
    if (t1->ct < t2->ct)
        return 1;
    if ((t1->seq).size() > (t2->seq).size())
        return 1;
    if ((t1->seq).size() < (t2->seq).size())
        return -1;
    if (t1->seq < t2->seq)
        return -1;
    return 1;
}
int main()
{
    string table;
    string tmp;
    ifstream fin("contact.in");
    ofstream fout("contact.out");
    fin >> a  >> b >> n;
    while (fin >> tmp)
        table += tmp;
    int len = table.size()-b;
    
    for (int i = 0; i < len; i++)
        insert(table.substr(i,b));
    if (len < 0)
        len = 0;
    for (int i = len; i <= table.size()-a; i++)
        insert(table.substr(i));
    qsort(tree,10000,sizeof(node),cmp);
    fout << tree[0].ct << endl << tree[0].seq;
    int t = 1;
    int count = 1;
    for (int i = 1;;i++)
    {
        if (tree[i].seq.size() == 0)
            break;
        if (tree[i].ct != tree[i-1].ct)
        {
            count++;
            if (count > n)
                break;
            fout << endl;
            t = 1;
            fout << tree[i].ct << endl << tree[i].seq;
        }
        else
        {
            ++t;
            if (t%6==1)
                fout << endl;
            else
                fout << ' ';
            fout << tree[i].seq;
        }
    }
    fout << endl;
    fin.close();
    fout.close();
    return 0;
}
