#ifndef DOC_GHI_FILE_H
#define DOC_GHI_FILE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <fstream>

#include "struct.h"

using namespace std;
/* 
return:
0:  khong mo duoc file dslh
1:  ok
-1: doc file dslh loi~
-2: khong doc duoc file cho dslk SinhVien
-3: doc file cho dslk SinhVien bi loi~
-4: khong doc duoc file cho dslk DiemThi
-5: doc file cho dslk DiemThi bi loi~   
 */
int doc_danhSachLopHoc(ListLH &dslh);
int doc_danhSachSinhVien(PtrSV &dssv, string maLH); //--> doc_danhSachLopHoc
int doc_danhSachDiemThi(PtrDT &dsdt, string maLH, string mssv); // --> doc_danhSachSinhVien
int doc_danhSachMonHoc(ListMH &dsmh);
int doc_danhSachCauHoi(STreeCH &dsch);
int doc_CauHoiDaThi(string maLH, string mssv);
int kiemTraDangNhap(string user, string password);

 // <-- dssv, dsdt, dstk
int ghi_danhSachLopHoc(ListLH dslh);
int ghi_danhSachSinhVien(PtrSV dssv);
int ghi_danhSachDiemThi(PtrDT dsdt);
int ghi_danhSachTaiKhoan(ListLH dslh);
int ghi_danhSachMonHoc(ListMH dsmh);
int ghi_danhSachCauHoi(STreeCH dsch);

#endif // DOC_GHI_FILE_H