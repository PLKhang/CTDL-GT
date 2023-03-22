#include "struct.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <string>
#include <vector>

//---------------------------MonHoc--------------------------//

//---------------------------CauHoi--------------------------//

//---------------------------DiemThi--------------------------//
bool is_Empty_DT(PtrDT first)
{
    if (first == NULL)
        return 1;
    return 0;
}
bool is_Full_DT(PtrDT first)
{
    if (is_Empty_DT(first))
        return 0;
    int count = 0;
    PtrDT p;
    for (p = first; p != NULL; p = p->next)
        if (p->info.diemThi < 0)
            return 0;
    return 1;
}
bool is_Existed_DT(PtrDT first, char *maMon)
{
    if (is_Empty_DT(first))
        return 0;
    PtrDT p;
    for (p = first; p != NULL; p = p->next)
        if (p->info.maMonHoc == maMon)
            if (p->info.diemThi >= 0)
                return 1;
    return 0;
}

bool is_Existed_MaMH_DT(PtrDT first, char *maMon)
{
    if (is_Empty_DT(first))
        return 0;
    PtrDT p;
    for (p = first; p != NULL; p = p->next)
        if (p->info.maMonHoc == maMon)
            return 1;
    return 0;
}
bool insert_First_DT(PtrDT &first, DiemThi x)
{
    PtrDT p = new nodeDiemThi;
    p->info = x;
    p->next = first;
    first = p;
    return 1;
}

bool insert_After_DT(PtrDT p, DiemThi x)
{
    if (p == NULL)
        return 0;
    PtrDT q = new nodeDiemThi;
    q->info = x;
    q->next = p->next;
    p->next = q;
    return 1;
}

bool insert_Order_DT(PtrDT &first, DiemThi x)
{
    PtrDT u, v;
    for (u = first; u->info.maMonHoc > x.maMonHoc; v = u, u = u->next)
        ;
    if (u == first)
        insert_First_DT(first, x);
    else
        insert_After_DT(v, x);
    return 1;
}

bool delete_First_DT(PtrDT &first)
{
    if (is_Empty_DT(first))
        return 0;
    PtrDT p = first;
    first = p->next;
    delete p;
    return 1;
}

bool delete_After_DT(PtrDT p)
{
    if (p == NULL || p->next == NULL)
        return 0;
    PtrDT q = p->next;
    p->next = q->next;
    delete q;
    return 1;
}
bool delete_Pos_DT(PtrDT &first, char *maMon)
{
    if (is_Empty_DT(first) || !is_Existed_MaMH_DT(first, maMon))
        return 0;
    PtrDT pos = pos_MaMH_DT(first, maMon);
    pos->info.diemThi = -1;
    return 1;
}

bool delete_List_DT(PtrDT &first)
{
    while (first != NULL)
        if (!delete_First_DT(first))
            return 0;
    return 1;
}

bool set_DiemThi_DT(PtrDT &p, float x)
{
    if (p == NULL)
        return 0;
    p->info.diemThi = x;
    return 1;
}
PtrDT pos_MaMH_DT(PtrDT first, char *maMon)
{
    if (is_Empty_DT(first))
        return NULL;
    PtrDT p = NULL;

    for (p = first; p->info.maMonHoc != maMon && p != NULL; p = p->next)
        ;
    return p;
}

//---------------------------SinhVien--------------------------//

//---------------------------LopHoc--------------------------//
