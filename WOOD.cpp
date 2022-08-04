#include    <iostream>
#define ll long long

using namespace std;
///////////////////////

const   int N = 1e5+5;
const   int K = 1e3+5;
const   int MOD = 1e9+7;

int     n, k, h[K];
ll      f[N];

void fastscan(int &number) 
{ 
    //variable to indicate sign of input number 
    bool negative = false; 
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    if (c=='-') 
    { 
        // number is negative 
        negative = true; 
  
        // extract the next character from the buffer 
        c = getchar(); 
    } 
  
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
    // if scanned input has a negative sign, negate the 
    // value of the input number 
    if (negative) 
        number *= -1; 
} 

void    enter(){    
    fastscan(n);    fastscan(k);
    scanf("\n");
    for (int i = 1; i <= k; i++) fastscan(h[i]);
}

void    solve(){
    for (int i = 1; i <= k; i++) f[h[i]] = 1;

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= k; j++)
            if (i >= h[j]) f[i] = (f[i] + f[i-h[j]])%MOD;

    cout << f[n];
}

int main(){

    enter();
    solve();

    return 0;
}