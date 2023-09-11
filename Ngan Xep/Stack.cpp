/*-------------------------- STACK (Ngăn Xếp) ----------------------------------------------------------

- khái niệm: stack là 1 cấu trúc trừu tượng, các đối tượng trong stack phải làm việc theo 1 
LIFO(last in first out): đối tượng nào vào sau thì sẽ ra trước

- IsEmpty: ktra stack có rỗng hay k
- Push: thêm 1 đối tượng vào đầu stack
- Pop: lấy ptu đầu stack và trả về giá trị của đối tượng đầu stack đồng thời hủy nó đi
- Top: xem thông tin của phần tử đầu stack và không hủy nó đi
=> 4 thao tác này làm việc theo 1 cơ chế đó là LIFO

------------------------------------------------------------------------------------------------*/
// bài toán nhập ds stack chứa các số nguyên , sau đó xuất ra màn hình các số nguyên đó
#include <iostream>
using namespace std;

// khai báo cấu trúc của 1 cái node trong stack
struct node{
    int data; // stack chứa các số nguyên
    node *next; // dùng để liên kết đến các node 
};

// khai báo cấu trúc stack
struct stack{
    node *pTop; // dùng con trỏ đầu để quản lí stack (vi khi lam viec vs stack chta thao tac vs ptu dau cua stack)
};

// hàm khởi tạo stack
void initStack(stack &s){
    s.pTop = NULL; // vì đầu tiên nó chưa có liên kết đến ai hết
}

// hàm khởi tạo 1 cái node
node *khoiTaoNode(int x){
    node *p = new node; // cấp phát vùng nhớ cho node p
    if(p == NULL){ // khởi tạo không thành côngcông
        cout << "\nKhong du bo nho de cap phat\n";
        return NULL;
    }
    p->data = x; // gán giá trị của biến x vào data
    p->next = NULL; // đầu tiên khai báo thì node p ch trỏ đến ai hết => cho trỏ vào NULL
    return p; 
}

// ktra stack có rỗng hay không
bool isEmpty(stack s){
    if(s.pTop == NULL){ // nếu ds rỗng
        return true;
    }
    return false; // ngược lại => ds có phần tử
}

// ----------------thêm một đối tượng vào đầu stack ---------------------------
bool push(stack &s, node *p){ // hàm thêm vào đầu
    if(p == NULL){ // nếu p khởi tạo k thành công
        return false;
    }
    if(isEmpty(s) == true){ // nếu danh sách đang rỗng
        s.pTop = p; // node p chinh la node dau stack
    }
    else{ // danh sach da co ptu
        p->next = s.pTop; // cho con tro cua node p tro den node dau ds <=> tao lien ket
        s.pTop = p; // cap nhat lai node dau
    }
    return true;
}

// ---------------------lấy ptu đầu stack và hủy nó đi--------------------------------------------
// => ham xoa phan tu dau (lay data cua node dau)
bool pop(stack &s, int &x){ // x là giá trị cần lấy trong node
    if(isEmpty(s) == true){ // nếu ds rỗng
        return false;
    }
    else{
        node *p = s.pTop; // node p chính là node thế mang để xóa nó đi
        x = p->data; // gán giá trị của node đầu stack vào biến x
        s.pTop = s.pTop->next; // cập nhật node đầu stack là node tiếp theo
        delete p; // xóa node stack vừa lấy
    }
    return true; // lấy ptu đầu stack thành công
}

// ----------------------xem thông tin của ptu đầu stack - và không hủy nó đi---------------------
// tức là hàm xem giá trị đầu
bool top(stack &s, int &x){ // x chính là giá trị cần lấy ra để xem
    if(isEmpty(s) == true){ // nếu stack rỗng 
        return false;
    }
    // ngược lại lấy ptu đầu tiên
    x = s.pTop->data; // lấy giá trị của phần tử đầu stack ra để xem
    return true; // lấy ra thành công
}

// tim kiem
node *search_Node(stack &s, int x) {
    node *q = s.pTop;
    while (q != NULL) {
        if (q->data == x) {
            return q;
        }
        q = q->next;
    }
    return NULL;
}

// xuất danh sách stack
void xuatStack(stack s){
    while(isEmpty(s) == false){ // khi ds còn phần tử
        int x;
        pop(s, x); // lấy ptu đầu và hủy nó đi
        cout << x << " ";  
    }
}

// nhập ds các số nguyên trong stack
void nhapStack(stack &s){
    int x, chon;
    while(true){
        system("cls");
        cout << "\t\t--------------------Stack-------------------\n";
        cout << "\t\t1. Them phan tu vao stack - push\n";
        cout << "\t\t2. Xuat danh sach stack ra man hinh - pop\n";
        cout << "\t\t3. Xem thong tin phan tu dau stack - top\n";
        cout << "\t\t0. Thoat chuong trinh\n";
        cout << "\t\t---------------------End--------------------\n";
            
        cout << "\nNhap chuc nang: "; cin >> chon;
        if(chon == 0){
            break;
        }
        else if(chon == 1){
            cout << "\nNhap phan tu can them: "; 
            cin >> x;
            node *p = khoiTaoNode(x);
            push(s, p);
        }
        else if(chon == 2){
            xuatStack(s);
            system("pause");
        }
        else if(chon == 3){
            int x;
            top(s, x);
            cout << "\nPhan tu dau stack la: " << x;
            system("pause");
        }
        else{
            cout << "Loi chuc nang vui long nhap lai.\n";
            system("pause");
        }
    }
}

int main(){
    stack s;
    initStack(s);
    nhapStack(s);

    system("pause");
    return 0;
}
























