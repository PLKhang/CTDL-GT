#include "DiemThi.h"
#include "MonHoc.h"

bool is_Empty_DT(PtrDT &first)
{
    if (first == NULL)
        return 1;
    return 0;
}
bool is_Full_DT(PtrDT &first, ListMH dsmh)
{
    if (is_Empty_DT(first))
        return 0;
    int count = 0;
    PtrDT p = new nodeDiemThi;
    for (p = first; p->next != NULL; p = p->next)
        count++;
    if (count < dsmh.n) // dsmh == tên khai báo biến của danh sách môn học(khai báo trong main.cpp)
        return 0;
    return 1;
}
bool is_Existed_MaMon(PtrDT &first, char *maMon)
{
    if (is_Empty_DT(first))
        return 0;
    PtrDT p = new nodeDiemThi;
    for (p = first; p->next != NULL; p = p->next)
        if (p->info.maMonHoc == maMon)
            return 1;
    return 0;
}

void insert_First_DT(PtrDT &first, DiemThi x)
{
    if (is_Full_DT(first))
        return;
    PtrDT p = new nodeDiemThi;
    p->info = x;
    p->next = first;
    first = p;
}
void insert_Last_DT(PtrDT &first, DiemThi x)
{
    if (is_Full_DT(first))
        return;
    PtrDT p = new nodeDiemThi;
    p->info = x;
    p->next = NULL;
    PtrDT q = first;
    while (q->next != NULL)
        q = q->next;
    q->next = p;
}
void insert_After_DT(PtrDT p, DiemThi x)
{
    // if(is_Full_DT(first)) // how to check it? :v
    //     return;
    if (p == NULL || p->next == NULL)
        return;
    PtrDT q = new nodeDiemThi;
    q->info = x;
    q->next = p->next;
    p->next = q;
}

void delete_First_DT(PtrDT &first)
{
    if (is_Empty_DT(first))
        return;
    PtrDT p = new nodeDiemThi;
    p = first;
    first = p->next;
    delete p;
}
void delete_Last_DT(PtrDT &first);
void delete_After_DT(PtrDT &first, PtrDT p)
{
    if (is_Empty_DT(first))
        return;
    if (p == NULL || p->next == NULL)
        return;
    PtrDT q = p->next;
    p->next = q->next;
    delete q;
}
void delete_List_DT(PtrDT &first)
{
    while (first != NULL)
        delete_First_DT(first);
}
void delete_Info_DT(PtrDT &first, char *maMon);

bool search_info_DT(PtrDT first, char *maMon)
{
    if (is_Empty_DT(first))
        return 0;
    PtrDT p = new nodeDiemThi;
    for (p = first; p->next != NULL; p = p->next)
        if (p->info.maMonHoc == maMon)
            return 1;
    return 0;
}
void set_Info_DT(PtrDT &p, DiemThi x)
{
    p->info = x;
}
PtrDT pos_MonHoc_DT(PtrDT first, char *maMon)
{
    if (is_Empty_DT(first))
        return NULL;
    PtrDT p = first;
    if (p->info.maMonHoc == maMon)
        return p;

    while (p->next->info.maMonHoc != maMon && p->next != NULL)
    {
        p = p->next;
    }
    return p->next;
}
int counting_Score_DT(PtrDT first, float x, int types)
{
    if (is_Empty_DT(first))
        return 0;

    int count = 0;
    PtrDT p = new nodeDiemThi;

    if (types > 0)
        for (p = first; p->next != NULL; p = p->next)
            if (p->info.diemThi > x)
                count++;
    if (types < 0)
        for (p = first; p->next != NULL; p = p->next)
            if (p->info.diemThi < x)
                count++;
    if (types == 0)
        for (p = first; p->next != NULL; p = p->next)
            if (p->info.diemThi == x)
                count++;
    return count;
}

int compare_Float_Number(float num1, float num2, int precision = 2)
{
    float threshold = pow(0.1, precision); // calculate threshold based on precision
    float diff = num1 - num2;
    if (abs(diff) < threshold)
    {
        return 0; // num1 = num2
    }
    else if (diff > 0)
    {
        return 1; // num1 > num2
    }
    else
    {
        return -1; // num1 < num2
    }
}

void print_List_DT(PtrDT first)
{
    if (is_Empty_DT(first))
        return;
    PtrDT p = new nodeDiemThi;
    for (p = first; p->next != NULL; p = p->next)
    {
        std::cout << p->info.maMonHoc << '\t';
        std::cout << p->info.diemThi << '\n';
    }
}