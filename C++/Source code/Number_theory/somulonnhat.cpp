#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Cho số tự nhiên N tìm x sao cho N! % p^x == 0 => phần tích xem p được biểu diễn trong N! bao nhiêu lần 
//chưa tối ưu
ll solve(ll n, ll p){
    ll res = 0;
    for(ll i = p; i <= n; i += p){
        int cnt = 0; 
        ll tmp = i;
        while(tmp % p == 0){
            cnt++;
            tmp /= p;
        }
        res += cnt;
    }
    return res;
}
//Cho số tự nhiên N tìm x sao cho N! % p^x == 0 => phần tích xem p được biểu diễn trong N! bao nhiêu lần 
//tối ưu => x = res += n / i^2 vs i là bội của p <= n
ll solve1(ll n, ll p){
    ll res = 0;
    for(ll i = p; i <= n; i *= p){
        res += n / i;
    }
    return res;
}
//Tìm số lượng số 0 ở cuối của N! -> tìm các cặp lũy thừa 2 * 5 => đếm có bao nhiêu số 5 -> có bấy nhiêu số 0
const int MOD = 1e9 + 7;
ll solve2(ll n){
    ll res = 0;
    for(ll i = 5; i <= n; i *= 5){
        res += n / i;
        res %= MOD;
    }
    return res;
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    ll n, x; cin >> n >> x;
    cout << solve1(n, x);
}