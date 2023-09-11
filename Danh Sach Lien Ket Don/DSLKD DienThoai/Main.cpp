#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct DienThoai{
    string MaDT;
    string TenDT;
    float KhuyenMai;
    float DonGia;
    int SoLuong;
}; typedef DienThoai value;
struct Node{
    value data;
    Node *next;
};
struct List{
    Node *Head;
    Node *Tail;
};
void KhoiTaoDSLK(List &l){
    l.Head = l.Tail = NULL;
}
Node *khoiTaoNODE(value x){ 
    Node *p = new Node; 
    if(p == NULL){ 
        cout << "khong du bo nho de cap phat !\n";
        return NULL;
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
void NhapDienThoai(List &l){
    value x;
    cout << "Ma dien thoai: "; getline(cin, x.MaDT);
    cout << "Ten dien thoai: "; getline(cin, x.TenDT);
    cout << "Khuyen mai: "; cin >> x.KhuyenMai;
    cout << "Don gia: "; cin >> x.DonGia;
    cout << "So luong: "; cin >> x.SoLuong; cin.ignore();
    Node *p = khoiTaoNODE(x);
    ThemVaoCuoi(l, p);
}
void NhapDanhSachDienThoai(List &l){
    int n; cout << "Nhap so luong dien thoai: "; cin >> n; cin.ignore();
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin dien thoai thu " << i + 1 << endl;
        NhapDienThoai(l);
    }
}
void DocThongTinDienThoai(List &l){
    ifstream f;
    f.open("DIENTHOAI.txt", ios::in);
    while(f.eof() != true){
        value x;
        getline(f, x.MaDT, ',');
        getline(f, x.TenDT, ',');
        f >> x.KhuyenMai; f.ignore();
        f >> x.DonGia; f.ignore();
        f >> x.SoLuong; f.ignore();
        Node *p = khoiTaoNODE(x);
        ThemVaoCuoi(l, p);
    }
    f.close();
}
void XuatDanhSachDienThoai(List l){
    int dem = 1;
    for(Node *k = l.Head; k != NULL; k = k->next){
        cout << "\n================== THONG TIN DIEN THOAI THU " << dem++ << " ==================";
        cout << "\nMa dien thoai: " << k->data.MaDT;
        cout << "\nTen dien thoai: " << k->data.TenDT;
        cout << "\nKhuyen mai: " << k->data.KhuyenMai;
        cout << "\nDon gia: " << k->data.DonGia;
        cout << "\nSo luong: " << k->data.SoLuong;
    }
}
void TimDienThoaiKhuyenMaiTren10(List l){
    int dem = 1;
    cout << "\n================== DIEN THOAI KHUYEN MAI TREN 10 ==================";
    for(Node *k = l.Head; k != NULL; k = k->next){
        if(k->data.KhuyenMai > 10){
            cout << "\n\tTHONG TIN DIEN THOAI THU " << dem++;
            cout << "\nMa dien thoai: " << k->data.MaDT;
            cout << "\nTen dien thoai: " << k->data.TenDT;
            cout << "\nKhuyen mai: " << k->data.KhuyenMai;
            cout << "\nDon gia: " << k->data.DonGia;
            cout << "\nSo luong: " << k->data.SoLuong;
        }
    }
}
void TinhGiaTruKhuyenMai(List l){
    int dem = 1;
    cout << "\n================== DON GIA SAU KHI TRU KHUYEN MAI ==================";
    for(Node *k = l.Head; k != NULL; k = k->next){
        cout << "\n\tTHONG TIN DIEN THOAI THU " << dem++;
        cout << "\nMa dien thoai: " << k->data.MaDT;
        cout << "\nTen dien thoai: " << k->data.TenDT;
        cout << "\nKhuyen mai: " << k->data.KhuyenMai;
        cout << "\nDon gia: " << k->data.DonGia - (k->data.DonGia * (float)k->data.KhuyenMai/ 100);
        cout << "\nSo luong: " << k->data.SoLuong;
    }
}
int TinhTongTienGiamGia(List l){
    float Tong = 0;
    for(Node *k = l.Head; k != NULL; k = k->next){
        Tong += k->data.DonGia * ((float)k->data.KhuyenMai / 100) * k->data.SoLuong;
    }
    return Tong;
}
void SapXepDienThoaiGiamDanTheoDonGia(List l){
    for(Node *i = l.Head; i != NULL; i = i->next){
        for(Node *j = i->next; j != NULL; j = j->next){
            if(i->data.DonGia < j->data.DonGia){
                value temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void TimDienThoaiCoKhuyenMaiMAX(List l){
    int max = -1; // gia su max la gia tri lon nhat
    for(Node *k = l.Head; k != NULL; k = k->next){
        if(k->data.KhuyenMai > max){
            max = k->data.KhuyenMai;
        }
    }

    cout << "\n================== DIEN THOAI CO KHUYEN MAI LON NHAT ==================";
    for(Node *p = l.Head; p != NULL; p = p->next){
        if(p->data.KhuyenMai == max){
            cout << "\nMa dien thoai: " << p->data.MaDT;
            cout << "\nTen dien thoai: " << p->data.TenDT;
            cout << "\nKhuyen mai: " << p->data.KhuyenMai;
            cout << "\nDon gia: " << p->data.DonGia;
            cout << "\nSo luong: " << p->data.SoLuong;
        }
    }
}
void XoaDau(List &l){
    if(l.Head == NULL){
        return;
    }
    Node *p = l.Head;
    l.Head = l.Head->next;
    delete p;
}
void XoaCuoi(List &l){
    if(l.Head == NULL){
        return;
    }
    for(Node *k = l.Head; k != NULL; k = k->next){
        if(k->next == l.Tail){
            delete l.Tail;
            k->next = NULL;
            l.Tail = k;
            return;
        }
    }
}
void XoaDienThoaiTheoMa(List &l){
    string x; 
    cout << "Nhap ma dien thoai can xoa: "; cin >> x;
    if(l.Head == NULL){
        cout << "Danh sach dien thoai dang rong !\n";
        return;
    }
    if(l.Head->data.MaDT == x){
        XoaDau(l);
        return;
    }
    if(l.Tail->data.MaDT == x){
        XoaCuoi(l);
        return;
    }
    Node *g = new Node;
    for(Node *k = l.Head; k != NULL; k = k->next){
        if(k->data.MaDT == x){
            g->next = k->next;
            delete k;
        }
        g = k;
    }
}
void xoaDienThoaiTrung(List &l){
    if(l.Head == NULL) {
        cout << "Danh sach dien thoai dang rong !\n";
        return;
    } 
    Node *previous = l.Head;
    Node *current = l.Head->next;
    while(current != NULL) { // duyệt cho đến khi con trỏ next = NULL thì dừng
        if(previous->data.TenDT == current->data.TenDT) { // so sánh nếu tên dt = nhau
            previous->data.SoLuong += current->data.SoLuong; // cộng dồn số lượng;
            previous->next = current->next;
            delete current;
            current = previous->next;
        } 
        else {
            previous = current;
            current = current->next;
        }
    }
}
void CauTrucDienThoai(){
    List l;
    KhoiTaoDSLK(l);
    int x, n, ChucNang;
    DocThongTinDienThoai(l);
    while(true){
        system("cls");
        cout << "\n\t\t================= Cau Truc Dien Thoai =================\n";
        cout << "\t\t1. Them danh sach dien thoai\n";
        cout << "\t\t2. Xuat danh sach dien thoai\n";
        cout << "\t\t3. Tim kiem dien thoai co khuyen mai tren 10%\n";
        cout << "\t\t4. Tinh don gia thuc te sau khi tru khuyen mai\n";
        cout << "\t\t5. Tinh tong tien giam gia cac dien thoai\n";
        cout << "\t\t6. Sap xep dien thoai giam dan theo don gia\n";
        cout << "\t\t7. Them mot dien thoai nhung van giam dan theo don gia\n";
        cout << "\t\t8. Tim dien thoai co khuyen mai lon nhat\n";
        cout << "\t\t9. Xoa dien thoai theo ma so\n";
        cout << "\t\t10. Xoa tat ca dien thoai trung nhau\n";
        cout << "\t\t0. Thoat chuong trinh\n";
        cout << "\t\t=========================================================\n";
        cout << "Nhap chuc nang: "; cin >> ChucNang; cin.ignore();
        if(ChucNang == 0){
            break;
        }
        else if(ChucNang == 1){
            NhapDanhSachDienThoai(l);
        }
        else if(ChucNang == 2){
            XuatDanhSachDienThoai(l);
            cout << endl;
            system("pause");
        }
        else if(ChucNang == 3){
            TimDienThoaiKhuyenMaiTren10(l);
            system("pause");
        }
        else if(ChucNang == 4){
            TinhGiaTruKhuyenMai(l);
            system("pause");
        }
        else if(ChucNang == 5){
            cout << "Tong tien giam gia cac dien thoai: " << TinhTongTienGiamGia(l) << endl;
            system("pause");
        }
        else if(ChucNang == 6){
            SapXepDienThoaiGiamDanTheoDonGia(l);
            XuatDanhSachDienThoai(l);
            system("pause");
        }
        else if(ChucNang == 7){
            NhapDienThoai(l);
            SapXepDienThoaiGiamDanTheoDonGia(l);
            system("pause");
        }
        else if(ChucNang == 8){
            TimDienThoaiCoKhuyenMaiMAX(l);
            system("pause");
        }
        else if(ChucNang == 9){
            XoaDienThoaiTheoMa(l);
        }
        else if(ChucNang == 10){
            xoaDienThoaiTrung(l);
        }
        else{
            cout << "Sai chuc nang. Vui long nhap lai !\n";
            system("pause");
        }
    }
}
int main(){
    CauTrucDienThoai();
    system("pause");
    return 0;
}