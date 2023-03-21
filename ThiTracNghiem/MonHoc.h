#ifndef DANH_SACH_MON_HOC
#define DANH_SACH_MON_HOC

#pragma once

#define MaxOfSubjects 300

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

/*

(some functions here)

*/

#endif
