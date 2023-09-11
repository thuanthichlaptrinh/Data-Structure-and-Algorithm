//Bài tập 1: Quản lý danh sách liên kết đơn các phân số bằng 1 con trỏ đầu
#include <iostream>
using namespace std;

// cấu trúc của phân số
struct phanSo{
    int tuSo;
    int mauSo;
};
// nhập phân số
void nhapPhanSo(phanSo &ps){
    cout << "\nNhap tu so: "; cin >> ps.tuSo;
    cout << "\nNhap mau so: "; cin >> ps.mauSo;
}
// xuất phân số
void xuatPhanSo(phanSo ps){
    cout << ps.tuSo << "/" << ps.mauSo << " ";
}   
// khai báo cấu trúc node 
struct node{
    phanSo data; // dữ liệu chứa trong 1 cái node
    node *next; // con trỏ next dùng để lk các node lại với nhau
};
// khởi tạo 1 cái node
node *khoiTaoNode(phanSo ps){
    node *p = new node;
    if(p == NULL){
        cout << "\nK du bo nho de cap phat";
        return NULL;
    }
    p->data = ps; // truyền giá trị ps cho data của node p
    p->next = NULL; // đầu tiên khi khởi tạo ch lk đên node nào hết => trỏ đến NULL
    return p;
}
// hàn thêm vào đầu
void themVaoDau(node *&pHead, node *p){ // & để lưu lại, node *p cần thêm vào
    if(pHead == NULL){
        pHead = p;
    }
    else{
        p->next = pHead;
        pHead = p;
    }
}
// hàm thêm vào cuối 
void themVaoCuoi(node *&pHead, node *p){
    if(pHead == NULL){
        pHead = p;
    }
    else{
        for(node *k = pHead; ;k = k->next){ // lặp vô tận đến phát hiện node cuối thì dừng
            if(k->next == NULL){ // duyệt từ đầu đến cuối để tìm ptu có node có ctro next trỏ đến NULL
                k->next = p; // cho node cuối ds trỏ đến node p
                break;
            }
        }
    }
}
// hàm xóa đầu
void xoaDau(node *&pHead){ // truyền tham chiếu: để lưu lạilại
    if(pHead == NULL){
        return; // kết thúc chương trình
    }
    else{
       node *p = pHead; // cho node p lk đến node đầu
       pHead = pHead->next; // cập nhật node đầu là node kế tiếp
       delete p;  // xóa đi node p <=> xóa đi node đầu
    }  
}
// hàm xóa cuối
//b1: duyệt ds để tìm node cuối
//b2: xóa
//b3: cập nhật lại node cuối
void xoaCuoi(node *&pHead){ //phải có tham chiếu: để lưu lại việc xóa
    if(pHead == NULL){
        return;
    }
    if(pHead->next == NULL){
        node *p = pHead;
        pHead = pHead->next;
        delete p;
    }
    else{
        for(node *k = pHead; ; k = k->next){ 
            if(k->next->next == NULL){ // ktra node cuoi co tro den null hay k
                delete k->next; 
                k->next = NULL;
                return;
            } 
        }
    }
}
// xuat danh sách các phân số
void xuatDanhSachCacPhanSo(node *pHead){
    for(node *k = pHead; k != NULL; k = k->next){
        xuatPhanSo(k->data); // xuất data trong từng cái node k
        cout << " ";
    }
}
// them node k vao sau node Q trong dslk
//    l = q
//      |
// A -> B x C -> D -> NULL
//       \ /
//        h
//b1: lay node k lk den node nam sau node l
//b2: lay node l lk vs k can them vao sau node l
void themNodeKVaoSauNodeQ(node *&pHead, node *k, node *q){ // node q la node nhap tu ban phim de ktra
    for(node *l = pHead; l != NULL; l = l->next){
        if(l->data.tuSo == q->data.tuSo && l->data.mauSo == q->data.mauSo){
            node *h = khoiTaoNode(k->data);
            node *g = l->next;
            h->next = g; // l->next tuc la node nam sau node l = q
            l->next = h; // l->next chinh la node B
        }
    }
}
// hàm xóa node K sau node Q
void xoaNodeKVaoSauNodeQ(node *&pHead, node *q){
    /*if(pHead->next == NULL){ cach 1
        return;
    }*/
    for(node *l = pHead; l != NULL; l = l->next){
        if(l->data.tuSo == q->data.tuSo && l->data.mauSo == q->data.mauSo && l->next != NULL){
            node *tam = l->next; // node tạm là node giữ địa chỉ của node cần xóa(node nằm sau node l = q)
            l->next = l->next->next; //cho node l liên kết đến node nằm sau node cần xóa
            delete tam; // xóa đi node nằm sau node q = l
        }
    }
}
// ham menu
void menu(node *&pHead){
    int chon;
    while(true){
        system("cls"); 
        cout << "1. Nhap phan so\n";
        cout << "2. Xuat danh sach phan so\n";
        cout << "3. Xoa dau danh sach\n";
        cout << "4. Xoa cuoi danh sach\n";
        cout << "5. them node k vao sau node q\n";
        cout << "6. Xoa node k sau node q\n";
        cout << "0. Thoat chuong trinh\n";

        cout << "\nNhap chuc nang: "; cin >> chon;
        if(chon == 0){
            break;
        }
        else if(chon == 1){
            phanSo ps; // kiểu dữ liệu phanSo vừa định nghĩa
            nhapPhanSo(ps); 

            node *p = khoiTaoNode(ps);
            themVaoCuoi(pHead, p);
        }
        else if(chon == 2){
            xuatDanhSachCacPhanSo(pHead);
            system("pause");
        }
        else if(chon == 3){
            xoaDau(pHead);
        }
        else if(chon == 4){
            xoaCuoi(pHead);
        }
        else if(chon == 5){
            phanSo x;
            cout << "\nNhap gia tri phan so node k can them: ";
            nhapPhanSo(x);
            node *k = khoiTaoNode(x);

            phanSo y;
            cout << "\nNhap Q: ";
            nhapPhanSo(y);
            node *q = khoiTaoNode(y);

            themNodeKVaoSauNodeQ(pHead, k, q);
        }
        else if(chon == 6){
            phanSo x;
            cout << "\nNhap node Q: ";
            nhapPhanSo(x);
            node *q = khoiTaoNode(x);
            xoaNodeKVaoSauNodeQ(pHead, q);
        }
        else{
            cout << "\nSai chuc nang !!!\n";
            system("pause");
        }
    }
}

int main(){
    node *pHead = NULL;
    menu(pHead);

    system("pause");
    return 0;
}