#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
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
    float diemThi = -1;
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
int CreateID(int Number[],int &i);
STreeCH newnode(CauHoi CH);
int InsertQuestion(STreeCH &root,STreeCH question);
void Delete(STreeCH&root);
int DeleteQuestion(STreeCH&root,int ID);
int Modify(STreeCH root,CauHoi question);
void Store(STreeCH root,vector<STreeCH>&nodes);
STreeCH Convert(vector<STreeCH>&nodes,int max,int min);
STreeCH Balance(STreeCH root);
void PreTraversal(CauHoi save[],STreeCH root,int &i);
int InsertQuestion(STreeCH &root,STreeCH question);
CauHoi* GetQuestion(STreeCH &root,int number_question);
//void Read(STreeCH &root);

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
// kiem tra lop nay da co sinh vien nao hay chua
bool is_Empty_SV(PtrSV first);
// kiem tra neu mssv da ton tai(case : THEM SINH VIEN)
bool is_Existed_MSSV_SV(PtrSV first, const char * mssv);

void insert_First_SV(PtrSV &first, SinhVien sv);
bool insert_After_SV(PtrSV p, SinhVien sv);
bool insert_Order_SV(PtrSV first, SinhVien sv);

//+ xoa dsDT trong cac node
bool delete_First_SV(PtrSV &first);
bool delete_After_SV(PtrSV p);
void delete_List_SV(PtrSV &first);
// tao mot sinh vien moi(case: THEM SINH VIEN)
// da kiem tra khong trung MSSV
SinhVien create_New_SV(const char * mssv, ListMH dsmh);

bool set_MSSV_SV(PtrSV p, const char * mssv);
bool set_ho_SV(PtrSV p, const char * ho);
bool set_ten_SV(PtrSV p, const char * ten);
bool set_phai_SV(PtrSV p, bool gioiTinh);
// tao dsDT cho sv moi va cho tat ca diem thi = -1(chua thi)
PtrDT set_Blank_dsDT_SV();

//tra ve dia chi nam ngay truoc node co MSSV == mssv(kiem tra vi tri = first rieng)
PtrSV pos_MSSV_SV(PtrSV first, const char * mssv);

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