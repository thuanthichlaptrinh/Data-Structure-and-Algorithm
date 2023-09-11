/*-------------------------- Queue (Hàng Đợi) -------------------------------------------------

- khái niệm: queue là 1 cấu trúc trừu tượng, các đối tượng trong queue phải làm việc theo 1 
FIFO(first in first out): đối tượng nào vào trước thì sẽ ra trước

- IsEmpty: ktra queue có rỗng hay k
- Push: thêm 1 đối tượng vào cuối queue 
- Pop: lấy ptu đầu queue và trả về giá trị của đối tượng đầu queue đồng thời phải hủy nó đi
- Top: xem thông tin của phần tử đầu queue và không hủy nó đi
=> 4 thao tác này làm việc theo 1 cơ chế đó là FIFO

-----------------------------End------------------------------------------------------------*/
// bài toán nhập ds queue chứa các số nguyên , sau đó xuất ra màn hình các số nguyên đó
#include <iostream>
using namespace std;

// khai báo cấu trúc của 1 cái node trong queue
struct node{
    int data; // queue chứa các só nguyên
    node *next; // liên kết các node lại với nhau
};

// khai báo cấu trúc queue
struct queue{
    node *pHead; // dùng con trỏ đầu để quản lí queue
    node *pTail;  // dùng con trỏ cuối để quản lí queue
};

// hàm khởi tạo queue
void khoiTaoQueue(queue &q){
    q.pHead =q.pTail = NULL;  // cho 2 node trỏ đến NULL (vì queue chưa có liên kết đến ai hết)
}

// hàm khởi tạo 1 cái node
node *khoiTaoNode(int x){
    node *p = new node; // cấp phát vùng nhớ cho node p để thêm vào
    if(p == NULL){
        cout << "\nKhong du bo nho de cap phat\n";
        return NULL;
    }
    p->data = x; // gán giá trị của biến x vào data
    p->next = NULL; // đầu tiên khi khai báo node thì node đó ch có lk đến node nào hết => trỏ đến NULL 
    return p; // trả về giá trị của cái node vừa khởi tạo
}

// ktra queue có rỗng hay không
bool isEmpty(queue q){
    if(q.pHead == NULL){ // nếu ds rỗng => tra ket qua đúng
        return true;
    }
    return false; // ngược lại ds có phần tử => tra ve ket qua sai
}

// thêm một đối tượng vào cuối queue theo cơ chế FIFO
bool push(queue &q, node *p){ 
    if(p == NULL){ // neu khoi tao node p k thanh cong
        return false;
    }
    if(isEmpty(q) == true){ // nếu danh sách đang rỗng tuc la q.pHead == NULL
        q.pHead = q.pTail = p; // node p chinh la node dau queue
    }
    else{ // danh sach da co ptu
       q.pTail->next = p; // lk con trỏ cuối của ptu p cần thêm vào
       q.pTail = p; // cập nhật lại con trỏ cuối là node p
    }
    return true;
}

// lấy ptu đầu queue và hủy nó đi theo cơ chế fifo
bool pop(queue &q, int &x){ // x là giá trị cần lấy trong node
    if(isEmpty(q) == true){ // nếu ds rỗng
        return false;
    }
    else{
        node *p = q.pHead; // node p chính là node thế mang để xóa nó đi
        x = p->data; // gán giá trị của node đầu queue vào biến x
        q.pHead = q.pHead->next; // cập nhật node đầu queue là node tiếp theo
        delete p; // xóa node queue vừa lấy
    }
    return true; // lấy ptu đầu queue thành công
}

// xem thông tin của ptu đầu queue - và không hủy nó đi
bool top(queue &q, int &x){ // x chính là giá trị cần lấy ra để xem
    if(isEmpty(q) == true){ // nếu queue rỗng => ko lấy
        return false;
    }
    // ngược lại lấy ptu đầu tiên
    x = q.pHead->data; // lấy giá trị của phần tử đầu queue ra để xem
    return true; // lấy ra thành công
}
// xuất danh sách queue
void xuatQueue(queue q){
    while(isEmpty(q) == false){ // khi ds còn phần tử
        int x;
        pop(q, x); // lấy ptu đầu và hủy nó đi
        cout << x << " ";  
    }
}

// nhập ds các số nguyên trong queue
void nhapQueue(queue &q){
    int x, chon;
    while(true){
        system("cls");
        cout << "\t\t--------------------Queue-------------------\n";
        cout << "\t\t1. Them phan tu vao queue - push\n";
        cout << "\t\t2. Xuat danh sach queue ra man hinh - pop\n";
        cout << "\t\t3. Xem thong tin phan tu dau queue - top\n";
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
            push(q, p);
        }
        else if(chon == 2){
            xuatQueue(q);
            system("pause");
        }
        else if(chon == 3){
            int x;
            top(q, x);
            cout << "\nPhan tu dau queue la: " << x;
            cout << endl;
            system("pause");
        }
        else{
            cout << "Loi chuc nang vui long nhap lai.\n";
            system("pause");
        }
    }
}

int main(){
    queue s;
    khoiTaoQueue(s);
    nhapQueue(s);

    system("pause");
    return 0;
}
