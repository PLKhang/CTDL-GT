#include "docGhiFile.h"

int doc_danhSachLopHoc(ListLH &dslh)
{   
    //Mo file
    ifstream file;
    file.open("Data/DanhSachLopHoc.txt", ios::in);
    if (!file)
        return 0;

    // cap du lieu
    string line;
    LopHoc data;

    // cap cac bien de chay code
    int pos = 0;
    int field_Num = 1;
    string field;

    // vong lap de doc cac dong trong file
    while(getline(file, line)) 
    {
        pos = 0;
        field_Num = 1;
        while ((pos = line.find("|")) != string::npos) // dk: toi khi pos tim thay dau | va chuoi khac gia tri cuoi
        {
            field = line.substr(0, pos); // cat chuoi dai thanh chuoi con tu dau den vi tri pos -> luu vao field
            line.erase(0, pos + 1); // xoa chuoi trong line tu o den pos + 1
            switch (field_Num)
            {
            case 1:
                strcpy(data.maLop, field.c_str()); // copy du lieu chua ma lop vao field
                break;
            case 2:
                strcpy(data.tenLop, field.c_str());
                break;
            case 3:
                strcpy(data.nienKhoa, field.c_str());
                break;
            default:
                return -1;
            }
            field_Num++;
        }
    }
    doc_danhSachSinhVien(data.danhSachSinhVien, data.maLop);

    // Dong file
    file.close(); 
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
int doc_danhSachMonHoc(ListMH &dsmh)
{
    //Mo file
    ifstream file;
    file.open("Data/DanhSachMonHoc.txt", ios::in);
    if (!file)
        return 0;

    // cap du lieu
    string line;
    MonHoc data;

    // cap cac bien de chay code
    int pos = 0;
    int field_Num = 1;
    string field;

    // vong lap de doc cac dong trong file
    while(getline(file, line)) 
    {
        pos = 0;
        field_Num = 1;
        while ((pos = line.find("|")) != string::npos) // dk: toi khi pos tim thay dau | va chuoi khac gia tri cuoi
        {
            field = line.substr(0, pos); // cat chuoi dai thanh chuoi con tu dau den vi tri pos -> luu vao field
            line.erase(0, pos + 1); // xoa chuoi trong line tu o den pos + 1
            switch (field_Num)
            {
            case 1:
                strcpy(data.maMonHoc, field.c_str()); // copy du lieu chua ma mon vao field
                break;
            case 2:
                strcpy(data.tenMonHoc, field.c_str());
                break;
            default:
                return -1;
            }
            field_Num++;
        }
    }
    // Dong file
    file.close(); 
}
int doc_danhSachCauHoi(STreeCH &dsch);

int ghi_danhSachLopHoc(ListLH dslh)
{
    //Mo file
    ofstream file;
    file.open("Data/DanhSachLopHoc.txt", ios::out);
    if (!file)
        return 0;

    file << dslh.n << endl;
    for(int i = 0; i < dslh.n; i++)
    {
        // cap du lieu
        LopHoc data;
        file << data.maLop << "|" ;
		file << data.tenLop << "|" ;
        file << data.nienKhoa << "|";
        // Ghi dữ liệu vào file
        // cin >> data.maLop;
        // cin.ignore();
        // getline(cin, data.tenLop);
        // cin >> data.nienKhoa;
        //data.danhSachSinhVien = ghi_danhSachSinhVien();
        //file << data.maLop << "|" << data.tenLop << "|" << data.nienKhoa << "|"  << endl;
        //ghi_danhSachSinhVien(data.danhSachSinhVien, data.maLop);
        file << endl;
    }

    // Đóng file
    file.close();
    return 1;
}
int ghi_danhSachSinhVien(PtrSV dssv);
int ghi_danhSachDiemThi(PtrDT dsdt);
int ghi_danhSachMonHoc(ListMH dsmh)
{
    //Mo file
    ofstream file;
    file.open("Data/DanhSachLopHoc.txt", ios::out);
    if (!file)
        return 0;

    file << dsmh.n << endl;
    
    for(int i = 0; i < dsmh.n; i++)
    {
        // cap du lieu
        MonHoc data;
        file << data.maMonHoc << "|" ;
		file << data.tenMonHoc << "|" << endl ;
    }
    // Đong file
    file.close();
    return 1;
}
int ghi_danhSachCauHoi(STreeCH dsch);