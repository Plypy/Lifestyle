/*
ID: jake1994
LANG: C++
TASK: clocks
*/
// COPY Going on~
#include <fstream>
#include <limits.h>
  using namespace std;
 
  ifstream fin("clocks.in");
  ofstream fout("clocks.out");
 
  int m, minh, rus;
  int ham(int n)
  {
    int t = 0;
    do
    {
      t += (n & 3);
      n = n >> 2;
    } while (n);
    return t;
  }
 
  int mino(int pos)
  {
    int l = ham(pos);
    if (l > minh) return m;
    if (l < minh) {minh = l; return pos;}
  int pos_ = pos, min_ = m;
    while (pos_ && min_)
    {
      if ((pos_ & 3) > (min_ & 3)) return pos;
      if ((pos_ & 3) < (min_ & 3)) return m;
      pos_ = pos_ >> 2; 
      min_ = min_ >> 2;
    }
  }
 
  void seat(int &pos, int n)
  {
  int t = 3 << (2 * n - 2);
    if ((pos & t) == t) pos = pos & ~t;
      else pos += 1 << (2 *n - 2);
    return ;
  } 
 
  int turn(int pos, int n)
  { 
    switch (n)
    {
      case 1: seat(pos, 1); seat(pos, 2); seat(pos, 4); seat(pos, 5); break;
      case 2: seat(pos, 1); seat(pos, 2); seat(pos, 3); break;
      case 3: seat(pos, 2); seat(pos, 3); seat(pos, 5); seat(pos, 6); break;
      case 4: seat(pos, 1); seat(pos, 4); seat(pos, 7); break;
      case 5: seat(pos, 2); seat(pos, 4); seat(pos, 5); seat(pos, 6); seat(pos, 8); break;
      case 6: seat(pos, 3); seat(pos, 6); seat(pos, 9); break;
      case 7: seat(pos, 4); seat(pos, 5); seat(pos, 7); seat(pos, 8); break;
      case 8: seat(pos, 7); seat(pos, 8); seat(pos, 9); break;
      case 9: seat(pos, 5); seat(pos, 6); seat(pos, 8); seat(pos, 9); break;
    }
    return pos;
  }
 
  void test(int pos, int now, int n)
  {
    if (n > 9) return ; 
    test(pos, now, n + 1);
    for (int i = 1; i <= 3; i++) 
      {
        pos = turn(pos, n);
        now += (1 << (2 * n - 2));
        if (pos == rus) {m = mino(now);}
          else test(pos, now, n + 1);
      }
    return ;
  }
 
  void prin()
  {
  int k = m, i = 1, j, key = 0;
    do
    {
      j = (m & 3);
      for (int p = 0; p < j; p++)
        {
          if (key == 1) fout << ' ';
            fout << i;
          key = 1;
        }
      i++;
      m = m >> 2;
    }
    while (m);
    fout << endl;
    return ;
  } 
 
  int main()
  {
    m = INT_MAX;
    minh = INT_MAX;
  int t = 0;
    for (int i = 1; i <= 9; i++)
      {
        fin >> t;
        t = 4 - t/3;
        rus = rus | (t << (2 * i - 2));
      }
    test(0,0,1);
    prin(); 
    fin.close();
    fout.close();
    return EXIT_SUCCESS;
  }
