#include <bits/stdc++.h>
using namespace std;
#define ll long long 

//sàng số nguyên tố --> kt nhiều lần trong 1 khoảng n<=10^7
const int k = 100000; //Để sàng đc <= n số -> tạo mảng cỡ n + 1 phần tử
bool nt[k + 1];
void sang(){
	//cho tất cả các giá trị bằng true
	for(int i = 0; i <= k; i++){
		nt[i] = true;
	}
	//cho số 0 và 1 false
	nt[0] = nt[1] = false;

	//kt số nào là nguyên tố
	for(int i = 2; i <= sqrt(k); i++){
		if(nt[i]){
			//loại tất cả các bội < n của nó
			for(int j = i*i; j <= k; j += i){ 
			// j phải bắt đầu từ bình phương của số nguyên tố sau đó tăng bước nhảy lên i lần
				nt[j] = false;
			}
		}
	}
}

bool nt(ll n){
	if(n < 2) return false;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0) return false;
	}
	return true;
}

//trong ll có 8 số hoàn hảo 
bool hh(ll n){
    ll s = 1;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            s += i;
            if (i != n / i) s += n / i;
        }
    }
    return s == n;
}

bool dx(ll n){
	if(n < 10) return true;
	int temp = 0, res = n;
	while(n != 0){
		temp = temp * 10 + n % 10;
		n /= 10;
	}
	if(temp == res) return true;
	else return false;
}

bool palindrome(int a[], int n){
	int l = 0, r = n - 1;
	while(l <= r){
		if(a[l] != a[r]) return false;
		l++; r--;
	}
	return true;
}

void reverse(int a[], int n){
	int l = 0; r = n - 1;
	while(l <= r){
		swap(a[l], a[r]); //int temp = a[l]; a[l] = a[r]; a[r] = temp;
		l++; r--;
	}
}

bool cp(ll n){
	ll c = sqrt(n);
	if(n == c*c) return true;
	else return false;
}

int demChuSo(ll n){
	int dem = 0;
	if(n == 0) return 1;
	while(n){
		dem++;
		n /= 10;
	}
	return dem;
}

ll tongChuSo(ll n){
	int sum = 0;
	while(n != 0){
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

ll f[100]; //chỉ có 93 số đầu là lưu được vs giá trị long long
void fibo(){
	f[0] = 0;
	f[1] = 1;
	for(int i = 2; i <= 92; i++){
		f[i] = f[i - 1] + f[i - 2];
	}
	//for(int i = 0; i <= 92; i++) cout << f[i]<< ' ';
}

// kt số fibonacci -> sinh 93 số đầu -> kt số đã cho có trong mảng fibo[n] ko
bool checkFibo(ll n){
	for(int i = 0; i <= 92; i++){
		if(n == f[i]) return true;
	}
	return false;
}

// kt fibonacci ko dùng mảng
bool checkFibo2(ll n){
	if(n == 1 || n == 0) return true;
	ll f1 = 0, f2 = 1;
	for(int i = 0; i <= 92; i++){
		ll fn = f1 + f2;
		if(fn == n) return true;
		f1 = f2;
		f2 = fn;
	}
	return false;
}

ll gcd(ll a, ll b){
    if(b==0) return a;
    else return gcd(b, a%b);
}

ll gcd2(ll a, ll b){
    ll r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
        
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b; //tránh bị tràn số
}

//__gcd(a, b); __lcm(a, b);

bool oddCheck(int n){
	while(n != 0){
		if(n % 2 == 0) return false;
		else n /= 10;
	}
	return true;
}

bool evenCheck(int n){
	while(n != 0){
		if(n % 2 != 0) return false;
		else n /= 10;
	}
	return true;
}

//nt cùng nhau -> 2 số có ucln là 1
bool co_prime(int a, int b){ 
	if(gcd(a, b) == 1) return true;
	else return false;
}

//Phi hàm Euler: tính trong khoảng 1 --> n có bao nhiêu số nguyên tố cùng nhau vs n (có ucln = 1)
//phi(n) = tích các ước nguyên tố của n * (1 - 1/p) trong đó p là ước số của n và p là số nguyên tố
ll phi(ll n){
	ll res = n;
	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0){ // i là thừa số nguyên tố của n
			res -= res / i; //(n - n/p)
		    while(n % i == 0) n /= i; // loại bỏ những thừa số nguyên tố giống nó
		}
	}
	if(n>1) res -= res / n; //thừa số nguyên tố cuối cùng
	return res;
}

ll toHop(ll n, ll k){ // ứng dụng CT: nCk = nC(n - k) = n*(n-1)*(n-2)*...*(n-k+1)/1*2*3*...*k
	ll res = 1;
	k = min(k, n - k);
	for(int i = 1; i <= k; i++){
		res *= (n - i + 1);
		res /= i;
	}
	return res;
}

ll toHop2(ll n, ll k){//Dùng QHD -> số lớn được
	//C[i][j] tổ hợp chập j của i 
	ll C[n + 1][k + 1];
	for(int i = 0; i <= n; i++){//hàng
		for(int j = 0; j <= i; j++){//cột
			if(j == 0 || j == i) C[i][j] = 1;
			else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}
}

ll binPow(ll a, ll b){//Lũy thừa nhị phân: a^b = a * a^(b/2) * ... (b lẻ) = a^(b/2) * a^(b/2) * ...
	ll res = 1;
	while(b){
		if(b % 2 == 1) res *= a;
		a *= a;
		b /= 2;
	}
	return res; //Tính lũy thừa thì dùng hàm này ko cần dùng hàm khác
}

//Phân tích ra thừa số nguyên tố
void factorize(ll n){
    for(int i = 2; i <= sqrt(n); i++){
        while(n % i == 0){
            cout << i << ' ';
            n /= i;
        }
    }
    if(n > 1) cout << n;
}

void factorize2(ll n){
    for(int i = 2; i <= sqrt(n); i++){
        int dem = 0;
        while(n % i == 0){
            dem++;
            n /= i;
        }
        if(dem != 0){
            cout << i << '^' << dem;
            if(n > i) cout << " * ";
        }
    }
    if(n > 1) cout << n << '^' << 1;
}

//Đếm phân phối
int cnt[10000001] = {0}; 
int mark[10000001] = {0};
int used[10000001] = {0};
//Liệt kê theo thứ tự tăng dân
void counting1(int a[], int n){
	int min_val = INT_MAX; max_val = INT_MIN;
	for(int i = 0; i < n; i++){
		cnt[a[i]]++;
		max_val = max(max_val, a[i]);
		min_val = min(max_val, a[i]);
	}
	for(int i = min_val; i <= max_val; i++){
		if(cnt[i]) cout << i << ' ' << cnt[i];
	}
}

//Liệt kê theo thứ tự xuất hiện của các phần tử trong mảng
void counting2(int a[], int n){
	for(int i = 0; i < n; i++){
		mark[a[i]]++;
	}
	for(int i = 0; i < n; i++){
		if(used[a[i]] == 0){
			cout << a[i] << ' ' << mark[a[i]] << endl;
			used[a[i]] = 1;
		}
	}
}

//check số tăng dần (luôn tăng)
bool increase(int n){
    int r = n % 10;
    while(n != 0){
        n /= 10;
        if(n % 10 > r) return false;
        r = n % 10;
    }
    return true;
}

//Check số giảm dần (luôn giảm)
bool decrease(int n){
    int r = n % 10;
    while(n != 0){
        n /= 10;
        if(n % 10 < r) return false;
        r = n % 10;
    }
    return true;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
