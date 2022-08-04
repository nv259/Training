#include    <bits/stdc++.h>

using namespace std;
///////////////////////

const   int N = 1e5+5;
int     a[N], b[N], n, res;

void    enter(){
    cin >> n;
    for (int i = 1; i <= n; i++) 
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) 
        scanf("%d", &b[i]), b[i] += a[i];
}

void    solve(){
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    priority_queue <int, vector<int>, greater<int> > st;

    for (int i = 1; i <= n; i++)
    {
        st.push(b[i]);
        while (st.size() && st.top() <= a[i]) st.pop();
        res = max(res, (int) st.size());
    } 

    cout << res;
}

int main(){
    freopen("a.inp","r",stdin);

    enter();
    solve();

    return 0;
}