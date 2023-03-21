#ifndef DANH_SACH_LOP_HOC
#define DANH_SACH_LOP_HOC

#pragma once
#include <iostream>
#include "SinhVien.h"

#define MaxOfClasses 500

struct LopHoc
{
    char maLop[16];
    char tenLop[51];
    char nienKhoa[11];
    PtrSV First = NULL;
};

struct DanhSachLopHoc // MANG CON TRO
{
    int soLuong = 0;
    LopHoc* nodes[MaxOfClasses];
};

typedef DanhSachLopHoc ListLH;

bool is_Empty_LH(ListLH &ListLH);
bool is_Full_LH(ListLH &ListLH);
bool is_Existed_MaLop(ListLH &ListLH, char maLop[]);

//void FunctionLop(ListLH &ListLH);// HAM DO HOA

void ThemLop(ListLH &ListLH, LopHoc);

//void NhapLop(ListLH &ListLH, LopHoc);

void XoaLop (ListLH &ListLH, int &page);
//void NhapLopXoa(ListLH &ListLH,int &page);

void SuaLop(ListLH &ListLH, int state, int page);
void ChinhLop(ListLH &ListLH, int &page);
//void NhapLopChinh(ListLH &ListLH , int &page);

void InDSLH(ListLH ListLH);

#endif // DANH_SACH_lOP_HOC