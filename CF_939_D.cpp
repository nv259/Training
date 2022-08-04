#include    <bits/stdc++.h>

using namespace std;
///////////////////////
const   int N = 5e5+5;
int     n, cnt, par[N];
char    s[N], p[N];
pair <char, char> ans[N];

void    enter(){
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", p);
}

int     root(int x){
    return (par[x] < 0) ? x : par[x] = root(par[x]);
}

void    _union(int x, int y){
    if (par[y] < par[x]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

void    solve(){
    for (int i = 0; i <= 26; i++) par[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int     x, y;
        x = root(s[i] - 'a');
        y = root(p[i] - 'a');
        if (x == y) continue;
        ans[++cnt] = { s[i], p[i] };
        _union(x, y);
    }

    cout << cnt << "\n";
    for (int i = 1; i <= cnt; i++) 
        cout << ans[i].first << " " << ans[i].second << "\n";
}

int main(){
    //freopen("a.inp","r",stdin);

    enter();
    solve();

    return 0;
}