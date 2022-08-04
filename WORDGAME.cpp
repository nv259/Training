#include<bits/stdc++.h>
#define mino "wordgame"

#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define Down(i,a,b) for(int i=a; i>=b; i--)
#define FOR_(i,a,b) for(int i=a; i<b; i++)

#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e9

const int N = 105;

using namespace std;

typedef pair<int,int> pii;


int m, n, q, r[2*N], nx[2*N][30], D;
ll sum[N][N], dp[N][N][2*N];
char c[N][N];
vector <int> pre[2*N][30];
string S;

int main()
{
    turbo
    cin >> m >> n >> D;
    cin >> S;
    q = S.size();
    S = ' ' + S;

    int k = 0;
    FOR(i,2,q)
    {
        while( k > 0 && S[k+1] != S[i] ) k = r[k];
        if( S[k+1] == S[i] ) k++;
        r[i] = k;
    }

    FOR_(i,0,q)
    {
        FOR(j,0,25)
        {
            int k = i;
            while( k > 0 && S[k+1] - 'A' != j ) k = r[k];
            if( S[k+1] - 'A' == j ) k++;
            nx[i][j] = k;
            pre[k][j].pb(i);
        }
    }

    dp[0][1][0] = 1;
    sum[0][1] = 1;
    FOR(i,1,m)
    {
        FOR(j,1,n)
        {
            cin >> c[i][j];

            sum[i][j] = (sum[i-1][j] + sum[i][j-1]) % D;

            FOR_(k,0,q)
            {
                for(int t : pre[k][c[i][j]-'A'])
                {
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][t]) % D;
                    dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][t]) % D;
                }
            }
        }
    }

    ll res = 0;
    FOR_(i,0,q) res = (res + dp[m][n][i]) % D;
    res = (sum[m][n] - res + D) % D;
    cout << res;
}
    