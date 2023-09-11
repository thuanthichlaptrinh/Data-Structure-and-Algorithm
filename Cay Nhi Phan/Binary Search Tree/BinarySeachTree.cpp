// Bài toán: Nhập vào cây nhị phân các số nguyên. xuất ra màn hình các phần tử của cây nhị phân
#include <iostream>
#include <math.h>
#include <limits.h>
#include <fstream>
#include <queue>
#include <stack>
using namespace std;
typedef int value;

// khai báo cấu trúc node
struct Node{
    value data; // dữ liệu chứa trong 1 cái node
    Node *Left; // cây con trái
    Node *Right; // cây con phải
}; 
typedef Node* TREE; // TREE bản chất là 1 con trỏ

// khởi tạo cây
void KhoiTaoCay(TREE &t){
    t = NULL; // cây rỗng
}

// thêm node x vào cây O(log(n))
Node *ThemNodeVaoCay(TREE &t, value x){
    if(t == NULL){ // nếu cây rỗng
        Node *p = new Node; // khởi tạo 1 cái node để thêm vào cây
        p->data = x; // thêm dữ liệu x vào data
        p->Left = p->Right = NULL;
        t = p; // node p là node gốc (root) <=> x chính là node gốc
    }
    else{ // nếu có tồn tại phần tử 
        if(x < t->data){ // nếu ptu thêm vào < node gốc => đệ quy qua trái (để duyệt)
            ThemNodeVaoCay(t->Left, x);
        }
        else if(x > t->data){ // nếu ptu thêm vào > node gốc => đệ quy qua phải (để duyệt)
            ThemNodeVaoCay(t->Right, x);
        }
    }
}

// Kiểm tra cây có rỗng hay không
int IsEmpty(TREE t){
    if(t == NULL){
        return true;
    }
    return false;
}

// ===================== DUYỆT CÂY THEO 6 CÁCH =====================
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
void DuyetCayTheoChieuRong(TREE t){//hàm duyệt cây nhị phân tk theo chiều rộng
	if(t != NULL){ //nếu như cây có tồn tại phần tử
		queue<TREE> a; //tạo queue để tiến hành lưu vết
		a.push(t); //thêm vào queue gốc

		while(!a.empty()){//trong khi a khác rỗng
			Node *p = a.front(); //node p có tác dụng quay lui lại các node trước đó
			cout << p->data << " ";//xuất dữ liệu
			a.pop(); //xửa lý xong xóa trong queue;

			if(p->Left != NULL){ //lần lượt push pleft và pright vào queue theo dạng left right
				a.push(p->Left); //push left
			}
			else if(p->Right != NULL){ //push right
				a.push(p->Right);
			}
		}
	}
}
// void DuyetCayTheoChieuSau(TREE t){
//     if(t != NULL){
//         stack <TREE> a;
//         a.push(t);

//         while(!a.empty()){
//             Node *p = a.top();
//             cout << p->data << " ";
//             a.pop();

//             if(t->Right != NULL){
//                 a.push(p->Right);
//             }
//             else if(p->Left != NULL){
//                 a.push(p->Left);
//             }
//         }
//     }
// }

// ===================== TÌM KIẾM =====================
//tìm kiếm phần tử x trong cây (nếu node có tồn tại trong cây thì trả về cái node đó còn k tồn tại thì trả về NULL)
// TH trung bình: O(log n), TH xấu nhất: O(n)
Node *TimKiem(TREE t, value &x){
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

// ===================== XÓA NODE BẤT KỲ =====================
// tìm node thế mạng (TH trung bình: O(log n); TH tệ nhất O(n))
void TimNodeTheMang(TREE &x, TREE &y){ // *y = t->pRight: là node thế mạng cho node cần xóa (đảm nhận nhiệm vụ tìm ra node trái nhất)
    // cach 1: tìm node tận cùng bên trái của cây con phải
    if(y->Left != NULL){ // duyệt sang trái nhất
        TimNodeTheMang(x, y->Left); // tìm ra node trái nhất
    }
    else{ // y->Left == NULL đã tìm ra đc cái node trái nhất
        x->data = y->data; // cập nhật data của node cần xóa chính là data của node thế mạng
        x = y; // cho node x trỏ đến node thế mạng (node x là node mà ta sẽ xóa)
        y = y->Right; // cập nhật lại node cha của node thế mạng với node con phải của node thế mạng (14->NULL)
    }
    // cách 2:
    /*if(y->pRight != NULL){ // duyệt sang phải 
        timNodeTheMang(x, y->pRight); // tìm ra cái node phải nhất
    }
    else{ // tìm ra đc node phải nhất 
        x->data = y->data;
        x = y; // cho node x (node mà ta sẽ xóa) trỏ đến node thế mạng => ra khỏi hàm thì ta sẽ xóa x
        y = y->pLeft; // cập nhật lại node cha của node thế mạng với node con của node thế mạng
    }*/
}
/* hàm xóa 1 node bất kì trong cây 
Node x là node cần xóa:
1. node lá: xóa bình thường - bời vì lúc này node x đang là node tự do không tồn tại cây con trái và cây con phải
2. node có 1 cóon: trước khi xa node x - chúng ta phải cập nhật mối liên kết
giữa node cha của node x với node con (ct or ct) của node x
3. node có 2 con: trước khi hủy thì ta phải đi tìm 1 cái node thế mạng cho node cần xóa, 
tìm node thế mạng phải đảm bảo quy tắc cây nhị phân tìm kiếm (sau khi thế mạng vẫn đảm bảo tất cả ptu bên nhánh trái nhỏ hơn nó và pt bên nhánh phải nhỏ hơn nó)
 + tìm node trái nhất của cây con phải (ccp của cái node cần xóa)
 + tìm node phải nhất của cây con trái (cct của cái node cần xóa) 
*/
void XoaNodeBatKy(TREE &t, value x){ // data chính là giá trị của node cần xóa
    if(t == NULL){ // nếu cây rỗng 
        return; // kết thúc hàm
    }
    else{ // t != NULL (cây đã có phần tử)
        if(x < t->data){ // nếu node cần xóa < node root 
            XoaNodeBatKy(t->Left, x); // duyệt sang nhánh trái
        }
        else if(x > t->data){ // nếu node cần xóa > node root
            XoaNodeBatKy(t->Right, x); // duyệt sang nhánh phải
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
// hàm xóa toàn bộ cây
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

// ===================== XUẤT CÂY =====================
// node có 1 con(có tồn tại CCT và k tồn tại CCP or k tồn tại CCT và có tồn tại CCPCCP)
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
// node có 2 con (có tồn tại CCT và CCP)
void XuatNode2Con(TREE t){// xuất các nde có 2 con (có tồn tại CCT và CCP)
    if(t != NULL){
        if(t->Left != NULL && t->Right != NULL){
            cout << t->data << " ";
        }
        XuatNode2Con(t->Left);
        XuatNode2Con(t->Right);
    }
}
// node lá (ko tồn tại CCT và CCP)
void XuatNodeLa(TREE t){
    if(t != NULL){
        if(t->Left == NULL && t->Right == NULL){
            cout << t->data << " ";
        }
        XuatNodeLa(t->Left);
        XuatNodeLa(t->Right);
    }
}

// ===================== TÌM MIN, MAX =====================
// tìm max ta chỉ cần tìm kiếm cái node phải cùng bên nhánh phải
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

// ===================== ĐẾM SỐ NGUYÊN TỐ TRONG CÂY =====================
// là số tự nhiên từ 2 trở lên chỉ chia hết cho 1 và chính nó
bool ktraSNT(int n){
    if(n < 2){
        return false;
    }
    else{
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                return false;
            }
        }
    }
    return true;
}
// hàm đếm số lượng số nguyên tố
void DemSoLuongSNT(TREE t, int &count){
    if(t != NULL){ // nếu cây có phần tử
        // xử lí
        if(ktraSNT(t->data) == true){ // nếu só cần ktra là snt => tăng đếm
            count++;
        }
        // duyệt qua từng cái node trong cây (mỗi lần duyệt qua từng cái node trong cây ta sẽ xử lí nếu đúng => tăng đếm)
        DemSoLuongSNT(t->Left, count);
        DemSoLuongSNT(t->Right, count);
    }
}

// ===================== ĐỌC FILE ====================
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
void docFileDauPhay(TREE &t){
    ifstream f;
    f.open("INPUT1.txt", ios_base::in);
    int n;
    f >> n; // doc so luong ptu trong cay
   while(true){
        int x;
        f >> x; // doc tung phan tu trong cay
        ThemNodeVaoCay(t, x);

        char temp;
        f >> temp; // doc dau phay vao trong temp
        if(f.eof() == true){ // neu con tro chi vi nam o cuoi file
            break; // => thoat khoi vong lap vo tan
        }
    }
}


// ===================== HÀM MENU =====================
void BinarySearchTree(){
    TREE t;
    KhoiTaoCay(t);
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
        cout << "\t\t0. Thoat chuong trinh\n";
        cout << "\t\t==========================================\n";

        cout << "\nNhap chuc nang: "; cin >> chon;
        if(chon == 0){
            XoaToanBoCay(t);
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
            if(TimKiem(t, x) == NULL){ // nếu hàm bằng NULL => ptu x k ton tại
                cout << "\nPhan tu " << x << " khong ton tai trong cay\n" << endl;
            }
            else{ // nếu hàm tìm kiếm != NULL => tìm thấy x
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
