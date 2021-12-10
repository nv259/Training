#include <bits/stdc++.h>
using namespace std;

struct Equation { int64_t a, b, c; };

int64_t gcd(int64_t a, int64_t b) {
    if (!a && !b) return INT_MAX;
    if (!a) return b;
    if (!b) return a;
    if (a%b == 0) return b; else return gcd(b%a, a);
}

bool isNoSolution(Equation A) {
    return A.c % gcd(A.a, A.b);
}

void solve(Equation A, Equation B) {
    int64_t D(A.a*B.b - B.a*A.b);
    int64_t Dx(A.c*B.b - B.c*A.b);
    int64_t Dy(A.a*B.c - B.a*A.c);

    if (D) {
        if (Dx%D|| Dy%D) 
            cout << "NO SOLUTION\n";
        else 
            cout << Dx/D << ' ' << Dy/D << '\n';
    }
    else {
        if (Dx || Dy)
            cout << "NO SOLUTION\n";
        else
            cout << "INFINITE\n";
    }
}

int main() {
    freopen("INTSLE.INP", "r", stdin);
    freopen("INTSLE.OUT", "w", stdout);
    
    int n;
    scanf("%d", &n);
    
    Equation A, B;
    while (n--) {
        scanf("%lld%lld%lld", &A.a, &A.b, &A.c);
        scanf("%lld%lld%lld", &B.a, &B.b, &B.c);
        if (isNoSolution(A) || isNoSolution(B)) 
            cout << "NO SOLUTION\n";
        else 
            solve(A, B);
    }
}
