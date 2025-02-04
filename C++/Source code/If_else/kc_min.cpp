#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;

int main(){
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

   int d1, d2, d3; cin >> d1 >> d2 >> d3;
   int kc1 = d1 + d2 + d3;
   int kc2 = 2 * (d1 + d2);
   int kc3 = 2 * (d1 + d3);
   int kc4 = 2 * (d2 + d3);

   // C1
   cout << min({kc1, kc2, kc3, kc4}) << endl;

   //C2
   int min = kc1;
   if(kc2 < min) min = kc2;
   if(kc3 < min) min = kc3;
   if(kc4 < min) min = kc4;
   cout << min << endl;

}
