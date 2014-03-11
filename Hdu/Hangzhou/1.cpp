#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)

using namespace std;
#define maxn 10010
# define M_PI       3.14159265358979323846  /* pi */
#define sqr(v) ((v)*(v))
const double eps = 1E-8;
int sig(double d) {
    return (d>eps) - (d<-eps);
}
struct Point {
    double x, y, z;
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    Point() {}
    Point operator + (const Point & p) const {
        return Point(x+p.x, y+p.y, z+p.z);
    }
    Point operator - (const Point & p) const {
        return Point(x-p.x, y-p.y, z-p.z);
    }
    Point operator * (const double & d) const {
        return Point(x*d, y*d, z*d);
    }
    Point resize(double d) {
        d /= sqrt(x*x+y*y+z*z);
        return Point(x*d, y*d, z*d);
    }
    double len() const {
        return sqrt(x*x+y*y+z*z);
    }
    bool operator < (const Point & p) const {
        return sig(x-p.x)!=0 ? x<p.x : sig(y-p.y)!=0 ? y<p.y : sig(z-p.z)<0;
    }
    bool operator == (const Point & p) const {
        return sig(x-p.x)==0 && sig(y-p.y)==0 && sig(z-p.z)==0;
    }
    void input() {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
    void output() const {
        printf("x = %.2f, y = %.2f, z = %.2f\n", x, y, z);
    }
};
//µã³Ë
double dot(const Point & a, const Point & b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}
double dot(const Point & o, const Point & a, const Point & b) {
    return dot(a-o, b-o);
}
//²æ³Ë
Point cross(const Point & a, const Point & b) {
    return Point(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}
Point cross(const Point & o, const Point & a, const Point & b) {
    return cross(a-o,b-o);
}
//Á½µã¾àÀë
double dis(const Point & a, const Point & b) {
    return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y) + sqr(a.z-b.z));
}
//µãµ½Ö±Ïß¾àÀë
double dis(const Point & o, const Point & a, const Point & b) {
    return cross(o, a, b).len() / dis(a,b);
}
//·µ»Øoµ½abÖ±ÏßµÄÍ¶Ó°µã, ¶ÔÓÚoÔÚabÉÏÒ²ÊÊºÏ
Point pointToLine(const Point & o, const Point & a, const Point & b) {
    Point fa = cross(o, a, b);  //oabµÄ´¹ÏòÁ¿
    Point vec = cross(b-a, fa); //vecÎªÔÚoabÆ½ÃæÉÏ£¬ÇÒÓÉoÖ¸ÏòabµÄÒ»ÌõÏòÁ¿
    return o + vec.resize(fa.len()/dis(a,b));
}
//ÅÐ¶ÏÈýµã¹²Ïß
bool sameLine(const Point & a, const Point & b, const Point & c) {
    return sig(cross(a, b, c).len())==0;
}
//ÅÐ¶ÏËÄµã¹²Ãæ
bool sameFace(const Point & a, const Point & b, const Point & c, const Point & d) {
    return sig(dot(b-a, cross(a, c, d))) == 0;
}
//pÈÆ×ÅseÏòÁ¿£¬ÄæÊ±Õë×ªang½Ç¶È
Point rotate(Point p, Point s, Point e, double ang) {
    if(sameLine(p, s, e)) {
        //sprintf("keke..\n");  error!
        return p;
    }
    Point fa1 = cross(s, e, p);
    Point fa2 = cross(e-s, fa1);

    double len = fabs(cross(p, e, s).len() / dis(e, s));    //Ô²ÐÄ½Ç
    fa2 = fa2.resize(len);
    fa1 = fa1.resize(len);
    Point h = p + fa2;
    Point pp = h + fa1;

    Point res = h + (p-h)*cos(ang) + (pp-h)*sin(ang);
    return res;
}
//vecÊÇÒ»¸öÏòÁ¿£¬½«vec×ªµ½zÖáÏòÁ¿£¬·µ»ØpµãËù×ªµ½µÄÎ»ÖÃ
Point rotate(Point p, Point vec) {
    Point z(0, 0, 1);
    Point fa = cross(vec, z);
    return rotate(p, Point(0,0,0), fa, acos( dot(z,vec)/vec.len() ));
}

struct Face {
    Point a, b, c;
    Face() {}
    Face(Point a, Point b, Point c) : a(a), b(b), c(c) {}
    Point fa() const {
        return cross(a, b, c);
    }
    bool same_side(Point q , Point  p){
        return sig ( dot(a - q, cross(q, b, c))
            * dot(a - p , cross(p, b, c)) ) > 0 ;
    }
    bool inFace(Point q) const {    //ÅÐ¶ÏÄ³µãÊÇ·ñÔÚ¸ÃÆ½ÃæÉÏ
        return sameFace(a, b, c, q);
    }
    bool operator == (const Face & face) const {
        Point fa1 = fa();
        Point fa2 = face.fa();
        if(sig(cross(fa1,fa2).len())!=0)    return false;
        return inFace(face.a);
    }
};
//ÅÐ¶ÏÁ½Ö±ÏßÆ½ÐÐ
bool px(const Point & a, const Point & b, const Point & c, const Point & d) {
    return sig(cross(b-a, d-c).len()) == 0;
}
//ÅÐ¶ÏÖ±ÏßÓëÆ½ÃæÆ½ÐÐ
bool px(const Face & f, const Point & a, const Point & b) {
    return sig(dot(f.fa(), b-a))==0;
}
//ÅÐ¶ÏÁ½Æ½ÃæÆ½ÐÐ
bool px(const Face & f1, const Face & f2) {
    return sig(cross(f1.fa(),f2.fa()).len()) == 0;
}
//ÅÐ¶ÏÁ½Ö±Ïß´¹Ö±
bool cz(const Point & a, const Point & b, const Point & c, const Point & d) {
    return sig(dot(b-a, d-a)) == 0;
}
//ÅÐ¶ÏÖ±ÏßÓëÆ½Ãæ´¹Ö±
bool cz(const Face & f, const Point & a, const Point & b) {
    return sig(cross(f.fa(), b-a).len()) == 0;
}
//ÅÐ¶ÏÁ½Æ½Ãæ´¹Ö±
bool cz(const Face & f1, const Face & f2) {
    return sig(dot(f1.fa(), f2.fa())) == 0;
}
//µãµ½Æ½Ãæ¾àÀë
double dis(const Face & f, const Point & p) {
    Point fa = f.fa();
    return fabs(dot(fa, f.a-p) / fa.len());
}
//Á½Ö±Ïß¾àÀë
double dis(const Point & a, const Point & b, const Point & c, const Point & d) {
    Point fa = cross(b-a,d-c);
    if(fa.len() == 0) { //Á½Ö±ÏßÆ½ÐÐ
        return cross(c, a, b).len() / dis(a, b);
        return dis(c, a, b);        //»òÕßÓÃÕâ¸ö£¬µãµ½Ö±Ïß¾àÀë
    } else {
        return fabs(dot(c-a, fa) / fa.len());
    }
}

//ÇóabÖ±ÏßÓëfµÄ½»µã£¬¶ÏÑÔabÓÚf²»Æ½ÐÐ
Point intersect(const Face & f, const Point & a, const Point & b) {
    Point fa = f.fa();
    double t = dot(fa,f.a-a) / dot(fa,b-a);
    return a+(b-a)*t;
}
//ÇóÁ½Ö±Ïß½»µã£¬¡¾¶ÏÑÔ¡¿Á½Ö±Ïß¹²ÃæÇÒ²»Æ½ÐÐ
Point intersect(const Point & a, const Point & b, const Point & c, const Point & d) {
    Point e = d + cross(a-b, c-d);
    return intersect(Face(c,d,e), a, b);
    //»òÕßÓÃÏÂÃæ´úÂë£º
    Point fa = cross(c, d, e);
    double t = dot(fa, c-a) / dot(fa, b-a);
    return a+(b-a) * t;
}
//Çóf1,f2µÄ½»Ïß£¬¶ÏÑÔf1Óëf2²»Æ½ÐÐ
void intersect(const Face & f1, const Face & f2, Point & p1, Point & p2) {
    p1 = false==px(f2, f1.a, f1.b) ? intersect(f2, f1.a, f1.b) : intersect(f2, f1.b, f1.c);
    p2 = p1 + cross(f1.fa(), f2.fa());
}
//ÇóÁ½Ö±ÏßµÄ¹²´¹Ïß, p1·µ»ØabÖ±ÏßÉÏµÄ¹«´¹Ïß½»µã£¬p2·µ»ØcdÖ±ÏßÉÏµÄ¹«´¹Ïß½»µã
void gc(const Point & a, const Point & b, const Point & c, const Point & d, Point & p1, Point & p2) {
    Point e = d + cross(a-b, c-d);
    p1 = intersect(Face(c,d,e), a, b);
    p2 = pointToLine(p1, c, d);
}
//ÅÐ¶ÏµãÊÇ·ñÔÚ¿Õ¼äÈý½ÇÐÎÄÚ²¿, °üÀ¨±ß½ç, ¡¾¶ÏÑÔ¡¿abc²»¹²Ïß£¬²¢ÇÒoabc¹²Ãæ
bool inTriangle(const Point & o, const Point & a, const Point & b, const Point & c) {
    double s = cross(a, b, c).len();
    double s1 = cross(o, a, b).len();
    double s2 = cross(o, b, c).len();
    double s3 = cross(o, a, c).len();
//  return sig(s - s1 - s2 - s3) == 0;
    return sig(s-s1-s2-s3)==0 && sig(s1)==1 && sig(s2)==1 && sig(s3)==1;//²»°üÀ¨±ß½çµÄ°æ±¾
}
//ÅÐ¶ÏÄ³¸öµãÊÇ·ñÔÚÏß¶ÎÉÏ, ¶ÏÑÔoab¹²Ïß       -1±íÊ¾ÔÚÉÏÃæ£¬0±íÊ¾ÔÚÏß¶Î±ßÉÏ£¬1±íÊ¾ÔÚÏß¶ÎÍâ
int onSeg(const Point & o, const Point & a, const Point & b) {
    return sig(dot(o, a, b));
}

int T;
Point p[5];

int main() {
    scanf("%d", &T);
    while (T--) {
        FOR (i, 1, 4) scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
        bool ok = sameFace(p[1], p[2], p[3], p[4]);
        if (ok) {
            Point ans = intersect(p[1], p[2], p[3], p[4]);
            puts("0.000000");
            printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n", ans.x, ans.y, ans.z, ans.x, ans.y, ans.z);
        } else {
            double d = dis(p[1], p[2], p[3], p[4]);
            printf("%.6lf\n", d);
            Point p1, p2;
            gc(p[1], p[2], p[3], p[4], p1, p2);
            printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n", p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
        }
    }
    return 0;
}
