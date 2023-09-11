/*  DANH SÁCH LIÊN KẾT ĐƠN
- dslk đơn là tập hợp những cái nút và những cái nút đó liên kết với nhau thông qua con trỏ trong 
nút đó.
- đặc điểm: danh sách liên kết đơn không có chỉ số (vì vậy k thể truy xuất đến từng phần tử)
    VD: ta 100 cái node ta muốn truy xuất đến node 999 thì bắt buộc duyệt từ đầu đến cái node 999 đó
*/
#include <iostream>
#include <math.h>
using namespace std;
int n = 0; 
 
// khai báo cấu trúc 1 cái node
struct node{
    int data; // dữ liệu chứa trong 1 cái node
    node *next; // con trỏ next dùng để liên kết các node lại với nhau
};  

// khai báo cấu trúc của danh sách liên kết đơn
struct list{
    node *pHead; // node quản lí đầu danh sách
    node *pTail; // node quản lí cuối danh sách
};

// khởi tạo cấu trúc danh sách liên kết đơn các số nguyên
void khoiTaoDSLK(list &l){
    l.pHead = NULL;   // cho 2 node trỏ đến NULL (vì dslkd chưa có liên kết đến ai hết)
    l.pTail = NULL;
}

// hàm khởi tạo 1 cái node 
node *khoiTaoNODE(int x){ // truyền vào kiểu int (vì kdl node là số nguyên)
    node *p = new node; // cấp phát vùng nhớ cho node p
    if(p == NULL){ // khởi tạo k thành công (tràn bộ nhớ)
        cout << "khong du bo nho de cap phat !\n";
        return NULL;
    }
    p->data = x; // truyền giá trị x vào cho data
    p->next = NULL; // đầu tiên khi khai báo node thì node đó ch có lk đến node nào hết => trỏ đến NULL 
    return p; // trả về node p vừa khởi tạo
}    

// thêm node vào đầu danh sách liên kết
void themDau(list &l, node *p){ // node p = node cần thêm
    // danh sach đang rỗng => con trỏ đầu = NULL
    if(l.pHead == NULL){ 
        l.pHead = l.pTail = p; // node đầu cũng chính là node cuối và bằng p
    }
    else{
        p->next = l.pHead; // cho con trỏ của node cần thêm là node p lk đến node đầu (pHead)
        l.pHead = p; // cập nhật lại p chính là node đầu
    }
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

// them node p vao sau node q (nam trong danh sach lien ket don)
void themNode_p_vaoSauNode_q(list &l, node *p){
    int x;  
    cout << "\nNhap gia tri node Q: ";
    cin >> x;
    node *q = khoiTaoNODE(x); // khởi tạo node q để kiểm tra

    // nếu ds có 1 pt và pt đó cũng chính là node q => bai toan tro thanh them vao cuoi ds
    if(q->data == l.pHead->data && l.pHead->next == NULL){ // nếu node q cũng chính là node đầu tiên 
        themCuoi(l, p);
    }
    else{ // neu ds ton tai nhieu phan tu (tức là ds có tồn tại node q)
        for(node *k = l.pHead; k != NULL; k = k->next){ // duyệt từ đầu đến cuối để tìm node q
            if(q->data == k->data){ // nếu node q có tồn tại
                node *h = khoiTaoNODE(p->data); // khởi tạo node h mới để thêm vào sau node q
                node *g = k->next; // cho node g trỏ đến node nằm sau node q
                h->next = g; // b1: tao moi lk tu node h den node g <=>cung chinh la moi lk tu node h den node nam sau node q
                q->next = h; // b2: tao moi lk tu node q den node h <=> cung chinh la node k den node h
            } // node p đóng vai trò là node phụ
        }
    }
}

// them 1 node p vao truoc node q trong danh sach
void themNode_p_vaoTruocNode_q(list &l, node *p){
    int x;
    cout << "\nNhap gia tri node Q: ";
    cin >> x;
    node *q = khoiTaoNODE(x); // khoi tao 1 cai node q de tim kiem

    // neu ds chi ton tai duy nhat 1 node và phần tử đó cũng chính là node q => thêm vào đầu
    if(q->data == l.pHead->data && l.pHead->next == NULL){
        themDau(l, p); // them node p vao dau danh sach
    }
    else{ // nếu ds có nhiều phần tử
        node *g = new node; // node g la node giu lk vs node nam trc node q trong dslk
        for(node *k = l.pHead; k != NULL; k = k->next){ // duyet ds tu dau den cuoi de tim vt node p
            if(q->data == k->data){ // tim vi tri vt can them
                node *h = khoiTaoNODE(p->data); // khởi tạo node h để thêm vào trước node q
                h->next = k; // b1: cho node h liet ket(tro) node k <=> cho node p tro den node q
                g->next = h; // b2: cho node g lk den node h  
            }
            g = k; // neu if ko xay ra thi node g = node k(giu lien ket vs node nam trc node q)
        }
    }
}   
// cách 1
// thêm node p vào vị trí bất kì
void themNode_p_VaoViTriBatKy(list &l, node *p, int vt, int n){ // n = số lượng ptu trong ds
    if(l.pHead == NULL || vt == 1){ // neu ds dang rong, va vt can them la 1 => them vao dau
        themDau(l, p);
    }
    else if(vt == n + 1){ //vt can them o cuối danh sách => thêm vào cuối
        themCuoi(l, p);
    }
    else{ // vt nam trong doan [2, n]; xac dinh node q cach cach xac dinh chi so
        int dem = 0; // xac dinh vtri can them
        node *g = new node; // node g chinh la node giu lien ket vs node nam trc node q trong dslk
        for(node *k = l.pHead; k != NULL; k = k->next){ // duyet ds tu dau den cuoi de tim node q <=> tim vt can them 
            dem++; // tăng đếm kể kiểm tra
            if(dem == vt){ // ktra cái vị trí đếm có = vị trí cần thêm hay chưa
                node *h = khoiTaoNODE(p->data);
                h->next = k; // b1: cho node h liet ket(tro) node k <=> cho node p tro den node q
                g->next = h; // b2: cho node g lk den node h  
                break; // sau khi thêm đc dùng break để thoát khỏi vòng lặp
            }
            g = k; // neu if ko xay ra thi node g = node k(giu lien ket vs node nam trc node q)
        }
    }
}
// cách 2: chạy nhanh hơn
void themNodePVaoViTriBatKy(list &l, node *p, int vt){
    if(l.pHead == NULL || vt == 1){ // neu ds dang rong => them vao dau
        themDau(l, p);
    }
    else if(vt == n + 1){ // neu vt cuối danh sách => them vao cuoi
        themCuoi(l, p);
    }
    else{ // vt nam trong doan [2, n]
        int dem = 0; // xac dinh vtri can them
        node *g = new node; // node g chinh la node giu lien ket vs node nam trc node q trong dslk
        for(node *k = l.pHead; k != NULL; k = k->next){ // duyet ds tu dau den cuoi de tim vt node p
            dem++;
            if(dem == vt){ // ktra cái vị trí đếm có = vị trí cần thêm hay chưa
                node *h = khoiTaoNODE(p->data);
                h->next = k; // b1: cho node h liet ket(tro) node k <=> cho node p tro den node q
                g->next = h; // b2: cho node g lk den node h  
                break; // sau khi thêm đc dùng break để thoát khỏi vòng lặp
            }
            g = k; // neu if ko xay ra thi node g = node k(giu lien ket vs node nam trc node q)
        }
    }
}

// xoa vi tri dau
void xoaDau(list &l){
    // nếu ds đang rỗng
    if(l.pHead == NULL){
        return;
    }
    node *p = l.pHead; // cho p tro den pHead
    l.pHead = l.pHead->next; // cap nhat pHead la ptu ke tiep
    delete p; // xoa pHead
}

// xoa vi tri cuoi trong ds
void xoaCuoi(list &l){
    if(l.pHead == NULL){
        return;
    }
    for(node *k = l.pHead; k != NULL; k = k->next){ // duyet tu dau den thang ke cuoi ds
        if(k->next == l.pTail){ // kiem tra de phat hien thang ke cuoi
            delete l.pTail; // xoa ptu cuoi
            k->next = NULL; // cho con tro cua node ke cuoi tro den NULL
            l.pTail = k; // cap nhat lai pTail
            return;
        }
    }
}

// xoa node nam sau node q trong dslk
void xoaNodeNamSauNodeQ(list &l, node *q){
    for(node *k = l.pHead; k != NULL; k = k->next){
        if(k->data == q->data){ // k = q
            node *g = k->next; // node g chinh la node nam sau node k ma ta se xoa
            k->next = g->next; // cap nhat mlk giua k voi node sau node g
            delete g;
        }
    }
}

// xóa 1 node có khóa k bất kì
void xoaNodeCoKhoaKBatKi(list &l, int vt){
    if(l.pHead == NULL){ // nếu ds đang rỗng
        return;
    }
    if(l.pHead->data == vt){  // nếu node cần xóa nằm ở đầu
        xoaDau(l);
        return;
    }
    if(l.pTail->data == vt){  // neu node can xoa nam o cuoi
        xoaCuoi(l);
        return;
    }
    // neu node can xoa nam trong doan [2; n]
    node *g = new node; 
    for(node *k = l.pHead; k != NULL; k = k->next){
        if(k->data == vt){
            g->next = k->next; // cap nhat mlk giua g voi h
            delete k; 
            return;
        }
        g = k; // cho node g tro den k (tuc la tro den node can xoa)
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
// xuat danh sách liên kết đơn
void xuatDanhSach(list l){  
    for(node *k = l.pHead; k != NULL; k = k->next){ // duyet tu node dau den cuoi
        cout << k->data << " ";
    }
    cout << "\n";
}

//======================= Bai Tap ============================

// tìm kiếm
int timKiem(list &l, int x){
    node *p = l.pHead; // cho p tro den node dau 
    while(p != NULL){ // duyệt cho đến khi == NULL thì dừng
        if(p->data == x){ // nếu p->data bằng x => tìm thấy node x
            return 1;
        }
        p = p->next; // chạy if xong thì tiếp tục next đến node tiếp theo để kiểm tra
    } 
    return 0; // ko tìm thấy node có giá trị x trong ds
}

// tim max trong ds 
int Max(list l){
    int max = l.pHead->data; // gia su node dau la node max
    // bat dau duyet tu node thu 2 de kiem tra
    for(node *k = l.pHead->next; k != NULL; k = k->next){
        if(max < k->data){
            max = k->data; // cập nhật lại giá trị max
        }
    }
    return max; 
}

// đếm số node có giá trị bằng x trong dslk đơn
int demX(list l, int x){
    node *p = l.pHead;
    int dem = 0;
    while(p != NULL){ // duyệt cho đến khi == NULL thì dừng
        if(p->data == x){
            dem++;
        }
        p = p->next;
    }
    return dem; // kết quả: số lần xh x
}

//sắp xếp trong danh sách liên kết đơn theo thứ tự tăng dần */
void InterchangeSort(list &l){ // xắp sếp đổi chổ trực tiếp
    for(node *i = l.pHead; i != NULL; i = i->next){ // i = 0; i < n; i++
        for(node *j = i->next; j != NULL; j = j->next){ // j = i + 1; j < n; j++
            if(i->data > j->data){ // nếu giá trị trước > giá trị sau => hoán vị
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
//======================== ENd================================

void menu(list &l){
    int n, x, vt;
    int luachon;
    while(true){ // lap vo han 
        system("cls");
        cout << "\t\t-------------Danh Sach Lien Ket Don-------------\n";
        cout << "\t\t1. Them node vao danh sach\n";
        cout << "\t\t2. Xuat danh sach lien ket don\n";
        cout << "\t\t3. Them node p vao sau node q trong dslk\n";
        cout << "\t\t4. Them node p vao truoc node q trong dslk\n";
        cout << "\t\t5. Them node p vao vi tri bat ky trong dslk\n";
        cout << "\t\t6. Xoa vi tri dau trong dslk\n";
        cout << "\t\t7. Xoa vi tri cuoi trong dslk\n";
        cout << "\t\t8. Xoa 1 node nam sau node q\n";
        cout << "\t\t9. Xoa node co khoa k bat ki\n";
        cout << "\t\t10. Tim kiem - dem node co gia tri x\n";
        cout << "\t\t11. Sap Xep danh sach tang dan\n";
        cout << "\t\t12. Tim gia tri lon nhat trong danh sach\n";
        cout << "\t\t0. Thoat chuong trinh\n";
        cout << "\t\t---------------------End------------------------\n";

        cout << "\nNhap lua chon: "; cin >> luachon;
        if(luachon == 0){
            break;
        }
        else if(luachon == 1){
            //n++; // tang n cho cach 2
            cout << "\nNhap gia tri so nguyen: ";
            cin >> x;
            node *p = khoiTaoNODE(x); // khoi tao 1 cai node
            themCuoi(l, p); // them node vao cuoi danh sach 
            
            /*cout << "\nNhap vao so luong node can them: "; cin >> n;
            for(int i = 1; i <= n; i++){
                cout << "Nhap gia tri node thu " << i << ": " ; cin >> x;
                node *p = khoiTaoNODE(x); // khoi tao 1 cai node
                themCuoi(l, p); // them node vao cuoi danh sach
            }*/

        }
        else if(luachon == 2){
            xuatDanhSach(l);
            system("pause");
        }
        else if(luachon == 3){
            cout << "\nNhap gia tri node p can them: ";
            cin >> n;
            node *p = khoiTaoNODE(n);
            themNode_p_vaoSauNode_q(l, p);
        }
        else if(luachon == 4){
            cout << "\nNhap gia tri node p can them: ";
            cin >> n;
            node *p = khoiTaoNODE(n);
            themNode_p_vaoTruocNode_q(l, p);
        }
        else if(luachon == 5){
            // cach 1:
            int n = 0; // n = số lượng phần tử
            for(node *k = l.pHead; k != NULL; k = k->next){ // lay so luong node trong ds
                n++; // duyệt qua 1 ptu thì n tăng lên
            }

            // khoi tao gia tri cho node p
            int x;
            cout << "\nNhap gia tri node p: "; cin >> x;
            node *p = khoiTaoNODE(x);

            //nhap vtri can them cho node p
            int vt;
            do{
                cout << "\nNhap vi tri can them node P: "; cin >> vt;
                if(vt < 1 || vt > n + 1){
                    cout << "\nVi tri can them phai nam trong doan [1; " << n + 1 << "]\n";
                    system("pause");
                }
            }while(vt < 1 || vt > n + 1);
            themNode_p_VaoViTriBatKy(l, p, vt, n); //cach 1
           
            //themNodePVaoViTriBatKy(l, p, vt); // cach 2
            //n++;
        }
        else if(luachon == 6){
            xoaDau(l);
        }
        else if(luachon == 7){
            xoaCuoi(l);
        }
        else if(luachon == 8){
            cout << "\nXoa node nam sau node q: "; cin >> x;
            node *q = khoiTaoNODE(x);

            xoaNodeNamSauNodeQ(l, q);
        }
        else if(luachon == 9){
            cout << "\nNhap vi tri can xoa: "; cin >> x;
            xoaNodeCoKhoaKBatKi(l, x);
        }
        else if(luachon == 10){
            int x;
            cout << "\nNhap gia tri can tim: "; 
            cin >> x;

            timKiem(l, x) == 1 ? cout << "Tim thay " << x : cout << "Khong tim thay " << x ;
            
            cout << "\nSo lan xuat hien x: " << demX(l, x) << endl;

            system("pause");
        }
        else if(luachon == 11){
            InterchangeSort(l); // sắp xếp
            xuatDanhSach(l); // danh sách sau khi được sắp xếp
            system("pause");
        }
        else if(luachon == 12){
            cout << "Gia tri lon nhat: " << Max(l) << endl;
            system("pause");
        }
        else{
           cout << "\nChuc nang khong hop le.";
           system("pause");
        }
    }
}

int main(){
    int n, x;
    struct list l;
    khoiTaoDSLK(l); // luon luon goi ham ktao dslkd trc khi thao tac vs ds
    menu(l);

    giaiPhongVungNho(l);
    system("pause");    
    return 0;
}























