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
   int a, b, c, n, res; cin >> a >> b >> c >> n;
   //C1
   if(n >= a && n >= b && n >= c && (a + b + c + n)/3 % 3 == 0) cout << "YES";
   else cout << "NO";

   //C2
   res = (a + b + c + n)/3;
   if(res % 3 == 0 && res >= a && res >= b && res >= c) cout << "YES";
   else cout << "NO";

}
