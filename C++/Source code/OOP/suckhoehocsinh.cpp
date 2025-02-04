#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Extended Datatype -> better control
struct gpa{
	float Lit, Maths, English;
	double GPA;
};

struct bodySize{
	float weight, height;
};

class student{
private:
	//Encapsulation
	string name, birthday;
	gpa g;
	bodySize b;

	//static 
	static string schoolName;
public:
	//Constructor
	student(){}
	student(string name, string birthday, float weight, float height){
		cout << "CREATED A NEW STUDENT" << endl;
		this->name = name;
		this->birthday = birthday;
		this->b.weight = weight;
		this->b.height = height;
	}	

	//getter setter -> student(){}
	void setName(string newName){
		this->name = newName;
	}
	string getName(){
		return name;
	}
	void setBirthday(string s){
		this->birthday = s;
	}
	string getBirthday(){
		return birthday;
	}
	float getWeight(){
		return b.weight;
	}
	float getHeight(){
		return b.height;
	}
	
	//Abstraction -> chỉ cần biết hàm dùng làm gì => input tham số và output ra gì + ko quan tâm cài đặt
	void setGPA(float a, float b, float c);
	double countGPA();
	void print();
};
//Implementation
void student::setGPA(float a, float b, float c){
	g.Lit = a;
	g.Maths = b;
	g.English = c;
}
double student::countGPA(){
	g.GPA = 1.0 * (g.Lit + g.Maths + g.English) / 3;
	return g.GPA;
}
void student::print(){
	cout << name << endl;
	cout << birthday << endl;
	cout << b.weight << ' ' << b.height << endl;
	cout << "SCHOOL NAME : " << schoolName << endl;
	cout << g.Lit << ' ' << g.Maths << ' ' << g.English << endl;
	cout << g.GPA << endl;
}

//Init the static variable
string student::schoolName = "UIT";

class healthChecker{
private:
	float weight, height;
public:
	//Abstraction
	void check(student* s);
	void getResult();

};
//Implementation
void healthChecker::check(student* s){
	weight = s->getWeight();
	height = s->getHeight();
}
void healthChecker::getResult(){
	if(weight > 60 && weight <= 70) cout << "HEALTHY" << endl;
	else cout << "UNHEALTHY" << endl;
	if(height >= 178) cout << "TALL" << endl;
	else cout << "SHORT" << endl;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	//Dynamic memory allocation
	student* s = new student("Nguyen Van A", "19/12/2002", 65, 175);
	s->setGPA(9.8, 7, 10);
	s->countGPA();
	s->print();
	healthChecker* checker = new healthChecker;
	checker->check(s);
	checker->getResult();
}