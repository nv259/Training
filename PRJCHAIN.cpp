#include <bits/stdc++.h>
#define foru(i, a, b) for(int i=a; i<=b; i++)

const int maxn = 1e5+5;

struct data
{
    long long a, b, vt;
};

using namespace std;

data     a[maxn], b[maxn], c[maxn];
int      n, d1, d2;

void enter()
{
    scanf("%d", &n);
    foru (i, 1, n)
    {
        scanf("%I64d", &a[i].a); a[i].vt = i;
    }
    foru (i, 1, n) scanf("%I64d", &a[i].b);
}

bool ss(data a, data b)
{
    return a.a < b.a;
}

bool ss2(data a, data b)
{
    return a.b > b.b;
}

bool check(long long m)
{
    foru (i, 1, d1)
    {
        if (m - b[i].a < 0) return false;
        m = m - b[i].a + b[i].b;
    }
    foru (i, 1, d2)
    {
        if (m - c[i].a < 0) return false;
        m = m - c[i].a + c[i].b;
    }
    return true;
}

void solve()
{
    foru (i, 1, n) if (a[i].a < a[i].b) b[++d1] = a[i]; else c[++d2] = a[i];
    sort(b+1, b+1+d1, ss);
    sort(c+1, c+1+d2, ss2);

    long long d = 0, c1 = 1e14, mid = (d+c1)/2;
    while (d != mid && c1 != mid)
    {
        if (check(mid)) c1 = mid; else d = mid;
        mid = (d+c1)/2;
    }
    while (d <= c1)
    {
        if (check(d))
        {
                cout << d << '\n';
                foru (i, 1, d1) cout << b[i].vt << ' ';
                foru (i, 1, d2) cout << c[i].vt << ' ';
                break;
        }
        d++;
    }
}

int main()
{
    freopen("PRJCHAIN.INP", "r", stdin);
    freopen("PRJCHAIN.out", "w", stdout);

    enter();
    solve();

    return 0;
}