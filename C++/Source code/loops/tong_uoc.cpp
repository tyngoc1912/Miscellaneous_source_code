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

   ll n; cin >> n;
   ll tong_uoc = 0;
   for(int i = 1; i <= sqrt(n); i++){
   		if(n % i == 0){
   			tong_uoc += i;
   			if(n/i != i) tong_uoc += n/i;
   		}
   }
   cout << tong_uoc;
}
