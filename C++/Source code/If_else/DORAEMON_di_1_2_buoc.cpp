#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//Lời giải
	int n, m, temp;
	cin >> n >> m;

	if(n % 2 == 0) temp = n/2;
	else temp = n/2 + 1;

	if(temp % m == 0) cout << temp;
	else{
		int res = (temp/m + 1) * m;
		if(res < n) cout << res;
		else cout << -1;
	}
	//Công thức [min, max] => tìm k >= min sao cho chia hết cho m ([n/2; n])
	//==> (min + m - 1)/m * m;
	// kt xem giá trị ct có nằm trong khoảng min max ko

}
