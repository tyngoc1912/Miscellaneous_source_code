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

   int k2, k3, k5, k6, min1, min2;
   cin >> k2 >> k3 >> k5 >> k6;
   min1 = min({k2, k5, k6});
   k2 = k2 - min1;
   if(k2 <= 0) cout << min1 * 256;
   else{
   		min2 = min(k2, k3);
   		cout << min1 * 256 + min2 * 32;
   	}
}
