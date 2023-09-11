#include <iostream>
using namespace std;

#define LH -1   // cây con trái cao hơn (lệch trái)
#define EH 0    // cây con trái bằng cây con phải (cân bằng)
#define RH 1    // cây con phải cao hơn (lệch phải)
typedef int ItemType;

// Định nghĩa kiểu dữ liệu cho 1 nút của cây AVL
struct AVLNode{
    int balFactor;  // chỉ số cân bằng
    ItemType Info;  // dữ liệu chứa trong 1 cái node
    AVLNode *Left;  // cây con trái
    AVLNode *Right; // cây con phải
};

// Định nghĩa kiểu dữ liệu cho cây AVL
struct AVLTree{
    AVLNode *Root;
};

// khởi tạo cây
void initAVLTree(AVLTree &t){
    t.Root = NULL;
}

// cấp phát một nút mới cho cây AVL
AVLNode *createAVLNode(ItemType x){
    AVLNode *p = new AVLNode;
    if(p == NULL){
        printf("\nKhong du bo nho de cap phat");
        return NULL;
    }
    p->Info = x; 
    p->balFactor = EH;
    p->Left = p->Right = NULL;
    return p;
}

// hủy vùng nhớ đã cấp phát cho một nút trên cây avl
void DeleteAVLNode(AVLNode *&t) { 
    t->Left = t->Right = NULL;
    delete t; 
    t = NULL; 
}

// Trường hợp: cây con trái lệch trái (Left - Left)
void rotateLL(AVLNode *&t){
    AVLNode *t1 = t->Left;
    t->Left = t1->Right; t1->Right = t;
    switch(t1->balFactor){
        case LH:
            t->balFactor = EH;
            t1->balFactor = EH;
            break;
        case EH:
            t->balFactor = LH;
            t1->balFactor = RH;
            break;
    }
    t = t1;
}

// trường hơp: cây con phải lệch phải (Right-Right)
void rotateRR(AVLNode *&t){
    AVLNode *t1 = t->Right;
    t->Right = t1->Left;  t1->Left = t;
    switch(t1->balFactor){
        case RH:
            t->balFactor = EH;
            t1->balFactor = EH;
            break;
        case EH:
            t->balFactor = RH;
            t1->balFactor = LH;
            break;
    }
    t = t1; 
}

// Trường hợp cây con trái lệch phải (Left - Right)
void rotateLR(AVLNode *&t){
    AVLNode *t1 = t->Left;
    AVLNode *t2 = t1->Right;
    t1->Right = t2->Left; t2->Left = t1;
    t->Left = t2->Right; t2->Right = t;
    switch(t2->balFactor){
        case LH:
            t->balFactor = RH;
            t1->balFactor = EH;
            break;
        case EH:
            t->balFactor = EH;
            t1->balFactor = EH;
            break;
        case RH:
            t->balFactor = EH;
            t1->balFactor = LH;
            break;  
    }
    t2->balFactor = EH;
    t = t2;
}

// Trường hợp cây con phải lệch trái (Right - Left)
void rotateRL(AVLNode *&t){
    AVLNode *t1 = t->Right;
    AVLNode *t2 = t->Left;
    t1->Left = t2->Right; t2->Right = t1;
    t->Right = t2->Left; t2->Left = t;
    switch(t2->balFactor){
        case RH:
            t->balFactor = LH;
            t1->balFactor = EH;
            break;
        case EH:
            t->balFactor = EH;
            t1->balFactor = EH;
            break;
        case LH:
            t->balFactor = EH;
            t1->balFactor = RH;
            break;
    }
    t2->balFactor = EH;
    t = t2;
}

//  Trường hợp: cân bằng lại khi cây lệch trái
int BalanceLeft(AVLNode *&t){
    AVLNode *t1 = t->Left;
    switch(t1->balFactor){
        case LH:  rotateLL(t);  return 2;
        case EH:  rotateLL(t);  return 1;
        case RH:  rotateLR(t);  return 2; 
    }
    return 0; // th balance bị sai
}

// trường hợp: cân bằng lại khi cây lệch phải
int BalanceRight(AVLNode *&t){
    AVLNode *t1 = t->Right;
    switch(t1->balFactor){
        case RH:  rotateRR(t);  return 2;
        case EH:  rotateRR(t);  return 1;
        case LH:  rotateRL(t);  return 2;
    }
    return 0; // Th balance bị sai
}

// Thêm nút có giá trị x vào cây
int InsertAVLNode(AVLNode *&t, int x){
    int res;
    if(t != NULL){
        if(x < t->Info){
            res = InsertAVLNode(t->Left, x);
            if(res < 2) return res;
            switch(t->balFactor){
                case RH:  t->balFactor = EH;    return 1;
                case EH:  t->balFactor = LH;    return 2;
                case LH:  BalanceLeft(t);       return 1; 
            }
        }
        else if(x > t->Info){
            res = InsertAVLNode(t->Right, x);
            if(res < 2) return res;
            switch(t->balFactor){
                case LH:  t->balFactor = EH;    return 1;
                case EH:  t->balFactor = RH;    return 2;
                case RH:  BalanceRight(t);      return 1;
            }
        }
        else{ // t->Info == x (gia tri da co trong cay)
            return 0;
        }
    }
    // t == NULLL 
    t = createAVLNode(x);
    return 2;
}

// Tìm node thế mạng
int SearchStanFr(AVLNode *&X, AVLNode *&Y){
    int res;
    if(Y->Left != NULL){
        res = SearchStanFr(X, Y->Left);
        if(res < 2)  return 2;
        switch(Y->balFactor){
            case LH: Y->balFactor = EH; return 2;
            case EH: Y->balFactor = RH; return 1;
            case RH: return BalanceRight(Y);
        }
    }
    // y->left == NULL
    X->Info = Y->Info;
    X = Y;
    Y = Y->Right;
    return 2; 
}

// Xóa nút có giá trị x
int DeleteAVLNode(AVLNode *&t, int x){
    int res;
    if(t == NULL){
        return 0;
    }
    else{
        if(x < t->Info){
            res = DeleteAVLNode(t->Left, x);
            if(res < 2) return res;
            switch(t->balFactor){
                case LH:  t->balFactor = EH;    return 2;
                case EH:  t->balFactor = RH;    return 1;
                case RH:  return BalanceRight(t);
            }
        }
        else if(x > t->Info){
            res = DeleteAVLNode(t->Right, x);
            if(res < 2) return res;
            switch(t->balFactor){
                case RH:  t->balFactor = EH;    return 2;
                case EH:  t->balFactor = LH;    return 1;
                case LH:  return BalanceLeft(t);    
            }
        }
        else{
            AVLNode *p1 = t;
            if(t->Left == NULL){
                t = t->Right;
                res = 2;
            }
            else if(t->Right == NULL){
                t = t->Left;
                res = 2;
            }
            else{ // node can xoa la node co 2 con
                res = SearchStanFr(p1, t->Right);
                if(res < 2) return res;
                switch(t->balFactor){
                    case RH:  t->balFactor = EH;    return 2;
                    case EH:  t->balFactor = LH;    return 1;
                    case LH:  return BalanceLeft(t);
                }
            }
            delete p1;
            return res;
        }
    }
}

// Xóa toàn bộ nút trên cây
int DeleteAVLTree(AVLNode* &root) { 
    if(root == NULL) return 0;
    DeleteAVLTree(root->Left); //Xóa con trái
    DeleteAVLTree(root->Right); //Xóa con phải
    DeleteAVLNode(root); //Xóa nút gốc
    return 1;
}

// tim kiem phan tu x độ phức tạp big O(log(n))
AVLNode *FindAVLNode(AVLNode *&t, ItemType x){
    if(t == NULL){
        return NULL;
    }
    else{ // t != NULL
        if(x < t->Info){
            return FindAVLNode(t->Left, x);
        }
        else if(x > t->Info){
            return FindAVLNode(t->Right, x);
        }
        else{ // x == t->Info
            return t;
        }
    }
}

// duyet cay
void DuyetNLR(AVLNode *t){
    if(t != NULL){
        DuyetNLR(t->Left);
        printf("%d ", t->Info);
        DuyetNLR(t->Right   );
    }
}
// tao cay avl tu mang a co n phan tu
void CreateAVLTreeFromArray(AVLTree &t, ItemType a[], int n) { //Ham tao cay NPTK tu mang a
    initAVLTree(t);
    for(int i = 0; i < n; i++){
        InsertAVLNode(t.Root, a[i]);
    }   
}
// ham nhap
void Menu(AVLTree t){
    while(1){
        int luaChon, x, n, a[100];
        system("cls");
        printf("\t\t--------- AVL Tree ---------\n");
        printf("\t\t1. Chen nut vao cay\n");
        printf("\t\t2. Duyet LNR\n");
        printf("\t\t3. Xoa nut tren cay\n");
        printf("\t\t4. Tim kiem nut tren cay\n");
        printf("\t\t5. Xoa toan bo cay\n");
        printf("\t\t0. Thoat chuong trinh\n");
        printf("\t\t----------- End ------------");
        printf("\nNhap chuc nang: "); scanf("%d", &luaChon);
        if(luaChon == 0){
            break;
        }
        else if(luaChon == 1){
           /* printf("\nNhap n: "); scanf("%d", &n);
            for(int i = 0; i < n; i++){
                printf("Nhap nut thu %d: ", i); 
                scanf("%d", &a[i]);
            }
            CreateAVLTreeFromArray(t, a, n);*/
            printf("\nNhap gia tri nut can them: "); 
            scanf("%d", &x);
            InsertAVLNode(t.Root, x);
        }
        else if(luaChon == 2){
            printf("\nDuyet LNR: ");
            DuyetNLR(t.Root);
            system("pause");
        }
        else if(luaChon == 3){
            printf("\nNhap gia tri nut can xoa: ");
            scanf("%d", &x);
            DeleteAVLNode(t.Root, x);   
        }
        else if(luaChon == 4){
            printf("\nNhap nut can tim: "); scanf("%d", &x);
            if(FindAVLNode(t.Root, x) == NULL){
                printf("\nKhong tim thay gia tri nut %d trong cay");
            }
            else{
                printf("\nTim thay gia tri nut %d trong cay\n");
            }
            system("pause");
        }
        else if(luaChon == 5){
            if(DeleteAVLTree(t.Root) == 0){
                printf("\nKhong the xoa cay");
            }
            else{
                printf("\nDa xoa toan bo cay");
            }
            system("pause");
        }
        else{
            printf("\nSai chuc nang. Vui long nhap lai!");
            system("pause");
        }
    }
}


int main(){
    AVLTree t;
    initAVLTree(t);
    Menu(t);

    system("pause");
    return 0;
}

























