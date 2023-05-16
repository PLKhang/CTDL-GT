#ifndef DO_HOA_H
#define DO_HOA_H

#include <iostream>
#include <string>
#include <iomanip>

#include "struct.h"
#include "ThuVien.h"
#include "define.h"

using namespace std;
// Ve bang thong bao, chi xuat hien khi can thong bao
// nhung van chua` khoang trong tai vi tri bangThongBao khi ve cac bang khac
int THONGBAO(int option, string thongbao = "");
// Hien thong bao xac nhan YES / NO de xac nhan khi thuc hien 1 cong viec
bool XacNhan();
// Tieu de cua cac bang vd(DANH SACH CAC LOP hoac DANH SACH LOP D21CQCN01-N, ...),
void VeHeader(int types, string text1 = "", string text2 = "");

// type = 1: dslh : 3cols, x1 = 25, x2 = 100
// type = 2: dssv : 4cols, x1 = 25, x2 = 80, x3 = 100
// type = 3: dsdt : 2cols, x1 = 90
// type = 4: dsmh : 2cols, x1 = 35
// type = 5: dsch : 2cols, x1 = 35
bool VeDanhSach(int types);
void VeKhung(int x1, int y1, int x2, int y2);
bool KhungThem(int types);

void chuMenuGV(int x, int y);
void chuThiTracNghiem(int x, int y);
void chuMenuSV(int x, int y);
void XoaVungThi();
void VeKhungCauHoi(int index,int Answer_index=0,int option=0);
void VeKhungCauHoi1(char tenMH[], int ID=0);
void VeBangDanhSachCauHoi(char maMH[], int MaxPage, int Page);
float VeKhungDiem(STreeCH *Questions, char YourAnswer[], PtrSV &SV, int so_cau);
string VeKhungNhapThi(int tong_so_cau, int &so_cau, int &thoi_gian);
void ThanhChucNang(int option);
#endif // DO_HOA_H
