#include    <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
//////////////////////

const   int N = 1e6+5;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

int     n, q, S, cnt[N], a[N];
iii     e[N];
ii      ans;
set <int> s[N], result[N];

void    enter(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d", &e[i].X.X, &e[i].X.Y);
        e[i].Y = i;
    }
}

//  sort theo block
/// neu hai truy van thuoc cung mot block -> sort theo R
/// neu hai truy van khac block -> sort theo block

bool    cmp(iii a, iii b){
    if (a.X.X / S != b.X.X / S)
        return a.X.X / S < b.X.X / S;
    return a.X.Y < b.X.Y;
}

void    push(int a){
    s[cnt[a]].erase(a);
    cnt[a]++;
    s[cnt[a]].insert(a);
    if (cnt[a] >= ans.Y) { ans.Y = cnt[a]; ans.X = a; }
}

void    pop(int a){
    if (cnt[a] == 0) return;
    s[cnt[a]].erase(a);
    cnt[a]--;
    s[cnt[a]].insert(a);
    while (!s[ans.Y].size()) ans.Y--;
}

void    solve(){
    S = sqrt(n);
    sort(e+1, e+q+1, cmp);

    int     L = e[1].X.X, R = e[1].X.X-1;
    for (int i = 1; i <= q; i++){
        while (R > e[i].X.Y) pop(a[R--]);
        while (L > e[i].X.X) push(a[--L]);
        while (L < e[i].X.X) pop(a[L++]);
        while (R < e[i].X.Y) push(a[++R]);
        result[e[i].Y] = s[ans.Y];
    }

    for (int i = 1; i <= q; i++)
    {
        for (set <int> :: iterator it = result[i].begin(); it != result[i].end(); it++)
            cout << *it << " ";
        cout << "\n";
    }
}

int main(){
    freopen("a.inp","r",stdin);
    //freopen("a.out","w",stdout);

    enter();
    solve();

    return 0;
}
