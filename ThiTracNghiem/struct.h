#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
#define MaxOfSubjects 300
#define MaxOfClasses 500
//------------------------------------------------//
template <typename T>
struct node
{
    T info;
    node<T> *next;
};
template <typename T>
class Stack
{
private:
    int size;
    node<T> *top;

public:
    Stack()
    {
        size = 0;
        top = NULL;
    }
    void Push(T data)
    {
        node<T> *temp = new node<T>;
        temp->info = data;
        temp->next = top;
        top = temp;
        size++;
    }
    T Pop()
    {
        if (!this->Empty())
        {
            node<T> *temp = top;
            T data = top->info;
            top = top->next;
            delete temp;
            size--;
            return data;
        }
    }
    bool Empty()
    {
        return (top == NULL);
    }
    int GetSize() { return size; }
    void Destroy()
    {
        if (top == NULL)
            return;
        node<T> *temp, *run = top;
        while (run != NULL)
        {
            temp = run;
            run = run->next;
            delete temp;
        }
        top = NULL;
        size = 0;
    }
};
template <typename T>
class Queue
{
private:
    int number;
    node<T> *front;
    node<T> *rear;

public:
    Queue()
    {
        number = 0;
        front = NULL;
        rear = NULL;
    }
    void Push(T data)
    {
        node<T> *temp = new node<T>;
        temp->info = data;
        temp->next=NULL;
        if (front == NULL)
            front = temp;
        else
            rear->next = temp;
        rear = temp;
        number++;
    }
    T pop()
    {
        if (!this->empty())
        {
            node<T> *run = front;
            T data = front->info;
            if (front == rear && front != NULL)
                front = rear = NULL;
            else
                front = front->next;
            delete run;
            number--;
            return data;
        }
    }
    bool empty()
    {
        if (front == NULL)
            return true;
        else
            return false;
    }
    int GetNumber() { return number; }
    void Destroy()
    {
        if(front==NULL)return;
        node<T>*temp,*run=front;
        while(run!=NULL)
        {
            temp=run;
            run=run->next;
            delete temp;
        }
        rear=front=NULL;
        number=0;
    }
};
template<typename T>struct Array
{
    private:
        T *ptr;
        int number;
        int index_last;
    public:
        Array()
        {
            ptr=NULL;
            number=0;
            index_last=-1;
        }
        Array(int number_in)
        {
            ptr=new T[number_in];
            number=number_in;
            index_last=-1;
        }
        int GetIndexLast(){return index_last;}
        T& operator[](int i)
        {
            return ptr[i];
        }

        void push(T New)
        {
            if (index_last == number - 1) {
                T* temp;
                temp = new T[number + 10]; // tạo mảng mới 
                for (int i = 0; i < number; i++) {
                    temp[i] = ptr[i];
                }
                temp[index_last + 1] = New;
                delete[] ptr; // xóa mảng cũ
                ptr = temp; // gán con trỏ vào mảng mới
                index_last++;
                number+=10;
            }
            else {
                ptr[++index_last] = New;
            }
        }
        void clear()
        {
            index_last=-1;
        }
        void erase(int i)
        {
            if (i < 0 || i > index_last)
               return;
            if (i == index_last) {
                index_last--;
                return;
            }
            for (int k = i; k < index_last; k++) {
                ptr[k] = ptr[k + 1];
            }
            index_last--;
        }

        void destroy()
        {
            delete []ptr;
        }
};
//------------------------------------------------//
struct MonHoc
{
    char maMonHoc[16];
    char tenMonHoc[51];
    bool is_used = false;
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
    char answer;
    char ans1[101];
    char ans2[101];
    char ans3[101];
    char ans4[101];
    char question[201];
};
typedef CauHoi *ptrCauHoi;
struct nodeCauHoi
{
    CauHoi info; // key = info.ID;
    bool is_used = false;
    nodeCauHoi *left = NULL;
    nodeCauHoi *right = NULL;
};
typedef nodeCauHoi *STreeCH;
// tao bo id
struct ID
{
    int id;
    ID *left = NULL;
    ID *right = NULL;
};
typedef ID *createID;
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
    char password[12];
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
    int nienKhoa;
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
bool is_Existed_MaMH_MH(ListMH dsmh, string maMH);
bool is_existed_tenMH(ListMH dsmh, string tenMH);
// 0: dsmh FULL // 1: OK // -1: Trung` maMH
int insert_MH(ListMH &dsmh, MonHoc info);
// 0: dsmh EMPTY // 1: OK // -1: pos >= n || pos < 0
//  0 <=  pos  < dsmh.n
int delete_MH(ListMH &dsmh, unsigned pos);

// Tra ve vi tri MonHoc.maMonHoc = maMH
int pos_MaMH_MH(ListMH dsmh, string maMH);

string FindName(ListMH dsmh, char maMH[]);
// ****************Cau hoi**********************************//
//so luong nut
int NumberOfNode(ID *root);
//chen nut vao cay
void InsertID(ID *&tree, int data);
//tim vi tri de in
int InsertToBalance(ID *&root, int min, int max,int&temp, ofstream &file);
//giai phong vung nho
void DeleteAllID(ID*root);
// tao file ID
void TaoFileID();
// doc lay id
int ReadID(int&ExistID,int option=0);

// Phuc hoi lai ID
void RestoreID();
// tao node moi
STreeCH newnode();
void store(STreeCH,vector<STreeCH>&);
STreeCH Convert(Array<STreeCH>&,int max,int min);
STreeCH Balance(STreeCH root);
STreeCH BinarySearch(STreeCH root,int ID);
STreeCH OriginRoot(STreeCH);
// in cau hoi
int Insert(STreeCH &root, STreeCH &question);
int InsertNewQuestion(STreeCH &root, STreeCH &question);
void SubDelete(STreeCH&root);
int Delete(STreeCH&root,int ID);
// xoa cau hoi
int DeleteQuestion(STreeCH &root, STreeCH &Quetion);
int SoNode(STreeCH root);
void DeleteRoot(STreeCH &root);
// duyet tim cau hoi theo ma mon
void InTraversal(Array<STreeCH>&AllQuestions, STreeCH root, char maMH[]);
void PreTraversal(STreeCH *AllQuestions, STreeCH root, char maMH[], int &count);
// random cau hoi va tra ve con tro streech
STreeCH *GetQuestion(STreeCH &root, char maMH[], int number_question, int tong_so_cau_hoi);
// dem so cau hoi cua mon do
int DemSoCauHoi(STreeCH root, char maMH[]);
// tim cau hoi theo ID
//sap xep theo id
void Sort(Array<STreeCH>&Arr,int first,int last);
//-------------------DiemThi------------------//

void KhoiTao_PtrDT(PtrDT &First);
PtrDT create_Node_DT(DiemThi info);

// kiem tra dsdt co node nao hay chua
bool is_Empty_DT(PtrDT first);
// kiem tra MonHoc co trong ds hay chua(truong hop: THEM MON HOC)
bool is_Existed_MaMH_DT(PtrDT first, string maMon);
bool insert_First_DT(PtrDT &first, DiemThi x);
bool insert_After_DT(PtrDT p, DiemThi x);
bool insert_Order_DT(PtrDT &first, DiemThi x);

bool delete_First_DT(PtrDT &first);
bool delete_After_DT(PtrDT p);
// Xoa danh sach diem thi cua sinh vien
bool delete_List_DT(PtrDT &first);
//-------------------SinhVien------------------//

void KhoiTao_PtrSV(PtrSV &First);
// kiem tra lop nay da co sinh vien nao hay chua
bool is_Empty_SV(PtrSV first);
// kiem tra neu mssv da ton tai(case : THEM SINH VIEN)
bool is_Existed_MSSV_SV(ListLH dslh, string mssv);

void insert_First_SV(PtrSV &first, SinhVien sv);
bool insert_After_SV(PtrSV p, SinhVien sv);
bool insert_Order_SV(PtrSV &first, SinhVien sv);

// + xoa dsDT trong cac node
bool delete_First_SV(PtrSV &first);
bool delete_After_SV(PtrSV p);
bool delete_List_SV(PtrSV &first);

// tra ve dia chi nam ngay truoc node co MSSV == mssv(kiem tra vi tri = first rieng)
PtrSV pos_MSSV_SV(PtrSV first, string mssv);
void changeInfoByPtrArray_SV(PtrSV *nodePtrArray, int index, SinhVien newData);

//-------------------LopHoc------------------//

// kiem tra chuoi rong
bool is_Empty_LH(ListLH ListLH);
// kiem tra chuoi day
bool is_Full_LH(ListLH ListLH);
// kiem tra trung maLop
bool is_Existed_MaLop(ListLH ListLH, const char *maLop);
// chuong trinh thuc thi
int ThemLop(ListLH &ListLH, LopHoc lh); // ham them lop
// ham tim gia tri vi tri ma lop de gui vao cho ham xoa
int pos_MaLH_LH(ListLH ListLH, int i, char maLop[]);
// ket thuc chuong trinh, giai phong vung nho
void Delete_DSLH(ListLH &dslh);
// ham xoa lop va dong thoi xoa dssv thuoc lop do
int XoaLop(ListLH &ListLH, int pos);
// cap nhat thong tin dua vao ham strcpy
void SuaLop(ListLH &ListLH, int i, LopHoc lh);

#endif // STRUCT_H
