//bài toán anh đưa ra là giải sử mình có một nhà xe gồm hai loại xe : 
//xe thường và xe phòng; chủ nhà xe sẽ nhập vào thôgn tin của một cái xe như biển số của nó, mã xe trong nhà xe, thôgn tin người tài xế lái nó giá tiền đi chiếc xe ấy và số lượng ghế còn trống, 
//Nhập vào rồi sẽ in ra những thông tin như trên, kèm theo là số tiền thu được của tất cả các xe loại đó, đồng thời cuối cùng sẽ in ra doanh thu của toàn bộ nhà xe (gồm cả thường và phòng)

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

// thông tin của tài xế
class TAIXE {
    private:
        string TenTaixe;
        string MaCanCuoc;
    public:
        // các phương thức set:
        void setTenTaixe(string tx){
            TenTaixe = tx;
        }
       
        void setMaCanCuoc(string mcc){
            MaCanCuoc = mcc;
        }

		// các phương thức get:
        string getMaCanCuoc(){
            return MaCanCuoc;
        }

		string getTenTaixe(){
            return TenTaixe;
        }
    
        //Khởi tạo - Hủy
        TAIXE(string TenTX = "Nguyen Van A", string MCC = "123456"){
            TenTaixe = TenTX;
            MaCanCuoc = MCC;
        }
        TAIXE(const TAIXE& tx){
            TenTaixe = tx.TenTaixe;
            MaCanCuoc = tx.MaCanCuoc;
        }
        ~TAIXE(){};
        
        //Nhập - Xuất (overloading)
        friend istream& operator >> (istream& is, TAIXE& Taixe){
            getline(is, Taixe.TenTaixe);
            getline(is, Taixe.MaCanCuoc);
            
            return is;
        }
        friend ostream& operator << (ostream& os, TAIXE Taixe){
            os << "Ten tai xe: " << Taixe.TenTaixe << endl;
            os << "Ma can cuoc: " << Taixe.MaCanCuoc << endl;
            
            return os;
        }
};

// lớp cha: XE
class XE {
    private:
        string bienSoXe;
        string maXe;
        TAIXE taixe;
    public:
        //get - set
        XE () {}
        XE (string bienSoXe_, string maXe_, TAIXE taixe_): bienSoXe (bienSoXe_), maXe (maXe_), taixe (taixe_) {}
        XE (XE& xeKhac): bienSoXe (xeKhac.bienSoXe), maXe (xeKhac.maXe), taixe (xeKhac.taixe) {}
        
		// các phương thức get:
        string getBienSo(){
            return bienSoXe;
        }
        string getMaXe(){
            return maXe;
        }
        TAIXE getTaiXe(){
            return taixe;
        }
        void getThongTinXe() {
            cout << "Bien so xe: " << bienSoXe << endl;
            cout << "Ma xe: " << maXe << endl;
            cout << taixe;
        }
		
		// các phương thức set:
        void capNhatBienSo(string bienSoMoi){
            bienSoXe = bienSoMoi;
        }
        void capNhatMaXe(string maXeMoi){
            maXe = maXeMoi;
        }
        void capNhatTaiXe(TAIXE taiXeMoi){
            taixe = taiXeMoi;
        }
        void capNhatThongTinXe(string bienSoMoi, string maXe, TAIXE taixe){
            capNhatBienSo(bienSoMoi);
            capNhatMaXe(maXe);
            capNhatTaiXe(taixe);
        }

        void nhapThongTin(){
            getline (cin, bienSoXe);
            getline (cin, maXe);
            cin >> taixe;
        }
        
        //Hủy
        ~XE () {
            bienSoXe = "";
            maXe = "";
            taixe.~TAIXE();
        }
};

//Xe thường có 22 giường
// lớp con: XETHUONG (cha: XE)
class XETHUONG : public XE{
    private:
        double giaVe;
        vector <string> gheTrong;
    public:
        // các phương thức khởi tạo
        XETHUONG() {}

        XETHUONG(string bienSoXe_, string maXe_, TAIXE taiXe_, double giaVe_, vector <string> gheTrong_):
			XE(bienSoXe_, maXe_, taiXe_), 
            giaVe(giaVe_), gheTrong(gheTrong_){}

        XETHUONG(XETHUONG& xethuong): XE(xethuong), giaVe(xethuong.giaVe), gheTrong(xethuong.gheTrong){}

		// các phương thức get
        double getGiaVe (){
            return giaVe;
        }
        void getThongTinXe(){
            XE::getThongTinXe();
            cout << "Gia ve: " << giaVe << endl;
            cout << "Ghe con trong: ";
            for (int i = 0; i < gheTrong.size(); ++i){
                cout << gheTrong[i] << " |";
                if(i < gheTrong.size() - 1){
                    cout << " ";
                }
            }
            cout << endl;
            gheTrong.clear ();
        }

		int soLuongGheTrong(){
            return gheTrong.size();
        }

		// các phương thức set:
        void capNhatGiaVe(double giaVeMoi) {giaVe = giaVeMoi;}

        void capNhatViTri(string maViTri) {
            int vitri = 0;
            for (int i = 0; i < gheTrong.size(); ++i) {
                if (gheTrong[i] == maViTri) {
                    vitri = i;
                    break;
                }
            }
            gheTrong.erase (gheTrong.begin () + vitri);
        }

        void capNhatThongTinXe(string bienSoMoi, string maXe, TAIXE taixe, double giaVeMoi, string maGhe){
            capNhatBienSo(bienSoMoi);
            capNhatMaXe(maXe);
            capNhatTaiXe(taixe);
            capNhatGiaVe(giaVeMoi);
            capNhatViTri(maGhe);
        }

        void nhapThongTin(){
            XE::nhapThongTin();
            cin >> giaVe;
            string ghe;
            while (cin >> ghe){
				// định dạng của mã ghế sẽ có hai kí tự như sau: kí tự thứ nhất là chữ cái viết thường, kí tự thứ hai là 1 số: ví dụ a1, b2. v8 ....
                if (ghe.size() != 2) break;
                else gheTrong.push_back(ghe);
            }
        }

		// phương thức tính doanh thu thu được của một xe theo công thức: 
		// doanh thu = (tổng ghế (22) - số ghế còn lại) * giá vé của xe đó
        double doanhThu(){
            return (22 - soLuongGheTrong ()) * giaVe;
        }

        //Hủy
        ~XETHUONG(){
            giaVe = 0;
            gheTrong.clear();
        }
        
};

// Xe phòng thường có 22 phòng
// lớp con: XEPHONG (lớp cha: XETHUONG)
class XEPHONG : public XETHUONG {
    private:
        string maXeTrungChuyen;
    public:
		// các phương thức khởi tạo
        XEPHONG(){}

        XEPHONG(string bienSoXe_, string maXe_, TAIXE taiXe_, double giaVe_, vector <string> gheTrong_, string maXeTrungChuyen_):
            XETHUONG(bienSoXe_, maXe_, taiXe_, giaVe_, gheTrong_),
            maXeTrungChuyen(maXeTrungChuyen_){}

        XEPHONG(XEPHONG& xePhong) : XETHUONG (xePhong), maXeTrungChuyen(xePhong.maXeTrungChuyen){}

		// các phương thức get:
		string getMaXeTrungChuyen(){
            return maXeTrungChuyen;
        }
        void getThongTinXe(){
            XETHUONG::getThongTinXe();
            cout << "Ma xe trung chuyen: " << maXeTrungChuyen;
        }
        
		// các phương thức set:
        void capNhatMaXeTrungChuyen(string maMoi){
            maXeTrungChuyen = maMoi;
        }
        void capNhatThongTinXe(string bienSoMoi, string maXe, TAIXE taixe, double giaVeMoi, string maGhe){
            XETHUONG::capNhatBienSo(bienSoMoi);
            XETHUONG::capNhatMaXe(maXe);
            XETHUONG::capNhatTaiXe(taixe);
            XETHUONG::capNhatGiaVe(giaVeMoi);
            XETHUONG::capNhatViTri(maGhe);
            capNhatMaXeTrungChuyen(maGhe);
        }

        void nhapThongTin(){
            XETHUONG::nhapThongTin();
			cin >> maXeTrungChuyen;
        }

        //Hủy
        ~XEPHONG(){
            maXeTrungChuyen = "";
        }
};

//Tính tổng doanh thu của xe thường
double tongDoanhThu (XETHUONG a[], int soluong){
    double doanhthu = 0;
    for (int i = 0; i < soluong; ++i){
        doanhthu += a[i].doanhThu();
    }
    return doanhthu;
}

//Tính tổng doanh thu của xe phòng
double tongDoanhThu (XEPHONG a[], int soluong){
    double doanhthu = 0;
    for (int i = 0; i < soluong; ++i){
        doanhthu += a[i].doanhThu();
    }
    return doanhthu;
}    

//Xử lý yêu cầu của đề bài.
void XuLy(XETHUONG xethuong, XEPHONG xephong){
    double doanhThuChung = 0;
    double doanhThuXePhong = 0;
    double doanhThuXeThuong = 0;
    char r;
    // có hai lựa chọn cho r: nếu r bằng a thì ta chỉnh sửa xe phòng, bằng b thì chỉnh sửa xe thường, còn không thì thoát vòng lặp test
    while (cin >> r) {
        if (r == 'a') {
            cout << "XE PHONG" << endl;
            int soluongxe;
            cin >> soluongxe;

            while(soluongxe--){
                cin.ignore();
                xephong.nhapThongTin();
                xephong.getThongTinXe();
                cout << endl;
                cout << endl;
                doanhThuXePhong += xephong.doanhThu();
				
            }
        }
        else if (r == 'b'){
            cout << "XE THUONG" << endl;
            int soluongxe;
            cin >> soluongxe;
            while(soluongxe--){
                cin.ignore();
                xethuong.nhapThongTin();
                xethuong.getThongTinXe();
                cout << endl;
                doanhThuXeThuong += xethuong.doanhThu();
            }
        }
    }
    if (doanhThuXePhong == 0) {}
    else cout << "TONG DOANH THU XE PHONG: " << doanhThuXePhong << " VND" << endl;

    if (doanhThuXeThuong == 0) {}
    else cout << "TONG DOANH THU XE THUONG: " << doanhThuXeThuong << " VND" << endl;
    
    doanhThuChung = doanhThuXePhong + doanhThuXeThuong;
    if (doanhThuChung == 0) {}
    else cout << "\nTONG DOANH THU CHUNG: " << doanhThuChung << " VND";
}

int main(){

    XETHUONG xethuong;
    XEPHONG xephong;
    
    XuLy(xethuong, xephong);
    return 0;
}
