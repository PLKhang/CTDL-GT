#include"XuLyGiaoDien.h"
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
int THONGBAO(int option,string thongbao){
	VeKhung(125,0,155,10);
	gotoxy(126,1);
	cout<<"         THONG BAO           ";
	gotoxy(126,2);
	cout<<"-----------------------------";
	gotoxy(126,3);
	cout<<thongbao;
	if(option==1)//clear thanh thong bao
	{
		Sleep(600);
		for(int i=0;i<=10;i++){
			gotoxy(125,i);
			cout<<"                               ";
		}
	}
	else if(option==2)//xoa noi dung vua thong bao
	{
		for(int i=3;i<=9;i++){
			gotoxy(126,i);
			cout<<"                              ";
		}
	}
	else if(option==3)//hien yes no
	{
		int yes_no=0,option=0;
		do{
			if(option==224)
			{
				option=getch();
				if(option==77)
				{
					gotoxy(135,8);
					TextColor(16);
					cout<<"  YES  ";
					TextColor(64);
					gotoxy(142,8);
					cout<<"   NO  ";
					yes_no=0;
					"aaa";
					continue;
				}
			}
			
				{
				gotoxy(135,8);
				TextColor(64);
				cout<<"  YES  ";
				TextColor(16);
				gotoxy(142,8);
				cout<<"   NO  ";
				yes_no=1;
				}
		}while((option=getch())!=13);
		TextColor(7);
		return yes_no;
	}
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
int MENUGV()
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
void VEBANGCAUHOI()
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
void VEKHUNGTHI()
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