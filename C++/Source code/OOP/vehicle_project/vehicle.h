//pragma once
//file.h chứa hết toàn bộ thuộc tính và phương thức của class
#include <bits/stdc++.h>
using namespace std;

//Singleton => class yêu cầu chỉ có 1 đối tượng => quản lý các class khác
class vehicle{
protected:
	string modelName;
public:
	vehicle(string name);
	string getModelName();
	virtual void run();
};

class vehicleManager{
protected:
	vector<vehicle*> vehicles;
    //Tạo thuộc tính để quản lý class mà ko phụ thuộc vào class ấy => ko cần khởi tạo đối tượng mà có thể sử dụng luôn => static
    static vehicleManager* manager; //thuộc tính lưu object manager
    //constructor in private => giới hạn lại số lần cấp phát động ra các đối tượng từ bên ngoài
    vehicleManager();
public:
    //tạo hàm chứa được biến quản lý staic đó
    static vehicleManager* getManager(); //phương thức lấy ra thuộc tính đó
    void addVehicle(vehicle* v);
    void start();
};

//Facade => First add pattern => như một cái app tổng hướng dẫn người dùng sử dụng chức năng như thế nào => Abstraction
class vehicleApp{
protected:
public:
	void init();
	void start();
};

