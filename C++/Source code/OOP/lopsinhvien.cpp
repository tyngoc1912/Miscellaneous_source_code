/*
. Xây dựng lớp Candidate (Thí sinh) gồm các thuộc tính: mã, tên, ngày tháng năm sinh, điểm
thi Toán, Văn, Anh và các phương thức cần thiết. Xây dựng lớp TestCandidate để kiểm tra
lớp trên:
- Nhập vào n thí sinh (n do người dùng nhập)
- In ra thông tin về các thí sinh có tổng điểm lớn hơn 15
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Candidate{
private:
    string id, name, date;
    float toan, van, anh;
    double gpa;
public:
    void nhap(){
        getline(cin, name);
        cin.ignore();
        cin >> id >> date;
        cin >> toan >> van >> anh;
        gpa = toan + van + anh;
    }
    void xuat(){
        cout << name << endl << id << endl << date << endl << gpa << endl;
    }
    double getGPA(){
        return gpa;
    }
};

class TestCandidate{
private:
    int sizeClass;
    Candidate* ThiSinh;
public:
    void setSize(int n){
        sizeClass = n;
    }
    void nhapDS(int n){
        ThiSinh = new Candidate[sizeClass];
        for(int i = 0; i < n; i++){
            cin.ignore();
            (ThiSinh + i)->nhap();
            //ThiSinh[i].nhap();
        }
    }
    void xuatDS(int n){
        for(int i = 0; i < n; i++){
            if((ThiSinh + i)->getGPA() > 15){
                (ThiSinh + i)->xuat();
            }
        }
    }
};


//Source code khác
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using std::vector;
using std::string;
using ll = long long;

#define MIN_SCORE 15

struct Day {
    int day;
    int month;
    int year;

    void output () {
        std::cout << day << "/" << month << "/" << year << '\n';
    } 
};

Day input_day () {
    Day DAY;
    std::cin >> DAY.day >> DAY.month >> DAY.year;
    return DAY;
}

struct Score {
    double Math;
    double Literature;
    double English;

    void output () {
        std::cout << "Math: " << Math << " | " << "literature: " << Literature << " | " << "English: " << English << '\n';
        std::cout << "Total: " << std::setprecision (3) << Math + English + Literature << '\n';
    }
};

Score input_grade  () {
    Score score;
    std::cin >> score.Math >> score.Literature >> score.English;
    return score;
}

class Candidate {
    private:
        string studentCode;
        string studentFullName;
        Day birthday;
        Score score;
    public:
        // constructor
        Candidate () {}
        Candidate (string Code, string fullName, Day dayOfBirth, Score scores):
            studentCode(Code), 
            studentFullName(fullName), 
            birthday(dayOfBirth), score(scores){}
            
        Candidate (Candidate* candidate):
            studentCode (candidate -> studentCode),
            studentFullName (candidate -> studentFullName),
            birthday (candidate -> birthday),
            score (candidate -> score) {}

        // methods
        void Modify () {
           // std::fflush (stdin);
            std::getline (std::cin, studentCode);
            std::getline (std::cin, studentFullName);
            birthday = input_day ();
            score = input_grade ();
        }

        double totalGrade () {
            return score.English + score.Literature + score.Math;
        }

        void output () {
            std::cout << "Code: "<< studentCode << '\n';
            std::cout << "Full name: " << studentFullName << '\n';
            std::cout << "birthday:  "; birthday.output() ;
            std::cout << "Academic achieves: ";
            score.output();
        }

        //destructor
        ~Candidate () {
            studentCode = "";
            studentFullName = "";
            birthday = {0, 0, 0};
            score = {0, 0, 0};
            
            output();
        }
};


class TestCandidate {
    private:
        int sizeOfClass;
        Candidate* candidate;
    public:
        // constructor
        TestCandidate () {}
        TestCandidate (int size) {
            sizeOfClass = size;
            candidate = new Candidate[size];
        }
        TestCandidate (TestCandidate* test) {
            sizeOfClass = test -> sizeOfClass;
            candidate = test -> candidate;
        }

        // methods
        void setFullClassroom (int n) {
            sizeOfClass = n;
            candidate = new Candidate[n];
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    (candidate + i) -> Modify ();
                }else {
                    std::cin.ignore () ; // clearing all current caches in the memory
                    (candidate + i) -> Modify ();
                }
            }
        }

        void printAll () {
            for (int i = 0; i < sizeOfClass; ++i) {
                (candidate + i) -> output();
                std::cout << '\n';
            }
        }

        void filter () {
            for (int i = 0; i < sizeOfClass; ++i) {
                if ( (candidate + i) -> totalGrade() > MIN_SCORE) {
                    (candidate + i) -> output ();
                    std::cout << std::endl;
                }
            }
        }

        // destructror
        ~TestCandidate () {
            delete[] candidate;
            candidate = NULL;
            sizeOfClass  = 0;
        }
};
int main(){

    int n;
    std::cin >> n;
    TestCandidate* test = new TestCandidate();
    test -> setFullClassroom (n);
    test -> filter ();
    // Candidate* can = new Candidate ("23521718", "nguyen ha minh tuan", {2, 4, 2005}, {10, 9, 8});
    // can ->output ();
    // delete can;
    delete test;

    return 0;
}

