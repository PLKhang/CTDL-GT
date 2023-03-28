#ifndef XU_LY_CHUONG_TRINH_H
#define XU_LY_CHUONG_TRINH_H

#pragma once

#include "ThuVien.h"
#include "doHoa.h"
#include "struct.h"
#include <thread>
using namespace std;

int KiemTraTK(string Name, string Password);
int DANGNHAP();

// login: SV
int HienThiThongTinSinhVien(string mssv);
// line: 1->3 tuong ung 3 option cho nguoi dang nhap la sinh vien
void HienOptionChoSinhVien(int line = 1);
// Kiem tra ma mon, so luong cau hoi truoc khi lay de va bat dau lam bai thi
void NhapMaMonVaThoiGianThi();
// 1: lay de thanh cong, 0: khong du so luong cau hoi, -1, -2 ...
int LayDeThi(STreeCH dsch, CauHoi list[], int soLuongCau);
// tra ve diem thi cua sv
float BatDauLamBai(CauHoi *list[], int soLuongCau, int phut);
// tra ve ket qua dung hoac sai cua dap an;
bool HienCauHoi(CauHoi info);

// Login: GV
// line: 1->6 tuong ung 6 option(lop, them sv, monhoc, bang diem, thi thu, thoat)
void HienOptionGiangVien(int line = 1);
//  types = 0: sap xep theo dslh, 1: sap xep theo ma lop, 2: sap xep theo nien khoa
bool HienDanhSachLop(ListLH dslh, int start, int line, int types = 0);

bool HienBangDiemTheoMon(PtrSV dssv, const char maMon[], int start, int end, int line);
// line: 1->5 tuong ung voi 5 option cua LopHoc, line = 0: chua chon option nao nen khong to mau`
bool HienOptionLopHoc(int line = 0);
// tao folder moi trong function nay`
bool ThemLopHoc();
// xoa folder trong function nay`
bool XoaLopHoc();
bool HieuChinhLopHoc();

// types = 0: sap xep theo mssv, 1: sap xep theo ten
void HienDanhSachSinhVien(PtrSV dssv, int start, int line, int types = 0);
// line: 1->4 tuong ung voi 4 option cua SinhVien
bool HienOptionSinhVien(int line = 0);
bool ThemSinhVien(PtrSV &dssv);
bool XoaSinhVien(PtrSV &dssv);
bool HieuChinhSinhVien(PtrSV &dssv);
bool InCauHoiDaThi(string maLH, string mssv);

void HienDanhSachDiemThi(PtrDT dsdt, int start, int line);
void HienOptionDiemThi(int line = 1);
void ThemDiemThi(PtrDT dsdt);
void XoaDiemThi(PtrDT dsdt);
void HieuChinhDiemThi(PtrDT dsdt);

void HienDanhSachMonHoc(ListMH dsmh, int start, int line);
// line: 1-> 4 tuong ung 4 option cua MonHoc
void HienOptionMonHoc(int line = 1);
void ThemMonHoc();
void XoaMonHoc();
void HieuChinhMonHoc();

void HienDanhSachCauHoi(STreeCH dsch, const char *maMH, int start, int line);
// line: 1-> 4 tuong ung 4 option cua CauHoi
void HienOptionCauHoi(bool line = 0);
void ThemCauHoi();
void XoaCauHoi();
void HieuChinhCauHoi();
void Thi(STreeCH &root, PtrDT &score); // THI
#endif                                 // XU_LY_CHUONG_TRINH_H
