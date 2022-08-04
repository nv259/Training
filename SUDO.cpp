#include    <bits/stdc++.h>

using namespace std;
//////////////////////

int     a[10][10];
bool    check, row[10][10], col[10][10], box[4][4][10];

void    enter(){
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j])
            {
                row[i][a[i][j]] = true;
                col[j][a[i][j]] = true;
                box[(i-1)/3][(j-1)/3][a[i][j]] = true;
            }
        }
}

void    print(){
    for (int i = 1; i <= 9; i++) 
    {
        for (int j = 1; j <= 9; j++) cout << a[i][j] << " ";
        cout << "\n";
    }
    check = true;
}

void    dq(int i, int j){
    if (check) return;
    if (a[i][j])
    {
        if (j <= 8) dq(i, j+1);
        else if (i <= 8) dq(i+1, 1);
        else print();
        return; 
    }

    for (int k = 1; k <= 9; k++)
        if (!row[i][k] && !col[j][k] && !box[(i-1)/3][(j-1)/3][k]) 
        {
            a[i][j] = k;
            row[i][k] = true;
            col[j][k] = true;
            box[(i-1)/3][(j-1)/3][k] = true;

            if (j <= 8) dq(i, j+1);
            else if (i <= 8) dq(i+1, 1);
            else print();
            
            a[i][j] = 0;
            row[i][k] = false;
            col[j][k] = false;
            box[(i-1)/3][(j-1)/3][k] = false;
        }
}

int main(){
    freopen("a.inp","r",stdin);
    
    enter();
    dq(1, 1);
    if (!check) cout << -1;
    
    return 0;
}