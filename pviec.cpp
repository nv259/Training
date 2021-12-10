// coded by Binh_CBL_D5
#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

const	int mn = 20005, oo= 2e9;

int     l,r,n,m,v_edge,MaxFlow,
        trace[mn], queue_[mn], c[mn], f[mn], d[mn], Edge_chosen[mn], x[mn], y[mn];
vector<pair<int, int> > a[mn];
vector<int> kq[mn];

void    Add_Edge(int u, int v, int cc)
{
    c[++v_edge]= cc; x[v_edge]= u; y[v_edge]= v;
    a[u].push_back(make_pair(v, v_edge));
    a[v].push_back(make_pair(u,-v_edge));
}

void	enter()
{
    cin>>m>> n;
    FOR(i,1,n) Add_Edge(1+n, i, oo);
    FOR(i,1,n)
    {
        int x;
        scanf("%d", &x);
        while (x!=0)
        {
            Add_Edge(i, x+1+n, 1);
            scanf("%d", &x);
        }
    }
    FOR(i,n+2,n+1+m) Add_Edge(i, 2+n+m, 1);
}

bool    FindPath()
{
    l=1,r=1;
    FOR(i,1,n+m+2) trace[i]=d[i]= 0;
    trace[1+n]= d[1+n]= 2e9;
    queue_[1]= 1+n;

    while (l<=r)
    {
        int u= queue_[l++];
        if (u==n+m+2) return 1;
        for (pair<int, int> x: a[u])
        {
            int v= x.first, w=x.second;
            if (trace[v]==0)
            {
                if (w<0)
                {
                    if (f[-w]>0)
                    {
                        trace[v]= u;
                        Edge_chosen[v]= w;
                        queue_[++r]= v;
                        d[v]= min(d[u], f[-w]);
                    }
                }
                else
                if (f[w]<c[w])
                    {
                        trace[v]= u;
                        Edge_chosen[v]= w;
                        queue_[++r]= v;
                        d[v]= min(d[u], c[w]-f[w]);
                    }
            }
        }
    }
    return 0;
}

void    IncFlow()
{
    int v=n+m+2, i, Flow= d[n+m+2];
    while (v!=n+1)
    {
        i= Edge_chosen[v];
        if (i>0) f[i]+= Flow; else f[-i]-= Flow;
        v= trace[v];
    }
    MaxFlow+= Flow;
}

bool    Check(int x)
{
    FOR(i,1,v_edge) f[i]= 0;
    FOR(i,1,n) c[i]= x;

    MaxFlow= 0;
	while (FindPath())
    {
        IncFlow();
        int t;
        t++;
    }
	return MaxFlow==m;
}

void    solve()
{
    int l=1, r= m, mid, res=0;
    while (l<=r)
    {
        mid= (l+r)/2;
        if (Check(mid)) { res= mid; r=mid-1; } else l= mid+1;
    }
    if (res==0) cout << "NO" ; else
    {
        cout << "YES\n" << res << '\n';
        Check(res);
        FOR(i,n+1,v_edge-m) if (f[i]==1) kq[x[i]].push_back(y[i]-n-1);
        FOR(i,1,n)
        {
            for(int j: kq[i]) cout << j << ' '; cout << "0\n";
        }
    }
}

int 	main()
{
	freopen("pviec.inp","r",stdin);
	freopen("pviec.out","w",stdout);

	enter();
	solve();

	return 0;
}
