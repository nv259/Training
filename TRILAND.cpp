#include <bits/stdc++.h>

#define FOR(i,a,b) for( int i=(a), _b=(b); i<=_b; i++)
#define FORD(i,a,b) for( int i=(a), _b=(b); i>=_b; i--)

using namespace std;

const	int mn = 3e5+5;
struct  pt{
    int x,y;
}   a[mn],d[mn];
int     n;

void	enter()
{
    cin >> n;
    FOR(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
}

long long    turn(pt a, pt b, pt c)
{
    return 1LL*(b.x-a.x)*(b.y+a.y) + 1LL*(c.x-b.x)*(c.y+b.y)
    + 1LL*(a.x-c.x)*(a.y+c.y);
}
long long    area(pt a, pt b, pt c)
{
    return abs(turn(a,b,c));
}

void	solve()
{
    int mi = min_element(a+1,a+1+n,[] (pt a, pt b) {
                        return a.y < b.y || (a.y==b.y && a.x<b.x);}) - a;
    swap(a[mi],a[1]);
    sort(a+2,a+1+n,[] (pt x, pt y) {
                        return turn(y,a[1],x)<0;});
    int top=0;
    FOR(i,1,n)
    {
        while (top>=2 && turn(d[top-1],d[top],a[i])>=0) top--;
        d[++top]=a[i];
    }
    long long res = 0; n = top;
    FOR(i,1,n-2)
    {
        int k=i+1;
        FOR(j,i+2,n)
    //FOR(i,1,n-2)
        {
            while (area(d[i],d[k+1],d[j])>area(d[i],d[k],d[j])) k++;
            res=max(res,area(d[i],d[k],d[j]));
        }
    }
    cout << res/2;
    if (res%2==0) cout<<".0"; else cout <<".5";
}
 
int 	main()
{
    freopen("a.inp","r",stdin);

	enter();
	solve();

	return 0;
}