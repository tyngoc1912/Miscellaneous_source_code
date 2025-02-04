#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Employee {
protected:
    std::string name;
    std::string dob;
    double baseSalary;
public:
    Employee(std::string name, std::string dob, double baseSalary) 
        : name(name), dob(dob), baseSalary(baseSalary) {}

    virtual double calculateSalary() const = 0;

    virtual void input() {
        std::cout << "HO VA TEN: ";
        std::getline(std::cin, name);
        std::cout << "NGAY SINH : ";
        std::getline(std::cin, dob);
        std::cout << "LUONG : ";
        std::cin >> baseSalary;
        std::cin.ignore();
    }

    virtual void display() const {
        std::cout  << name << std::endl <<  dob << std::endl << calculateSalary() << std::endl;
    }

    virtual ~Employee() {}
};

class ProductionEmployee : public Employee {
private:
    int numProducts;
public:
    ProductionEmployee(std::string name, std::string dob, double baseSalary, int numProducts)
        : Employee(name, dob, baseSalary), numProducts(numProducts) {}

    double calculateSalary() const override {
        return baseSalary + numProducts * 5000;
    }

    void input() override {
        Employee::input();
        std::cout << "SO SAN PHAM: ";
        std::cin >> numProducts;
        std::cin.ignore();
    }
};

class OfficeEmployee : public Employee {
private:
    int numWorkingDays;
public:
    OfficeEmployee(std::string name, std::string dob, double baseSalary, int numWorkingDays)
        : Employee(name, dob, baseSalary), numWorkingDays(numWorkingDays) {}

    double calculateSalary() const override {
        return numWorkingDays * 100000;
    }

    void input() override {
        Employee::input();
        std::cout << "SO NGAY LAM VIEC: ";
        std::cin >> numWorkingDays;
        std::cin.ignore();
    }
};

void inputEmployees(std::vector<Employee*>& employees) {
    while (true) {
        int empType;
        std::cout << "CHON (1: NHAN VIEN SAN XUAT, 2: NHAN VIEN VAN PHONG, 0: THOAT): ";
        std::cin >> empType;
        std::cin.ignore();
        if (empType == 0) {
            break;
        }

        Employee* emp = nullptr;
        if (empType == 1) {
            emp = new ProductionEmployee("", "", 0, 0);
        } else if (empType == 2) {
            emp = new OfficeEmployee("", "", 0, 0);
        }
        
        if (emp) {
            emp->input();
            employees.push_back(emp);
        }
    }
}

double calculateTotalSalary(const std::vector<Employee*>& employees) {
    double totalSalary = 0;
    for (const auto& emp : employees) {
        totalSalary += emp->calculateSalary();
    }
    return totalSalary;
}

void findHighestLowestSalary(const std::vector<Employee*>& employees, Employee*& highestSalaryEmployee, Employee*& lowestSalaryEmployee) {
    if (employees.empty()) return;

    highestSalaryEmployee = employees[0];
    lowestSalaryEmployee = employees[0];

    for (const auto& emp : employees) {
        if (emp->calculateSalary() > highestSalaryEmployee->calculateSalary()) {
            highestSalaryEmployee = emp;
        }
        if (emp->calculateSalary() < lowestSalaryEmployee->calculateSalary()) {
            lowestSalaryEmployee = emp;
        }
    }
}

void sortEmployeesBySalary(std::vector<Employee*>& employees) {
    std::sort(employees.begin(), employees.end(), [](Employee* a, Employee* b) {
        return a->calculateSalary() > b->calculateSalary();
    });
}

void displayEmployees(const std::vector<Employee*>& employees) {
    for (const auto& emp : employees) {
        emp->display();
    }
}

int main() {
    std::vector<Employee*> employees;

    inputEmployees(employees);

    std::cout << "\nTHONG TIN NHAN VIEN:\n";
    displayEmployees(employees);

    double totalSalary = calculateTotalSalary(employees);
    std::cout << "\nTONG LUONG: " << totalSalary << std::endl;

    Employee* highestSalaryEmployee = nullptr;
    Employee* lowestSalaryEmployee = nullptr;
    findHighestLowestSalary(employees, highestSalaryEmployee, lowestSalaryEmployee);

    if (highestSalaryEmployee) {
        std::cout << "\nNHAN VIEN LUONG CAO NHAT: ";
        highestSalaryEmployee->display();
    }

    if (lowestSalaryEmployee) {
        std::cout << "NHAN VIEN LUONG THAP NHAT: ";
        lowestSalaryEmployee->display();
    }

    sortEmployeesBySalary(employees);
    std::cout << "\nDANH SACH NHAN VIEN LUONG GIAM DAN:\n";
    displayEmployees(employees);

    for (auto emp : employees) {
        delete emp;
    }

    return 0;
}