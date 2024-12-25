#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct 
{
    char fullName[100];
    char pass[100];
    char pass2[100];

}Accounts;
void registe(Accounts acc[], int *n);
void logIn(Accounts acc[], int n);
void saveFlie(Accounts *acc);
void readFile(Accounts acc[], int *n);
int main(){
    Accounts acc[100];
	int choice,n=0;
    readFile(acc,&n);
    do
    {
        printf("\n=========== MENU ===========\n");
        printf("1. dang nhap\n");
        printf("2. dang ky\n");
        printf("3. thoat\n");
        printf("============================\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                logIn(acc, n);
                break;
            case 2:
                registe(acc,&n);
                break;
            case 3:
                
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 3);
    return 0;
}
void registe(Accounts acc[],int *n){
    Accounts newAccount;
    printf("Moi ban nhap vao ten dang nhap: ");
	fgets(newAccount.fullName, 100, stdin);
	newAccount.fullName[strcspn(newAccount.fullName, "\n")] = '\0';
	do
    {
        printf("Moi bn nhap vao pass: \n");
        fgets(newAccount.pass, 100, stdin);
        newAccount.pass[strcspn(newAccount.pass, "\n")] = '\0';
        printf("Moi bn xac nhap lai pass: \n");
	    fgets(newAccount.pass2, 100, stdin);
        newAccount.pass2[strcspn(newAccount.pass2, "\n")] = '\0';
        if (strcmp(newAccount.pass, newAccount.pass2) != 0) {
            printf("Mat khau xac nhan khong khop. Vui long nhap lai.\n");
        }
    } while (strcmp(newAccount.pass2,newAccount.pass)!=0);
    for (int i = 0; i < *n; i++)
    {
        if (strcmp(acc[i].fullName,newAccount.fullName)==0)
        {
            printf("tai khoan da ton tai: \n");
            return;
        }
    }
    saveFlie(&newAccount);
    acc[*n] = newAccount;
    (*n)++;
    printf("dang ky thanh cong:\n");
}
void saveFlie(Accounts *acc){
    FILE *ptr =fopen("demo1.dat","ab"); 
	fwrite(acc,sizeof(Accounts),1,ptr);
    printf("luu thanh cong:\n");
    fclose(ptr);
}
void readFile(Accounts acc[], int *n){
    FILE *ptr = fopen("demo1.dat","rb");
    if (ptr==NULL)
    {
        return;
    }
    *n=fread(acc,sizeof(Accounts),100,ptr);
    fclose(ptr);
}
void logIn(Accounts acc[], int n){
    Accounts accounts;
    printf("Moi ban nhap vao ten dang nhap: ");
	fgets(accounts.fullName, 100, stdin);
	accounts.fullName[strcspn(accounts.fullName, "\n")] = '\0';
    printf("Moi bn nhap vao pass: \n");
    fgets(accounts.pass, 100, stdin);
    accounts.pass[strcspn(accounts.pass, "\n")] = '\0';
    for (int i = 0; i < n; i++)
    {
        if (strcmp(accounts.fullName,acc[i].fullName)==0&&strcmp(accounts.pass,acc[i].pass)==0)
        {
            printf("dang nhap thanh cong:\n");
            return;
        }
        
    }
    printf("dang nhap ko thanh cong:\n");
}