#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	//GIAO HOP THEO VECTOR --> du lieu phai dep
	// int m, n; cin >> m >> n;
	// int a[m], b[n];
	// for(int &x : a) cin >> x;
	// for(int &x : b) cin >> x;
	// vector<int> giao, hop;
	// int i = 0, j = 0;
	// while(i < m && j < n){
	// 	if(a[i] == b[j]){
	// 		giao.push_back(a[i]);
	// 		hop.push_back(a[i]);
	// 		i++; j++;
	// 	}
	// 	else if(a[i] < b[j]){
	// 		hop.push_back(a[i]);
	// 		i++;
	// 	}
	// 	else if(a[i] > b[j]){
	// 		hop.push_back(b[j]);
	// 		j++;
	// 	}
	// }
	// while(i < m){
	// 	hop.push_back(a[i]);
	// 	i++;
	// }
	// while(j < n){
	// 	hop.push_back(b[j]);
	// 	j++;
	// }
	// for(int x : giao) cout << x << ' '; 
	// cout << endl;
	// for(int x : hop) cout << x << ' ';

	//GIAO HOP THEO SET 1
	// int m, n;
	// set<int> a, b, hop;
	// cin >> m >> n;
	// for(int i = 0; i < m; i++){
	// 	int temp; cin >> temp;
	// 	a.insert(temp);
	// }
	// for(int i = 0; i < n; i++){
	// 	int temp; cin >> temp;
	// 	b.insert(temp);
	// }
	// vector<int> giao;
	// for(int x : a){
	// 	hop.insert(x);
	// 	if(b.count(x)) giao.push_back(x);
	// }
	// for(int x : b){
	// 	hop.insert(x);
	// }
	// for(int x : giao) cout << x << ' ';
	// cout << endl;
	// for(int x : hop) cout << x << ' ';

	//GIAO HOP THEO SET 2
	int m, n;
	set<int> a, hop;
	vector<int> giao;
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		int temp; cin >> temp;
		hop.insert(temp);
		a.insert(temp);
	}
	for(int i = 0; i < n; i++){
		int temp; cin >> temp;
		hop.insert(temp);
		if(a.count(temp) != 0) giao.push_back(temp);
	}
	for(int x : hop) cout << x << " ";
	cout << endl;
	for(int x : giao) cout << x << " ";
}