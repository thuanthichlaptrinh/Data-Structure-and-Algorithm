// Phương pháp địa chỉ mở (dò tuyến tính)
#include <iostream>
using namespace std;

#define TRUE 1
#define FALSE 0
#define NULLKEY -1
#define MAXSIZE 7

struct HashNode{
    int Key;
};
HashNode HashTable[MAXSIZE];
int N;

// ham bam
int HashFunction(int Key) {
    return (Key % MAXSIZE);
}

// khoi tao ham bam
void InitHashTable(){
    for(int i = 0; i < MAXSIZE; i++){
        HashTable[i].Key = NULLKEY; 
    }
    N = 0;
}

// kiểm tra bảng băm có rỗng hay không
bool IsEmpty(){
    if(N == 0){
        return true;
    }
    return false;
}

// ktra bảng băm có đầy hay không
int IsFull(){
    if(N == MAXSIZE - 1)
        return TRUE; //Nếu đầy
    else
        return FALSE; //Nếu chưa đầy
}

//Tac vu tim 1 Key, tim thay tra ve index, khong thay tra ve MAXSIZE
int Search(int k) {
    int i = HashFunction(k);
    while(HashTable[i].Key != k && HashTable[i].Key != NULLKEY) {
        i = i + 1;
        if(i >= MAXSIZE)
            i = i - MAXSIZE; 
    }
    if(HashTable[i].Key == k)
        return i;
    else
        return MAXSIZE; 
}

// Them khoa k vao bang bam
int Insert(int k) {
    int i = HashFunction(k);
    if(IsFull() == TRUE) {
        printf("\n Bang bam bi day, khong them vao duoc");
        return MAXSIZE; 
    }
    
    while(HashTable[i].Key != NULLKEY) {
        i++;
        if(i >= MAXSIZE)
        i = i - MAXSIZE; 
    }
    HashTable[i].Key = k; 
    N++;
    return i;
}

// Xem chi tiet thong tin bang bam
void ViewTable(){
    for(int i = 0; i < MAXSIZE; i++){
        printf("\n table[%2d]: %4d", i, HashTable[i].Key);
    } 
    printf("\n");
}

int main(){
    InitHashTable();

    Insert(18);
    Insert(20);
    Insert(15);

    ViewTable();

    return 0;
}




