#include <stdio.h>
#include <string.h>

typedef struct {
    int maThiSinh;
    char ten[100];
    char date[15];
    float mon1, mon2, mon3, tongDiem;
} ThiSinh;

void sapXepTheoMa(ThiSinh ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].maThiSinh > ds[j].maThiSinh) {
                ThiSinh temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void timThuKhoa(ThiSinh ds[], int n) {
    float maxDiem = -1;
    for (int i = 0; i < n; i++) {
        if (ds[i].tongDiem > maxDiem) {
            maxDiem = ds[i].tongDiem;
        }
    }
    printf("Danh sach thu khoa:\n");
    for (int i = 0; i < n; i++) {
        if (ds[i].tongDiem == maxDiem) {
            printf("Ma: %d, Ten: %s, Ngay sinh: %s, Tong diem: %.2f\n",
                   ds[i].maThiSinh, ds[i].ten, ds[i].date, ds[i].tongDiem);
        }
    }
}

int main() {
    int n;
    printf("Nhap so luong thi sinh: ");
    scanf("%d", &n);
    ThiSinh ds[n];
    for (int i = 0; i < n; i++) {
        ds[i].maThiSinh = i + 1;
        printf("Nhap ten thi sinh %d: ", ds[i].maThiSinh);
        getchar();
        fgets(ds[i].ten, sizeof(ds[i].ten), stdin);
        ds[i].ten[strcspn(ds[i].ten, "\n")] = '\0';
        printf("Nhap ngay sinh (dd/mm/yyyy): ");
        scanf("%s", ds[i].date);
        printf("Nhap diem mon 1, mon 2, mon 3: ");
        scanf("%f %f %f", &ds[i].mon1, &ds[i].mon2, &ds[i].mon3);
        ds[i].tongDiem = ds[i].mon1 + ds[i].mon2 + ds[i].mon3;
    }
    sapXepTheoMa(ds, n);
    timThuKhoa(ds, n);
    return 0;
}
