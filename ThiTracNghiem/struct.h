#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>

#define MaxOfSubjects 300
#define MaxOfClasses 500

//------------------------------------------------//
struct MonHoc
{
    char maMonHoc[16];
    char tenMonHoc[51];
};

struct DanhSachMonHoc
{
    int n = 0;
    MonHoc nodes[MaxOfSubjects];
};

typedef DanhSachMonHoc ListMH;
//------------------------------------------------//
struct CauHoi
{
    int ID;
    char maMonHoc[16];
    unsigned short answer;
    char ans1[100], ans2[100], ans3[100], ans4[100], question[200];
};
typedef CauHoi *ptrCauHoi;
struct nodeCauHoi
{
    CauHoi info; // key = info.ID;
    nodeCauHoi *left = NULL;
    nodeCauHoi *right = NULL;
};

typedef nodeCauHoi *STreeCH;
//------------------------------------------------//
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
//------------------------------------------------//
struct SinhVien
{
    char MSSV[11];
    char ho[51];
    char ten[16];
    char password[21];
    bool phai; // male: 0     female: 1
    PtrDT danhSachDiemThi;
};

struct nodeSinhVien
{
    SinhVien info;
    nodeSinhVien *next;
};

typedef nodeSinhVien *PtrSV;
//------------------------------------------------//
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
    LopHoc *nodes[MaxOfClasses];
};

typedef DanhSachLopHoc ListLH;
//------------------------------------------------//

//-------------------MonHoc------------------//
/*

(some functions here)

*/

//-------------------CauHoi------------------//
int CreateID(int Number[], int &i);
void PreTraversal(CauHoi save[], STreeCH root, int &i);
void InsertQuestion(STreeCH &root, STreeCH question);
STreeCH balance(STreeCH root);
CauHoi *GetQuestion(STreeCH &root, int number_question);
// void Read(STreeCH &root);

//-------------------DiemThi------------------//

void KhoiTao_PtrDT(PtrDT First)
{
    First = NULL;
}

// kiem tra dsdt co node nao hay chua
bool is_Empty_DT(PtrDT first);
// kiem tra neu tat ca cac mon hoc deu co diem(sai neu ton tai diem < 0)
bool is_Full_DT(PtrDT first);
// kiem tra neu MonHoc da co diem (diem >= 0)
bool is_Existed_DT(PtrDT first, char *maMon);
// kiem tra MonHoc co trong ds hay chua(truong hop: THEM MON HOC)
bool is_Existed_MaMH_DT(PtrDT first, char *maMon);
bool insert_First_DT(PtrDT &first, DiemThi x);
bool insert_After_DT(PtrDT p, DiemThi x);
// them vao sap xep theo ma mon (truong hop: THEM MON HOC)
bool insert_Order_DT(PtrDT &first, DiemThi x);

bool delete_DiemThi_First_DT(PtrDT &first);
bool delete_DiemThi_After_DT(PtrDT p);
bool delete_Pos_DT(PtrDT &first, char *maMon);
// Xoa danh sach diem thi cua sinh vien
bool delete_List_DT(PtrDT &first);
// void delete_Info_DT(PtrDT &first, DiemThi x);

// Dung ham pos_MaMH_DT() truyen vao de lay vi tri sua diemThi
bool set_DiemThi_DT(PtrDT &p, float x);
// Tra ve vi tri node chua MaMH
PtrDT pos_MaMH_DT(PtrDT first, char *maMon);

//-------------------SinhVien------------------//

void KhoiTao_PtrSV(PtrSV &First)
{
    First = NULL;
}

bool is_Empty_SV(PtrSV first);

//-------------------LopHoc------------------//

bool is_Empty_LH(ListLH &ListLH);
bool is_Full_LH(ListLH &ListLH);
bool is_Existed_MaLop(ListLH &ListLH, char maLop[]);

// void FunctionLop(ListLH &ListLH);// HAM DO HOA

void ThemLop(ListLH &ListLH, LopHoc);

// void NhapLop(ListLH &ListLH, LopHoc);

void XoaLop(ListLH &ListLH, int &page);
// void NhapLopXoa(ListLH &ListLH,int &page);

void SuaLop(ListLH &ListLH, int state, int page);
void ChinhLop(ListLH &ListLH, int &page);
// void NhapLopChinh(ListLH &ListLH , int &page);

void InDSLH(ListLH ListLH);

#endif // STRUCT_H