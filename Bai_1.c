#include <stdio.h>
#include <ctype.h>
#include <string.h>


void chuanHoaHoTen(char *hoTen) {
    int length = strlen(hoTen);
    int i = 0, j = 0;
    while (i < length && isspace(hoTen[i])) {
        i++;
    }
    int capitalize = 1;
    char result[100];
    for (; i < length; i++) {
        if (isspace(hoTen[i])) {

            if (j > 0 && !isspace(result[j - 1])) {
                result[j++] = ' ';
            }
            capitalize = 1;
        } else {
            if (capitalize && isalpha(hoTen[i])) {
                result[j++] = toupper(hoTen[i]); 
                capitalize = 0;
            } else {
                result[j++] = tolower(hoTen[i]);
            }
        }
    }
    if (j > 0 && isspace(result[j - 1])) {
        j--;
    }
    result[j] = '\0'; 
    strcpy(hoTen, result);
}

int main() {
    char hoTen[100];
    printf("Nhap ho ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    hoTen[strcspn(hoTen, "\n")] = '\0';
    chuanHoaHoTen(hoTen);
    printf("Ho ten chuan : %s\n", hoTen);
    return 0;
}
