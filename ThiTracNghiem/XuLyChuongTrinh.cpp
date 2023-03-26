#include "XuLyChuongTrinh.h"
#include "struct.h"

int KiemTraTK(string Name, string Password)
{
    if (Name == "GV" && Password == "GV")
        return 2;
    fstream DocFileTK("Data/DanhSachTaiKhoan.txt");
    if (!DocFileTK.is_open())
        return 0;
    string line;
    int pos = 0;
    while (getline(DocFileTK, line))
    {
        pos = line.find("|");
        if (Name == line.substr(0, pos))
        {
            line.erase(0, pos + 1);
            pos = line.find("|");
            if (Password == line.substr(0, pos))
            {
                return 1;
            }
        }
    }
    return 0;
}
int DANGNHAP()
{
    string Name, Password;
    chuThiTracNghiem(18, 2);
    gotoxy(60, 15);
    cout << "ACCOUNT";
    VeKhung(68, 14, 90, 16);
    gotoxy(60, 18);
    cout << "PASSWORD";
    VeKhung(68, 17, 90, 19);
    do
    {
        Name = NhapMa(69, 15, 21);
        if (Name == "")
            THONGBAO(1, "NAME RONG!");
    } while (Name == "");
    do
    {
        Password = NhapMa(69, 18, 21, "MATKHAU");
        if (Password == "")
            THONGBAO(1, "PASSWORD RONG!");
    } while (Password == "");
    return KiemTraTK(Name, Password);
}
int THONGBAO(int option, string thongbao)
{
    VeKhung(125, 0, 155, 10);
    gotoxy(126, 1);
    cout << "         THONG BAO           ";
    gotoxy(126, 2);
    cout << "-----------------------------";
    gotoxy(126, 3);
    cout << thongbao;
    if (option == 1) // clear thanh thong bao
    {
        Sleep(600);
        for (int i = 0; i <= 10; i++)
        {
            gotoxy(125, i);
            cout << "                               ";
        }
    }
    else if (option == 2) // xoa noi dung vua thong bao
    {
        for (int i = 3; i <= 9; i++)
        {
            gotoxy(126, i);
            cout << "                              ";
        }
    }
    else if (option == 3) // hien yes no
    {
        int yes_no = 0, option = 0;
        do
        {
            if (option == 224)
            {
                option = getch();
                if (option == 77)
                {
                    gotoxy(135, 8);
                    TextColor(16);
                    cout << "  YES  ";
                    TextColor(64);
                    gotoxy(142, 8);
                    cout << "   NO  ";
                    yes_no = 0;
                    "aaa";
                    continue;
                }
            }

            {
                gotoxy(135, 8);
                TextColor(64);
                cout << "  YES  ";
                TextColor(16);
                gotoxy(142, 8);
                cout << "   NO  ";
                yes_no = 1;
            }
        } while ((option = getch()) != 13);
        TextColor(7);
        return yes_no;
    }
}