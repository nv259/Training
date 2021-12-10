#include <bits/stdc++.h>
#define MAX   1111

const double PI=acos(-1.0);
const double INF=2e9;

struct point
{
    double x,y;
    point(){}
    point(const double &_x,const double &_y) {
        x=_x;y=_y;
    }
    point rotate(const double &alpha) {
        return (point(x*cos(alpha)-y*sin(alpha),x*sin(alpha)+y*cos(alpha)));
    }
};

double min(const double &x,const double &y) {
    if (x<y) return (x); else return (y);
}
double max(const double &x,const double &y) {
    if (x>y) return (x); else return (y);
}
int m,n;
point a[MAX];
point b[MAX];

void init()
{
    int i;
    scanf("%d",&m);
    for (i=1;i<=m;i=i+1)
    {
        scanf("%lf",&a[i].x);
        scanf("%lf",&a[i].y);
    }
    scanf("%d",&n);
    for (i=1;i<=n;i=i+1)
    {
        scanf("%lf",&b[i].x);
        scanf("%lf",&b[i].y);
    }
}
void check()
{
    int i,j;
    double alpha;
    double mxa,mna,mxb,mnb;

    for (i = 0;i < 100; i++)
    {
        alpha = i*PI/100.0;
        mxa = -INF; mna = INF;
        mxb = -INF; mnb = INF;
        for (j = 1; j <= m; j++) {
            mxa = max(mxa, a[j].rotate(alpha).x);
            mna = min(mna, a[j].rotate(alpha).x);
        }
        for (j = 1; j <= n; j++) {
            mxb = max(mxb, b[j].rotate(alpha).x);
            mnb = min(mnb, b[j].rotate(alpha).x);
        }
        if (mxa < mnb) {
            printf("NO\n");
            return;
        }
        if (mxb < mna) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main()
{
    freopen("nkland.inp", "r", stdin);
    freopen("nkland.out", "w", stdout);

    int t,c;
    scanf("%d",&t);
    for (c = 1;c <= t;c++)
    {
        init();
        check();
    }
    return 0;
}
