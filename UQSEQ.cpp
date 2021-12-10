#include    <bits/stdc++.h>
#define ll long long

using namespace std;
//////////////////////
const   int N = 5e5+5;

struct  node{
    ll  lazy, val;
}st[N];

int     n, m;

void    down(int id){
    ll  t = st[id].lazy;

    st[id*2].val += t;
    st[id*2].lazy += t;
    st[id*2+1].val += t;
    st[id*2+1].lazy += t;

    st[id].lazy = 0;
}

void    update(int id, int l, int r, int u, int v, int delta){
    if (v < l || r < u) return;
    if (u <= l && r <= v)
    {
        st[id].lazy += 1LL*delta;
        st[id].val += 1LL*delta;
        return;
    }
    
    int mid = (l + r) >> 1;
    down(id);

    update(id*2, l, mid, u, v, delta);
    update(id*2+1, mid+1, r, u, v, delta); 
    st[id].val = st[id*2].val + st[id*2+1].val;
}

ll      get(int id, int l, int r, int u, int v){
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id].val;

    int mid = (l + r) >> 1;
    down(id);
    return  get(id*2, l, mid, u, v)
        +   get(id*2+1, mid+1, r, u, v);
}

int main(){
    freopen("uqseq.inp","r",stdin);
    freopen("uqseq.out","w",stdout);
    //freopen("a.inp","r",stdin);

    int     u, v, delta;
    char    c;
    scanf("%d%d\n", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%c", &c);
        if (c == 'I') 
        {
            scanf("%d%d%d\n", &u, &v, &delta);
            update(1, 1, n, u, v, delta);
        } else {
            scanf("%d\n", &u);
            cout << get(1, 1, n, u, u) << "\n";
        }
    }
    

    return 0;
}