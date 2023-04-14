#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

void menu()
{
    printf("\n\t****************MENU****************\n");
    printf("\t1.Them vao 1 nhan vien.\n");
    printf("\t2.Tim nhan vien theo ma.\n");
    printf("\t3.Tim nhan vien theo ten.\n");
    printf("\t4.Bang luong cua nhan vien giam dan.\n");
    printf("\t5.Xoa 1 nhan vien theo ma.\n");
    printf("\t0.Thoat chuong trinh.\n");
    printf("\t************************************\n");
    printf("\t==> Chon 1 chuc nang: ");
}
int main()
{
    int chon;
    do
    {
        menu();
        scanf("%d", &chon);
        switch (chon)
        {
        case 1:
            printf("Case 1");
            break;
        case 2:
            printf("Case 2");
            break;
        case 3:
            printf("Case 3");
            break;
        case 4:
            printf("Case 4");
            break;
        case 5:
            printf("Case 5");
            break;
        case 0:
            printf("Case 0");
            break;
        default:
            printf("Chuc nang khong ton tai!\n");
        }
    } while (chon != 0);
    return 0;
}