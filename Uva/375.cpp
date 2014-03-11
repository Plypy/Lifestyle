#include<stdio.h>
#include<math.h>
#define INFS 1e-6
int main()
{
    double b, h, r, t, _h, y;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf",&b,&h);
        y = sqrt(h*h+b*b/4);
        t = b/(b+2*y);
        _h = h;
        r = t*_h;
        while(r >= INFS)
        {
            _h = _h-2*r;
            r = _h*t;
        }
      printf("%13.6lf\n",M_PI*(h-r/t));
      if(T)
        putchar('\n');
    }
    return 0;
}
