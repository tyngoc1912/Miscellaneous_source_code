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

  float n; cin >> n;
  if(abs(n - int(n)) <= 0.5) cout << int(n) << endl;
  else cout << int(n) + 1 << endl;
}
