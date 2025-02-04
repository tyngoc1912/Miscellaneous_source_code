#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e7 + 1;
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
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    //Ước số nguyên tố nhỏ nhất của n
    sieve();
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cout << prime[i] << endl;
    }
}