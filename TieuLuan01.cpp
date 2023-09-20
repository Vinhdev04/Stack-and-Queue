#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Khoi Tao Cau Truc SV  ------ CAO BINH TAY -----
typedef struct {
    char maSV[20];
    char lop[20];
    char gioiTinh[5];
    char tenSV[30];
    float diemMon1;
    float diemMon2;
    float diemMon3;
    float diemTB;
    char hocLuc[10];
} SinhVien;

// Khoi Tao Cau Truc Node  ------ CAO BINH TAY -----
typedef struct Node {
    SinhVien data;
    struct Node* next;
} Node;

// Khoi Tao Cau Truc SV   ------ PHAM DUC THANH ------ 
Node* createSV(SinhVien sv) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = sv;
    newNode->next = NULL;
    return newNode;
}

// Ham Them 1 SV   ------ PHAM DUC THANH ------ 
Node* ThemSV(Node* head, SinhVien sv) {
    Node* newNode = createSV(sv);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Ham Xuat Thong Tin SV   ------ PHAM DUC THANH ------ 
void PrintfSV(Node* node) {
    printf("\n|  %s  |  %s  |  %s  |  %s  |  %.2f  |  %.2f  |  %.2f  |  %.2f  |    \n", node->data.maSV, node->data.lop, node->data.gioiTinh, node->data.tenSV, node->data.diemMon1, node->data.diemMon2, node->data.diemMon3, node->data.diemTB, node->data.hocLuc);
}

// Ham Xuat  Thong Tin DSSV   ------ PHAM DUC THANH ------ 
void displayList(Node* head) {
    if (head == NULL) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        Node* temp = head;
        while (temp != NULL) {
            PrintfSV(temp);
            temp = temp->next;
        }
    }
}

// Ham Xuat  Thong Tin DSSV   ------ LUU VAN NHUT ------ 
int NhapN() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar(); 

    return n;
}

// Ham Xuat  Thong Tin DSSV   ------ PHAM DUC THANH ------ 
Node* XoaSVTheoMa(Node* head, char maSV[20]) {
    if (head == NULL) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        if (strcmp(head->data.maSV, maSV) == 0) {
            Node* temp = head;
            head = head->next;
            free(temp);
        } else {
            Node* prev = head;
            Node* curr = head->next;
            while (curr != NULL) {
                if (strcmp(curr->data.maSV, maSV) == 0) {
                    prev->next = curr->next;
                    free(curr);
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
            if (curr == NULL) {
                printf("Khong tim thay sinh vien co ma SV: %s\n", maSV);
            }
        }
    }
    return head;
}

// Ham Xuat  Thong Tin DSSV   ------ PHAM CONG VINH ------ 
Node* XoaSVTheoTen(Node* head, char tenSV[20]) {
    if (head == NULL) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        if (strcmp(head->data.tenSV, tenSV) == 0) {
            Node* temp = head;
            head = head->next;
            free(temp);
        } else {
            Node* prev = head;
            Node* curr = head->next;
            while (curr != NULL) {
                if (strcmp(curr->data.tenSV, tenSV) == 0) {
                    prev->next = curr->next;
                    free(curr);
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
            if (curr == NULL) {
                printf("Khong tim thay sinh vien co ten: %s\n", tenSV);
            }
        }
    }
    return head;
}

// Ham Xuat  Thong Tin DSSV   ------ PHAM DUC THANH ------ 
Node* TimSVTheoMa(Node* head, char keyword[20]) {
    if (head == NULL) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        Node* temp = head;
        while (temp != NULL) {
            if (strstr(temp->data.maSV, keyword) || strstr(temp->data.tenSV, keyword)) {
                PrintfSV(temp);
            }
            temp = temp->next;
        }
    }
    return head;
}

// Ham Xuat  Thong Tin DSSV   ------ CAO BINH TAY ------ 
Node* TimSVTheoTen(Node* head, char keyword[20]) {
    if (head == NULL) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        Node* temp = head;
        while (temp != NULL) {
            if (strstr(temp->data.maSV, keyword) || strstr(temp->data.tenSV, keyword)) {
                PrintfSV(temp);
            }
            temp = temp->next;
        }
    }
    return head;
}

// Ham Xuat  Thong Tin DSSV   ------ LUU VAN NHUT ------ 
float TinhDiemTB(float diemMon1, float diemMon2, float diemMon3) {
    return (diemMon1 + diemMon2 + diemMon3) / 3;
}

void XepLoaiHocLuc(SinhVien* sv) {
    if (sv->diemTB >= 8.5) {
        strcpy(sv->hocLuc, "Gioi");
    } else if (sv->diemTB >= 7) {
        strcpy(sv->hocLuc, "Kha");
    } else if (sv->diemTB >= 5.5) {
        strcpy(sv->hocLuc, "Trung Binh");
    } else if (sv->diemTB >= 4) {
        strcpy(sv->hocLuc, "Yeu");
    } else {
        strcpy(sv->hocLuc, "Kem");
    }
}

// Ham Xuat  Thong Tin DSSV   ------ PHAM DUC THANH ------ 
void sortSVDiemTB(Node* head) {
    if (head == NULL) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        int swapped;
        Node* ptr1;
        Node* lptr = NULL;

        do {
            swapped = 0;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (ptr1->data.diemTB > ptr1->next->data.diemTB) {
                    SinhVien temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;
                    swapped = 1;
                } else if (ptr1->data.diemTB == ptr1->next->data.diemTB) {
                    if (strcmp(ptr1->data.hocLuc, ptr1->next->data.hocLuc) > 0) {
                        SinhVien temp = ptr1->data;
                        ptr1->data = ptr1->next->data;
                        ptr1->next->data = temp;
                        swapped = 1;
                    }
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
}

// Ham Xuat  Thong Tin DSSV   ------ PHAM CONG VINH ------ 
void sortHocLuc(Node* head) {
    if (head == NULL) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        int swapped;
        Node* ptr1;
        Node* lptr = NULL;

        do {
            swapped = 0;
            ptr1 = head;

            while (ptr1->next != lptr) {
                if (strcmp(ptr1->data.hocLuc, ptr1->next->data.hocLuc) > 0) {
                    SinhVien temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
}

// Ham Xuat  Thong Tin DSSV   ------ CAO BINH TAY ------ 
void writeFile(Node* head) {
    FILE* file = fopen("sinhvien.txt", "w");
    if (file == NULL) {
       // printf("Khong the mo file.\n");
        return;
    }
    if (head == NULL) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        Node* temp = head;
        while (temp != NULL) {
            fprintf(file, "%s    %s    %s    %s     %.2f    %.2f    %.2f    %.2f    %s  \n", temp->data.maSV, temp->data.lop, temp->data.gioiTinh, 
            temp->data.tenSV, temp->data.diemMon1, temp->data.diemMon2, temp->data.diemMon3, temp->data.diemTB, temp->data.hocLuc);
            temp = temp->next;
        }
        printf("Ghi file thanh cong.\n");
    }
    fclose(file);
}
// Ham Xuat  Thong Tin DSSV   ------ PHAM CONG VINH ------ 
Node* readFile() {
    FILE* file = fopen("sinhvien.txt", "r");
    if (file == NULL) {
      //  printf("Khong the mo file.\n");
        return NULL;
    }
    Node* head = NULL;
    char buffer[50];
    while (fgets(buffer, sizeof(buffer), file)) {
        SinhVien sv;
        sscanf(buffer, "%[^,],%[^,],%[^,],%[^,],%f,%f,%f,%f,%[^,]\n", sv.maSV, sv.lop, sv.gioiTinh, 
        sv.tenSV,sv.diemMon1, sv.diemMon2, sv.diemMon3, sv.diemTB, sv.hocLuc);
    sortHocLuc(head);
    head = ThemSV(head, sv);
    }
    printf("Doc file thanh cong.\n");
    fclose(file);
    return head;
}


// Ham MAIN   ------ PHAM CONG VINH ------ 
int main() {
	Node* head = readFile();

	int choice;
	do {
    printf("****************************MENU**************************\n");
	printf("**  1. Hien Thi Danh Sach Sinh Vien                     **\n");
	printf("**  2. Them Sinh Vien Vao Danh Sach                     **\n");
	printf("**  3. Xoa Sinh Vien Theo Ma Sinh Vien                  **\n");
	printf("**  4. Xoa Sinh Vien Theo Ten Sinh Vien                 **\n");
	printf("**  5. Tim Kiem Sinh Vien Theo Ma Sinh Vien             **\n");
	printf("**  6. Tim Kiem Sinh Vien Theo Ten Sinh Vien            **\n");
	printf("**  7. Sap Xep Danh Sach Sinh Vien Theo Diem Trung Binh **\n");
    printf("**  8. Sap Xep Danh Sach Sinh Vien Theo Hoc Luc         **\n");
	printf("**  9. Ghi Danh Sach Sinh Vien Vao File                 **\n");
	printf("**  0. Exit                                             **\n");
	printf("****************************MENU**************************\n");
	printf("Nhap lua chon cua ban: ");
	scanf("%d", &choice);
	getchar(); 
	
	switch (choice) {
		case 1:
			displayList(head);
			break;
		case 2: 
			SinhVien sv;
			printf("Nhap ma SV: ");
			fgets(sv.maSV, sizeof(sv.maSV), stdin);
			sv.maSV[strcspn(sv.maSV, "\n")] = '\0';
			printf("Nhap lop: ");
			fgets(sv.lop, sizeof(sv.lop), stdin);
			sv.lop[strcspn(sv.lop, "\n")] = '\0';
			printf("Nhap gioi tinh: ");
			fgets(sv.gioiTinh, sizeof(sv.gioiTinh), stdin);
			sv.gioiTinh[strcspn(sv.gioiTinh, "\n")] = '\0';
			printf("Nhap ten SV: ");
			fgets(sv.tenSV, sizeof(sv.tenSV), stdin);
			sv.tenSV[strcspn(sv.tenSV, "\n")] = '\0';
			printf("Nhap diem Mon 1: ");
			scanf("%f", &sv.diemMon1);
			printf("Nhap diem Mon 2: ");
			scanf("%f", &sv.diemMon2);
			printf("Nhap diem Mon 3: ");
			scanf("%f", &sv.diemMon3);
			sv.diemTB = TinhDiemTB(sv.diemMon1, sv.diemMon2, sv.diemMon3);
			//sortHocLuc(head);
			head = ThemSV(head, sv);
			printf("Them sinh vien thanh cong.\n");
			getchar();
			break;
		case 3:
			char maSV[20];
			printf("Nhap ma SV can xoa: ");
			fgets(maSV, sizeof(maSV), stdin);
			maSV[strcspn(maSV, "\n")] = '\0';
			head = XoaSVTheoMa(head, maSV);
			printf("Xoa sinh vien thanh cong.\n");
			getchar();
			break;
		case 4:
            char tenSV[30];
            printf("Nhap ten SV can xoa: ");
            fgets(tenSV, sizeof(tenSV), stdin);
            tenSV[strcspn(tenSV, "\n")] = '\0';
            head = XoaSVTheoTen(head, tenSV);
            getchar();
            break;	
		case 5: 
			char keyword[50];
			printf("Nhap ma tim kiem: ");
			fgets(keyword, sizeof(keyword), stdin);
			keyword[strcspn(keyword, "\n")] = '\0';
			head = TimSVTheoMa(head, keyword);
			getchar();
			break;
		case 6:
            char ten[30];
            printf("Nhap ten SV can tim: ");
            fgets(ten, sizeof(ten), stdin);
            tenSV[strcspn(tenSV, "\n")] = '\0';
            head = TimSVTheoTen(head, ten);
            getchar();
            break;
		case 7:
			sortSVDiemTB(head);
            printf("Danh sach sinh vien da duoc sap xep.\n");
            displayList(head);
            getchar();
            break;
        case 8:
            sortHocLuc(head);
            printf("Danh sach sinh vien da duoc sap xep theo hoc luc.\n");
            getchar();
            break;    
		case 9:
			writeFile(head);
			getchar();
			break;
		case 0:
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
			getchar();
			break;
	}
}while(choice != 0);

	return 0;
}
