#include    <bits/stdc++.h>
#define ll long long

using namespace std;
//////////////////////

int     n, k, cnt, s[50], c[50][50], d[50];
ll      gt[50], f[50][50];

void    init(){
    //gt[0] = 1;
    //for (int i = 1; i <= 35; i++) gt[i] = gt[i-1]*i;

    //for (int i = 1; i <= 35; i++) 
        //for (int j = 1; j < i; j++) f[i][j] = f[i-1][j] + gt[i-1] / (gt[i-j-1]*gt[j]);

    for (int i = 0; i <= 35; i++) c[0][i] = 1;

    for (int j = 1; j <= 35; j++)
        for (int i = 1; i <= 35; i++) c[i][j] = c[i-1][j-1] + c[i][j-1];
}

ll      convert(int pos, int p){
    if (p < 0) return 0;
    if (!pos) return (p == 0)? 1 : 0;
    if (s[pos] == 0) return convert(pos-1, p-1);
    else    
    {
        ll  tmp = convert(pos-1, p);
        if (p) tmp += c[p-1][pos-1];
        return tmp;
    }
}

ll      calc(){
    if (n > 31) return 0;
    if (!n) if (k == 1) return 1; else return 0;

    int tmp = n;    cnt = 0;
    while (tmp)
    {
        s[++cnt] = tmp % 2;
        tmp /= 2;
    }

    ll  answer = 0;
    for (int i = 2; i < cnt; i++) answer += c[k][i-1];
    answer += convert(cnt-1, k);
    if (k == 1) answer++;
    return answer;
}

void    solve(){
    while (true)
    {
        scanf("%d%d", &n, &k);
        if (!n && !k) return;
        cout << calc() << "\n";
    }
}

int main(){
    freopen("soluong.inp","r",stdin);
    freopen("soluong.out","w",stdout);
    //freopen("a.inp","r",stdin);

    init();
    solve();

    return 0;
}