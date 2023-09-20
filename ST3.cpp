#include <stdio.h>


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Ham chia mang va dua phan tu chot ve ðung vi tri 
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // Chon phan tu chot la phan tu cuoi cung
    int i = (low - 1);        // Index cua phan tu nho nhat

    for (int j = low; j <= high- 1; j++) {
        // Neu phan tu hien tai nho hon phan tu chot
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Ham sap xep day so nguyen tang dan bang QuickSort
void quickSort(int arr[], int low, int high) {
    // Tao mot stack de luu  cac gioi han cua mang con duoc sap xep
    int stack[high - low + 1];

    // Khoi tao dinh cua stack
    int top = -1;

    // dua phan tu chot vào stack
    stack[++top] = low;
    stack[++top] = high;

    // Lap khi stack khong rong
    while (top >= 0) {
        // Lay phan tu high va low tu stack
        high = stack[top--];
        low = stack[top--];

        // Partition mang con va lay index cua phan tu chot
        int pi = partition(arr, low, high);

        // Neu co cac mang con ben trai cua phan tu chot,
        // dua gioi han cua chung vao stack
        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        // Neu co cac mang con ben phai cua phan tu chot,
        // dua gioi han cua chung vao stack
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }
}

// Ham in ra mang so nguyen
void printArray(int arr[], int size) {
    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Mang truoc khi sap xep: \n");
    printArray(arr, n);
    quickSort(arr, 0, n-1);
    printf("Mang sau khi sap xep: \n");
    printArray(arr, n);
    return 0;
}

