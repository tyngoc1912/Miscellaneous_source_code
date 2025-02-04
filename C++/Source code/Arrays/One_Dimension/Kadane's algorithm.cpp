#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    //Kadane's algorithm
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    ll sum = 0, res = -1e9;
    for(int x : a){
        sum += x;
        res = max(res, sum);
        if(sum < 0) sum = 0;
    }
    cout << res << endl;
}