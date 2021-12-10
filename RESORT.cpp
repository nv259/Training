#include    <bits/stdc++.h>

using namespace std;
////////////////////////////
const   int N = 5e3+5;

int     m, n, p, q, B;
int     mid, a[N][N], lower[N][N], upper[N][N];  

void    enter(){
    scanf("%d%d%d%d", &m, &n, &p, &q);
    scanf("%d", &B);
    mid = (p*q + 1)/2;
    for (int i = 1; i <= m; i++) 
        for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
}

void    solve(){
    int     res = 0;
    
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) 
        {
            upper[i][j] = upper[i-1][j] + upper[i][j-1] - upper[i-1][j-1];
            lower[i][j] = lower[i-1][j] + lower[i][j-1] - lower[i-1][j-1];
            
            if (a[i][j] > B) upper[i][j]++;
            if (a[i][j] < B) lower[i][j]++;

            if (i >= p && j >= q) 
            {
                int     Upper, Lower;
                Upper = upper[i][j] - upper[i-p][j] - upper[i][j-q] + upper[i-p][j-q];
                Lower = lower[i][j] - lower[i-p][j] - lower[i][j-q] + lower[i-p][j-q];

                if (Lower < mid) 
                    switch ((p*q)%2)
                    {    
                        case 0:
                            if (Upper <= mid) res++;
                            break;
                    
                        default:
                            if (Upper <  mid) res++;
                            break;
                    }
            }
        }
    cout << res;
}

int main(){
    freopen("resort.inp","r",stdin);
    freopen("resort.out","w",stdout);
    //freopen("a.inp","r",stdin);

    enter();
    solve();

    return 0;
}