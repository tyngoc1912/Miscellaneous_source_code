#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    //in ra vị trí 2 pt có tổng bằng k
    int n, k; cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x;
    int i = 0, j = n - 1;
    while(i <= j){
        ll sum = a[i] + a[j];
        if(sum == k){
            cout << i + 1 << " " << j + 1 << endl;
            return 0;
        }
        else if(sum < k) i++;
        else j--;
    }
    cout << "IMPOSSIBLE\n";
}   