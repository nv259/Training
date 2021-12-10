#include    <bits/stdc++.h>
#define X first
#define Y second
#define ll long long

using namespace std;
/////////////////////////

const   int N = 1e6+5;

typedef pair <int, int> ii;

ii      land[N], meteor[N], lower_line[N], upper_line[N];
int     n, m, top_upper, top_lower;

void    enter(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &land[i].X, &land[i].Y);
    ///////////////////
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d%d", &meteor[i].X, &meteor[i].Y);
}

bool    cmp(ii a, ii b){
    return a.X < b.X || a.X == b.X && a.Y < b.Y;
}

ll      area(ii a, ii b, ii c){
    return  1LL*(b.X - a.X)*(b.Y + a.Y) +
            1LL*(c.X - b.X)*(c.Y + b.Y) +
            1LL*(a.X - c.X)*(a.Y + c.Y) ;
}

bool    ccw(ii a, ii b, ii c){
    return area(a, b, c) < 0;
}

void    divide(){
    /*int     left = min_element(land+1, land+n+1, [] (ii a, ii b){
                            return a.X < b.X || a.X == b.X && a.Y < b.Y; }) - land;
    int     right = max_element(land+1, land+n+1, [] (ii a, ii b){
                            return a.X < b.X || a.X == b.X && a.Y < b.Y; }) - land;
    swap(land[1], land[left]);
    swap(land[n], land[right]);*/

    sort(land+1, land+n+1, cmp);

    lower_line[1] = upper_line[1] = land[1];
    top_upper = top_lower = 1;
    //////////////////
    for (int i = 2; i < n; i++) 
    {
        if (ccw(land[1], land[i], land[n])) lower_line[++top_lower] = land[i];
        else upper_line[++top_upper] = land[i];
    }
    //////////////////
    lower_line[++top_lower] = upper_line[++top_upper] = land[n]; 
}

void    solve(){    
    for (int i = 1; i <= m; i++)
    {
        int     pos_lower = lower_bound(lower_line+1, lower_line+top_lower+1, meteor[i], cmp) - lower_line;
        int     pos_upper = lower_bound(upper_line+1, upper_line+top_upper+1, meteor[i], cmp) - upper_line;
        
        // diem nam ngoai hai ben ria trai va ria phai
        if (pos_lower == 1 || pos_upper == 1) { cout << "NO\n"; continue; }
        if (land[n].X <= meteor[i].X) { cout << "NO\n"; continue; }

        if (area(lower_line[pos_lower-1], meteor[i], lower_line[pos_lower]) * 
            area(upper_line[pos_upper-1], meteor[i], upper_line[pos_upper]) < 0 ) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(){
    freopen("meteor.inp","r",stdin);
    freopen("meteor.out","w",stdout);

    enter();
    divide();
    solve();

    return 0;
}