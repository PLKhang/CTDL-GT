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
// MaLH(C20), TenLH(C70), NienKhoa(C10)
void VeDanhSachLopHoc(ListLH dslh);
// MSSV(C20), Ho(C50), Ten(C20), GioiTinh(C10)
void VeDanhSachSinhVien(PtrSV dssv);
// MaMH(C20), DiemThi(C50)
void VeDanhSachDiemThi(PtrDT dsdt);
// MaMH(C20), TenMH(C50)
void veDanhSachMonHoc(ListMH dsmh);
// ID(C20), CauHoi(C50)( > 50 -> C47 + "...")
void VeDanhSachCauHoi();

void KhungThemSinhVien();
void KhungThemMonHoc();
void KhungThemDiemThi();
void KhungThemLopHoc();
// Khung dung khi lam bai thi, xem cau hoi va HIEU CHINH cau hoi
void KhungCauHoi();
#endif // DO_HOA_H