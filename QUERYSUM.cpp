#include    <bits/stdc++.h>
#define ll long long

using namespace std;
////////////////////////
const   int N = 5e5+5;
int     n, m, a[N];
ll      f[N];

void    update(int i, int k){
    while (i <= n)
    {
        f[i] += 1LL*k;
        i += (i & -i);
    }
}

ll      get(int i){
    ll  result = 0;

    while (i)
    {
        result += f[i];
        i -= (i & -i);
    }
    return result;
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
        if (c == 'S') 
        {   
            int     key = v - a[u];
            a[u] = v;
            update(u, key);
        }
        else cout << get(v) - get(u-1) << "\n";
    }

    return 0;
}