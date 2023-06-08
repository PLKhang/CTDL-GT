#ifndef THU_VIEN_H
#define THU_VIEN_H

#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <fstream>
#include <cstring>

#include "struct.h"
#include "define.h"

using namespace std;
void FullScreen();
void gotoxy(int x, int y);
void TextColor(int color);
void SetBGColor(WORD color);
int wherex(void);
int wherey(void);
void SetColor(int backgound_color, int text_color);
int GetKey();
string NhapChuoi(int x, int y, int chieudai,int option=0);
string NhapChuoi1(int x, int y, int length,string &input);
string NhapDapAn(int x,int y,char &Answer);
string NhapMa(int x, int y, int chieudai = 20, string = "");
string NhapMa1(int x, int y, int chieudai ,string &input,string loai = "");
double NhapSo(int x, int y, int soluong);
string NhapSo1(int x, int y, int soluong,int&num);
// kiem tra neu mang ky tu rong
bool is_Empty_CArray(const char *a);
// xoa 1 dong dang hien thi tren man hinh de tao khoang trong dien thong tin moi
void delete_LineOnScreen(int x, int y, int length);
void delete_AreaOnScreen(int x, int y, int width, int height = 1);
void setCursorVisibility(bool isVisible);

bool createLopHocFolder(string maLH);
bool removeLopHocFolder(string maLH);
bool removeLopHocFile(string maLH);
bool removeSinhVienFile(string maLH, string mssv);

/*
return:
0:  khong mo duoc file dslh
1:  ok
-1: doc file dslh loi~
-2: khong doc duoc file cho dslk SinhVien
-3: doc file cho dslk SinhVien bi loi~
-4: khong doc duoc file cho dslk DiemThi
-5: doc file cho dslk DiemThi bi loi~
 */
int doc_danhSachLopHoc(ListLH &dslh);
int doc_danhSachSinhVien(PtrSV &dssv, const string &maLH);                    //--> doc_danhSachLopHoc
int doc_danhSachDiemThi(PtrDT &dsdt, const string &maLH, const string &mssv); // --> doc_danhSachSinhVien

int doc_danhSachMonHoc(ListMH &dsmh);
int doc_danhSachCauHoi(STreeCH &dsch);
int docCauHoiDaThi(STreeCH root, Array<STreeCH>&List,char YourAnswer[], char MSSV[], MonHoc MH);
int demSoCauDaThi(MonHoc MH, char MSSV[]);
// <-- dssv, dsdt, dstk
int ghi_danhSachLopHoc(ListLH dslh);
int ghi_danhSachSinhVien(PtrSV dssv, string maLH);
int ghi_danhSachDiemThi(PtrDT dsdt, string maLH, string mssv);
int ghi_danhSachTaiKhoan(ListLH dslh); // ios::app
int ghi_danhSachMonHoc(ListMH dsmh);
int ghi_danhSachCauHoi(STreeCH dsch);
void GhiCauHoiDaThi(char MSSV[], STreeCH *ListQuestion, char YourAnswer[], int numberQuestion);

#endif // THU_VIEN_H
