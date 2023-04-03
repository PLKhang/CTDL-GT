#include "doHoa.h"

int THONGBAO(int option, string thongbao)
{
	SetColor(0,7);
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
		// xoa thanh thong bao
		SetColor(0,7);
		for (int i = 0; i <= 10; i++)
		{
			gotoxy(125, i);
			cout << "                               ";
		}
		TextColor(7);
		return yes_no;
	}
}
void VeHeader(int types, string text1, string text2)
{
	int x = 5, y = 5;
	switch (types)
	{
	case 1:
	case 2:
		while (x <= 115)
		{
			gotoxy(x, y);
			if (x == 5)
				cout << LEFT_TOP;
			else if (x == 115)
				cout << RIGHT_TOP;
			else
				cout << NGANG;
			x++;
		}
		gotoxy(55 - text1.length() / 2, 6);
		cout << text1;
		gotoxy(55 - text2.length() / 2, 7);
		cout << text2;
		gotoxy(5, 6);
		cout << DOC;
		gotoxy(5, 7);
		cout << DOC;
		gotoxy(115, 6);
		cout << DOC;
		gotoxy(115, 7);
		cout << DOC;
		break;
	case 3:
	case 4:
	case 5:
		while (x <= 90)
		{
			gotoxy(x, y);
			if (x == 5)
				cout << LEFT_TOP;
			else if (x == 90)
				cout << RIGHT_TOP;
			else
				cout << NGANG;
			x++;
		}
		gotoxy(42 - text1.length() / 2, 6);
		cout << text1;
		gotoxy(42 - text2.length() / 2, 7);
		cout << text2;
		gotoxy(5, 6);
		cout << DOC;
		gotoxy(5, 7);
		cout << DOC;
		gotoxy(90, 6);
		cout << DOC;
		gotoxy(90, 7);
		cout << DOC;
		break;
	}
}


bool VeDanhSach(int types)
{
	int x0 = 5, y0 = 8;
	int xn = 115, yn = 30;
	int x1 = 200, x2 = 200, x3 = 200;
	switch (types)
	{
	case 1:
		x1 = 25;
		x2 = 100;
		gotoxy(12, 9);
		cout << "MA LOP";
		gotoxy(59, 9);
		cout << "TEN LOP";
		gotoxy(103, 9);
		cout << "NIEN KHOA";
		break;
	case 2:
		x1 = 25;
		x2 = 80;
		x3 = 100;
		gotoxy(8, 9);
		cout << "MA SO SINH VIEN";
		gotoxy(50, 9);
		cout << "HO";
		gotoxy(89, 9);
		cout << "TEN";
		gotoxy(101, 9);
		cout << "  GIOI TINH  ";
		break;
	case 3:
		xn = 90;
		x1 = 70;
		gotoxy(30, 9);
		cout << "TEN MON HOC";
		gotoxy(78, 9);
		cout << "DIEM";
		break;
	case 4:
		xn = 90;
		x1 = 25;
		gotoxy(12, 9);
		cout << "MA MON";
		gotoxy(52, 9);
		cout << "TEN MON HOC";
		break;
	case 5:
		xn = 90;
		x1 = 25;
		gotoxy(13, 9);
		cout << "ID";
		gotoxy(53, 9);
		cout << "NOI DUNG";
		break;
	default:
		return 0;
	}
	gotoxy(x0, y0);
	for (int i = x0; i <= xn; i++)
	{
		if (i == x0)
		{
			gotoxy(i, y0);
			cout << LEFT_MIDDLE;
			for (int j = y0 + 1; j <= yn; j++)
			{
				gotoxy(i, j);
				if (j == yn)
					cout << LEFT_BOTTOM;
				else if (j % 2 == 0)
					cout << LEFT_MIDDLE;
				else
					cout << DOC;
			}
		}
		else if (i == xn)
		{
			gotoxy(xn, y0);
			cout << RIGHT_MIDDLE;
			for (int j = y0 + 1; j <= yn; j++)
			{
				gotoxy(i, j);
				if (j == yn)
					cout << RIGHT_BOTTOM;
				else if (j % 2 == 0)
					cout << RIGHT_MIDDLE;
				else
					cout << DOC;
			}
		}
		else if (i == x1 || i == x2 || i == x3)
		{
			gotoxy(i, y0);
			cout << TOP_MIDDLE;
			for (int j = y0 + 1; j <= yn; j++)
			{
				gotoxy(i, j);
				if (j == yn)
					cout << BOTTOM_MIDDLE;
				else if (j % 2 == 0)
					cout << CENTER;
				else
					cout << DOC;
			}
		}
	}
	for (int i = y0; i <= yn; i++)
	{
		if (!(i & 1))
		{
			for (int j = x0 + 1; j < xn; j++)
				if (!(j == x1 || j == x2 || j == x3))
				{
					gotoxy(j, i);
					cout << NGANG;
				}
		}
	}
	return 1;
}
void VeKhung(int x1, int y1, int x2, int y2)
{
	for (int ix = x1 + 1; ix < x2; ix++)
	{
		gotoxy(ix, y1);
		cout << NGANG;
		gotoxy(ix, y2);
		cout << NGANG;
	}
	for (int iy = y1 + 1; iy < y2; iy++)
	{
		gotoxy(x1, iy);
		cout << DOC;
		gotoxy(x2, iy);
		cout << DOC;
	}
	gotoxy(x1, y1);
	cout << LEFT_TOP;
	gotoxy(x2, y1);
	cout << RIGHT_TOP;
	gotoxy(x1, y2);
	cout << LEFT_BOTTOM;
	gotoxy(x2, y2);
	cout << RIGHT_BOTTOM;
}
bool KhungThem(int types)
{
	for (int i = 0; i < 5; i++)
		delete_LineOnScreen(5, 32 + i, 110);
	int x0 = 5, y0 = 32;
	int xn = 115, yn = 36;
	int x1 = 200, x2 = 200, x3 = 200;
	switch (types)
	{
	case 1:
		x1 = 25;
		x2 = 100;
		gotoxy(6, 33);
		cout << "NHAP MA LOP";
		gotoxy(26, 33);
		cout << "NHAP TEN LOP";
		gotoxy(101, 33);
		cout << "NHAP NIEN KHOA";
		break;
	case 2:
		x1 = 25;
		x2 = 80;
		x3 = 100;
		gotoxy(6, 33);
		cout << "NHAP MSSV";
		gotoxy(26, 33);
		cout << "NHAP HO";
		gotoxy(81, 33);
		cout << "NHAP TEN";
		gotoxy(101, 33);
		cout << "NHAP MAT KHAU";
		break;
	case 4:
		xn = 90;
		x1 = 25;
		gotoxy(6, 33);
		cout << "NHAP MA MON";
		gotoxy(26, 33);
		cout << "NHAP TEN MON HOC";
		break;
	default:
		return 0;
	}

	for (int i = x0; i <= xn; i++)
	{
		if (i == x0)
		{
			gotoxy(i, y0);
			cout << LEFT_TOP;
			for (int j = y0 + 1; j <= yn; j++)
			{
				gotoxy(i, j);
				if (j == yn)
					cout << LEFT_BOTTOM;
				else if (!(j & 1))
					cout << LEFT_MIDDLE;
				else
					cout << DOC;
			}
		}
		else if (i == xn)
		{
			gotoxy(i, y0);
			cout << RIGHT_TOP;
			for (int j = y0 + 1; j <= yn; j++)
			{
				gotoxy(i, j);
				if (j == yn)
					cout << RIGHT_BOTTOM;
				else if (!(j & 1))
					cout << RIGHT_MIDDLE;
				else
					cout << DOC;
			}
		}
		else if (i == x1 || i == x2 || i == x3)
		{
			gotoxy(i, y0);
			cout << TOP_MIDDLE;
			for (int j = y0 + 1; j <= yn; j++)
			{
				gotoxy(i, j);
				if (j == yn)
					cout << BOTTOM_MIDDLE;
				else if (!(j & 1))
					cout << CENTER;
				else
					cout << DOC;
			}
		}
	}
	for (int i = y0; i <= yn; i += 2)
	{
		for (int j = x0 + 1; j < xn; j++)
			if (!(j == x1 || j == x2 || j == x3))
			{
				gotoxy(j, i);
				cout << NGANG;
			}
	}
	return 1;
}

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
void VeBangCauHoi(char tenMH[], int ID)
{
	system("cls");
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
	gotoxy(45, 6);
	cout << "NOI DUNG CAU HOI-" << ID;
	gotoxy(45, 8);
	cout << tenMH;
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
	system("cls");
	VeKhung(5, 5, 115, 25);
	int x = 5, y = 9;
	while (y <= 21)
	{
		x = 5;
		while (x <= 115)
		{
			gotoxy(x, y);
			if (x == 5)
				cout << LEFT_MIDDLE;
			else if (x == 115)
				cout << RIGHT_MIDDLE;
			else
				cout << NGANG;
			x++;
		}
		y = y + 4;
	}
	x = 15, y = 9;
	while (y <= 25)
	{
		gotoxy(x, y);
		if (y == 9)
			cout << TOP_MIDDLE;
		else if (y == 25)
			cout << BOTTOM_MIDDLE;
		else if (y == 9 || y == 13 || y == 17 || y == 21)
			cout << CENTER;
		else
			cout << DOC;
		y++;
	}
	SetColor(2, 0);
	gotoxy(6, 10);
	cout << "         ";
	gotoxy(6, 11);
	cout << "         ";
	gotoxy(6, 12);
	cout << "         ";
	gotoxy(10, 10);
	cout << "A";
	SetColor(0, 7);
	gotoxy(10, 14);
	cout << "B";
	gotoxy(10, 18);
	cout << "C";
	gotoxy(10, 22);
	cout << "D";
}
void VeBangDanhSachCauHoi(char maMH[], int MaxPage, int Page)
{
	system("cls");
	VeKhung(5, 5, 115, 29);
	int x = 5, y = 7;
	while (y <= 27)
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
		y += 2;
	}
	x = 20, y = 7;
	while (y <= 29)
	{
		gotoxy(x, y);
		if (y == 7)
			cout << char(194);
		else if (y == 29)
			cout << char(193);
		else if (y == 9 || y == 11 || y == 13 || y == 15 || y == 17 || y == 19 || y == 21 || y == 23 || y == 25 || y == 27)
			cout << char(197);
		else
			cout << char(179);
		y++;
	}
	gotoxy(12, 8);
	cout << "ID";
	gotoxy(55, 8);
	cout << "NOI DUNG";
	gotoxy(45, 6);
	cout << "DANH SACH CAU HOI - ";
	gotoxy(65, 6);
	cout << maMH;

	gotoxy(116, 28);
	SetColor(5, 6);
	cout << "Page " << Page << '/' << MaxPage;
	SetColor(0, 7);
}
