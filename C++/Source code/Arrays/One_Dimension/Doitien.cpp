#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <ctype.h>
#include <stdlib.h>
#include <climits>
using namespace std;
using ll = long long; 

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	ll n; cin >> n;
	//Làm tay
	// ll t1000=0, t500=0, t200=0, t100=0, t50=0, t20=0, t10=0, t5=0, t2=0, t1=0;
	// t1000 = n/1000; n %= 1000;
	// t500 = n/500; n %= 500;
	// t200 = n/200; n %= 200;
	// t100 = n/100; n %= 100;
	// t50 = n/50; n %= 50;
	// t20 = n/20; n %= 20;
	// t10 = n/10; n %= 10;
	// t5 = n/5; n %= 5;
	// t2 = n/2; n %= 2;
	// t1 = n/1; n %= 1;
	// cout << t1000 + t500 + t200 + t100 + t50 + t20 + t10 + t5 + t2 + t1 << endl;

	//Dùng mảng
	int res = 0, a[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
	for(int i = 0; i < 10; i++){
		if(n != 0){
			res = res + n / a[i];
			n %= a[i];
		}
		else break;
	}
	cout << res << endl;
}
