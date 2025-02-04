#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b; cin >> a >> b;
	
	//Số lớn nhất <=a chia hết b
	cout << a/b*b << endl;

	//Số bé nhất >= a chia hết b 20 vs 3 và 21 vs 3
	//Cách 1:
	if(a % b == 0) cout << a;
	else cout << (a/b+1)*b << endl;

	//Cách 2: Công thức
	cout << (a-b+1)/b*b << endl;	
}
