#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    //in số pt ít hơn của mỗi pt ở dãy 1 so với dãy 2
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] < b[j]) i++;
        else{
            cout << i << " ";
            j++;
        }
    }
    while(j < m){
        cout << n << ' ';
        j++;
    }

    //C2
    int j = 0;
    for(int i = 0; i < m; i++){
        while(j < n && a[j] < b[i]) j++;
        cout << j << ' '; 
    }
}   