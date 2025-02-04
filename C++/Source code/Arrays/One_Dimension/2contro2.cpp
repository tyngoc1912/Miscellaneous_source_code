#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    //tìm số cặp của các pt giống nhau ở 2 dãy
    int n, m; cin >> n >> m;
    int a[n], b[m];
    for(int &x : a) cin >> x;
    for(int &x : b) cin >> x;
    int i = 0, j = 0;
    ll cnt = 0;
    while(i < n && j < m){
        if(a[i] == b[j]){
            int x = a[i], d1 = 0, d2 = 0;
            while(a[i] == x){
                d1++;
                i++;
            }
            while(b[j] == x){
                d2++;
                j++;
            }
            cnt += 1ll * d1 * d2;
        }
        else if(a[i] < b[j]) i++;
        else j++;
    }
    cout << cnt << endl;
}   