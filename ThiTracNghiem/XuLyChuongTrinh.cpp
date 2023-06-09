#include "XuLyChuongTrinh.h"

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
	return -1;
}
string DANGNHAP()
{
	system("cls");
	string Name = "", Password = "", temp;
	int option = 0, stop = 0;
	chuThiTracNghiem(18, 2);
	VeKhung(40, 10, 105, 28);
	// VeKhung(41,11,104,27);
	SetBGColor(3);
	gotoxy(40, 10);
	cout << "                                                                  ";
	gotoxy(40, 28);
	cout << "                                                                  ";
	for (int i = 11; i <= 27; i++)
	{
		gotoxy(40, i);
		cout << "  ";
		gotoxy(104, i);
		cout << "  ";
	}
	SetBGColor(0);
	gotoxy(54, 15);
	TextColor(13);
	cout << "ACCOUNT";
	VeKhung(62, 14, 84, 16);
	gotoxy(54, 18);
	cout << "PASSWORD";
	VeKhung(62, 17, 84, 19);
	// VeKhung(68, 21, 78, 23);
	gotoxy(69, 22);
	cout << "DANG NHAP";
	delete_LineOnScreen(63, 15, 21);
	delete_LineOnScreen(63, 18, 21);
	ThanhChucNang(16);
	while (stop == 0)
	{
		switch (option)
		{
		case 0:
		{
			temp = NhapMa1(63, 15, 20, Name);
			if (temp == "DOWN" || temp == "DONE")
				option = 1;
			if (temp == "EXIT")
				return "EXIT";
			break;
		}
		case 1:
		{
			temp = NhapMa1(63, 18, 20, Password, "MATKHAU");
			if (temp == "UP")
				option = 0;
			if (temp == "DOWN" || temp == "DONE")
				option = 2;
			if (temp == "EXIT")
				return "EXIT";
			break;
		}
		case 2:
		{
			gotoxy(69, 22);
			SetBGColor(15);
			cout << "DANG NHAP";
			while (option = getch())
			{
				if (option == ENTER)
				{
					if (Name == "")
					{
						THONGBAO(2, "NAME EMPTY!");
						Sleep(500);
						option = 0;
					}
					else if (Password == "")
					{
						THONGBAO(2, "PASSWORD EMPTY!");
						Sleep(500);
						option = 1;
					}
					else
						stop = 1;
					gotoxy(69, 22);
					SetBGColor(0);
					cout << "DANG NHAP";
					break;
				}
				if (option == 224)
				{
					option = getch();
					if (option == UP)
					{
						option = 1;
						gotoxy(69, 22);
						SetBGColor(0);
						cout << "DANG NHAP";
						break;
					}
				}
				if (option == ESC)
					return "EXIT";
			}
			break;
		}
		}
	}
	switch (KiemTraTK(Name, Password))
	{
	case -1:
		THONGBAO(2, "KHONG CO TAI KHOAN");
		return "NONE";
	case 0:
		THONGBAO(2, "KHONG DOC DUOC FILE");
		return "READ FILE ERROR";
	case 1:
		// THONGBAO(2, "LOGIN SV");
		return Name;
	case 2:
		// THONGBAO(2, "LOGIN GV");
		return "GV";
	}
}
int MENU_GV()
{
	system("cls");
	chuMenuGV(30, 1);
	gotoxy(60, 15);
	TextColor(20);
	cout << "      DANH SACH CAC LOP     ";
	TextColor(112);
	gotoxy(60, 17);
	cout << "      THEM SINH VIEN        ";
	gotoxy(60, 19);
	cout << "      DANH SACH MON HOC     ";
	gotoxy(60, 21);
	cout << "      BANG DIEM             ";
	gotoxy(60, 23);
	cout << "      THI THU               ";
	gotoxy(60, 25);
	cout << "      THOAT                 ";
	TextColor(7);
	ThanhChucNang(15);

	int chon, vi_tri_contro = 15, wherey = 15;

	while (1)
	{
		chon = getch();
		switch (chon)
		{
		case ENTER:
		{
			switch (vi_tri_contro)
			{
			case 15:
				return 1;
			case 17:
				return 2;
			case 19:
				return 3;
			case 21:
				return 4;
			case 23:
				return 5;
			case 25:
				return 6;
			}
		}
		case ESC:
			if (THONGBAO(3, "BAN CO MUON THOAT KHONG"))
				return 0;
		case 224:
		{
			chon = getch();
			if (chon == UP && vi_tri_contro != 15)
			{
				wherey = vi_tri_contro;
				vi_tri_contro -= 2;
			}
			else if (chon == DOWN && vi_tri_contro != 25)
			{
				wherey = vi_tri_contro;
				vi_tri_contro += 2;
			}
			else
				continue;

			TextColor(112);
			switch (wherey) // wherey la vi tri cu cua vi_tri_contro de to lai
			{
			case 15:
			{
				gotoxy(60, 15);
				cout << "      DANH SACH CAC LOP     ";
				break;
			}
			case 17:
			{
				gotoxy(60, 17);
				cout << "      THEM SINH VIEN        ";
				break;
			}
			case 19:
			{
				gotoxy(60, 19);
				cout << "      DANH SACH MON HOC     ";
				break;
			}
			case 21:
			{
				gotoxy(60, 21);
				cout << "      BANG DIEM             ";
				break;
			}
			case 23:
			{
				gotoxy(60, 23);
				cout << "      THI THU               ";
				break;
			}
			case 25:
			{
				gotoxy(60, 25);
				cout << "      THOAT                 ";
				break;
			}
			}

			TextColor(20);
			switch (vi_tri_contro) // to vi tri moi
			{
			case 15:
			{
				gotoxy(60, 15);
				cout << "      DANH SACH CAC LOP     ";
				break;
			}
			case 17:
			{
				gotoxy(60, 17);
				cout << "      THEM SINH VIEN        ";
				break;
			}
			case 19:
			{
				gotoxy(60, 19);
				cout << "      DANH SACH MON HOC     ";
				break;
			}
			case 21:
			{
				gotoxy(60, 21);
				cout << "      BANG DIEM             ";
				break;
			}
			case 23:
			{
				gotoxy(60, 23);
				cout << "      THI THU               ";
				break;
			}
			case 25:
			{
				gotoxy(60, 25);
				cout << "      THOAT                 ";
				break;
			}
			}
			TextColor(7);
		}
		}
	}
}
int MENU_SV(string maLop, PtrSV &p)
{
	system("cls");
	VeKhung(25, 7, 125, 10);
	chuMenuSV(32, 2);
	// cho nay them vao maLop sao khi doc va tro toi ma lop cua TKSV
	gotoxy(30, 9);
	cout << maLop;
	// cho nay them vao maSSV sao khi doc va tro toi ma lop cua TKSV
	gotoxy(50, 9);
	cout << p->info.MSSV;
	// cho nay them vao tenSV sao khi doc va tro toi ma lop cua TKSV
	gotoxy(73, 9);
	cout << p->info.ho << " " << p->info.ten;
	// cho nay them vao gioiTinh sao khi doc va tro toi ma lop cua TKSV
	gotoxy(110, 9);
	cout << (p->info.phai ? "NU" : "NAM");
	gotoxy(60, 15);
	TextColor(20); //
	cout << "      THI                   ";
	TextColor(112);
	gotoxy(60, 17);
	cout << "      XEM DIEM              ";
	gotoxy(60, 19);
	cout << "      THOAT                 ";
	TextColor(7);
	ThanhChucNang(15);
	//
	int chon, vi_tri_contro = 15;
	while (1)
	{
		chon = getch();
		switch (chon)
		{
			/////////////////////////
		case ENTER:
		{
			switch (vi_tri_contro)
			{
			case 15:
				return 1;
			case 17:
				return 2;
			case 19:
				return 3;
			}
		}
			///////////////////////////////
		case ESC:
		{
			if (THONGBAO(3, "BAN CO MUON THOAT KHONG") == 1)
				return 0;
		}
			//////////////////////////////////
		case 224:
		{
			chon = getch();
			switch (chon)
			{
			case UP:
			{
				if (vi_tri_contro != 15)
				{
					if (vi_tri_contro == 17)
					{
						vi_tri_contro = 15;
						gotoxy(60, 15);
						TextColor(20);
						cout << "      THI                   ";
						TextColor(112);
						gotoxy(60, 17);
						cout << "      XEM DIEM              ";
					}
					else
					{
						vi_tri_contro = 17;
						TextColor(20);
						gotoxy(60, 17);
						cout << "      XEM DIEM              ";
						TextColor(112);
						gotoxy(60, 19);
						cout << "      THOAT                 ";
					}
					TextColor(7);
				}
				break;
			}
			case DOWN:
			{
				if (vi_tri_contro != 19)
				{
					if (vi_tri_contro == 15)
					{
						vi_tri_contro = 17;
						gotoxy(60, 15);
						TextColor(112);
						cout << "      THI                   ";
						TextColor(20);
						gotoxy(60, 17);
						cout << "      XEM DIEM              ";
					}
					else
					{
						vi_tri_contro = 19;
						TextColor(112);
						gotoxy(60, 17);
						cout << "      XEM DIEM              ";
						TextColor(20);
						gotoxy(60, 19);
						cout << "      THOAT                 ";
					}
					TextColor(7);
				}
				break;
			}
			}
			break;
		}
		}
	}
}

//********************************************PHUONG****************************************************//
int stopThi = 0; // stop=1 thi dung thi
void DongHo(int time)
{
	int giay;
	VeKhung(55, 1, 79, 3);
	gotoxy(56, 2);
	cout << "TIME:";
	while (time > 0)
	{
		gotoxy(63, 2);
		cout << right << setw(2) << setfill('0') << time;
		gotoxy(65, 2);
		cout << ":phut  ";
		gotoxy(72, 2);
		cout << "00";
		gotoxy(74, 2);
		cout << ":giay";
		Sleep(1000);
		gotoxy(63, 2);
		cout << time--;
		giay = 59;

		while (giay >= 0)
		{
			SetColor(0, 7);
			gotoxy(63, 2);
			cout << right << setw(2) << setfill('0') << time;
			gotoxy(65, 2);
			cout << ":phut  ";
			gotoxy(72, 2);
			cout << right << setw(2) << setfill('0') << giay--;
			gotoxy(74, 2);
			cout << ":giay|";
			Sleep(1000);
			if (stopThi == 1)
				return;
		}
	}
	THONGBAO(0, "       HET THOI GIAN- NHAN PHIM BAT KI DE THOAT");
	stopThi = 1;
}

int InCauHoiThi(STreeCH &Question, char YourAnswer, int current_index, int so_cau, int option)
{
	// DUNG CHO IN CAU HOI THI VA DE XEM CAU HOI DA THI
	Sleep(300);
	XoaVungThi();
	char temp[95];
	int Your_index, Answer_index;
	switch (YourAnswer)
	{
	case '\0':
	{
		Your_index = 0;
		break;
	}
	case 'A':
	{
		Your_index = 10;
		break;
	}
	case 'B':
	{
		Your_index = 14;
		break;
	}
	case 'C':
	{
		Your_index = 18;
		break;
	}
	case 'D':
	{
		Your_index = 22;
		break;
	}
	}
	if (option == 1)
	{
		switch (Question->info.answer)
		{
		case 'A':
		{
			Answer_index = 10;
			break;
		}
		case 'B':
		{
			Answer_index = 14;
			break;
		}
		case 'C':
		{
			Answer_index = 18;
			break;
		}
		case 'D':
		{
			Answer_index = 22;
			break;
		}
		}
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
	else // ch? d? xem câu h?i dã thi
	{
		if (Your_index != 0)
		{
			if (Your_index != Answer_index)
			{
				// tô dáp án b?n chon
				SetColor(4, 0);
				gotoxy(6, Your_index);
				cout << "         ";
				gotoxy(6, Your_index + 1);
				cout << "         ";
				gotoxy(6, Your_index + 2);
				cout << "         ";
			}
		}
		// tô dáp án dúng
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
		if (Your_index != 0&&Your_index != Answer_index)// TRU?NG H?P CÓ CH?N VÀ KHÁC K?T QU?
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
	//VeKhungCauHoi(Your_index, Answer_index, option);
	VeKhung(5, 27, 20, 29); // ve khung dap an ban chon
	if (YourAnswer == '\0')
	{
		gotoxy(6, 28);
		cout << "BAN CHUA CHON";
	}
	else
	{
		gotoxy(6, 28);
		cout << "BAN CHON " << YourAnswer << "   ";
	}

	gotoxy(6, 6);
	if (strlen(Question->info.question) < 110)
		cout << Question->info.question; // IN CAU HOI
	else
	{
		strncpy(temp, Question->info.question, 109); // copy 119 ki tu 0->118
		cout << temp;
		gotoxy(6, 7);
		cout << &Question->info.question[109];
	}
	gotoxy(16, 10);
	cout << Question->info.ans1; // IN CAU A
	gotoxy(16, 14);
	cout << Question->info.ans2; // IN CAU B
	gotoxy(16, 18);
	cout << Question->info.ans3; // IN CAU C
	gotoxy(16, 22);
	cout << Question->info.ans4; // IN CAU D
	gotoxy(110, 26);
	cout << "      ";
	gotoxy(110, 26);
	cout << current_index + 1 << '/' << so_cau;
	if (Your_index == 0)
		Your_index = 10;
	return Your_index;
}
string NhapSC_TG(int &so_cau, int &thoi_gian, int soluongcauhoi, PtrSV &SV)
{
	int option = 0, check_empty = 0;
	string temp;
	system("cls");
	VeKhung(57, 12, 97, 22);
	gotoxy(58, 14);
	cout << "HO VA TEN: " << SV->info.ho << " " << SV->info.ten;
	gotoxy(58, 16);
	cout << "SO CAU HOI:";
	gotoxy(58, 18);
	cout << "THOI GIAN:";
	gotoxy(58, 20);
	cout << "SO CAU TOI THIEU: 1| SO CAU TOI DA:" << soluongcauhoi;
	while (1)
	{
		switch (option)
		{
		case 0:
		{
			check_empty = 0;
			temp = NhapSo1(70, 16, 3, so_cau);
			if (temp.compare("EMPTY") == 0)
				check_empty = 1;
			if (temp.compare("DOWN") == 0 || temp.compare("DONE") == 0 || temp.compare("EMPTY") == 0)
				option = 1;
			break;
		}
		case 1:
		{
			temp = NhapSo1(70, 18, 2, thoi_gian);
			if (temp.compare("UP") == 0)
				option = 0;
			if (temp.compare("EMPTY") == 0)
				THONGBAO(2, "THOI GIAN TRONG");
			if (temp.compare("DONE") == 0)
			{
				if (check_empty == 1)
				{
					THONGBAO(2, "SO CAU TRONG");
					gotoxy(70, 16);
					cout << "  ";
					if (thoi_gian == 0)
					{
						gotoxy(70, 18);
						cout << "  ";
					}
					option = 0;
					break;
				}
				if (so_cau == 0)
				{
					THONGBAO(2, "SO CAU PHAI > 0");
					gotoxy(70, 16);
					cout << "  ";
					option = 0;
					break;
				}
				if (so_cau > soluongcauhoi)
				{
					THONGBAO(2, "SO CAU PHAI <= TONG SO CAU");
					option = 0;
					break;
				}
				if (thoi_gian == 0 || thoi_gian > 60)
				{
					THONGBAO(2, "THOI GIAN THI-0 < X <= 60 (PHUT)");
					gotoxy(70, 18);
					cout << "  ";
					thoi_gian = 0;
					option = 1;
					break;
				}
				return "DONE";
			}
			break;
		}
		}
		if (temp.compare("EXIT") == 0 && THONGBAO(3, "BAN CO MUON THOAT KHONG?"))
			return "EXIT";
	}
}
void Thi(STreeCH &root, PtrSV &SV, ListMH &dsmh)
{
	stopThi = 0;
	int so_cau = 0, thoi_gian = 0, soluongcauhoi, chon, index, wherey;
	char maMH[16], *YourAnswer;
	STreeCH *Questions = NULL;
	thread timer;
	do
	{
		strcpy(maMH, MENU_DSMH_GV(root, dsmh, 2, SV).data());
		if (strcmp(maMH, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY THAO TAC?"))
				return;
		}
		soluongcauhoi = DemSoCauHoi(root, maMH);
		if (soluongcauhoi == 0)
			THONGBAO(2, "KHONG CO CAU HOI");
	} while (soluongcauhoi == 0);

	if (NhapSC_TG(so_cau, thoi_gian, soluongcauhoi, SV).compare("EXIT") == 0)
		return;

	YourAnswer = new char[so_cau];
	Questions = GetQuestion(root, maMH, so_cau, soluongcauhoi);
	for (int i = 0; i < so_cau; i++)
		Questions[i]->is_used = true;
	for (int i = 0; i < so_cau; i++)
		YourAnswer[i] = '\0';
	system("cls");
	ThanhChucNang(0);
	VeKhungCauHoi();
	timer = thread(DongHo, thoi_gian);
	for (int i = 0; stopThi != 1;)
	{
		index = wherey = InCauHoiThi(Questions[i], YourAnswer[i], i, so_cau);
		// XEM LUA CHON
		while (1)
		{
			chon = getch(); // LAY KI TU TU BAN PHIM
			if (stopThi == 1)
			{
				if (chon == 224)
					getch();
				break;
			}
			if (chon == ESC) // NHAN ESC
			{
				stopThi = THONGBAO(3, "BAN CO MUON THOAT KHONG"); // NEU THOAT THI STOP=1 VA THOAT
				break;
			}
			else if (chon == ENTER) // PHAT HIEN NHAN ENTER VA KIEM TRA DAP AN
			{
				switch (index)
				{
				case 10:
				{
					YourAnswer[i] = 'A';
					break;
				}
				case 14:
				{
					YourAnswer[i] = 'B';
					break;
				}
				case 18:
				{
					YourAnswer[i] = 'C';
					break;
				}
				case 22:
				{
					YourAnswer[i] = 'D';
					break;
				}
				}
				gotoxy(6, 28);
				cout << "BAN CHON " << YourAnswer[i] << "   ";
				// i++; // qua trang moi
				continue;
			}
			else if (chon == 224)
			{
				chon = getch();
				// KIEM TRA CO NHAN NUT LEN HAY KHONG VA INDEX KHONG O TAI CAU A
				if (chon == UP && index != 10)
				{
					wherey = index;
					index -= 4;
				}
				// NUT XUONG VA INDEX KHONG TAI CAU D
				else if (chon == DOWN && index != 22)
				{
					wherey = index;
					index += 4;
				}
				else if (chon == LEFT && i > 0)
				{
					i--;
					break;
				} // lui trang
				else if (chon == RIGHT && i < so_cau - 1)
				{
					i++;
					break;
				} // qua trang
				else
					continue;
			}
			else
				continue;

			// TO LAI MAU TRANG
			SetColor(0, 7);
			gotoxy(6, wherey);
			cout << "         ";
			gotoxy(6, wherey + 1);
			cout << "         ";
			gotoxy(6, wherey + 2);
			cout << "         ";
			// VIET LAI DAP AN
			switch (wherey)
			{
			case 10:
			{
				gotoxy(10, wherey);
				cout << "A";
				break;
			}
			case 14:
			{
				gotoxy(10, wherey);
				cout << "B";
				break;
			}
			case 18:
			{
				gotoxy(10, wherey);
				cout << "C";
				break;
			}
			case 22:
			{
				gotoxy(10, wherey);
				cout << "D";
				break;
			}
			}
			// TO MAU XANH
			SetColor(2, 0);
			gotoxy(6, index);
			cout << "         ";
			gotoxy(6, index + 1);
			cout << "         ";
			gotoxy(6, index + 2);
			cout << "         ";
			// TO MAU XANH
			switch (index)
			{
			case 10:
			{
				gotoxy(10, index);
				cout << "A";
				break;
			}
			case 14:
			{
				gotoxy(10, index);
				cout << "B";
				break;
			}
			case 18:
			{
				gotoxy(10, index);
				cout << "C";
				break;
			}
			case 22:
			{
				gotoxy(10, index);
				cout << "D";
				break;
			}
			}
			SetColor(0, 7); // DAT LAI MAU CHU VA Nï¿½N
		}
	}
	stopThi = 1;
	timer.join();
	GhiCauHoiDaThi(SV->info.MSSV, Questions, YourAnswer, so_cau);
	DiemThi info;
	strcpy(info.maMonHoc, maMH);
	info.diemThi = VeKhungDiem(Questions, YourAnswer, SV, so_cau);
	insert_Order_DT(SV->info.danhSachDiemThi, info);
	THONGBAO(0, "NHAN PHIM BAT KY DE THOAT");
	getch();
	delete[] Questions;
	delete[] YourAnswer;
}
STreeCH ThemCauHoi(STreeCH &root, char maMH[], char tenMH[])
{
	int option = 0, stop = 0;
	char answer = '\0';
	string temp, question = "", ans1 = "", ans2 = "", ans3 = "", ans4 = "";
	STreeCH NewQuestion = newnode();
	ReadID(NewQuestion->info.ID, 1);
	VeKhungCauHoi1(tenMH, NewQuestion->info.ID);
	ThanhChucNang(17);
	while (stop == 0)
	{
		switch (option)
		{
		case 0:
		{
			temp = NhapChuoi1(21, 10, 188, question);
			if (temp.compare("DONE") == 0 || temp.compare("DOWN") == 0)
				option = 1;
			break;
		}
		case 1:
		{
			temp = NhapChuoi1(21, 13, 94, ans1);
			if (temp.compare("DONE") == 0 || temp.compare("DOWN") == 0)
				option = 2;
			if (temp.compare("UP") == 0)
				option = 0;
			break;
		}
		case 2:
		{
			temp = NhapChuoi1(21, 16, 94, ans2);
			if (temp.compare("DONE") == 0 || temp.compare("DOWN") == 0)
				option = 3;
			if (temp.compare("UP") == 0)
				option = 1;
			break;
		}
		case 3:
		{
			temp = NhapChuoi1(21, 19, 94, ans3);
			if (temp.compare("DONE") == 0 || temp.compare("DOWN") == 0)
				option = 4;
			if (temp.compare("UP") == 0)
				option = 2;
			break;
		}
		case 4:
		{
			temp = NhapChuoi1(21, 22, 94, ans4);
			if (temp.compare("DONE") == 0 || temp.compare("DOWN") == 0)
				option = 5;
			if (temp.compare("UP") == 0)
				option = 3;
			break;
		}
		case 5:
		{
			temp = NhapDapAn(21, 25, answer);
			if (temp.compare("DONE") == 0)
			{
				if (question.compare("") == 0)
				{
					THONGBAO(2, "NOI DUNG TRONG!");
					option = 0;
					break;
				}
				if (ans1.compare("") == 0)
				{
					THONGBAO(2, "LUA CHON 1 TRONG");
					option = 1;
					break;
				}
				if (ans2.compare("") == 0)
				{
					THONGBAO(2, "LUA CHON 2 TRONG");
					option = 2;
					break;
				}
				if (ans3.compare("") == 0)
				{
					THONGBAO(2, "LUA CHON 3 TRONG");
					option = 3;
					break;
				}
				if (ans4.compare("") == 0)
				{
					THONGBAO(2, "LUA CHON 4 TRONG");
					option = 4;
					break;
				}
				if (answer == '\0')
				{
					THONGBAO(2, "DAP AN TRONG");
					option = 5;
					break;
				}
				stop = 1;
			}
			else if (temp.compare("UP") == 0)
				option = 4;
			break;
		}
		}
		if (temp.compare("EXIT") == 0 && THONGBAO(3, "BAN CO MUON HUY KHONG"))
		{
			THONGBAO(2, "HUY CAU HOI THANH CONG");
			delete NewQuestion;
			return NULL;
		}
	}
	strcpy(NewQuestion->info.maMonHoc, maMH);
	strcpy(NewQuestion->info.question, question.data());
	strcpy(NewQuestion->info.ans1, ans1.data());
	strcpy(NewQuestion->info.ans2, ans2.data());
	strcpy(NewQuestion->info.ans3, ans3.data());
	strcpy(NewQuestion->info.ans4, ans4.data());
	NewQuestion->info.answer = answer;
	NewQuestion->is_used = false;
	if (InsertNewQuestion(root, NewQuestion))
		THONGBAO(2, "THEM CAU HOI-THANH CONG");
	else
		THONGBAO(2, "THEM CAU HOI-KHONG THANH CONG");
	return NewQuestion;
}
void InCauHoi(STreeCH &ExsistQuestion, char tenMH[])
{
	char temp[95]; // 94 ki tu+ ki tu '\0'
	VeKhungCauHoi1(tenMH, ExsistQuestion->info.ID);
	gotoxy(21, 10);
	if (strlen(ExsistQuestion->info.question) <= 94)
		cout << ExsistQuestion->info.question;
	else
	{
		strncpy(temp, ExsistQuestion->info.question, 94); // copy 94 ki tu 0->93
		cout << temp;
		gotoxy(21, 11);
		cout << &ExsistQuestion->info.question[94]; // in tu ki tu 94->188
	}
	gotoxy(21, 13);
	cout << ExsistQuestion->info.ans1;
	gotoxy(21, 16);
	cout << ExsistQuestion->info.ans2;
	gotoxy(21, 19);
	cout << ExsistQuestion->info.ans3;
	gotoxy(21, 22);
	cout << ExsistQuestion->info.ans4;
	gotoxy(21, 25);
	cout << ExsistQuestion->info.answer;
}
int XemCauHoi(STreeCH &root, STreeCH &ExsistQuestion, char tenMH[])
{
	int chon, vi_tri_contro = 16, stop = 0, check_change = 0;
	string temp, question, ans1, ans2, ans3, ans4;
	char answer;
	InCauHoi(ExsistQuestion, tenMH);
	TextColor(20);
	gotoxy(120, 16);
	cout << "     HIEU CHINH         ";
	TextColor(112);
	gotoxy(120, 19);
	cout << "     XOA CAU HOI        ";
	SetColor(0, 7);
	ThanhChucNang(4);
	while (stop != 1)
	{
		chon = getch();
		switch (chon)
		{
		case ENTER:
		{
			if (vi_tri_contro == 16)
			{
				TextColor(112);
				gotoxy(120, 16);
				cout << "     HIEU CHINH         ";
				TextColor(112);
				gotoxy(120, 19);
				cout << "     XOA CAU HOI        ";
				SetColor(0, 7);
				chon = 0;
				question = ExsistQuestion->info.question;
				ans1 = ExsistQuestion->info.ans1;
				ans2 = ExsistQuestion->info.ans2;
				ans3 = ExsistQuestion->info.ans3;
				ans4 = ExsistQuestion->info.ans4;
				answer = ExsistQuestion->info.answer;
				while (1)
				{
					switch (chon)
					{
					case 0:
					{
						temp = NhapChuoi1(21, 10, 188, question);
						if (temp.compare("DOWN") == 0 || temp.compare("DONE") == 0)
							chon = 1;
						if (strcmp(ExsistQuestion->info.question, question.data()) != 0)
							check_change = 1;
						break;
					}
					case 1:
					{
						temp = NhapChuoi1(21, 13, 94, ans1);
						if (strcmp(ExsistQuestion->info.ans1, ans1.data()) != 0)
							check_change = 1;
						if (temp.compare("UP") == 0)
							chon = 0;
						if (temp.compare("DOWN") == 0 || temp.compare("DONE") == 0)
							chon = 2;
						break;
					}
					case 2:
					{
						temp = NhapChuoi1(21, 16, 94, ans2);
						if (temp.compare("UP") == 0)
							chon = 1;
						if (temp.compare("DOWN") == 0 || temp.compare("DONE") == 0)
							chon = 3;
						if (strcmp(ExsistQuestion->info.ans2, ans2.data()) != 0)
							check_change = 1;
						break;
					}
					case 3:
					{
						temp = NhapChuoi1(21, 19, 94, ans3);
						if (temp.compare("UP") == 0)
							chon = 2;
						if (temp.compare("DOWN") == 0 || temp.compare("DONE") == 0)
							chon = 4;
						if (strcmp(ExsistQuestion->info.ans3, ans3.data()) != 0)
							check_change = 1;
						break;
					}
					case 4:
					{
						temp = NhapChuoi1(21, 22, 94, ans4);
						if (temp.compare("UP") == 0)
							chon = 3;
						if (temp.compare("DOWN") == 0 || temp.compare("DONE") == 0)
							chon = 5;
						if (strcmp(ExsistQuestion->info.ans4, ans4.data()) != 0)
							check_change = 1;
						break;
					}
					case 5:
					{
						temp = NhapDapAn(21, 25, answer);
						if (temp.compare("UP") == 0)
							chon = 4;
						if (ExsistQuestion->info.answer != answer)
							check_change = 1;
						break;
					}
					}
					if (temp.compare("EXIT") == 0)
					{
						if (check_change == 1 && THONGBAO(3, "BAN CO MUON LUU KHONG") == 1)
						{
							strcpy(ExsistQuestion->info.question, question.data());
							strcpy(ExsistQuestion->info.ans1, ans1.data());
							strcpy(ExsistQuestion->info.ans2, ans2.data());
							strcpy(ExsistQuestion->info.ans3, ans3.data());
							strcpy(ExsistQuestion->info.ans4, ans4.data());
						}
						return 0;
					}
					if (temp.compare("RIGHT") == 0)
						break;
				}
				TextColor(20);
				gotoxy(120, 16);
				cout << "     HIEU CHINH         ";
				TextColor(112);
				gotoxy(120, 19);
				cout << "     XOA CAU HOI        ";
				SetColor(0, 7);
			}
			else
			{
				if (ExsistQuestion->is_used == true)
				{
					THONGBAO(2, "   CAU HOI DA DUOC THI-     KHONG XOA DUOC!");
				}
				else if (THONGBAO(3, "BAN CO MUON XOA"))
				{
					DeleteQuestion(root, ExsistQuestion);
					return 1;
				}
			}
			break;
		}
		case ESC:
		{
			stop = 1;
			if (check_change == 1)
			{
				if (THONGBAO(3, "BAN CO MUON LUU KHONG") == 1)
				{
					strcpy(ExsistQuestion->info.question, question.data());
					strcpy(ExsistQuestion->info.ans1, ans1.data());
					strcpy(ExsistQuestion->info.ans2, ans2.data());
					strcpy(ExsistQuestion->info.ans3, ans3.data());
					strcpy(ExsistQuestion->info.ans4, ans4.data());
				}
			}
			break;
		}
		case 0:
		case 224:
		{
			chon = getch();
			if (chon == UP && vi_tri_contro != 16)
			{
				TextColor(20);
				gotoxy(120, 16);
				cout << "     HIEU CHINH         ";
				TextColor(112);
				gotoxy(120, 19);
				cout << "     XOA CAU HOI        ";
				vi_tri_contro = 16;
			}
			else if (chon == DOWN && vi_tri_contro != 19)
			{
				TextColor(112);
				gotoxy(120, 16);
				cout << "     HIEU CHINH         ";
				TextColor(20);
				gotoxy(120, 19);
				cout << "     XOA CAU HOI        ";
				vi_tri_contro = 19;
			}
			TextColor(7);
			break;
		}
		}
	}
	return 0;
}
void InDanhSachCH(Array<STreeCH> &ListQuestion, char maMH[], int NumberQuestion, int Page, int MaxPage)
{
	int wherey = 10;
	char chuoi[90];
	XoaVungDanhSachCauHoi();
	for (int i = (Page - 1) * 10; i <= (Page * 10 < NumberQuestion ? Page * 10 - 1 : NumberQuestion - 1); i++)
	{
		gotoxy(6, wherey);
		cout << ListQuestion[i]->info.ID;
		gotoxy(21, wherey);
		if (strlen(ListQuestion[i]->info.question) < 94)
			cout << ListQuestion[i]->info.question;
		else
		{
			strncpy(chuoi, ListQuestion[i]->info.question, 91);
			cout << chuoi << "...";
		}
		wherey += 2;
	}
	gotoxy(116, 28);
	SetColor(5, 6);
	cout << "Page " << Page << '/' << MaxPage;
	SetColor(0, 7);
}

int TimCauHoi(Array<STreeCH> &List, int &NumberQuestion, char *YourAnswer)
{
	// 0 la ko co|| 1: la co ||27 Ban Muon thoat
	string content;
	char *address = NULL;
	VeKhung(5, 30, 115, 33);
	gotoxy(6, 31);
	cout << "NHAP NOI DUNG |";
	gotoxy(6, 32);
	cout << "  CAN TIM     |";
	content = NhapChuoi(21, 31, 188, 1);
	delete_LineOnScreen(5, 30, 112);
	delete_LineOnScreen(5, 31, 112);
	delete_LineOnScreen(5, 32, 112);
	delete_LineOnScreen(5, 33, 112);
	if (content.compare("EXIT") == 0)
		return 27;
	STreeCH ptr;
	int temp = 0;
	for (int i = 0; i < NumberQuestion; i++)
	{
		address = strstr(List[i]->info.question, content.data());
		if (address != NULL)
		{
			ptr = List[temp];
			List[temp] = List[i];
			List[i] = ptr;
			if (YourAnswer != NULL)
				swap(YourAnswer[i], YourAnswer[temp]);
			temp++;
		}
	}
	if (temp == 0)
		return 0;
	else
	{
		NumberQuestion = temp;
		return 1;
	}
}
void MENU_DSCH_GV(STreeCH &root, MonHoc &monHoc)
{
	system("cls");
	int NumberQuestion, vi_tri_contro, wherey, chon, MaxPage, Page, stop;
	char chuoi[90];
	NumberQuestion = DemSoCauHoi(root, monHoc.maMonHoc);
	Array<STreeCH> ListQuestion(NumberQuestion + 10);
	InTraversal(ListQuestion, root, monHoc.maMonHoc); // tim cau hoi và sắp câu hỏi theo ID
	Page = 1, MaxPage = (NumberQuestion - 1) / 10 + 1;
	VeBangDanhSachCauHoi(monHoc.maMonHoc, MaxPage, Page);
	while (1)
	{
		// XUAT NOI DUNG
		stop = 0, vi_tri_contro = 16;
		if (NumberQuestion == 0)
			THONGBAO(0, "KHONG CO CAU HOI");
		else
			InDanhSachCH(ListQuestion, monHoc.maMonHoc, NumberQuestion, Page, MaxPage);

		TextColor(20);
		gotoxy(120, 16);
		cout << "     THEM CAU HOI       ";
		TextColor(112);
		gotoxy(120, 19);
		cout << "     XEM CAU HOI        ";
		SetColor(0, 7);
		ThanhChucNang(3);
		// CHON LUA
		while (stop != 1)
		{
			chon = getch();
			switch (chon)
			{
			case ENTER:
			{
				switch (vi_tri_contro)
				{
				case 16:
				{
					STreeCH temp = ThemCauHoi(root, monHoc.maMonHoc, monHoc.tenMonHoc);
					VeBangDanhSachCauHoi(monHoc.maMonHoc, MaxPage, Page);
					if (temp == NULL)
					{
						stop = 1;
						break;
					}
					monHoc.is_used = true;
					ListQuestion.push(temp);
					NumberQuestion++;
					stop = 1, MaxPage = (NumberQuestion - 1) / 10 + 1;
					break;
				}
				case 19: // XEM CAU HOI
				{
					if (NumberQuestion == 0)
					{
						THONGBAO(2, "KHONG CO CAU HOI");
						break;
					}
					wherey = 10;																				  // muon wherey
					for (int i = (Page - 1) * 10; i < (Page * 10 < NumberQuestion ? Page * 10 : NumberQuestion);) // truong hop khong co cau hoi thi khong co con tro
					{
						gotoxy(3, wherey);
						cout << ">>";
						chon = getch();
						if (chon == ENTER)
						{
							if (XemCauHoi(root, ListQuestion[i], monHoc.tenMonHoc) == 1)
							{

								ListQuestion.erase(i);
								--NumberQuestion;
								monHoc.is_used = (NumberQuestion == 0 ? false : true);
								MaxPage = (NumberQuestion - 1) / 10 + 1;
								if (Page > MaxPage)
									Page = MaxPage;
							}
							VeBangDanhSachCauHoi(monHoc.maMonHoc, MaxPage, Page);
							stop = 1;
							break;
						}
						if (chon == ESC)
						{
							gotoxy(3, wherey);
							cout << "  ";
							break;
						}
						if (chon == 224)
						{
							chon = getch();
							if (chon == UP && wherey != 10)
							{
								gotoxy(3, wherey);
								cout << "  ";
								wherey -= 2;
								gotoxy(3, wherey);
								i--;
							}
							if (chon == DOWN && wherey != 28 && i < (Page * 10 < NumberQuestion ? Page * 10 : NumberQuestion) - 1)
							{
								gotoxy(3, wherey);
								cout << "  ";
								wherey += 2;
								gotoxy(3, wherey);
								i++;
							}
						}
					}
					break;
				}
				}
				// stop=1;
				break;
			}
			case 0:
			case 224:
			{
				chon = getch();
				switch (chon)
				{
				case F1:
				{
					chon = TimCauHoi(ListQuestion, NumberQuestion);
					if (chon == 0)
					{
						THONGBAO(2, "KHONG TIM THAY CAU HOI");
						break;
					}
					else if (chon == 27)
					{
						THONGBAO(2, "HUY TIM");
						break;
					}
					MaxPage = (NumberQuestion - 1) / 10 + 1, Page = 1; //?
					stop = 1;
					break;
				}
				case F5:
				{
					NumberQuestion = ListQuestion.GetIndexLast() + 1;
					if (NumberQuestion > 0)
						Sort(ListQuestion, 0, NumberQuestion - 1);
					MaxPage = (NumberQuestion - 1) / 10 + 1, Page = 1;
					stop = 1;
					break;
				}
				case UP:
				{
					if (vi_tri_contro != 16)
					{
						gotoxy(120, 16);
						TextColor(20);
						cout << "     THEM CAU HOI       ";
						gotoxy(120, 19);
						TextColor(112);
						cout << "     XEM CAU HOI        ";
						vi_tri_contro = 16;
					}
					break;
				}
				case DOWN:
				{
					if (vi_tri_contro != 19)
					{
						gotoxy(120, 16);
						TextColor(112);
						cout << "     THEM CAU HOI       ";
						gotoxy(120, 19);
						TextColor(20);
						cout << "     XEM CAU HOI        ";
						vi_tri_contro = 19;
					}
					break;
				}
				case LEFT:
				{
					if (Page != 1)
					{
						Page--;
						stop = 1;
					}
					break;
				}
				case RIGHT:
				{
					if (Page != MaxPage)
					{
						Page++;
						stop = 1;
					}
					break;
				}
				}
				TextColor(7);
				break;
			}
			case ESC:
			{
				if (THONGBAO(3, "BAN CO MUON THOAT KHONG")) // THOÁT
				{
					ListQuestion.destroy();
					system("cls");
					return;
				}
			}
			}
		}
	}
}

void InCauHoiDaThi(STreeCH root, MonHoc monHoc, char MSSV[])
{
	int NumberQuestion, chon, change = 0;
	NumberQuestion = demSoCauDaThi(monHoc, MSSV);
	if (NumberQuestion == 0)
	{
		THONGBAO(0, "CHUA THI");
		return;
	}
	Array<STreeCH> List(NumberQuestion);
	char *YourAnswer = new char[NumberQuestion];
	docCauHoiDaThi(root, List, YourAnswer, MSSV, monHoc);
	system("cls");
	VeKhungCauHoi();
	InCauHoiThi(List[0], YourAnswer[0], 0, NumberQuestion, 1);
	ThanhChucNang(1);
	for (int start = 0, end = NumberQuestion - 1; start <= end;)
	{
		if (change == 1)
			InCauHoiThi(List[start], YourAnswer[start], start, end + 1, 1);
		change = 0;
		chon = getch();
		switch (chon)
		{
		case ESC:
		{
			if (THONGBAO(3, "BAN CO MUON THOAT KHONG?"))
			{
				system("cls");
				return;
			}
			break;
		}
		case 0:
		case 224:
		{
			chon = getch();
			switch (chon)
			{
			case F1:
			{
				end = NumberQuestion; // tìm từ đầu đến cuối mảng
				chon = TimCauHoi(List, end, YourAnswer);
				if (chon == 0)
				{
					THONGBAO(2, "KHONG TIM THAY CAU HOI");
					break;
				}
				else if (chon == ESC)
				{
					THONGBAO(2, "HUY TIM");
					break;
				}
				start = 0, end--, change = 1; // giảm end đi 1 vì end là chỉ số cuối
				break;
			}
			case F5:
			{
				List.clear();
				docCauHoiDaThi(root, List, YourAnswer, MSSV, monHoc);
				start = 0, end = NumberQuestion - 1, change = 1;
				break;
			}
			case LEFT:
			{
				if (start > 0)
				{
					start--;
					change = 1;
				}
				break;
			}
			case RIGHT:
			{
				if (start < end)
				{
					start++;
					change = 1;
				}
				break;
			}
			}
		}
		}
	}
	delete[] YourAnswer;
	List.destroy();
}
//****************************************End Phuong*************************************************//
/////////////////////////GV->DANH SACH SINH VIEN/////////////////////

PtrSV MENU_DSSV_GV(ListLH dslh, int classIndex, ListMH dsmh, STreeCH root, int types, string maMon)
{
	system("cls");
	PtrSV p = dslh.lh[classIndex]->danhSachSinhVien;
	int numOfStudents = 0;
	for (int i = 0; p != NULL; i++)
	{
		numOfStudents++;
		p = p->next;
	}
	// tao mang con tro = so node + 100 de quan li dslk;
	// khi mang con tro day thi khong the them nodeSV nao nua
	PtrSV temp[numOfStudents + 100] = {NULL};

	p = dslh.lh[classIndex]->danhSachSinhVien;
	// lay dia chi cua cac SV cho mang con tro
	for (int i = 0; p != NULL && i < numOfStudents; i++)
	{
		temp[i] = p;
		p = p->next;
	}

	if (numOfStudents == 0)
		THONGBAO(2, "DANH SACH SINH VIEN TRONG");

	int index = 0;
	int page = 1;
	int maxPage = (numOfStudents - 1) / 10 + 1;

	HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, numOfStudents, page, maxPage, types, maMon);
	gotoxy(2, 9 + (index % 10 + 1) * 2);
	cout << ">>";

	// check = 0: sap xep theo mssv, 1: sap xep theo ho
	bool checkList = 0;
	// kiem tra co phai dang o che do XOA SINH VIEN
	bool check_Delete = 0;
	// kiem tra co phai dang o che do HIEU CHINH
	bool check_Edit = 0;
	// kiem tra neu da them 100 SV thi khong cho them nua
	int students_Added = 0;

	bool check_Question = 0;
	char ch;
	while (1)
	{
		ch = getch();
		if (ch == -32 || ch == 0)
		{
			ch = getch();
			switch (ch)
			{
			case F1: // tim kiem sv theo ten
			{
				// lỗi hiện danh sách khi tìm vì trong hàm in tìm NULL để dừng
				if (types == 1)
					break;
				VeKhung(5, 31, 115, 33);
				gotoxy(6, 32);
				cout << "NHAP TEN SINH VIEN: ";
				string content = NhapChuoi(27, 32, 65);
				int numOfResults = 0;
				if (content == "EXIT")
				{
					delete_AreaOnScreen(5, 31, 120, 3);
					break;
				}
				p = dslh.lh[classIndex]->danhSachSinhVien;
				while (p != NULL)
				{
					if ((strstr(p->info.ten, content.data()) != NULL) || (strstr(p->info.ho, content.data()) != NULL))
						temp[numOfResults++] = p;
					p = p->next;
				}
				if (numOfResults == 0)
				{
					THONGBAO(2, "KHONG TIM THAY KET QUA");
				}
				else
				{
					// Cập nhật thông tin sau khi tìm kiếm thành công
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					numOfStudents = numOfResults;
					maxPage = (numOfStudents - 1) / 10 + 1;
					index = 0;
					page = 1;
					HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, numOfStudents, page, maxPage, types, maMon);
					gotoxy(2, 9 + (index % 10 + 1) * 2); // di chuyen toi vi tri hien con tro vi tri
					cout << ">>";
					// TODO: Xử lý hiển thị kết quả tìm kiếm
				}
				delete_AreaOnScreen(5, 31, 120, 3);
				break;
			}
			case F2:												 // sap xep theo ho <-> ten(mssv)
				delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2); // di chuyen toi vi tri xoa con tro vi tri
				SortDSSV(temp, numOfStudents, checkList);			 // sap xep lai dssv tuy theo nhu cau
				page = 1;											 // thao tac di chuyen ve dau dssv
				index = 0;
				HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, numOfStudents, page, maxPage, types, maMon);
				gotoxy(2, 9 + (index % 10 + 1) * 2); // di chuyen toi vi tri hien con tro vi tri
				cout << ">>";
				break;
			case F5: // tai lai danh sach ban dau
				if (types == 1)
					break;
				check_Delete = false;
				check_Edit = false;
				check_Question = false;
				numOfStudents = 0;
				p = dslh.lh[classIndex]->danhSachSinhVien;
				for (int i = 0; p != NULL; i++)
				{
					numOfStudents++;
					temp[i] = p;
					p = p->next;
				}
				delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
				maxPage = (numOfStudents - 1) / 10 + 1;
				index = 0;
				page = 1;
				HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, numOfStudents, page, maxPage, types, maMon);
				gotoxy(2, 9 + (index % 10 + 1) * 2); // di chuyen toi vi tri hien con tro vi tri
				cout << ">>";
				break;
			case UP:
			{
				if (index % 10 == 0 && page > 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page--;
					index--;
					HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, numOfStudents, page, maxPage, types, maMon);
					gotoxy(2, 9 + (index % 10 + 1) * 2); // di chuyen toi vi tri hien con tro vi tri
					cout << ">>";
				}
				else if (index % 10 > 0)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					index--;
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
			}
			break;
			case DOWN:
			{
				if (index % 10 == 9 && index < numOfStudents - 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page++;
					index++;
					HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, numOfStudents, page, maxPage, types, maMon);
					gotoxy(2, 9 + (index % 10 + 1) * 2); // di chuyen toi vi tri hien con tro vi tri
					cout << ">>";
				}
				else if (index % 10 < 9 && index < numOfStudents - 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					index++;
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
			}
			break;
			case PAGEUP:
			{
				if (page > 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					index = (index / 10) * 10 - 1;
					page--;

					HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, numOfStudents, page, maxPage, types, maMon);
					gotoxy(2, 9 + (index % 10 + 1) * 2); // di chuyen toi vi tri hien con tro vi tri
					cout << ">>";
				}
			}
			break;
			case PAGEDOWN:
			{
				if (page < maxPage)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					index = (index / 10 + 1) * 10;
					page++;
					HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, numOfStudents, page, maxPage, types, maMon);
					gotoxy(2, 9 + (index % 10 + 1) * 2); // di chuyen toi vi tri hien con tro vi tri
					cout << ">>";
				}
			}
			break;
			case RIGHT: // chuyen tu thao tac dssv sang option dssv
			{
				if (check_Delete || check_Edit || types)
					break;
				delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
				switch (HienOptionSinhVien())
				{
				case 0: // option0: do nothing
					break;
				case 1: // option1: thuc hien chuc nang THEM SINH VIEN
					SetColor(0, 7);
					if (students_Added == 100)
					{
						THONGBAO(2, "DA DAT SO LUONG THEM TOI DA-THOAT VA QUAY LAI-DE TIEP TUC THEM SV");
					}
					else if (ThemSinhVien(dslh, dslh.lh[classIndex]->danhSachSinhVien, dsmh))
					{
						THONGBAO(2, "DA THEM SINH VIEN");
						p = dslh.lh[classIndex]->danhSachSinhVien;
						numOfStudents = 0;
						students_Added++;
						for (int i = 0; p != NULL; i++)
						{
							numOfStudents++;
							temp[i] = p;
							p = p->next;
						}
					}
					else
						THONGBAO(2, "DA HUY QUA TRINH");

					maxPage = (numOfStudents - 1) / 10 + 1;
					page = 1;
					index = 0;
					HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, numOfStudents, page, maxPage, types, maMon);
					gotoxy(2, 9 + (index % 10 + 1) * 2); // di chuyen toi vi tri hien con tro vi tri
					cout << ">>";
					break;
				case 2: // option2: thuc hien chuc nang XOA SINH VIEN
					THONGBAO(2, "CHON SINH VIEN MUON XOA---F5 DE HUY QUA TRINH");
					check_Delete = 1;
					break;
				case 3: // option3: thuc hien chuc nang HIEU CHINH thong tin sinh vien
					THONGBAO(2, "CHON SINH VIEN MUON HIEU CHINH---F5 DE HUY QUA TRINH");
					check_Edit = 1;
					break;
				case 4: // option4: thuc hien chuc nang in ds DIEMTHI cua 1 sinh vien
				{
					THONGBAO(2, "CHON MON HOC");
					string maMon;
					while (1)
					{
						maMon = MENU_DSMH_GV(root, dsmh, 1);
						if (maMon == "EXIT")
							break;
						MENU_DSSV_GV(dslh, classIndex, dsmh, root, 1, maMon);
					}
					HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, numOfStudents, page, maxPage, types, maMon);
					break;
				}
				case 5: // option5: thuc hien chuc nang in ds CAUHOI da thi cua 1 sinh vien
					THONGBAO(2, "CHON SINH VIEN DE XEM---F5 DE HUY QUA TRINH");
					check_Question = 1;
					break;
				}
			}
			}
			if (types == 0)
				HienOptionSinhVien(1);
			gotoxy(2, 9 + (index % 10 + 1) * 2);
			cout << ">>";
		}
		else
		{
			switch (ch)
			{
			case ESC:
				system("cls");
				return NULL;
			case ENTER:
			{
				if (numOfStudents == 0)
					break;
				else if (types == 1)
				{
					MonHoc selectedSub;
					strcpy(selectedSub.maMonHoc, maMon.c_str());
					strcpy(selectedSub.tenMonHoc, FindName(dsmh, selectedSub.maMonHoc).c_str());
					InCauHoiDaThi(root, selectedSub, temp[index]->info.MSSV);
				}
				else if (types == 2) // tra ve PtrSV duoc chi dinh
				{
					system("cls");
					return temp[index];
				}
				else if (check_Delete) // thuc hien option XOA SINH VIEN
				{
					if (temp[index]->info.danhSachDiemThi != NULL)
					{
						THONGBAO(2, "SINH VIEN DA LAM BAI THI-KHONG THE XOA");
					}
					else if (THONGBAO(3, "BAN CHAC CHAN MUON XOA?"))
					{
						numOfStudents--;
						students_Added--;
						maxPage = (numOfStudents - 1) / 10 + 1;
						if (XoaSinhVien(dslh.lh[classIndex]->danhSachSinhVien, temp, numOfStudents, dslh.lh[classIndex]->maLop, index))
						{
							system("cls");
							THONGBAO(2, "DA XOA SINH VIEN THANH CONG");
						}
						page = 1;
						index = 0;
					}
					// check_Delete = 0;
				}
				else if (check_Edit) // thuc hien option HIEU CHINH
				{
					if (HieuChinhSinhVien(dslh, dslh.lh[classIndex]->danhSachSinhVien, temp, index))
						THONGBAO(2, "DA HIEU CHINH THANH CONG");
					else
						THONGBAO(2, "DA HUY THAO TAC");
				}
				else if (check_Question)
				{
					MonHoc mh;
					while (1)
					{
						strcpy(mh.maMonHoc, MENU_DSMH_GV(root, dsmh, 1).data());
						if (strcmp(mh.maMonHoc, "EXIT") == 0)
							break;
						strcpy(mh.tenMonHoc, FindName(dsmh, mh.maMonHoc).data());
						InCauHoiDaThi(root, mh, temp[index]->info.MSSV);
					}
					check_Question = 0;
				}
				else // ENTER khi chua bat thao tac(Xoa, Hieu chinh) -> truy cap vao dsDT
				{
					MENU_DSDT_GV(temp[index]->info, dsmh, root, 0);
				}
			}
			}
			HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, numOfStudents, page, maxPage, types, maMon);
			gotoxy(2, 9 + (index % 10 + 1) * 2); // di chuyen toi vi tri hien con tro vi tri
			cout << ">>";
		}
	}
}
// types: 0-> hien dssv co options, 1->hien dsDT theo mon, 2-> hien dssv khong option
void HienDanhSachSinhVien(PtrSV *data, string tenLop, int numOfStudents, int page, int maxPage, int types, string maMon)
// void HienDanhSachSinhVien(PtrSV *data, string tenLop, int numOfClasses, int page, int maxPage, int types = 0, string maMon = "")
{
	delete_MenuContent(108);
	TextColor(7);
	VeHeader(2, "DANH SACH SINH VIEN", tenLop);
	VeDanhSach(2);
	if (!types)
		HienOptionSinhVien(1);
	if (types == 1)
	{
		delete_LineOnScreen(103, 9, 10);
		gotoxy(104, 9);
		cout << maMon;
	}
	int count = 0;
	// con tro -> dsdt cua tung sv -> in dsdt theo monhoc
	PtrDT p = NULL;

	for (int i = (page - 1) * 10; (i < page * 10) && (i < numOfStudents); i++)
	{
		gotoxy(10, 11 + 2 * count);
		cout << data[i]->info.MSSV;
		gotoxy(26, 11 + 2 * count);
		cout << data[i]->info.ho;
		gotoxy(81, 11 + 2 * count);
		cout << data[i]->info.ten;
		if (types != 1)
		{
			gotoxy(107, 11 + 2 * count);
			cout << (data[i]->info.phai ? "NU" : "NAM");
		}
		else
		{
			p = data[i]->info.danhSachDiemThi;
			gotoxy(105, 11 + 2 * count);
			while (p != NULL)
			{
				if (strcmp(p->info.maMonHoc, maMon.c_str()) == 0)
				{
					cout << setprecision(2) << fixed << p->info.diemThi;
					break;
				}
				p = p->next;
			}
			if (p == NULL)
				cout << "Chua thi";
		}
		count++;
	}
	types == 2 ? ThanhChucNang(8) : ThanhChucNang(7);
	gotoxy(116, 29);
	cout << "Page " << page << '/' << maxPage;
}
// check == 1: chi hien cac option(khong chon), check == 0: lua chon -> tra ve option da chon
int HienOptionSinhVien(bool check)
{
	string option1 = "   THEM SINH VIEN       ";
	string option2 = "   XOA SINH VIEN        ";
	string option3 = "   HIEU CHINH           ";
	string option4 = "   IN DANH SACH DIEM    ";
	string option5 = "   IN CAU HOI DA THI    ";

	TextColor(112);
	gotoxy(120, 15);
	cout << option1;
	gotoxy(120, 17);
	cout << option2;
	gotoxy(120, 19);
	cout << option3;
	gotoxy(120, 21);
	cout << option4;
	gotoxy(120, 23);
	cout << option5;
	TextColor(7);

	if (check)
		return 0;

	int pos_Y = 15, conTro = 15;

	gotoxy(120, 15);
	TextColor(20);
	cout << option1;
	TextColor(112);

	char ch;
	while (1)
	{
		while ((ch = getch()) == -32)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
			{
				if (pos_Y > 15)
				{
					conTro -= 2;
					TextColor(20);
					gotoxy(120, conTro);
					switch (conTro)
					{
					case 15:
						cout << option1;
						break;
					case 17:
						cout << option2;
						break;
					case 19:
						cout << option3;
						break;
					case 21:
						cout << option4;
						break;
					}
					TextColor(112);
					gotoxy(120, pos_Y);
					switch (pos_Y)
					{
					case 17:
						cout << option2;
						break;
					case 19:
						cout << option3;
						break;
					case 21:
						cout << option4;
						break;
					case 23:
						cout << option5;
						break;
					}
					pos_Y -= 2;
					TextColor(7);
				}
			}
			break;
			case DOWN:
			{
				if (pos_Y < 23)
				{
					conTro += 2;
					TextColor(20);
					gotoxy(120, conTro);
					switch (conTro)
					{
					case 17:
						cout << option2;
						break;
					case 19:
						cout << option3;
						break;
					case 21:
						cout << option4;
						break;
					case 23:
						cout << option5;
						break;
					}
					TextColor(112);
					gotoxy(120, pos_Y);
					switch (pos_Y)
					{
					case 15:
						cout << option1;
						break;
					case 17:
						cout << option2;
						break;
					case 19:
						cout << option3;
						break;
					case 21:
						cout << option4;
						break;
					}
					pos_Y += 2;
					TextColor(7);
				}
			}
			break;
			case LEFT:
				return 0;
			}
		}
		if (ch == ENTER)
			switch (conTro)
			{
			case 15:
				return 1;
			case 17:
				return 2;
			case 19:
				return 3;
			case 21:
				return 4;
			case 23:
				return 5;
			}
		else if (ch == ESC)
			return 0;
	}
}
void SortDSSV(PtrSV *data, int n, bool &check)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (check && strcmp(data[i]->info.MSSV, data[j]->info.MSSV) > 0)
			{
				swap(data[i], data[j]);
			}
			else if (!check && strcmp(data[i]->info.ho, data[j]->info.ho) > 0)
			{
				swap(data[i], data[j]);
			}
	check = !check;
}
bool ThemSinhVien(ListLH dslh, PtrSV &dssv, ListMH dsmh)
{
	KhungThem(2);
	SinhVien newSV;
	string mssv = "", ho = "", ten = "", password = "";
	string temp = "";
	KhoiTao_PtrDT(newSV.danhSachDiemThi);

	int check = 0;
	int stage = 0;
	newSV.phai = 0;
	while (1)
	{
		temp = "";
		switch (stage)
		{
		case 0: // nhap mssv
			temp = NhapMa1(8, 35, 10, mssv);
			if (is_Existed_MSSV_SV(dslh, mssv))
			{
				THONGBAO(2, "MA SO SINH VIEN DA TON TAI-HAY NHAP MA MOI");
				delete_LineOnScreen(8, 35, 10);
				mssv = "";
				temp = "";
			}
			else if (!is_Empty_CArray(mssv.c_str()))
				check++;
			else if (is_Empty_CArray(mssv.c_str()) && check > 0)
				check--;
			break;
		case 1: // nhap ho
			temp = NhapChuoi1(26, 35, 50, ho);
			if (!is_Empty_CArray(ho.c_str()))
				check++;
			else if (is_Empty_CArray(ho.c_str()) && check > 1)
				check--;
			break;
		case 2: // nhap ten
			temp = NhapChuoi1(81, 35, 15, ten);
			if (!is_Empty_CArray(ten.c_str()))
				check++;
			else if (is_Empty_CArray(ten.c_str()) && check > 2)
				check--;
			break;
		case 3: // nhap password
			temp = NhapMa1(101, 35, 11, password);
			if (!is_Empty_CArray(password.c_str()))
				check++;
			else if (is_Empty_CArray(password.c_str()) && check > 3)
				check--;
			break;
		case 4: // gioi tinh
		{
			if (newSV.phai == 0)
			{
				gotoxy(116, 33);
				SetColor(1, 3);
				cout << " NAM ";
			}
			else
			{
				gotoxy(116, 35);
				SetColor(1, 3);
				cout << " NU  ";
			}
			SetColor(0, 7);
			char ch;
			bool move = false;
			while (1)
			{
				ch = getch();
				if (ch == -32)
				{
					ch = getch();
					switch (ch)
					{
					case UP:
						newSV.phai = 0;
						break;
					case DOWN:
						newSV.phai = 1;
						break;
					case LEFT:
						temp = "LEFT";
						move = true;
						break;
					case RIGHT:
						temp = "RIGHT";
						move = true;
						break;
					}
					gotoxy(116, 33);
					(newSV.phai == 0 ? SetColor(1, 3) : SetColor(0, 7));
					cout << " NAM ";
					gotoxy(116, 35);
					(newSV.phai == 1 ? SetColor(1, 3) : SetColor(0, 7));
					cout << " NU  ";
					SetColor(0, 7);
				}
				else if (ch == ENTER)
				{
					temp = "DONE";
					break;
				}
				if (move)
					break;
			}
			break;
		}
		case 5: // xong
			gotoxy(123, 34);
			SetColor(1, 3);
			cout << " XONG ";
			SetColor(0, 7);
			char ch = getch();
			switch (ch)
			{
			case LEFT:
				temp = "LEFT";
				gotoxy(123, 34);
				SetColor(7, 0);
				cout << " XONG ";
				SetColor(0, 7);
				break;
			case ENTER:
				if (check < 4)
					THONGBAO(2, "HAY NHAP DU THONG TIN");
				else if (THONGBAO(3, "LUU THONG TIN?"))
				{
					strcpy(newSV.MSSV, mssv.c_str());
					strcpy(newSV.ho, ho.c_str());
					strcpy(newSV.ten, ten.c_str());
					strcpy(newSV.password, password.c_str());
					insert_Order_SV(dssv, newSV);
					delete_AreaOnScreen(5, 32, 125, 5);
					return 1;
				}
				break;
			case ESC:
				if (THONGBAO(3, "HUY QUA TRINH?"))
				{
					delete_AreaOnScreen(5, 32, 125, 5);
					return 0;
				}
				break;
			}
		}
		if (temp == "LEFT" && stage > 0)
			stage--;
		else if (temp == "RIGHT" || temp == "DONE" && stage < 5)
			stage++;
		else if (temp == "EXIT")
		{
			if (THONGBAO(3, "HUY THAO TAC?"))
			{
				delete_AreaOnScreen(5, 32, 125, 5);
				return 0;
			}
		}
	}
}
bool XoaSinhVien(PtrSV &dssv, PtrSV *data, int numOfStudents, const string &maLH, int index)
{
	bool check = false;
	removeSinhVienFile(maLH, data[index]->info.MSSV);
	PtrSV p = NULL;
	if (data[index] == dssv)
	{
		if (delete_First_SV(dssv))
			check = true;
	}
	else
	{
		p = NULL;
		for (p = dssv; p->next != NULL; p = p->next)
			if (data[index] == p->next)
			{
				if (delete_After_SV(p))
					check = true;
				break;
			}
	}
	for (int i = index; i < numOfStudents; i++)
		data[i] = data[i + 1];
	return check;
}
bool HieuChinhSinhVien(ListLH dslh, PtrSV dssv, PtrSV *data, int index)
{
	SinhVien tempSV;
	tempSV.phai = data[index]->info.phai;
	strcpy(tempSV.MSSV, data[index]->info.MSSV);
	strcpy(tempSV.password, data[index]->info.password); // cap lai mat khau cu~
	KhoiTao_PtrDT(tempSV.danhSachDiemThi);
	tempSV.danhSachDiemThi = data[index]->info.danhSachDiemThi; // cap lai diem thi cu~

	THONGBAO(2, "NHAP THONG TIN SINH VIEN");
	delete_LineOnScreen(101, 9 + (index % 10 + 1) * 2, 14);
	gotoxy(102, 9 + (index % 10 + 1) * 2);
	tempSV.phai == 0 ? SetColor(1, 3) : SetColor(7, 0);
	cout << " NAM ";
	gotoxy(109, 9 + (index % 10 + 1) * 2);
	tempSV.phai == 1 ? SetColor(1, 3) : SetColor(7, 0);
	cout << " NU  ";
	SetColor(0, 7);
	while (1)
	{
		strcpy(tempSV.ho, NhapChuoi(26, 9 + (index % 10 + 1) * 2, 50).c_str()); // nhap ho
		if (is_Empty_CArray(tempSV.ho))											// neu ENTER khi chua nhap -> dung ho cu~ cua SV
		{
			strcpy(tempSV.ho, data[index]->info.ho);
			break;
		}
		else if (strcmp(tempSV.ho, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY THAO TAC?"))
				return 0;
			else
				continue;
		}
		else
			break;
	}
	gotoxy(26, 9 + (index % 10 + 1) * 2);
	cout << tempSV.ho;
	while (1)
	{
		strcpy(tempSV.ten, NhapChuoi(81, 9 + (index % 10 + 1) * 2, 15).c_str());
		if (is_Empty_CArray(tempSV.ten)) // tuong tu nhu tren
		{
			strcpy(tempSV.ten, data[index]->info.ten);
			break;
		}
		else if (strcmp(tempSV.ten, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY THAO TAC?"))
				return 0;
			else
				continue;
		}
		else
			break;
	}
	gotoxy(81, 9 + (index % 10 + 1) * 2);
	cout << tempSV.ten;

	char ch;
	while ((ch = getch()) != ENTER)
	{
		if (ch == -32 || ch == 224)
		{
			ch = getch();
			switch (ch)
			{
			case LEFT:
				tempSV.phai = 0;
				break;
			case RIGHT:
				tempSV.phai = 1;
				break;
			}
		}
		else if (ch == ESC)
		{
			if (THONGBAO(3, "HUY THAO TAC?"))
				return 0;
		}
		gotoxy(102, 9 + (index % 10 + 1) * 2);
		tempSV.phai == 0 ? SetColor(1, 3) : SetColor(7, 0);
		cout << " NAM ";
		gotoxy(109, 9 + (index % 10 + 1) * 2);
		tempSV.phai == 1 ? SetColor(1, 3) : SetColor(7, 0);
		cout << " NU  ";
		SetColor(0, 7);
	}
	if (THONGBAO(3, "LUU THAY DOI?"))
	{
		changeInfoByPtrArray_SV(dssv, data[index]->info.MSSV, tempSV);
		return 1;
	}
	else
	{
		return 0;
	}
}
//////////////////////////GV->DANH SACH DIEM THI/////////////////////
void MENU_DSDT_GV(SinhVien &data, ListMH dsmh, STreeCH root, bool is_SV)
{
	system("cls");
	int numOfScores = 0;
	PtrDT p = data.danhSachDiemThi;
	for (p = data.danhSachDiemThi; p != NULL; p = p->next)
		numOfScores++;

	if (numOfScores == 0)
	{
		THONGBAO(2, "CHUA CO DIEM THI");
		system("cls");
		return;
	}
	PtrDT temp[numOfScores] = {NULL};

	int numOfSubs = 0;
	PtrDT q = data.danhSachDiemThi;
	temp[numOfSubs++] = q;
	p = q->next;
	while (p != NULL) // chi quan ly diem thi cuoi cung cua tung mon hoc
	{
		if (strcmp(p->info.maMonHoc, q->info.maMonHoc) != 0)
		{
			q = p;
			temp[numOfSubs++] = q;
		}
		p = p->next;
	}

	int page = 1;
	int index = 0; // vi tri trong mang con tro
	int maxPage = (numOfSubs - 1) / 10 + 1;
	HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, numOfSubs, page, maxPage, is_SV);
	gotoxy(2, 9 + (index % 10 + 1) * 2);
	cout << ">>";

	int check_List = 1; // cach sap xep cua ds

	char ch;
	while (1)
	{
		ch = getch();
		if (ch == -32 || ch == 0)
		{
			ch = getch();
			switch (ch)
			{
			case F1: // tim kiem
			{
				VeKhung(5, 31, 90, 33);
				gotoxy(6, 32);
				cout << "NHAP TEN MON HOC: ";
				string content = NhapChuoi(27, 32, 50);
				int numOfResults = 0;
				if (content == "EXIT")
				{
					delete_AreaOnScreen(5, 31, 90, 3);
					break;
				}
				p = data.danhSachDiemThi;
				while (p != NULL)
				{
					if (strstr(FindName(dsmh, p->info.maMonHoc).data(), content.data()) != NULL)
						temp[numOfResults++] = p;
					p = p->next;
				}
				if (numOfResults == 0)
					THONGBAO(2, "KHONG TIM THAY KET QUA");
				else
				{
					numOfSubs = numOfResults;
					int page = 1;
					int maxPage = (numOfSubs - 1) / 10 + 1;
					HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, numOfSubs, page, maxPage, is_SV);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				delete_AreaOnScreen(5, 31, 90, 3);
				break;
			}
			case F2:
			{
				delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
				SortDSDT(temp, numOfSubs, check_List);
				page = 1;
				index = 0;
				HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, numOfSubs, page, maxPage, is_SV);
				gotoxy(2, 9 + (index % 10 + 1) * 2);
				cout << ">>";
				break;
			}
			case F5:
			{
				numOfSubs = 0;
				p = data.danhSachDiemThi;
				for (int i = 0; p != NULL; i++)
				{
					numOfSubs++;
					temp[i] = p;
					p = p->next;
				}
				delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
				int page = 1;
				index = 0;
				int maxPage = (numOfSubs - 1) / 10 + 1;
				HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, numOfSubs, page, maxPage, is_SV);
				gotoxy(2, 9 + (index % 10 + 1) * 2);
				cout << ">>";

				break;
			}
			case UP:
			{
				if (index % 10 == 0 && page > 1) // truong hop dang o dau trang va ton tai trang truoc thi PgUp
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page--;
					index--;
					HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, numOfSubs, page, maxPage, is_SV);

					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				else if (index % 10 > 0) // truong hop o vi tri khong phai dau trang
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					index--;
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
			}
			break;
			case DOWN:
			{
				if (index % 10 == 9 && index < numOfSubs - 1) // truong hop o cuoi trang va con sinh vien thi PgDn
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page++;
					index++;
					HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, numOfSubs, page, maxPage, is_SV);

					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				else if (index % 10 < 9 && index < numOfSubs - 1) // truong hop o vi tri khong phai cuoi trang
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					index++;
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
			}
			break;
			case PAGEUP:
			{
				if (page > 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page--;
					index = (index / 10) * 10 - 1;
					HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, numOfSubs, page, maxPage, is_SV);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
			}
			break;
			case PAGEDOWN:
			{
				if (page < maxPage)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page++;
					index = (index / 10 + 1) * 10;
					HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, numOfSubs, page, maxPage, is_SV);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
			}
			break;
			}
		}
		else
		{
			switch (ch)
			{
			case ESC:
				system("cls");
				return;
			case ENTER:
			{
				if (is_SV)
					break;
				MonHoc selectedSub;
				strcpy(selectedSub.maMonHoc, temp[index]->info.maMonHoc);
				strcpy(selectedSub.tenMonHoc, FindName(dsmh, selectedSub.maMonHoc).c_str());
				InCauHoiDaThi(root, selectedSub, data.MSSV);
				system("cls");
			}
				HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, numOfSubs, page, maxPage, is_SV);
				gotoxy(2, 9 + (index % 10 + 1) * 2);
				cout << ">>";
			}
		}
	}
}
void HienDanhSachDiemThi(ListMH dsmh, PtrDT *data, string MSSV, string ho, string ten, int numOfSubs, int page, int maxPage, bool is_SV)
{
	// system("cls");
	delete_MenuContent(83);
	TextColor(7);

	VeHeader(3, "DANH SACH DIEM THI", MSSV + " - " + ho + ' ' + ten);
	VeDanhSach(3);
	int count = 1;
	for (int i = (page - 1) * 10; i < page * 10 && i < numOfSubs; i++)
	{
		gotoxy(6, 9 + count * 2);
		cout << FindName(dsmh, data[i]->info.maMonHoc);
		gotoxy(78, 9 + count * 2);
		cout << setprecision(2) << fixed << data[i]->info.diemThi;
		count++;
	}
	is_SV ? ThanhChucNang(13) : ThanhChucNang(12);
	gotoxy(91, 29);
	cout << "Page " << page << '/' << maxPage;
}
int HienOptionDiemThi(bool check)
{
	string option1 = "     THEM DIEM THI      ";
	string option2 = "     XOA DIEM THI       ";
	string option3 = "     HIEU CHINH         ";

	TextColor(112);
	gotoxy(120, 15);
	cout << option1;
	gotoxy(120, 17);
	cout << option2;
	gotoxy(120, 19);
	cout << option3;
	TextColor(7);

	if (check)
		return 0;

	int pos_Y = 15, conTro = 15;

	gotoxy(120, 15);
	TextColor(20);
	cout << option1;
	TextColor(7);

	char ch;
	while (1)
	{
		while ((ch = getch()) == -32)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
			{
				if (pos_Y > 15)
				{
					conTro -= 2;
					TextColor(20);
					gotoxy(120, conTro);
					switch (conTro)
					{
					case 15:
						cout << option1;
						break;
					case 17:
						cout << option2;
						break;
					}
					TextColor(112);
					gotoxy(120, pos_Y);
					switch (pos_Y)
					{
					case 17:
						cout << option2;
						break;
					case 19:
						cout << option3;
						break;
					}
					pos_Y -= 2;
					TextColor(7);
				}
			}
			break;
			case DOWN:
			{
				if (pos_Y < 19)
				{
					conTro += 2;
					TextColor(20);
					gotoxy(120, conTro);
					switch (conTro)
					{
					case 17:
						cout << option2;
						break;
					case 19:
						cout << option3;
						break;
					}
					TextColor(112);
					gotoxy(120, pos_Y);
					switch (pos_Y)
					{
					case 15:
						cout << option1;
						break;
					case 17:
						cout << option2;
						break;
					}
					pos_Y += 2;
					TextColor(7);
				}
			}
			break;
			case LEFT:
				return 0;
			}
		}
		if (ch == ENTER)
			switch (conTro)
			{
			case 15:
				return 1;
			case 17:
				return 2;
			case 19:
				return 3;
			}
		else if (ch == ESC)
			return 0;
	}
}
void SortDSDT(PtrDT *data, int n, int &check)
{
	PtrDT temp = NULL;
	if (check == 0)
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (strcmp(data[i]->info.maMonHoc, data[j]->info.maMonHoc) > 0)
				{
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
		check = 1;
	}
	else if (check == 1)
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (data[i]->info.diemThi < data[j]->info.diemThi)
				{
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
		check = 0;
	}
}
///////////////////////////GV->DANH SACH LOP HOC/////////////////////
bool sortDSLH(LopHoc **dslh, int numOfClass, int &index)
{
	if (index < 1 || index > 2)
		return false; // index = 1, 2  tuong ung voi maLop, tenLop
	for (int i = 0; i < numOfClass - 1; i++)
	{
		for (int j = i + 1; j < numOfClass; j++)
		{
			if (index == 1)
			{ // sap xep theo maLop
				if (strcmp(dslh[i]->maLop, dslh[j]->maLop) > 0)
				{
					swap(dslh[i], dslh[j]);
				}
			}
			else if (index == 2)
			{ // sap xep theo tenLop
				if (strcmp(dslh[i]->tenLop, dslh[j]->tenLop) > 0)
				{
					swap(dslh[i], dslh[j]);
				}
			}
		}
	}
	if (index < 2)
		index++;
	else
		index = 1;
	return true;
}
int HienOptionLopHoc(bool check)
{
	string option1 = "   THEM LOP HOC         ";
	string option2 = "   XOA LOP HOC          ";
	string option3 = "   HIEU CHINH           ";
	string option4 = "   IN DANH SACH DIEM    ";
	string option5 = "   IN DSLH THEO KHOA    ";
	// hien khung option
	TextColor(112);
	gotoxy(120, 15);
	cout << option1;
	gotoxy(120, 17);
	cout << option2;
	gotoxy(120, 19);
	cout << option3;
	gotoxy(120, 21);
	cout << option4;
	gotoxy(120, 23);
	cout << option5;
	TextColor(7);

	if (check)
		return 0;

	int pos_Y = 15, conTro = 15;
	// hien de chon khung option
	gotoxy(120, 15);
	TextColor(20);
	cout << option1;
	TextColor(7);

	char ch;
	while (1)
	{
		while ((ch = getch()) == -32)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
				if (pos_Y > 15)
				{
					conTro -= 2;
					TextColor(20);
					gotoxy(120, conTro);
					switch (conTro)
					{
					case 15:
						cout << option1;
						break;
					case 17:
						cout << option2;
						break;
					case 19:
						cout << option3;
						break;
					case 21:
						cout << option4;
						break;
					}
					TextColor(112);
					gotoxy(120, pos_Y);
					switch (pos_Y)
					{
					case 17:
						cout << option2;
						break;
					case 19:
						cout << option3;
						break;
					case 21:
						cout << option4;
						break;
					case 23:
						cout << option5;
						break;
					}
					pos_Y -= 2;
					TextColor(7);
				}
				break;
			case DOWN:
				if (pos_Y < 23)
				{
					conTro += 2;
					TextColor(20);
					gotoxy(120, conTro);
					switch (conTro)
					{
					case 17:
						cout << option2;
						break;
					case 19:
						cout << option3;
						break;
					case 21:
						cout << option4;
						break;
					case 23:
						cout << option5;
						break;
					}
					TextColor(112);
					gotoxy(120, pos_Y);
					switch (pos_Y)
					{
					case 15:
						cout << option1;
						break;
					case 17:
						cout << option2;
						break;
					case 19:
						cout << option3;
						break;
					case 21:
						cout << option4;
						break;
					}
					pos_Y += 2;
					TextColor(7);
				}
				break;
			case LEFT:
				return 0;
			}
		}
		if (ch == ENTER)
			switch (conTro)
			{
			case 15:
				return 1;
			case 17:
				return 2;
			case 19:
				return 3;
			case 21:
				return 4;
			case 23:
				return 5;
			}
		else if (ch == ESC)
			return 0;
	}
}
bool ThemLopHoc(ListLH &dslh, int check, string maLH)
{
	KhungThem(1);
	LopHoc newLH;
	string maLopM = "", tenLopM = "";
	// string nienKhoaM = "";
	int nK = -1;
	// nK = atoi(nienKhoaM.c_str());
	// kiem tra da nhap du 3 noi dung hay chua
	int index = 0;
	int key = 0;
	string temp = "";

	while (1)
	{
		temp = "";
		switch (key)
		{
		case 0: // nhap ma lop
			temp = NhapMa1(6, 35, 15, maLopM);
			if (is_Existed_MaLop(dslh, maLopM.c_str()))
			{
				THONGBAO(2, "MA LOP NAY DA TON TAI");
				delete_LineOnScreen(6, 35, 15);
				maLopM = "";
				temp = "";
				continue;
			}
			// else if (is_Empty_CArray(maMon.c_str()))
			// {
			// 	THONGBAO(2, "NHAP MA MON HOC");
			// 	if (check > 0)
			// 		--check;
			// 	// continue;
			// }
			else if (!is_Empty_CArray(maLopM.c_str()) && index < 1)
				index++;
			else if (is_Empty_CArray(maLopM.c_str()) && index > 0)
				index--;
			break;
		case 1: // nhap ten lop
			temp = NhapChuoi1(26, 35, 50, tenLopM);
			if (is_Existed_tenLop(dslh, tenLopM.c_str()))
			{
				THONGBAO(2, "TEN LOP NAY DA TON TAI");
				delete_LineOnScreen(26, 35, 50);
				tenLopM = "";
				temp = "";
				continue;
			}
			// else if (is_Empty_CArray(tenLop.c_str()))
			// {
			// 	THONGBAO(2, "NHAP TEN LOP HOC");
			// 	if (check > 0)
			// 		--check;
			// 	// continue;
			// }
			else if (!is_Empty_CArray(tenLopM.c_str()) && index < 2)
				index++;
			else if (is_Empty_CArray(tenLopM.c_str()) && index > 1)
				index--;
			break;
		case 2: // nhap nien khoa
			// nK = atoi(nienKhoaM.c_str());
			temp = NhapSo1(106, 35, 4, nK);
			// nienKhoaM = to_string(nK);
			if (nK <= 2000 && nK >= 0 || nK > 2023)
			{
				THONGBAO(2, "NAM HOC: 2000 < X < 2024");
				delete_LineOnScreen(106, 35, 4);
				nK = -1;
				continue;
			}
			else if (nK > 2000 && nK <= 2023 && index < 3)
				index++;
			else if (nK == -1 && index > 2)
				index--;
			// else if (nK < 0)
			// 	THONGBAO(2, "HAY NHAP NIEN KHOA");
			// if (!is_Empty_CArray(nienKhoaM.c_str()))
			// 	index++;
			break;
		case 3: // XONG
			gotoxy(117, 34);
			SetColor(1, 3);
			cout << " XONG ";
			SetColor(0, 7);
			char ch = getch();
			switch (ch)
			{
			case LEFT:
				temp = "LEFT";
				gotoxy(117, 34);
				SetColor(7, 0);
				cout << " XONG ";
				SetColor(0, 7);
				break;
			case ENTER:
				if (index < 3)
					THONGBAO(2, "HAY NHAP DU THONG TIN");
				else if (THONGBAO(3, "LUU LOP HOC?"))
				{
					strcpy(newLH.maLop, maLopM.c_str());
					strcpy(newLH.tenLop, tenLopM.c_str());
					// newLH.nienKhoa = atoi(nienKhoaM.c_str());
					newLH.nienKhoa = nK;
					ThemLop(dslh, newLH);
					createLopHocFolder(newLH.maLop);
					delete_AreaOnScreen(5, 32, 120, 5);
					return 1;
				}
				break;
			case ESC:
				if (THONGBAO(3, "HUY QUA TRINH?"))
				{
					delete_AreaOnScreen(5, 32, 120, 5);
					return 0;
				}
				break;
			}
		}
		if (temp == "LEFT" && key > 0)
			key--;
		else if ((temp == "RIGHT" || temp == "DONE") && key < 3)
			key++;
		else if (temp == "EXIT")
		{
			if (THONGBAO(3, "HUY THAO TAC?"))
			{
				delete_AreaOnScreen(5, 32, 120, 5);
				return 0;
			}
		}
	}
}
bool XoaLopHoc(ListLH &dslh, LopHoc **lh, int index)
{
	if (is_Empty_LH(dslh) || index < 0 || index >= dslh.n)
		return false;
	int i = 0;
	for (i = 0; i < dslh.n; i++)
		if (lh[index] == dslh.lh[i])
			break;
	removeLopHocFolder(lh[index]->maLop);
	removeLopHocFile(lh[index]->maLop);
	XoaLop(dslh, i);
	for (int j = index; j < dslh.n; j++)
		lh[j] = lh[j + 1];
	return true;
}
bool HieuChinhLopHoc(ListLH dslh, LopHoc **data, int index)
{
	LopHoc tempLH;
	strcpy(tempLH.maLop, data[index]->maLop);
	THONGBAO(2, "NHAP THONG TIN LOP HOC MOI");
	while (1)
	{
		strcpy(tempLH.tenLop, NhapChuoi(26, 9 + (index % 10 + 1) * 2, 50).c_str()); // nhap ten lop
		if (is_Empty_CArray(tempLH.tenLop))											// neu ENTER khi chua nhap -> dung ten lop cu~
		{
			strcpy(tempLH.tenLop, data[index]->tenLop);
			break;
		}
		else if (is_Existed_tenLop(dslh, tempLH.tenLop) && strcmp(tempLH.tenLop, data[index]->tenLop) != 0)
		{
			THONGBAO(2, "TEN LOP NAY DA TON TAI");
			delete_LineOnScreen(26, 9 + (index % 10 + 1) * 2, 50);
		}
		else if (strcmp(tempLH.tenLop, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY THAO TAC?"))
				return 0;
		}
		else
			break;
	}
	gotoxy(26, 9 + (index % 10 + 1) * 2);
	cout << tempLH.tenLop;

	// xu ly nienKhoa
	while (1)
	{
		tempLH.nienKhoa = NhapSo(106, 9 + (index % 10 + 1) * 2, 4);
		if (tempLH.nienKhoa == -2)
		{
			tempLH.nienKhoa = data[index]->nienKhoa;
			break;
		}
		else if (tempLH.nienKhoa < 2000 || tempLH.nienKhoa > 2023)
			THONGBAO(2, "NIEN KHOA: 2000 < X < 2024");
		else if (tempLH.nienKhoa == -1)
		{
			if (THONGBAO(3, "HUY THAO TAC?"))
				return 0;
		}
		else
			break;
	}
	gotoxy(106, 9 + (index % 10 + 1) * 2);
	cout << tempLH.nienKhoa;
	if (THONGBAO(3, "LUU THAY DOI?"))
	{
		tempLH.danhSachSinhVien = data[index]->danhSachSinhVien;
		*data[index] = tempLH;
		THONGBAO(2, "DA THAY DOI THONG TIN");
		return 1;
	}
	else
	{
		THONGBAO(2, "DA HUY THAO TAC");
		return 0;
	}
}
void HienDanhSachLopHoc(LopHoc **data, int numOfClasses, int page, int maxPage, bool types)
{
	// system("cls");
	delete_MenuContent(108);
	SetColor(0, 7);
	VeHeader(1, "DANH SACH LOP HOC", "");
	VeDanhSach(1);
	if (!types)
		HienOptionLopHoc(1);
	int count = 1;
	//(index < page * 10) && (data[index] != NULL) && ((page - 1) * 10 + index % 10 < numOfClasses)
	for (int index = (page - 1) * 10; index <= (page - 1) * 10 + 9 && index < numOfClasses; index++)
	{
		gotoxy(10, 9 + 2 * count);
		cout << data[index]->maLop;
		gotoxy(26, 9 + 2 * count);
		cout << data[index]->tenLop;
		gotoxy(106, 9 + 2 * count);
		cout << data[index]->nienKhoa;
		count++;
	}
	types ? ThanhChucNang(6) : ThanhChucNang(5);
	gotoxy(116, 29);
	cout << "Page " << page << '/' << maxPage;
}
void DanhSachTheoNienKhoa(ListLH dslh, LopHoc **data, int nienKhoa, int &numOfClasses)
{
	int newNumOfClasses = 0;
	int index = 0;
	while (index < dslh.n)
	{
		if (dslh.lh[index]->nienKhoa == nienKhoa)
			data[newNumOfClasses++] = dslh.lh[index];
		index++;
	}
	if (newNumOfClasses == 0)
		THONGBAO(2, "KHONG CO LOP NAO");
	else
	{
		numOfClasses = newNumOfClasses;
	}
}
string MENU_DSLH_GV(ListLH &dslh, ListMH dsmh, STreeCH root, bool types)
{
	system("cls");
	int numOfClasses = dslh.n;
	// tao mang con tro quan ly dslh
	LopHoc *temp[MaxOfClasses] = {NULL};
	// copy du lieu tu danh sach con tro ban dau sang danh sach moi
	for (int i = 0; i < dslh.n; i++)
		temp[i] = dslh.lh[i];

	int index = 0;
	int page = 1;
	int maxPage = (numOfClasses - 1) / 10 + 1;

	HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, types);
	gotoxy(2, 9 + (index % 10 + 1) * 2);
	cout << ">>";

	bool check_Delete = 0; // kiem tra co dang bat che do xoa lop duoc chon
	bool check_Edit = 0;   // kiem tra co dang bat che do sua lop duoc chon

	// kieu sap xep danh sach
	int check_List = 1;
	char ch;
	while (1)
	{
		ch = getch();
		if (ch == -32 || ch == 0)
		{
			ch = getch();
			switch (ch)
			{
			case F1: // Tim kiem theo ten lop hoc
			{
				VeKhung(5, 31, 115, 33);
				gotoxy(6, 32);
				cout << "NHAP TEN LOP HOC: ";
				string content = NhapChuoi(27, 32, 50);
				int numOfResults = 0;
				if (content == "EXIT")
				{
					delete_AreaOnScreen(5, 31, 120, 3);
					break;
				}
				for (int i = 0; i < dslh.n; i++)
				{
					if (strstr(dslh.lh[i]->tenLop, content.data()) != NULL)
						temp[numOfResults++] = dslh.lh[i];
				}
				if (numOfResults == 0)
					THONGBAO(2, "KHONG TIM THAY KET QUA");
				else
				{
					// Cập nhật thông tin sau khi tìm kiếm thành công
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					numOfClasses = numOfResults;
					maxPage = (numOfClasses - 1) / 10 + 1;
					index = 0;
					page = 1;
					// TODO: Xử lý hiển thị kết quả tìm kiếm
				}
				HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, types);
				gotoxy(2, 9 + (index % 10 + 1) * 2);
				cout << ">>";
				delete_AreaOnScreen(5, 31, 120, 3);
				break;
			}
			case F2: // sap xep theo ho <-> ten(mssv)
			{
				sortDSLH(temp, numOfClasses, check_List);

				delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
				index = 0;
				page = 1;
				HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, types);
				gotoxy(2, 9 + (index % 10 + 1) * 2);
				cout << ">>";
				break;
			}
			case F5: // tai lai danh sach ban dau
			{
				check_Delete = false;
				check_Edit = false;
				numOfClasses = dslh.n;
				delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
				maxPage = (numOfClasses - 1) / 10 + 1;
				index = 0;
				page = 1;
				for (int i = 0; i < dslh.n; i++)
					temp[i] = dslh.lh[i];

				HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, types);
				gotoxy(2, 9 + (index % 10 + 1) * 2);
				cout << ">>";
				break;
			}
			case UP:
			{
				if (index % 10 == 0 && page > 1) // dang o vi tri dau trang -> PgUp
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page--;
					index--;

					HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, types);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				else if (index % 10 > 0) // vi tri khong phai dau trang -> giam di 1
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					index--;
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
			}
			case DOWN:
			{
				if (index % 10 == 9 && index < numOfClasses - 1) // dang o vi tri cuoi trang -> PgDn
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page++;
					index++;

					HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, types);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				else if (index % 10 < 9 && index < numOfClasses - 1) // vi tri khong phai cuoi trang -> tang len 1
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					index++;
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
			}
			case PAGEUP:
			{
				if (page > 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page--;
					index = (index / 10) * 10 - 1;

					HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, types);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
			}
			case PAGEDOWN:
			{
				if (page < maxPage)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page++;
					index = (index / 10 + 1) * 10;

					HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, types);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
			}
			case RIGHT: // chuyen sang thao tac voi option dslh
			{
				// dang o che do khong thao tac voi option
				if (check_Delete || check_Edit || types)
					break;
				delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);

				// option = HienOptionLopHoc();
				// switch (option)
				switch (HienOptionLopHoc())
				{
				case 1: // chon che do them lop
				{
					if (is_Full_LH(dslh))
						THONGBAO(2, "SO LUONG LOP DA DAY");
					else if (ThemLopHoc(dslh))
					{
						temp[dslh.n - 1] = dslh.lh[dslh.n - 1];
						numOfClasses = dslh.n;
						maxPage = (numOfClasses - 1) / 10 + 1;
						THONGBAO(2, "DA THEM THANH CONG");
						system("cls");
					}
					else
						THONGBAO(2, "DA HUY THAO TAC");
					index = dslh.n - 1;
					page = index / 10 + 1;
					HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, types);
					// gotoxy(2, 9 + (index % 10 + 1) * 2);
					// cout << ">>";
					break;
				}
				case 2: // chon che do xoa lop
				{
					if (is_Empty_LH(dslh))
					{
						THONGBAO(2, "KHONG CO LOP TRONG DANH SACH");
					}
					else
					{
						THONGBAO(2, "CHON LOP MUON XOA---AN F5 DE HUY CHON");
						check_Delete = 1; // bat che do xoa lop duoc chon
					}
					break;
				}
				case 3: // chon che do hieu chinh
				{
					if (is_Empty_LH(dslh))
					{
						THONGBAO(2, "KHONG CO LOP TRONG DANH SACH");
					}
					else
					{
						THONGBAO(2, "CHON LOP HIEU CHINH---AN F5 DE HUY CHON");
						check_Edit = 1; // bat che do chinh sua lop duoc chon
					}
					break;
				}
				case 4: // chon che do in ds diem theolop
				{
					if (is_Empty_LH(dslh))
					{
						THONGBAO(2, "KHONG CO LOP TRONG DANH SACH");
					}
					else
					{
						THONGBAO(2, "CHON LOP");
						string maLop = MENU_DSLH_GV(dslh, dsmh, root, 1);
						if (maLop == "EXIT") // bam ESC khi chon ma lop
							break;
						while (1)
						{
							string maMon = MENU_DSMH_GV(root, dsmh, 1);
							if (maMon == "EXIT")
								break;
							int index;
							for (index = 0; index < dslh.n; index++)
								if (strcmp(dslh.lh[index]->maLop, maLop.c_str()) == 0)
									break;
							MENU_DSSV_GV(dslh, index, dsmh, root, 1, maMon);
						}
						HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, 1);
					}

					// gotoxy(2, 9 + (index % 10 + 1) * 2);
					// cout << ">>";
					break;
				}
				case 5: // chon che do in sd theo nK
				{
					if (is_Empty_LH(dslh))
					{
						THONGBAO(2, "KHONG CO LOP TRONG DANH SACH");
					}
					else
					{
						THONGBAO(2, "NHAP NIEN KHOA");
						delete_AreaOnScreen(120, 15, 26, 11);
						VeKhung(120, 16, 145, 18);
						int year;
						year = NhapSo(121, 17, 4); // nhap nien khoa can xem
						delete_AreaOnScreen(120, 16, 26, 3);
						DanhSachTheoNienKhoa(dslh, temp, year, numOfClasses);

						maxPage = (numOfClasses - 1) / 10 + 1;
						index = 0;
						page = 1;
						HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, types);
					}
					break;
				}
					// gotoxy(2, 9 + (index % 10 + 1) * 2);
					// cout << ">>";
				}
				HienOptionLopHoc(1);

				gotoxy(2, 9 + (index % 10 + 1) * 2);
				cout << ">>";
				break;
			}
			}
		}
		else
		{
			switch (ch)
			{
			case ESC:
				system("cls");
				return "EXIT";
			case ENTER:
			{
				if (types)
				{
					system("cls");
					return temp[index]->maLop;
				}
				if (check_Delete) // ktra che do xoa lop
				{
					if (temp[index]->danhSachSinhVien != NULL)
					{
						THONGBAO(2, "LOP DA TON TAI SV-KHONG THE XOA");
					}
					else if (THONGBAO(3, "XAC NHAN XOA LOP HOC?"))
					{
						XoaLopHoc(dslh, temp, index);

						numOfClasses = dslh.n;
						maxPage = (numOfClasses - 1) / 10 + 1;
						index = 0;
						page = 1;
						THONGBAO(2, "DA XOA LOP HOC");
						system("cls");
					}
					// check_Delete = 0;
				}
				else if (check_Edit) // ktra che do hieu chinh
				{
					HieuChinhLopHoc(dslh, temp, index);
					// check_Edit = 0;
				}
				else
				{
					int i;
					for (i = 0; i < dslh.n; i++)
						if (dslh.lh[i] == temp[index])
							break;
					MENU_DSSV_GV(dslh, i, dsmh, root);
				}
			}
			}
			HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, types);
			gotoxy(2, 9 + (index % 10 + 1) * 2);
			cout << ">>";
		}
		// for(int i = 0; i < MaxOfClasses; i++) // xoa mang con tro
		//  	temp[i] = NULL;
		// delete []temp;
	}
}
///////////////////////////GV->DANH SACH MON HOC/////////////////////
string MENU_DSMH_GV(STreeCH &root, ListMH &dsmh, int selectMode, PtrSV SV)
{
	system("cls");
	int numOfSubjects = 0;
	// tao mang con tro quan li dsmh
	MonHoc *temp[MaxOfSubjects] = {NULL};
	if (selectMode != 2)
	{
		for (int i = 0; i < dsmh.n; i++)
			temp[i] = &dsmh.nodes[i];
		numOfSubjects = dsmh.n;
	}
	// trong che do dang thi cua sv: ktra so mon chua co diem de hien thi ds mon
	else
	{
		for (int i = 0; i < dsmh.n; i++)
			if (((!is_Existed_MaMH_DT(SV->info.danhSachDiemThi, dsmh.nodes[i].maMonHoc)) && (dsmh.nodes[i].is_used == true)))
				temp[numOfSubjects++] = &dsmh.nodes[i];
	}
	int index = 0;
	int page = 1;
	int maxPage = (numOfSubjects - 1) / 10 + 1;

	// kiem tra co phai dang o che do XOA MON HOC
	bool check_Delete = 0;
	// Kiem tra co phai dang o che do HIEU CHINH
	bool check_Edit = 0;

	HienDanhSachMonHoc(temp, numOfSubjects, page, maxPage, selectMode);
	gotoxy(2, 9 + (index % 10 + 1) * 2);
	cout << ">>";

	char ch;
	while (1)
	{
		ch = getch();
		if (ch == -32 || ch == 0)
		{
			ch = getch();
			switch (ch)
			{
			case F1: // tim kiem theo ten mon
			{
				VeKhung(5, 31, 90, 33);
				gotoxy(6, 32);
				cout << "NHAP TEN MON HOC: ";
				string content = NhapChuoi(25, 32, 50);
				int numOfResults = 0;
				if (content == "EXIT")
				{
					delete_AreaOnScreen(5, 31, 95, 3);
					break;
				}
				for (int i = 0; i < dsmh.n; i++)
				{
					if (strstr(dsmh.nodes[i].tenMonHoc, content.data()) != NULL)
					{
						if (selectMode != 2) // khong thi
							temp[numOfResults++] = &dsmh.nodes[i];
						else if (((!is_Existed_MaMH_DT(SV->info.danhSachDiemThi, dsmh.nodes[i].maMonHoc)) && (dsmh.nodes[i].is_used == true))) // thi -> da co diem thi khong hien mon
							temp[numOfResults++] = &dsmh.nodes[i];
					}
				}
				if (numOfResults == 0)
					THONGBAO(2, "KHONG TIM THAY KET QUA");
				else
				{
					// Cập nhật thông tin sau khi tìm kiếm thành công
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					numOfSubjects = numOfResults;
					maxPage = (numOfSubjects - 1) / 10 + 1;
					index = 0;
					page = 1;
					HienDanhSachMonHoc(temp, numOfSubjects, page, maxPage, selectMode);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
					// TODO: Xử lý hiển thị kết quả tìm kiếm
				}
				delete_AreaOnScreen(5, 31, 95, 3);
				break;
			}
			case F5:
			{
				if (selectMode != 2)
				{
					for (int i = 0; i < dsmh.n; i++)
						temp[i] = &dsmh.nodes[i];
					numOfSubjects = dsmh.n;
				}
				else
				{
					int pos = 0;
					int numOfScores = 0;
					for (PtrDT p = SV->info.danhSachDiemThi; p != NULL; p = p->next)
						numOfScores++;
					numOfSubjects = dsmh.n - numOfScores;
					for (int i = 0; i < dsmh.n; i++)
						if (((!is_Existed_MaMH_DT(SV->info.danhSachDiemThi, dsmh.nodes[i].maMonHoc)) && (dsmh.nodes[i].is_used == true)))
							temp[pos++] = &dsmh.nodes[i];
				}
				delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
				maxPage = (numOfSubjects - 1) / 10 + 1;
				index = 0;
				page = 1;
				check_Delete = false;
				check_Edit = false;
				HienDanhSachMonHoc(temp, numOfSubjects, page, maxPage, selectMode);
				gotoxy(2, 9 + (index % 10 + 1) * 2);
				cout << ">>";
				break;
			}
			case UP:
			{
				if (index % 10 == 0 && page > 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page--;
					index--;

					HienDanhSachMonHoc(temp, numOfSubjects, page, maxPage, selectMode);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				else if (index % 10 > 0)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					index--;
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
			}
			case DOWN:
			{
				if (index % 10 == 9 && index < numOfSubjects - 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page++;
					index++;

					HienDanhSachMonHoc(temp, numOfSubjects, page, maxPage, selectMode);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				else if (index % 10 < 9 && index < numOfSubjects - 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					index++;
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
			}
			case PAGEUP:
			{
				if (page > 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page--;
					index = (index / 10) * 10 - 1;

					HienDanhSachMonHoc(temp, numOfSubjects, page, maxPage, selectMode);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
			}
			case PAGEDOWN:
			{
				if (page < maxPage)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page++;
					index = (index / 10 + 1) * 10;
					HienDanhSachMonHoc(temp, numOfSubjects, page, maxPage, selectMode);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
			}
			case RIGHT:
			{
				// dang o che do khong thao tac voi option
				if (check_Delete || check_Edit || selectMode)
					break;

				delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
				// option = HienOptionMonHoc();
				// switch (option)
				switch (HienOptionMonHoc())
				{
				case 0:
					break;
				case 1: // chon che do them mon
				{
					if (is_Full_MH(dsmh))
						THONGBAO(2, "SO LUONG MON HOC DA DAY");
					else if (ThemMonHoc(dsmh))
					{
						for (int i = 0; i < dsmh.n; i++)
							temp[i] = &dsmh.nodes[i];
						numOfSubjects = dsmh.n;
						maxPage = (numOfSubjects - 1) / 10 + 1;
					}
					else
						THONGBAO(2, "DA HUY THAO TAC THEM");

					page = 1;
					index = 0;
					HienDanhSachMonHoc(temp, numOfSubjects, page, maxPage, selectMode);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
					break;
				}
				case 2: // chon che do xoa mon
				{
					if (is_Empty_MH(dsmh))
					{
						THONGBAO(2, "KHONG CO LOP TRONG DANH SACH");
					}
					else
					{
						THONGBAO(2, "CHON MON HOC MUON XOA---AN F5 DE HUY CHON");
						check_Delete = 1;
					}
					break;
				}
				case 3: // chon che do hieu chinh
				{
					if (is_Empty_MH(dsmh))
					{
						THONGBAO(2, "KHONG CO LOP TRONG DANH SACH");
					}
					else
					{
						THONGBAO(2, "CHON MON HOC HIEU CHINH---AN F5 DE HUY CHON");
						check_Edit = 1;
					}
					break;
				}
				case 4: // chon che do xem cau hoi
				{
					if (is_Empty_MH(dsmh))
					{
						THONGBAO(2, "KHONG CO LOP TRONG DANH SACH");
					}
					else
						THONGBAO(2, "CHON MON HOC DE XEM-DANH SACH CAU HOI---AN F5 DE HUY CHON");
					break;
				}
				}
				HienOptionMonHoc(1);
				gotoxy(2, 9 + (index % 10 + 1) * 2);
				cout << ">>";
				break;
			}
			}
		}
		else
		{
			switch (ch)
			{
			case ESC:
				system("cls");
				return "EXIT";
			case ENTER:
			{
				if (selectMode)
				{
					temp[index]->is_used = true;
					system("cls");
					return temp[index]->maMonHoc;
				}
				if (check_Delete) // ktra che do xoa
				{
					if (temp[index]->is_used)
						THONGBAO(2, "KHONG THE XOA-MON HOC DA DUOC SU DUNG");
					else if (THONGBAO(3, "XOA MON HOC?"))
					{
						if (XoaMonHoc(dsmh, temp, index))
						{
							delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
							numOfSubjects = dsmh.n;
							maxPage = (numOfSubjects - 1) / 10 + 1;
							page = 1;
							index = 0;
						}
						// check_Delete = 0;
					}
				}
				else if (check_Edit) // ktra che do hieu chinh
				{
					if (!HieuChinhMonHoc(dsmh, *temp[index], index % 10 + 1))
						THONGBAO(2, "DA HUY-THAO TAC HIEU CHINH");
					else
						THONGBAO(2, "THAO TAC HOAN TAT");
					// check_Edit = 0;
				}
				else
					MENU_DSCH_GV(root, *temp[index]);
				break;
			}
			}
			HienDanhSachMonHoc(temp, numOfSubjects, page, maxPage, selectMode);
			gotoxy(2, 9 + (index % 10 + 1) * 2);
			cout << ">>";
		}
	}
	// return "";
}
void HienDanhSachMonHoc(MonHoc *dsmh[], int numOfSubs, int page, int maxPage, bool selectMode)
{
	// system("cls");
	delete_MenuContent(83);
	SetColor(0, 7);
	VeHeader(4, "DANH SACH MON HOC");
	VeDanhSach(4);
	if (!selectMode)
		HienOptionMonHoc(1);
	int count = 0;
	for (int i = (page - 1) * 10; i <= (page - 1) * 10 + 9 && i < numOfSubs; i++)
	{
		gotoxy(12, 11 + count * 2);
		cout << dsmh[i]->maMonHoc;
		gotoxy(36, 11 + count * 2);
		cout << dsmh[i]->tenMonHoc;
		count++;
	}
	selectMode ? ThanhChucNang(10) : ThanhChucNang(9);
	gotoxy(91, 29);
	cout << "Page " << page << '/' << maxPage;
}
int HienOptionMonHoc(bool types)
{
	string option1 = "    THEM MON HOC        ";
	string option2 = "    XOA MON HOC         ";
	string option3 = "    HIEU CHINH MON HOC  ";
	string option4 = "    XEM DS CAU HOI      ";

	TextColor(112);
	gotoxy(120, 15);
	cout << option1;
	gotoxy(120, 17);
	cout << option2;
	gotoxy(120, 19);
	cout << option3;
	gotoxy(120, 21);
	cout << option4;
	TextColor(7);

	if (types)
		return 0;

	int pos_Y = 15, conTro = 15;

	gotoxy(120, 15);
	TextColor(20);
	cout << option1;
	TextColor(7);

	char ch;
	while (1)
	{
		while ((ch = getch()) == -32)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
				if (pos_Y > 15)
				{
					conTro -= 2;
					TextColor(20);
					gotoxy(120, conTro);
					switch (conTro)
					{
					case 15:
						cout << option1;
						break;
					case 17:
						cout << option2;
						break;
					case 19:
						cout << option3;
						break;
					}
					TextColor(112);
					gotoxy(120, pos_Y);
					switch (pos_Y)
					{
					case 17:
						cout << option2;
						break;
					case 19:
						cout << option3;
						break;
					case 21:
						cout << option4;
						break;
					}
					pos_Y -= 2;
					TextColor(7);
				}
				break;
			case DOWN:
				if (pos_Y < 21)
				{
					conTro += 2;
					TextColor(20);
					gotoxy(120, conTro);
					switch (conTro)
					{
					case 17:
						cout << option2;
						break;
					case 19:
						cout << option3;
						break;
					case 21:
						cout << option4;
						break;
					}
					TextColor(112);
					gotoxy(120, pos_Y);
					switch (pos_Y)
					{
					case 15:
						cout << option1;
						break;
					case 17:
						cout << option2;
						break;
					case 19:
						cout << option3;
						break;
					}
					pos_Y += 2;
					TextColor(7);
				}
				break;
			case LEFT:
				return 0;
			}
		}
		if (ch == ENTER)
			switch (conTro)
			{
			case 15:
				return 1;
			case 17:
				return 2;
			case 19:
				return 3;
			case 21:
				return 4;
			}
		else if (ch == ESC)
			return 0;
	}
}
bool XoaMonHoc(ListMH &dsmh, MonHoc *temp[], int index)
{
	if (is_Empty_MH(dsmh) || index < 0 || index >= dsmh.n)
		return false;
	int i = 0;
	for (i = 0; i < dsmh.n; i++)
		if (strcmp(dsmh.nodes[i].maMonHoc, temp[index]->maMonHoc) == 0)
			break;
	delete_MH(dsmh, i);
	// for (int j = index; j < dsmh.n - 1; j++)
	// 	temp[j] = temp[j + 1];
	return true;
}
bool ThemMonHoc(ListMH &dsmh)
{
	KhungThem(4);
	MonHoc newMH;
	string maMon = "", tenMon = "";
	// kiem tra da nhap du 2 noi dung hay chua
	int check = 0;
	int key = 0;
	string temp = "";

	while (1)
	{
		temp = "";
		switch (key)
		{
		case 0: // nhap ma mon
			temp = NhapMa1(6, 35, 15, maMon);
			if (is_Existed_MaMH_MH(dsmh, maMon))
			{
				THONGBAO(2, "MA MON NAY DA TON TAI");
				delete_LineOnScreen(6, 35, 15);
				maMon = "";
				temp = "";
				continue;
			}
			// else if (is_Empty_CArray(maMon.c_str()))
			// {
			// 	THONGBAO(2, "NHAP MA MON HOC");
			// 	if (check > 0)
			// 		--check;
			// 	// continue;
			// }
			else if (!is_Empty_CArray(maMon.c_str()))
				check++;
			break;
		case 1: // nhap ten mon
			temp = NhapChuoi1(26, 35, 50, tenMon);
			if (is_existed_tenMH(dsmh, tenMon))
			{
				THONGBAO(2, "TEN MON NAY DA TON TAI");
				delete_LineOnScreen(26, 35, 50);
				tenMon = "";
				temp = "";
				continue;
			}
			// else if (is_Empty_CArray(tenMon.c_str()))
			// {
			// 	THONGBAO(2, "NHAP TEN MON HOC");
			// 	if (check > 0)
			// 		--check;
			// 	// continue;
			// }
			else if (!is_Empty_CArray(tenMon.c_str()))
				check++;
			break;
		case 2: // XONG
			gotoxy(92, 34);
			SetColor(1, 3);
			cout << " XONG ";
			SetColor(0, 7);
			char ch = getch();
			switch (ch)
			{
			case LEFT:
				temp = "LEFT";
				gotoxy(92, 34);
				SetColor(7, 0);
				cout << " XONG ";
				SetColor(0, 7);
				break;
			case ENTER:
				if (check < 2)
					THONGBAO(2, "HAY NHAP DU THONG TIN");
				else if (THONGBAO(3, "LUU MON HOC?"))
				{
					strcpy(newMH.maMonHoc, maMon.c_str());
					strcpy(newMH.tenMonHoc, tenMon.c_str());
					insert_MH(dsmh, newMH);
					delete_AreaOnScreen(5, 32, 120, 5);
					return 1;
				}
				else
					return 0;
				break;
			case ESC:
				if (THONGBAO(3, "HUY QUA TRINH?"))
				{
					delete_AreaOnScreen(5, 32, 120, 5);
					return 0;
				}
				break;
			}
		}
		if (temp == "LEFT" && key > 0)
			key--;
		else if (temp == "RIGHT" || temp == "DONE" && key < 2)
			key++;
		else if (temp == "EXIT")
		{
			if (THONGBAO(3, "HUY THAO TAC?"))
			{
				delete_AreaOnScreen(5, 32, 120, 5);
				return 0;
			}
		}
	}
}
bool HieuChinhMonHoc(ListMH dsmh, MonHoc &selectedSubject, int line)
{
	MonHoc temp;
	bool is_Changed = false;

	temp.is_used = selectedSubject.is_used;
	strcpy(temp.maMonHoc, selectedSubject.maMonHoc);

	while (true)
	{
		strcpy(temp.tenMonHoc, NhapChuoi(26, 9 + line * 2, 50).c_str());
		if (is_existed_tenMH(dsmh, temp.tenMonHoc))
		{
			THONGBAO(2, "TEN MON NAY DA TON TAI");
			continue;
		}
		if (is_Empty_CArray(temp.tenMonHoc)) // dung tenMH cu
		{
			strcpy(temp.tenMonHoc, selectedSubject.tenMonHoc);
			return 0;
		}
		else if (strcmp(temp.tenMonHoc, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY QUA TRINH?"))
				return 0;
		}
		else
		{
			if (THONGBAO(3, "LUU THAY DOI?"))
				selectedSubject = temp;
			return 1;
		}
	}
	return 0;
}
bool THEMSINHVIEN(ListLH &dslh, ListMH dsmh, STreeCH root)
{
	system("cls");
	VeKhung(5, 5, 75, 7);
	VeKhung(5, 8, 75, 10);
	gotoxy(6, 6);
	cout << "NHAP MA LOP    : ";
	gotoxy(6, 9);
	cout << "NHAP SO LUONG  : ";
	ThanhChucNang(11);
	LopHoc temp;
	LopHoc *lopHoc;
	int num = 0;
	bool checkMaLH = 0;
	int check = 0;
	while (check == 0)
	{
		strcpy(temp.maLop, NhapMa(23, 6, 11).c_str());
		if (is_Empty_CArray(temp.maLop))
			THONGBAO(2, "HAY NHAP DU THONG TIN");
		else if (strcmp(temp.maLop, "F1") == 0) // F1 = chon lop theo dslh
		{
			strcpy(temp.maLop, MENU_DSLH_GV(dslh, dsmh, root, 1).c_str());
			if (strcmp(temp.maLop, "EXIT") != 0)
				check++;
			system("cls");
			VeKhung(5, 5, 75, 7);
			VeKhung(5, 8, 75, 10);
			gotoxy(6, 6);
			cout << "NHAP MA LOP    : " << temp.maLop;
			gotoxy(6, 9);
			cout << "NHAP SO LUONG  : ";
			ThanhChucNang(11);
		}
		else if (is_Existed_MaLop(dslh, temp.maLop))
			check++;
		else if (strcmp(temp.maLop, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY THAO TAC?"))
				return 0;
		}
		else
		{
			if (THONGBAO(3, "MA LOP KHONG TON TAI-THEM LOP MOI?"))
			{
				delete_AreaOnScreen(5, 32, 125, 5);
				if (ThemLopHoc(dslh, 1, temp.maLop))
				{
					check++;
					delete_AreaOnScreen(5, 32, 125, 5);
					THONGBAO(2, "DA THEM LOP HOC");
				}
				else
					return 0;
			}
		}
	}
	while (check == 1)
	{
		num = NhapSo(23, 9, 5);
		if (num == -1)
		{
			if (THONGBAO(3, "HUY THAO TAC"))
				return 0;
		}
		else if (num == -2)
		{
			THONGBAO(2, "HAY NHAP DU THONG TIN");
		}
		else
			check++;
	}
	for (int i = 0; i < dslh.n; i++)
		if (strcmp(dslh.lh[i]->maLop, temp.maLop) == 0)
		{
			lopHoc = dslh.lh[i];
			break;
		}
	for (int i = 0; i < num; i++)
	{
		THONGBAO(2, "NHAP THONG TIN-SINH VIEN THU " + to_string(i + 1));
		if (!ThemSinhVien(dslh, lopHoc->danhSachSinhVien, dsmh))
			return 0;
	}
	delete_AreaOnScreen(5, 32, 125);
	return 1;
}
void MainProcessing(ListMH &dsmh, ListLH &dslh, STreeCH &root)
{

	doc_danhSachLopHoc(dslh);
	if (TaoFileID() == 0)
		doc_danhSachMonHoc(dsmh);
	doc_danhSachCauHoi(root);
	Sleep(100);

	char ch;
	int option, stop = 0;
	while (1)
	{
		stop = 0;
		string login = DANGNHAP();
		if (login == "EXIT")
		{
			if (THONGBAO(3, "THOAT?"))
				break;
		}
		else if (login == "NONE")
		{
		}
		else if (login == "READ FILE ERROR") // Loi khi doc file ds tai khoan
		{
		}
		else if (login == "GV")
		{
			SinhVien giangVien;
			strcpy(giangVien.ho, "GV");
			strcpy(giangVien.ten, "GV");
			KhoiTao_PtrDT(giangVien.danhSachDiemThi);
			nodeSinhVien temp;
			temp.info = giangVien;
			temp.next = NULL;
			PtrSV p = new nodeSinhVien;
			p = &temp;
			while (stop != 1)
			{
				option = MENU_GV();
				switch (option)
				{
				case 0:
					stop = 1;
					break;
				case 1: // DANH SACH LOP HOC
					MENU_DSLH_GV(dslh, dsmh, root);
					break;
				case 2: // THEM SINH VIEN
					if (THEMSINHVIEN(dslh, dsmh, root))
						THONGBAO(2, "DA HOAN TAT QUA TRINH");
					else
						THONGBAO(2, "DA HUY QUA TRINH");
					break;
				case 3: // DANH SACH MON HOC
					MENU_DSMH_GV(root, dsmh);
					break;
				case 4: // BANG DIEM
				{
					string maLop;
					int index;
					PtrSV pSV = NULL;
					// chon lop
					while ((maLop = MENU_DSLH_GV(dslh, dsmh, root, 1)) != "EXIT")
					{
						for (index = 0; index < dslh.n; index++) // lay lop hoc da chon
							if (strcmp(dslh.lh[index]->maLop, maLop.c_str()) == 0)
								break;
						while ((pSV = MENU_DSSV_GV(dslh, index, dsmh, root, 2)) != NULL)
						{
							MENU_DSDT_GV(pSV->info, dsmh, root, 0);
						}
					}
				}
				break;
				case 5: // THI THU
				{
					Thi(root, p, dsmh);
					delete_First_DT(p->info.danhSachDiemThi);
					break;
				}
				case 6: // THOAT
				{
					if (THONGBAO(3, "DANG XUAT?"))
						stop = 1;
					break;
				}
				}
			}
		}
		else
		{
			PtrSV p = NULL;
			int index;
			bool check = 0;
			for (index = 0; index < dslh.n; index++) // kiem tra tung lop
			{
				// kiem tra so sanh tung sinh vien voi Login
				for (p = dslh.lh[index]->danhSachSinhVien; p != NULL; p = p->next)
				{
					if (strcmp(p->info.MSSV, login.c_str()) == 0)
					{
						check = 1;
						break;
					}
				}
				if (check)
					break;
			}
			while (stop != 1)
			{
				option = MENU_SV(dslh.lh[index]->maLop, p);
				switch (option)
				{
				case 0:
					stop = 1;
					break;
				case 1:
					Thi(root, p, dsmh);
					break;
				case 2:
				{
					MENU_DSDT_GV(p->info, dsmh, root, 1);
					// cin.ignore();
					break;
				}
				case 3:
				{
					if (THONGBAO(3, "DANG XUAT?"))
						stop = 1;
					break;
				}
				}
			}
		}
		ghi_danhSachCauHoi(root);
		ghi_danhSachMonHoc(dsmh);
		ghi_danhSachLopHoc(dslh);
	}
}
