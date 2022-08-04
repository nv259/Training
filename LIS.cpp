#include    <bits/stdc++.h>

using namespace std;
//////////////////////////

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("a.inp","r",stdin);

    int n;  
    cin >> n;
    vector <int> a(n);
    for (int &i : a) cin >> i;
    vector <int> b(n, INFINITY);
    int ans = 0;

    for (int i = 0; i < n; i++) 
    {
        int k = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        ans = max(ans, k);
        b[k] = a[i];
    }
    cout << ans + 1;

    return 0;
}