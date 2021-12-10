/// IO_Light Le Nhat Huy T5 CBL ///

#include <bits/stdc++.h>
#define forn(i,a,b) for (int i=(a); i<=(b); i++)
#define ford(i,a,b) for (int i=(a); i>=(b); i--)
#define repn(i,a,b) for (int i=(a); i<(b); ++i)
using namespace std;
//////

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<ULL, LL> cap;
const
    int maxn=1e5+100;
int n;
LL minL, maxR, a[maxn];
cap res;
//////

void enter()
{
    scanf("%d", &n);
    scanf("%lld%lld\n", &minL, &maxR);
    forn(i, 1, n) scanf("%lld", &a[i]);
    sort(a+1, a+n+1);
}
//////

ULL distan(LL l, LL r)
{
    if (l>r) swap(l, r);
    if (l>=0) return r-l; else return ULL(-l)+r;
}

LL Getmid(LL l, LL r)
{
    LL del=distan(l, r)/2;
    return l+del;
}

void maximize(cap &x, cap y) { if (x<y) x=y;}

void process()
{
    res={0, minL};
    if (minL<a[1]) maximize(res, cap(distan(minL, a[1]), minL));
    if (a[n]<maxR) maximize(res, cap(distan(a[n], maxR), maxR));
    forn(i, 1, n-1)
    {
        if (a[i+1]<=minL) continue;
        if (a[i]>=maxR) break;
        LL mid=Getmid(a[i], a[i+1]);
        LL x=max(min(mid, maxR), minL);
        maximize(res, cap(min(distan(a[i], x), distan(x, a[i+1])), x));
        ++mid;
        x=max(min(mid, maxR), minL);
        maximize(res, cap(min(distan(a[i], x), distan(x, a[i+1])), x));
    }
    cout << res.second;
}
//////

int main()
{
    freopen("maxdis.inp", "r", stdin);
    freopen("maxdis.out", "w", stdout);
    enter();
    process();
}
