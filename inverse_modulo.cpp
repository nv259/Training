#include	<bits/stdc++.h>
#define ll long long

using namespace std;
//////////////////////////
const 	ll MOD = 1e9+7;

ll		power(ll a, ll b, ll MOD){
	if (b == 1) return a%MOD;
	if (b == 0) return 1;
	ll	temp = power(a, b/2, MOD);
	return (b&1)? ((temp*temp)%MOD*a)%MOD : (temp*temp)%MOD;
}

ll		lcm(ll a, ll b){
	return a / __gcd(a, b) * b; 
}

void	process(){	
	int 	test, n;
	scanf("%d", &test);

	ll		p;

	while (test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &p);

		for (int i = 1; i < n; i++) cout << "1 ";

		ll	m = lcm(p - 1, MOD - 1);
		ll	k = ((p - 1)*power(m%p, p-2, p)) % MOD;

		cout << power(n-1, (1 + k*m)/p, MOD)%MOD << "\n";
	}
}

int main(){
	//freopen("a.inp","r",stdin);

	process();

	return 0;
}