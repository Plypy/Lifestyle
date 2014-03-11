/*
 * 第一题：置换扑克 
 * 输入文件：test.in
 * 输出文件：test.out 
 */ 
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("test.in");
ofstream fout("test.out");
class circular_que
{
private:
    int *numlist;
    int BAS;
    int size;
    int bg, ed;
public:
    circular_que(int _size)
    {
        numlist = new int[_size];
        BAS = _size;
        size = _size;
        bg = ed = 0;
    }
    ~circular_que()
    {
        delete[] numlist;
    }
    int front()
    {
        return numlist[bg];
    }
    int del()
    {
        ++bg;
        --size;
        if (bg == BAS)
            bg = 0;
    }
    void insert(int val)
    {
        numlist[ed++] = val;
        ++size;
        if (ed == BAS)
            ed = 0;
    }
};
int n;
void load()
{
    fin >> n;
}
void work()
{
    circular_que poker_heap(n+2);
    for (int i = 1; i <= n; ++i)
        poker_heap.insert(i);
    for (int i = n; i > 2; --i)
    {
        fout << poker_heap.front() << ' ';
        poker_heap.del();
        poker_heap.insert(poker_heap.front());
        poker_heap.del();
    }
    fout << poker_heap.front() << ' ';
    poker_heap.del();
    fout << poker_heap.front() << endl;
    poker_heap.del();
}

int main()
{
    load();
    work();
    return 0;
}
