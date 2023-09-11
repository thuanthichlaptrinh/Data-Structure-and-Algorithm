#include <iostream>
using namespace std;

struct PhanSo{
    int tuSo;
    int mauSo;
};

// nhap phan so
void nhapPhanSo(PhanSo &ps){
    printf("\nNhap tu so: "); scanf("%d", &ps.tuSo);
    printf("\nNhap mau so: "); scanf("%d", &ps.mauSo);
}
// xuat phan so
void xuatPhanSo(PhanSo ps){
    printf("%d/%d ", ps.tuSo, ps.mauSo);
}

struct AVLNode{
    int balFactor;
    PhanSo data;
    AVLNode *Left;
    AVLNode *Right;
};


int main(){

    system("pause");
    return 0;
}