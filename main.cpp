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
// menu
void menu();
void nhapNgayThang(date &ntn);
NhanVien nhap1NV(danhSach &ds);
void xuat1NV(nhanVien nv);
void xuatNgayThang(date ntn);
void nhapDanhSachNV(danhSach &ds);
void xuatDanhSachNV(danhSach ds);
void timTheoTen(danhSach ds, char *c, danhSach &dsKetQua);
void themNV(danhSach &ds, nhanVien &nv, int viTri);
int timTheoMa(danhSach ds, int ma);
void xoaNV(danhSach &ds, int vt);
void sapXep(danhSach ds);
// kiểm tra int
int checkInputInteger(char err[1000]);
int kiemTraNgayThang(date &ntn);
int kiemTraNamNhuan(int nam);
void swap(nhanVien &a, nhanVien &b);
// case
void case1(danhSach &ds);
void case2(danhSach ds);
void case3(danhSach ds);
void case4(danhSach ds);
void case5(danhSach &ds);

int main()
{
    menu();
    getch();
    return 0;
}
// menu
void menu()
{
    danhSach ds;
    int chon, viTriThem;
    nhanVien *nv;
    nhanVien nvm;
    nhapDanhSachNV(ds);
    do
    {
        printf("\t-------------------");
        printf("\n\tDanh sach nhan vien");
        printf("\n\t-------------------");
        xuatDanhSachNV(ds);
        printf("\n****************MENU****************\n");
        printf("1.Them vao 1 nhan vien.\n");
        printf("2.Tim nhan vien theo ma so.\n");
        printf("3.Tim nhan vien theo ten.\n");
        printf("4.Bang luong cua nhan vien giam dan.\n");
        printf("5.Xoa 1 nhan vien theo ma.\n");
        printf("0.Thoat chuong trinh.\n");
        printf("************************************\n");
        printf("Vui long chon 1 trong cac chuc nang tren: ");
        char err[100] = "Loi chuc nang! Vui long chon chuc nang [0-5].";
        chon = checkInputInteger(err);
        printf("\n");
        switch (chon)
        {
        case 1:
            printf("Ban da chon them mot nhan vien: \n");
            case1(ds);
            printf("\nBam phim bat ky de tiep tuc");
            getch();
            system("cls");
            break;
        case 2:
            case2(ds);
            printf("\nBam phim bat ky de tiep tuc");
            getch();
            system("cls");
            break;
        case 3:
            case3(ds);
            printf("\nBam phim bat ky de tiep tuc");
            getch();
            system("cls");
            break;
        case 4:
            case4(ds);
            printf("\nBam phim bat ky de tiep tuc");
            getch();
            system("cls");
            break;
        case 5:
            case5(ds);
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
// case 1:
void case1(danhSach &ds)
{
    int viTriThem = -1;
    nhanVien nvm;

    printf("Vui long nhap vi tri ban muon them: ");
    char err1[] = "Vui long vi tri la so nguyen!";
    viTriThem = checkInputInteger(err1);
    if (viTriThem < 1 || viTriThem > ds.n + 1)
    {
        printf("Vui long nhap vi tri > 0 va < %d\n", ds.n + 1);
        case1(ds);
    }
    else
    {
        nvm = nhap1NV(ds);
        themNV(ds, nvm, viTriThem - 1);
        printf("\t--------------------------------");
        printf("\n\tDanh sach nhan vien sau khi them");
        printf("\n\t--------------------------------");
        xuatDanhSachNV(ds);
    }
}
// case 2:
void case2(danhSach ds)
{
    printf("Ban da chon tim nhan vien theo ma so.\n");
    printf("Vui long nhap MSNV can tim: ");
    int maTim = -1;
    char err2[] = "Vui long nhap ma so la so nguyen!";
    maTim = checkInputInteger(err2);
    int ketQua = timTheoMa(ds, maTim);
    if (ketQua == -1)
    {
        printf("Khong tim thay nhan vien co ma: %d", maTim);
    }
    else
    {
        printf("Nhan vien co ma: %d", maTim);
        xuat1NV(ds.a[ketQua]);
    }
}
// case 3:
void case3(danhSach ds)
{
    printf("Ban da chon tim nhan vien theo ten.\n");
    danhSach dsKetQua;
    char c[100];
    printf("Vui long nhap ten nhan vien can tim: ");
    gets(c);
    dsKetQua.n = 0;
    timTheoTen(ds, c, dsKetQua);
    if (dsKetQua.n == 0)
    {
        printf("Khong tim thay nhan vien co ten: %s", c);
    }
    else
    {
        printf("\t-----------------------------");
        printf("\n\tDanh sach nhan vien co ten: %s", c);
        printf("\n\t-----------------------------");
        xuatDanhSachNV(dsKetQua);
    }
}
// case 4
void case4(danhSach ds)
{
    printf("Ban da chon danh sach nhan vien theo luong giam dan.\n");
    sapXep(ds);
};
// case 5
void case5(danhSach &ds)
{
    printf("Ban da chon xoa nhan vien theo ma.\n");
    printf("Vui long nhap MSNV can xoa: ");
    int maXoa = -1;
    char err5[] = "Vui long nhap ma so la so nguyen!";
    maXoa = checkInputInteger(err5);
    int ketQua = timTheoMa(ds, maXoa);
    if (ketQua == -1)
    {
        printf("Khong tim thay nhan vien co ma: %d", maXoa);
    }
    else
    {
        printf("Xac nhan xoa nhan vien co ma: %d\n", maXoa);
        printf("Nhap Y/y = 'Xoa' hoac N/n = 'Huy'\n");
        printf("Xac nhan: ");
        char xacNhan;
        while (true)
        {
            scanf(" %c", &xacNhan);
            if (xacNhan == 'y' || xacNhan == 'Y')
            {
                xoaNV(ds, ketQua);
                printf("Xoa thanh cong nhan vien ma: %d\n", maXoa);
                return;
            }
            else if (xacNhan == 'n' || xacNhan == 'N')
            {
                printf("Da huy xoa");
                return;
            }
            else
            {
                printf("Khong hop le. Vui long nhap 'Y/y' or 'N/n': ");
            }
        }
    }
};

int checkInputInteger(char err[1000])
{
    int num;
    int result;
    do
    {
        fflush(stdin);

        result = scanf("%d", &num);
        //  xóa bộ đệm đầu vào
        fflush(stdin);
        if (result != 1)
        {
            printf("%s\n", err);
            printf("\tVui long nhap lai: ");
        }
    } while (result != 1);
    return num;
};

// tham chiếu
nhanVien nhap1NV(danhSach &ds)
{
    nhanVien nv;
    printf("\tMoi nhap MSNV: ");
    char errMa[] = "Ma nhan vien la so nguyen!";
    while (true)
    {
        nv.msnv = checkInputInteger(errMa);
        int check = timTheoMa(ds, nv.msnv);
        if (check != -1)
        {
            printf("Ma nhan vien da ton tai!");
            printf("\n\tVui long nhap lai MSNV: ");
            continue;
        }
        else if (nv.msnv < 0)
        {
            printf("Ma nhan vien > 0 ");
            printf("\n\tVui long nhap lai MSNV: ");
            continue;
        }
        else
        {
            break;
        }
    }
    fflush(stdin);
    printf("\tMoi nhap ho: ");
    gets(nv.ho);
    printf("\tMoi nhap ten: ");
    gets(nv.ten);
    printf("\tMoi nhap ngay sinh: \n");
    nhapNgayThang(nv.namSinh);
    fflush(stdin);
    printf("\tMoi noi sinh: ");
    gets(nv.noiSinh);
    printf("\tMoi dia chi: ");
    gets(nv.diaChi);
    printf("\tMoi nhap luong: ");
    scanf("%f", &nv.luong);
    printf("\tMoi nhap ngay vao: \n");
    nhapNgayThang(nv.ngayVao);
    return nv;
};

void nhapDanhSachNV(danhSach &ds)
{
    char errMa[] = "SL nhan vien la so nguyen!";
    printf("\nNhap so luong nhan vien: ");
    char err[] = "Vui long nhap so luong la so nguyen!";
    ds.n = checkInputInteger(err);
    if (ds.n < 0 || ds.n > 100)
    {
        printf("Vui long nhap so luong > 0 va < 100");
        nhapDanhSachNV(ds);
    }
    else
    {
        for (int i = 0; i < ds.n; i++)
        {
            printf("Vui long nhap thong tin nhan vien thu %d:\n", i + 1);
            nhanVien nv = nhap1NV(ds);
            ds.a[i] = nv;
        };
    }
};

void nhapNgayThang(date &ntn)
{
    printf("\t\tNhap ngay: ");
    char err[] = "Vui long nhap so nguyen de nhap ngay/thang/nam sinh!";
    ntn.ngay = checkInputInteger(err);
    printf("\t\tNhap thang: ");
    ntn.thang = checkInputInteger(err);
    printf("\t\tNhap nam: ");
    ntn.nam = checkInputInteger(err);
    if (!kiemTraNgayThang(ntn))
    {
        // Nếu ngày tháng không hợp lệ xuất thông báo và yêu cầu nhập lại
        printf("Vui long nhap lai!\n");
        nhapNgayThang(ntn);
    }
}

void xuat1NV(nhanVien nv)
{
    printf("\n\tHo ten: %s %s - MSNV: %d", nv.ho, nv.ten, nv.msnv);
    printf("\n\tNgay sinh: ");
    xuatNgayThang(nv.namSinh);
    printf(" - Noi sinh: %s", nv.noiSinh);
    printf("\n\tDia chi: %s - Luong: %.0f vnd", nv.diaChi, nv.luong);
    printf("\n\tNgay vao: ");
    xuatNgayThang(nv.ngayVao);
}

void xuatNgayThang(date ntn)
{
    printf("%d/%d/%d", ntn.ngay, ntn.thang, ntn.nam);
}

void xuatDanhSachNV(danhSach ds)
{
    if (ds.n == 0)
    {
        printf("\nDanh sach nhan vien trong!\n");
    }
    else
    {
        for (int i = 0; i < ds.n; i++)
        {
            printf("\nNhan vien thu %d", i + 1);
            xuat1NV(ds.a[i]);
        }
    }
}

int kiemTraNgayThang(date &ntn)
{
    int t = ntn.thang;
    int n = ntn.ngay;
    switch (t)
    {
        // Những tháng có 31 ngày
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (n < 0 || n > 31)
        { // Nếu ngày > 31 xuất thông báo k hợp lệ trả về 0
            printf("Ngay %d Thang %d Nam %d khong hop le!\n", n, t, ntn.nam);
            return 0;
        }
        break;
    // Những tháng  có 30 ngày
    case 4:
    case 6:
    case 9:
    case 11:
        if (n < 0 || n > 30)
        { // Nếu ngày > 30 xuất thông báo k hợp lệ trả về 0
            printf("Ngay %d Thang %d Nam %d khong hop le!\n", n, t, ntn.nam);
            return 0;
        }
        break;
    case 2:
        if (kiemTraNamNhuan(ntn.nam))
        { // Kiểm tra năm nhuận tháng có 29 ngày
            if (n < 0 || n > 29)
            {
                printf("Ngay %d Thang %d Nam %d khong hop le!\n", n, t, ntn.nam);
                return 0;
            }
        }
        else
        { // Không là năm nhuận chỉ có 28 ngày
            if (n < 0 || n > 28)
            {
                printf("Ngay %d Thang %d Nam %d khong hop le!\n", n, t, ntn.nam);
                return 0;
            }
        }
        break;
    default:
        printf("Ngay %d Thang %d Nam %d khong hop le!\n", n, t, ntn.nam);
        return 0;
    }
    return 1;
}

int kiemTraNamNhuan(int nam)
{
    // Kiểm tra nếu là năm nhuận trả về 1 ngược lại trả về 0
    if (nam % 4 == 0 || (nam % 100 == 0 && nam % 400 == 0))
    {
        return 1;
    }
    return 0;
};

void themNV(danhSach &ds, nhanVien &nv, int viTri)
{
    ds.n++;
    for (int i = ds.n - 1; i > viTri; i--)
    {
        ds.a[i] = ds.a[i - 1];
    }
    ds.a[viTri] = nv;
};

int timTheoMa(danhSach ds, int ma)
{
    for (int i = 0; i < ds.n; i++)
    {
        if (ds.a[i].msnv == ma)
        {
            return i;
        }
    }
    return -1;
};

void timTheoTen(danhSach ds, char *c, danhSach &dsKetQua)
{
    int count = 0;
    for (int i = 0; i < ds.n; i++)
    {
        if (strcasecmp(ds.a[i].ten, c) == 0)
        {
            themNV(dsKetQua, ds.a[i], dsKetQua.n);
        }
    }
};

void sapXep(danhSach ds)
{
    for (int i = 0; i < ds.n - 1; i++)
    {
        for (int j = i + 1; j < ds.n; j++)
        {
            if (ds.a[i].luong < ds.a[j].luong)
            {
                swap(ds.a[i], ds.a[j]);
            }
        }
    }
    printf("\t-------------------------------");
    printf("\n\tDanh sach nhan sau khi sap xep: ");
    printf("\n\t---------------------------------");
    xuatDanhSachNV(ds);
};

void swap(nhanVien &a, nhanVien &b)
{
    nhanVien temp = a;
    a = b;
    b = temp;
};

void xoaNV(danhSach &ds, int vt)
{
    for (int i = vt; i < ds.n; i++)
    {
        ds.a[i] = ds.a[i + 1];
    }
    ds.n--;
};