#include <stdio.h>

#define MAX_VALUE 30000
#define MAX_SIZE 100

void find_most_frequent_numbers(int arr[], int n) {
    int freq[MAX_VALUE + 1] = {0};
    int max_frequency = 0;

    for (int i = 0; i < n; i++) {
        int value = arr[i];
        freq[value]++;
        if (freq[value] > max_frequency) {
            max_frequency = freq[value];
        }
    }

    int printed[MAX_VALUE + 1] = {0};
    printf("Các số xuất hiện nhiều nhất là: ");
    for (int i = 0; i < n; i++) {
        int value = arr[i];
        if (freq[value] == max_frequency && !printed[value]) {
            printf("%d ", value);
            printed[value] = 1;
        }
    }
    printf("\n");
}

int main() {
    int n;
    int arr[MAX_SIZE];

    printf("Nhập số phần tử của mảng: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX_SIZE) {
        printf("Số phần tử không hợp lệ!\n");
        return 1;
    }

    printf("Nhập các phần tử của mảng:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < 1 || arr[i] > MAX_VALUE) {
            printf("Phần tử không hợp lệ!\n");
            return 1;
        }
    }

    find_most_frequent_numbers(arr, n);

    return 0;
}
