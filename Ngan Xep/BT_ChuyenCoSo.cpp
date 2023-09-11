#include <iostream>
using namespace std;
typedef int value;

// khai báo cấu trúc của 1 cái node trong stack
struct node{
    value data; // stack chứa các số nguyên
    node *next; // dùng để liên kết đến các node 
};
// khai báo cấu trúc stack
struct stack{
    node *pTop; // dùng con trỏ đầu để quản lí stack (vi khi lam viec vs stack chta thao tac vs ptu dau cua stack)
};
// hàm khởi tạo stack
void khoiTaoStack(stack &s){
    s.pTop = NULL; // vì đầu tiên nó chưa có liên kết đến ai hết
}
// hàm khởi tạo 1 cái node
node *khoiTaoNode(value x){
    node *p = new node; // cấp phát vùng nhớ cho node p
    if(p == NULL){
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
// ----------------thêm một đối tượng vào đầu stack theo cơ chế LIFO---------------------------
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
// tức là hàm lấy phần tử ở đầu
bool pop(stack &s, value &x){ // x là giá trị cần lấy trong node
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
bool top(stack &s, value &x){ // x chính là giá trị cần lấy ra để xem
    if(isEmpty(s) == true){ // nếu stack rỗng => ko lấy
        return false;
    }
    // ngược lại lấy ptu đầu tiên
    x = s.pTop->data; // lấy giá trị của phần tử đầu stack ra để xem
    return true; // lấy ra thành công
}

// hàm đổi cơ số 10 sang 2, 8, 16
void chuyenCoSo(stack &s, int coSoCanDoi, int heThapPhan){
    while(heThapPhan != 0){ // khi mà giá trị chưa khác 0 thì thực hiện tiếp đến khi = 0 thì dừng
        int x = heThapPhan % coSoCanDoi; // chia lấy phần dư
        node *p = khoiTaoNode(x); // them x vao p
        push(s, p); // them node p vao stack

        heThapPhan /= coSoCanDoi; // lay phan nguyen
    }
}

// ham xuat co so
void xuatCoSo(stack &s){
    while(isEmpty(s) == false){
        int x;
        pop(s, x); // lay ptu o dau
        if(x < 10){
            cout << x;
        }
        else{
            if(x == 10){
                cout << "A";
            }
            else if(x == 11){
                cout << "B";
            }
            else if(x == 12){
                cout << "C";
            }
            else if(x == 13){
                cout << "D";
            }
            else if(x == 14){
                cout << "E";
            }
            else if(x == 15){
                cout << "F";
            }
        }
    }
}

int main(){
    stack s;
    khoiTaoStack(s);
    
    int heThapPhan, coSoCanDoi;
    cout << "\nNhap gia tri he thap phan can chuyen: "; cin >> heThapPhan;
    cout << "\nNhap co so can chuyen(2, 8, 16): "; cin >> coSoCanDoi;

    chuyenCoSo(s, coSoCanDoi, heThapPhan);
    cout << "Ket qua: "; xuatCoSo(s);  cout << "\n";

    system("pause");
    return 0;
}
























