#include <iostream>
using namespace std;

#define M 7

struct Item {
	int value;
	int next;
};

struct HashTable {
	Item h[M]; // bang bambam
	int r; 
};

// khởi tạo bảng băm
void init(HashTable& t) {
	for (int i = 0; i < M; i++){ // khởi động tất cả các ptu trong bẳng băm là -1
		t.h[i].value = -1;
		t.h[i].next = -1;
	}
	t.r = M - 1; // cho r trỏ đến ptu ở cuối để dò
}

// hàm băm
int hashFunc(int value) {
	return value % M;
}

void insertHashItem(HashTable& t, int x) {
	if (t.r >= 0) {
		int index = hashFunc(x);

		if (t.h[index].value == -1) {
			t.h[index].value = x;
		}
		else {
			t.h[t.r].value = x;

			while (t.h[index].next != -1) {
				index = t.h[index].next;
			}
			t.h[index].next = t.r;
		}
		while (t.r >= 0 && t.h[t.r].value >= 0) {
			t.r--;
		}
	}
}

// hàm xuất
void displae(HashTable t) {
	for (int i = 0; i < M; i++) {
		if (t.h[i].value >= 0) {
			cout << "index " << i << ": " << t.h[i].value << " : " << t.h[i].next << endl;
		}
	} 
}

// tìm kiếm
int search(HashTable t, int x) {
	int index = hashFunc(x);
	do {
		if (t.h[index].value == x) {
			return index;
		}

		index = t.h[index].next; // ngược lại t.h[index] > -1 thì tiếp tục trỏ next đến khi hết thì trả về -1 
	} while (index >= 0);
	
	return -1; // không tìm thấy
}

// hàm nhập bảng băm
void menu(){
	HashTable t;
	init(t);
	int luaChon, x;
	
	while(1){
		system("cls");
		printf("\n1. Them gia tri vao bang bam");
		printf("\n2. Xuat bang bam");
		printf("\n3. Tim kiem phan tu trong bang bam");
		printf("\nNhap chuc nang: "); scanf("%d", &luaChon);

		if(luaChon == 0){
			break;
		}
		else if(luaChon == 1){
			printf("\nNhap gia tri can chen: "); scanf("%d", &x);
			insertHashItem(t, x);
		}
		else if(luaChon == 2){
			displae(t);
			system("pause");
		}
		else if(luaChon == 3){
			printf("\nNhap phan tu can tim: "); scanf("%d", &x);
			if(search(t, x) > -1){
				printf("\nTim thay phan tu %d", x);
			}
			else{
				printf("\nKhong tim thay phan tu %d", x);
			}
			system("pause");
		}
	}
}

int main() {
	menu();
	//HashTable t;
	//init(t);
	
	
	/*insertHashItem(t, 12);
	insertHashItem(t, 1);
	insertHashItem(t, 8);
	insertHashItem(t, 15);
    insertHashItem(t, 14);
    insertHashItem(t, 21);
    insertHashItem(t, 35);
    insertHashItem(t, 63); // 63 ko được thêm vì r đã âm*/

	//displae(t);

    /*if(search(t, 35) >= 0){
        printf("\nTim thay gia tri 35 tai vi tri %d", search(t, 35));
    }
    if(search(t, 63) < 0){
        printf("\nKhong tim thay gia tri 63 tai vi tri %d", search(t, 63));
    }

    printf("\n");*/
	return 0;
}


















