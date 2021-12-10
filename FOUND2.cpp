#include    <bits/stdc++.h>

using namespace std;
////////////////////////

const   int N = 1e5+5;

int     n, m, a[N];
set <int> St;
map <int, int> M;

void    enter(){
    int     x;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        M[x]++;
        //St.insert(x);
    }
}

void    solve(){
    int     x;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &x);
        //if (St.find(x) != St.end()) cout << 1 << "\n";
        //else cout << 0 << "\n";
        map <int, int> :: iterator it = M.find(x);
        if (it != M.end()) cout << M.find(x)->second << "\n";
        else cout << 0 << "\n";
    }
}

int main(){
    freopen("found2.inp","r",stdin);
    freopen("found2.out","w",stdout);
    //freopen("a.inp","r",stdin);

    enter();
    solve();

    return 0;
}