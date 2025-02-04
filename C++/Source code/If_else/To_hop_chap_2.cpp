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

   //Tổ hợp chập 2 của n
   int n; cin >> n;
   cout << 1ll * n/2 * (n - 1) << endl;
}
