#include    <bits/stdc++.h>
#define ULL unsigned long long
#define ll long long

using namespace std;
///////////////////////////

ULL     a, b, k;

ULL     mulmod(ULL a, ULL b, ULL m) {
    if (!a || !b) return 0;
    if (b == 1) return a%m;
    
    ULL     t = mulmod(a, b/2, m);
    return (b&1)? ((t+t)%m+a)%m : (t+t)%m;
}

ULL     pm(ULL a, ULL e, ULL m) {
	if (e == 1) return a%m;
    if (!e) return 1;

    ULL     t = pm(a, e/2, m);
    return (e&1)? mulmod(mulmod(t, t, m), a, m) : mulmod(t, t, m);
}

int main(){
    freopen("digit.inp","r",stdin);
    freopen("digit.out","w",stdout);
    //freopen("a.inp","r",stdin);

    scanf("%lld%lld%lld", &a, &b, &k);

    ULL  x = pm(10, k-1, b);
    ULL  y = mulmod(a%b, x, b);

    cout << y*10/ b;

    return 0;
}