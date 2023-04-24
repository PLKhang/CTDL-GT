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

//------------------------LOP HOC----------------------------
// types: 0-> quan ly dslh, 1->chon lop hoc->return "maLop"
string MENU_DSLH_GV(ListLH &dslh, ListMH dsmh, STreeCH root, bool types = 0);
// tao folder moi trong function nay`
bool ThemLopHoc(ListLH &dslh, int check = 0, string maLH = "");
// xoa folder trong function nay`
bool XoaLopHoc(ListLH &dslh, LopHoc **lh, int count);
bool HieuChinhLopHoc(ListLH dslh, LopHoc **data, int index);

void HienDanhSachLopHoc(LopHoc **data, int numOfClasses, int page, int maxPage, bool types);
int HienOptionLopHoc(bool check = 0);
bool sortDSLH(LopHoc **dslh, int numOfClass, int &index);
void DanhSachTheoNienKhoa(ListLH dslh, LopHoc **data, int nienKhoa, int &numOfClasses);

bool THEMSINHVIEN(ListLH &dslh, ListMH dsmh);
//-------------------------SINH VIEN-------------------------
// types: 0->chuc nang quan ly sinh vien, 1->xem dsdt theo mon, 2->lay mssv
PtrSV MENU_DSSV_GV(ListLH dslh, int classIndex, ListMH dsmh, STreeCH root, int types = 0, string maMon = "");
bool ThemSinhVien(ListLH dslh, PtrSV &dssv, ListMH dsmh);
bool XoaSinhVien(PtrSV &dssv, PtrSV *data, const string &maLH, int index);
bool HieuChinhSinhVien(ListLH dslh, PtrSV dssv, PtrSV *data, int index);

void HienDanhSachSinhVien(PtrSV *data, string tenLop, int page, int maxPage, int types = 0, string maMon = "");
int HienOptionSinhVien(bool check = 0);
// sap xep theo mssv <-> sap xep theo ho
void SortDSSV(PtrSV *data, int n, bool &check);

//-------------------------DIEM THI--------------------------
// types:  0->co the chinh sua diem thi, 1->chi xem diem
void MENU_DSDT_GV(SinhVien &data, ListMH dsmh, STreeCH root, bool types = 0);
void HienDiemThi(STreeCH root, MonHoc monHoc, SinhVien &data, int numOfScores);
bool ThemDiemThi(PtrDT &dsdt, PtrDT *data, ListMH dsmh, STreeCH root);
bool XoaDiemThi(PtrDT &dsdt, PtrDT *data, int index);
bool HieuChinhDiemThi(PtrDT *data, int index, int line);

void HienDanhSachDiemThi(ListMH dsmh, PtrDT *data, string MSSV, string ho, string ten, int numOfSubs, int page, int maxPage, bool is_SV = false);
void HienDiemTheoLanThi(PtrDT *data, int numOfScores, int page, int maxPage);
int HienOptionDiemThi(bool check = 0);
// sap xep theo mon <-> sap xep theo diem(cao xuong thap)
void SortDSDT(PtrDT *data, int n, int &check);

//--------------------------MON HOC---------------------------
// types: 0-> chuc nang quan ly mon hoc, 1-> chon ma mon hoc de thi
string MENU_DSMH_GV(STreeCH &root, ListMH &dsmh, bool types = 0);
bool ThemMonHoc(ListMH &dsmh);
bool XoaMonHoc(ListMH &dsmh, int index);
// index: vi tri HIEU CHINH trong dsmh, line: vi tri hieu chinh tren man hinh
bool HieuChinhMonHoc(ListMH &dsmh, int index, int line);

void HienDanhSachMonHoc(ListMH dsmh, int page, int maxPage, bool types);
int HienOptionMonHoc(bool check = 0);
//--------------------------CAU HOI-------------------------
int MENU_DSCH_GV(STreeCH &root, MonHoc monHoc);
void InCauHoiThi(STreeCH &Question, char so_cau_dung[], int i, int so_cau);
void HienDanhSachCauHoi(STreeCH dsch, const char *maMH, int start, int line);
void ThemCauHoi(STreeCH &root, char maMH[], char tenMH[]);
void XemCauHoi(STreeCH &root, STreeCH &ExsistQuestion, char tenMH[]);
void InDanhSachCH(STreeCH *ListQuestion, char maMH[], int start, int end, int Page, int MaxPage);
void InCauHoiDaThi(STreeCH root, MonHoc monHoc, char MSSV[], int LANTHI = -1);
void Tim_End_Start(STreeCH List[], int NOE[], int &start, int &end, int lanthi, int NumberQuestion, int NumberofExams);
void Thi(STreeCH &root, PtrSV &SV, ListMH &dsmh);

#endif // XU_LY_CHUONG_TRINH_H
