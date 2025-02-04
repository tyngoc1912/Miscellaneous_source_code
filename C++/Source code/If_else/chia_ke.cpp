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

   int a1, a2, a3, b1, b2, b3, ke1, ke2; 
   int n;
   cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
   cin >> n;

   int so_cup = a1 + a2 + a3;
   int so_hc = b1 + b2 + b3;
   if(so_cup % 5 == 0) ke1 = so_cup/5;
   else ke1 = so_cup/5 + 1;
   if(so_hc % 10 == 0) ke2 = so_hc/10;
   else ke2 = so_hc/10 + 1;
   if(ke1 + ke2 <= n) cout << "YES";
   else cout << "NO";
}
