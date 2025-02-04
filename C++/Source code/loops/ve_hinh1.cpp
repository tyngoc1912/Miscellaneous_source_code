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

	int n; cin >> n;

	// 	C1 tự code
// 	int n; cin >> n;
// 	for(int i = 1; i <= n; i++){
// 		for(int j = 1; j <= n; j++){
// 			cout << "*";
// 		}
// 		cout << endl;
// 	}

// 	cout << endl;

// 	for(int i = 1; i <= n; i++){
// 		if(i == 1 || i == n){
// 			for(int j = 1; j <= n; j++) cout << "*";
// 		}
// 		else{
// 			for(int j = 1; j <= n; j++){
// 				cout << "*";
// 				while(j < n - 1){
// 					//cout << "#";
// 					cout << " ";
// 					j++;
// 				}
// 			}
// 		}
// 		cout << endl;
// 	}

// 	cout << endl;
// 	for(int i = 1; i <= n; i++){
// 		if(i == 1 || i == n){
// 			for(int j = 1; j <= n; j++) cout << "*";
// 		}
// 		else{
// 			for(int j = 1; j <= n; j++){
// 				cout << "*";
// 				while(j < n - 1){
// 					cout << "#";
// 					// cout << " ";
// 					j++;
// 				}
// 			}
// 		}
// 		cout << endl;
// 	}

// 	cout << endl;
// 	for(int i = 1; i <= n; i++){
// 		if(i == 1 || i == n){
// 			for(int j = 1; j <= n; j++) cout << i << " ";
// 		}
// 		else{
// 			for(int j = 1; j <= n; j++){
// 				cout << i << " ";
// 				while(j < n - 1){
// 					//cout << "#";
// 					cout << "  ";
// 					j++;
// 				}
// 			}
// 		}
// 		cout << endl;
// 	}

// int n;
// cin >> n;
// int space = n - 1;
// for (int i = 0; i < 5; i++) {
//     for (int j = 0; j < space; j++) {
//         cout << ' ';
//     }
//     for (int z = space; z < 5; z++) {
//         cout << '*';
//     }
//     cout << endl;

//     space--;


	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			// if(i == 1 || i == n || j == 1 || j == n) cout << "*";
			// else cout << " ";
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == 1 || i == n || j == 1 || j == n) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == 1 || i == n || j == 1 || j == n) cout << "*";
			else cout << "#";
		}
		cout << endl;
	}
	cout << endl;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == 1 || i == n || j == 1 || j == n) cout << i << " ";
			else cout << "  ";
		}
		cout << endl;
	}
	cout << endl;
}
