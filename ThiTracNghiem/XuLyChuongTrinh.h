#ifndef XU_LY_CHUONG_TRINH_H
#define XU_LY_CHUONG_TRINH_H

#pragma once

#include "ThuVien.h"
#include "doHoa.h"
#include "struct.h"
#include <thread>
using namespace std;

void MainProcessing(ListMH &dsmh, ListLH &dslh, STreeCH &root);

int KiemTraTK(string Name, string Password);
string DANGNHAP();
int MENU_GV(ListMH &dsmh, ListLH &dslh, STreeCH &root);
// login: SV
int MENU_SV(STreeCH root, ListMH dsmh, string maLop, PtrSV &p);
// tra ve ket qua dung hoac sai cua dap an;
bool HienCauHoi(CauHoi info);

// Login: GV
// line: 1->6 tuong ung 6 option(lop, them sv, monhoc, bang diem, thi thu, thoat)
void HienOptionGiangVien(int line = 1);
//  types = 0: sap xep theo dslh, 1: sap xep theo ma lop, 2: sap xep theo nien khoa
//------------------------LOP HOC----------------------------
string MENU_DSLH_GV(ListLH &dslh, ListMH dsmh, STreeCH root, bool types = 0);

void HienDanhSachLopHoc(LopHoc **data, int page, int maxPage, bool types);
int HienOptionLopHoc(bool check = 0);
// tao folder moi trong function nay`
bool ThemLopHoc(ListLH &dslh);
// xoa folder trong function nay`
bool XoaLopHoc(ListLH &dslh, LopHoc **lh, int count);
bool HieuChinhLopHoc(ListLH dslh, LopHoc **data, int index, int line);
void sortDSLH(LopHoc **dslh, int numOfClass, int &index);
void InDSLH_NienKhoa(ListLH dslh, int nienKhoa);
void THEMSINHVIEN(ListLH &dslh, ListMH dsmh);
//-------------------------SINH VIEN-------------------------
// types: 0->chuc nang quan ly sinh vien, 1->xem dsdt theo mon, 2->lay mssv
PtrSV MENU_DSSV_GV(LopHoc *data, ListMH dsmh,STreeCH root, int types = 0, string maMon = "");
void HienDanhSachSinhVien(PtrSV *data, string tenLop, int page, int maxPage, int types = 0, string maMon = "");
int HienOptionSinhVien(bool check = 0);
bool ThemSinhVien(PtrSV &dssv, ListMH dsmh);
int XoaSinhVien(PtrSV &dssv, PtrSV *data, int count);
bool HieuChinhSinhVien(PtrSV dssv, PtrSV *data, int index, int line);
// sap xep theo mssv <-> sap xep theo ho
void SortDSSV(PtrSV *data, int n, bool &check);

//-------------------------DIEM THI--------------------------
// types: 1->read only, 0->manage
void MENU_DSDT_GV(SinhVien data, ListMH dsmh, bool types = 0);
void HienDanhSachDiemThi(ListMH dsmh, PtrDT *data, string MSSV, string ho, string ten, int page, int maxPage);
int HienOptionDiemThi(bool check = 0);
// sap xep theo mon <-> sap xep theo diem(cao xuong thap)
void SortDSDT(PtrDT *data, int n, int &check);

//--------------------------MON HOC---------------------------
// types: 0-> chuc nang quan ly mon hoc, 1-> chon ma mon hoc de thi
string MENU_DSMH_GV(STreeCH &root, ListMH &dsmh,bool types = 0);
void HienDanhSachMonHoc(ListMH dsmh, int page, int maxPage, bool types);
// line: 1-> 4 tuong ung 4 option cua MonHoc
int HienOptionMonHoc(bool check = 0);
bool ThemMonHoc(ListMH &dsmh);
bool XoaMonHoc(ListMH &dsmh, int index);
// index: vi tri HIEU CHINH trong dsmh, line: vi tri hieu chinh tren man hinh
bool HieuChinhMonHoc(ListMH &dsmh, int index, int line);

//--------------------------CAU HOI-------------------------
int MENU_DSCH_GV(STreeCH &root, MonHoc monHoc);
void HienDanhSachCauHoi(STreeCH dsch, const char *maMH, int start, int line);
// line: 1-> 4 tuong ung 4 option cua CauHoi
void HienOptionCauHoi(bool line = 0);
void ThemCauHoi();
void XoaCauHoi();
void HieuChinhCauHoi();
void InCauHoiDaThi(STreeCH root, MonHoc monHoc, char MSSV[]);
int CauHoi1(STreeCH &root, char maMH[], char tenMH[]);
void Thi(STreeCH &root, PtrSV &SV, ListMH &dsmh);

#endif // XU_LY_CHUONG_TRINH_H
