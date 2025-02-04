#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, a; cin >> n >> m >> a;
	int x, y;

	if(n % a == 0) x = n/a;
	else x = n/a + 1;
	if(m % a == 0) y = m/a;
	else y = m/a + 1;
	cout << 1ll * x * y;

	//tính xem số hàng và số cột chia cho a có bị lẻ hay ko, nếu có thì số lượng viên gạch + 1
}
