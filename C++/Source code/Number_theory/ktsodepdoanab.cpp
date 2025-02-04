#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//kiểm tra số đẹp trong đoạn a b
const int MAXN = 1e7 + 1;
int nt[MAXN], dep[MAXN];
void sang(){
    memset(nt, 1, sizeof(nt));
    nt[0] = nt[1] = 0;
    for(int i = 2; i <= sqrt(MAXN); i++){
        if(nt[i]){
            //i là số nguyên tố
            //số đẹp là bội của nguyên tố và chia hết cho bình phương nguyên tố đó
            int tmp = i * i;
            //k là bội của tmp
            for(int k = 1; k * tmp <= MAXN; k++){
                dep[k * tmp] = 1;
            }
            for(int j = i * i; j <= MAXN; j += i){
                nt[j] = 0;
            }
        }
    }
}
void check(int a, int b){
    sang();
    for(int i = a; i <= b; i++){
        if(dep[i]) cout << i << ' ';
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    int a, b; cin >> a >> b;
    check(a, b);
}