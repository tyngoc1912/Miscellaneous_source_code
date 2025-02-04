#include "vehicle.h"
#include <bits/stdc++.h>
using namespace std;
//Implementation => cài đặt các phương thức
vehicle::vehicle(string name) : modelName(name){}
string vehicle::getModelName(){
	return modelName;
}
void vehicle::run(){
	cout << modelName << " is running .. !" << endl;
}

//Khởi tạo giá trị cho biến manager
vehicleManager* vehicleManager::manager = NULL;
vehicleManager::vehicleManager(){
	cout << "Created a manager" << endl;
}
vehicleManager* vehicleManager::getManager(){ //phương thức lấy ra thuộc tính đó
	if(manager == NULL) manager = new vehicleManager();
	return manager;
}
void vehicleManager::addVehicle(vehicle* v){
	vehicles.push_back(v);
}
void vehicleManager::start(){
	for(vehicle* v : vehicles) v->run();
}

void vehicleApp::init(){
    //dữ liệu thực tế sẽ load từ database đây chỉ là demo nên cho fix cứng
	vehicle* t = new vehicle("Kia Morning");
	vehicle* v = new vehicle("Ford Ranger");
    //truy cập manager qua phương thức static
	vehicleManager::getManager()->addVehicle(t);
	vehicleManager::getManager()->addVehicle(v);
}
void vehicleApp::start(){
	vehicleManager::getManager()->start();
}
