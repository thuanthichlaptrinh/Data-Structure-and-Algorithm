#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <cmath>
using namespace std;

struct Date{
    int ngay;
    int thang;
    int nam;
};
struct MonHoc{
    string maMonHoc;
    string tenMonHoc;
    int soTinChi;
    float DTL;
    float DCK;
    float diemMonHoc; // xd bang 30% DTL + 70% DCK
};
struct SinhVien{
    string maSV;
    string hoDem;
    string tenSV;
    int namSinh;
    float diemKQ;
    MonHoc monHoc[10];
    float soMonHoc; 
}; typedef SinhVien value;
struct Node{
    value data;
    Node *next;
};
struct List{
    Node *Head;
    Node *Tail;
};
// ============================ NGUYÊN MẪU HÀM ============================
void KhoiTaoDSLK(List &l);
Node *KhoiTaoNode(value x);
void ThemVaoCuoi(List &l, Node *p);
void chuanHoaChuoi(string& a);
void Nhap1SinhVien(List &l);
void XuatDanhSachSinhVien(List l);
void DocFileSinhVien(List &l);
void TimSinhVienTheoMa(List &l);
void TimSinhVienTheoTen(List &l);
void swap(value &i, value &j);
void sapXepTheoMaSV(List &l);
void sapXepTheoTen(List &l);
void xoaDau(List &l);
void xoaCuoi(List &l);
void XoaSinhVienCoMaX(List &l);
void XoaSinhVienCoTenX(List &l);
void InDanhSachSinhVienTheoLoai(List l);
void SapXepSinhVienGiamDanTheoDiemKQ(List l);
void XuatSinhVienCoDiemKqMAX(List l);
void XuatSinhVienCoDiemKqMIN(List l);
void XuatSinhVienGioiCoDiemKqMin(List l);
void XuatSinhVienCoDiemKqGanVoiX(List l);
// ============================ HÀM MENU ============================
void DSLKD_SV(){
    List l;
    value sv;
    KhoiTaoDSLK(l);
    int x, n, ChucNang;
    string ma, ten;
    DocFileSinhVien(l);
    while(1){
        system("cls");
        cout << "\t\t+------------- Quan Li Sinh Vien --------------+\n";
        cout << "\t\t|  1. Them sinh vien vao danh sach             |\n";
        cout << "\t\t|  2. Xuat danh sach sinh vien                 |\n";
        cout << "\t\t|  3. Tim sinh vien co ma so x                 |\n";
        cout << "\t\t|  4. Tim sinh vien co ten x                   |\n";
        cout << "\t\t|  5. Sap xep sinh vien theo ma                |\n";
        cout << "\t\t|  6. Sap xep sinh vien theo ten               |\n";
        cout << "\t\t|  7. Xoa sinh vien co ma so x                 |\n";
        cout << "\t\t|  8. Xoa sinh vien co ten x                   |\n";
        cout << "\t\t|  9. Xuat sinh vien loai kha                  |\n";
        cout << "\t\t|  10. Xuat sinh vien giam dan theo diem KQ    |\n";
        cout << "\t\t|  11. Xuat sinh vien co diem KQ cao nhat      |\n";
        cout << "\t\t|  12. Xuat sinh vien co diem KQ thap nhat     |\n";
        cout << "\t\t|  13. Xuat SV co diemKQ min trong ds SV gioi  |\n";
        cout << "\t\t|  0. Thoat chuong trinh                       |\n";
        cout << "\t\t+----------------------------------------------+\n";

        cout << "\nNhap chuc nang: "; cin >> ChucNang; cin.ignore();
        if(ChucNang == 0){
            break;
        }
        else if(ChucNang == 1){
            Nhap1SinhVien(l);
            sapXepTheoMaSV(l);
        }
        else if(ChucNang == 2){
            XuatDanhSachSinhVien(l);
            cout << endl;
            system("pause");
        }
        else if(ChucNang == 3){
            TimSinhVienTheoMa(l);
            system("pause");
        }
        else if(ChucNang == 4){
            TimSinhVienTheoTen(l);
            system("pause");
        }
        else if(ChucNang == 5){
            sapXepTheoMaSV(l);
            XuatDanhSachSinhVien(l);
            system("pause");
        }
        else if(ChucNang == 6){
            sapXepTheoTen(l);
            XuatDanhSachSinhVien(l);
            system("pause");
        }
        else if(ChucNang == 7){
            XoaSinhVienCoMaX(l);
            cout << "Da xoa thanh cong !\n";
            system("pause");
        }
        else if(ChucNang == 8){
            XoaSinhVienCoTenX(l);
            cout << "Da xoa thanh cong !\n";
            system("pause");
        }
        else if(ChucNang == 9){
            InDanhSachSinhVienTheoLoai(l);
            system("pause");
        }
        else if(ChucNang == 10){
            SapXepSinhVienGiamDanTheoDiemKQ(l);
            XuatDanhSachSinhVien(l);
            system("pause");
        }
        else if(ChucNang == 11){
            XuatSinhVienCoDiemKqMAX(l);
            system("pause");
        }
        else if(ChucNang == 12){
            XuatSinhVienCoDiemKqMIN(l);
            system("pause");
        }
        else if(ChucNang == 13){
            XuatSinhVienGioiCoDiemKqMin(l);
            system("pause");
        }
        else if(ChucNang == 14){
            XuatSinhVienCoDiemKqGanVoiX(l);
            system("pause");
        }
        else{
            cout << "Sai chuc nang vui long nhap lai !\n";
            system("pause");
        }
    }
}

int main(){
    DSLKD_SV();

    system("pause");
    return 0;
}
 
void KhoiTaoDSLK(List &l){
    l.Head = l.Tail = NULL;
}
Node *KhoiTaoNode(value x){
    Node *p = new Node;
    if(p == NULL){
        cout << "Khong du bo nho de cap phat !\n";
        exit(1);
    }
    p->data = x;
    p->next = NULL;
    return p;
}
void ThemVaoCuoi(List &l, Node *p){
    if(l.Head == NULL){
        l.Head = l.Tail = p;
    }
    else{
        l.Tail->next = p;
        l.Tail = p;
    }
}
void chuanHoaChuoi(string& a) {
	// xoa khoang trang dau
	while (a[0] == ' ') { // neu ptu dau = ktrang
		a.erase(a.begin() + 0); // arese(): ham xoa ; begin(): bat dau + vi tri
	}
	// xoa ktrang cuoi
	while (a[a.length() - 1] == ' ') { // ptu o cuoi = 32
		a.erase(a.begin() + a.length() - 1);
	}
	// xoa o giua
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ' ' && a[i + 1] == ' ') { // neu 2 ktrang lien tiep nhau
			a.erase(a.begin() + i);
			i--;
		}
	}
	// chuan hoa ki tu
	if (a[0] >= 97 && a[0] <= 122) { // thuong thanh hoa
		a[0] -= 32;
	}
	for (int i = 1; i < a.length(); i++) {
		if (a[i] == ' ') {
			i++;
			if (a[i] >= 97 && a[i] <= 122) {
				a[i] -= 32;
			}
		}
		else {
			if (a[i] >= 65 && a[i] <= 90) {
				a[i] += 32;
			}
		}
	}
}
void Nhap1SinhVien(List &l){
    value sv;
    sv.diemKQ = 0; 
    bool KiemTra = true; // giả sử KiemTra là đúng
    // vòng lặp bắt điều kiện trùng mã sinh viên
    do{
        cout << "Ma sinh vien: "; getline(cin, sv.maSV);
        bool KiemTra = true; // giả sử KiemTra là đúng
        for(Node *k = l.Head; k != NULL; k = k->next){
            if(k->data.maSV == sv.maSV){ // nếu phát hiện có maSV trùng với maSV trong ds
                cout << "Da co ma sinh vien " << sv.maSV << " trong danh sach\n";
                KiemTra = false; // cập nhật lại giả sử ban đầu là sai
                break; // thoát khỏi vòng lập
            }
        }
    }while(!KiemTra);
    cout << "Ho dem: "; getline(cin, sv.hoDem); chuanHoaChuoi(sv.hoDem);
    cout << "Ten sinh vien: "; getline(cin, sv.tenSV); chuanHoaChuoi(sv.tenSV);
    cout << "Nam sinh: "; cin >> sv.namSinh; 
    cout << "Nhap so mon hoc: "; cin >> sv.soMonHoc; cin.ignore();

    for(int i = 0; i < sv.soMonHoc; i++){
        cout << "Nhap thong tin mon hoc thu " << i + 1 << endl;
        cout << "Ma mon hoc: "; getline(cin, sv.monHoc[i].maMonHoc); chuanHoaChuoi(sv.monHoc[i].maMonHoc);
        cout << "Ten mon hoc: "; getline(cin, sv.monHoc[i].tenMonHoc); chuanHoaChuoi(sv.monHoc[i].tenMonHoc);
        cout << "So tin chi: "; cin >> sv.monHoc[i].soTinChi;
        cout << "Diem tieu luan: "; cin >> sv.monHoc[i].DTL;
        cout << "Diem cuoi ki: "; cin >> sv.monHoc[i].DCK; cin.ignore();
        // điểm môn học = 30% điểm tiểu luận + 70% điểm cuối kỳ
        sv.monHoc[i].diemMonHoc = 0.3 * sv.monHoc[i].DTL + 0.7 * sv.monHoc[i].DCK; 
        sv.diemKQ += sv.monHoc[i].diemMonHoc; // cộng dồn vào biến điểm kết quả
    }
    sv.diemKQ = sv.diemKQ / sv.soMonHoc; // sau đó lấy điểm kq chia cho số môn học => chính điểm trung bình
    Node *p = KhoiTaoNode(sv);
    ThemVaoCuoi(l, p);
}
void XuatDanhSachSinhVien(List l){
    int dem = 1;
    // nếu con trỏ đầu = NULL tức là danh sách đang rỗng
    if(l.Head == NULL){
        cout << "Danh sach dang rong !\n";
        return;
    }
    // ngược lại danh sách đã có phần tử
    for(Node *k = l.Head; k != NULL; k = k->next){ // duyệt từ đầu đến cuối và xuất ra từng tt sinh viên trong ds
        cout << "\n======================== SINH VIEN THU " << dem++ << " ========================";
        cout << "\nMa sinh vien: " << k->data.maSV;
        cout << "\nTen dem: " << k->data.hoDem;
        cout << "\nTen: " << k->data.tenSV;
        cout << "\nNam sinh: " << k->data.namSinh;
        cout << "\nDiem trung binh: " << k->data.diemKQ;
        cout << "\n-------------- DANH SACH MON HOC --------------"; 
        for(int i = 0; i < k->data.soMonHoc; i++){
            cout << "\n\t\tMON HOC THU " << i + 1;
            cout << "\nMa mon hoc: " << k->data.monHoc[i].maMonHoc;
            cout << "\nTen mon hoc: " << k->data.monHoc[i].tenMonHoc;
            cout << "\nSo tin chi: " << k->data.monHoc[i].soTinChi;
            cout << "\nDiem tieu luan: " << k->data.monHoc[i].DTL;
            cout << "\nDiem cuoi ki: " << k->data.monHoc[i].DCK;
            cout << "\nDiem mon hoc: " << k->data.monHoc[i].diemMonHoc;
        }
    }
}
void DocFileSinhVien(List &l){
    ifstream f;
    f.open("BT_SGK.txt", ios::in);
    while(!f.eof()){
        value sv;
        getline(f, sv.maSV, ','); 
        getline(f, sv.hoDem, ',');
        getline(f, sv.tenSV, ',');
        f >> sv.namSinh; f.ignore();
        f >> sv.soMonHoc; f.ignore();
        for(int i = 0; i < sv.soMonHoc; i++){
            getline(f, sv.monHoc[i].maMonHoc, ',');
            getline(f, sv.monHoc[i].tenMonHoc, ',');
            f >> sv.monHoc[i].soTinChi; f.ignore();
            f >> sv.monHoc[i].DTL; f.ignore();
            f >> sv.monHoc[i].DCK; f.ignore();
            f >> sv.monHoc[i].diemMonHoc; f.ignore();
        }
        f >> sv.diemKQ; f.ignore();
        Node *p = KhoiTaoNode(sv);
        ThemVaoCuoi(l, p);
    }
    f.close();
}
void TimSinhVienTheoMa(List &l){
    string x; cout << "Nhap ma can tim: "; cin >> x;
    for(Node *k = l.Head; k != NULL; k = k->next){
        if(k->data.maSV == x){
            cout << "\nMa sinh vien: " << k->data.maSV;
            cout << "\nHo dem: " << k->data.hoDem;
            cout << "\nTen: " << k->data.tenSV ;
            cout << "\nDiem trung binh: " << k->data.diemKQ;
        }
    }
}
void TimSinhVienTheoTen(List &l){
    string ten; 
    cout << "Nhap ten can tim: "; cin >> ten; chuanHoaChuoi(ten);
    for(Node *k = l.Head; k != NULL; k = k->next){
        if(k->data.tenSV == ten){
            cout << "\nMa sinh vien: " << k->data.maSV;
            cout << "\nTen dem: " << k->data.hoDem;
            cout << "\nTen: " << k->data.tenSV;
            cout << "\nNam sinh: " << k->data.namSinh;
            cout << "\nDiem trung binh: " << k->data.diemKQ;
        }
    }
}
void swap(value &i, value &j){
    value temp = i;
    i = j;
    j = temp;
}
void sapXepTheoMaSV(List &l) {
    for(Node *i = l.Head; i != NULL; i = i->next){
        for(Node *j = i->next; j != NULL; j = j->next){
            if(i->data.maSV > j->data.maSV){
                swap(i->data, j->data);
            }
        }
    }
}
void sapXepTheoTen(List &l) {
    for(Node *i = l.Head; i != NULL; i = i->next){
        for(Node *j = i->next; j != NULL; j = j->next){
            if(i->data.tenSV > j->data.tenSV){
                swap(i->data, j->data);
            }
        }
    }
}
void xoaDau(List &l){
    // nếu ds đang rỗng
    if(l.Head == NULL){
        return;
    }
    Node *p = l.Head; // cho p tro den pHead
    l.Head = l.Head->next; // cap nhat pHead la ptu ke tiep
    delete p; // xoa pHead
}
void xoaCuoi(List &l){
    if(l.Head == NULL){
        return;
    }
    for(Node *k = l.Head; k != NULL; k = k->next){ // duyet tu dau den thang ke cuoi ds
        if(k->next == l.Tail){ // kiem tra de phat hien thang ke cuoi
            delete l.Tail; // xoa ptu cuoi
            k->next = NULL; // cho con tro cua node ke cuoi tro den NULL
            l.Tail = k; // cap nhat lai pTail
            return;
        }
    }
}
void XoaSinhVienCoMaX(List &l){
    string ma;
    cout << "Nhap ma can xoa: "; cin >> ma;
    if(l.Head == NULL){ // nếu ds đang rỗng
        cout << "Danh sach dang rong !\n";
        return;
    }
    if(l.Head->data.maSV == ma){  // nếu node cần xóa nằm ở đầu
        xoaDau(l);
        return;
    }
    if(l.Tail->data.maSV == ma){  // neu node can xoa nam o cuoi
        xoaCuoi(l);
        return;
    }
    // neu node can xoa nam trong doan [2; n]
    Node *g = new Node; 
    for(Node *k = l.Head; k != NULL; k = k->next){
        if(k->data.maSV == ma){
            g->next = k->next; // cap nhat mlk giua g voi h
            delete k; 
            return;
        }
        g = k; // cho node g tro den k (tuc la tro den node can xoa)
    }
}
void XoaSinhVienCoTenX(List &l){
    string ma;
    cout << "Nhap ten sv can xoa: "; cin >> ma; chuanHoaChuoi(ma);
    if(l.Head == NULL){ // nếu ds đang rỗng
        cout << "Danh sach dang rong !\n";
        return;
    }
    if(l.Head->data.tenSV == ma){  // nếu node cần xóa nằm ở đầu
        xoaDau(l);
    }
    if(l.Tail->data.tenSV == ma){  // neu node can xoa nam o cuoi
        xoaCuoi(l);
    }
    // neu node can xoa nam trong doan [2; n]
    Node *g = new Node; 
    for(Node *k = l.Head; k != NULL; k = k->next){
        if(k->data.tenSV == ma){
            g->next = k->next; // cap nhat mlk giua g voi h
            delete k;
        }
        g = k; // cho node g tro den k (tuc la tro den node can xoa)
    }
}
void InDanhSachSinhVienTheoLoai(List l){
    int dem = 1;
    cout << "\n===================== Danh sach sinh vien xep loai kha =======================";
    for(Node *k = l.Head; k != NULL; k = k->next){
        if(k->data.diemKQ >= 7.0 && k->data.diemKQ <= 8.5){
            cout << "\n\t\tSINH VIEN THU " << dem++;
            cout << "\nMa sinh vien: " << k->data.maSV;
            cout << "\nTen dem: " << k->data.hoDem;
            cout << "\nTen: " << k->data.tenSV;
            cout << "\nNam sinh: " << k->data.namSinh;
            cout << "\nDiem trung binh: " << k->data.diemKQ;
        }
    }
}
void SapXepSinhVienGiamDanTheoDiemKQ(List l){
    for(Node *i = l.Head; i != NULL; i = i->next){
        for(Node *j = i->next; j != NULL; j = j->next){
            if(i->data.diemKQ < j->data.diemKQ){
                value temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void XuatSinhVienCoDiemKqMAX(List l){
    float max = -1; // giả sử biến max là giá trị lớn nhất
    for(Node *k = l.Head; k != NULL; k = k->next){ // duyệt qua từng cái node
        if(k->data.diemKQ > max){  // nếu phát hiện có node lớn hơn
            max = k->data.diemKQ; // cập nhật lại node đó là node lớn nhất
        }
    }
    cout << "\n\t\tSINH VIEN CO DIEM TRUNG BINH CAO NHAT\n";
    for(Node *p = l.Head; p != NULL; p = p->next){ 
        if(p->data.diemKQ == max){ // nếu diemKQ của cái node nào đó bằng mới max => xuất sv đó ra màn hình 
            cout << "\nMa so: " << p->data.maSV;
            cout << "\nHo dem: " << p->data.hoDem;
            cout << "\nTen: " << p->data.tenSV;
            cout << "\nNam sinh: " << p->data.namSinh;
            cout << "\nDiem trung binh: " << p->data.diemKQ;
        }
    }
}
void XuatSinhVienCoDiemKqMIN(List l){
    float min = 69; // Khởi tạo biến min = 69 để lưu điểm trung bình thấp nhất
    for(Node *k = l.Head; k != NULL; k = k->next){ // duyệt qua từng cái node
        if(k->data.diemKQ < min){ // nếu phát hiện có node < min
            min = k->data.diemKQ;  // cập nhật node đó là min
        }
    }
    cout << "\n\t\tSINH VIEN CO DIEM TRUNG BINH THAP NHAT\n";
    for(Node *p = l.Head; p != NULL; p = p->next){ 
        if(p->data.diemKQ == min){ // nếu diemKQ của cái node nào đó bằng mới min => xuất sv đó ra màn hình 
            cout << "\nMa so: " << p->data.maSV;
            cout << "\nHo dem: " << p->data.hoDem;
            cout << "\nTen: " << p->data.tenSV;
            cout << "\nNam sinh: " << p->data.namSinh;
            cout << "\nDiem trung binh: " << p->data.diemKQ;
        }
    }
}
void XuatSinhVienGioiCoDiemKqMin(List l){
    float min = 69; // Khởi tạo biến min = 69 để lưu điểm trung bình thấp nhất
    for(Node *k = l.Head; k != NULL; k = k->next){ // duyệt qua từng cái node
        if(k->data.diemKQ < min && k->data.diemKQ >= 8.5){ // nếu phát hiện có node < min
            min = k->data.diemKQ;  // cập nhật node đó là min
        }
    }
    cout << "\n\t\tSINH VIEN CO DTB THAP NHAT TRONG CAC SINH VIEN GIOI\n";
    for(Node *p = l.Head; p != NULL; p = p->next){ 
        if(p->data.diemKQ == min){ // nếu diemKQ của cái node nào đó bằng mới min => xuất sv đó ra màn hình 
            cout << "\nMa so: " << p->data.maSV;
            cout << "\nHo dem: " << p->data.hoDem;
            cout << "\nTen: " << p->data.tenSV;
            cout << "\nNam sinh: " << p->data.namSinh;
            cout << "\nDiem trung binh: " << p->data.diemKQ;
        }
    }
}
void XuatSinhVienCoDiemKqGanVoiX(List l){
    float x;
    cout << "Nhap x: "; cin >> x;

    float minDiff = fabs(l.Head->data.diemKQ - x); // lưu hiệu của biến đầu tiên với biên x 
    Node *p = l.Head; // cho node p trỏ đến node đầu
    for(Node *k = l.Head; k != NULL; k = k->next){ 
        float Diff = fabs(k->data.diemKQ - x); // lưu hiệu của node hiện tại với node x
        if(Diff < minDiff){ 
            minDiff = Diff;
            p = k; // cho p trỏ đến node k hiện tại => sau này xuất node p = k này ra
        }
    }
    cout << "\n\t\tSINH VIEN CO DIEM TRUNG BINH GAN VOI " << x << endl;
    cout << "\nMa so: " << p->data.maSV;
    cout << "\nHo dem: " << p->data.hoDem;
    cout << "\nTen: " << p->data.tenSV;
    cout << "\nNam sinh: " << p->data.namSinh;
    cout << "\nDiem trung binh: " << p->data.diemKQ;
}