#include    <bits/stdc++.h>
#define ll long long
#define X first
#define Y second

using namespace std;
///////////////////////////

typedef pair <ll, ll> l2;

ll  n, a;
vector <l2> ans;

ll      power(ll a, int b){
    if (b == 0) return 1;
    ll  temp = power(a, b/2);
    return (b&1)? temp*temp*a : temp*temp;
}

bool    check(int i){
    int     first = 1, last = log2(n) / log2(i);
    
    while (first <= last)
    {
        ll  mid = (first + last) >> 1;
        ll  ApowerB = power(mid, i);
        if (ApowerB == n) { a = mid; return true; } 
        if (ApowerB > n) last = mid - 1;
        else first = mid + 1;
    }
    return false;

}

int main(){ 
    freopen("power.inp","r",stdin);
    freopen("power.out","w",stdout);
    //freopen("a.inp","r",stdin);

    cin >> n;
    if (n <= 2) { cout << 0; return 0; }
    for (int b = 2; b <= 60; b++) 
        if (check(b)) ans.push_back({a, b}); 

    cout << ans.size() << "\n";
    for (l2 &x : ans)
        cout << x.X << " " << x.Y << "\n"; 

    return 0;
}