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

   int n; ll s;
   cin >> n >> s;
   if(s % n == 0) cout << s/n;
   else cout << s/n + 1;

}
