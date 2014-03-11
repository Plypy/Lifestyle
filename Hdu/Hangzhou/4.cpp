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
#define M_PI       3.14159265358979323846  /* pi */
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
        printf("%.6lf, %.6lf, %.6lf\n", x, y, z);
    }
};
//繕瓊糧�
double dot(const Point & a, const Point & b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}
double dot(const Point & o, const Point & a, const Point & b) {
    return dot(a-o, b-o);
}
//簡疆糧�
Point cross(const Point & a, const Point & b) {
    return Point(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}
Point cross(const Point & o, const Point & a, const Point & b) {
    return cross(a-o,b-o);
}
//�翻繕瓊職��禱
double dis(const Point & a, const Point & b) {
    return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y) + sqr(a.z-b.z));
}
//繕瓊繕翻�簣��職��禱
double dis(const Point & o, const Point & a, const Point & b) {
    return cross(o, a, b).len() / dis(a,b);
}
//繚繕罈�o繕翻ab�簣��繕��繞�簞繕瓊, 繞���o��ab���簡��繙�
Point pointToLine(const Point & o, const Point & a, const Point & b) {
    Point fa = cross(o, a, b);  //oab繕�織繒�簷�聶
    Point vec = cross(b-a, fa); //vec�穠��oab�翻�疆��瞿竅����o�繡�簷ab繕��罈�繭�簷�聶
    return o + vec.resize(fa.len()/dis(a,b));
}
//��繞��羸繕瓊繒簡��
bool sameLine(const Point & a, const Point & b, const Point & c) {
    return sig(cross(a, b, c).len())==0;
}
//��繞���繕瓊繒簡�疆
bool sameFace(const Point & a, const Point & b, const Point & c, const Point & d) {
    return sig(dot(b-a, cross(a, c, d))) == 0;
}
//p����se�簷�聶瞿竅�疆�簣�禱�穠ang翻�繞�
Point rotate(Point p, Point s, Point e, double ang) {
    if(sameLine(p, s, e)) {
        //sprintf("keke..\n");  error!
        return p;
    }
    Point fa1 = cross(s, e, p);
    Point fa2 = cross(e-s, fa1);

    double len = fabs(cross(p, e, s).len() / dis(e, s));    //�簡��翻�
    fa2 = fa2.resize(len);
    fa1 = fa1.resize(len);
    Point h = p + fa2;
    Point pp = h + fa1;

    Point res = h + (p-h)*cos(ang) + (pp-h)*sin(ang);
    return res;
}
//vec���罈繡繹�簷�聶瞿竅翻竄vec�穠繕翻z�獺�簷�聶瞿竅繚繕罈�p繕瓊�羅�穠繕翻繕��罈��
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
    bool inFace(Point q) const {    //��繞��糧繕瓊��繚簽��繡��翻�疆��
        return sameFace(a, b, c, q);
    }
    bool operator == (const Face & face) const {
        Point fa1 = fa();
        Point fa2 = face.fa();
        if(sig(cross(fa1,fa2).len())!=0)    return false;
        return inFace(face.a);
    }
};
//��繞��翻�簣���翻��
bool px(const Point & a, const Point & b, const Point & c, const Point & d) {
    return sig(cross(b-a, d-c).len()) == 0;
}
//��繞��簣���禱�翻�疆�翻��
bool px(const Face & f, const Point & a, const Point & b) {
    return sig(dot(f.fa(), b-a))==0;
}
//��繞��翻�翻�疆�翻��
bool px(const Face & f1, const Face & f2) {
    return sig(cross(f1.fa(),f2.fa()).len()) == 0;
}
//��繞��翻�簣��織繒�簣
bool cz(const Point & a, const Point & b, const Point & c, const Point & d) {
    return sig(dot(b-a, d-a)) == 0;
}
//��繞��簣���禱�翻�疆織繒�簣
bool cz(const Face & f, const Point & a, const Point & b) {
    return sig(cross(f.fa(), b-a).len()) == 0;
}
//��繞��翻�翻�疆織繒�簣
bool cz(const Face & f1, const Face & f2) {
    return sig(dot(f1.fa(), f2.fa())) == 0;
}
//繕瓊繕翻�翻�疆職��禱
double dis(const Face & f, const Point & p) {
    Point fa = f.fa();
    return fabs(dot(fa, f.a-p) / fa.len());
}
//�翻�簣��職��禱
double dis(const Point & a, const Point & b, const Point & c, const Point & d) {
    Point fa = cross(b-a,d-c);
    if(fa.len() == 0) { //�翻�簣���翻��
        return cross(c, a, b).len() / dis(a, b);
        return dis(c, a, b);        //罈簷�����璽繡繹瞿竅繕瓊繕翻�簣��職��禱
    } else {
        return fabs(dot(c-a, fa) / fa.len());
    }
}

//�籀ab�簣���禱f繕�翻罈繕瓊瞿竅繞���ab��f簡罈�翻��
Point intersect(const Face & f, const Point & a, const Point & b) {
    Point fa = f.fa();
    double t = dot(fa,f.a-a) / dot(fa,b-a);
    return a+(b-a)*t;
}
//�籀�翻�簣��翻罈繕瓊瞿竅癒職繞���癒聶�翻�簣��繒簡�疆��簡罈�翻��
Point intersect(const Point & a, const Point & b, const Point & c, const Point & d) {
    Point e = d + cross(a-b, c-d);
    return intersect(Face(c,d,e), a, b);
    //罈簷�������疆織繳�禱瞿繙
    Point fa = cross(c, d, e);
    double t = dot(fa, c-a) / dot(fa, b-a);
    return a+(b-a) * t;
}
//�籀f1,f2繕�翻罈��瞿竅繞���f1�禱f2簡罈�翻��
void intersect(const Face & f1, const Face & f2, Point & p1, Point & p2) {
    p1 = false==px(f2, f1.a, f1.b) ? intersect(f2, f1.a, f1.b) : intersect(f2, f1.b, f1.c);
    p2 = p1 + cross(f1.fa(), f2.fa());
}
//�籀�翻�簣��繕�繒簡織繒��, p1繚繕罈�ab�簣����繕�繒竄織繒��翻罈繕瓊瞿竅p2繚繕罈�cd�簣����繕�繒竄織繒��翻罈繕瓊
void gc(const Point & a, const Point & b, const Point & c, const Point & d, Point & p1, Point & p2) {
    Point e = d + cross(a-b, c-d);
    p1 = intersect(Face(c,d,e), a, b);
    p2 = pointToLine(p1, c, d);
}
//��繞�繕瓊��繚簽��聶�翹瓣�羸翻�����簡聶, 簞羹�穡簣�翻癟, 癒職繞���癒聶abc簡罈繒簡��瞿竅簡瞽��oabc繒簡�疆
bool inTriangle(const Point & o, const Point & a, const Point & b, const Point & c) {
    double s = cross(a, b, c).len();
    double s1 = cross(o, a, b).len();
    double s2 = cross(o, b, c).len();
    double s3 = cross(o, a, c).len();
//  return sig(s - s1 - s2 - s3) == 0;
    return sig(s-s1-s2-s3)==0 && sig(s1)==1 && sig(s2)==1 && sig(s3)==1;//簡罈簞羹�穡簣�翻癟繕�簞疆簣職
}
//��繞��糧繡繹繕瓊��繚簽����繞���, 繞���oab繒簡��       -1簣穩�職�����疆瞿竅0簣穩�職����繞�簣���瞿竅1簣穩�職����繞��璽
int onSeg(const Point & o, const Point & a, const Point & b) {
    return sig(dot(o, a, b));
}

int T;
Point pt[5];

int main() {
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 4; ++i)
            pt[i].input();
        bool fucked = sameFace(pt[0], pt[1], pt[2], pt[3]);
        if (fucked) {
            Point in = intersect(pt[0], pt[1], pt[2], pt[3]);
            puts("0.000000");
            printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n", in.x, in.y, in.z, in.x, in.y, in.z);
        } else {
            double di = dis(pt[0], pt[1], pt[2], pt[3]);
            printf("%.6lf\n", di);
            Point p, q;
            gc(pt[0], pt[1], pt[2], pt[3], p, q);
            printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n", p.x, p.y, p.z, q.x, q.y, q.z);
        }
    }
    return 0;
}
