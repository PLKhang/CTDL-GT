#include "doHoa.h"

int THONGBAO(int option, string thongbao)
{
	SetColor(0, 7);
	VeKhung(125, 0, 155, 10);
	gotoxy(126, 1);
	cout << "         THONG BAO           ";
	gotoxy(126, 2);
	cout << "-----------------------------";
	int pos = 0;
	int field = 0;
	string subStr;
	while ((pos = thongbao.find("-")) != string::npos)
	{
		subStr = thongbao.substr(0, pos);
		thongbao.erase(0, pos + 1);
		gotoxy(126, 3 + field++);
		cout << subStr;
	}
	gotoxy(126, 3 + field++);
	cout << thongbao;
	if (option == 1) // clear thanh thong bao
	{
		Sleep(2000);
		for (int i = 0; i <= 10; i++)
		{
			gotoxy(125, i);
			cout << "                               ";
		}
	}
	else if (option == 2) // Tat thong bao khi an phim bat ky
	{
		getch();
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
		SetColor(0, 7);
		for (int i = 0; i <= 10; i++)
			delete_LineOnScreen(125, i, 32);
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
	delete_AreaOnScreen(6, 32, 110, 5);
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
		gotoxy(116, 33);
		cout << " NAM ";
		gotoxy(116, 35);
		cout << " NU  ";
		gotoxy(123, 34);
		SetColor(7, 0);
		cout << " XONG ";
		SetColor(0, 7);
		break;
	case 4:
		xn = 90;
		x1 = 25;
		gotoxy(6, 33);
		cout << "NHAP MA MON";
		gotoxy(26, 33);
		cout << "NHAP TEN MON HOC";
		gotoxy(92, 34);
		SetColor(7, 0);
		cout << " XONG ";
		SetColor(0, 7);
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
void XoaVungThi()
{
	gotoxy(80, 2);
	cout << "                                                               ";
	for (int j = 5; j <= 25; j++)
	{
		gotoxy(5, j);
		cout << "                                                                                                                    ";
	}
}
void VeKhungCauHoi(int Your_index, int Answer_index, int option)
{
	Sleep(200); // để chờ in thời gian thi
	XoaVungThi();
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
	if (option == 0) // thi
	{
		if (Your_index == 0)
			Your_index = 10;
		SetColor(2, 0);
		gotoxy(6, Your_index);
		cout << "         ";
		gotoxy(6, Your_index + 1);
		cout << "         ";
		gotoxy(6, Your_index + 2);
		cout << "         ";
	}
	else // chế độ xem câu hỏi đã thi
	{
		if (Your_index != 0)
		{
			if (Your_index != Answer_index)
			{
				// tô đáp án bạn chon
				SetColor(4, 0);
				gotoxy(6, Your_index);
				cout << "         ";
				gotoxy(6, Your_index + 1);
				cout << "         ";
				gotoxy(6, Your_index + 2);
				cout << "         ";
			}
		}
		// tô đáp án đúng
		SetColor(2, 0);
		gotoxy(6, Answer_index);
		cout << "         ";
		gotoxy(6, Answer_index + 1);
		cout << "         ";
		gotoxy(6, Answer_index + 2);
		cout << "         ";
	}
	SetColor(0, 7);
	gotoxy(10, 10);
	cout << "A";
	gotoxy(10, 14);
	cout << "B";
	gotoxy(10, 18);
	cout << "C";
	gotoxy(10, 22);
	cout << "D";
	if (option == 0)
	{
		SetColor(2, 0);
		switch (Your_index)
		{
		case 10:
		{
			gotoxy(10, 10);
			cout << "A";
			break;
		}
		case 14:
		{
			gotoxy(10, 14);
			cout << "B";
			break;
		}
		case 18:
		{
			gotoxy(10, 18);
			cout << "C";
			break;
		}
		case 22:
		{
			gotoxy(10, 22);
			cout << "D";
			break;
		}
		}
	}
	else
	{
		if (Your_index != 0&&Your_index != Answer_index)// TRƯỜNG HỢP CÓ CHỌN VÀ KHÁC KẾT QUẢ
		{
			// if (Your_index != Answer_index)
			// {
			SetColor(4, 0);
			switch (Your_index)
			{
			case 10:
			{
				gotoxy(10, 10);
				cout << "A";
				break;
			}
			case 14:
			{
				gotoxy(10, 14);
				cout << "B";
				break;
			}
			case 18:
			{
				gotoxy(10, 18);
				cout << "C";
				break;
			}
			case 22:
			{
				gotoxy(10, 22);
				cout << "D";
				break;
			}
				//}
			}
		}
		SetColor(2, 0);
		switch (Answer_index)
		{
		case 10:
		{
			gotoxy(10, 10);
			cout << "A";
			break;
		}
		case 14:
		{
			gotoxy(10, 14);
			cout << "B";
			break;
		}
		case 18:
		{
			gotoxy(10, 18);
			cout << "C";
			break;
		}
		case 22:
		{
			gotoxy(10, 22);
			cout << "D";
			break;
		}
		}
	}
	SetColor(0, 7);
}
void VeKhungCauHoi1(char tenMH[], int ID)
{
	// DÙNG CHO THÊM CÂU HỎI VÀ XEM CÂU HỎI BÌNH THƯỜNG
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
	cout << "NOI DUNG CAU HOI";
	if (ID > 0)
		cout << " - " << ID;
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

float VeKhungDiem(STreeCH *Questions, char YourAnswer[], PtrSV &SV, int so_cau)
{
	system("cls");
	VeKhung(57, 12, 90, 20);
	float diem = 0;
	int so_cau_dung = 0;
	for (int i = 0; i < so_cau; i++)
	{
		if (YourAnswer[i] == Questions[i]->info.answer)
			diem++;
	}
	so_cau_dung = diem;
	diem = (diem / so_cau) * 10;
	gotoxy(58, 14);
	cout << "HO VA TEN: " << SV->info.ho << " " << SV->info.ten;
	gotoxy(58, 16);
	cout << "DIEM THI: " << diem;
	gotoxy(58, 18);
	cout << "SO CAU DUNG: " << so_cau_dung << '/' << so_cau;
	return diem;
}
string VeKhungNhapThi(int tong_so_cau, int &so_cau, int &thoi_gian)
{
	system("cls");
	VeKhung(57, 12, 100, 20);
	gotoxy(58, 14);
	cout << "SO CAU HOI:";
	gotoxy(58, 16);
	cout << "THOI GIAN:";
	gotoxy(58, 18);
	cout << "SO CAU TOI THIEU: 1| SO CAU TOI DA:" << tong_so_cau;
	do
	{
		gotoxy(69, 14);
		cout << "   ";
		so_cau = NhapSo(69, 14, 3);
		if (so_cau > tong_so_cau)
			THONGBAO(1, "NHAP NHIEU HON SO CAU CO SAN"); // in so cau ra nua
		if (so_cau == 0)
			THONGBAO(1, "SO CAU =0 KHONG HOP LE");
		if (so_cau == -1)
		{
			if (THONGBAO(3, "BAN MUON THOAT KHONG"))
				return "ESC";
		}
	} while (so_cau > tong_so_cau || so_cau == 0 || so_cau == -1);
	do
	{
		thoi_gian = NhapSo(69, 16, 3);
		if (thoi_gian == 0)
		{
			THONGBAO(1, "THOI GIAN PHAI LON HON 0");
		}
		if (thoi_gian == -1)
		{
			if (THONGBAO(3, "BAN CO MUON THOAT KHONG"))
				return "ESC";
		}
		else
			continue;
	} while (thoi_gian == 0 || thoi_gian == -1);
	return "NOTHING";
}
void ThanhChucNang(int option)
{
	VeKhung(5, 34, 115, 36);
	gotoxy(6, 35);
	switch (option)
	{
	case 0:
	{
		cout << "  ESC: DUNG THI(NOP BAI)     ENTER: CHON DAP AN     <-: CAU TRUOC     ->: CAU SAU     " << char(30) << ":LEN     " << char(31) << ":XUONG ";
		break;
	}
	case 1:
	{
		cout << "ESC: THOAT           F1: TIM CAU HOI          F5: TAI LAI          <-: LUI TRANG          ->: TRANG MOI   ";
		break;
	}
	case 2:
	{
		cout << "          ESC: THOAT           F5: TIM CAU HOI               <-: LUI TRANG                  ->: TRANG MOI ";
		break;
	}
	case 3:
	{
		cout << "ESC:THOAT   F1:TIM CAU HOI   F5:TAI LAI TRANG  ENTER:CHON   <-: LUI TRANG   ->: TRANG MOI   " << char(30) << ":LEN   " << char(31) << ":XUONG ";
		break;
	}
	case 4:
	{
		cout << "ESC:THOAT     ENTER:CHON     ->: QUAY LAI      " << char(30) << ":LEN      " << char(31) << ":XUONG    HUONG DAN: DAP AN CHON LA A,B,C,D";
		break;
	}
	case 5: // menu_dslh_gv
	{
		cout << "ESC:THOAT  F1:TIM LOP  F2:SAP XEP  F5:TAI LAI  PgUp/PgDn:DOI TRANG  < / > / " << char(30) << " / " << char(31) << ": DI CHUYEN   ENTER: XEM LOP";
		break;
	}
	case 6: // menu_dslh_gv (selection mode)
	{
		cout << "ESC: THOAT   F1: TIM LOP   F2: SAP XEP   F5: TAI LAI   PgUp/PgDn: DOI TRANG    " << char(30) << " / " << char(31) << ": DI CHUYEN   ENTER: CHON";
		break;
	}
	case 7: // menu_dssv_gv
	{
		cout << "ESC:THOAT  F1:TIM SV  F2:SAP XEP  F5: TAI LAI  PgUp/PgDn:DOI TRANG  < / > / " << char(30) << " / " << char(31) << ":DI CHUYEN   ENTER: XEM DIEM";
		break;
	}
	case 8: // menu_dssv_gv (selection mode)
	{
		cout << "ESC: THOAT   F1: TIM SV   F2: SAP XEP   F5: TAI LAI   PgUp/PgDn: DOI TRANG    " << char(30) << " / " << char(31) << ": DI CHUYEN   ENTER: CHON";
		break;
	}
	case 9: // menu_dsmh_gv
	{
		cout << "ESC:THOAT  F1:TIM MON  F5:TAI LAI   PgUp/PgDn:DOI TRANG    < / > / " << char(30) << " / " << char(31) << ": DI CHUYEN   ENTER: XEM DSCH CUA MON";
		break;
	}
	case 10: // menu_dsmh (selection mode)
	{
		delete_AreaOnScreen(5, 34, 111, 3);
		VeKhung(5, 34, 90, 36);
		gotoxy(6, 35);
		cout << "ESC:THOAT  F1:TIM MON  F5:TAI LAI   PgUp/PgDn:DOI TRANG   " << char(30) << "/" << char(31) << ":DI CHUYEN   ENTER:CHON";
		break;
	}
	case 11: // THEMSINHVIEN
	{
		delete_AreaOnScreen(5, 34, 111, 3);
		VeKhung(5, 34, 90, 36);
		gotoxy(6, 35);
		cout << "ESC: THOAT   F1: CHON LOP                                              ENTER: CHON";
		break;
	}
	case 12: // menu_dsdt_gv
	{
		delete_AreaOnScreen(5, 34, 111, 3);
		VeKhung(5, 34, 90, 36);
		gotoxy(6, 35);
		cout << "ESC: THOAT        PgUp/PgDn: DOI TRANG        " << char(30) << " / " << char(31) << ": DI CHUYEN   ENTER: XEM CHI TIET";
		break;
	}
	case 13: // menu_dsdt_gv (case: SV)
	{
		cout << "ESC: THOAT                                PgUp/PgDn: DOI TRANG                               " << char(30) << " / " << char(31) << ": DI CHUYEN";
		break;
	}
	case 14: // dsdt theo lan thi
	{
		delete_AreaOnScreen(5, 34, 111, 3);
		VeKhung(5, 34, 90, 36);
		gotoxy(6, 35);
		cout << "ESC: THOAT        PgUp/PgDn: DOI TRANG        " << char(30) << " / " << char(31) << ": DI CHUYEN   ENTER: XEM DSCH THI";
		break;
	}
	case 15: // menu_GV // menu_SV
	{
		delete_AreaOnScreen(5, 34, 111, 3);
		VeKhung(30, 34, 115, 36);
		gotoxy(31, 35);
		cout << "ESC: THOAT                       " << char(30) << " / " << char(31) << ": DI CHUYEN                     ENTER: CHON";
		break;
	}
	case 16: // login
		break;
	case 17:
	{
		cout << "                              ESC: HUY CAU HOI     HUONG DAN: NHAP DAP AN LA A,B,C,D           ";
	}
	}
}