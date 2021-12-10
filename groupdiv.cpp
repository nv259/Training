/// IO_Light Le Nhat Huy T5 CBL ///

#include <bits/stdc++.h>
#define forn(i,a,b) for (int i=(a); i<=(b); i++)
#define ford(i,a,b) for (int i=(a); i>=(b); i--)
#define repn(i,a,b) for (int i=(a); i<(b); ++i)
using namespace std;
//////

const
    int maxn=3e5+100;
int n;
vector<int> e[maxn];
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
    forn(i, 1, n)
    {
        int len; fastscan(len);
        while (len--)
        {
            int x; fastscan(x);
            e[i].emplace_back(x);
        }
    }
}
//////

void process()
{
    forn(u, 1, n) ans[u]=0;
    while (true)
    {
        bool ok=true;
        forn(u, 1, n)
            if (ans[u]==0)
            {
                int cou=0;
                for(int v : e[u])
                    if (ans[v]==ans[u]) ++cou;
                if (cou>1)
                {
                    ans[u]=1;
                    ok=false;
                }
            }
        forn(u, 1, n)
            if (ans[u]==1)
            {
                int cou=0;
                for(int v : e[u])
                    if (ans[v]==ans[u]) ++cou;
                if (cou>1)
                {
                    ans[u]=0;
                    ok=false;
                }
            }
        if (ok) break;
    }
    cout << "YES" << '\n';
    forn(u, 1, n)
        if (ans[u]==0) cout << u << ' ';
    cout << '\n';
    forn(u, 1, n)
        if (ans[u]==1) cout << u << ' ';
}
//////

int main()
{
    freopen("groupdiv.inp", "r", stdin);
    freopen("groupdiv.out", "w", stdout);
    enter();
    process();
}
