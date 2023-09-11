#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct PhanSo{
	int TuSo;
	int MauSo;
}; typedef PhanSo value;

struct Node{
	PhanSo data;
	Node *Left;
	Node *Right;
}; typedef Node* Tree;

void KhoiTaoCay(Tree &t){
    t = NULL;
}
Node *ThemNodeVaoCay(Tree &t, value x){
    if(t == NULL){
        Node *p = new Node;
        p->data = x;
        p->Left = p->Right = NULL;
        t = p;
    }
    else{
        if(((float)x.TuSo / x.MauSo) < ((float)t->data.TuSo / t->data.MauSo)){
            ThemNodeVaoCay(t->Left, x);
        }
        else if(((float)x.TuSo / x.MauSo) > ((float)t->data.TuSo / t->data.MauSo)){
            ThemNodeVaoCay(t->Right, x);
        }
    }
}
void NhapPhanSo(Tree &t){
    value x;
    cout << "Nhap tu so: "; cin >> x.TuSo;
    cout << "Nhap mau so: "; cin >> x.MauSo;
    ThemNodeVaoCay(t, x);
}
void DuyetCayNLR(Tree t){
    if(t != NULL){
        cout << t->data.TuSo << "/" << t->data.MauSo << " ";
        DuyetCayNLR(t->Left);
        DuyetCayNLR(t->Right);
    }
}
int DemSoLuongPhanSoLonHon1(Tree t){
    int cout = 0;
    if(t != NULL){
        if(((float)t->data.TuSo / t->data.MauSo) > 1){
            cout++;
        }
        cout += DemSoLuongPhanSoLonHon1(t->Left);
        cout += DemSoLuongPhanSoLonHon1(t->Right);
    }
    return cout;
}
int TimKiem(Tree t, value x){
    if(t == NULL){
        return 0;
    }
    else if(x.TuSo == t->data.TuSo && x.MauSo == t->data.MauSo){
        return 1;
    }
    return (TimKiem(t->Left, x) || TimKiem(t->Right, x));
}
int UCLN(int a, int b){
    while(a != b){
        if(a > b){
            a -= b;
        }
        else{
            b -= a;
        }
    }
    return a;
}
void ToiGianPhanSo(value ps){
    if(ps.TuSo != 0){
        int u = UCLN(ps.TuSo, ps.MauSo);
        ps.TuSo /= u;
        ps.MauSo /= u;
    }
    cout << ps.TuSo << "/" << ps.MauSo << " ";
}
void ToiGianPhanSoTrenCay(Tree t){
    if(t != NULL){
        ToiGianPhanSo(t->data);
        ToiGianPhanSoTrenCay(t->Left);
        ToiGianPhanSoTrenCay(t->Right);
    }
}
int TimMin(Tree t){
    if(t->Left == NULL){
        cout << t->data.TuSo << "/" << t->data.MauSo;
        return 1;
    }
    return TimMin(t->Left);
}
int TimMax(Tree t){
    if(t->Right == NULL){
        cout << t->data.TuSo << "/" << t->data.MauSo;
        return 1;
    }
    return TimMax(t->Right);
}
float TinhTong(Tree t){
    if(t == NULL){
        return 0;
    }
    return TinhTong(t->Left) + TinhTong(t->Right) + ((float)t->data.TuSo / t->data.MauSo);
}
void LietKePsCoTuLonHonMau(Tree t){
    if(t != NULL){
        if(t->data.TuSo > t->data.MauSo){
            cout << t->data.TuSo << "/" << t->data.MauSo << " ";
        }
        LietKePsCoTuLonHonMau(t->Left);
        LietKePsCoTuLonHonMau(t->Right);
    }
}
void LietKePsCoTuBeHonMau(Tree t){
    if(t != NULL){
        if(t->data.TuSo < t->data.MauSo){
            cout << t->data.TuSo << "/" << t->data.MauSo << " ";
        }
        LietKePsCoTuBeHonMau(t->Left);
        LietKePsCoTuBeHonMau(t->Right);
    }
}
bool KtraSNT(int n){
    if(n < 2){
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
void LietKePsCoTuVaMauLaSNT(Tree t){
    if(t != NULL){
        if(KtraSNT(t->data.TuSo) && KtraSNT(t->data.MauSo)){
            cout << t->data.TuSo << "/" << t->data.MauSo << " ";
        }
        LietKePsCoTuVaMauLaSNT(t->Left);
        LietKePsCoTuVaMauLaSNT(t->Right);
    }
}
bool KtraSCP(int n){
    if(n < 1){
        return false;
    }
    if(sqrt(n) * sqrt(n) == n){
        return true;
    }
    return false;
}
void LietKePsCoTuVaMauLaSCP(Tree t){
    if(t != NULL){
        if(KtraSCP(t->data.TuSo) && KtraSCP(t->data.MauSo)){
            cout << t->data.TuSo << "/" << t->data.MauSo << " ";
        }
        LietKePsCoTuVaMauLaSCP(t->Left);
        LietKePsCoTuVaMauLaSCP(t->Right);
    }
}
float TinhTongPhanSoMucK(Tree t, int k){
    float tong = 0;
    if(t != NULL){
        if(k == 0){
            tong += (float)t->data.TuSo / t->data.MauSo;
        }
        tong += TinhTongPhanSoMucK(t->Left, k - 1);
        tong += TinhTongPhanSoMucK(t->Right, k - 1);
    }
    return tong;
}
int demPS(Tree t, int k){
    int dem = 0;
    if(t == NULL){
        return 0;
    }
    else if(k == 0){
        dem++;
    }
    return dem + demPS(t->Left, k - 1) + demPS(t->Right, k - 1);
}
void DocFile(Tree &t){
    ifstream f;
    f.open("PHANSO.txt", ios::in);
    int n; f >> n;
    for(int i = 1; i <= n; i++){
        value x; 
        f >> x.TuSo; f.ignore();
        f >> x.MauSo;
        ThemNodeVaoCay(t, x);
    }
}
void NgoMinhThuan(){
    Tree t; value ps;
    KhoiTaoCay(t); 
    int x, LuaChon;
    DocFile(t);
    while(1){
        system("cls");
        cout << "1. Them\n";
        cout << "2. Xuat\n";
        cout << "3. dem ps > 1\n";
        cout << "4. tiem kiem\n";
        cout << "5. Toi gian ps\n";
        cout << "6. Tim min max\n";
        cout << "7. Tinh tong\n";
        cout << "8. Liet ke ps co tu > < mau\n";
        cout << "9. Liet ke ps la snt\n";
        cout << "10. Liet ke ps la scp\n";
        cout << "11. Liet ke ps o muc k\n";
        cout << "12. Tong ps muc k\n";

        cout << "Nhap chuc nang: "; cin >> LuaChon;
        if(LuaChon == 1){
            NhapPhanSo(t);
        }
        else if(LuaChon == 2){
            DuyetCayNLR(t);
            system("pause");
        }
        else if(LuaChon == 3){
            cout << "ps > 1: " << DemSoLuongPhanSoLonHon1(t);
            system("pause");
        }
        else if(LuaChon == 4){
            cout << "Nhap tu so: "; cin >> ps.TuSo;
            cout << "Nhap mau so: "; cin >> ps.MauSo;    
            if(TimKiem(t, ps) == 1){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
            system("pause");
        }
        else if(LuaChon == 5){
            ToiGianPhanSoTrenCay(t);
            system("pause");
        }
        else if(LuaChon == 6){
            cout << "\nMin: "; TimMin(t);
            cout << "\nMax: "; TimMax(t);
            system("pause");
        }
        else if(LuaChon == 7){
            cout << "Tong cac phan so: " << TinhTong(t) << endl;
            system("pause");
        }
        else if(LuaChon == 8){
            cout << "\nCac ps co tu < mau: "; LietKePsCoTuBeHonMau(t);
            cout << "\nCac ps co tu > mau: "; LietKePsCoTuLonHonMau(t);
            system("pause");
        }
        else if(LuaChon == 9){
            LietKePsCoTuVaMauLaSNT(t);
            system("pause");
        }
        else if(LuaChon == 10){
            LietKePsCoTuVaMauLaSCP(t);
            system("pause");
        }
        else if(LuaChon == 12){
            int k = 2;
            cout << "Tong cac ps o muc k: " << TinhTongPhanSoMucK(t, k);
            cout << "So luong ps o muc k: " << demPS(t, k);
            system("pause");

        }
    }
}

int main(){
    NgoMinhThuan();
    system("pause");
    return 0;
}