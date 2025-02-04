#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//số smith
ll sumDigit(ll n){
    ll s = 0;
    while(n){
        s += n % 10;
        n /= 10;
    }
    return s;
}

ll sum = 0;
bool prime(ll n){
    ll tmp = n;
    for(int i = 2; i <= sqrt(n); i++){
        while(n % i == 0){
            n /= i;
            sum += sumDigit(i);
        }
    } 
    //check có phải số nguyên tố hay ko
    if(sum == 0 && n == tmp) return true;
    //thừa số nguyên tố cuối cùng
    if(n > 1) sum += sumDigit(n);
    return false;
}

void smithCheck(){
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        sum = 0;
        bool check = prime(n);
        if(check == false && sum == sumDigit(n)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    smithCheck();
}