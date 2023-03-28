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

using namespace std;

void gotoxy(int x, int y);
void TextColor(int color);
void SetBGColor(WORD color);
int wherex(void);
int wherey(void);
void SetColor(int backgound_color, int text_color);
char GetKey();
string NhapChuoi(int x, int y, int chieudai);
string NhapMa(int x, int y, int chieudai = 21, string = "");

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
int doc_danhSachSinhVien(PtrSV &dssv, string maLH);             //--> doc_danhSachLopHoc
int doc_danhSachDiemThi(PtrDT &dsdt, string maLH, string mssv); // --> doc_danhSachSinhVien

int doc_danhSachMonHoc(ListMH &dsmh);
int doc_danhSachCauHoi(STreeCH &dsch);
int doc_CauHoiDaThi(string maLH, string mssv);

// <-- dssv, dsdt, dstk
int ghi_danhSachLopHoc(ListLH dslh);
int ghi_danhSachSinhVien(PtrSV dssv, string maLH);
int ghi_danhSachDiemThi(PtrDT dsdt, string maLH, string mssv);
int ghi_danhSachTaiKhoan(ListLH dslh); // ios::app
int ghi_danhSachMonHoc(ListMH dsmh);
int ghi_danhSachCauHoi(STreeCH dsch);

#endif // THU_VIEN_H