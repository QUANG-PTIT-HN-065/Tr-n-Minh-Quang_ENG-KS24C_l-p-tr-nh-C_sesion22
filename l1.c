#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int age;
    char Name[100];
} Studen;

void prinfListStuden(Studen std[], int n);
void addStuden(Studen std[], int *n);
void updeatStuden(Studen std[], int n);
void delleteStuden(Studen std[], int *n);
void sstd(Studen std[], int n);
void xapSep(Studen std[], int n);
void readFile(Studen std[], int *n);
void saveFile(Studen std[], int n);

int main() {
    Studen std[100];
    int choice, n = 0;

    readFile(std, &n);

    do {
        printf("\n=========== MENU ===========\n");
        printf("1. In danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem\n");
        printf("6. Xap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("============================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                prinfListStuden(std, n);
                break;
            case 2:
                addStuden(std, &n);
                break;
            case 3:
                updeatStuden(std, n);
                break;
            case 4:
                delleteStuden(std, &n);
                break;
            case 5:
                sstd(std, n);
                break;
            case 6:
                xapSep(std, n);
                break;
            case 7:
                saveFile(std, n);
                printf("Du lieu da duoc luu. Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 7);

    return 0;
}

void prinfListStuden(Studen std[], int n) {
    for (int i = 0; i < n; i++) {
        printf("ID: %d\n", std[i].id);
        printf("Tuoi: %d\n", std[i].age);
        printf("Ten: %s\n", std[i].Name);
        printf("------------------------\n");
    }
}

void addStuden(Studen std[], int *n) {
    printf("Hay nhap ten hoc sinh muon them: ");
    fgets(std[*n].Name, 100, stdin);
    std[*n].Name[strcspn(std[*n].Name, "\n")] = '\0';
    printf("Hay nhap vao ID: ");
    scanf("%d", &std[*n].id);
    printf("Hay nhap vao tuoi: ");
    scanf("%d", &std[*n].age);
    getchar();
    (*n)++;
    printf("Them sinh vien thanh cong.\n");
}

void updeatStuden(Studen std[], int n) {
    int id;
    printf("Hay nhap ID sinh vien can sua: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < n; i++) {
        if (std[i].id == id) {
            printf("Hay nhap ten moi: ");
            fgets(std[i].Name, 100, stdin);
            std[i].Name[strcspn(std[i].Name, "\n")] = '\0';
            printf("Hay nhap tuoi moi: ");
            scanf("%d", &std[i].age);
            getchar();
            printf("Cap nhat thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay ID.\n");
}

void delleteStuden(Studen std[], int *n) {
    int id;
    printf("Hay nhap ID sinh vien can xoa: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < *n; i++) {
        if (std[i].id == id) {
            for (int j = i; j < *n - 1; j++) {
                std[j] = std[j + 1];
            }
            (*n)--;
            printf("Xoa thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay ID.\n");
}

void sstd(Studen std[], int n) {
    int id;
    printf("Hay nhap ID sinh vien can tim: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < n; i++) {
        if (std[i].id == id) {
            printf("ID: %d\n", std[i].id);
            printf("Tuoi: %d\n", std[i].age);
            printf("Ten: %s\n", std[i].Name);
            printf("------------------------\n");
            return;
        }
    }
    printf("Khong tim thay ID.\n");
}

void xapSep(Studen std[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (std[i].age > std[j].age) {
                Studen temp = std[i];
                std[i] = std[j];
                std[j] = temp;
            }
        }
    }
    printf("Danh sach da duoc sap xep.\n");
}

void readFile(Studen std[], int *n) {
    FILE *ptr = fopen("demo1.dat", "rb");
    if (ptr == NULL) {
        return;
    }
    *n = fread(std, sizeof(Studen), 100, ptr);
    fclose(ptr);
}

void saveFile(Studen std[], int n) {
    FILE *ptr = fopen("demo1.dat", "wb");
    if (ptr == NULL) {
        printf("Loi khi luu file.\n");
        return;
    }
    fwrite(std, sizeof(Studen), n, ptr);
    fclose(ptr);
    printf("Luu file thanh cong.\n");
}
