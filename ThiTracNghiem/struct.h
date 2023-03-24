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
template<typename T>
struct node{
    T info;
    node<T>*next;
};
template<typename T> class Queue{
    private:
        int number=0;
        node<T>* front=NULL;
        node<T>* rear=NULL;
    public:
        void Push(T data)
        {
            node<T>* temp=new node<T>;
            temp->info=data;
            if(front==NULL) front=temp;
            else rear->next=temp;
            rear=temp;
            number++;
        }
        T pop(){
            if(!this->empty())
            {
            node<T> *run=front;
            T data=front->info;
            if(front==rear&&front!=NULL)front=rear=NULL;
            else front=front->next;
            delete run;
            number--;
            return data;
            }
        }
        bool empty(){
            if(front==NULL)return true;
            else return false;
        }
        int GetNumber()return number;
};
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
    int ID = 0;
    char maMonHoc[16];
    unsigned short answer;
    char ans1[100];
    char ans2[100];
    char ans3[100];
    char ans4[100];
    char question[200];
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
    PtrDT danhSachDiemThi = NULL;
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
    PtrSV danhSachSinhVien = NULL;
};

struct DanhSachLopHoc // MANG CON TRO
{
    int n = 0;
    LopHoc *lh[MaxOfClasses];
};

typedef DanhSachLopHoc ListLH;
//------------------------------------------------//

//-------------------MonHoc------------------//
bool is_Empty_MH(ListMH dsmh);
bool is_Full_MH(ListMH dsmh);
bool is_Existed_MaMH_MH(ListMH dsmh, const char *maMH);

// 0: dsmh FULL // 1: OK // -1: Trung` maMH
int insert_MH(ListMH &dsmh, MonHoc info);
// 0: dsmh EMPTY // 1: OK // -1: pos >= n || pos < 0
//  0 <=  pos  < dsmh.n
int delete_MH(ListMH &dsmh, unsigned pos);

// Dung ham nay khi HIEU CHINH mon hoc
// Vi tri duoc truyen vao tu XuLyChuongTrinh
void set_Info_MH(ListMH &dsmh, unsigned pos, MonHoc new_MH);

// Tra ve vi tri MonHoc.maMonHoc = maMH
int pos_MaMH_MH(ListMH dsmh, const char *maMH);

//-------------------CauHoi------------------//
int CreateID(int Number[], int &i);
STreeCH newnode(CauHoi CH);
int InsertQuestion(STreeCH &root, STreeCH question);
void Delete(STreeCH &root);
int DeleteQuestion(STreeCH &root, int ID);
int Modify(STreeCH root, CauHoi question);
void Store(STreeCH root, vector<STreeCH> &nodes);
STreeCH Convert(vector<STreeCH> &nodes, int max, int min);
STreeCH Balance(STreeCH root);
void PreTraversal(CauHoi save[], STreeCH root, int &i);
int InsertQuestion(STreeCH &root, STreeCH question);
CauHoi *GetQuestion(STreeCH &root, int number_question);
// void Read(STreeCH &root);

//-------------------DiemThi------------------//

void KhoiTao_PtrDT(PtrDT &First);

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

void KhoiTao_PtrSV(PtrSV &First);
// kiem tra lop nay da co sinh vien nao hay chua
bool is_Empty_SV(PtrSV first);
// kiem tra neu mssv da ton tai(case : THEM SINH VIEN)
bool is_Existed_MSSV_SV(PtrSV first, const char *mssv);

void insert_First_SV(PtrSV &first, SinhVien sv);
bool insert_After_SV(PtrSV p, SinhVien sv);
bool insert_Order_SV(PtrSV first, SinhVien sv);

//+ xoa dsDT trong cac node
bool delete_First_SV(PtrSV &first);
bool delete_After_SV(PtrSV p);
void delete_List_SV(PtrSV &first);
// tao mot sinh vien moi(case: THEM SINH VIEN)
// da kiem tra khong trung MSSV
SinhVien create_New_SV(const char *mssv, ListMH dsmh);

bool set_MSSV_SV(PtrSV p, const char *mssv);
bool set_ho_SV(PtrSV p, const char *ho);
bool set_ten_SV(PtrSV p, const char *ten);
bool set_phai_SV(PtrSV p, bool gioiTinh);
// tao dsDT cho sv moi va cho tat ca diem thi = -1(chua thi)
PtrDT set_Blank_dsDT_SV();

// tra ve dia chi nam ngay truoc node co MSSV == mssv(kiem tra vi tri = first rieng)
PtrSV pos_MSSV_SV(PtrSV first, const char *mssv);

//-------------------LopHoc------------------//

// kiem tra chuoi rong
bool is_Empty_LH(ListLH ListLH);
// kiem tra chuoi day
bool is_Full_LH(ListLH ListLH);
// kiem tra trung maLop
bool is_Existed_MaLop(ListLH ListLH, char maLop[]);
// chuong trinh thuc thi
int ThemLop(ListLH &ListLH, LopHoc lh); // ham them lop
// ham tim gia tri vi tri ma lop de gui vao cho ham xoa
int pos_MaLH_LH(ListLH ListLH, int i, char maLop[]);
// ham xoa lop va dong thoi xoa dssv thuoc lop do
int XoaLop(ListLH &ListLH, int i, LopHoc lh);
// cap nhat thong tin dua vao ham strcpy
void SuaLop(ListLH &ListLH, int i, LopHoc lh);

#endif // STRUCT_H