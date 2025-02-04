#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    //đêm 3 pt có tổng bằng k
    int n, k; cin >> n >> s;
    int a[n];
    for(int &x : a) cin >> x;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        int l = i + 1, r = n - 1;
        int k = s - a[i];
        while(l < r){
            ll sum = a[l] + a[r];
            if(sum == k){
                int x1 = a[l], x2 = a[r], d1 = 0, d2 = 0; 
                while(a[l] == x1){
                    d1++; l++;
                }
                while(a[r] == x2){
                    d2++; r--;
                }
                if(x1 == x2) cnt += 1ll * d1 * (d1 - 1) / 2;
                else cnt += 1ll * d1 * d2;
            }
            else if(sum < k) l++;
            else r--;
        }
    }
    cout << cnt << endl;
}          