/// IO_Light Le Nhat Huy T5 CBL ///

#include <bits/stdc++.h>
#define forn(i,a,b) for (int i=(a); i<=(b); i++)
#define ford(i,a,b) for (int i=(a); i>=(b); i--)
#define repn(i,a,b) for (int i=(a); i<(b); ++i)
using namespace std;
//////

const
    int maxn=2e3+100;
int n;
int c[maxn];
int pos[maxn][maxn];
long long f[maxn][maxn], child[maxn][maxn];
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
    forn(i, 1, n) fastscan(c[i]);
}
//////

void process()
{
    forn(i, 1, n)
    {
        child[i][i]=c[i];
        forn(j, i+1, n)
            child[i][j]=child[i][j-1]+c[j];
    }

    forn(i, 1, n) f[i][i]=c[i], pos[i][i]=i;
    ford(i, n, 1)
        forn(j, i+1, n)
        {
            f[i][j]=1e15;
            forn(k, pos[i][j-1], pos[i+1][j])
                if (f[i][j]>f[i][k-1]+f[k+1][j]+child[i][j])
                {
                    f[i][j]=f[i][k-1]+f[k+1][j]+child[i][j];
                    pos[i][j]=k;
                }
        }
    cout << f[1][n];
}
//////

int main()
{
    freopen("optbst.inp", "r", stdin);
    freopen("optbst.out", "w", stdout);
    enter();
    process();
}
