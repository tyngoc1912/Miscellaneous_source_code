#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Đếm ước khó -> cho mảng => đếm ước của tích toàn bộ các phần tử của mảng
const int MAXN = 1e7 + 1;
const int MOD = 1e9 + 7;
int prime[MAXN];
void sieve(){
    for(int i = 1; i <= MAXN; i++) prime[i] = i; //coi ước nguyên tố nhỏ nhất của mỗi số là chính nó
    for(int i = 2; i <= sqrt(MAXN); i++){
        if(prime[i] == i){
            for(int j = i * i; j <= MAXN; j += i){
                //Tránh trường hợp các số như 12 có ước nt min = 2
                if(prime[j] == j) prime[j] = i;
            }
        }
    }
}
ll n;
ll cnt[MAXN];
void demUoc(){
    sieve();
    cin >> n;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        //x chưa phân tích thừa số nguyên tố xong
        while(x != 1){
            ll tmp = prime[x];
            //đếm số lượng xuất hiện của thường số nguyên tố nhỏ nhất của x
            while(x % tmp == 0){
                cnt[tmp]++;
                x /= tmp;
            }
        }
    }
    ll res = 1;
    for(int i = 2; i <= MAXN; i++){
        if(cnt[i] != 0){
            res *= (cnt[i] + 1); // đếm số lượng ước
            res %= MOD;
        }
    }
    cout << res << endl;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    demUoc();
}