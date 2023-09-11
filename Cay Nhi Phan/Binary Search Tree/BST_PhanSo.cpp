#include <iostream>
#include <fstream>
#include <time.h> 
#include <cmath> 
using namespace std;

// cau truc phan so
struct PhanSo{
	int TuSo;
	int MauSo;
}; typedef PhanSo value;

// cau truc 1 cai node
struct Node{
	PhanSo data;
	Node *Left;
	Node *Right;
}; typedef Node* Tree;

// ========================== NGUYEN MAU HAM ==========================
void khoiTaoCay(Tree &t);
Node *ThemNodeVaoCay(Tree &t, PhanSo x);
void Duyet_NLR(Tree t);
void Duyet_NRL(Tree t);
void Duyet_LNR(Tree t);
void Duyet_LRN(Tree t);
void Duyet_RNL(Tree t);
void Duyet_RLN(Tree t);
int DemSoLuongPsLonHon1(Tree &t);
int UCLN(int a, int b);
void ToiGianPhanSo(value p);
void ToiGianTrenCay(Tree t);
int TimKiem(Tree t, value x);
int TimPhanSoMax(Tree t);
int TimPhanSoMin(Tree t);
void LietKePsCoTuLonHonMau(Tree t);
void LietKePsCoTuNhoHonMau(Tree t);
void LietKePhanSoMucK(Tree t, int k);
int ktraSNT(int n);
void LietKePhanSoLaSNT(Tree t);
float TinhTongPhanSo(Tree root);
float TongCacPsMucK(Tree t, int k);
int DemSoLuongPsMucK(Tree t, int k);
bool KTraSoChinhPhuong(int n);
void LietKePhanSoLaSCP(Tree t);
void docFile(Tree &t);

// ============================ HAM MENU ============================
void menu(){
	Tree t;
	value ps, tu, mau;
	khoiTaoCay(t);
	int k, x, n, ChucNang;
	docFile(t);
	while (1){
		system("cls");
		cout << "\t1. Them node vao cay nhi phan\n";
		cout << "\t2. Duyet cay nhi phan bang 6 cach\n";
        cout << "\t3. Dem so luong phan so lon hon 1\n";
		cout << "\t4. Tim kiem gia tri bang voi gia tri x\n";
		cout << "\t5. Toi gian phan so tren cay\n";
		cout << "\t6. Tim min max trong cay\n";
		cout << "\t7. Tinh tong cac phan so\n";
		cout << "\t8. Liet ke phan so co tu lon / be hon mau\n";
		cout << "\t9. Liet ke cac phan so o muc k\n"; 
		cout << "\t10. Liet ke phan so la so nguyen to\n";
		cout << "\t11. Tinh tong phan so o muc k\n"; 
		cout << "\t12. Dem so luong phan so o muc k\n"; 
		cout << "\t13. Liet ke cac phan so la so chinh phuong\n";
		cout << "\t0. Thoat chuong trinh\n";

		cout << "Nhap chuc nang: "; cin >> ChucNang;
		if (ChucNang == 0) {
			break;
		}
		else if (ChucNang == 1){
			cout << "Nhap tu so: "; cin >> ps.TuSo;
            cout << "Nhap mau so: "; cin >> ps.MauSo;
			ThemNodeVaoCay(t, ps);
		}
		else if (ChucNang == 2){
			cout << "\nDuyet NLR: "; Duyet_NLR(t);
			// cout << "\nDuyet LNR: "; Duyet_LNR(t);
			// cout << "\nDuyet LRN: "; Duyet_LRN(t);
			// cout << "\nDuyet NRL: "; Duyet_NRL(t);
			// cout << "\nDuyet RNL: "; Duyet_RNL(t);
			// cout << "\nDuyet RLN: "; Duyet_RLN(t);
			system("pause");
		}
		else if (ChucNang == 3){
			cout << "Cac phan so lon hon 1: " << DemSoLuongPsLonHon1(t) << endl;
			system("pause");
		}
		else if(ChucNang == 4){
			cout << "Nhap tu so: "; cin >> ps.TuSo;
			cout << "Nhap mau so: "; cin >> ps.MauSo;
			if(TimKiem(t, ps)){
				cout << "Phan so ton tai trong cay\n";
			}
			else{
				cout << "Phan so khong ton tai trong cay\n";
			}
			system("pause");
		}
		else if(ChucNang == 5){
			cout << "Phan so sau khi toi gian: "; ToiGianTrenCay(t);
			system("pause");
		}
		else if(ChucNang == 6){
			TimPhanSoMax(t);
			TimPhanSoMin(t);
			system("pause");
		}
		else if(ChucNang == 7){
			cout << "Tong cac phan so: " << TinhTongPhanSo(t); 
			system("pause");
		}
		else if(ChucNang == 8){
			cout << "\nPhan so co tu > mau: "; LietKePsCoTuLonHonMau(t);
			cout << "\nPhan so co tu < mau: "; LietKePsCoTuNhoHonMau(t);
			system("pause");
		}
		else if(ChucNang == 9){
			cout << "Nhap muc k: "; cin >> k;
			cout << "\nPhan so o muc " << k << ": "; LietKePhanSoMucK(t, k);
			system("pause");
		}
		else if(ChucNang == 10){
			cout << "Cac phan so co tu va mau la SNT: "; LietKePhanSoLaSNT(t);
			cout << endl;
			system("pause");
		}
		else if(ChucNang == 11){
			cout << "Nhap muc k: "; cin >> k;
			cout << "Tong cac phan so o muc k: " << TongCacPsMucK(t, k); 
			system("pause");
		}
		else if(ChucNang == 12){
			cout << "Nhap muc k: "; cin >> k;
			cout << "So luong phan so o muc k: " << DemSoLuongPsMucK(t, k);
			system("pause");
		}
		else if(ChucNang == 13){
			cout << "Cac so chinh phuong: "; LietKePhanSoLaSCP(t);
			system("pause");
		}
		else{
			cout << "Sai chuc nang vui long nhap lai\n";
			system("pause");
		}
	}
}

int main(){
	menu();

	system("pause");
	return 0;
}

// ========================== XU LI ==========================
void khoiTaoCay(Tree &t){
	t = NULL;
}
Node *ThemNodeVaoCay(Tree &t, PhanSo x){
	if (t == NULL){
		Node *p = new Node;
		p->data = x;
		p->Left = p->Right = NULL;
		t = p;
	}
	else{
		if (((float)x.TuSo / x.MauSo) < ((float)t->data.TuSo / t->data.MauSo)){
			ThemNodeVaoCay(t->Left, x);
		}
		else if (((float)x.TuSo / x.MauSo) > ((float)t->data.TuSo / t->data.MauSo)){
			ThemNodeVaoCay(t->Right, x);
		}
	}
}
void docFile(Tree &t){
    ifstream f;
    f.open("PHANSO.txt", ios_base::in);
    int n;
    f >> n; // doc so luong ptu trong cay
    for(int i = 1; i <= n; i++){
        value ps;
        f >> ps.TuSo; f.ignore();
		f >> ps.MauSo; // doc tung phan tu trong cay
        ThemNodeVaoCay(t, ps);
    }
}
void Duyet_NLR(Tree t){
	if (t != NULL){
		cout << t->data.TuSo << "/" << t->data.MauSo << " ";
		Duyet_NLR(t->Left);
		Duyet_NLR(t->Right);
	}
}
void Duyet_LNR(Tree t){
	if (t != NULL){
		Duyet_LNR(t->Left);
		cout << t->data.TuSo << "/" << t->data.MauSo << " ";
		Duyet_LNR(t->Right);
	}
}
void Duyet_LRN(Tree t){
	if (t != NULL){
		Duyet_LNR(t->Left);
		Duyet_LNR(t->Right);
		cout << t->data.TuSo << "/" << t->data.MauSo << " ";
	}
}
void Duyet_NRL(Tree t){
	if (t != NULL){
		cout << t->data.TuSo << "/" << t->data.MauSo << " ";
		Duyet_LNR(t->Right);
		Duyet_LNR(t->Left);
	}
}
void Duyet_RNL(Tree t){
	if (t != NULL){
		Duyet_LNR(t->Right);
		cout << t->data.TuSo << "/" << t->data.MauSo << " ";
		Duyet_LNR(t->Left);
	}
}
void Duyet_RLN(Tree t){
	if (t != NULL){
		Duyet_LNR(t->Right);
		Duyet_LNR(t->Left);
		cout << t->data.TuSo << "/" << t->data.MauSo << " ";
	}
}
int DemSoLuongPsLonHon1(Tree &t){
	int dem = 0;
	if (t != NULL){
		if (((float)t->data.TuSo / t->data.MauSo) > 1){
			dem++;
		}
		dem += DemSoLuongPsLonHon1(t->Left);
		dem += DemSoLuongPsLonHon1(t->Right);
	}
	return dem;
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
void ToiGianPhanSo(value p){
    if(p.TuSo != 0){
        int u = UCLN(p.TuSo, p.MauSo);
        p.TuSo /= u;
        p.MauSo /= u;
    }
    printf("%d/%d ", p.TuSo, p.MauSo);
}
void ToiGianTrenCay(Tree t){
	if(t != NULL){
		ToiGianPhanSo(t->data);
		ToiGianTrenCay(t->Left);
		ToiGianTrenCay(t->Right);
	}
}
int TimKiem(Tree t, value x){
	if(t == NULL){
		return 0;
	}
	if(t->data.TuSo == x.TuSo && t->data.MauSo == x.MauSo){
		return 1;
	}
	return (TimKiem(t->Left, x) || TimKiem(t->Right, x));
}
float TinhTongPhanSo(Tree t) {
    if (t == NULL) {
        return 0;
    }
    return (TinhTongPhanSo(t->Left) + TinhTongPhanSo(t->Right) + ((float)t->data.TuSo / t->data.MauSo));
}
int TimPhanSoMax(Tree t){
	if (t->Right == NULL){
		cout << "Gia tri lon nhat la: " << t->data.TuSo << "/" << t->data.MauSo << endl;
		return 1;
	}
	return TimPhanSoMax(t->Right);
}
int TimPhanSoMin(Tree t){
	if (t->Left == NULL){
		cout << "Gia tri nho nhat la: " << t->data.TuSo << "/" << t->data.MauSo << endl;
		return 1;
	}
	return TimPhanSoMin(t->Left);
}
void LietKePsCoTuLonHonMau(Tree t){
	if (t != NULL){
		if (t->data.TuSo > t->data.MauSo){
			cout << t->data.TuSo << "/" << t->data.MauSo << " ";
		}
		LietKePsCoTuLonHonMau(t->Left);
		LietKePsCoTuLonHonMau(t->Right);
	}
}
void LietKePsCoTuNhoHonMau(Tree t){
	if (t != NULL){
		// xu li
		if (t->data.TuSo < t->data.MauSo){
			cout << t->data.TuSo << "/" << t->data.MauSo << " ";
		}
		// de quy
		LietKePsCoTuNhoHonMau(t->Left);
		LietKePsCoTuNhoHonMau(t->Right);
	}
}
void LietKePhanSoMucK(Tree t, int k){
	if (t == NULL){
		return;
	}
	if (k == 0){
		printf("%d/%d ", t->data.TuSo, t->data.MauSo);
		return;
	}
	LietKePhanSoMucK(t->Left, k - 1);
	LietKePhanSoMucK(t->Right, k - 1);
}
int ktraSNT(int n){
    if(n <= 1){ 
        return 0;
    }
    for(int i = 2; i <= sqrt(n); i++){ 
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
void LietKePhanSoLaSNT(Tree t){
	if(t != NULL){
		if(ktraSNT(t->data.TuSo) && ktraSNT(t->data.MauSo)){
			cout << t->data.TuSo << "/" << t->data.MauSo << " ";
		}
		LietKePhanSoLaSNT(t->Left);
		LietKePhanSoLaSNT(t->Right);
	}
}
float TongCacPsMucK(Tree t, int k){
	float tong = 0;
	if (t == NULL){
		return 0;
	}
	if (k == 0){
		tong += ((float)t->data.TuSo / t->data.MauSo);
	}
	return tong + (TongCacPsMucK(t->Left, k - 1) + TongCacPsMucK(t->Right, k - 1));
}
int DemSoLuongPsMucK(Tree t, int k){
	int count = 0;
	if (t == NULL){
		return 0;
	}
	if (k == 0){
		count++;
	}
	return count + DemSoLuongPsMucK(t->Left, k - 1) + DemSoLuongPsMucK(t->Right, k - 1);
}
bool KTraSoChinhPhuong(int n){ // scp = binh phuong cua 1 so tn 
    if(n < 1){
        return false;
    }
    if(sqrt(n) * sqrt(n) == n){ // 2^2 = 4
        return true;
    }
    return false;
}
void LietKePhanSoLaSCP(Tree t){
	if(t != NULL){
		if(KTraSoChinhPhuong(t->data.TuSo) && KTraSoChinhPhuong(t->data.MauSo)){
			cout << t->data.TuSo << "/" << t->data.MauSo << " ";
		}
		LietKePhanSoLaSCP(t->Left);
		LietKePhanSoLaSCP(t->Right);
	}
}




