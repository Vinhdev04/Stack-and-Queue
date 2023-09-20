#include"stdio.h"
#include"stdlib.h"
typedef struct node{
	int info;
	struct node* next;
}*Stack,Node;


// Khoi tao stack  
void Init(Stack &s){ 
	s = NULL;
}

// Kiem tra rong 
bool IsEmpty(Stack s){
	return(s==NULL);
} 

// Ham Push 1 phan tu vao stack  
bool Push(Stack &s,int x){
	Stack p =new Node;
	if(p==NULL) return 0;
		p->info = x;
		p->next = s;
		s = p;
	return 1;
}

// Ham Pop 1 phan tu ra khoi stack va xoa du lieu  
bool Pop(Stack &s, int &x){
	if(IsEmpty(s)) return 0;
		Stack p = s;
		x = p->info;
		s = s->next;
	free(p);
	return 1;
}

// Ham Peek lay gia tri dau stack in ra  va khong xoa  
bool Peek(Stack &s, int &x){ //  la gia tri can lay ra xem
	if(IsEmpty(s)==true){
		return false;
	}else{
		 x = s->info; // lay gia tri dau stack
		return true;
	}
}

// Ham xuat du lieu cho stack  
void ShowStack(Stack s){
	while(IsEmpty(s)==false){
		int x;
		Pop(s,x);
		printf("%4d",x);
		
	}
	if(IsEmpty(s)==true){
		printf("\nDanh sach rong !");
	}else{
		printf("\nDanh sach dang co phan tu ");
	}
}

// Ham nhap du lieu cho stack  
void InputStack(Stack &s){
	int choice;
	while(true){
		printf("\n\n\t\t========== MENU ==========");
		printf("\n\t\t1. Push ");
		printf("\n\t\t2. Pop");
		printf("\n\t\t3. Peek");
		printf("\n\t\t0. Exit !");
		printf("\n\n\t\t========== END ==========");
		
		printf("\nNhap lua chon: ");
		scanf("%d",&choice);
		if(choice==1){
			int x;
			printf("\nNhap phan tu can them: ");
			scanf("%d",&x);
			Push(s,x);
		}else if(choice == 2){
			ShowStack(s);
		}else if(choice == 3){
			int x;
			Peek(s,x);
			printf("\nPhan tu dau stack: %d",x);
		}else{
			break;
		}
		
	}
}


int main(){
	Stack s;
	Init(s);

	InputStack(s);
	ShowStack(s);
}
