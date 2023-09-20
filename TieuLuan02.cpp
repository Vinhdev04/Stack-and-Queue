#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai bao cau truc SinhVien
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

// Khai bao cau truc node danh sach lien ket don 
typedef struct Node {
    SinhVien data;
    struct Node* next;
} Node;

// tao mot node moi  
Node* createNode(SinhVien sv) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = sv;
    newNode->next = NULL;
    return newNode;
}

//Them mot sinh vien vao danh sach  
Node* ThemSV(Node* head, SinhVien sv) {
    Node* newNode = createNode(sv);
    newNode->next = head;
    return newNode;
}

// Hien thi thong tin mot sinh vien  
void PrintfSV(SinhVien sv) {
    printf("\n|  %s  |  %s  |  %s  |  %s  |  %.2f  |  %.2f  |  %.2f  |  %.2f  | %s  |\n", sv.maSV, sv.lop, sv.gioiTinh, sv.tenSV, sv.diemMon1, sv.diemMon2, sv.diemMon3, sv.diemTB, sv.hocLuc);
}

// Hien thi danh sach sinh vien  
void displayList(Node* head) {
    if (head == NULL) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        Node* temp = head;
        while (temp != NULL) {
            PrintfSV(temp->data);
            temp = temp->next;
        }
    }
}

// Xoa sinh vien theo ma sinh vien  
Node* XoaSVTheoMa(Node* head, char maSV[20]) {
    Node* prev = NULL;
    Node* curr = head;
    while (curr != NULL) {
        if (strcmp(curr->data.maSV, maSV) == 0) {
            if (prev == NULL) {
                head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("Xoa sinh vien thanh cong.\n");
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Khong tim thay sinh vien co ma SV: %s\n", maSV);
    return head;
}

// Tim sinh vien theo ma sv hoac ten  
void TimSVTheoKeyword(Node* head, char keyword[20]) {
    int found = 0;
    if (head == NULL) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        Node* temp = head;
        while (temp != NULL) {
            if (strstr(temp->data.maSV, keyword) || strstr(temp->data.tenSV, keyword)) {
                PrintfSV(temp->data);
                found = 1;
            }
            temp = temp->next;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien nao phu hop voi tu khoa: %s\n", keyword);
    }
}

// Sap xep sinh vien theo diem trung binh  
void SortByDiemTB(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; 
    }

    int swapped;
    Node* curr;
    Node* prev = NULL;

    do {
        swapped = 0;
        curr = *head;

        while (curr->next != NULL) {
            if (curr->data.diemTB > curr->next->data.diemTB) {
                Node* temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;
                if (prev == NULL) {
                    *head = temp;
                } else {
                    prev->next = temp;
                }
                prev = temp;
                swapped = 1;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    } while (swapped);
}

// sap xep sinh vien theo hoc luc  
void SortByHocLuc(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; 
    }

    int swapped;
    Node* curr;
    Node* prev = NULL;

    do {
        swapped = 0;
        curr = *head;

        while (curr->next != NULL) {
            if (strcmp(curr->data.hocLuc, curr->next->data.hocLuc) > 0) {
                Node* temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;
                if (prev == NULL) {
                    *head = temp;
                } else {
                    prev->next = temp;
                }
                prev = temp;
                swapped = 1;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
    } while (swapped);
}

// Them danh sach sinh vien vao tep tin  
void WriteFile(Node* head) {
    FILE* file = fopen("sinhvien.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    if (head == NULL) {
        printf("Danh sach sinh vien rong.\n");
    } else {
        Node* temp = head;
        while (temp != NULL) {
            fprintf(file, "%s  %s  %s  %s  %.2f  %.2f  %.2f  %.2f  %s\n", temp->data.maSV, temp->data.lop, temp->data.gioiTinh, temp->data.tenSV, temp->data.diemMon1, temp->data.diemMon2, temp->data.diemMon3, temp->data.diemTB, temp->data.hocLuc);
            temp = temp->next;
        }
        printf("Ghi file thanh cong.\n");
    }
    fclose(file);
}

// Doc danh sach sinh vien tu tep tin  
Node* ReadFile() {
    FILE* file = fopen("sinhvien.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return NULL;
    }
    Node* head = NULL;
    char buffer[200];
    while (fgets(buffer, sizeof(buffer), file)) {
        SinhVien sv;
        sscanf(buffer, "%s %s %s %s %f %f %f %f %s", sv.maSV, sv.lop, sv.gioiTinh, sv.tenSV, &sv.diemMon1, &sv.diemMon2, &sv.diemMon3, &sv.diemTB, sv.hocLuc);
        head = ThemSV(head, sv);
    }
    printf("Doc file thanh cong.\n");
    fclose(file);
    return head;
}
//==============================================================================//
int main() {
    Node* head = ReadFile();
    int choice;

    do {
        printf("****************************MENU**************************\n");
        printf("**  1. Hien Thi Danh Sach Sinh Vien                     **\n");
        printf("**  2. Them Sinh Vien Vao Danh Sach                     **\n");
        printf("**  3. Xoa Sinh Vien Theo Ma Sinh Vien                  **\n");
        printf("**  4. Tim Kiem Sinh Vien Theo Ma Sinh Vien             **\n");
        printf("**  5. Tim Kiem Sinh Vien Theo Ten Sinh Vien            **\n");
        printf("**  6. Sap Xep Danh Sach Sinh Vien Theo Diem Trung Binh **\n");
        printf("**  7. Sap Xep Danh Sach Sinh Vien Theo Hoc Luc         **\n");
        printf("**  8. Ghi Danh Sach Sinh Vien Vao File                 **\n");
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
                sv.diemTB = (sv.diemMon1 + sv.diemMon2 + sv.diemMon3) / 3;
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
                getchar();
                break;
            case 4:
                char keyword[50];
                printf("Nhap ma tim kiem: ");
                fgets(keyword, sizeof(keyword), stdin);
                keyword[strcspn(keyword, "\n")] = '\0';
                TimSVTheoKeyword(head, keyword);
                getchar();
                break;
            case 5:
                char tenSV[30];
                printf("Nhap ten SV can tim: ");
                fgets(tenSV, sizeof(tenSV), stdin);
                tenSV[strcspn(tenSV, "\n")] = '\0';
                TimSVTheoKeyword(head, tenSV);
                getchar();
                break;
            case 6:
                SortByDiemTB(&head);
                printf("Danh sach sinh vien da duoc sap xep theo diem trung binh.\n");
                displayList(head);
                getchar();
                break;
            case 7:
                SortByHocLuc(&head);
                printf("Danh sach sinh vien da duoc sap xep theo hoc luc.\n");
                getchar();
                break;
            case 8:
                WriteFile(head);
                getchar();
                break;
            case 0:
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                getchar();
                break;
        }
    } while (choice != 0);

// giai phong bo nho 
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

