#include    <bits/stdc++.h>
#define ll long long

using namespace std;
//////////////////////////
const   int N = 6e3+5;

int     n, m, k;
ll      a[N], sum[N], dp[N][N];
bool    avail[N][N];

void    read(ll &x){
    bool    negative = false;
    x = 0;
    register char c;
    c = getchar();
    if (c == '-') 
    {
        negative = true;
        c = getchar();
    }
    for (; c >= '0' && c <= '9'; c = getchar()) 
        x = (x << 1) + (x << 3) + c - '0';
    if (negative) x = -x;
}

void    enter(){
    scanf("%d%d%d\n", &n, &m, &k);
    for (int i = 1; i <= n; i++) 
    {
        read(a[i]);
        sum[i] = sum[i-1] + a[i];
    }
}

ll      get(int cnt, int pos){
    if (cnt == 0) return 0;
    if (avail[cnt][pos]) return dp[cnt][pos];
    avail[cnt][pos] = true;
    if (cnt == 1) return dp[cnt][pos] = sum[pos+m-1] - sum[pos-1];
    for (int i = pos+m; i <= n; i++)
        dp[cnt][pos] = max(dp[cnt][pos], get(cnt-1, i) + sum[pos+m-1] - sum[pos-1]);
    return dp[cnt][pos];
}

void    solve(){
    ll  res = -INFINITY;
    for (int i = 1; i <= n - (m*k) + 1; i++) 
        res = max(res, get(k, i));
    cout << res;
}

int main(){
    //freopen("a.inp","r",stdin);

    enter();
    solve();

    return 0;
}