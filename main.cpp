// thư viện
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#define sl 100

// khai báo Struct Date
struct Date
{
    int ngay;
    int thang;
    int nam;
};
typedef Date date;

// khai báo Struct NhanVien
struct NhanVien
{
    int msnv;
    char ho[20];
    char ten[20];
    date namSinh;
    char noiSinh[100];
    char diaChi[200];
    float luong;
    date ngayVao;
};
typedef NhanVien nhanVien;
// khai báo danh sanh nv
struct DanhSach
{
    nhanVien a[sl];
    int n;
};
typedef DanhSach danhSach;

// Các hàm sử dụng
void menu();
void nhapNgayThang(date *ntn);
void nhap1NV(nhanVien *nv);
void xuat1NV(nhanVien *nv);
void xuatNgayThang(date ntn);
void nhapDanhSachNV(danhSach *ds);
void xuatDanhSachNV(danhSach ds);
int timTheoTen(danhSach ds, char *c[]);
void themNV(danhSach *ds, nhanVien *nv, int viTri);
int timTheoMa(danhSach ds, int viTri);
void xoaNV(danhSach ds, int viTri);
// ktra
// kiểm tra int
int checkInputInteger();

int main()
{

    menu();
    getch();
    return 0;
}

void menu()
{
    do
    {
        int chon;
        printf("\n****************MENU****************\n");
        printf("1.Them vao 1 nhan vien.\n");
        printf("2.Tim nhan vien theo ma.\n");
        printf("3.Tim nhan vien theo ten.\n");
        printf("4.Bang luong cua nhan vien giam dan.\n");
        printf("5.Xoa 1 nhan vien theo ma.\n");
        printf("0.Thoat chuong trinh.\n");
        printf("************************************\n");
        chon = checkInputInteger();
        switch (chon)
        {
        case 1:
            printf("Case 1");
            printf("\nBam phim bat ky de tiep tuc");
            getch();
            system("cls");
            break;
        case 2:
            printf("Case 2");
            printf("\nBam phim bat ky de tiep tuc");
            getch();
            system("cls");
            break;
        case 3:
            printf("Case 3");
            printf("\nBam phim bat ky de tiep tuc");
            getch();
            system("cls");
            break;
        case 4:
            printf("Case 4");
            printf("\nBam phim bat ky de tiep tuc");
            getch();
            system("cls");
            break;
        case 5:
            printf("Case 5");
            printf("\nBam phim bat ky de tiep tuc");
            getch();
            system("cls");
            break;
        case 0:
            printf("Ban da chon thoat chuong trinh");
            return;
            break;
        default:
            printf("Chuc nang khong ton tai!\n");
        }
    } while (1);
}

int checkInputInteger()
{
    int num;
    int result;
    do
    {
        printf("Vui long chon chuc nang: ");
        result = scanf("%d", &num);
        //  xóa bộ đệm đầu vào
        while (getchar() != '\n')
            ;
        if (result != 1)
        {
            printf("Vui long chon chuc nang la so!\n");
        }
    } while (result != 1);
    return num;
}
