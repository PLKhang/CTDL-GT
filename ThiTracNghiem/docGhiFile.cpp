#include "docGhiFile.h"

int doc_danhSachLopHoc(ListLH &dslh)
{
    
}
int doc_danhSachSinhVien(PtrSV &dssv, string maLH)
{
    KhoiTao_PtrSV(dssv);
    string fileLocation = "Data/DanhSachSinhVien/" + maLH + ".txt";

    ifstream file(fileLocation);
    if (!file)
        return 0;

    string line;
    SinhVien info;

    int pos = 0;
    int field_Num = 1;
    string field;

    while (getline(file, line))
    {
        pos = 0;
        field_Num = 1;
        while ((pos = line.find("|")) != string::npos)
        {
            field = line.substr(0, pos);
            line.erase(0, pos + 1);
            switch (field_Num)
            {
            case 1:
                strcpy(info.MSSV, field.c_str());
                break;
            case 2:
                strcpy(info.password, field.c_str());
                break;
            case 3:
                strcpy(info.ho, field.c_str());
                break;
            case 4:
                strcpy(info.ten, field.c_str());
                break;
            case 5:
                if (atoi(field.c_str()) == 1)
                    info.phai = true;
                else
                    info.phai = false;
                break;
            default:
                return -1;
            }
            field_Num++;
        }
        doc_danhSachDiemThi(info.danhSachDiemThi, maLH, info.MSSV);
        insert_Order_SV(dssv, info);
    }
    return 1;
}
int doc_danhSachDiemThi(PtrDT &dsdt, string maLH, string mssv)
{
    KhoiTao_PtrDT(dsdt);
    string fileLocation = "Data/DanhSachSinhVien/DanhSachDiemThi/" + maLH + '/' + mssv + ".txt";

    ifstream file(fileLocation);
    if (!file)
        return 0;

    string line;
    DiemThi info;

    int pos = 0;
    int field_Num = 1;
    string field;

    while (getline(file, line))
    {
        pos = 0;
        field_Num = 1;
        while ((pos = line.find("|")) != string::npos)
        {
            field = line.substr(0, pos);
            line.erase(0, pos + 1);
            switch (field_Num)
            {
            case 1:
                strcpy(info.maMonHoc, field.c_str());
                break;
            case 2:
                info.diemThi = atof(field.c_str());
                break;
            default:
                return -1;
            }
            field_Num++;
        }
        insert_Order_DT(dsdt, info);
    }
    return 1;
}
int doc_danhSachMonHoc(ListMH &dsmh);
int doc_danhSachCauHoi(STreeCH &dsch);

int ghi_danhSachLopHoc(ListLH dslh);
int ghi_danhSachSinhVien(PtrSV dssv);
int ghi_danhSachDiemThi(PtrDT dsdt);
int ghi_danhSachMonHoc(ListMH dsmh);
int ghi_danhSachCauHoi(STreeCH dsch);