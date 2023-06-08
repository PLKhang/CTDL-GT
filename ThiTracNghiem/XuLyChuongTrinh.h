#ifndef XU_LY_CHUONG_TRINH_H
#define XU_LY_CHUONG_TRINH_H

#pragma once

#include "ThuVien.h"
#include "doHoa.h"
#include "struct.h"
#include <thread>
#include<iomanip>
using namespace std;

void MainProcessing(ListMH &dsmh, ListLH &dslh, STreeCH &root);

int KiemTraTK(string Name, string Password);
string DANGNHAP();
int MENU_GV();
// login: SV
int MENU_SV();

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

bool THEMSINHVIEN(ListLH &dslh, ListMH dsmh, STreeCH root);
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
void HienDanhSachDiemThi(ListMH dsmh, PtrDT *data, string MSSV, string ho, string ten, int numOfSubs, int page, int maxPage);
//--------------------------MON HOC---------------------------
// types: 0-> chuc nang quan ly mon hoc
// types: 1-> chon mon hoc
// types: 2-> thi: mon hoc da thi -> khong hien ra
string MENU_DSMH_GV(STreeCH &root, ListMH &dsmh, int selectMode = 0, PtrSV SV = NULL);
bool ThemMonHoc(ListMH &dsmh);
bool XoaMonHoc(ListMH &dsmh, MonHoc *temp[], int index);
// chi duoc hieu chinh ten mon hoc
bool HieuChinhMonHoc(ListMH dsmh, MonHoc &selectedSubject, int line);
void HienDanhSachMonHoc(MonHoc *dsmh[], int numOfSubs, int page, int maxPage, bool selectMode);
// types: 0-> chon option
// types: 1-> chi hien option
int HienOptionMonHoc(bool types = 0);
//--------------------------CAU HOI-------------------------
int InCauHoiThi(STreeCH &Question, char YourAnswer, int current_index, int so_cau, int option = 0);
string NhapSC_TG(int &so_cau, int &thoi_gian, int soluongcauhoi, PtrSV &SV);
void Thi(STreeCH &root, PtrSV &SV, ListMH &dsmh);
STreeCH ThemCauHoi(STreeCH &root, char maMH[], char tenMH[]);
int XemCauHoi(STreeCH &root, STreeCH &ExsistQuestion, char tenMH[]);
void InDanhSachCH(Array<STreeCH> &ListQuestion, char maMH[], int start, int end, int Page, int MaxPage);
bool TimCauHoi1(Array<STreeCH> &List, int &NumberQuestion);
void MENU_DSCH_GV(STreeCH &root, MonHoc monHoc);
void Tim_End_Start(int NOE[], int &start, int &end, int lanthi, int NumberQuestion, int NumberofExams);
bool TimCauHoi2(Array<STreeCH> List, char YourAnswer[], int &end);
void InCauHoiDaThi(STreeCH root, MonHoc monHoc, char MSSV[]);

#endif // XU_LY_CHUONG_TRINH_H
