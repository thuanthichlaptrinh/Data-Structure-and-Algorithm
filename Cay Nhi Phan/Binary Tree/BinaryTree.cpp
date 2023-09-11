#include <iostream>
using namespace std;

// khai báo 1 cái node 
struct node{
    int data;
    node *Left;
    node *Right;
};
typedef node* TREE;
// khởi tạo cây
void KhoiTaoCay(TREE &t){
    t = NULL;
}
// tạo nút mới 
node *createNode(int x){
    node *p = new node;
    if(p == NULL){
        cout << "\nKhong du bo nho de cap phat";
        return NULL;
    }
    p->data = x;
    p->Left = p->Right = NULL;
    return p;
}

// thêm nút con bên trái
bool insertNodeLeft(TREE t, int x){
    if(t == NULL){ 
        return false; // không tồn tại nút T
    }
    if(t->Left != NULL){
        return false; // đã tồn tại con trái
    }
    node *p = createNode(x);
    t->Left = p;
    return true;
}
// thêm nút con bên phải
bool insertNodeRight(TREE t, int x){
    if(t == NULL){
        return false; // không tồn tại nút T
    }
    if(t->Right != NULL){
        return false; // đã tồn tại con phải
    }
    node *p = new node;
    t->Right = p;
    return true;
}
// xuất NLR
void Duyet_NLR(TREE t){
    if(t != NULL){ // nếu cây còn phân tử thì tiếp tục duyệt
        cout << t->data << " "; // xuất dữ liệu trong node
        Duyet_NLR(t->Left); // duyệt sang trái
        Duyet_NLR(t->Right); // duyệt sang phải
    }
}
// xuất LRN
void Duyet_LRN(TREE t){
    if(t != NULL){
        Duyet_LRN(t->Left);
        Duyet_LRN(t->Right);
        cout << t->data << " ";
    }
}
// xóa nút con trái của T
bool delete_Node_Left(TREE t){
    if(t == NULL){
        return false;
    }
    node *p = t->Left;
    if(p == NULL){
        return false;
    }
    if(p->Left != NULL || p->Right != NULL){
        return false;
    }
    delete p;
    return true;
}
// xóa nút con phải của T
bool delete_Node_Right(TREE t){
    if(t == NULL){
        return false;
    }
    node *p = t->Right;
    if(p == NULL){
        return false;
    }
    if(p->Left != NULL || p->Right != NULL){
        return false;
    }
    delete p;
    return true;
}
// tìm nút có khóa K
node *findNode(TREE t, int &x){
    if(t == NULL){ // nếu cây rỗng => trả về NULL
        return NULL;
    }
    else{
        if(x < t->data){ // nếu ptu cần tìm < node gốc => đệ quy qua trái để tìm
            findNode(t->Left, x);
        }
        else if(x > t->data){ // nếu ptu cần tìm > node gốc => đệ quy qua phải đề tìm
            findNode(t->Right, x);
        }
        else{ // x == t->data => trả về cái node cần tìm kiếm
            return t;
        }
    }
}
// xóa cây
int deleteTree(TREE &t){
    if(t == NULL){
        return 0;
    }
    deleteTree(t->Left);
    deleteTree(t->Right);
    delete t;
    return 1;
}

int x;
// hàm nhập
void menu(TREE &t){
     int luaChon, x;
    while(true){
        system("cls");
        cout << "1. Them node vao cay\n";
        cout << "2. Them node con trai\n";
        cout << "3. Them node con phai\n";
        cout << "4. Duyet cay\n";
        cout << "5. Xoa node con trai\n";
        cout << "6. Xoa node con phai\n";
        cout << "7. Tim nut co khoa K\n";
        cout << "8. Xoa cay\n";
        cout << "0. Thoat chuong trinh\n";

        cout << "\nNhap chuc nang: "; cin >> luaChon;
        switch (luaChon){
        case 0:
            break;
        case 1:
            cout << "\nNhap node can them: "; cin >> x;
            createNode(x);
            break;
        case 2: 
            cout << "\nNhap node con trai can them: "; cin >> x;
            insertNodeLeft(t, x);
            break;
        case 3:
            cout << "\nNhap node con phai can them: "; cin >> x;
            insertNodeRight(t, x);
            break;
        case 4:
            cout << "\nDuyet LRN: "; Duyet_LRN(t);
            cout << endl;
            system("pause");
            break;
        case 5: 
            delete_Node_Left(t);
            break;
        case 6:
            delete_Node_Right(t);
            break;
        case 7:
            cout << "\nNhap node can tim: "; cin >> x;
            if(findNode(t, x) == NULL){
                cout << "\nKhong tim thay node " << x << " trong cay\n";
            }
            else{
                cout << "\nTim thay node " << x << " trong cay\n";
            }
            system("pause");
            break;
        case 8:
            deleteTree(t);
            break;
        default:
            cout << "\nSai chuc nang. Vui long nhap lai!";
            system("pause");
            break;
        }
    }
}
int main(){
    TREE t;
    KhoiTaoCay(t);
    menu(t);

    system("pause");
    return 0;
}