#include <iostream>
#include <math.h>
#include <limits.h>
#include <fstream>
#include <queue> // thu vien cua hang doi
#include <stack> // thu vien cua ngan xep
using namespace std;

struct Node{
    int data; // dữ liệu chứa trong 1 cái node
    Node *Left; // cây con trái
    Node *Right; // cây con phải
}; 
typedef Node* TREE; 
void KhoiTaoCay(TREE &t){
    t = NULL; // cây rỗng
}
Node *ThemNodeVaoCay(TREE &t, int x){
    if(t == NULL){ // nếu cây rỗng
        Node *p = new Node; // khởi tạo 1 cái node để thêm vào cây
        p->data = x; // thêm dữ liệu x vào data
        p->Left = p->Right = NULL;
        t = p; // node p là node gốc (root) <=> x chính là node gốc
    }
    else{ // nếu có tồn tại phần tử (Thuật toán chèn)
        if(x < t->data){ // nếu ptu thêm vào < node gốc => đệ quy qua trái (để duyệt)
            ThemNodeVaoCay(t->Left, x);
        }
        else if(x > t->data){ // nếu ptu thêm vào > node gốc => đệ quy qua phải (để duyệt)
            ThemNodeVaoCay(t->Right, x);
        }
    }
}
void docFile(TREE &t){
    ifstream f;
    f.open("SONGUYEN.txt", ios_base::in);
    int n;
    f >> n; // doc so luong ptu trong cay
    for(int i = 1; i <= n; i++){
        int x;
        f >> x; // doc tung phan tu trong cay
        ThemNodeVaoCay(t, x);
    }
}
void Duyet_NLR(TREE t){
    if(t != NULL){ // nếu cây còn phân tử thì tiếp tục duyệt
        cout << t->data << " "; // xuất dữ liệu trong node
        Duyet_NLR(t->Left); // duyệt sang trái
        Duyet_NLR(t->Right); // duyệt sang phải
    }
}
void Duyet_NRL(TREE t){
    if(t != NULL){
        cout << t->data << " ";
        Duyet_NRL(t->Right);
        Duyet_NRL(t->Left);
    }
}
void Duyet_LNR(TREE t){
    if(t != NULL){
        Duyet_LNR(t->Left);
        cout << t->data << " ";
        Duyet_LNR(t->Right);
    }
}
void Duyet_RNL(TREE t){
    if(t != NULL){
        Duyet_RNL(t->Right);
        cout << t->data << " ";
        Duyet_RNL(t->Left);
    }
}
void Duyet_LRN(TREE t){
    if(t != NULL){
        Duyet_LRN(t->Left);
        Duyet_LRN(t->Right);
        cout << t->data << " ";
    }
}
void Duyet_RLN(TREE t){
    if(t != NULL){
        Duyet_RLN(t->Left);
        Duyet_RLN(t->Right);
        cout << t->data << " ";
    }
}
Node *TimKiem(TREE t, int &x){
    if(t == NULL){ // nếu cây rỗng => trả về NULL
        return NULL;
    }
    else{ // t != NULL
        if(x < t->data){ // nếu ptu cần tìm < node gốc => đệ quy qua trái để tìm
            TimKiem(t->Left, x);
        }
        else if(x > t->data){ // nếu ptu cần tìm > node gốc => đệ quy qua phải đề tìm
            TimKiem(t->Right, x);
        }
        else{ // x == t->data => trả về cái node cần tìm kiếm
            return t;
        }
    }
}
void TimNodeTheMang(TREE &x, TREE &y){ // *y = t->pRight: là node thế mạng cho node cần xóa (đảm nhận nhiệm vụ tìm ra node trái nhất)
    // cach 1: tìm node tận cùng bên trái của cây con phải
    if(y->Left != NULL){ // duyệt sang trái nhất
        TimNodeTheMang(x, y->Left); // tìm ra node trái nhất
    }
    else{ // y->Left == NULL đã tìm ra đc cái node trái nhất
        x->data = y->data; // cập nhật data của node cần xóa chính là data của node thế mạng
        x = y; // cho node x trỏ đến node thế mạng (node x là node mà ta sẽ xóa)
        y = y->Right; // cập nhật lại node cha của node thế mạng với node con của node thế mạng (14->NULL)
    }
}
void XoaNodeBatKy(TREE &t, int data){ // data chính là giá trị của node cần xóa
    if(t == NULL){ // nếu cây rỗng => kết thúc chương trình
        return; // kết thúc hàm
    }
    else{ // t != NULL (cây đã có phần tử)
        if(data < t->data){ // nếu node cần xóa < node root 
            XoaNodeBatKy(t->Left, data); // duyệt sang nhánh trái
        }
        else if(data > t->data){ // nếu node cần xóa > node root
            XoaNodeBatKy(t->Right, data); // duyệt sang nhánh phải
        }
        else{ // x == t->data  (đã tìm ra cái node cần xóa)
            Node *X = t; // node x là node thế mạng
            if(t->Left == NULL){ // <=> đây là cây con phải
                t = t->Right; // duyệt sang phải node cần xóa để cập nhật mlk giữa node cha node cần xóa với node con node cần xóa
            }
            else if(t->Right == NULL){ // <=> đây là cây con trái
                t = t->Left; // duyệt sang trái node cần xóa để cập nhật lại mlk giữa node cha node cần xóa với node con node cần xóa
            }
            else{ // nếu node cần xóa là node có 2 con
                TimNodeTheMang(X, t->Right); // cách 1: tìm ra node trái nhất của cây con phải
                //TimNodeTheMang(X, t->pLeft); // cách 2: tìm ra node phải nhất của cây con trái
            }
            delete X;
        }
    }
}
void XoaToanBoCay(TREE &t){
    if(t == NULL){
        return;
    }
    else{
        XoaToanBoCay(t->Left);
        XoaToanBoCay(t->Right);
        delete t;
    }
}
void XuatNode1Con(TREE t){
    if(t != NULL){
        // xử lí
        if((t->Left != NULL && t->Right == NULL) || (t->Left == NULL && t->Right != NULL)){
            cout << t->data << " ";
        }
        XuatNode1Con(t->Left);// duyệt sang cây con trái của node hiện tại
        XuatNode1Con(t->Right); // duyệt sang cây con phải của node hiện tại
    }
}
void XuatNode2Con(TREE t){// xuất các nde có 2 con (có tồn tại CCT và CCP)
    if(t != NULL){
        if(t->Left != NULL && t->Right != NULL){
            cout << t->data << " ";
        }
        XuatNode2Con(t->Left);
        XuatNode2Con(t->Right);
    }
}
void XuatNodeLa(TREE t){
    if(t != NULL){
        if(t->Left == NULL && t->Right == NULL){
            cout << t->data << " ";
        }
        XuatNodeLa(t->Left);
        XuatNodeLa(t->Right);
    }
}
int TimMax(TREE t){
    if(t->Right == NULL){ // nếu node gốc mà k ton tai cây con phải => node nay chinh la node ngoài cùng nhất của ccphai
        return t->data;
    }
    return TimMax(t->Right); // duyệt đến node cuối cùng bên cây con phải => để tìm max 
}
int TimMin(TREE t){
    if(t->Left == NULL){ // nếu node gốc mà k ton tai cây con phải => node nay chinh la node ngoài cùng nhất của ccphai
        return t->data;
    }
    return TimMin(t->Left); // duyệt đến node cuối cùng bên cây con phải => để tìm max 
}
bool ktraSNT(int n){
    if(n <= 1){
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void DemSoLuongSNT(TREE t, int &count){
    if(t != NULL){ // nếu cây có phần tử
        // xử lí
        if(ktraSNT(t->data) == true){ // nếu só cần ktra là snt => tăng đếmđếm
            count++;
        }
        // duyệt qua từng cái node trong cây (mỗi lần duyệt qua từng cái node trong cây ta sẽ xử lí nếu đúng => tăng đếm)
        DemSoLuongSNT(t->Left, count);
        DemSoLuongSNT(t->Right, count);
    }
}
void KiemTraGiaTriLonHonX(TREE t, int x){
    if(t != NULL){
        // xu li
        if(t->data > x){
            cout << t->data << " ";
        }
        KiemTraGiaTriLonHonX(t->Left, x);
        KiemTraGiaTriLonHonX(t->Right, x);
    }
}
int TinhTongDuong(TREE t){
    int tong = 0;
    if(t != NULL){
        if(t->data > 0){
            tong += t->data;
        }
        tong += TinhTongDuong(t->Left);
        tong += TinhTongDuong(t->Right);
    }
    return tong;
}
int TinhTongAm(TREE t){
    int tong = 0;
    if(t != NULL){
        if(t->data < 0){
            tong += t->data;
        }
        tong += TinhTongAm(t->Left);
        tong += TinhTongAm(t->Right);
    }
    return tong;
}
int DemSoNutTrongCay(TREE t){
    int dem = 0;
    if(t != NULL){
        dem++;
        dem += DemSoNutTrongCay(t->Left);
        dem += DemSoNutTrongCay(t->Right);
    }
    return dem;
}
int DemNutLa(TREE t){
    int dem = 0;
    if(t != NULL){
        if(t->Left == NULL && t->Right == NULL){
            dem++;
        }
        dem += DemNutLa(t->Left);
        dem += DemNutLa(t->Right);
    }
    return dem;
}
int DemNut1Con(TREE t){
    int dem = 0;
    if(t != NULL){
        if(t->Left != NULL && t->Right == NULL || t->Left == NULL && t->Right != NULL){
            dem++;
        }
        dem += DemNut1Con(t->Left);
        dem += DemNut1Con(t->Right);
    }
    return dem;
}
int DemNut2Con(TREE t){
    int dem = 0;
    if(t != NULL){
        if(t->Left != NULL && t->Right != NULL){
            dem++;
        }
        dem += DemNut2Con(t->Left);
        dem += DemNut2Con(t->Right);
    }
    return dem;
}
int TinhTongSoNutTrongCay(TREE t){
    if(t == NULL){
        return 0;
    }
    return TinhTongSoNutTrongCay(t->Left) + TinhTongSoNutTrongCay(t->Right) + t->data;
}
int TinhTongNutLa(TREE t){
    int tong = 0;
    if(t != NULL){
        if(t->Left == NULL && t->Right == NULL){
            tong += t->data;
        }
        tong += TinhTongNutLa(t->Left);
        tong += TinhTongNutLa(t->Right);
    }
    return tong;
}
int TinhTongNut1Con(TREE t){
    int tong = 0;
    if(t != NULL){
        if(t->Left != NULL && t->Right == NULL || t->Left == NULL && t->Right != NULL){
            tong += t->data;
        }
        tong += TinhTongNut1Con(t->Left);
        tong += TinhTongNut1Con(t->Right);
    }
    return tong;
}
int TinhTongNut2Con(TREE t){
    int tong = 0;
    if(t != NULL){
        if(t->Left != NULL && t->Right != NULL){
            tong += t->data;
        }
        tong += TinhTongNut2Con(t->Left);
        tong += TinhTongNut2Con(t->Right);
    }
    return tong;
}

// ===================== HÀM MENU =====================
void BinarySearchTree(){
    TREE t;
    KhoiTaoCay(t);
    int x, n, ChucNang;
    docFile(t);
    while(1){
        int chon;
        system("cls");
        cout << "\t\t============== Cay nhi phan ==============\n";
        cout << "\t\t1. Nhap danh sach\n";
        cout << "\t\t2. Duyet danh sach - NLR\n";
        cout << "\t\t3. Tim kiem node trong cay\n";
        cout << "\t\t4. Xoa node bat ki trong cay\n";
        cout << "\t\t5. Xuat node co 1 con, 2 con, node la'\n";
        cout << "\t\t6. Tim gia tri lon nhat\n";
        cout << "\t\t7. Dem so luong so nguyen to\n";
        cout << "\t\t8. Tinh tong cac node co gia tri am, duong\n";
        cout << "\t\t9. Xuat cac gia tri lon hon X\n";
        cout << "\t\t10. Dem so nut trong cay\n";
        cout << "\t\t11. Tinh tong cac nut trong cay\n";
        cout << "\t\t0. Thoat chuong trinh\n";
        cout << "\t\t==========================================\n";

        cout << "\nNhap chuc nang: "; cin >> chon;
        if(chon == 0){
            break;
        }
        else if(chon == 1){
            int x;
            cout << "\nNhap gia tri: "; cin >> x;
            ThemNodeVaoCay(t, x);
        }
        else if(chon == 2){
            Duyet_LRN(t);
            cout << endl;
            system("pause");
        }
        else if(chon == 3){
            int x;
            cout << "\nNhap gia tri can tim: "; cin >> x;
            Node *p = TimKiem(t, x);
            if(p == NULL){ // nếu hàm bằng NULL => ptu x k ton tại
                cout << "\nPhan tu " << x << " khong ton tai trong cay\n" << endl;
            }
            else{ // nếu hàm tìm kiếm != NULL => tìm thấy xx
                cout << "\nPhan tu " << x << " co ton tai trong cay\n" << endl;
            }
            system("pause");
        }
        else if(chon == 4){
            int x;
            cout << "\nNhap node can xoa: "; cin >> x;
            XoaNodeBatKy(t, x);
        }
        else if(chon == 5){
            cout << "\nNode co 1 con: "; XuatNode1Con(t);
            cout << "\nNode co 2 con: "; XuatNode2Con(t);
            cout << "\nNode la': "; XuatNodeLa(t);
            system("pause");
        }
        else if(chon == 6){
            cout << "Min: " << TimMin(t) << endl;
            cout << "Max: " << TimMax(t) << endl;
            system("pause");
        }
        else if(chon == 7){
            int count = 0;
            DemSoLuongSNT(t, count);
            cout << "\nSo luong so nguyen to: " << count << endl;
            system("pause");
        }
        else if(chon == 8){
            cout << "Tong duong = " << TinhTongDuong(t) << endl;
            cout << "Tong am = " << TinhTongAm(t) << endl;
            system("pause");            
        }
        else if(chon == 9){
            cout << "Nhap gia tri x: "; cin >> x;
            cout << "Cac phan tu lon hon X: " ; KiemTraGiaTriLonHonX(t, x);
            system("pause");
        }
        else if(chon == 10){
            cout << "\nSo nut trong cay: " << DemSoNutTrongCay(t);
            cout << "\nSo nut la: " << DemNutLa(t);
            cout << "\nSo nut 1 con: " << DemNut1Con(t);
            cout << "\nSo nut 2 con: " << DemNut2Con(t) << endl;
            system("pause");
        }
        else if(chon == 11){
            cout << "\nTong cac nut tren cay: " << TinhTongSoNutTrongCay(t);
            cout << "\nTong nut la: " << TinhTongNutLa(t);
            cout << "\nTong nut 1 con: " << TinhTongNut1Con(t);
            cout << "\nTong nut 2 con: " << TinhTongNut2Con(t);
            system("pause");
        }
        else{
            cout << "\nChuc nang khong dung. Vui long nhap lai!\n";
            system("pause");
        }
    }
}

int main(){
    BinarySearchTree();

    system("pause");
    return 0;
}
/*      ĐỘ PHỨC TẠP CỦA THUẬT TOÁN
----------------------------------------------
thuật toán	| Trung bình  |Trường hợp xấu nhất
----------------------------------------------
Không gian	| Ô( n )	  |     Ô( n )       |   
Tìm kiếm	| O(log n )   |     Ô( n )       |    
Chèn	    | O(log n )   |     Ô( n )       |    
Xóa bỏ	    | O(log n )   |     Ô( n )       |  
----------------------------------------------
*/
