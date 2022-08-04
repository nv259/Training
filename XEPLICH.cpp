#include	<bits/stdc++.h>

using namespace std;
//////////////////////

int 	n, k, a[200][200], f[200][200];

void	enter(){
	cin >> k >> n;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++) cin >> a[i][j];
}

void	solve(){
	for (int i = 1; i <= k; i++) 
		for (int j = i; j <= n; j++) f[i][j] = max(f[i][j-1], f[i-1][j-1] + a[i][j]);
	cout << f[k][n];
}

int main(){
	freopen("a.inp","r",stdin);

	enter();
	solve();

	return 0;
}