/*
Bài tập: cho file INPUT.TXT có định dạng như sau:
+ dòng đầu tiên là 1 số nguyên biểu diễn số lượng các số nguyên cần đọc
+ dòng thứ 2 là 1 dãy các số nguyên cần đọc
VD: INPUT.TXT
5 
1 4 7 8 9
-----Yêu cầu------
1. khởi tạo cấu trúc dslk đơn các số nguyên và đọc dữ liệu từ file INPUT.TXT
2. xuất các số chính phương
3. tìm phần tử lớn nhất và ghi vào file KETQUA.TXT
4. sắp xếp dslk đơn các số nguyên tăng dần và ghi vào file SAPXEPTANGDAN.TXT

*/
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

// khai báo cấu trúc node
struct node{
    int data;
    node *next;
};
// hàm khởi tạo 1 cái node
node *khoiTaoNode(int x){
    node *p = new node;
    if(p == NULL){
        cout << "\nK du bo nho de cap phat";
        return NULL;
    }
    p->data = x;
    p->next = NULL;
    return p;
}
// them vào đầu
void themDau(node *&pHead, node *p){
    if(pHead == NULL){
        pHead = p;
    }
    else{
        p->next = pHead;
        pHead = p;
    }
}
// them vào cuối
void themCuoi(node *&pHead, node *p){
    if(pHead == NULL){
        pHead = p;
    }
    else{
        for(node *k = pHead; k != NULL; k = k->next){
            if(k->next == NULL){
                k->next = p;
                break;
            }
        }
    }
}

// hàm xuất danh sách lk đơn
void xuatDanhSach(node *pHead){
    for(node *k = pHead; k != NULL; k = k->next){
        cout << k->data << " ";
    }
}

// giải phóng vùng nhớ
void giaiPhongVungNho(node *pHead){
    node *k = NULL;
    while(pHead != NULL){
        k = pHead;
        pHead = pHead->next;
        delete k;
    }
}

// ktra so chinh phuong
bool ktra_SCP(int n){
    int x = sqrt(n);
    if(x*x == n){
        return true;
    }
    return false;
}
// ham xuat cac so chinh phuong trong dslkd
void xuatCacSoChinhPhuong(node *pHead){
    for(node *k = pHead; k != NULL; k = k->next){
        if(ktra_SCP(k->data) == true){
            cout << k->data << " ";
        }
    }
}

// ham tim phan tu lon nhat va ghi vao file
void ghiFileMax(node *&pHead, ostream &fileout){
    int max = pHead->data; // ki thuat dat linh canh (gia su ptu dau tien la lon nhat)
    for(node *k = pHead; k != NULL; k = k->next){
        if(max < k->data){
            max = k->data;
        }
    }
    fileout << max; // ghi max vao file
}
// ham sap xep tang
void sapXepTangDan(node *&pHead){
    for(node *k = pHead; k != NULL; k = k->next){ 
        for(node *h = k->next; h != NULL; h = h ->next){
            if(k->data > h->data){
                int temp = k->data;
                k->data = h->data;
                h->data = temp;
            }
        }
    }
}
// ham ghi vao file cac so nguyen tang dan
void ghiFileTangDan(node *&pHead, ofstream & fileout, int n){
    sapXepTangDan(pHead);
    fileout << n << endl; // luu n
    for(node *k = pHead; k != NULL; k = k->next){
        fileout << k->data << " "; // luu ds da sap xep
    }
}
int main(){
    node *pHead = NULL; // khoi tao con tro dau de quan li dslk
    ifstream filein;
    filein.open("INPUT.TXT", ios_base::in);
    if(filein.fail() == true){
        cout << "\nFile k ton tai";
        exit(1);
    }
    int n;
    filein >> n; // doc gia tri n
    for(int i = 1; i <= n; i++){
        int x;
        filein >> x; // doc tung node
        node *p = khoiTaoNode(x);
        themCuoi(pHead, p);
    }
    // xuat danh sach lien ket don
    xuatDanhSach(pHead);
    // xuat cac so chinh phuong
    cout << "\nCac so chinh phuong: ";
    xuatCacSoChinhPhuong(pHead);
    // ghi gia tri max vao file 
    ofstream fileout;
    /*fileout.open("KETQUA.txt", ios_base::out);
    ghiFileMax(pHead, fileout);*/

    fileout.open("SAPXEPTANG.txt", ios_base::out);
    ghiFileTangDan(pHead, fileout, n);
    
    giaiPhongVungNho(pHead);
    // dong file
    fileout.close();
    filein.close();
    system("pause");
    return 0;
}