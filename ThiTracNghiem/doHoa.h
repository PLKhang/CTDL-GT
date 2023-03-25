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
void VeKhung();
// Co the dung VeKhung thay the
void VeOptions();

void MENU_GV();
void MENU_SV();
//type = 1: dslh : 3cols, x1 = 25, x2 = 100
//type = 2: dssv : 4cols, x1 = 25, x2 = 80, x3 = 100
//type = 3: dsdt : 2cols, x1 = 90
//type = 4: dsmh : 2cols, x1 = 35
//type = 5: dsch : 2cols, x1 = 35
void VeDanhSach(int types);

void KhungThemSinhVien();
void KhungThemMonHoc();
void KhungThemDiemThi();
void KhungThemLopHoc();
// Khung dung khi lam bai thi, xem cau hoi va HIEU CHINH cau hoi
void KhungCauHoi();
#endif // DO_HOA_H