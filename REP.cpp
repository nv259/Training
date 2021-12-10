#include <bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; i++)

const int maxn = 1e5+5;

struct data
{
    int x, y;
};

using namespace std;

int     n, maxa;
int     b[maxn*20];
data    a[maxn];
vector  <int> kq;

void enter()
{
    scanf("%d", &n);
    foru (i, 1, n)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].x += maxn*10;
        a[i].y += maxn*10;
        maxa = max(maxa, a[i].y);
    }
}

bool ss(data a, data b)
{
    return a.x > b.x;
}

void up(int m)
{
    while (m <= maxa)
    {
        b[m]++;
        m += (m & (-m));
    }
}

int get(int m)
{
    int re = 0;
    while (m > 0)
    {
        re += b[m];
        m -= (m & (-m));
    }
    return re;
}

void solve()
{
    sort(a+1, a+1+n, ss);

    int t;
    foru (i, 1, n)
    {
        t = get(a[i].y);
        if (t == 0)
        {
            kq.push_back(a[i].x - maxn*10);
            kq.push_back(a[i].x+1 - maxn*10);
            up(a[i].x);
            up(a[i].x+1);
        }
        if (t == 1)
        {
            kq.push_back(a[i].x - maxn*10);
            up(a[i].x); 
        }
    }

    sort(kq.begin(), kq.end());

    cout << kq.size() << '\n';
    foru (i, 0, (int)kq.size()-1) cout << kq[i] << ' ';
}

int main()
{
    freopen("REP.INP", "r", stdin);
    freopen("REP.out", "w", stdout);
    //freopen("a.inp","r",stdin);
    
    enter();
    solve();
}