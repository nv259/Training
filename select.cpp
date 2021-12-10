/// IO_Light Le Nhat Huy T5 CBL ///

#include <bits/stdc++.h>
#define forn(i,a,b) for (int i=(a); i<=(b); i++)
#define ford(i,a,b) for (int i=(a); i>=(b); i--)
#define repn(i,a,b) for (int i=(a); i<(b); ++i)
using namespace std;
//////

const
    int maxn=2e5+100;
int n, m, T;
int W[maxn], X[maxn], Y[maxn], de[maxn];
char type[maxn];
int T1[maxn], T2[maxn];
long long ans[maxn];

struct DSU
{
    int lab[maxn];
    long long sum[maxn];
    priority_queue<pair<long long, int> > Q;

    void create()
    {
        while (!Q.empty()) Q.pop();
        forn(u, 1, n) lab[u]=-1, sum[u]=W[u], Q.push({sum[u], u});
    }
    int GetRoot(int p)
    {
        if (lab[p]<0) return p;
        return lab[p]=GetRoot(lab[p]);
    }
    void Union(int x, int y)
    {
        int x0=GetRoot(x), y0=GetRoot(y);
        if (x0==y0) return;
        if (lab[x0]>lab[y0]) swap(x0, y0);
        lab[x0]+=lab[y0];
        lab[y0]=x0;
        sum[x0]+=sum[y0];
        Q.push({sum[x0], x0});
    }
    void change(int u, int w)
    {
        int u0=GetRoot(u);
        sum[u0]+=w-W[u];
        Q.push({sum[u0], u0});
        W[u]=w;
    }
    long long Getmax()
    {
        while (!Q.empty())
        {
            pair<long long, int> p=Q.top();
            if (!lab[p.second]<0 || sum[p.second]!=p.first) Q.pop();
            else break;
        }
        return Q.top().first;
    }
} dsu;
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
    fastscan(n); fastscan(m); fastscan(T);
    forn(u, 1, n) fastscan(W[u]);
    forn(i, 1, m)
        fastscan(X[i]), fastscan(Y[i]);
    forn(i, 1, T)
    {
        type[i]=getchar();
        if (type[i]=='D')
        {
            fastscan(T1[i]);
            de[T1[i]]=1;
        } else
        {
            fastscan(T1[i]); fastscan(T2[i]);
            swap(W[T1[i]], T2[i]);
        }
    }
}
//////

void process()
{
    dsu.create();
    forn(i, 1, m)
        if (de[i]==0) dsu.Union(X[i], Y[i]);
    ford(i, T, 1)
    {
        ans[i]=dsu.Getmax();
        if (type[i]=='C') dsu.change(T1[i], T2[i]); else
        if (type[i]=='D') dsu.Union(X[T1[i]], Y[T1[i]]);
    }
    forn(i, 1, T) cout << ans[i] << '\n';
}
//////

int main()
{
    freopen("select.inp", "r", stdin);
    freopen("select.out", "w", stdout);
    enter();
    process();
}
