#include <stdio.h>

#define MAX_SIZE 100

void sort_array(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    int A[MAX_SIZE];
    int even[MAX_SIZE], odd[MAX_SIZE];
    int even_count = 0, odd_count = 0;

    printf("Nhập số phần tử của mảng (1 < n < 100): ");
    scanf("%d", &n);

    if (n <= 1 || n >= 100) {
        printf("Số phần tử không hợp lệ!\n");
        return 1;
    }

    printf("Nhập các phần tử của mảng:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        if (A[i] % 2 == 0) {
            even[even_count++] = A[i];
        } else {
            odd[odd_count++] = A[i];
        }
    }

    sort_array(even, even_count);
    sort_array(odd, odd_count);

    printf("Các phần tử chẵn sau khi sắp xếp: ");
    for (int i = 0; i < even_count; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");

    printf("Các phần tử lẻ sau khi sắp xếp: ");
    for (int i = 0; i < odd_count; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");

    return 0;
}
