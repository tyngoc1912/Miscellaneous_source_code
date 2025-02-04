#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Chọn thằng nào nhỏ nhất lên đầu -> gán chỉ số min
void selection_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        //Giả sử chỉ số ở phần tử i là nhỏ nhất
        int min = i;
        for(int j = i + 1; j < n; j++){
            //Duyệt thấy thằng nào nhỏ hơn min thì cập nhật chỉ số min = j
            if(a[min] > a[j]) min = j;
        }
        //Đổi chô 2 phần tử cho nhau
        swap(a[i], a[min]);
        cout << "Buoc thu " << i + 1 << ": ";
        for(int i = 0; i < n; i++) cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) cout << a[i] << ' ';
}

//Thấy thằng nào nhỏ hơn số đang xét là đổi chổ luôn
void interchange_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]) swap(a[i], a[j]);
        }
        cout << "Buoc thu " << i + 1 << ": ";
        for(int i = 0; i < n; i++) cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) cout << a[i] << ' ';
}

//Đưa phần tử lớn nhất nổi về sau cùng -> xét 1 cặp a[j] và a[j + 1] ứng vs mỗi chỉ số i
void bubble_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
        cout << "Buoc thu " << i + 1 << ": ";
        for(int i = 0; i < n; i++) cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}

//Chèn những phần tử nằm sai vị trí vào vị trí đúng của nó -> xét 1 thằng và những thằng đứng trc nó xem thử nó đứng đúng thứ tự chưa
void insertion_sort(int a[], int n){
    for(int i = 1; i < n; i++){
        //Lấy ra phần tử ở chỉ số i và vị trí trước phần tử trước nó
        int x = a[i], pos = i - 1;
        while(pos >= 0 && a[pos] > x){
            //Dịch sang phải để chừa chỗ để chèn x vào vị trí pos
            a[pos + 1] = a[pos];
            pos--;
        }
        //out vòng while có 2 trường hợp : chạy hết chỉ số pos (pos = -1) hoặc x > a[pos] => chèn sau vị trí của a[pos]
        a[pos + 1] = x;
        cout << "Buoc thu " << i << ": ";
        for(int i = 0; i < n; i++) cout << a[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}

// Sắp xếp đếm phân phối
int cnt1[10000001] = {0};
void counting_sort(int a[], int n){ 
    int min_val = INT_MAX, max_val = INT_MIN;
    for(int i = 0; i < n; i++){
        cnt1[a[i]]++;
        max_val = max(max_val, a[i]);
        min_val = min(min_val, a[i]);
    }

    for(int i = min_val; i <= max_val; i++){
        if(cnt1[i] != 0) cout << i << " " << cnt1[i] << endl;
    }
}

//Frequency theo thứ tự xuất hiện của các phần tử trong mảng
int cnt2[10000001] = {0};
int used[10000001] = {0};
void freq(int a[], int n){
    for(int i = 0; i < n; i++) cnt2[a[i]]++;    
    for(int i = 0; i < n; i++){
        if(used[a[i]] == 0){
            cout << a[i] << " " << cnt2[a[i]] << endl;
            used[a[i]] = 1;
        } 
    }
}

//Merge Sort - Sắp xếp trộn
//Trộn 2 dãy con đã sắp xếp vào 1 dãy : dãy 1 [l, m], dãy 2 [m + 1, r]
void merge(int a[], int l, int m, int r){
    //copy nội dung ra 2 mảng con 1 và 2
    vector<int> x(a + l, a + m + 1); //mảng con 1
    vector<int> y(a + m + 1, a + r + 1); // mảng con 2
    //Trộn vào mảng a thành 1 dãy tăng dần bắt đầu từ chỉ số l
    int i = 0, j = 0;
    while(i < x.size() && j < y.size()){
        if(x[i] <= y[j]){
            a[l] = x[i];
            l++; i++;
        }
        else{
            a[l] = y[j];
            l++; j++;
        }
    }
    //Trộn các phần tử còn dư (nếu có) của mỗi mảng vào mảng a
    while(i < x.size()){
        a[l] = x[i];
        l++; i++;
    }
    while(j < y.size()){
        a[l] = y[j]; 
        l++; j++;
    }
    //vì chỉ số left chỉ truyền tham trị nên sau vòng lặp while thì chỉ số left ko đổi
}
//Cài đặt hàm mergeSort theo đệ quy => chia 2 dãy con và sắp xếp 2 dãy con đó theo thứ tự tăng dần => trộn 2 dãy đó vào 1 dãy
void merge_sort(int a[], int l, int r){
    //Chia dãy thành các dãy con bằng đệ quy và sắp xếp theo thứ tự tăng dần
    if(l >= r) return;
    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    //Trộn 2 dãy vào 1 dãy
    merge(a, l, m, r);
}
void print(int a[], int n){
    for(int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << endl;
}
//Cài đặt mergeSort thuần mảng, ko dùng vector
void mergeArray(int a[], int l, int m, int r){
    int cnt = l;
    int n1 = m - l + 1, n2 = r - m;
    int x[n1], y[n2];
    for(int j = l; j <= m; j++) x[j - l] = a[j];
    for(int j = m + 1; j <= r; j++) y[j - m - 1] = a[j];
    int i = 0, j = 0;
    while(i < n1 && j < n2){
        if(x[i] <= y[j])
            a[cnt++] = x[i++];
        else
            a[cnt++] = y[j++];
    }
    while(i < n1) a[cnt++] = x[i++];
    while(j < n2) a[cnt++] = y[j++];
}
void mergeSortArray(int a[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergesortArray(a, l, m);
        mergesortArray(a, m + 1, r);
        merge1(a, l, m, r);
    }
}

//Heap sort
//Tạo Max heap -> Heapify
void heapify(int a[], int n, int i){
    int largest = i; //xem node đang xét là lớn nhất
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    //kiểm tra node con bên trái và bên phải vẫn thỏa chỉ số trong mảng và nếu nó lớn hơn node cha thì gán chỉ số
    if(l < n && a[l] > a[largest]) largest = l;
    if(r < n && a[r] > a[largest]) largest = r;
    if(largest != i){
        swap(a[i], a[largest]); // nếu node i ko phải max thì swap vs node largest
        heapify(a, n, largest); //tiếp tục gọi đệ quy đến node chỉ số largest
    }
}
//Tư tưởng : sau khi xây dựng max-heap thì phần tử đầu tiên của mảng luôn là phần tử lớn nhất
//swap(a[0], a[n - 1])
//Heapify lại từ cái node gốc sau khi swap phần tử lớn nhất vs phần tử cuối (0 -> n - 2) => ko xét node ở cuối nữa
void heap_sort(int a[], int n){
    //tạo heapify
    //gọi heapify với mọi node ko phải node lá => Node cha đầu tiên i = i / 2 - 1
    for(int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    for(int i = n - 1; i >= 0; i--){ // xét từ cuối đến đầu 
        swap(a[0], a[i]); // đổi chỗ phần tử lớn nhất
        heapify(a, i, 0); // tạo max heap với số lượng phần tử là i vì mỗi lần swap sẽ ko xét đến thằng cuối cùng nữa
    }
}

//Quick sort => thao tác quan trọng nhất là partition : chia dãy ra + 2 phân hoạch : Lomuto và Hoare
//Chia dãy a[l..r] = a[l..p-1], a[p], a[p+1..r] 
//sao cho ai[l..p-1] <= a[p] <= ai[p+1..r] (i : biến chạy) với pivot(chốt)
//gọi đệ quy đến 2 dãy con để tiếp tục phân hoạch ra

//Lomuto partition (nếu dãy đã xếp tăng dần thì ko tối ưu) => chọn chốt (pivot) = r -> duyệt từ l đến r - 1 cứ phần tử nào < pivot => swap lớn thì bỏ qua
int partitionLomuto(int a[], int l, int r){ // phân hoạch đoạn từ l -> r trả về chốt cuối ở dãy
    int pivot = a[r]; // phần tử ngoài cùng
    int i = l - 1; // biến i 1 trong 2 biến dùng để chạy và hoán đổi vị trí của 2 phần tử
    for(int j = l; j < r; j++){
        if(a[j] <= pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    //đưa chốt về giữa
    i++;
    swap(a[i], a[r]);
    return i; // vị trí chốt sau khi phân hoạch
}
void quick_sort_Lomuto(int a[], int l, int r){
    if(l >= r) return;
    //phân hoạch thành 2 dãy con
    int p = partitionLomuto(a, l, r);
    //đệ quy dãy bên trái
    quick_sort_Lomuto(a, l, p - 1);
    //đệ quy dãy bên phải
    quick_sort_Lomuto(a, p + 1, r);
}

//Hoare partition => tìm cặp nghịch thế i = l - 1, j = r + 1 -> swap cặp đó luôn
int partitionHoare(int a[], int l, int r){
    int pivot = a[l]; // phần tử đầu
    int i = l, j = r;
    while(1){
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;
        if(i < j){ // nếu 2 thằng này vẫn còn thỏa điều kiện thì swap luôn
            swap(a[i], a[j]);
            i++; j--;
        }
        else return j; // j lúc này ko phải nằm giữa dãy nữa mà là 1 phần tử của dãy con bên trái để xét tiếp đệ quy 
    }
}
void quick_sort_Hoare(int a[], int l, int r){
    if(l >= r) return;
    int p = partitionHoare(a, l, r); // phân hoạch 2 dãy con
    quick_sort_Hoare(a, l, p); // phần tử p phải thuộc dãy con trái
    quick_sort_Hoare(a, p + 1, r); // dãy con bên phải
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    // selection_sort(a, n); cout << endl;
    // interchange_sort(a, n); cout << endl;
    // bubble_sort(a, n);
    // insertion_sort(a, n);
    // counting_sort(a, n); cout << endl;
    // merge_sort(a, 0, n - 1); print(a, n);
    // heap_sort(a, n); print(a, n);
    // quick_sort_Hoare(a, n); print(a, n);
    // quick_sort_Lomuto(a, n); print(a, n);
}