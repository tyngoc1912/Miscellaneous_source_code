#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b, a%b);
}
        
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}



int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    int a, b; cin >> a >> b;
    if(a == b == 1) cout << '(' << a << ',' << b << ')' << endl; // duy nhất 1 cặp giống nhau mà nguyên tố cùng nhau là (1,1)
    for(int i = a; i <= b; i++){
        for(int j = i + 1; j <= b; j++){
            if(gcd(i, j) == 1) cout << '(' << i << ',' << j << ')' << endl;
        }
    }
}