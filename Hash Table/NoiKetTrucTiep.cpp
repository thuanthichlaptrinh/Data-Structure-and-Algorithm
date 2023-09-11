#include <iostream>
using namespace std;

#define MAXSIZE 7 // kích thước cuả bảng băm

// khai báo cấu trúc 1 cái node
struct node{
    int key; // lưu địa chỉ của bảng băm
    node *next; 
};
node* bucket[MAXSIZE];

// khởi tạo bảng băm
void initHash(node *heads[]){ 
    for(int i = 0; i < MAXSIZE; i++){
        heads[i] = NULL;
    }
}

// khởi tạo 1 cái node
node *createNode(int x){
    node *p = new node;
    p->key = x;
    p->next = NULL;
    return p;
}

// hàm băm
int hashFunc(int value){
    return (value % MAXSIZE);
}

// thêm phần tử vào bản băm (theo trật tự tăng)
void insertNode(node *heads[], int value){
    int h = hashFunc(value); // giá trị băm
    node *r = heads[h]; // vị trí thứ h
    node *prev = NULL;

    while(r != NULL && r->key < value){ // value: giá trị chèn
        prev = r; // giữ vết của prev 
        r = r->next; // duyệt r cho đến khi ko thỏa đk thì dừng
    }

    node *p = createNode(value);
    if(prev == NULL){ // thêm vào đầu
        heads[h] = p; // cho heads trỏ đến node cần thêm
        p->next = r;
    }
    else if(r == NULL){ // thêm vào cuối
        prev->next = p;
    }
    else{ // thêm vào trước r
        p->next = r;
        prev->next = p;
    }
}

bool isEmpty(){
    for(int i = 0; i < MAXSIZE; i++){
        if(bucket[i] != NULL){
            return false;
        }
    }
    return true;
}

// xóa 1 nút ở đầu bucket
int Pop(int value){
    node *p = bucket[value]; 
    int k = p->key;
    bucket[value] = p->next;
    delete p;
    return k;
}

// xóa một nút nằm sau nút p
int deleteAfter(node *p){
    node *q = p->next;
    int k = q->key;
    p->next = q->next;
    delete q;
    return k;
}

// hàm xóa 1 phần tử có khóa k trong bảng băm
void remove(node *heads[], int k){
    int h = hashFunc(k);
    node *q, *p = heads[h];

    while(p != NULL && p->key != k){
        q = p;
        p = p->next;
    }
    if(p == NULL){
        printf("\nKhong co hashnode co khoa la %d", h);
    }
    else if(p == bucket[h]){ // xoa nut o dau but ket
        Pop(h);  
    }
    else{  // xóa một nút nằm sau nút p
        deleteAfter(q);
    }
}

// hàm xuất
void display(node *heads[]){
    for(int i = 0; i < MAXSIZE; i++){
        if(heads[i] != NULL){ // co gia tri moi xuat ra
            printf("Bucket %d: ", i);
            node *p = heads[i]; // tro vao ptu dau cua ds thu i

            while(p != NULL){ 
                printf("%d  ", p->key);
                p = p->next;
            }
            printf("\n");
        }
    }
}

// ham tim kiem 
node *search(node *heads[], int value){
    int h = hashFunc(value); // giá trị băm
    node *r = heads[h]; 
    
    while(r != NULL && r->key != value){
        r = r->next;
    }
    return r; 
}

// hàm nhập bảng băm
void NhapBangBam(){
    node *heads[MAXSIZE];
    initHash(heads);
    int luaChon, x;
    while(1){
        system("cls");
        printf("-------------- Hash Table --------------\n");
        printf("1. Them phan tu vao bang bam.\n");
        printf("2. Xuat bang bam.\n");
        printf("3. Xoa phan tu khoi bang bam.\n");
        printf("4. Tim kiem mot pha n tu trong bang bam.\n");
        printf("0. Thoat chuong trinh.\n");
        printf("----------------- End ------------------\n");

        printf("\nNhap chuc nang: "); scanf("%d", &luaChon);
        if(luaChon == 0){
            break;
        }
        else if(luaChon == 1){
            printf("\nNhap gia tri: "); scanf("%d", &x);
            insertNode(heads, x);
        }
        else if(luaChon == 2){
            display(heads);
            system("pause");
        }
        else if(luaChon == 3){
            printf("\nNhap phan tu can xoa: "); scanf("%d", &x);
            remove(heads, x);
        }
        else if(luaChon == 4){
            printf("\nNhap phan tu can tim: ");
            scanf("%d", &x);
            
            if(search(heads, x) == NULL){
                printf("Khong tim thay phan tu %d\n", x);
            }
            else{
                printf("Tim thay phan tu %d\n", x);
            }
            system("pause");
        }
        else{
            printf("Chuc nang khong dung. Vui long nhap lai !\n");
            system("pause");
        }
    }
}

int main(){
    NhapBangBam();

    return 0;
}