#include <stdio.h>
#include <stdlib.h>

// Khai bao cau truc 1 node
struct node{
    int data; // Stack chua cac so nguyen
    struct node *pNext; // Con tro lien ket
};
typedef struct node NODE;

// Khai bao cau truc stack
struct stack{
    NODE *pTop; // Con tro dau quan ly stack
};
typedef struct stack STACK;

// Ham khoi tao stack
void Init(STACK &s){
    s.pTop=NULL;
}

// Ham khoi tao node
NODE* InitNode(int x){
    NODE* p = new NODE();
    if(p==NULL){
        printf("\nKhong the cap phat !");
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}

// Ham kiem tra rong
bool IsEmpty(STACK s){
    if(s.pTop==NULL){
        return true;
    }
    return false;  
}

// Ham Push 
bool Push(STACK &s, NODE* p){
    if(p==NULL){
        return false;
    }
    if(IsEmpty(s)==true){
        s.pTop = p; // node dau = node p
    } else {
        p->pNext = s.pTop; // con tro p -> node dau
        s.pTop = p; // cap nhat node dau 
    }
    return true;
}

// Ham Pop 
bool Pop(STACK &s, int &x){ // x = gia tri can lay
    if(IsEmpty(s)==true){
        return false;
    } else {
        NODE* p = s.pTop;
        x = p->data;
        s.pTop = s.pTop->pNext;
        free(p);
    }
    return true;
}

// Ham Peek xem thong tin phan tu dau stack va ko xoa 
bool Peek(STACK &s, int &x){ //  la gia tri can lay ra xem
    if(IsEmpty(s)==true){
        return false;
    } else {
        x = s.pTop->data; // lay gia tri dau stack
        return true;
    }
}

// Ham chuyen doi co so 10 -> 2, 8, 16
void Chuyen_Co_So(STACK &s, int co_so, int he_thap_phan){
    while(he_thap_phan != 0){
        int x = he_thap_phan % co_so;
        NODE* p = InitNode(x);
        Push(s, p);
        he_thap_phan /= co_so;
    }
}

// Ham xuat du lieu cho chuyen cho so
void xuatCo_So(STACK &s){
    while(IsEmpty(s)==false){
        int x;
        Pop(s, x);
        if(x<10){
            printf("%d", x);
        }
        else {
            if(x==10){
                printf("A");
            } else if(x==11){
                printf("B");
            } else if(x==12){
                printf("C");
            } else if(x==13){
                printf("D");
            } else if(x==14){
                printf("E");
            } else if(x==15){
                printf("F");
            }
        }
    }
}

// Ham xuat danh sach stack
void xuat(STACK s){
    while(IsEmpty(s)==false){
        int x;
        Pop(s, x);
        printf("%4d", x);
    }
    if(IsEmpty(s)==true){
        printf("\nDanh sach rong !");
    } else {
        printf("\nDanh sach dang co phan tu ");
    }
}

// Ham nhap so nguyen trong stack
void nhap(STACK &s){
    int choice;
    while(true){
        printf("\n\n\t\t========== MENU ==========");
        printf("\n\t\t1. Push ");
        printf("\n\t\t2. Pop");
        printf("\n\t\t3. Peek");
        printf("\n\t\t4. Chuyen co so");
        printf("\n\t\t0. Exit !");
        printf("\n\n\t\t========== END ==========");
        
        printf("\nNhap lua chon: ");
        scanf("%d", &choice);
        if(choice == 1){
            int x;
            printf("\nNhap phan tu can them: ");
            scanf("%d", &x);
            NODE* p = InitNode(x);
            Push(s, p);
        }
        else if(choice == 2){
            xuat(s);
        }
        else if(choice == 3){
            int x;
            Peek(s, x);
            printf("\nPhan tu dau stack: %d", x);
        }
        else if(choice==4){
        	    int hethapphan;
		    printf("\nNhap gia tri he(10) can chuyen: ");
		    scanf("%d", &hethapphan);
		    int coso;
		    printf("\nNhap co so can chuyen(2,8,16): ");
		    scanf("%d", &coso);
		    Chuyen_Co_So(s, coso, hethapphan);
		    printf("\nKet qua: ");
		    xuatCo_So(s);
	   }else{
	   		break; 
	   } 
	}
}

int main(){
    STACK s;
    Init(s);



    nhap(s);
    xuat(s);
    
    return 0;
}

