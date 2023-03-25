#include"ThuVien.h"
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void TextColor(int color) {
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
	else return key;
}
void VeKhung(int x1, int y1, int x2, int y2)
{
	int khung_ngang = 196, khung_doc = 179, goc1 = 218, goc2 = 191, goc3 = 192, goc4 = 217;
	for (int ix = x1 + 1; ix < x2; ix++)
	{
		gotoxy(ix, y1);
		cout << char(khung_ngang);
		gotoxy(ix, y2);
		cout << char(khung_ngang);
	}
	for (int iy = y1 + 1; iy < y2; iy++)
	{
		gotoxy(x1, iy);
		cout << char(khung_doc);
		gotoxy(x2, iy);
		cout << char(khung_doc);
	}
	gotoxy(x1, y1);
	cout << char(goc1);
	gotoxy(x2, y1);
	cout << char(goc2);
	gotoxy(x1, y2);
	cout << char(goc3);
	gotoxy(x2, y2);
	cout << char(goc4);
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