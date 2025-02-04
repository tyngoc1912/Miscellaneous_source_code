#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Ticket{
protected:
    int food, drink;
public:
    void setStuff(int p1, int p2){
        food = p1;
        drink = p2;
    }
    int getFood(){
        return food;
    }
    int getDrink(){
        return drink;
    }
    virtual ll priceCal() = 0;
    virtual string getLabel() = 0;
};

class Combo : public Ticket{
protected:
    const string label = "Combo";
public:
    ll priceCal(){
        return 200000;
    }
    string getLabel(){
        return label;
    }
};

class Normal : public Ticket{
protected:
    const string label = "Normal";
public:
    ll priceCal(){
        return 60000 + 30000 * food + 30000 * drink;
    }
    string getLabel(){
        return label;
    }
};

class Student : public Ticket{
protected:
    const string label = "Student";
public:
    ll priceCal(){
        return 30000 + 30000 * food + 30000 * drink;
    }
    string getLabel(){
        return label;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); cout.tie(nullptr);

    //Nhập ds
    Ticket** t = new Ticket*[1000000];
    int cnt = 0;
    while(1){
        int q, p1, p2;
        cin >> q >> p1 >> p2;
        if(cnt > 1e6) break;
        else if(q == 0) break;
        else if(q == 1){
            t[cnt] = new Combo;
        }
        else if(q == 2){
            t[cnt] = new Normal;
        }
        else t[cnt] = new Student;
        t[cnt]->setStuff(p1, p2);
        cnt++;
    }
    //Tiền vé SV
    ll sum = 0;
    for(int i = 0; i < cnt; i++){
        if(t[i]->getLabel() == "Student") sum += t[i]->priceCal();
    }
    cout << sum << endl;

    //đếm số lượng đồ ăn thêm tb
    double avg = 0;
    int dem = 0;
    for(int i = 0; i < cnt; i++){
        if(t[i]->getLabel() == "Normal"){
            dem++;
            avg += 0ll + t[i]->getFood() + t[i]->getDrink();
        }
    }
    avg /= dem;
    cout << fixed << setprecision(2) << avg << endl;
}