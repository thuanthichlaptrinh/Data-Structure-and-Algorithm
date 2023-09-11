#include <iostream>
#include <string>
#include <fstream>
using namespace std;



struct NhanVien{
    string hoTen;
    double luong;
    string queQuan;
    string chucVu;
};
typedef NhanVien value;
// khai báo cấu trúc 1 cái node
struct node{
    value data; // dữ liệu chứa trong 1 cái node
    node *next; // con trỏ next dùng để liên kết các node lại với nhau
};  

// khai báo cấu trúc của danh sách liên kết đơn
struct list{
    node *pHead; // node quản lí đầu danh sách
    node *pTail; // node quản lí cuối danh sách
};

// khởi tạo cấu trúc danh sách liên kết đơn các số nguyên
void khoiTaoDSLK(list &l){
    l.pHead = l.pTail = NULL;
}

// hàm khởi tạo 1 cái node 
node *khoiTaoNODE(value x){ // truyền vào kiểu int (vì kdl node là số nguyên)
    node *p = new node; // cấp phát vùng nhớ cho node p
    if(p == NULL){ // khởi tạo k thành công (tràn bộ nhớ)
        cout << "khong du bo nho de cap phat !\n";
        return NULL;
    }
    p->data = x; // truyền giá trị x vào cho data
    p->next = NULL; // đầu tiên khi khai báo node thì node đó ch có lk đến node nào hết => trỏ đến NULL 
    return p; // trả về node p vừa khởi tạo
}    

// thêm node vào cuối dslk
void themCuoi(list &l, node *p){
    if(l.pHead == NULL){ // danh sách đang rỗng
        l.pHead = l.pTail = p; 
    }
    else{
        l.pTail->next = p; // cho con trỏ của pTail lk với node p
        l.pTail = p; // cập nhật lại p là node cuối
    }
}

void addFirst(node *&head, value x){
    node *p = khoiTaoNODE(x);
    p->next = head;
    head = p;
}
node *Search(list &l, double fromPrice, double toPrice){
    node *kq = NULL;

    node *p = l.pHead;
    while(p != NULL){
        if(p->data.luong >= fromPrice && p->data.luong <= toPrice){
            addFirst(kq, p->data);
        }
        p = p->next;
    }
    return kq;
}

node *search(list &l, string x){
    node *kq = NULL;

    node *p = l.pHead;
    while(p != NULL){
        if(p->data.hoTen.find(x) != string::npos){ // string::npos nghia la vtri nay ko ton tai
            addFirst(kq, p->data);
        }
        p = p->next;
    }
    return kq;
}

void swap(value &i, value &j){
    value temp = i;
    i = j;
    j = temp;
}

void sort(list &l){
    for(node *i = l.pHead; i != NULL; i = i->next){
        for(node *j = i->next; j != NULL; j = j->next){
            if(i->data.queQuan < j->data.queQuan){
                swap(i->data, j->data);
            }
            else if(i->data.queQuan == j->data.queQuan){
                if(i->data.hoTen > j->data.hoTen){
                    swap(i->data, j->data);
                }
            }
        }
    }
}

void sapXepTheoLuong(list &l){
     for(node *i = l.pHead; i != NULL; i = i->next){
        for(node *j = i->next; j != NULL; j = j->next){
            if(i->data.luong < j->data.luong){
                swap(i->data, j->data);
            }
        }
    }
}


void DocFile(list &l){
    ifstream f;
    f.open("NhanVien.txt", ios::in);

    while(!f.eof()){
        NhanVien nv;
        getline(f, nv.hoTen); 
        f >> nv.luong; f.ignore(); // khi doc so bo ki tu dem enter cuoi cung
        getline(f, nv.chucVu);
        getline(f, nv.queQuan);

        node *p = khoiTaoNODE(nv);
        themCuoi(l, p);
    }

    f.close();
}
/*
void xuatNhanVien(NhanVien nv){
    cout << "Ho ten: " << nv.hoTen << endl;
    cout << "Luong: " << nv.luong << endl;
    cout << "Chuc vu: " << nv.chucVu << endl;
    cout << "Que quan: " << nv.queQuan << endl;
    cout << "===========================" << endl;
}*/
void xuatNhanVien(NhanVien nv){
    cout << nv.hoTen << "\t\t" << nv.luong << "\t\t" << nv.chucVu << "\t\t" << nv.queQuan << endl;
}

void xuatDanhSachNhanVien(list &l){
    node *p = l.pHead;
    while(p != NULL){
        xuatNhanVien(p->data);
        p = p->next;
    }
}

void xuatDanhSachNhanVien1(node *head){
    node *p = head;
    while(p != NULL){
        xuatNhanVien(p->data);
        p = p->next;
    }
}
// ham giai phong vung nho
void giaiPhongVungNho(list &l){
    node *k = NULL; 
    while(l.pHead != NULL){
        k = l.pHead;
        l.pHead = l.pHead->next;
        delete k; // giải phóng từng cái node trong danh sách
    }
}

int main(){
    list l;
    khoiTaoDSLK(l);
    DocFile(l);
    xuatDanhSachNhanVien(l);

    cout << "\n\t\t=======Tim kiem theo luong\n";
    node *q = Search(l, 10, 11);
    xuatDanhSachNhanVien1(q);

    cout << "\n\t\t==========Tim kiem theo ten\n";
    node *p = search(l, "Nguyen Van Teo");
    xuatDanhSachNhanVien1(p);

    cout << "\n\t\t==========Sap xep theo ten\n";
    sort(l);
    xuatDanhSachNhanVien(l);


    cout << "\n\t\t==========Sap xep theo luong\n";
    sapXepTheoLuong(l);

    xuatDanhSachNhanVien(l);

    
    giaiPhongVungNho(l);
    return 0;
}