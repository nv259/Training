#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

const	int mn = 1e6+6;

long long height[mn];
int     n, st[mn], a[mn];

void	enter()
{
    cin>>n;
    FOR(i,1,n) scanf("%d", &a[i]), height[i]= height[i-1]+ a[i];;
}

int     area(long long i, long long j, long long k)
{
    long long x =
    (height[j]+height[i])*(j-i) + (height[k]+height[j])*(k-j) + (height[i]+height[k])*(i-k);
    if (x>=0) return 1; else return 0;
}

long long calc(int l, int r)
{
    long long res= (height[r]+height[l])*(1-r+l);
    FOR(i,l+1,r-1) res+= height[i]*2;
    return res;
}

void	solve()
{
    int top= 0;
    FOR(i,0,n)
    {
        while (top>=2 && area(st[top-1],st[top],i)) top--;
        st[++top]= i;
    }
    long long kq= 0;
    FOR(i,1,top-1) kq += calc(st[i], st[i+1]);
    cout << kq/2;
    if (kq%2==1) cout << ".5" ; else cout << ".0";  
}

int 	main()
{
	freopen("watermov.inp","r",stdin);
	freopen("watermov.out","w",stdout);

	enter();
	solve();

	return 0;
}