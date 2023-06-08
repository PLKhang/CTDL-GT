#include "ThuVien.h"
void FullScreen()
{
	keybd_event(VK_F11, 0, 0, 0); // Simulate pressing F11 key
    keybd_event(VK_F11, 0, KEYEVENTF_KEYUP, 0); // Simulate releasing F11 key
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void TextColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
int wherex()
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}
int wherey(void)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

//////////////////////////////////////////////////////////////////////////
int GetKey() // dung để loại bỏ phím mở rộng
{
    int key;
    key = getch();
    if (key == 224 || key == 0)
        return -getch();
    else
        return key;
}
string NhapChuoi(int x, int y, int chieudai, int option) // x va y la dia chi de hien ki tu vua nhap
{
    char chuoi[chieudai + 1] = {'\0'};
    int index = 0;
    int ki_tu;
    if (option == 0)
        delete_LineOnScreen(x, y, chieudai);
    else
    {
        gotoxy(21, 10);
        cout << "                                                                                              ";
        gotoxy(21, 11);
        cout << "                                                                                              ";
    }
    gotoxy(x, y);
    setCursorVisibility(1);
    while ((ki_tu = getch()) != ENTER)
    {
        if (ki_tu == ESC)
        {
            setCursorVisibility(0);
            return "EXIT";
        }
        else if (ki_tu == 0 || ki_tu == 224)
        {
            ki_tu = getch();
            setCursorVisibility(0);
            switch (ki_tu)
            {
            case F1:
                return "F1";
            case F2:
                return "F2";
            case F5:
                return "F5";
            }
            continue;
        }

        // xoa ki tu
        else if (ki_tu == BACKSPACE && index > 0)
        {
            index--;
            chuoi[index] = '\0';
            if (index <= 93)
            {
                gotoxy(x + index, y);
                cout << " ";
                gotoxy(x + index, y);
            }
            else
            {
                gotoxy(x - 94 + index, y + 1);
                cout << " ";
                gotoxy(x - 94 + index, y + 1);
            }
        }
        // kiem tra neu lon hon chieu dai hoac ki tu dau bang ' ' thi khong cho vao mang
        if ((index == chieudai) || (ki_tu == ' ' && index == 0) || (ki_tu == ' ' && chuoi[index - 1] == ' '))
            continue;

        if ((ki_tu >= 'A' && ki_tu <= 'Z') || (ki_tu >= 'a' && ki_tu <= 'z') || ki_tu == '-' || ki_tu == '_' || (ki_tu >= '0' && ki_tu <= '9') || ki_tu == ' ')
        {
            chuoi[index] = toupper(ki_tu);
            if (index <= 93)
            {
                gotoxy(x + index, y);
            }
            else
            {
                gotoxy(x - 94 + index, y + 1);
            }
            cout << chuoi[index];
            index++;
        }
    }
    setCursorVisibility(0);
    chuoi[index] = '\0';
    return chuoi;
}
string NhapChuoi1(int x, int y, int length, string &input) // x va y la dia chi de hien ki tu vua nhap
{
    setCursorVisibility(1);
    int index, ki_tu;
    // cập nhật vị trí hiện tại
    index = input.size();
    gotoxy(x + index, y);
    input.resize(length); // thiết lập độ dài cho chuỗi
    while ((ki_tu = getch()) != ENTER)
    {
        if (ki_tu == ESC)
        {
            if (input[index - 1] == ' ' && index != 0)
                input[--index] = '\0';
            input.resize(index);
            return "EXIT";
        }
        else if (ki_tu == 0 || ki_tu == 224)
        {
            ki_tu = getch();
            if (ki_tu == UP)
            {
                if (input[index - 1] == ' ' && index != 0)
                    input[--index] = '\0';
                input.resize(index);
                return "UP";
            }
            else if (ki_tu == DOWN)
            {
                if (input[index - 1] == ' ' && index != 0)
                    input[--index] = '\0';
                input.resize(index);
                return "DOWN";
            }
            else if (ki_tu == LEFT)
            {
                if (input[index - 1] == ' ' && index != 0)
                    input[--index] = '\0';
                input.resize(index);
                return "LEFT";
            }
            else if (ki_tu == RIGHT)
            {
                if (input[index - 1] == ' ' && index != 0)
                    input[--index] = '\0';
                input.resize(index);
                return "RIGHT";
            }
            continue;
        }
        // xoa ki tu
        else if (ki_tu == BACKSPACE && index > 0)
        {
            index--;
            input[index] = '\0';
            if (index <= 93)
            {
                gotoxy(x + index, y);
                cout << " ";
                gotoxy(x + index, y);
            }
            else
            {
                gotoxy(x - 94 + index, y + 1);
                cout << " ";
                gotoxy(x - 94 + index, y + 1);
            }
        }
        // kiem tra neu lon hon chieu dai hoac ki tu dau bang ' ' thi khong cho vao mang
        if ((index == length) || (ki_tu == ' ' && index == 0) || (ki_tu == ' ' && input[index - 1] == ' '))
            continue;

        if ((ki_tu >= 'A' && ki_tu <= 'Z') || (ki_tu >= 'a' && ki_tu <= 'z') || ki_tu == '-' || ki_tu == '_' || (ki_tu >= '0' && ki_tu <= '9') || ki_tu == ' ')
        {
            input[index] = toupper(ki_tu);
            if (index <= 93)
            {
                gotoxy(x + index, y);
            }
            else
            {
                gotoxy(x - 94 + index, y + 1);
            }
            cout << input[index];
            index++;
        }
    }
    if (input[index - 1] == ' ')
        input[--index] = '\0'; // bỏ kí tự cuối
    input.resize(index);       // thiết lập kích thước của chuỗi
    return "DONE";
}
string NhapDapAn(int x, int y, char &Answer)
{
    setCursorVisibility(1);
    int index = 0, ki_tu;
    if (Answer >= 'A' && Answer <= 'D')
        index = 1;
    gotoxy(x + index, y);
    while ((ki_tu = getch()) != ENTER)
    {
        if (ki_tu == ESC)
        {
            setCursorVisibility(0);
            return "EXIT";
        }
        else if (ki_tu == 0 || ki_tu == 224)
        {
            ki_tu = getch();
            if (ki_tu == UP)
            {
                setCursorVisibility(0);
                return "UP";
            }
            else if (ki_tu == DOWN)
            {
                setCursorVisibility(0);
                return "DOWN";
            }
            else if (ki_tu == LEFT)
            {
                setCursorVisibility(0);
                return "LEFT";
            }
            else if (ki_tu == RIGHT)
            {
                setCursorVisibility(0);
                return "RIGHT";
            }
            continue;
        }
        // xoa ki tu
        else if (ki_tu == BACKSPACE && index > 0)
        {
            index = 0;
            Answer = '\0';
            gotoxy(x, y);
            cout << " ";
            gotoxy(x, y);
        }
        ki_tu = toupper(ki_tu);
        if (ki_tu >= 'A' && ki_tu <= 'D' && index == 0)
        {
            Answer = ki_tu;
            gotoxy(x, y);
            cout << Answer;
            index++;
        }
    }
    setCursorVisibility(0);
    return "DONE";
}
string NhapMa(int x, int y, int chieudai, string loai)
{
    delete_LineOnScreen(x, y, chieudai);
    setCursorVisibility(1);
    gotoxy(x, y);
    char Ma[chieudai + 1] = {'\0'};
    int ki_tu;
    int index = 0;
    while ((ki_tu = getch()) != ENTER)
    {
        if (ki_tu == ESC)
        {
            setCursorVisibility(0);
            return "EXIT";
        }
        if (ki_tu == 0 || ki_tu == 224)
        {
            ki_tu = getch(); // bat ki tu con khi nhap phim mo rong
            switch (ki_tu)
            {
            case F1:
                setCursorVisibility(0);
                return "F1";
            case F2:
                setCursorVisibility(0);
                return "F2";
            case F5:
                setCursorVisibility(0);
                return "F5";
            }
            continue; // tiep tuc de khong nhap ki tu du
        }

        if (ki_tu == BACKSPACE && index > 0)
        {
            index--;
            Ma[index] = '\0';
            gotoxy(x + index, y);
            cout << " ";
            gotoxy(x + index, y);
        }
        if ((index == 0 && (ki_tu == ' ')) || index == chieudai)
            continue;
        if ((ki_tu >= 'A' && ki_tu <= 'Z') || (ki_tu >= 'a' && ki_tu <= 'z') || (ki_tu >= '0' && ki_tu <= '9') || ki_tu == '_' || ki_tu == '-')
        {
            Ma[index] = toupper(ki_tu);
            gotoxy(x + index, y);
            if (loai == "MATKHAU")
                cout << '*';
            else
                cout << Ma[index];
            index++;
        }
    }
    setCursorVisibility(0);
    Ma[index] = '\0';
    return Ma;
}
string NhapMa1(int x, int y, int length, string &input, string loai)
{
    setCursorVisibility(1);
    int ki_tu, index;
    index = input.size();
    input.resize(length);
    gotoxy(x + index, y);
    while ((ki_tu = getch()) != ENTER)
    {
        if (ki_tu == ESC)
        {
            if (input[index] = '\0' && index != 0)
                input[--index] = '\0';
            input.resize(index);
            setCursorVisibility(0);
            return "EXIT";
        }
        if (ki_tu == 0 || ki_tu == 224)
        {
            ki_tu = getch(); // bat ki tu con khi nhap phim mo rong
            if (ki_tu == UP)
            {
                if (input[index] = '\0' && index != 0)
                    input[--index] = '\0';
                input.resize(index);
                setCursorVisibility(0);
                return "UP";
            }
            if (ki_tu == DOWN)
            {
                if (input[index] = '\0' && index != 0)
                    input[--index] = '\0';
                input.resize(index);
                setCursorVisibility(0);
                return "DOWN";
            }
            if (ki_tu == LEFT)
            {
                if (input[index] = '\0' && index != 0)
                    input[--index] = '\0';
                input.resize(index);
                setCursorVisibility(0);
                return "LEFT";
            }
            if (ki_tu == RIGHT)
            {
                if (input[index] = '\0' && index != 0)
                    input[--index] = '\0';
                input.resize(index);
                setCursorVisibility(0);
                return "RIGHT";
            }
            continue; // tiep tuc de khong nhap ki tu du
        }

        if (ki_tu == BACKSPACE && index > 0)
        {
            index--;
            input[index] = '\0';
            gotoxy(x + index, y);
            cout << " ";
            gotoxy(x + index, y);
        }
        if ((index == 0 && (ki_tu == ' ')) || index == length)
            continue;
        if ((ki_tu >= 'A' && ki_tu <= 'Z') || (ki_tu >= 'a' && ki_tu <= 'z') || (ki_tu >= '0' && ki_tu <= '9') || ki_tu == '_' || ki_tu == '-')
        {
            input[index] = toupper(ki_tu);
            gotoxy(x + index, y);
            if (loai == "MATKHAU")
                cout << '*';
            else
                cout << input[index];
            index++;
        }
    }
    if (input[index] = '\0')
        input[--index] = '\0';
    input.resize(index);
    setCursorVisibility(0);
    return "DONE";
}
double NhapSo(int x, int y, int soluong)
{
    char num[soluong + 1] = {'\0'};
    int index = 0;
    char ch;
    bool check = true; // kiem tra de nhap duy nhat 1 dau '.'
    delete_LineOnScreen(x, y, soluong);
    setCursorVisibility(1);
    while ((ch = getch()) != ENTER)
    {
        if (ch >= '0' && ch <= '9' && index < soluong)
        {
            num[index] = ch;
            gotoxy(x + index++, y);
            cout << ch;
        }
        if (ch == '.' && check && index < soluong)
        {
            num[index] = ch;
            check = false;
            gotoxy(x + index++, y);
            cout << ch;
        }
        if (ch == BACKSPACE && index > 0)
        {
            num[index] = '\0';
            gotoxy(x + --index, y);
            cout << ' ';
            gotoxy(x + index, y);
        }
        if (ch == ESC) // dang nhap lieu thi chon thoat
        {
            setCursorVisibility(0);
            return -1;
        }
    }
    setCursorVisibility(0);
    if (index == 0) // truong hop enter khi chua nhap
        return -2;
    return atof(num);
}
int Dem(int num)
{
    int count = 0;
    while (num > 0)
    {
        num /= 10;
        count++;
    }
    return count;
}
string NhapSo1(int x, int y, int soluong, int &num)
{
    int index, ch;
    index = Dem(num);
    gotoxy(x + index, y);
    while ((ch = getch()) != ENTER)
    {
        setCursorVisibility(1);
        if (ch >= '0' && ch <= '9' && index < soluong)
        {
            num = num * 10 + (ch - '0');
            gotoxy(x + index++, y);
            cout << ch - '0';
        }
        if (ch == BACKSPACE && index > 0)
        {
            num /= 10;
            gotoxy(x + --index, y);
            cout << ' ';
            gotoxy(x + index, y);
        }
        if (ch == ESC) // dang nhap lieu thi chon thoat
        {
            setCursorVisibility(0);
            return "EXIT";
        }
        if (ch == 224 || ch == 0)
        {
            ch = getch();
            setCursorVisibility(0);
            if (ch == UP)
                return "UP";
            else if (ch == DOWN)
                return "DOWN";
            else if (ch == LEFT)
                return "LEFT";
            else if (ch == RIGHT)
                return "RIGHT";
        }
    }
    setCursorVisibility(0);
    if (index == 0)
        return "EMPTY";
    return "DONE";
}
bool is_Empty_CArray(const char *a)
{
    return a[0] == '\0' || a == "ESC";
}
void delete_LineOnScreen(int x, int y, int length)
{
    string eraser;
    eraser.resize(length, ' ');
    gotoxy(x, y);
    // SetColor(0, 7);
    // for (int i = 0; i < length; i++)
    cout << eraser;
    gotoxy(x, y);
}
void delete_AreaOnScreen(int x, int y, int width, int height)
{
    for (int i = 0; i < height; i++)
        delete_LineOnScreen(x, y + i, width);
}
void setCursorVisibility(bool isVisible)
{
    CONSOLE_CURSOR_INFO cursorInfo;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get the current cursor info
    GetConsoleCursorInfo(handle, &cursorInfo);

    // Set the cursor visibility
    cursorInfo.bVisible = isVisible;
    SetConsoleCursorInfo(handle, &cursorInfo);
}
////////////////////////////////////////////////////
int doc_danhSachLopHoc(ListLH &dslh)
{
    // Mo file
    ifstream file("Data\\DanhSachLopHoc.txt", ios::in);
    if (!file)
        return 0;

    // cap du lieu
    string line;
    LopHoc data;

    // cap cac bien de chay code
    int pos = 0;
    int field_Num = 1;
    string field;
    int check = 0;

    int debug = 0;
    // vong lap de doc cac dong trong file
    while (getline(file, line))
    {
        pos = 0;
        field_Num = 1;
        while ((pos = line.find("|")) != string::npos) // dk: toi khi pos tim thay dau | va chuoi khac gia tri cuoi
        {
            field = line.substr(0, pos); // cat chuoi dai thanh chuoi con tu dau den vi tri pos -> luu vao field
            line.erase(0, pos + 1);      // xoa chuoi trong line tu o den pos + 1
            switch (field_Num)
            {
            case 1:
                strcpy(data.maLop, field.c_str()); // copy du lieu chua ma lop vao field
                break;
            case 2:
                strcpy(data.tenLop, field.c_str());
                break;
            case 3:
                data.nienKhoa = atoi(field.c_str());
                break;
            default:
                return -1;
            }
            field_Num++;
        }
        check = doc_danhSachSinhVien(data.danhSachSinhVien, data.maLop);
        if (check != 1)
        {
            switch (check)
            {
            case 0:
                return -2;
            case -1:
                return -3;
            case -2:
                return -4;
            case -3:
                return -5;
            default:
                return 0;
            }
        }
        ThemLop(dslh, data);
    }

    // Dong file
    file.close();
    return 1;
}
int doc_danhSachSinhVien(PtrSV &dssv, const string &maLH)
{
    KhoiTao_PtrSV(dssv);
    string filePath = "Data\\DanhSachSinhVien\\" + maLH + ".txt";

    ifstream file(filePath.c_str());
    if (!file)
        return 0;

    string line;
    SinhVien info;

    int pos = 0;
    int field_Num = 1;
    string field;
    int check = 0;
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
        check = doc_danhSachDiemThi(info.danhSachDiemThi, maLH, info.MSSV);
        if (check != 1)
        {
            switch (check)
            {
            case 0:
                return -2;
            case -1:
                return -3;
            }
        }
        insert_Order_SV(dssv, info);
    }
    file.close();
    return 1;
}
int doc_danhSachDiemThi(PtrDT &dsdt, const string &maLH, const string &mssv) // insert_Last_DT
{
    KhoiTao_PtrDT(dsdt);
    string filePath = "Data/DanhSachSinhVien/DanhSachDiemThi/" + maLH + '/' + mssv + ".txt";

    ifstream file(filePath.c_str());
    if (!file)
        return 0;

    string line;
    DiemThi info;

    int pos = 0;
    int field_Num = 1;
    string field;

    PtrDT lastDT = dsdt;

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
        if (info.diemThi >= 0)
        {
            if (is_Empty_DT(dsdt))
            {
                insert_First_DT(dsdt, info);
                lastDT = dsdt;
            }
            else
            {
                lastDT->next = create_Node_DT(info);
                lastDT = lastDT->next;
            }
        }
    }
    file.close();
    return 1;
}
int doc_danhSachMonHoc(ListMH &dsmh)
{
    // Mo file
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
    while (getline(file, line))
    {
        pos = 0;
        field_Num = 1;
        while ((pos = line.find("|")) != string::npos) // dk: toi khi pos tim thay dau | va chuoi khac gia tri cuoi
        {
            field = line.substr(0, pos); // cat chuoi dai thanh chuoi con tu dau den vi tri pos -> luu vao field
            line.erase(0, pos + 1);      // xoa chuoi trong line tu o den pos + 1
            switch (field_Num)
            {
            case 1:
                strcpy(data.maMonHoc, field.c_str()); // copy du lieu chua ma mon vao field
                break;
            case 2:
                strcpy(data.tenMonHoc, field.c_str());
                break;
            case 3:
                if (!(atof(field.c_str())))
                    data.is_used = false;
                else
                    data.is_used = true;
                break;
            }
            field_Num++;
        }
        insert_MH(dsmh, data);
    }
    // Dong file
    file.close();
    return 1;
}
int doc_danhSachCauHoi(STreeCH &dsch)
{
    ifstream docfile("Data/DanhSachCauHoi.txt");
    STreeCH question;
    string temp;
    if (!docfile)
        return 0;
    while (!docfile.eof())
    {
        question = new nodeCauHoi;
        docfile.getline(question->info.maMonHoc, 16);
        docfile >> question->info.ID;
        docfile.ignore(); // bo qua ki tu xuong dong
        getline(docfile, temp);
        if (temp.compare("DA THI") == 0)
            question->is_used = true;
        else
            question->is_used = false;
        docfile.getline(question->info.question, 201);
        // gotoxy(0,0);cout<<question->info.question;
        // cin.ignore();
        docfile.getline(question->info.ans1, 101);
        docfile.getline(question->info.ans2, 101);
        docfile.getline(question->info.ans3, 101);
        docfile.getline(question->info.ans4, 101);
        docfile >> question->info.answer;
        docfile.ignore(); // bo qua ki tu xuong dong
        Insert(dsch, question);
    }
    docfile.close();
    return 1;
}
int docCauHoiDaThi(STreeCH root, Array<STreeCH> &List, char YourAnswer[], char MSSV[], MonHoc MH)
{
    ifstream docfile(("Data/DanhSachSinhVien/DanhSachCauHoiThi/" + string(MSSV) + ".txt").data());
    if (!docfile.is_open())
        return 0;
    string maMH;
    int temp, count = 0, ID;
    while (!docfile.eof())
    {
        getline(docfile, maMH);
        if (strcmp(MH.maMonHoc, maMH.data()) == 0)
        {
            docfile >> temp;
            for (int i = 0; i < temp; i++)
            {
                docfile >> ID;
                docfile.ignore(); // bỏ dấu |
                docfile >> YourAnswer[i];
                List.push(BinarySearch(root, ID));
            }
            docfile.close();
            Sort(List,0,List.GetIndexLast());
            return 1;
        }
    }
    return 0;
}
int demSoCauDaThi(MonHoc MH, char MSSV[])
{
    int temp = 0;
    string maMH;
    ifstream docfile(("Data/DanhSachSinhVien/DanhSachCauHoiThi/" + string(MSSV) + ".txt").data());
    if (!docfile.is_open())
        return 0;

    while (!docfile.eof())
    {
        getline(docfile, maMH);
        if (strcmp(MH.maMonHoc, maMH.data()) == 0)
        {
            docfile >> temp;
            docfile.close();
            return temp;
        }
    }
    return 0;
}
bool createLopHocFolder(string maLH)
{
    string folderPath = "Data\\DanhSachSinhVien\\DanhSachDiemThi\\" + maLH;
    string command = "mkdir " + folderPath;
    int status = system(command.c_str());
    if (status == 0)
        return 1;
    return 0;
}
bool removeLopHocFolder(string maLH)
{
    string folderPath = "Data\\DanhSachSinhVien\\DanhSachDiemThi\\" + maLH;
    string command = "rmdir " + folderPath;
    int status = system(command.c_str());
    if (status == 0)
        return 1;
    return 0;
}
bool removeLopHocFile(string maLH)
{
    string filePath = "Data/DanhSachSinhVien/" + maLH + ".txt";
    string command = "rm " + filePath;
    int status = system(command.c_str());
    if (status == 0)
        return 1;
    return 0;
}
bool removeSinhVienFile(string maLH, string mssv)
{
    string filePath = "Data/DanhSachSinhVien/DanhSachDiemThi/" + maLH + '/' + mssv + ".txt";
    string command = "rm " + filePath;
    int status = system(command.c_str());
    if (status == 0)
        return 1;
    return 0;
}
int ghi_danhSachLopHoc(ListLH dslh)
{
    // Mo file
    ofstream file;
    ofstream accountFile("Data/DanhSachTaiKhoan.txt");
    accountFile.clear();
    accountFile.close();
    file.open("Data/DanhSachLopHoc.txt", ios::out);
    if (!file)
        return 0;

    for (int i = 0; i < dslh.n; i++)
    {

        file << dslh.lh[i]->maLop << "|"
             << dslh.lh[i]->tenLop << "|"
             << dslh.lh[i]->nienKhoa << "|\n";
        ghi_danhSachSinhVien(dslh.lh[i]->danhSachSinhVien, dslh.lh[i]->maLop);
    }
    file.close();
    return 1;
}
int ghi_danhSachSinhVien(PtrSV dssv, string maLH)
{
    string filePath = "Data/DanhSachSinhvien/" + maLH + ".txt";
    ofstream file(filePath.c_str());
    ofstream accountFile("Data/DanhSachTaiKhoan.txt", ios::app);
    if (!file)
        return 0;
    PtrSV p = dssv;
    while (p != NULL)
    {
        file << p->info.MSSV << '|'
             << p->info.password << '|'
             << p->info.ho << '|'
             << p->info.ten << '|'
             << p->info.phai << "|\n";
        accountFile << p->info.MSSV << '|' << p->info.password << "|\n";
        ghi_danhSachDiemThi(p->info.danhSachDiemThi, maLH, p->info.MSSV);
        p = p->next;
    }
    file.close();
    accountFile.close();
    return 1;
}
int ghi_danhSachDiemThi(PtrDT dsdt, string maLH, string mssv)
{
    string filePath = "Data/DanhSachSinhVien/DanhSachDiemThi/" + maLH + '/' + mssv + ".txt";
    ofstream file(filePath.c_str());
    if (!file)
        return 0;
    PtrDT p = dsdt;
    while (p != NULL)
    {
        if (p->info.diemThi >= 0 && p->info.diemThi <= 10)
            file << p->info.maMonHoc << '|' << p->info.diemThi << "|\n";
        p = p->next;
    }
    file.close();
    return 1;
}
int ghi_danhSachMonHoc(ListMH dsmh)
{
    // Mo file
    ofstream file("Data/DanhSachMonHoc.txt");
    if (!file)
        return 0;

    for (int i = 0; i < dsmh.n; i++)
    {
        file << dsmh.nodes[i].maMonHoc << '|'
             << dsmh.nodes[i].tenMonHoc << "|"
             << (dsmh.nodes[i].is_used ? "1|\n" : "0|\n");
    }
    // Đong file
    file.close();
    return 1;
}
int ghi_danhSachCauHoi(STreeCH dsch)
{
    ofstream ghifile("Data/DanhSachCauHoi.txt");

    Queue<STreeCH> q;
    STreeCH temp;

    if (!ghifile)
        return 0;
    q.Push(dsch);
    while (!q.empty())
    {
        temp = q.pop();
        if (temp->left != NULL)
            q.Push(temp->left);
        if (temp->right != NULL)
            q.Push(temp->right);
        ghifile << temp->info.maMonHoc << endl
                << temp->info.ID << endl
                << (temp->is_used == true ? "DA THI" : "CHUA THI") << endl
                << temp->info.question << endl
                << temp->info.ans1 << endl
                << temp->info.ans2 << endl
                << temp->info.ans3 << endl
                << temp->info.ans4 << endl
                << temp->info.answer;
        if (!q.empty())
            ghifile << endl;
    }
    q.Destroy();
    ghifile.close();
}

void GhiCauHoiDaThi(char MSSV[], STreeCH *ListQuestion, char YourAnswer[], int numberQuestion)
{
    ofstream ghiCauHoiDaThi(("Data/DanhSachSinhVien/DanhSachCauHoiThi/" + string(MSSV) + ".txt").data(), ios::app);
    ghiCauHoiDaThi << ListQuestion[0]->info.maMonHoc << endl;
    ghiCauHoiDaThi << numberQuestion << endl;
    for (int k = 0; k < numberQuestion; k++)
    {
        ghiCauHoiDaThi << ListQuestion[k]->info.ID << '|' << YourAnswer[k] << endl;
    }
    ghiCauHoiDaThi.close();
}
