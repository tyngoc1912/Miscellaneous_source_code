#include "vehicle.h"
using namespace std;
int main(){
    //người dùng chỉ cần sử dụng qua các chức năng có trong app mà ko cần quan tâm cài đặt nó như thế nào
    vehicleApp* app = new vehicleApp;
    app->init();
    app->start();
}