#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct computer{
    string name;
    float speed;
    int price;
    friend istream& operator >> (istream& in, computer& c){
        in >> c.name >> c.speed >> c.price;
        return in;
    }
    friend ostream& operator << (ostream& out, computer c){
        out << c.name << " " << fixed << setprecision(2) << c.speed << " GHz " << c.price << endl;
        return out; 
    }
};

void sortByName(computer a[], int n){
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(a[j].name < a[min].name) min = j;
        }
        swap(a[min], a[i]);
    }
}

void sortBySpeed(computer a[], int n){
    for(int i = 0; i < n; i++){
        int max = i;
        for(int j = i + 1; j < n; j++){
            if(a[j].speed > a[max].speed) max = j;
        }
        swap(a[max], a[i]);
    }
}

void Sort(computer a[], int n){
    for(int i = 0; i < n; i++){
        int min = i; 
        for(int j = i + 1; j < n; j++){
            if(a[j].price < a[min].price) min = j;
            else if(a[j].price == a[min].price){
                if(a[j].speed > a[min].speed) min = j;
            }
        }
        swap(a[min], a[i]);
    }
}

void filter(computer a[], int n, int p1, int p2, float s1, float s2){
    for(int i = 0; i < n; i++){
        if(a[i].price >= p1 && a[i].price <= p2 && a[i].speed >= s1 && a[i].speed <= s2){
            cout << a[i];
        }
    }
    cout << endl;
}

int main(){
    int n; cin >> n;
    computer a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sortByName(a, n);
    sortBySpeed(a, n);
    Sort(a, n);
    for(int i = 0; i < n; i++) cout << a[i];
    filter(a, n, 2000, 3000, 1.0, 2.4);
}