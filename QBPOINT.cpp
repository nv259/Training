#include    <bits/stdc++.h>
#define ii pair<int, int>

using namespace std;
/////////////////////////////////

const   int N = 2020;

int     n,re,m,a[N],b[N];
ii      c[2020];

bool cmp(ii i,ii j){
	return i.second*j.first<i.first*j.second;	
}
	
int main()
{
    freopen("qbpoint.inp","r",stdin);
    freopen("qbpoint.out","w",stdout);

	int     n,x,y;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	for (int i = 0; i < n; i++)
	{
		m = 0;
	
		for (int j = 0; j < n; j++)
		{
			x = a[j]-a[i];
			y = b[j]-b[i];

			if (y < 0 || (y == 0 && x <= 0)) continue;
			c[m++] = make_pair(x,y);
		}
	
		if (!m) continue;

		sort(c, c+m, cmp);

		int cur = 1;

		for (int i = 1;i < m; i++)
			if (!cmp(c[i],c[i-1]) && !cmp(c[i-1],c[i])) re += cur++;
			else cur = 1;
	}
	cout << re << endl;

    return 0;
}