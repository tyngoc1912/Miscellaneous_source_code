#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    //đêm các cặp pt có tổng bằng k
    int n, k; cin >> n >> k;
    int a[n];
    for(int &x : a) cin >> x;
    int i = 0, j = n - 1;
    ll cnt = 0;
    while(i <= j){
        ll sum = a[i] + a[j];
        if(sum == k){
            int x1 = a[i], x2 = a[j], d1 = 0, d2 = 0;
            while(a[i] == x1){
                d1++; i++;
            }
            while(a[j] == x2){
                d2++; j--;
            }
            if(x1 == x2) cnt += 1ll * d1 * (d1 - 1) / 2;
            else cnt += 1ll * d1 * d2;
        }
        else if(sum < k) i++;
        else j--;
    }
    cout << cnt << endl;
}   
