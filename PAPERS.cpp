#include    <bits/stdc++.h>
#define ll long long

using namespace std;
///////////////////////

const   ll MOD = 1e9+7;

int     m, n;

ll      extended_euclide(ll a, ll b, ll *x, ll *y){
    if (b == 0)
    {
        *x = 1; 
        *y = 0;
        return a;
    }
    ll  x1, y1;
    ll  temp = extended_euclide(b, a%b, &x1, &y1);
    *x = y1;
    *y = x1 - (a/b)*y1;
    return temp;
}

ll      inverse_modulo_euclide(ll n){
    ll  x, y;
    if (extended_euclide(n, MOD, &x, &y) != 1) return -1;
    else return (x%MOD + MOD)%MOD;
}

ll      C(int k, int n){
    ll  gtK = 1, gtN_K = 1, gtN = 1;

    for (ll i = 2; i <= n; i++) gtN = (gtN * i)%MOD;
    for (ll i = 2; i <= n-k; i++) gtN_K = (gtN_K * i)%MOD;
    for (ll i = 2; i <= k; i++) gtK = (gtK * i)%MOD;
    ll  gtMau = (gtN_K * gtK)%MOD;

    return (gtN * inverse_modulo_euclide(gtMau))%MOD;
}

int main(){
    freopen("papers.inp","r",stdin);
    freopen("papers.out","w",stdout);
	//freopen("a.inp","r",stdin);

    cin >> m >> n;
    int     x;

    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &x);
        m -= x;
    }

    if (m < 0) cout << 0;
    else 
    if (m== 0) cout << 1;
    else cout << C(n-1, m+n-1)%MOD;

    return 0;
}