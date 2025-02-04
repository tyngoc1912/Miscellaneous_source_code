#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

struct date{
	string day, month, year;
};

void chuanHoa(string &s){
	if(s[2] != '/') s = "0" + s;
	if(s[5] != '/') s.insert(3, "0");
}

date tach(string s, date &d){
	d.day.insert(0, s.substr(0, 2));
	d.month.insert(0, s.substr(3, 2)); 
	d.year.insert(0, s.substr(6, 4)); 
	return d; 
}

void nextDay(int &day, int &month, int &year){
	day += 1; 
	if(year % 400 == 0 || (year % 4 == 0) && (year % 100 != 0)){
		switch (month){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				if(day > 31){
					month += 1;
					day = 1;
				}
				break;
			case 4: case 6: case 9: case 11:
				if(day > 30){
					month += 1;
					day = 1;
				}
				break;		
			default:
				if(day > 29){
					month = 3;
					day = 1;
				}
				break;
		}
		if(month > 12){
			year += 1;
			month = 1;
		}		
	}
	else{
		switch (month){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				if(day > 31){
					month += 1;
					day = 1;
				}
				break;
			case 4: case 6: case 9: case 11:
				if(day > 30){
					month += 1;
					day = 1;
				}
				break;		
			default:
				if(day > 28){
					month = 3;
					day = 1;
				}
				break;
		}
		if(month > 12){
			year += 1;
			month = 1;
		}
	}
}

void xuat(int day, int month, int year){
	string s = "";
	s += to_string(day) + '/';
	s += to_string(month) + '/';
	s += to_string(year);
	chuanHoa(s);
	cout << s << endl;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);
	
	string s; cin >> s;
	date d;
	chuanHoa(s);
	cout << s << endl;
	tach(s, d);
	int day = stoi(d.day);
	int month = stoi(d.month);
	int year = stoi(d.year);
	cout << day << " " << month << " " << year << endl; 
	nextDay(day, month, year);
	xuat(day, month, year);	
}


