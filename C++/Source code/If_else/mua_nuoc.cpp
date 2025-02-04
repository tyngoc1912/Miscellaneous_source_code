#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;

int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

   ll n; int a, b;
   cin >> n >> a >> b;
   if(2 * a > b) cout << b * n/2 + (n % 2)*a;
   else cout << a * n;
   //ko quan tâm n chẵn hay  b * n/2 + (n % 2)*a; tính theo này là mặc định đúng, chủ yếu quan tâm đơn giá
}
