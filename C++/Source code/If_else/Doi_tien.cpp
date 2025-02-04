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

   int n; cin >> n;
   //1, 5, 10, 20, 100
   cout << (n/100) + (n % 100 / 20) + (n % 100 % 20 / 10) + (n % 100 % 20 % 10 / 5) + (n % 100 % 20 % 10 % 5);

}
