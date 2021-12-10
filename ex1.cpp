#include <bits/stdc++.h>

using namespace std;
////////////////////////

double  cc, dk, dt;

void process() {
  scanf("%lf%lf", &cc, &dk);
  if (cc < 5.0 or dk < 3)
  {
    cout << "CAM THI";
    return;
  }
  scanf("%lf", &dt);
  
  double  dhp = cc * 0.1 + dk * 0.3 + dt * 0.6;
  if (dhp < 4.0) cout << "F";
  else
    if (dhp <= 4.7) cout << "D";
  else 
    if (dhp <= 5.4) cout << "D+";
  else 
    if (dhp <= 6.2) cout << "C";
  else 
    if (dhp <= 6.9) cout << "C+";
  else 
    if (dhp <= 7.7) cout << "B";
  else 
    if (dhp <= 8.4) cout << "B+";
  else cout << "A";
}

int main() {
  
  process();
  return 0;
}

