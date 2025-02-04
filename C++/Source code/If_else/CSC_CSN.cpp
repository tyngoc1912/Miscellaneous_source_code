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

   cấp số cộng
   int n, u1, d; cin >> n >> u1 >> d;
   cout << 1ll * (n/2 * (2*u1 + (n-1)*d)) << endl;

   cấp số nhân
   int a, b, c, d; cin >> a >> b >> c >> d;
   int q = b/a;
   if(b * q == c && c * q == d) cout << "YES";
   else cout << "NO";
}
