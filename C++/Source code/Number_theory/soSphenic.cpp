#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Số Sphenic = số có duy nhất 3 thừa số ngto khác nhau 
bool check(ll n){
    int res = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            if(cnt > 1) return false;
            if(cnt == 1) res++;
            if(res > 3) return false;
        }
    }
    if(n > 1) res++;
    if(res == 3) return true;
    else return false;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    ll n; cin >> n;
    if(check(n)) cout << 1; 
    else cout << 0;
}