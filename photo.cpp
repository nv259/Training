/// IO_Light Le Nhat Huy T5 CBL ///
	
#include <bits/stdc++.h>
#define forn(i,a,b) for (int i=(a); i<=(b); i++)
#define ford(i,a,b) for (int i=(a); i>=(b); i--)
#define repn(i,a,b) for (int i=(a); i<(b); ++i)
using namespace std;
//////

const
    int maxn=1e5+100;
int n;
int pos[5][maxn];
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
    forn(t, 0, 4)
        forn(i, 1, n)
        {
            int x; fastscan(x);
            pos[t][x]=i;
        }
}
//////

bool compare(int x, int y)
{
    int cx=0;
    forn(t, 0, 4)
        if (pos[t][x]<pos[t][y]) ++cx;
    if (cx>=3) return true; else return false;
}

void process()
{
    forn(i, 1, n) ans[i]=i;
    sort(ans+1, ans+n+1, compare);
    forn(i, 1, n) cout << ans[i] << ' ';
}
//////

int main()
{
    freopen("photo.inp", "r", stdin);
    freopen("photo.out", "w", stdout);
    enter();
    process();
}
