#include    <bits/stdc++.h>
#define ll long long

using namespace std;
////////////////////////
const   int N = 5e5+5;
int     n, m;
ll      st[N];

void    update(int id, int l, int r, int i, int v)
{
    if (i < l || r < i) return;
    if (l == r)
    {
        st[id] = v;
        return;
    }

    int mid = (l + r) >> 1;
    update(id*2, l, mid, i, v);
    update(id*2 + 1, mid+1, r, i, v);   
    st[id] = st[id*2] + st[id*2+1];
}

ll      get(int id, int l, int r, int i, int j)
{
    if (j < l || r < i) return 0;
    if (i <= l && r <= j) return st[id];

    int mid = (l + r) >> 1;
    return  get(id*2, l, mid, i, j) 
        +   get(id*2+1, mid+1, r, i, j);
}

int main(){
    freopen("querysum.inp","r",stdin);
    freopen("querysum.out","w",stdout);
    //freopen("a.inp","r",stdin);

    char    c;
    ll      u, v;

    scanf("%d%d\n", &n, &m);
    for (int i = 1; i <= m; i++) 
    {
        scanf("%c%d%d\n", &c, &u, &v);
        if (c == 'S') update(1, 1, n, u, v);
        else cout << get(1, 1, n, u, v) << "\n";
    }

    return 0;
}