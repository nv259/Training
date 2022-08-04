#include	<bits/stdc++.h>

using namespace std;
////////////////////////

const	int N = 46;

int 	a[N], b[N];
// 	a[i] la do dai cua F[i]
// 	b[i] la so chu so a cua do dai i

void	init(){
	a[0] = a[1] = 1;
	b[0] = 1;	b[1] = 0;
	
	for (int i = 2; i <= N; i++) 
	{
		a[i] = a[i-2] + a[i-1];
		b[i] = b[i-2] + b[i-1];
	}
}

int 	answer(int n, int k){
	if (k == 0) return 0;
	if (n <= 1) return b[n];
	if (a[n-2] >= k) return answer(n-2, k);
	return b[n-2] + answer(n-1, k-a[n-2]);
}

int main(){
	freopen("a.inp","r",stdin);

	init();

	int 	t, n, k;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &k);
		cout << answer(n, k) << "\n";
	}

	return 0;
}