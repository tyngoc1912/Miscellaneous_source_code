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

	int n; cin >> n;
	// int a[n];
	// for(int &x : a) cin >> x;
	// sort(a, a + n); //increase
	// for(int x : a) cout << x << " "; cout << endl;

	// sort(a, a + n, greater<int>()); //decrease
	// for(int x : a) cout << x << " "; cout << endl;

	//vector<int> a;
	// for(int i = 0; i < n; i++){
	// 	int temp; cin >> temp;
	// 	a.push_back(temp);
	// }

	vector<int> a(n);
	//for(int i = 0; i < n; i++) cin >> a[i];
	for(auto &i : a) cin >> i;

	for(auto x : a) cout << x << " "; cout << endl;
	for(int x : a) cout << x << " "; cout << endl;
	for(int i = 0; i < a.size(); i++) cout << a[i] << ' '; cout << endl;
	for(vector<int>::iterator it = a.begin(); it != a.end(); it++){
		cout << *it << " "; 
	}
	cout << endl;
	for(auto it = a.begin(); it != a.end(); it++) cout << *it << " "; cout << endl;
}
