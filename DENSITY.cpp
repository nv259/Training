#include    <bits/stdc++.h>

using namespace std;
/////////////////////////
const   int N = 200;

int     n,k,p,q, a[N][N], sum[N][N];
pair <int,int>  luu[N][N];
double  f[N][N];

void    enter(){
    scanf("%d%d",&n,&k);
    char c;
    scanf("%c",&c);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            scanf("%c",&c);
            sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + (int)c - 48;
        }
        scanf("%c",&c);
    }
}

void    solve(){
    int t;
    p = 0;  q = 1;
    for (int x = 1; x <= n ; x++){
        for (int y = 1; y <= n; y++){
            for (int u = x; u <= n; u++){
                for (int v = y; v <= n; v++){
                    t = (u-x+1)*(v-y+1);
                    if (t < k) continue;
                    int b = sum[u][v] - sum[x-1][v] - sum[u][y-1] + sum[x-1][y-1];
                    if (p*1.0 / q < b*1.0 / t){
                        p = b, q = t;
                    }
                }
            }
        }
    }
    cout << p / __gcd(p,q) << "/" << q / __gcd(p,q);
}

int main()
{
    freopen("DENSITY.inp","r",stdin);
    freopen("DENSITY.out","w",stdout);
    //freopen("a.inp","r",stdin);
    
    enter();
    solve();

    return 0;
}

