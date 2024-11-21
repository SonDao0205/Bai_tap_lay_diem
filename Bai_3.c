#include <stdio.h>

void nhap(int a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhap phan tu a[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void hienThi(int a[][100], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void tinhTich(int a[][100], int n, int m, int kq[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            kq[i][j] = 0;
            for (int k = 0; k < m; k++) {
                kq[i][j] += a[i][k] * a[j][k];
            }
        }
    }
}

int main() {
    int n, m;
    int a[100][100], kq[100][100];

    printf("Nhap so hang N va so cot M cua ma tran: ");
    scanf("%d %d", &n, &m);

    printf("Nhap ma tran A:\n");
    nhapMaTran(a, n, m);

    printf("Ma tran A:\n");
    hienThiMaTran(a, n, m);

    tinhTichMaTran(a, n, m, kq);

    printf("Tich cua A voi ma tran chuyen vi cua no (A x A^T):\n");
    hienThiMaTran(kq, n, n);

    return 0;
}
