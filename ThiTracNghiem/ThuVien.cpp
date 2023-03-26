#include "ThuVien.h"
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
char GetKey()
{
	char key;
	key = getch();
	if (key == -32 || key == 0)
		return -getch();
	else
		return key;
}
string NhapChuoi(int x, int y, int chieudai) // x va y la dia chi de hien ki tu vua nhap
{
	gotoxy(x, y);
	char chuoi[chieudai];
	int index = 0;
	char ki_tu;
	while ((ki_tu = GetKey()) != 13)
	{
		if ((index == chieudai) || (ki_tu == 32 && index > 0 && chuoi[index - 1] == 32) || (ki_tu == ' ' && index == 0))
			continue;
		if ((ki_tu >= 'A' && ki_tu <= 'Z') || (ki_tu >= 'a' && ki_tu <= 'z') || ki_tu == '-' || ki_tu == '_' || (ki_tu >= '0' && ki_tu <= '9'))
		{
			chuoi[index] = toupper(ki_tu);
			gotoxy(x + index, y);
			cout << ki_tu;
			index++;
		}
		if (ki_tu == 8 && index > 0)
		{
			index--;
			chuoi[index] = '\0';
			gotoxy(x + index, y);
			cout << " ";
			gotoxy(x + index, y);
		}
	}
	chuoi[index] = '\0';
	return string(chuoi);
}
string NhapMa(int x, int y, int chieudai, string loai)
{
	gotoxy(x, y);
	char Ma[chieudai], ki_tu;
	int index = 0;
	while ((ki_tu = GetKey()) != 13)
	{
		if (index == chieudai)
			continue;
		if ((index == 0 && (ki_tu == ' ')) || ki_tu == -32 || ki_tu == 0)
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
		if (ki_tu == 8 && index > 0)
		{
			index--;
			Ma[index] = '\0';
			gotoxy(x + index, y);
			cout << " ";
			gotoxy(x + index, y);
		}
	}
	Ma[index] = '\0';
	return string(Ma);
}
int doc_danhSachLopHoc(ListLH &dslh)
{
    // Mo file
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
                strcpy(data.nienKhoa, field.c_str());
                break;
            default:
                return -1;
            }
            field_Num++;
        }
        doc_danhSachSinhVien(data.danhSachSinhVien, data.maLop);
    }

    // Dong file
    file.close();
}
int doc_danhSachSinhVien(PtrSV &dssv, string maLH)
{
    KhoiTao_PtrSV(dssv);
    string fileLocation = "Data/DanhSachSinhVien/" + maLH + ".txt";

    ifstream file(fileLocation.c_str());
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
    file.close();
	return 1;
}
int doc_danhSachDiemThi(PtrDT &dsdt, string maLH, string mssv)
{
    KhoiTao_PtrDT(dsdt);
    string fileLocation = "Data/DanhSachSinhVien/DanhSachDiemThi/" + maLH + '/' + mssv + ".txt";

    ifstream file(fileLocation.c_str());
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
            default:
                return -1;
            }
            field_Num++;
        }
    }
    // Dong file
    file.close();
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
        docfile.ignore();
        docfile.getline(question->info.question, 200);
        docfile.getline(question->info.ans1, 100);
        docfile.getline(question->info.ans2, 100);
        docfile.getline(question->info.ans3, 100);
        docfile.getline(question->info.ans4, 100);
        docfile >> question->info.answer;
        docfile.ignore();
        InsertQuestion(dsch, question);
    }
    docfile.close();
}
int ghi_danhSachLopHoc(ListLH dslh)
{
    // Mo file
    ofstream file;
    file.open("Data/DanhSachLopHoc.txt", ios::out);
    if (!file)
        return 0;

    file << dslh.n << endl;
    for (int i = 0; i < dslh.n; i++)
    {
        // cap du lieu
        LopHoc data;
        file << data.maLop << "|";
        file << data.tenLop << "|";
        file << data.nienKhoa << "|";
        // Ghi dữ liệu vào file
        // cin >> data.maLop;
        // cin.ignore();
        // getline(cin, data.tenLop);
        // cin >> data.nienKhoa;
        // data.danhSachSinhVien = ghi_danhSachSinhVien();
        // file << data.maLop << "|" << data.tenLop << "|" << data.nienKhoa << "|"  << endl;
        // ghi_danhSachSinhVien(data.danhSachSinhVien, data.maLop);
        file << '\n';
    }

    // Đóng file
    file.close();
    return 1;
}
int ghi_danhSachSinhVien(PtrSV dssv, string maLH)
{
    string fileLocation = "Data/DanhSachSinhvien/" + maLH + ".txt";
    ofstream file(fileLocation.c_str());
    if (!file)
        return 0;
    PtrSV p = dssv;
    while (p != NULL)
    {
        file << p->info.MSSV << '|' << p->info.password << '|' << p->info.ho << '|' << p->info.ten << '|' << p->info.phai << "|\n";
        ghi_danhSachDiemThi(p->info.danhSachDiemThi, maLH, p->info.MSSV);
        p = p->next;
    }
    file.close();
	return 1;
}
int ghi_danhSachDiemThi(PtrDT dsdt, string maLH, string mssv)
{
    string fileLocation = "Data/DanhSachSinhVien/DanhSachDiemThi/" + maLH + '/' + mssv + ".txt";
    ofstream file(fileLocation.c_str());
    if (!file)
        return 0;
    PtrDT p = dsdt;
    while (p != NULL)
    {
        file << p->info.maMonHoc << '|' << p->info.diemThi << "|\n";
        p = p->next;
    }
    file.close();
    return 1;
}
int ghi_danhSachMonHoc(ListMH dsmh)
{
    // Mo file
    ofstream file;
    file.open("Data/DanhSachLopHoc.txt", ios::out);
    if (!file)
        return 0;

    file << dsmh.n << endl;

    for (int i = 0; i < dsmh.n; i++)
    {
        // cap du lieu
        MonHoc data;
        file << data.maMonHoc << "|";
        file << data.tenMonHoc << "|" << endl;
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
                << temp->info.question << endl
                << temp->info.ans1 << endl
                << temp->info.ans2 << endl
                << temp->info.ans3 << endl
                << temp->info.ans4 << temp->info.answer;
        if (!q.empty())
            ghifile << endl;
    }
    ghifile.close();
}
