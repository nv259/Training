/// IO_Light Le Nhat Huy T5 CBL ///

#include <bits/stdc++.h>
#define forn(i,a,b) for (int i=(a); i<=(b); i++)
#define ford(i,a,b) for (int i=(a); i>=(b); i--)
#define repn(i,a,b) for (int i=(a); i<(b); ++i)
using namespace std;
//////

typedef pair<int, int> pii;
const
    int maxn=1e5+100;
int n;
pii a[maxn], b[maxn];
int ans[maxn];
//////

void fastscan(int &number)
{
    number=0;
    register char c=getchar();
    while (c!='-' && (c<48 || c>57)) c=getchar();
    bool negative=false;
    if (c=='-') negative=true, c=getchar();
    for(; c>47 && c<58; c=getchar())
        number=number*10+c-48;
    if (negative) number=-number;
}

void enter()
{
    fastscan(n);
    forn(i, 1, n) fastscan(a[i].first), a[i].second=i;
    forn(i, 1, n) fastscan(b[i].first), b[i].second=i;
    sort(a+1, a+n+1, greater<pii>() );
    sort(b+1, b+n+1);
}
//////

void process()
{
    int L=1, R=n+1, mid;
    while (L<R)
    {
        mid=(L+R)/2;
        bool ok=true;
        forn(i, 1, mid)
            if (b[i].first>a[mid-i+1].first)
            {
                ok=false;
                break;
            }
        if (!ok) R=mid; else L=mid+1;
    }
    --L;
    forn(i, 1, L) ans[a[i].second]=b[L-i+1].second;
    forn(i, L+1, n) ans[a[i].second]=b[n-i+1+L].second;
    forn(i, 1, n) cout << ans[i] << ' ';
}
//////

int main()
{
    freopen("iq.inp", "r", stdin);
    freopen("iq.out", "w", stdout);
    enter();
    process();
}
