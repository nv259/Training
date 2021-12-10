#include <bits/stdc++.h>
#define forn(i,a,b) for (int i=(a); i<=(b); i++)
#define ford(i,a,b) for (int i=(a); i>=(b); i--)
#define repn(i,a,b) for (int i=(a); i<(b); ++i)
using namespace std;
//////

const
    int maxn=3e6+10, del=1e6+1;
int n, cou0, res;
int d[maxn+1];
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

void  test() {
  int code = 10;

  if (code) {
  
  }
}

void enter()
{
    fastscan(n);
    int x;
    forn(x, 0, maxn) d[x]=1;
    forn(i, 1, n)
    {
        fastscan(x);
        if (x==0) ++cou0; else d[x+del]=0;
    }
    forn(x, 1, maxn) d[x]+=d[x-1];
}
//////

void process()
{
    int L=1;
    res=0;
    forn(R, 1, maxn)
    {
        while (d[R]-d[L-1]>cou0) ++L;
        res=max(res, R-L+1);
    }
    cout << res;
}
//////

int main()
{
    freopen("lseq.inp", "r", stdin);
    freopen("lseq.out", "w", stdout);
    enter();
    process();
}
