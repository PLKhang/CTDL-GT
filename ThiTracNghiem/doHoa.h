#ifndef DO_HOA_H
#define DO_HOA_H

#include <iostream>
#include <string>

#include "struct.h"
#include "ThuVien.h"

using namespace std;
// Ve bang thong bao, chi xuat hien khi can thong bao
// nhung van chua` khoang trong tai vi tri bangThongBao khi ve cac bang khac
int ThongBao();
// Hien thong bao xac nhan YES / NO de xac nhan khi thuc hien 1 cong viec
bool XacNhan();
// Tieu de cua cac bang vd(DANH SACH CAC LOP hoac DANH SACH LOP D21CQCN01-N, ...),
void VeHeader();
void VeOptions();

void MENU_GV();
void MENU_SV();
// type = 1: dslh : 3cols, x1 = 25, x2 = 100
// type = 2: dssv : 4cols, x1 = 25, x2 = 80, x3 = 100
// type = 3: dsdt : 2cols, x1 = 90
// type = 4: dsmh : 2cols, x1 = 35
// type = 5: dsch : 2cols, x1 = 35
void VeDanhSach(int types);
void VeKhung(int x1, int y1, int x2, int y2);
void KhungThemSinhVien();
void KhungThemMonHoc();
void KhungThemDiemThi();
void KhungThemLopHoc();

void chuMenuGV(int x, int y);
void chuThiTracNghiem(int x, int y);
void chuMenuSV(int x, int y);
void VeBangCauHoi();
void VeKhungThi();
int MenuGV();

#endif // DO_HOA_H