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

bool nt(int a){
    if(a<2) return false;
    else{
        for(int i = 2; i <= sqrt(a); i++){
            if(a % i == 0) return false;
        }
    }
    return true;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	//11 2 8 9 17 11 2 5 5 7 13

	//cách 1
	// int n, max1 = INT_MIN, min1 = INT_MAX; int mark[100001], used[100001] = {0};
	// vector<int> a;
	// while(cin >> n){
	// 	if(nt(n)){
	// 		mark[n]++;
	// 		a.push_back(n);
	// 	}
	// 	min1 = min(min1, n);
	// 	max1 = max(max1, n);
	// }

	// for(int i = 0; i < a.size(); i++){
	// 	if(used[a[i]] == 0){
	// 		cout << a[i] << " " << mark[a[i]] << endl;
	// 		used[a[i]] = 1;
	// 	}
	// }
	// cout << endl;
	// for(int i = min1; i <= max1; i++){
	// 	if(mark[i] != 0){
	// 		cout << i << " " << mark[i] << endl;
	// 	}
	// cout << endl;
	// }

	//Cách 2
	int n;
	vector<int> v;
	while(cin >> n){
		if(nt(n)) v.push_back(n);
	}

	int b[v.size()] = {0};
	for(int i = 0; i < v.size(); i++){
		if(b[i] == 0){
			int dem = 1;
			for(int j = i + 1; j < v.size(); j++){
				if(v[i] == v[j]){
					dem++;
					b[j] = 1;
				}
			}
		cout << v[i] << " " << dem << endl;

		}
	}

}
