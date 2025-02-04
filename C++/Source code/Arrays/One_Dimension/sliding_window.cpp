#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <utility>
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

	int n, k; cin >> n >> k;
	int a[n];
	for(int &x : a) cin >> x;
	ll sum = 0;
	for(int i = 0; i < k; i++){
		sum += a[i];
	}
	ll res = sum, pos = 0;
	for(int i = 1; i <= n - k; i++){
		sum = sum - a[i - 1] + a[i + k - 1];
		if(sum > res){ //nếu có dấu bằng là cập nhật dãy cuối cùng, còn ko có là dãy đầu 
			res = sum;
			pos = i;
		}
	}
	cout << res << endl;
	for(int i = 0; i < k; i++) cout << a[pos + i] << " ";
}
