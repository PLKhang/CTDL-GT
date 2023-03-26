#include "doHoa.h"

int ThongBao();
bool XacNhan();
void VeHeader()
{
}
void VeOptions();

void MENU_GV();
void MENU_SV();

void VeDanhSach(int types);
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
void KhungThemSinhVien();
void KhungThemMonHoc();
void KhungThemDiemThi();
void KhungThemLopHoc();

void chuMenuGV(int x, int y)
{
	TextColor(4);
	gotoxy(x, y++);
	cout << " ________ _________ _______ _       ________            _________ _______  _   ";
	gotoxy(x, y++);
	cout << "(  ____ \\\\__   __/(  ___  )( (    /|(  ____ \\  |\\     /|\\__   __/(  ____ \\( (    /|";
	gotoxy(x, y++);
	cout << "| (    \\/   ) (   | (   ) ||  \\  ( || (    \\/  | )   ( |   ) (   | (    \\/|  \\  ( |";
	gotoxy(x, y++);
	cout << "| |         | |   | (___) ||   \\ | || |        | |   | |   | |   | (__    |   \\ | |";
	gotoxy(x, y++);
	cout << "| | ____    | |   |  ___  || (\\ \\) || | ____   ( (   ) )   | |   |  __)   | (\\ \\) |";
	gotoxy(x, y++);
	cout << "| | \\_  )   | |   | (   ) || | \\   || | \\_  )   \\ \\_/ /    | |   | (      | | \\   |";
	gotoxy(x, y++);
	cout << "| (___) |___) (___| )   ( || )  \\  || (___) |    \\   /  ___) (___| (____/\\| )  \\  |";
	gotoxy(x, y++);
	cout << "(_______)\\_______/|/     \\||/    )_)(_______)     \\_/   \\_______/(_______/|/    )_)";
	TextColor(0);
}
void chuThiTracNghiem(int x, int y)
{
	TextColor(5);
	gotoxy(x, y++);
	cout << " _______  _    _  _____   _______  _____             _____   _   _   _____  _    _  _____  ______  __  __ " << endl;
	gotoxy(x, y++);
	cout << "|__   __|| |  | ||_   _| |__   __||  __ \\     /\\    / ____| | \\ | | / ____|| |  | ||_   _||  ____||  \\/  |" << endl;
	gotoxy(x, y++);
	cout << "   | |   | |__| |  | |      | |   | |__) |   /  \\  | |      |  \\| || |  __ | |__| |  | |  | |__   | \\  / |" << endl;
	gotoxy(x, y++);
	cout << "   | |   |  __  |  | |      | |   |  _  /   / /\\ \\ | |      | . ` || | |_ ||  __  |  | |  |  __|  | |\\/| |" << endl;
	gotoxy(x, y++);
	cout << "   | |   | |  | | _| |_     | |   | | \\ \\  / ____ \\| |____  | |\\  || |__| || |  | | _| |_ | |____ | |  | |" << endl;
	gotoxy(x, y++);
	cout << "   |_|   |_|  |_||_____|    |_|   |_|  \\_\\/_/    \\_\\\\_____| |_| \\_| \\_____||_|  |_||_____||______||_|  |_|" << endl;
	TextColor(7);
}
void chuMenuSV(int x, int y)
{
	gotoxy(x, y++);
	cout << " __  __ ______ _   _ _    _    _____ _____ _   _ _    _  __      _______ ______ _   _";
	gotoxy(x, y++);
	cout << "|  \\/  |  ____| \\ | | |  | |  / ____|_   _| \\ | | |  | | \\ \\    / /_   _|  ____| \\ | |";
	gotoxy(x, y++);
	cout << "| \\  / | |__  |  \\| | |  | | | (___   | | |  \\| | |__| |  \\ \\  / /  | | | |__  |  \\| |";
	gotoxy(x, y++);
	cout << "| |\\/| |  __| | . ` | |  | |  \\___ \\  | | | . ` |  __  |   \\ \\/ /   | | |  __| | . ` |";
	gotoxy(x, y++);
	cout << "| |  | | |____| |\\  | |__| |  ____) |_| |_| |\\  | |  | |    \\  /   _| |_| |____| |\\  |";
	gotoxy(x, y++);
	cout << "|_|  |_|______|_| \\_|\\____/  |_____/|_____|_| \\_|_|  |_|     \\/   |_____|______|_| \\_|";
}
void VeBangCauHoi()
{
	VeKhung(5, 5, 115, 27);
	int x = 5, y = 7;
	while (y <= 25)
	{
		x = 5;
		while (x <= 115)
		{
			gotoxy(x, y);
			if (x == 5)
				cout << char(195);
			else if (x == 115)
				cout << char(180);
			else
				cout << char(196);
			x++;
		}
		if (y == 7)
			y += 2;
		else
			y += 3;
	}
	x = 20, y = 7;
	while (y <= 27)
	{
		gotoxy(x, y);
		if (y == 7)
			cout << char(194);
		else if (y == 27)
			cout << char(193);
		else if (y == 9 || y == 12 || y == 15 || y == 18 || y == 21 || y == 24)
			cout << char(197);
		else
			cout << char(179);
		y++;
	}
	gotoxy(6, 8);
	cout << "TEN MON HOC";
	gotoxy(6, 10);
	cout << "NOI DUNG";
	gotoxy(6, 13);
	cout << "LUA CHON 1";
	gotoxy(6, 16);
	cout << "LUA CHON 2";
	gotoxy(6, 19);
	cout << "LUA CHON 3";
	gotoxy(6, 22);
	cout << "LUA CHON 4";
	gotoxy(6, 25);
	cout << "DAP AN";
}
void VeKhungThi()
{
	VeKhung(5, 5, 115, 25);
	int x = 5, y = 9;
	while (y <= 21)
	{
		x = 5;
		while (x <= 115)
		{
			gotoxy(x, y);
			if (x == 5)
				cout << char(195);
			else if (x == 115)
				cout << char(180);
			else
				cout << char(196);
			x++;
		}
		y = y + 4;
	}
	x = 15, y = 9;
	while (y <= 25)
	{
		gotoxy(x, y);
		if (y == 9)
			cout << char(194);
		else if (y == 25)
			cout << char(193);
		else if (y == 9 || y == 13 || y == 17 || y == 21)
			cout << char(197);
		else
			cout << char(179);
		y++;
	}
	gotoxy(10, 10);
	cout << "A";
	gotoxy(10, 14);
	cout << "B";
	gotoxy(10, 18);
	cout << "C";
	gotoxy(10, 22);
	cout << "D";
}
int MenuGV()
{
	int chon, to = 5, len = 0;
	chuMenuGV(30, 1);
	gotoxy(65, 15);
	TextColor(20);
	cout << "      DANH SACH CAC LOP     ";
	TextColor(112);
	gotoxy(65, 17);
	cout << "      THEM SINH VIEN        ";
	gotoxy(65, 19);
	cout << "      DANH SACH MON HOC     ";
	gotoxy(65, 21);
	cout << "      BANG DIEM             ";
	gotoxy(65, 23);
	cout << "      THI THU               ";
	gotoxy(65, 25);
	cout << "      THOAT                 ";
	TextColor(0);
}