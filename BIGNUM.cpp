// BIGNUM

#include    <bits/stdc++.h>

using namespace std;
//////////////////////////

vector <int> a, b;
char    s[1001], t[1001];

void    init(char s[], vector <int> &x) {
    int len = strlen(s + 1);

    for (int i = len; i >= 1; i--)
        x.push_back(s[i] - '0');
}

void    balance(vector <int> &a, vector <int> &b) {
    while (a.size() < b.size()) a.push_back(0);
    while (b.size() < a.size()) b.push_back(0);
}

int     compare(vector <int> a, vector <int> b) {
    for (int i = (int) a.size() - 1; i >= 0; i--)
    {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}

void    print(vector <int> c) {
    while (c.size() > 1 && c[(int) c.size() - 1] == 0) c.pop_back();

    if (c[0] == 250903) cout << '-';
    for (int i = (int) c.size() - 1; i >= 0; i--) 
        if (c[i] != 250903) cout << c[i];
    cout << "\n"; 
}

vector <int> add(vector <int> a, vector <int> b) {
    vector <int> c;
    int remem = 0;

    for (int i = 0; i < (int) a.size(); i++)
    {
        c.push_back((a[i] + b[i] + remem) % 10);
        remem = (a[i] + b[i] + remem) / 10;
    }
    if (remem) c.push_back(remem);

    return c;
}

void    change(vector <int> &a, vector <int> &b) {
    for (int i = (int) a.size() - 1; i >= 0; i--) swap(a[i], b[i]);
}

vector <int> subtract(vector <int> a, vector <int> b) {
    vector <int> c;
    if (compare(a, b) == -1) c.push_back(250903), change(a, b);
    int remem = 0;

    for (int i = 0; i < (int) a.size(); i++)
    {
        int temp = a[i] - b[i] - remem;
        if (temp < 0) 
            temp += 10, remem = 1;
        else remem = 0;
        c.push_back(temp);
    }
    if (remem) c.push_back(remem);

    return c;
}

vector <int> multiply(vector <int> a, vector <int> b) {
    vector <int> c; c.push_back(0);
    
    for (int i = 0; i < (int) a.size(); i++)
    { 
        int remem = 0;
        vector <int> tempC;
        for (int j = 0; j < i; j++) tempC.push_back(0);

        for (int j = 0; j < (int) b.size(); j++) 
        {
            int temp = a[i] * b[j] + remem;
            tempC.push_back(temp % 10);
            remem = temp / 10;
        }
        if (remem) tempC.push_back(remem);
        balance(c, tempC);

        c = add(c, tempC);   
    }

    return c;
}

int main(){
    scanf("%s\n%s", s + 1, t + 1);
    
    init(s, a);
    init(t, b);
    balance(a, b);

    vector <int> ans;

    ans = add(a, b); print(ans);
    ans = subtract(a, b); print(ans);
    ans = multiply(a, b); print(ans);

    return 0;
}