#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    int a[n];
    //nếu nhập pt a[i] i = 1...n
    for(int i = 1; i <= n; i++) cin >> a[i];
    //nếu duyệt theo chỉ số
    sort(a + 1, a + n + 1, greater<int>());
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
    //duyệt theo for each
    sort(a, a + n + 1);
    for(int x : a) cout << x << ' ';
}   