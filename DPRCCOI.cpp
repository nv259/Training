#include    <bits/stdc++.h>
#define ll long long

using namespace std;
//////////////////////
const   int N = 2e6+5;

ll  dp[N];
bool    avail[N];

ll      get(int x){
    if (x < 4) return x;
    if (x <= N) 
    {
        if (avail[x]) return dp[x];
        avail[x] = true;
        dp[x] = x;
        dp[x] = max(dp[x], get(x/2) + get(x/3) + get(x/4));
        return dp[x];
    }
    return max(1LL*x, get(x/2) + get(x/3) + get(x/4));
}

int main(){
    int n;
    while (scanf("%d", &n) != -1)
        cout << get(n) << "\n";

    return 0;
}