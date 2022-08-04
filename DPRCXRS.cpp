#include    <bits/stdc++.h>
#define ll long long

using namespace std;
//////////////////////
const   ll MOD = 1e9+7;
const   int N = 100;

int     nA, nB, nQ;
char    a[N], b[N], question[N];
bool    avail[N][N][N];
ll      dp[N][N][N];

ll      get(int pos, int posA, int posB){
    if (pos > nQ) return 1;
    if (avail[pos][posA][posB]) return dp[pos][posA][posB];
    avail[pos][posA][posB] = true;
    for (int i = posA; i <= nA; i++)
        if (question[pos] == a[i]) 
            dp[pos][posA][posB] = (dp[pos][posA][posB] + get(pos+1, i+1, posB)) % MOD;
    for (int j = posB; j <= nB; j++) 
        if (question[pos] == b[j])
            dp[pos][posA][posB] = (dp[pos][posA][posB] + get(pos+1, posA, j+1)) % MOD;
    return dp[pos][posA][posB]%MOD;
}

int main(){
    //freopen("a.inp","r",stdin);
    
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%s %s %s\n", a+1, b+1, question+1);
        nA = strlen(a+1);
        nB = strlen(b+1);
        nQ = strlen(question+1);
        for (int i = 1; i <= 66; i++)
            for (int j = 1; j <= 66; j++)   
                for (int k = 1; k <= 66; k++)   
                {
                    avail[i][j][k] = false;
                    dp[i][j][k] = 0;
                }
        cout << get(1, 1, 1) << "\n";
    }

    return 0;
}