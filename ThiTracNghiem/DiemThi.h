#ifndef DANH_SACH_DIEM_THI
#define DANH_SACH_DIEM_THI

#pragma once
#include <iostream>
#include <iomanip>

struct DiemThi
{
    char maMonHoc[16];
    float diemThi;
};

struct nodeDiemThi
{
    DiemThi info;
    nodeDiemThi *next;
};

typedef nodeDiemThi *PtrDT;

void KhoiTao_PtrDT(PtrDT &First)
{
    First = NULL;
}

bool is_Empty_DT(PtrDT &first);
bool is_Full_DT(PtrDT &first);
bool is_Existed_MaMon(PtrDT &first, char * maMon);

void insert_First_DT(PtrDT &first, DiemThi x);
void insert_Last_DT(PtrDT &first, DiemThi x);
void insert_Order_DT(PtrDT &first, DiemThi x); // them vao sap xep theo ma mon
void insert_After_DT(PtrDT &p, DiemThi x);

void delete_First_DT(PtrDT &first);
void delete_Last_DT(PtrDT &first);
void delete_After_DT(PtrDT &first, PtrDT p);
void delete_List_DT(PtrDT &first);
void delete_Info_DT(PtrDT &first, DiemThi x);

bool search_Info_DT(PtrDT &first, char * maMon);
void set_Info_DT(PtrDT &first, DiemThi x);
PtrDT pos_MonHoc_DT(PtrDT &first, char *maMon);
int counting_Score_DT(PtrDT &first, float x, int types);
int compare_Float_Number(float num1, float num2, int precision = 2);

void print_List_DT(PtrDT first);

#endif // DANH_SACH_DIEM_THI
