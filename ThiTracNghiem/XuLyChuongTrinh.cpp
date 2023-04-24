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
	string Name, Password;
	chuThiTracNghiem(18, 2);
	gotoxy(60, 15);
	cout << "ACCOUNT";
	VeKhung(68, 14, 90, 16);
	gotoxy(60, 18);
	cout << "PASSWORD";
	VeKhung(68, 17, 90, 19);
	delete_LineOnScreen(69, 15, 21);
	delete_LineOnScreen(69, 18, 21);
	do
	{
		Name = NhapMa(69, 15, 20);
		if (Name == "")
			THONGBAO(1, "NAME RONG!");
		else if (Name == "EXIT")
			return Name;
	} while (Name == "");
	do
	{
		Password = NhapMa(69, 18, 20, "MATKHAU");
		if (Password == "")
			THONGBAO(1, "PASSWORD RONG!");
		else if (Password == "EXIT")
			return Password;
	} while (Password == "");
	switch (KiemTraTK(Name, Password))
	{
	case -1:
		THONGBAO(1, "KHONG CO TAI KHOAN");
		return "NONE";
	case 0:
		THONGBAO(1, "KHONG DOC DUOC FILE");
		return "READ FILE ERROR";
	case 1:
		THONGBAO(1, "LOGIN SV");
		return Name;
	case 2:
		THONGBAO(1, "LOGIN GV");
		return "GV";
	}
}
int MENU_GV()
{
	system("cls");
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
	TextColor(7);

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
				gotoxy(65, 15);
				cout << "      DANH SACH CAC LOP     ";
				break;
			}
			case 17:
			{
				gotoxy(65, 17);
				cout << "      THEM SINH VIEN        ";
				break;
			}
			case 19:
			{
				gotoxy(65, 19);
				cout << "      DANH SACH MON HOC     ";
				break;
			}
			case 21:
			{
				gotoxy(65, 21);
				cout << "      BANG DIEM             ";
				break;
			}
			case 23:
			{
				gotoxy(65, 23);
				cout << "      THI THU               ";
				break;
			}
			case 25:
			{
				gotoxy(65, 25);
				cout << "      THOAT                 ";
				break;
			}
			}

			TextColor(20);
			switch (vi_tri_contro) // to vi tri moi
			{
			case 15:
			{
				gotoxy(65, 15);
				cout << "      DANH SACH CAC LOP     ";
				break;
			}
			case 17:
			{
				gotoxy(65, 17);
				cout << "      THEM SINH VIEN        ";
				break;
			}
			case 19:
			{
				gotoxy(65, 19);
				cout << "      DANH SACH MON HOC     ";
				break;
			}
			case 21:
			{
				gotoxy(65, 21);
				cout << "      BANG DIEM             ";
				break;
			}
			case 23:
			{
				gotoxy(65, 23);
				cout << "      THI THU               ";
				break;
			}
			case 25:
			{
				gotoxy(65, 25);
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
	gotoxy(65, 15);
	TextColor(20); //
	cout << "      THI                   ";
	TextColor(112);
	gotoxy(65, 17);
	cout << "      XEM DIEM              ";
	gotoxy(65, 19);
	cout << "      THOAT                 ";
	TextColor(7);
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
						gotoxy(65, 15);
						TextColor(20);
						cout << "      THI                   ";
						TextColor(112);
						gotoxy(65, 17);
						cout << "      XEM DIEM              ";
					}
					else
					{
						vi_tri_contro = 17;
						TextColor(20);
						gotoxy(65, 17);
						cout << "      XEM DIEM              ";
						TextColor(112);
						gotoxy(65, 19);
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
						gotoxy(65, 15);
						TextColor(112);
						cout << "      THI                   ";
						TextColor(20);
						gotoxy(65, 17);
						cout << "      XEM DIEM              ";
					}
					else
					{
						vi_tri_contro = 19;
						TextColor(112);
						gotoxy(65, 17);
						cout << "      XEM DIEM              ";
						TextColor(20);
						gotoxy(65, 19);
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
	while (time > 0)
	{
		gotoxy(62, 2);
		cout << time;
		gotoxy(65, 2);
		cout << ":phut";
		gotoxy(71, 2);
		cout << "00";
		gotoxy(74, 2);
		cout << ":giay";
		VeKhung(60, 1, 80, 3);
		Sleep(1000);

		gotoxy(62, 2);
		cout << time--;
		giay = 59;

		while (giay >= 0)
		{
			SetColor(0, 7);
			VeKhung(60, 1, 80, 3);
			gotoxy(62, 2);
			cout << "   ";
			gotoxy(62, 2);
			cout << time;
			gotoxy(65, 2);
			cout << ":phut";
			gotoxy(71, 2);
			cout << "   ";
			gotoxy(71, 2);
			cout << giay--;
			gotoxy(74, 2);
			cout << ":giay";
			Sleep(1000);
			if (stopThi == 1)
				return;
		}
	}
	stopThi = 1;
}

void InCauHoiThi(STreeCH &Question, char so_cau_dung[], int i, int so_cau)
{
	char temp[95];
	VeKhungThi();
	if (so_cau_dung[i] == '\0')
	{
		VeKhung(5, 27, 20, 29); // ve khung dap an ban chon
		gotoxy(6, 28);
		cout << "BAN CHUA CHON";
	}
	else if (so_cau_dung[i] == 1)
	{
		VeKhung(5, 27, 20, 29);
		gotoxy(6, 28);
		cout << "BAN CHON " << so_cau_dung[i];
	}
	gotoxy(6, 6);
	if (strlen(Question->info.question) <= 94)
		cout << Question->info.question; // IN CAU HOI
	else
	{
		strncpy(temp, Question->info.question, 94); // copy 94 ki tu 0->93
		cout << temp;
		gotoxy(6, 7);
		cout << &Question->info.question[94];
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
	cout << i + 1 << '/' << so_cau;
}
void Thi(STreeCH &root, PtrSV &SV, ListMH &dsmh)
{
	stopThi = 0;
	int so_cau, thoi_gian, soluongcauhoi;
	char maMH[16];
	thread timer;

	do
	{
		strcpy(maMH, MENU_DSMH_GV(root, dsmh, 1).data());
		soluongcauhoi = DemSoCauHoi(root, maMH);
		if (soluongcauhoi == 0)
			THONGBAO(1, "KHONG CO CAU HOI");
	} while (soluongcauhoi == 0);
	system("cls");

	gotoxy(12, 15);
	cout << "SO CAU HOI:";
	VeKhung(24, 14, 28, 16);
	gotoxy(12, 19);
	cout << "THOI GIAN:";
	VeKhung(24, 18, 28, 20);

	gotoxy(50, 24);
	cout << "SO CAU TOI THIEU: 1| SO CAU TOI DA:" << soluongcauhoi;

	do
	{
		gotoxy(25, 15);
		cout << "   ";
		so_cau = NhapSo(25, 15, 3);
		if (so_cau > soluongcauhoi)
			THONGBAO(1, "NHAP NHIEU HON SO CAU CO SAN"); // in so cau ra nua
		if (so_cau == 0)
			THONGBAO(1, "SO CAU =0 KHONG HOP LE");
		if (so_cau == -1)
		{
			if (THONGBAO(3, "BAN MUON THOAT KHONG"))
				return;
		}
	} while (so_cau > soluongcauhoi || so_cau == 0 || so_cau == -1);
	do
	{
		thoi_gian = NhapSo(25, 19, 3);
		if (thoi_gian == 0)
		{
			THONGBAO(1, "THOI GIAN PHAI LON HON 0");
		}
		if (thoi_gian == -1)
		{
			if (THONGBAO(3, "BAN CO MUON THOAT KHONG"))
				return;
		}
		else
			continue;
	} while (thoi_gian == 0 || thoi_gian == -1);

	timer = thread(DongHo, thoi_gian);
	STreeCH *Questions = GetQuestion(root, maMH, so_cau, soluongcauhoi);
	int chon, index, wherey;
	char YourAnswer[so_cau];
	for (int i = 0; i < so_cau; i++)
		YourAnswer[i] = '0';
	for (int i = 0; i < so_cau; i++)
	{
		Questions[i]->is_used = true;
	}
	for (int i = 0; stopThi != 1;)
	{
		if (i == so_cau)
		{
			stopThi = THONGBAO(3, "BAN CO MUON THOAT KHONG");
			if (stopThi == 0)
				i--;
			else
				break;
		}
		InCauHoiThi(Questions[i], YourAnswer, i, so_cau);
		index = wherey = 10; // thiet lap vi tri
		// XEM LUA CHON
		while (stopThi != 1)
		{
			chon = getch();	 // LAY KI TU TU BAN PHIM
			if (chon == ESC) // NHAN ESC
			{
				stopThi = THONGBAO(3, "BAN CO MUON THOAT KHONG"); // NEU THOAT THI STOP=1 VA THOAT
				THONGBAO(1);
			}
			else if (chon == ENTER) // PHAT HIEN NHAN ENTER VA KIEM TRA DAP AN
			{
				switch (index)
				{
				case 10:
				{
					YourAnswer[i] = 'A'; // chon sai
					break;
				}
				case 14:
				{
					YourAnswer[i] = 'B'; // chon sai
					break;
				}
				case 18:
				{
					YourAnswer[i] = 'C'; // chon sai
					break;
				}
				case 22:
				{
					YourAnswer[i] = 'D'; // chon sai
					break;
				}
				}
				i++; // qua trang moi
				break;
			}
			else if (chon == 224)
				chon = getch(); // NUT MO
			// XU LY DI CHUYEN
			if (chon == 72 && index != 10) // KIEM TRA CO NHAN NUT LEN HAY KHONG VA INDEX KHONG O TAI CAU A
			{
				wherey = index;
				index -= 4;
			}
			else if (chon == 80 && index != 22) // NUT XUONG VA INDEX KHONG TAI CAU D
			{
				wherey = index;
				index += 4;
			}
			else if (chon == 75 && i > 0)
			{
				i--; // lui trang
				break;
			}
			else if (chon == 77 && i < so_cau)
			{
				i++; // qua trang
				break;
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
			switch (index) // TO MAU XANH
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
	cin.ignore();
}
void ThemCauHoi(STreeCH &root, char maMH[], char tenMH[])
{
	int answer = 0, ki_tu;
	STreeCH NewQuestion = newnode();

	NewQuestion->info.ID = ReadID();
	VeBangCauHoi(tenMH, NewQuestion->info.ID);
	strcpy(NewQuestion->info.maMonHoc, maMH);

	do
	{
		strcpy(NewQuestion->info.question, NhapChuoi(21, 10, 188).data());
		if (NewQuestion->info.question[0] == '\0' || strcmp(NewQuestion->info.question, "EXIT") == 0)
			THONGBAO(1, "CAU HOI RONG");
	} while (NewQuestion->info.question[0] == '\0' || strcmp(NewQuestion->info.question, "EXIT") == 0);
	do
	{
		strcpy(NewQuestion->info.ans1, NhapChuoi(21, 13, 94).data());
		if (NewQuestion->info.ans1[0] == '\0' || strcmp(NewQuestion->info.ans1, "EXIT") == 0)
			THONGBAO(1, "DAP AN 1 RONG");
	} while (NewQuestion->info.ans1[0] == '\0' || strcmp(NewQuestion->info.ans1, "EXIT") == 0);
	do
	{
		strcpy(NewQuestion->info.ans2, NhapChuoi(21, 16, 94).data());
		if (NewQuestion->info.ans2[0] == '\0' || strcmp(NewQuestion->info.ans2, "EXIT") == 0)
			THONGBAO(1, "DAP AN 2 RONG");
	} while (NewQuestion->info.ans2[0] == '\0' || strcmp(NewQuestion->info.ans2, "EXIT") == 0);
	do
	{
		strcpy(NewQuestion->info.ans3, NhapChuoi(21, 19, 94).data());
		if (NewQuestion->info.ans3[0] == '\0' || strcmp(NewQuestion->info.ans3, "EXIT") == 0)
			THONGBAO(1, "DAP AN 3 RONG");
	} while (NewQuestion->info.ans3[0] == '\0' || strcmp(NewQuestion->info.ans3, "EXIT") == 0);
	do
	{
		strcpy(NewQuestion->info.ans4, NhapChuoi(21, 22, 94).data());
		if (NewQuestion->info.ans4 == '\0' || strcmp(NewQuestion->info.ans4, "EXIT") == 0)
			THONGBAO(1, "DAP AN 4 RONG");
	} while (NewQuestion->info.ans4[0] == '\0' || strcmp(NewQuestion->info.ans4, "EXIT") == 0);
	gotoxy(21, 25);
	do
	{
		ki_tu = getch();
		if (ki_tu == ENTER && answer >= 'A' && answer <= 'D')
			break;
		if (ki_tu == 224 || ki_tu == 0)
			getch();
		if (ki_tu >= 'A' && ki_tu <= 'D')
		{
			gotoxy(21, 25);
			cout << char(ki_tu);
			answer = ki_tu;
		}
	} while (1);
	NewQuestion->info.answer = answer;
	NewQuestion->is_used = false;
	if (InsertQuestion(root, NewQuestion))
		THONGBAO(1, "THEM CAU HOI THANH CONG");
	THONGBAO(0, "AN PHIM BAT KY DE THOAT");
	getch();
}
void InCauHoi(STreeCH &ExsistQuestion, char tenMH[])
{
	char temp[95]; // 94 ki tu+ ki tu '\0'
	VeBangCauHoi(tenMH, ExsistQuestion->info.ID);
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
void XemCauHoi(STreeCH &root, STreeCH &ExsistQuestion, char tenMH[])
{
	int chon, vi_tri_contro = 16, stop = 0;
	InCauHoi(ExsistQuestion, tenMH);
	TextColor(20);
	gotoxy(120, 16);
	cout << "     HIEU CHINH         ";
	TextColor(112);
	gotoxy(120, 19);
	cout << "     XOA CAU HOI        ";
	SetColor(0, 7);
	while (stop != 1)
	{
		chon = getch();
		switch (chon)
		{
		case ENTER:
		{
			if (vi_tri_contro == 16)
			{
				int contro = 10;
				gotoxy(3, 10);
				cout << ">>";
				while (stop != 1)
				{
					chon = getch();
					switch (chon)
					{
					case ENTER:
					{
						gotoxy(21, contro);
						cout << "                                                                                              ";
						switch (contro)
						{
						case 10:
						{
							gotoxy(21, 11);
							cout << "                                                                                              ";
							strcpy(ExsistQuestion->info.question, NhapChuoi(21, 10, 188).data());
							break;
						}
						case 13:
						{
							strcpy(ExsistQuestion->info.ans1, NhapChuoi(21, 13, 94).data());
							break;
						}
						case 16:
						{
							strcpy(ExsistQuestion->info.ans2, NhapChuoi(21, 16, 94).data());
							break;
						}
						case 19:
						{
							strcpy(ExsistQuestion->info.ans3, NhapChuoi(21, 19, 94).data());
							break;
						}
						case 22:
						{
							strcpy(ExsistQuestion->info.ans4, NhapChuoi(21, 22, 94).data());
							break;
						}
						case 25:
						{
							int ki_tu, answer; // viet ham nhap dap an
							while (1)
							{
								ki_tu = getch();
								if (ki_tu == ENTER && answer >= 'A' && answer <= 'D')
									break;
								if (ki_tu >= 'A' && ki_tu <= 'D')
								{
									gotoxy(21, 25);
									cout << ki_tu;
									answer = ki_tu;
								}
							}
							ExsistQuestion->info.answer = answer;
						}
						break;
						}
					}
					case ESC:
					{
						gotoxy(3, contro);
						cout << "  ";
						stop = 1;
						break;
					}
					case 0:
					case 224:
					{
						chon = getch();
						if (chon == UP && contro != 10)
						{
							gotoxy(3, contro);
							cout << "  ";
							contro -= 3;
							gotoxy(3, contro);
							cout << ">>";
						}
						if (chon == DOWN && contro != 25)
						{
							gotoxy(3, contro);
							cout << "  ";
							contro += 3;
							gotoxy(3, contro);
							cout << ">>";
						}
						break;
					}
					}
				}
				stop = 0;
			}
			else
			{
				if (ExsistQuestion->is_used == true)
					THONGBAO(0, "CAU HOI DA DUOC THI");
				else if (THONGBAO(3, "BAN CO MUON XOA"))
				{
					DeleteQuestion(root, ExsistQuestion);
					// RestoreID();
					return;
				}
			}
			break;
		}
		case ESC:
		{
			if (THONGBAO(3, "BAN CO MUON THOAT KHONG"))
				stop = 1;
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
}
void InDanhSachCH(STreeCH *ListQuestion, char maMH[], int start, int end, int Page, int MaxPage)
{
	int wherey = 10;
	char chuoi[90];
	VeBangDanhSachCauHoi(maMH, MaxPage, Page);
	for (int i = start; i < end; i++)
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
}
int MENU_DSCH_GV(STreeCH &root, MonHoc monHoc) // thi
{
	int NumberQuestion = 0, vi_tri_contro, wherey, chon, MaxPage, Page, stop;
	char chuoi[90];
	STreeCH *ListQuestion = new STreeCH[300];
	Page = 1;
	while (1)
	{
		// XUAT NOI DUNG
		stop = 0, vi_tri_contro = 16;
		NumberQuestion = 0;
		PreTraversal(ListQuestion, root, monHoc.maMonHoc, NumberQuestion); // tim cau hoi
		MaxPage = (NumberQuestion - 1) / 10 + 1;
		if (NumberQuestion == 0)
			THONGBAO(0, "KHONG CO CAU HOI");
		else
		{
			InDanhSachCH(ListQuestion, monHoc.maMonHoc, (Page - 1) * 10, (Page * 10 < NumberQuestion ? Page * 10 : NumberQuestion), Page, MaxPage);
		}
		TextColor(20);
		gotoxy(120, 16);
		cout << "     THEM CAU HOI       ";
		TextColor(112);
		gotoxy(120, 19);
		cout << "     XEM CAU HOI        ";
		SetColor(0, 7);
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
					ThemCauHoi(root, monHoc.maMonHoc, monHoc.tenMonHoc);
					NumberQuestion = 0;
					stop = 1;
					break;
				}
				case 19: // XEM CAU HOI
				{
					wherey = 10;																				  // muon wherey
					for (int i = (Page - 1) * 10; i < (Page * 10 < NumberQuestion ? Page * 10 : NumberQuestion);) // truong hop khong co cau hoi thi khong co con tro
					{
						gotoxy(3, wherey);
						cout << ">>";
						chon = getch();
						if (chon == ENTER)
						{
							XemCauHoi(root, ListQuestion[i], monHoc.tenMonHoc);
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
			case 224:
			{
				chon = getch();
				switch (chon)
				{
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
				if (THONGBAO(3, "BAN CO MUON THOAT KHONG"))
					return 0;
				break;
			}
			}
		}
	}
}
void Tim_End_Start(STreeCH List[], int NOE[], int &start, int &end, int lanthi, int NumberQuestion, int NumberofExams)
{
	start = NOE[lanthi - 1];
	if (lanthi == NumberofExams)
	{
		end = NumberQuestion;
	}
	else
	{
		end = NOE[lanthi];
	}
}
void InCauHoiDaThi(STreeCH root, MonHoc monHoc, char MSSV[], int LANTHI)
{
	STreeCH List[500];
	int NOE[10], NumberQuestion = 0, NumberOfExams = 0;
	char YourAnswer[500];
	docCauHoiDaThi(root, List, NOE, YourAnswer, monHoc, NumberQuestion, NumberOfExams, MSSV);
	if (NumberQuestion == 0)
	{
		THONGBAO(1, "CHUA THI");
		return;
	}

	int MaxPage, Page, start, end, wherey, chon, stop;
	if (LANTHI >= 0)
		Tim_End_Start(List, NOE, start, end, LANTHI, NumberQuestion, NumberOfExams);
	else
		Tim_End_Start(List, NOE, start, end, NumberOfExams, NumberQuestion, NumberOfExams); // hien lan cuoi
	MaxPage = (end - start - 1) / 10 + 1, Page = 1;

	InDanhSachCH(List, monHoc.maMonHoc, start, (end > start + 10 ? start + 10 : end), Page, MaxPage);

	for (int index = start,wherey=10; index < end;)
	{
		gotoxy(3, wherey);
		cout << ">>";
		chon = getch();
		switch (chon)
		{
		case ESC:
		{
			if (THONGBAO(3, "BAN CO MUON THOAT KHONG"))
				return;
		}
		case ENTER:
		{
			InCauHoi(List[index], monHoc.tenMonHoc);
			VeKhung(5, 30, 115, 32);
			gotoxy(6, 31);
			cout << "DAP AN BAN CHON LA:";
			if (YourAnswer[start] >= 'A' && YourAnswer[start] <= 'D')
				cout << YourAnswer[start];
			else
				cout << "CHUA CHON";
			THONGBAO(0, "NHAN ESC DE THOAT");
			while (1)
			{
				chon = getch();
				if (chon == ESC) break;
				
				else if (chon == 224 || chon == 0)
					getch();
			}
			InDanhSachCH(List, monHoc.maMonHoc, start, (end > start + 10 ? start + 10 : end), Page, MaxPage);
			break;
		}
		case 0:
		case 224:
		{
			chon = getch();
			switch (chon)
			{
			case F5:
			{
				if (LANTHI >= 0)
					break;
				int LanThi = 0;
				VeKhung(5, 30, 30, 32);
				gotoxy(6, 31);cout << "NHAP LAN THI MUON XEM:";
				gotoxy(31,31);cout<<"/"<<NumberOfExams<<" LAN";
				while (LanThi < 1 || LanThi > NumberOfExams)
				{
					LanThi = NhapSo(28, 31, 2);
					if(LanThi < 1 || LanThi > NumberOfExams)THONGBAO(0,"SO LAN THI>=1 VA NHO HON BANG TONG LAN THI");//SUA CHO XUONG DONG
				}
				Tim_End_Start(List, NOE, start, end, LanThi, NumberQuestion, NumberOfExams);
				MaxPage = (end - start - 1) / 10 + 1,Page = 1,index=start,wherey=10;
				InDanhSachCH(List, monHoc.maMonHoc, start, (end > start + 10 ? start + 10 : end), Page, MaxPage);
				break;
			}
			case UP:
			{
				if (wherey != 10)
				{
					gotoxy(3, wherey);
					cout << "  ";
					wherey -= 2;
					gotoxy(3, wherey);
					cout << ">>";
					index -= 1;
				}
				else if (wherey == 10 && Page > 1)
				{
					Page--;
					start = NOE[NumberOfExams - 1] + (Page - 1) * 10;
					index=start+9;
					wherey=28;
					InDanhSachCH(List, monHoc.maMonHoc, start, (end > start + 10 ? start + 10 : end), Page, MaxPage);
				}
				break;
			}
			case DOWN:
			{
				if (wherey != 28 && start != end - 1)
				{
					gotoxy(3, wherey);
					cout << "  ";
					wherey += 2;
					gotoxy(3, wherey);
					cout << ">>";
					index += 1;
				}
				else if (wherey == 28 && Page != MaxPage)
				{
					Page++;
					index=start = NOE[NumberOfExams - 1] + (Page - 1) * 10;
					wherey=10;
					InDanhSachCH(List, monHoc.maMonHoc, start, (end > start + 10 ? start + 10 : end), Page, MaxPage);
				}
				break;
			}
			case LEFT:
			{
				if (Page != 1)
				{
					Page--;
					start = NOE[NumberOfExams - 1] + (Page - 1) * 10;
					index=start+9;
					wherey=28;
					InDanhSachCH(List, monHoc.maMonHoc, start, (end > start + 10 ? start + 10 : end), Page, MaxPage);
				}
				break;
			}
			case RIGHT:
			{
				if (Page != MaxPage)
				{
					Page++;
					index = start = NOE[NumberOfExams - 1] + (Page - 1) * 10;
					wherey=10;
					InDanhSachCH(List, monHoc.maMonHoc, start, (end > start + 10 ? start + 10 : end), Page, MaxPage);
				}
				break;
			}
			}
		}
		}
	}

	// while (1)
	// {
	// 	wherey = 10, stop = 0;
	// 	InDanhSachCH(List, monHoc.maMonHoc, start, (end > start + 10 ? start + 10 : end), Page, MaxPage);
	// 	// CHON LUA;
	// 	gotoxy(3, 10);
	// 	cout << ">>";
	// 	while (stop != 1)
	// 	{
	// 		chon = getch();
	// 		switch (chon)
	// 		{
	// 		case ESC:
	// 		{
	// 			if (THONGBAO(3, "BAN CO MUON THOAT KHONG"))
	// 				return;
	// 		}
	// 		case ENTER:
	// 		{
	// 			InCauHoi(List[start], monHoc.tenMonHoc);
	// 			VeKhung(5, 30, 115, 32);
	// 			gotoxy(6, 31);
	// 			cout << "DAP AN BAN CHON LA:";
	// 			if (YourAnswer[start] >= 'A' && YourAnswer[start] <= 'D')
	// 				cout << YourAnswer[start];
	// 			else
	// 				cout << "CHUA CHON";
	// 			THONGBAO(0, "NHAN ESC DE THOAT");
	// 			while (1)
	// 			{
	// 				chon = getch();
	// 				if (chon == ESC)
	// 				{
	// 					stop = 1;
	// 					break;
	// 				}
	// 				else if (chon == 224 || chon == 0)
	// 					getch();
	// 			}
	// 			break;
	// 		}
	// 		case 0:
	// 		case 224:
	// 		{
	// 			chon = getch();
	// 			switch (chon)
	// 			{
	// 			case F5:
	// 			{
	// 				if (LANTHI >= 0)
	// 					break;
	// 				int LanThi = 0;
	// 				VeKhung(5, 30, 30, 32);
	// 				gotoxy(6, 31);
	// 				cout << "NHAP LAN THI MUON XEM:";
	// 				while (LanThi < 1 || LanThi > NumberOfExams)
	// 					LanThi = NhapSo(28, 31, 2);
	// 				Tim_End_Start(List, NOE, start, end, LanThi, NumberQuestion, NumberOfExams);
	// 				MaxPage = (end - start - 1) / 10 + 1;
	// 				Page = 1;
	// 				// if (NumberOfExams >= 1)
	// 				// 	gotoxy(50, 0);
	// 				// cout << "LAN THI THU: " << LanThi;
	// 				// InDanhSachCH(List, monHoc.maMonHoc, start, end, Page, MaxPage);
	// 				stop = 1;
	// 				break;
	// 			}
	// 			case UP:
	// 			{
	// 				if (wherey != 10)
	// 				{
	// 					gotoxy(3, wherey);
	// 					cout << "  ";
	// 					wherey -= 2;
	// 					gotoxy(3, wherey);
	// 					cout << ">>";
	// 					start -= 1;
	// 				}
	// 				else if (wherey == 10 && Page > 1)
	// 				{
	// 					Page--;
	// 					start = NOE[NumberOfExams - 1] + (Page - 1) * 10;
	// 					stop = 1;
	// 				}
	// 				break;
	// 			}
	// 			case DOWN:
	// 			{
	// 				if (wherey != 28 && start != end - 1)
	// 				{
	// 					gotoxy(3, wherey);
	// 					cout << "  ";
	// 					wherey += 2;
	// 					gotoxy(3, wherey);
	// 					cout << ">>";
	// 					start += 1;
	// 				}
	// 				else if (wherey == 28 && Page != MaxPage)
	// 				{
	// 					Page++;
	// 					start = NOE[NumberOfExams - 1] + (Page - 1) * 10;
	// 					stop = 1;
	// 				}
	// 				break;
	// 			}
	// 			case LEFT:
	// 			{
	// 				if (Page != 1)
	// 				{
	// 					Page--;
	// 					start = NOE[NumberOfExams - 1] + (Page - 1) * 10;
	// 					stop = 1;
	// 				}
	// 				break;
	// 			}
	// 			case RIGHT:
	// 			{
	// 				if (Page != MaxPage)
	// 				{
	// 					Page++;
	// 					start = NOE[NumberOfExams - 1] + (Page - 1) * 10;
	// 					stop = 1;
	// 				}
	// 				break;
	// 			}
	// 			}
	// 		}
	// 		}
	// 	}
	// }
}
//****************************************End Phuong*************************************************//
/////////////////////////GV->DANH SACH SINH VIEN/////////////////////

PtrSV MENU_DSSV_GV(ListLH dslh, int classIndex, ListMH dsmh, STreeCH root, int types, string maMon)
{
	// system("cls");

	// tao mang con tro toi da 100 SV de quan li dslk;
	PtrSV temp[100] = {NULL};

	PtrSV p = NULL;
	p = dslh.lh[classIndex]->danhSachSinhVien;

	int numOfStudents = 0;
	// lay dia chi cua cac SV cho mang con tro
	for (int i = 0; p != NULL && i < 100; i++)
	{
		temp[i] = p;
		p = p->next;
		numOfStudents++;
	}

	if (numOfStudents == 0)
		THONGBAO(1, "DANH SACH SINH VIEN RONG");

	int index = 0;
	int page = 1;
	int maxPage = (numOfStudents - 1) / 10 + 1;

	HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, page, maxPage, types, maMon);
	gotoxy(2, 9 + (index % 10 + 1) * 2);
	cout << ">>";

	// check = 0: sap xep theo mssv, 1: sap xep theo ho
	bool checkList = 0;
	// kiem tra co phai dang o che do XOA SINH VIEN
	bool check_Delete = 0;
	// kiem tra co phai dang o che do HIEU CHINH
	bool check_Edit = 0;

	bool check_Question = 0;
	char ch;
	while (1)
	{
		if ((ch = getch()) == -32)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
			{
				if (index % 10 == 0 && page > 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page--;
					index--;
					HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, page, maxPage, types, maMon);
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
					HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, page, maxPage, types, maMon);
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

					HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, page, maxPage, types, maMon);
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
					HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, page, maxPage, types, maMon);
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
					if (ThemSinhVien(dslh, dslh.lh[classIndex]->danhSachSinhVien, dsmh))
					{
						THONGBAO(1, "DA THEM SINH VIEN");
						p = dslh.lh[classIndex]->danhSachSinhVien;
						numOfStudents++;
						maxPage = (numOfStudents - 1) / 10 + 1;
						for (int i = 0; p != NULL; i++)
						{
							temp[i] = p;
							p = p->next;
						}
					}
					else
						THONGBAO(1, "DA HUY QUA TRINH");

					page = 1;
					index = 0;
					HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, page, maxPage, types, maMon);
					gotoxy(2, 9 + (index % 10 + 1) * 2); // di chuyen toi vi tri hien con tro vi tri
					cout << ">>";
					break;
				case 2: // option2: thuc hien chuc nang XOA SINH VIEN
					THONGBAO(1, "CHON SINH VIEN MUON XOA");
					check_Delete = 1;
					break;
				case 3: // option3: thuc hien chuc nang HIEU CHINH thong tin sinh vien
					THONGBAO(1, "CHON SINH VIEN MUON HIEU CHINH");
					check_Edit = 1;
					break;
				case 4: // option4: thuc hien chuc nang in ds DIEMTHI cua 1 sinh vien
					THONGBAO(1, "CHON SINH VIEN MUON XEM DIEM");
					break;
				case 5: // option5: thuc hien chuc nang in ds CAUHOI da thi cua 1 sinh vien
					THONGBAO(1, "HIEN DSCH DA THI");
					check_Question = 1;
					break;
				}
			}
			}
			if (types != 2)
				HienOptionSinhVien(1);
			gotoxy(2, 9 + (index % 10 + 1) * 2);
			cout << ">>";
		}
		else
		{
			switch (ch)
			{
			case ESC:
				return NULL;
			case F5:												 // sap xep theo ho <-> ten(mssv)
				delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2); // di chuyen toi vi tri xoa con tro vi tri
				SortDSSV(temp, numOfStudents, checkList);			 // sap xep lai dssv tuy theo nhu cau
				page = 1;											 // thao tac di chuyen ve dau dssv
				index = 0;
				break;
			case ENTER:
			{
				if (types == 1 || numOfStudents == 0)
					break;
				else if (types == 2) // tra ve PtrSV duoc chi dinh
				{
					return temp[index];
				}
				else if (check_Delete) // thuc hien option XOA SINH VIEN
				{
					if (temp[index]->info.danhSachDiemThi != NULL)
					{
						THONGBAO(1, "KHONG THE XOA SINH VIEN");
					}
					else if (THONGBAO(3, "BAN CHAC CHAN MUON XOA?"))
					{
						numOfStudents--;
						maxPage = (numOfStudents - 1) / 10 + 1;
						XoaSinhVien(dslh.lh[classIndex]->danhSachSinhVien, temp, dslh.lh[classIndex]->maLop, index);
						page = 1;
						index = 0;
					}
					check_Delete = 0;
				}
				else if (check_Edit) // thuc hien option HIEU CHINH
				{
					HieuChinhSinhVien(dslh, dslh.lh[classIndex]->danhSachSinhVien, temp, index);
					check_Edit = 0;
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
					// MENU_DSDT_GV(temp[index]->info, dsmh, root, 0);
					MENU_DSDT_GV(temp[index]->info, dsmh, root, 1);
			}
			}
			HienDanhSachSinhVien(temp, dslh.lh[classIndex]->tenLop, page, maxPage, types, maMon);
			gotoxy(2, 9 + (index % 10 + 1) * 2); // di chuyen toi vi tri hien con tro vi tri
			cout << ">>";
		}
	}
}
// types: 0-> hien dssv co options, 1->hien dsDT theo mon, 2-> hien dssv khong option
void HienDanhSachSinhVien(PtrSV *data, string tenLop, int page, int maxPage, int types, string maMon)
// void HienDanhSachSinhVien(PtrSV *data, string tenLop, int numOfClasses, int page, int maxPage, int types = 0, string maMon = "")
{
	system("cls");
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

	for (int i = (page - 1) * 10; (i < page * 10) && (data[i] != NULL); i++)
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
			while (p != NULL)
			{
				if (strcmp(p->info.maMonHoc, maMon.c_str()) == 0)
				{
					gotoxy(105, 11 + 2 * count);
					if (p->info.diemThi >= 0)
						cout << setprecision(2) << fixed << p->info.diemThi;
					else
						cout << "Chua thi";
					break;
				}
				p = p->next;
			}
		}
		count++;
	}
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
	KhoiTao_PtrDT(newSV.danhSachDiemThi);

	int check = 0;
	while (1) // nhap MSSV
	{
		strcpy(newSV.MSSV, NhapMa(8, 35, 10).c_str());
		if (is_Existed_MSSV_SV(dslh, newSV.MSSV))
			THONGBAO(1, "MSSV DA TON TAI");
		else if (strcmp(newSV.MSSV, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY QUA TRINH?"))
				return 0;
		}
		else if (is_Empty_CArray(newSV.MSSV))
			THONGBAO(1, "HAY NHAP DU THONG TIN");
		else
			break;
	}
	while (1) // nhap HO
	{
		strcpy(newSV.ho, NhapChuoi(26, 35, 50).c_str());
		if (is_Empty_CArray(newSV.ho))
			THONGBAO(1, "HAY NHAP DU THONG TIN");
		else if (strcmp(newSV.ho, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY QUA TRINH?"))
				return 0;
		}
		else
			break;
	}
	while (1) // nhap TEN
	{
		strcpy(newSV.ten, NhapChuoi(81, 35, 15).c_str());
		if (is_Empty_CArray(newSV.ten))
			THONGBAO(1, "HAY NHAP DU THONG TIN");
		else if (strcmp(newSV.ten, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY QUA TRINH?"))
				return 0;
		}
		else
			break;
	}
	while (1) // nhap PASSWORD
	{
		strcpy(newSV.password, NhapMa(101, 35, 11).c_str());
		if (is_Empty_CArray(newSV.password))
			THONGBAO(1, "HAY NHAP DU THONG TIN");
		else if (strcmp(newSV.password, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY QUA TRINH?"))
				return 0;
		}
		else
			break;
	}
	gotoxy(116, 33);
	SetColor(1, 3);
	cout << " NAM ";
	SetColor(0, 7);
	newSV.phai = 0;
	char ch;
	while (1)
	{
		ch = getch();
		if (ch == -32)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
				gotoxy(116, 33);
				SetColor(1, 3);
				cout << " NAM ";
				gotoxy(116, 35);
				SetColor(0, 7);
				cout << " NU  ";
				newSV.phai = 0;
				break;
			case DOWN:
				gotoxy(116, 35);
				SetColor(1, 3);
				cout << " NU  ";
				gotoxy(116, 33);
				SetColor(0, 7);
				cout << " NAM ";
				newSV.phai = 1;
				break;
			}
		}
		else if (ch == ENTER)
		{
			if (THONGBAO(3, "LUU THONG TIN?"))
			{
				insert_Order_SV(dssv, newSV);
				return 1;
			}
		}
		else if (ch == ESC)
		{
			if (THONGBAO(3, "HUY QUA TRINH?"))
				return 0;
		}
	}
}
bool XoaSinhVien(PtrSV &dssv, PtrSV *data, const string &maLH, int index)
{
	removeSinhVienFile(maLH, data[index]->info.MSSV);
	if (data[index] == dssv)
		delete_First_SV(dssv);
	else
	{
		PtrSV p = NULL;
		for (p = dssv; p->next != NULL; p = p->next)
			if (data[index] == p->next)
			{
				delete_After_SV(p);
				break;
			}
	}
	for (int i = index; i < 99; i++)
		data[i] = data[i + 1];
	return 1;
}
bool HieuChinhSinhVien(ListLH dslh, PtrSV dssv, PtrSV *data, int index)
{
	SinhVien tempSV;
	string gioiTinh = "NAM";
	tempSV.phai = 0;
	THONGBAO(1, "NHAP THONG TIN SINH VIEN MOI");
	do // cho nhap MSSV truoc khi nhap thong tin khac
	{
		strcpy(tempSV.MSSV, NhapMa(10, 9 + (index % 10 + 1) * 2, 10).c_str());
		if (is_Existed_MSSV_SV(dslh, tempSV.MSSV))
			THONGBAO(1, "MA SO SINH VIEN DA TON TAI");
		else
			break;
	} while (1);
	if (is_Empty_CArray(tempSV.MSSV)) // neu khong nhap MSSV khac -> dung MSSV cu~
		strcpy(tempSV.MSSV, data[index]->info.MSSV);
	gotoxy(10, 9 + (index % 10 + 1) * 2);
	cout << tempSV.MSSV;

	strcpy(tempSV.ho, NhapChuoi(26, 9 + (index % 10 + 1) * 2, 50).c_str()); // nhap ho
	if (is_Empty_CArray(tempSV.ho))											// neu ENTER khi chua nhap -> dung ho cu~ cua SV
		strcpy(tempSV.ho, data[index]->info.ho);
	gotoxy(26, 9 + (index % 10 + 1) * 2);
	cout << tempSV.ho;

	strcpy(tempSV.ten, NhapChuoi(81, 9 + (index % 10 + 1) * 2, 15).c_str());
	if (is_Empty_CArray(tempSV.ten)) // tuong tu nhu tren
		strcpy(tempSV.ten, data[index]->info.ten);
	gotoxy(81, 9 + (index % 10 + 1) * 2);
	cout << tempSV.ten;

	gioiTinh = NhapChuoi(107, 9 + (index % 10 + 1) * 2, 3); // gan gioi tinh moi(default: NAM)
	if (gioiTinh == "NU")
		tempSV.phai = 1;
	strcpy(tempSV.password, data[index]->info.password); // cap lai mat khau cu~
	KhoiTao_PtrDT(tempSV.danhSachDiemThi);
	tempSV.danhSachDiemThi = data[index]->info.danhSachDiemThi; // cap lai diem thi cu~
	if (THONGBAO(3, "LUU THAY DOI?"))
	{
		changeInfoByPtrArray_SV(data, index, tempSV);
		THONGBAO(1, "DA THAY DOI THONG TIN");
	}
	else
		THONGBAO(1, "DA HUY THAO TAC");
}
//////////////////////////GV->DANH SACH DIEM THI/////////////////////
void MENU_DSDT_GV(SinhVien &data, ListMH dsmh, STreeCH root, bool is_SV)
{
	int numOfScores = 0;
	PtrDT temp[MaxOfSubjects] = {NULL};
	PtrDT p = data.danhSachDiemThi;

	for (int i = 0; p != NULL && i < dsmh.n; i++)
	{
		temp[i] = p;
		p = p->next;
		numOfScores++;
	}
	if (numOfScores == 0)
		THONGBAO(1, "CHUA CO DIEM THI");

	int page = 1;
	int index = 0; // vi tri trong mang con tro
	int maxPage = (numOfScores - 1) / 10 + 1;
	HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, page, maxPage, is_SV);
	gotoxy(2, 9 + (index % 10 + 1) * 2);
	cout << ">>";

	// kiem tra co phai dang o che do XOA DIEM THI
	bool check_Delete = 0;
	// kiem tra co phai dang o che do HIEU CHINH
	bool check_Edit = 0;

	char ch;
	while (1)
	{
		if ((ch = getch()) == -32)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
			{
				if (index % 10 == 0 && page > 1) // truong hop dang o dau trang va ton tai trang truoc thi PgUp
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page--;
					index--;
					HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, page, maxPage, is_SV);

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
				if (index % 10 == 9 && index < numOfScores - 1) // truong hop o cuoi trang va con sinh vien thi PgDn
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page++;
					index++;
					HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, page, maxPage, is_SV);

					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				else if (index % 10 < 9 && index < numOfScores - 1) // truong hop o vi tri khong phai cuoi trang
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
					HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, page, maxPage, is_SV);
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
					HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, page, maxPage, is_SV);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
			}
			break;
			case RIGHT:
			{
				if (check_Delete || check_Edit || is_SV)
					break;
				delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
				switch (HienOptionDiemThi())
				{
				case 0:
					break;
				case 1:
				{
					THONGBAO(1, "CHON MON HOC");
					if (ThemDiemThi(data.danhSachDiemThi, temp, dsmh, root))
					{
						THONGBAO(1, "DA THEM THANH CONG");
						numOfScores++;
					}
					else
						THONGBAO(1, "DA HUY THAO TAC");
					page = 1;
					index = 0;
					HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, page, maxPage, is_SV);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
				case 2:
				{
					THONGBAO(1, "CHON DIEM THI MUON XOA");
					check_Delete = 1;
				}
				break;
				case 3:
				{
					THONGBAO(1, "CHON DIEM THI HIEU CHINH");
					check_Edit = 1;
				}
				break;
				}
				if (!is_SV)
					HienOptionDiemThi(1);
				gotoxy(2, 9 + (index % 10 + 1) * 2);
				cout << ">>";
			}
			break;
			}
		}
		else
		{
			switch (ch)
			{
			case ESC:
				return;
			case F1:
			{
				if (is_SV)
					break;
				THONGBAO(1, "HIEN DSMH");
			}
			break;
			case ENTER:
			{
				if (is_SV)
					break;
				else if (check_Delete)
				{
					if (THONGBAO(3, "XAC NHAN XOA DIEM?"))
					{
						XoaDiemThi(data.danhSachDiemThi, temp, index);
						if (numOfScores-- == 0)
							return;
						maxPage = (numOfScores - 1) / 10 + 1;
						page = 1;
						index = 0;
					}
					check_Delete = 0;
				}
				else if (check_Edit)
				{
					HieuChinhDiemThi(temp, index, index % 10 + 1);
					check_Edit = 0;
				}
			}
			}
			HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, page, maxPage, is_SV);
			gotoxy(2, 9 + (index % 10 + 1) * 2);
			cout << ">>";
		}
	}
}
void HienDiemThi(STreeCH root, MonHoc monHoc, SinhVien &data, int numOfScores)
{
	PtrDT temp[numOfScores] = {NULL};
	PtrDT p = NULL;
	int numOfSubScores = 0;
	bool check = false;
	for (p = data.danhSachDiemThi; p != NULL; p = p->next)
	{
		if (strcmp(p->info.maMonHoc, monHoc.maMonHoc) == 0)
		{
			temp[numOfSubScores++] = p;
			check = true;
		}
		else if (check)
			break;
	}
	THONGBAO(1, "NumOfScore: " + to_string(numOfSubScores));
	int index = 0;
	int page = 1;
	int maxPage = (numOfSubScores - 1) / 10 + 1;
	HienDiemTheoLanThi(temp, numOfSubScores, page, maxPage);
	gotoxy(2, 9 + (index % 10 + 1) * 2);
	cout << ">>";

	char ch;
	while (1)
	{
		if ((ch = getch()) == -32)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
			{
				if (index % 10 == 0 && page > 1) // truong hop dang o dau trang va ton tai trang truoc thi PgUp
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page--;
					index--;
					HienDiemTheoLanThi(temp, numOfSubScores, page, maxPage);
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
				if (index % 10 == 9 && index < numOfSubScores - 1) // truong hop o cuoi trang va con sinh vien thi PgDn
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page++;
					index++;
					HienDiemTheoLanThi(temp, numOfSubScores, page, maxPage);

					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				else if (index % 10 < 9 && index < numOfSubScores - 1) // truong hop o vi tri khong phai cuoi trang
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
					HienDiemTheoLanThi(temp, numOfSubScores, page, maxPage);
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
					HienDiemTheoLanThi(temp, numOfSubScores, page, maxPage);
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
				return;
			case ENTER:
				InCauHoiDaThi(root, monHoc, data.MSSV, numOfSubScores - index);
			}
		}
	}
}
bool ThemDiemThi(PtrDT &dsdt, PtrDT *data, ListMH dsmh, STreeCH root)
{
	DiemThi score;
	strcpy(score.maMonHoc, MENU_DSMH_GV(root, dsmh, 1).c_str());
	if (score.maMonHoc == "EXIT") // khong chon maMH
		return 0;
	PtrDT p = NULL;
	for (p = dsdt; p != NULL; p = p->next)
	{
		if (strcmp(score.maMonHoc, p->info.maMonHoc) == 0) // mon hoc da co diem
		{
			THONGBAO(1, "MON HOC DA CO DIEM");
			return 0;
		}
	}
	THONGBAO(1, "NHAP DIEM THI,0 <= X <= 10");
	delete_AreaOnScreen(120, 15, 25, 6);
	VeKhung(120, 15, 145, 17);
	while (1)
	{
		score.diemThi = NhapSo(121, 16, 5);
		if (score.diemThi == -1) // an ESC khi nhap diem -> return -1;
		{
			if (THONGBAO(3, "HUY THEM DIEM THI?"))
				return 0;
		}
		else if (score.diemThi > 10 || score.diemThi < 0)
		{
			THONGBAO(1, "SAI DU LIEU,0 <= DIEM <= 10");
		}
		else // nhap chinh xac = stop loop
		{
			insert_Order_DT(dsdt, score);
			break;
		}
	}
	p = dsdt;
	for (int i = 0; p != NULL; i++) // dat lai mang con tro
	{
		data[i] = p;
		p = p->next;
	}
	return 1;
}
bool XoaDiemThi(PtrDT &dsdt, PtrDT *data, int index)
{
	if (dsdt == data[index])
		delete_First_DT(dsdt);
	else
	{
		PtrDT p = NULL;
		for (p = dsdt; p->next != NULL; p = p->next)
			if (data[index] == p->next)
			{
				delete_After_DT(p);
				break;
			}
	}
	for (int i = index; i < MaxOfSubjects - 1; i++)
		data[i] = data[i + 1];
	return 1;
}
bool HieuChinhDiemThi(PtrDT *data, int index, int line)
{
	delete_LineOnScreen(78, 9 + line * 2, 5);
	double newScore = -1;
	do
	{
		newScore = NhapSo(78, 9 + line * 2, 5);
		if (newScore == -1)
			return false;
		if (newScore > 10 || newScore < 0)
			THONGBAO(1, "0 <= DIEM <= 10");
	} while (!(newScore >= 0 && newScore <= 10));

	data[index]->info.diemThi = newScore;
	return true;
}
void HienDanhSachDiemThi(ListMH dsmh, PtrDT *data, string MSSV, string ho, string ten, int numOfSubs, int page, int maxPage, bool is_SV)
{
	system("cls");
	TextColor(7);

	VeHeader(3, "DANH SACH DIEM THI", MSSV + " - " + ho + ' ' + ten);
	VeDanhSach(3);
	if (!is_SV)
		HienOptionDiemThi(1);
	int count = 1;
	for (int i = (page - 1) * 10; i < page * 10 && i < numOfSubs; i++)
	{
		gotoxy(6, 9 + count * 2);
		cout << FindName(dsmh, data[i]->info.maMonHoc);
		gotoxy(78, 9 + count * 2);
		cout << setprecision(2) << fixed << data[i]->info.diemThi;
		count++;
	}
	gotoxy(91, 29);
	cout << "Page " << page << '/' << maxPage;
}
void HienDiemTheoLanThi(PtrDT *data, int numOfScore, int page, int maxPage)
{
	system("cls");
	TextColor(7);

	VeHeader(3, "DANH SACH DIEM THI", data[0]->info.maMonHoc);
	VeDanhSach(3);
	delete_LineOnScreen(30, 9, 12);
	gotoxy(33, 9);
	cout << "LAN THI";

	int count = 1;
	for (int i = (page - 1) * 10; i < page * 10 && i < numOfScore; i++)
	{
		gotoxy(37, 9 + count * 2);
		cout << numOfScore - i;
		gotoxy(78, 9 + count * 2);
		cout << setprecision(2) << fixed << data[i]->info.diemThi;
		count++;
	}
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
		check = 2;
	}
	else if (check == 2)
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (data[i]->info.diemThi > data[i]->info.diemThi)
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
	if (index < 1 || index > 3)
		return false; // index = 1, 2 ho?c 3 tuong ?ng v?i maLop, tenLop ho?c nienKhoa
	for (int i = 0; i < numOfClass - 1; i++)
	{
		for (int j = i + 1; j < numOfClass; j++)
		{
			if (index == 1)
			{ // s?p x?p theo maLop
				if (strcmp(dslh[i]->maLop, dslh[j]->maLop) > 0)
				{
					swap(dslh[i], dslh[j]);
				}
			}
			else if (index == 2)
			{ // s?p x?p theo tenLop
				if (strcmp(dslh[i]->tenLop, dslh[j]->tenLop) > 0)
				{
					swap(dslh[i], dslh[j]);
				}
			}
			else
			{ // s?p x?p theo nienKhoa
				if (dslh[i]->nienKhoa > dslh[j]->nienKhoa)
				{
					swap(dslh[i], dslh[j]);
				}
			}
		}
	}
	if (index < 3)
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
	LopHoc temp;
	strcpy(temp.maLop, maLH.c_str());
	while (check == 0)
	{
		strcpy(temp.maLop, NhapMa(8, 35, 11).c_str());
		if (is_Existed_MaLop(dslh, temp.maLop))
			THONGBAO(1, "MA LOP DA TON TAI");
		else if (is_Empty_CArray(temp.maLop))
			THONGBAO(1, "NHAP MA LOP");
		else if (strcmp(temp.maLop, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY QUA TRINH?"))
				return 0;
		}
		else
			check++;
	}

	gotoxy(8, 35);
	cout << temp.maLop;

	while (check == 1)
	{
		strcpy(temp.tenLop, NhapChuoi(26, 35, 50).c_str());
		if (is_Empty_CArray(temp.tenLop))
			THONGBAO(1, "NHAP TEN LOP");
		else if (strcmp(temp.tenLop, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY QUA TRINH?"))
				return 0;
		}
		else
			check++;
	}
	while (check == 2)
	{
		temp.nienKhoa = NhapSo(101, 35, 4);
		if (temp.nienKhoa == -1)
		{
			if (THONGBAO(3, "HUY QUA TRINH?"))
				return 0;
		}
		else if (temp.nienKhoa <= 2000)
			THONGBAO(1, "NAM HOC: X > 2000");
		else
			check++;
	}

	char ch;
	while (1)
	{
		ch = getch();
		switch (ch)
		{
		case ENTER:
		{
			TextColor(0);
			createLopHocFolder(temp.maLop);
			TextColor(7);
			ThemLop(dslh, temp);
			return 1;
		}
		case ESC:
		{
			if (THONGBAO(3, "HUY THAO TAC?"))
				return 0;
		}
		}
	}
}
bool XoaLopHoc(ListLH &dslh, LopHoc **lh, int index)
{
	int i = 0;
	for (i = 0; i < dslh.n; i++)
		if (lh[index] == dslh.lh[i])
			break;
	removeLopHocFolder(lh[index]->maLop);
	XoaLop(dslh, i);
	for (int j = index; j < MaxOfClasses - 1; j++)
		lh[j] = lh[j + 1];
	return 1;
}
bool HieuChinhLopHoc(ListLH dslh, LopHoc **data, int index)
{
	LopHoc tempLH;
	THONGBAO(1, "NHAP THONG TIN - LOP HOC MOI");
	do // cho nhap maLop truoc khi nhap thong tin khac
	{
		strcpy(tempLH.maLop, NhapMa(10, 9 + (index % 10 + 1) * 2, 11).c_str());
		if (is_Existed_MaLop(dslh, tempLH.maLop))
			THONGBAO(1, "MA LOP HOC DA TON TAI");
		else
			break;
	} while (1);
	if (is_Empty_CArray(tempLH.maLop)) // neu khong nhap ma lop khac -> dung ma lop cu~
	{
		strcpy(tempLH.maLop, data[index]->maLop);
		gotoxy(10, 9 + (index % 10 + 1) * 2);
		cout << tempLH.maLop;
	}

	strcpy(tempLH.tenLop, NhapChuoi(26, 9 + (index % 10 + 1) * 2, 50).c_str()); // nhap ten lop
	if (is_Empty_CArray(tempLH.tenLop))											// neu ENTER khi chua nhap -> dung ten lop cu~
		strcpy(tempLH.tenLop, data[index]->tenLop);
	gotoxy(26, 9 + (index % 10 + 1) * 2);
	cout << tempLH.tenLop;

	// xu ly nienKhoa
	tempLH.nienKhoa = NhapSo(101, 9 + (index % 10 + 1) * 2, 4);
	if (tempLH.nienKhoa == 0)
		tempLH.nienKhoa = data[index]->nienKhoa;
	gotoxy(101, 9 + (index % 10 + 1) * 2);
	cout << tempLH.nienKhoa;
	if (THONGBAO(3, "LUU THAY DOI?"))
	{
		tempLH.danhSachSinhVien = data[index]->danhSachSinhVien;
		*data[index] = tempLH;
		THONGBAO(1, "DA THAY DOI THONG TIN");
	}
	else
		THONGBAO(1, "DA HUY THAO TAC");
}
void HienDanhSachLopHoc(LopHoc **data, int numOfClasses, int page, int maxPage, bool types)
{
	system("cls");
	SetColor(0, 7);
	VeHeader(1, "DANH SACH LOP HOC", "");
	VeDanhSach(1);
	if (!types)
		HienOptionLopHoc(1);
	int count = 1;

	for (int index = (page - 1) * 10; (index < page * 10) && (data[index] != NULL) && ((page - 1) * 10 + index % 10 < numOfClasses); index++)
	{
		gotoxy(10, 9 + 2 * count);
		cout << data[index]->maLop;
		gotoxy(26, 9 + 2 * count);
		cout << data[index]->tenLop;
		gotoxy(106, 9 + 2 * count);
		cout << data[index]->nienKhoa;
		count++;
	}
	gotoxy(116, 29);
	cout << "Page " << page << '/' << maxPage;
}
void DanhSachTheoNienKhoa(ListLH dslh, LopHoc **data, int nienKhoa, int &numOfClasses)
{
	LopHoc *temp[MaxOfClasses];
	int newNumOfClasses = 0;
	int index = 0;
	while (index < dslh.n)
	{
		if (dslh.lh[index]->nienKhoa == nienKhoa)
			temp[newNumOfClasses++] = dslh.lh[index];
		index++;
	}
	if (newNumOfClasses == 0)
		THONGBAO(1, "KHONG CO LOP NAO");
	else
	{
		data = temp;
		numOfClasses = newNumOfClasses;
	}
}
string MENU_DSLH_GV(ListLH &dslh, ListMH dsmh, STreeCH root, bool types)
{
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
		if ((ch = getch()) == -32)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
			{
				if (index % 10 == 0 && page > 1) // dang o vi tri dau trang -> PgUp
				{
					HienDanhSachLopHoc(temp, numOfClasses, --page, maxPage, types);
					delete_LineOnScreen(2, 9 + (index-- % 10 + 1) * 2, 2);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				else if (index % 10 > 0) // vi tri khong phai dau trang -> giam di 1
				{
					delete_LineOnScreen(2, 9 + (index-- % 10 + 1) * 2, 2);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
			}
			break;
			case DOWN:
			{
				if (index % 10 == 9 && index < numOfClasses - 1) // dang o vi tri cuoi trang -> PgDn
				{
					HienDanhSachLopHoc(temp, numOfClasses, ++page, maxPage, types);
					delete_LineOnScreen(2, 9 + (index++ % 10 + 1) * 2, 2);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				else if (index % 10 < 9 && index < numOfClasses - 1) // vi tri khong phai cuoi trang -> tang len 1
				{
					delete_LineOnScreen(2, 9 + (index++ % 10 + 1) * 2, 2);
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
					HienDanhSachLopHoc(temp, numOfClasses, --page, maxPage, types);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
			case PAGEDOWN:
				if (page < maxPage)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					index = (index % 10 + 1) * 10;
					HienDanhSachLopHoc(temp, numOfClasses, ++page, maxPage, types);
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
				case 1:
				{
					if (is_Full_LH(dslh))
						THONGBAO(1, "SO LUONG LOP DA DAY");
					else if (ThemLopHoc(dslh))
					{
						temp[dslh.n - 1] = dslh.lh[dslh.n - 1];
						numOfClasses = dslh.n;
						maxPage = (numOfClasses - 1) / 10 + 1;
						THONGBAO(1, "DA THEM THANH CONG");
					}
					else
						THONGBAO(1, "DA HUY THAO TAC");
					index = 0;
					page = 1;
					HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, types);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
				case 2:
				{
					THONGBAO(1, "CHON LOP MUON XOA");
					check_Delete = 1; // bat che do xoa lop duoc chon
				}
				break;
				case 3:
				{
					THONGBAO(1, "CHON LOP HIEU CHINH");
					check_Edit = 1; // bat che do chinh sua lop duoc chon
				}
				break;
				case 4:
				{
					THONGBAO(1, "CHON LOP");
					string maLop = MENU_DSLH_GV(dslh, dsmh, root, 1);
					if (maLop == "EXIT") // bam ESC khi chon ma lop
						break;
					THONGBAO(1, "CHON MON HOC");
					string maMon = MENU_DSMH_GV(root, dsmh, 1);
					int index;
					for (index = 0; index < dslh.n; index++)
						if (strcmp(dslh.lh[index]->maLop, maLop.c_str()) == 0)
							break;
					MENU_DSSV_GV(dslh, index, dsmh, root, 1, maMon);
					HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, 1);

					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
				case 5:
				{
					THONGBAO(1, "NHAP NIEN KHOA");
					delete_AreaOnScreen(120, 15, 26, 11);
					VeKhung(120, 16, 145, 18);
					int year;
					year = NhapSo(121, 17, 4); // nhap nien khoa can xem
					DanhSachTheoNienKhoa(dslh, temp, year, numOfClasses);

					maxPage = (numOfClasses - 1) / 10 + 1;
					index = 0;
					page = 1;
					HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, types);

					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				}
				HienOptionLopHoc(1);

				gotoxy(2, 9 + (index % 10 + 1) * 2);
				cout << ">>";
			}
			break;
			}
		}
		else
		{
			switch (ch)
			{
			case F1: // Hien danh sach mon hoc
			{
				if (types)
					break;
				THONGBAO(1, "HIEN DANH SACH MON HOC");
			}
			break;
			case F5: // sap xep theo ho <-> ten(mssv)
			{
				sortDSLH(temp, dslh.n, check_List);

				index = 0;
				page = 1;
			}
			break;
			case ESC:
				return "EXIT";
			case ENTER:
			{
				if (types)
					return temp[index]->maLop;
				if (check_Delete)
				{
					if (temp[index]->danhSachSinhVien != NULL)
					{
						THONGBAO(1, "KHONG THE XOA LOP HOC");
					}
					else if (THONGBAO(3, "XAC NHAN XOA LOP HOC?"))
					{
						XoaLopHoc(dslh, temp, index);

						numOfClasses--;
						maxPage = (numOfClasses - 1) / 10 + 1;
						index = 0;
						page = 1;
						THONGBAO(1, "DA XOA LOP HOC");
					}
					check_Delete = 0;
				}
				else if (check_Edit)
				{
					HieuChinhLopHoc(dslh, temp, index);
					check_Edit = 0;
				}
				else
				{
					int i;
					for (i = 0; i < dslh.n; i++)
						if (dslh.lh[i] = temp[index])
							break;
					MENU_DSSV_GV(dslh, i, dsmh, root);
				}
			}
			}
			HienDanhSachLopHoc(temp, numOfClasses, page, maxPage, types);
			gotoxy(2, 9 + (index % 10 + 1) * 2);
			cout << ">>";
		}
	}
}
///////////////////////////GV->DANH SACH MON HOC/////////////////////
string MENU_DSMH_GV(STreeCH &root, ListMH &dsmh, bool types)
{
	int numOfSubjects = dsmh.n;

	int index = 0;
	int page = 1;
	int maxPage = (numOfSubjects - 1) / 10 + 1;

	// kiem tra co phai dang o che do XOA MON HOC
	bool check_Delete = 0;
	// Kiem tra co phai dang o che do HIEU CHINH
	bool check_Edit = 0;

	HienDanhSachMonHoc(dsmh, page, maxPage, types);
	gotoxy(2, 9 + (index % 10 + 1) * 2);
	cout << ">>";

	char ch;
	while (1)
	{
		if ((ch = getch()) == -32)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
				if (index % 10 == 0 && page > 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page--;
					index--;

					HienDanhSachMonHoc(dsmh, page, maxPage, types);
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
			case DOWN:
				if (index % 10 == 9 && index < dsmh.n - 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page++;
					index++;

					HienDanhSachMonHoc(dsmh, page, maxPage, types);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				else if (index % 10 < 9 && index < dsmh.n - 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					index++;
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
			case PAGEUP:
				if (page > 1)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page--;
					index = (index / 10) * 10 - 1;

					HienDanhSachMonHoc(dsmh, page, maxPage, types);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
			case PAGEDOWN:
				if (page < maxPage)
				{
					delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
					page++;
					index = (index / 10 + 1) * 10;
					HienDanhSachMonHoc(dsmh, page, maxPage, types);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
				}
				break;
			case RIGHT:
				if (check_Delete || check_Edit || types)
					break;

				delete_LineOnScreen(2, 9 + (index % 10 + 1) * 2, 2);
				switch (HienOptionMonHoc())
				{
				case 0:
					break;
				case 1:
					if (is_Full_MH(dsmh))
						THONGBAO(1, "SO LUONG MON HOC DA DAY");
					else if (ThemMonHoc(dsmh))
						maxPage = (dsmh.n - 1) / 10 + 1;
					else
						THONGBAO(1, "DA HUY THAO TAC THEM");

					page = 1;
					index = 0;
					HienDanhSachMonHoc(dsmh, page, maxPage, types);
					gotoxy(2, 9 + (index % 10 + 1) * 2);
					cout << ">>";
					break;
				case 2:
					THONGBAO(1, "CHON MON HOC MUON XOA");
					check_Delete = 1;
					break;
				case 3:
					THONGBAO(1, "CHON MON HOC HIEU CHINH");
					check_Edit = 1;
					break;
				case 4:
					THONGBAO(1, "CHON MON HOC DE XEM - DANH SACH CAU HOI");
					break;
				}
				gotoxy(2, 9 + (index % 10 + 1) * 2);
				cout << ">>";
			}
		}
		else if (ch == ESC)
			return "EXIT";
		else if (ch == ENTER)
		{
			if (types)
			{
				return dsmh.nodes[index].maMonHoc;
			}
			if (check_Delete)
			{
				if (THONGBAO(3, "XOA MON HOC?"))
				{
					if (XoaMonHoc(dsmh, index))
					{
						maxPage = (dsmh.n - 1) / 10 + 1;
						page = 1;
						index = 0;
					}
					check_Delete = 0;
				}
			}
			else if (check_Edit)
			{
				if (!HieuChinhMonHoc(dsmh, index, index % 10 + 1))
					THONGBAO(1, "DA HUY - THAO TAC HIEU CHINH");
				else
					THONGBAO(1, "THAO TAC HOAN TAT");
			}
			else
				MENU_DSCH_GV(root, dsmh.nodes[index]);

			HienDanhSachMonHoc(dsmh, page, maxPage, types);
			gotoxy(2, 9 + (index % 10 + 1) * 2);
			cout << ">>";
		}
	}
	return "";
}
void HienDanhSachMonHoc(ListMH dsmh, int page, int maxPage, bool types)
{
	system("cls");
	SetColor(0, 7);
	VeHeader(4, "DANH SACH MON HOC");
	VeDanhSach(4);
	if (!types)
		HienOptionMonHoc(1);
	int count = 0;
	for (int i = (page - 1) * 10; i <= (page - 1) * 10 + 9 && i < dsmh.n; i++)
	{
		gotoxy(12, 11 + count * 2);
		cout << dsmh.nodes[i].maMonHoc;
		gotoxy(36, 11 + count * 2);
		cout << dsmh.nodes[i].tenMonHoc;
		count++;
	}
	gotoxy(91, 29);
	cout << "Page " << page << '/' << maxPage;
}
int HienOptionMonHoc(bool check)
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
bool XoaMonHoc(ListMH &dsmh, int index)
{
	if (is_Empty_MH(dsmh) || index < 0 || index >= dsmh.n)
		return false;
	for (int i = index; i < dsmh.n - 1; i++)
		dsmh.nodes[i] = dsmh.nodes[i + 1];
	dsmh.n--;
	return true;
}
bool ThemMonHoc(ListMH &dsmh)
{
	KhungThem(4);
	MonHoc newMH;
	// kiem tra da nhap du 2 noi dung hay chua
	int check = 0;

	while (check == 0)
	{
		strcpy(newMH.maMonHoc, NhapMa(6, 35, 15).c_str());
		if (is_Existed_MaMH_MH(dsmh, newMH.maMonHoc))
		{
			THONGBAO(1, "MA MON NAY DA TON TAI");
			continue;
		}
		else if (is_Empty_CArray(newMH.maMonHoc))
		{
			THONGBAO(1, "NHAP MA MON HOC");
			continue;
		}
		else if (strcmp(newMH.maMonHoc, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY THAO TAC?"))
				return 0;
		}
		else
			check++;
	}
	while (check == 1)
	{
		strcpy(newMH.tenMonHoc, NhapChuoi(26, 35, 50).c_str());
		if (is_Empty_CArray(newMH.tenMonHoc))
		{
			THONGBAO(1, "NHAP TEN MON HOC");
			continue;
		}
		else if (strcmp(newMH.tenMonHoc, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY THAO TAC?"))
				return 0;
		}
		else
			check++;
	}
	char ch;
	while (1)
	{
		ch = getch();
		switch (ch)
		{
		case ENTER:
			insert_MH(dsmh, newMH);
			return 1;
		case ESC:
			if (THONGBAO(3, "HUY THAO TAC?"))
				return 0;
		}
	}
	return 1;
}
bool HieuChinhMonHoc(ListMH &dsmh, int index, int line)
{
	MonHoc temp;
	bool is_Changed = false;

	strcpy(temp.maMonHoc, dsmh.nodes[index].maMonHoc);

	while (1)
	{
		strcpy(temp.tenMonHoc, NhapChuoi(26, 9 + line * 2, 50).c_str());
		if (is_Empty_CArray(temp.tenMonHoc)) // dung tenMH cu
		{
			strcpy(temp.tenMonHoc, dsmh.nodes[index].tenMonHoc);
			break;
		}
		else if (strcmp(temp.tenMonHoc, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY QUA TRINH?"))
				return 0;
		}
		else
		{
			is_Changed = true;
			break;
		}
		gotoxy(26, 9 + line * 2);
		cout << temp.tenMonHoc;
	}
	char ch;
	while (1)
	{
		if (!is_Changed)
			break;
		ch = getch();
		switch (ch)
		{
		case ENTER:
		{
			set_Info_MH(dsmh, index, temp);
			return 1;
		}
		case ESC:
		{
			if (THONGBAO(3, "HUY QUA TRINH?"))
				return 0;
		}
		}
	}
	return 1;
}
bool THEMSINHVIEN(ListLH &dslh, ListMH dsmh)
{
	system("cls");
	VeKhung(5, 5, 75, 7);
	VeKhung(5, 8, 75, 10);
	gotoxy(6, 6);
	cout << "NHAP MA LOP    : ";
	gotoxy(6, 9);
	cout << "NHAP SO LUONG  : ";
	LopHoc temp;
	LopHoc *lopHoc;
	int num = 0;
	bool checkMaLH = 0;
	int check = 0;
	while (check == 0)
	{
		strcpy(temp.maLop, NhapMa(25, 6, 11).c_str());
		if (is_Empty_CArray(temp.maLop))
			THONGBAO(1, "HAY NHAP DU THONG TIN");
		else if (is_Existed_MaLop(dslh, temp.maLop))
			check++;
		else if (strcmp(temp.maLop, "EXIT") == 0)
		{
			if (THONGBAO(3, "HUY THAO TAC?"))
				return 0;
		}
		else
		{
			if (THONGBAO(3, "MA LOP KHONG TON TAI - THEM LOP MOI?"))
			{
				delete_AreaOnScreen(5, 32, 120, 5);
				if (ThemLopHoc(dslh, 1, temp.maLop))
				{
					check++;
					delete_AreaOnScreen(5, 32, 120, 5);
					THONGBAO(1, "DA THEM LOP HOC");
				}
				else
					return 0;
			}
		}
	}
	while (check == 1)
	{
		num = NhapSo(25, 9, 5);
		if (num <= 0)
			THONGBAO(1, "HAY NHAP DU THONG TIN");
		else if (num == -1)
		{
			return 0;
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
		THONGBAO(1, "NHAP THONG TIN - SINH VIEN THU " + to_string(i + 1));
		if (!ThemSinhVien(dslh, lopHoc->danhSachSinhVien, dsmh))
			return 0;
	}
	delete_AreaOnScreen(5, 32, 120);
	return 1;
}
void MainProcessing(ListMH &dsmh, ListLH &dslh, STreeCH &root)
{

	doc_danhSachLopHoc(dslh);
	doc_danhSachMonHoc(dsmh);
	cout << "JE";
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
				case 1: // DANH SACH LOP HOC
					MENU_DSLH_GV(dslh, dsmh, root);
					break;
				case 2: // THEM SINH VIEN
					if (THEMSINHVIEN(dslh, dsmh))
						THONGBAO(1, "DA HOAN TAT QUA TRINH");
					else
						THONGBAO(1, "DA HUY QUA TRINH");
					break;
				case 3: // DANH SACH MON HOC
					MENU_DSMH_GV(root, dsmh);
					break;
				case 4: // BANG DIEM
				{
					// chon lop
					THONGBAO(1, "CHON LOP");
					string maLop = MENU_DSLH_GV(dslh, dsmh, root, 1);
					if (maLop == "EXIT") // bam ESC khi chon lop -> return "EXIT"
						break;
					int index;
					for (index = 0; index < dslh.n; index++) // lay lop hoc da chon
						if (strcmp(dslh.lh[index]->maLop, maLop.c_str()) == 0)
							break;
					THONGBAO(1, "CHON SINH VIEN");
					PtrSV pSV = MENU_DSSV_GV(dslh, index, dsmh, root, 2);
					if (pSV == NULL) // bam ESC khi chon sinh vien -> return NULL
						break;
					// MENU_DSDT_GV(pSV->info, dsmh, root, 0);
					MENU_DSDT_GV(pSV->info, dsmh, root, 1);
				}
				break;
				case 5: // THI THU
				{
					Thi(root, p, dsmh);
					break;
				}
				case 6: // THOAT
				{
					if (THONGBAO(3, "DANH XUAT?"))
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
				case 1:
					Thi(root, p, dsmh);
					break;
				case 2:
				{
					PtrDT temp[MaxOfSubjects] = {NULL};
					PtrDT pDT = p->info.danhSachDiemThi;
					for (int i = 0; pDT != NULL; i++)
					{
						temp[i] = pDT;
						pDT = pDT->next;
					}
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
