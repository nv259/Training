#include	<bits/stdc++.h>

using namespace std;
///////////////////////

const	int mn = 1e6+5, oo = 2e9;

int 	l, r, n, m, s, t, v_edge, MaxFlow,
		trace[mn], queue_[mn], c[mn], f[mn], d[mn], Edge_chosen[mn];
vector <pair <int, int> > a[mn];

void    Add_Edge(int u, int v, int cc)
{
    c[++v_edge]= cc;
    a[u].push_back(make_pair(v, v_edge));
    a[v].push_back(make_pair(u,-v_edge));
}

void	enter(){
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= n; i++) 
	{
		int 	c;
		scanf("%d", &c);
		Add_Edge(i, i+n, c);
	}
	for (int i = 1; i <= m; i++)
	{
		int 	u, v;
		scanf("%d%d", &u, &v);
		Add_Edge(u+n, v, oo);
        Add_Edge(v+n, u, oo);
	}
}

bool    FindPath()
{
    l=1,r=1;
	for (int i = 1; i <= n*2; i++) trace[i]=d[i]= 0;
    trace[s+n]= d[s+n]= 2e9;
    queue_[1]= s+n;

    while (l<=r)
    {
        int u= queue_[l++];
        if (u==t) return 1;
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
    int v=t, i, Flow= d[t];
    while (v!=s+n)
    {
        i= Edge_chosen[v];
        if (i>0) f[i]+= Flow; else f[-i]-= Flow;
        v= trace[v];
    }
    MaxFlow+= Flow;
}

int main(){
	freopen("mafia.inp","r",stdin);
	freopen("mafia.out","w",stdout);
	//freopen("a.inp","r",stdin);
    
	enter();
    while (FindPath()) IncFlow();
    //cout << MaxFlow << "\n";
    if (MaxFlow > min(c[s], c[t])) 
    {
        if (c[s] < c[t]) cout << s; 
        else cout << t;
        return 0;
    }
    for (int i = 1; i <= n; i++) 
        if ((trace[i] && !trace[i+n]) || (!trace[i] && trace[i+n]))
            if (i!=t && i!=s) cout << i << ' ';

	return 0;
}