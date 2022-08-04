#include	<bits/stdc++.h>
#define ll long long 
#define MOD 123456789

using namespace std;
////////////////////////

ll 	power(int a, ll b){
	if (b == 0) return 1;
	if (b == 1) return a;
	ll 	temp = power(a, b/2)%MOD;
	return (b&1)? ((temp*temp)%MOD*a)%MOD : (temp*temp)%MOD;
}

int main(){
	ll 	n;
	cin >> n;
	cout << power(2, n-1)%MOD;

	return 0;
}
