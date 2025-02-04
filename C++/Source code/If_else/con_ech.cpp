#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;

int main() {
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);

   int a, b, k; cin >> a >> b >> k;
   if(k % 2 == 0) cout << k/2 * (a - b);
   else cout << (k/2 + 1)* a - k/2 * b;

   //bản chất bài toán là sử tính xem tổng quãng đường di chuyển cả 2 bên của con ếch r trừ cho nhau
   //nhưng bên phải nhiều hơn bên trái 1 lần và xét k chẵn hoặc lẻ
}
