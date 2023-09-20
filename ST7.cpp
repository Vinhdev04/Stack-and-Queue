#include"stdio.h"
#include"stdlib.h"

typedef struct node{
	int info;
	struct node* next;
}*Stack,Node;

void Init(Stack &s){
	s = NULL;
}

bool IsEmpty(Stack s){
	return s==NULL;
}

bool Push(Stack &s,int x){
	Stack p = new Node; // Khoi tao node moi
	if(p==NULL){ // Kiem tra rong
		return 0;
	}else{
		p->info = x; // Gan du lieu cho x
		p->next = s; // p tro toi s
	}
	return 1;
}

bool Pop(Stack &s, int &x){
	if(IsEmpty(s)) return 0; // Kiem tra rong
		Stack p = s; // Tao node moi 
		x = p->info; // Gan du lieu cho x
		s = s->next;	// Cho s tro toi tiep theo
	free(p); // Giai phong bo nho
	return 1;	
}

bool Peek(Stack s, int &x){
	if(IsEmpty(s)==true) {
		return false;
	}else{
		x = s->info;
		return true;
	}	
	
}

void xuat(Stack s){
	while(IsEmpty(s)==false){
		int x;
		Pop(s,x);
		printf("%4d",x);
	}
	if(IsEmpty(s)==true){
		printf("\nEmpty !");
	}else{
		printf("\nDang co phan tu !");
	}
}

void nhap(Stack &s){
	int choice;
	while(true){
		printf("\n\n\t\t========== MENU ==========");
		printf("\n\n\t\t1. Push");
		printf("\n\n\t\t2. Pop");
		printf("\n\n\t\t3. Peek");
		printf("\n\n\t\t0. Exit !");
		printf("\n\n\t\t========== MENU ==========");
		printf("\nLua chon: ");
		scanf("%d",&choice);
		if(choice==1){
			int x;
			printf("\nNhap x = ");
			scanf("%d",&x);
			Push(s,x);
		}else if(choice==2){
			xuat(s);
		}else if(choice==3){
			int x;
			Peek(s,x);
			printf("\nPhan tu dau trong stack = %d",x);
		}else{
			break;
		}
	}
}

int main(){
	Stack s;
	Init(s);
	
	nhap(s);
	xuat(s);
	
	return 0;
}
