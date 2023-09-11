#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 100

// Định nghĩa cấu trúc Stack.
typedef struct {
	char data[MAX_SIZE];
	int top;
} Stack;
void initialize(Stack* stack);
bool isEmpty(Stack* stack);
bool isFull(Stack* stack);
void push(Stack* stack, char item);
void pop(Stack* stack);
bool isValidParentheses(const char* s);
bool isMatchingPair(char opening, char closing);
bool containsRedundantParentheses(const char* expression);
// Hàm main để kiểm tra.
int main() {
	int choice;
	char expression[MAX_SIZE];

	do {
		printf("\n1. Kiem tra su hop le cua dau ngoac");
		printf("\n2. Kiem tra su ton tai cua dau ngoac don trung lap");
		printf("\n3. Thoat chuong trinh");

		printf("\nNhap lua chon cua ban: "); scanf("%d", &choice);
		switch (choice) {
		case 1:
			printf("\nNhap bieu thuc can kiem tra: ");
			fflush(stdin);
			gets(expression);
			if (isValidParentheses(expression)) {
				printf("Cap dau ngoac hop le!\n");
			}
			else {
				printf("Cap dau ngoac khong hop le!\n");
			}
			break;
		case 2:
			printf("\nNhap bieu thuc can kiem tra: ");
			fflush(stdin);
			gets(expression);
			if (containsRedundantParentheses(expression)) {
				printf("Bieu thuc chua dau ngoac don trung lap!\n");
			}
			else {
				printf("Bieu thuc khong chua dau ngoac don trung lap!\n");
			}
			break;
		case 3:
			printf("\nThoat chuong trinh!");
			break;
		default:
			printf("\nLua chon khong hop le. Vui long chon lai!\n");
			break;
		}
		printf("\n");
		system("pause");
		system("cls");
	} while (choice != 3);

	return 0;
}
// Khởi tạo stack rỗng.
void initialize(Stack* stack) {
	stack->top = -1;
}
// Kiểm tra stack rỗng.
bool isEmpty(Stack* stack) {
	return stack->top == -1;
}
// Kiểm tra stack đầy.
bool isFull(Stack* stack) {
	return stack->top == MAX_SIZE - 1;
}
// Thêm phần tử vào stack.
void push(Stack* stack, char item) {
	if (isFull(stack)) {
		printf("Stack overflow!\n");
		exit(1);
	}
	stack->data[++stack->top] = item;
}
// Loại bỏ phần tử khỏi stack.
void pop(Stack* stack) {
	if (isEmpty(stack)) {
		printf("Stack underflow!\n");
		exit(1);
	}
	stack->top--;
}
// Kiểm tra sự hợp lệ của các cặp dấu ngoặc.
bool isValidParentheses(const char* s) {
	Stack stack;
	initialize(&stack);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			push(&stack, s[i]);
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
			if (isEmpty(&stack)) {
				return false;
			}
			else if ((s[i] == ')' && stack.data[stack.top] == '(') ||
				(s[i] == ']' && stack.data[stack.top] == '[') ||
				(s[i] == '}' && stack.data[stack.top] == '{')) {
				pop(&stack);
			}
			else {
				return false;
			}
		}
	}
	return isEmpty(&stack);
}
// Kiểm tra xem một ký tự có phải là dấu ngoặc đơn hay không.
bool isSingleParenthesis(char c) {
	return (c == '(' || c == ')');
}
// Kiểm tra xem biểu thức có chứa dấu ngoặc đơn trùng lặp hay không.
bool containsRedundantParentheses(const char* expression) {
	int length = strlen(expression);
	Stack stack;
	initialize(&stack);
	for (int i = 0; i < length; i++) {
		char currentChar = expression[i];

		if (isSingleParenthesis(currentChar)) {
			if (currentChar == '(') {
				push(&stack, currentChar);
			}
			else if (currentChar == ')') {
				bool foundOpening = false;

				// Kiểm tra dấu ngoặc mở gần nhất và xem liệu có ký tự không phải dấu đóng ngay sau nó hay không
				while (!isEmpty(&stack)) {
					char topChar = stack.data[stack.top];
					pop(&stack);

					if (topChar == '(') {
						if (i < length - 1 && expression[i + 1] != ')') {
							foundOpening = true;
							break;
						}
						else {
							break;
						}
					}
				}
				if (foundOpening) {
					return true; // Có dấu ngoặc mở không được đóng ngay sau nó
				}
			}
		}
	}
	// Nếu stack còn dư dấu ngoặc mở, có dấu ngoặc đơn trùng lặp
	return !isEmpty(&stack);
}









