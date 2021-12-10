#include    <bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define ull unsigned long long

using namespace std;
//////////////////////

typedef pair <int, int> ii;
const   int N = 1e5+5;

ii      a[N];
int     n, k;

void    enter(){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].X, &a[i].Y);
}

ull      check(ll x){
    ull  result = 0;

    for (int i = 1; i <= n; i++) 
        if (x-1LL*a[i].X >= 0) 
            result += (x-1ULL*a[i].X)/(1ULL*a[i].Y) + 1;
    return result;
};

void    solve(){
    ll  first, last, mid, ans;
    k++;
    first = 0;   last = 1e18;   
    while (first <= last)
    {
        mid = (first + last) >> 1;
        ull  sumAttacks = check(mid);
        if (sumAttacks >= k) { last = mid - 1; ans = mid; }
        else first = mid + 1;
    }
    if (check(ans-1) == k) cout << ans-1;
    else cout << ans;
}

int main(){ 
    freopen("attack.inp","r",stdin);
    freopen("attack.out","w",stdout);
    //freopen("a.inp","r",stdin);

    enter();
    solve();

    return 0;
}