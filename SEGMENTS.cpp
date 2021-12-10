#include <bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; i++)

const int maxn=3e5+5;

struct data
{
    int gt, vt, l;
    data (){}
    data (int a, int b, int c):gt(a), vt(b), l(c){}
};

struct data2
{
    int a, b;
};

using namespace std;

int b[maxn], a[maxn], bi[maxn], kq[maxn];
data2 c[maxn], d[maxn];
vector <data> l;
int n, m, dem;

void enter()
{
    int x, y;
    scanf("%d%d", &n, &m);
    foru (i, 1, n)
    {
        scanf("%d%d", &x, &y);
        if (y < x) swap(x, y);
        l.emplace_back(x, i, 1);
        l.emplace_back(y, i, 2);
    }
    foru (i, 1, m)
    {
        scanf("%d", &x);
        l.emplace_back(x, i, 3);
    }
}

bool ss(data a, data b)
{
    return a.gt < b.gt;
}

void compress()
{
    sort(l.begin(), l.end(), ss);

    dem = 1;
    if (l[0].l == 1) a[l[0].vt] = dem;
    if (l[0].l == 2) b[l[0].vt] = dem;
    if (l[0].l == 3) d[l[0].vt].a = dem;

    int len = l.size();
    foru (i, 1, len-1)
    {
        if (l[i].gt != l[i-1].gt) dem++;
        if (l[i].l == 1) a[l[i].vt] = dem;
        if (l[i].l == 2) b[l[i].vt] = dem;
        if (l[i].l == 3) d[l[i].vt].a = dem;
    }
}

bool cmp(data2 a, data2 b)
{
    return a.a < b.a;
}

void up(int m)
{
    while (m <= dem)
    {
        bi[m] ++;
        m += (m & (-m));
    }
}

int get(int m)
{
    int re =0;
    while (m>0)
    {
        re += bi[m];
        m -= (m & (-m));
    }
    return re;
}

void solve()
{
    foru (i, 1, m) d[i].b = i;
    foru (i, 1, n)
    {
        c[i].a = a[i]; c[i].b = b[i];
    }
    sort(c+1, c+1+n, cmp);
    sort(d+1, d+1+m, cmp);
    int j= 1;
    foru (i, 1, m)
    {
        while (j<=n && d[i].a >= c[j].a)
        {
            up(dem - c[j].b + 1);
            j++;
        }
        kq[d[i].b] = get(dem - d[i].a + 1);
    }

    foru (i, 1, m) cout << kq[i] << ' ';
}

int main()
{
    freopen("segments.inp", "r", stdin);
    freopen("segments.out", "w", stdout);
    //freopen("a.inp","r",stdin);
    
    enter();
    compress();
    solve();

    return 0;
}