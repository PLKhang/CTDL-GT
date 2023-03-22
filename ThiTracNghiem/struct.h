#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>
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
typedef CauHoi*ptrCauHoi;
struct nodeCauHoi
{
    CauHoi info; //key = info.ID;
    nodeCauHoi *left=NULL;
    nodeCauHoi *right=NULL;
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
    nodeSinhVien* next;
};

typedef nodeSinhVien* PtrSV;
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
    LopHoc* nodes[MaxOfClasses];
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

//-------------------SinhVien------------------//

void KhoiTao_PtrSV(PtrSV& First)
{
    First = NULL;
}

/*

(some functions here)

*/

//-------------------LopHoc------------------//

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

#endif //STRUCT_H