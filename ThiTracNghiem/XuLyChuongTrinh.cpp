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
int MENU_GV(ListMH &dsmh, ListLH &dslh, STreeCH &root)
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
				MENU_DSLH_GV(dslh, dsmh, root);
				break;
			case 17:
				THEMSINHVIEN(dslh, dsmh);
				break;
			case 19:
				MENU_DSMH_GV(root, dsmh);
				break;
			case 21:
				break; // chua lam`
			case 23:
				SinhVien giangVien;
				strcpy(giangVien.ho, "gv");
				strcpy(giangVien.ten, "gv");
				strcpy(giangVien.MSSV, "GV");
				strcpy(giangVien.password, "gv");
				giangVien.phai = 0;
				KhoiTao_PtrDT(giangVien.danhSachDiemThi);
				nodeSinhVien temp;
				temp.info = giangVien;
				temp.next = NULL;
				PtrSV p = new nodeSinhVien;
				p = &temp;
				Thi(root, p);
				return 5; 
			case 25:
				if (THONGBAO(3, "DANH XUAT?"))
					return 0;
				else
					break;
			}
			break;
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
int MENU_SV(string maLop, SinhVien &data)
{
	system("cls");
	VeKhung(25, 7, 125, 10);
	chuMenuSV(32, 2);
	// cho nay them vao maLop sao khi doc va tro toi ma lop cua TKSV
	gotoxy(30, 9);
	cout << maLop;
	// cho nay them vao maSSV sao khi doc va tro toi ma lop cua TKSV
	gotoxy(50, 9);
	cout << data.MSSV;
	// cho nay them vao tenSV sao khi doc va tro toi ma lop cua TKSV
	gotoxy(73, 9);
	cout << data.ho << " " << data.ten;
	// cho nay them vao gioiTinh sao khi doc va tro toi ma lop cua TKSV
	gotoxy(110, 9);
	cout << data.phai;
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

//*********************************PHUONG*********************//
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
		Sleep(980);

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
			Sleep(980);
			if (stopThi == 1)
				return;
		}
	}
	stopThi = 1;
}
void Thi(STreeCH &root, PtrSV &SV)
{
	int so_cau, thoi_gian, soluongcauhoi;
	char mon[51];
	thread timer;

	system("cls");
	gotoxy(12, 11);
	cout << "MA MON THI:";
	VeKhung(24, 10, 40, 12);
	gotoxy(12, 15);
	cout << "SO CAU HOI:";
	VeKhung(24, 14, 28, 16);
	gotoxy(12, 19);
	cout << "THOI GIAN:";
	VeKhung(24, 18, 28, 20);

	// nhap va kiem tra xem co mon do khong
	do
	{
		gotoxy(25, 11);
		cout << "               "; // xoa vung nhap de nhap
		strcpy(mon, NhapChuoi(25, 11, 15).data());
		if (strcmp(mon, "ESC") == 0)
		{
			if (THONGBAO(3, "BAN MUON THOAT KHONG"))
				return;
		}
		else
		{
			soluongcauhoi = DemSoCauHoi(root, mon);
			if (soluongcauhoi == 0)
				THONGBAO(1, "KHONG CO CAU HOI");
		}
	} while (soluongcauhoi == 0);

	do
	{
		gotoxy(25, 15);
		cout << "   ";
		so_cau = NhapSo(25, 15, 3);
		if (so_cau > soluongcauhoi)
			THONGBAO(1, "NHAP NHIEU HON SO CAU CO SAN"); // in so cau ra nua
		if (so_cau == 0)
			THONGBAO(1, "SO CAU =0 KHONG HOP LE");
	} while (so_cau > soluongcauhoi || so_cau == 0);
	do
	{
		thoi_gian = NhapSo(25, 19, 3);
		if (thoi_gian == 0)
		{
			THONGBAO(1, "THOI GIAN PHAI LON HON 0");
		}
	} while (thoi_gian == 0);

	timer = thread(DongHo, thoi_gian);
	STreeCH *Questions = GetQuestion(root, mon, so_cau, soluongcauhoi);
	int so_cau_dung[so_cau], chon, index, wherey; // 10=A 14=B 18=C 22=D
	char temp[90];
	for (int i = 0; i < so_cau; i++) // LUU CAU DA TRA LOI: DUNG = 1,  sai = -1 / -2 / -3 / -4,  chua chon =0
		so_cau_dung[i] = 0;

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
		index = wherey = 10; // GAN TAI VI TRI CAU A

		VeKhungThi();

		if (so_cau_dung[i] == 0)
		{
			VeKhung(5, 27, 20, 29); // ve khung dap an ban chon
			gotoxy(6, 28);
			cout << "BAN CHUA CHON";
		}
		else if (so_cau_dung[i] == 1)
		{
			VeKhung(5, 27, 20, 29);
			gotoxy(6, 28);
			switch (Questions[i]->info.answer)
			{
			case 1:
			{
				cout << " BAN CHON A";
				break;
			}
			case 2:
			{
				cout << " BAN CHON B";
				break;
			}
			case 3:
			{
				cout << " BAN CHON C";
				break;
			}
			case 4:
			{
				cout << " BAN CHON D";
				break;
			}
			}
		}
		else
		{
			VeKhung(5, 27, 20, 29);
			gotoxy(6, 28);
			switch (so_cau_dung[i])
			{
			case -1:
			{
				cout << " BAN CHON A";
				break;
			}
			case -2:
			{
				cout << " BAN CHON B";
				break;
			}
			case -3:
			{
				cout << " BAN CHON C";
				break;
			}
			case -4:
			{
				cout << " BAN CHON D";
				break;
			}
			}
		}
		gotoxy(6, 6);
		if (strlen(Questions[i]->info.question) < 94)
			cout << Questions[i]->info.question; // IN CAU HOI
		else
		{
			strncpy(temp, Questions[i]->info.question, 90); // copy 89 ki tu
			cout << temp;
			gotoxy(6, 7);
			cout << &Questions[i]->info.question[90];
		}
		gotoxy(16, 10);
		cout << Questions[i]->info.ans1; // IN CAU A
		gotoxy(16, 14);
		cout << Questions[i]->info.ans2; // IN CAU B
		gotoxy(16, 18);
		cout << Questions[i]->info.ans3; // IN CAU C
		gotoxy(16, 22);
		cout << Questions[i]->info.ans4; // IN CAU D
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
				if ((Questions[i]->info.answer == 1 && index == 10) || (Questions[i]->info.answer == 2 && index == 14) || (Questions[i]->info.answer == 3 && index == 18) || (Questions[i]->info.answer == 4 && index == 22))
					so_cau_dung[i] = 1;
				else
				{
					switch (index)
					{
					case 10:
					{
						so_cau_dung[i] = -1; // chon sai
						break;
					}
					case 14:
					{
						so_cau_dung[i] = -2; // chon sai
						break;
					}
					case 18:
					{
						so_cau_dung[i] = -3; // chon sai
						break;
					}
					case 22:
					{
						so_cau_dung[i] = -4; // chon sai
						break;
					}
					}
				}
				i++; // qua trang moi
				break;
			}
			else if (chon == 224)
				chon = getch(); // NUT MO RÃ¯Â¿Â½NG NÃ¯Â¿Â½N LÃ¯Â¿Â½Y THÃ¯Â¿Â½M MÃ¯Â¿Â½T LAN NUA
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
			SetColor(0, 7); // DAT LAI MAU CHU VA NÃ¯Â¿Â½N
		}
	}
	GhiCauHoiDaThi(SV->info.MSSV, Questions, so_cau_dung, so_cau);
	// TINH DIEM

	stopThi = 1;
	timer.join();
}
/////////////////////////GV->DANH SACH SINH VIEN/////////////////////
// Menu chuc nang voi danh sach sinh vien(role: GV)
void MENU_DSSV_GV(LopHoc *data, ListMH dsmh)
{
	// system("cls");

	PtrSV p;

	int numOfStudents = 0;
	for (p = data->danhSachSinhVien; p != NULL; p = p->next)
		numOfStudents++;
	// tao mang con tro toi da 100 SV de quan li dslk;
	PtrSV temp[100] = {NULL};
	p = data->danhSachSinhVien;

	// lay dia chi cua cac SV cho mang con tro
	for (int i = 0; p != NULL && i < 100; i++)
	{
		temp[i] = p;
		p = p->next;
	}

	int line = 1, start = 1, count = 1, option = 0;
	int page = 1, maxPage = (numOfStudents - 1) / 10 + 1;

	HienDanhSachSinhVien(temp, data->tenLop, start);
	gotoxy(2, 9 + line * 2);
	cout << ">>";
	gotoxy(116, 29);
	cout << "Page " << page << '/' << maxPage;
	HienOptionSinhVien(1);

	// check = 0: sap xep theo mssv, 1: sap xep theo ho
	bool checkList = 0;
	// kiem tra co phai dang o che do XOA SINH VIEN
	bool check_Delete = 0;
	// kiem tra co phai dang o che do HIEU CHINH
	bool check_Edit = 0;
	char ch;
	while ((ch = getch()) != ESC)
	{
		if (ch == -32)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
				if (line == 1 && start > 10)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 10;
					start -= 10;
					count--;
					HienDanhSachSinhVien(temp, data->tenLop, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << --page << '/' << maxPage;
				}
				else if (line > 1 && count > 1)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line--;
					count--;
					gotoxy(2, 9 + line * 2);
					cout << ">>";
				}
				break;
			case DOWN:
				if (line == 10 && count < numOfStudents)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 1;
					start += 10;
					count++;
					HienDanhSachSinhVien(temp, data->tenLop, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << ++page << '/' << maxPage;
				}
				else if (line < 10 && count < numOfStudents)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line++;
					count++;
					gotoxy(2, 9 + line * 2);
					cout << ">>";
				}
				break;
			case RIGHT: // chuyen tu thao tac dssv sang option dssv
				if (check_Delete || check_Edit)
					break;
				delete_LineOnScreen(2, 9 + line * 2, 2);
				switch (option = HienOptionSinhVien())
				{
				case 0: // option0: do nothing
					break;
				case 1: // option1: thuc hien chuc nang THEM SINH VIEN
				{
					SetColor(0, 7);
					ThemSinhVien(data->danhSachSinhVien, dsmh);
					p = data->danhSachSinhVien;
					numOfStudents++;
					maxPage = (numOfStudents - 1) / 10 + 1;
					for (int i = 0; p != NULL; i++)
					{
						temp[i] = p;
						p = p->next;
					}
					start = count = line = page = 1;
					HienDanhSachSinhVien(temp, data->tenLop, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << page << '/' << maxPage;
					HienOptionSinhVien(1);
					break;
				}
				case 2: // option2: thuc hien chuc nang XOA SINH VIEN
				{
					THONGBAO(1, "CHON SINH VIEN MUON XOA");
					check_Delete = 1;
					break;
				}
				case 3: // option3: thuc hien chuc nang HIEU CHINH thong tin sinh vien
					THONGBAO(1, "CHON SINH VIEN MUON HIEU CHINH");
					check_Edit = 1;
					break;
				case 4: // option4: thuc hien chuc nang in ds DIEMTHI cua 1 sinh vien
					THONGBAO(1, "CHON SINH VIEN MUON XEM DIEM");
					break;
				case 5: // option5: thuc hien chuc nang in ds CAUHOI da thi cua 1 sinh vien
					THONGBAO(1, "HIEN DSCH DA THI");
					break;
				default:
					THONGBAO(1, "CO LOI TRONG OPTION SINH VIEN");
					break;
				}
				HienOptionSinhVien(1); // tro lai thao tac voi dssv->tra ve option dssv nguyen ban
				gotoxy(2, 9 + line * 2);
				cout << ">>";
				break;
			case PAGEUP:
				if (page > 1)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 10;
					start -= 10;
					count = (count / 10) * 10;
					HienDanhSachSinhVien(temp, data->tenLop, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << --page << '/' << maxPage;
				}
				break;
			case PAGEDOWN:
				if (page < maxPage)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 1;
					start += 10;
					count = ((count - 1) / 10 + 1) * 10 + 1;
					HienDanhSachSinhVien(temp, data->tenLop, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << ++page << '/' << maxPage;
				}
				break;
			}
		}
		else
		{
			switch (ch)
			{
			case F5:									  // sap xep theo ho <-> ten(mssv)
				delete_LineOnScreen(2, 9 + line * 2, 2);  // di chuyen toi vi tri xoa con tro vi tri
				SortDSSV(temp, numOfStudents, checkList); // sap xep lai dssv tuy theo nhu cau
				start = page = line = count = 1;		  // thao tac di chuyen ve dau dssv

				HienDanhSachSinhVien(temp, data->tenLop, start);
				HienOptionSinhVien(1);
				gotoxy(2, 9 + line * 2);
				cout << ">>";
				gotoxy(116, 29);
				cout << "Page " << page << '/' << maxPage;
				break;
			case ENTER:
				if (check_Delete) // thuc hien option XOA SINH VIEN
				{
					if (THONGBAO(3, "BAN CHAC CHAN MUON XOA?"))
					{
						numOfStudents--;
						maxPage = (numOfStudents - 1) / 10 + 1;
						XoaSinhVien(data->danhSachSinhVien, temp, count);
						line = page = count = start = 1;
					}

					check_Delete = 0;
				}
				else if (check_Edit) // thuc hien option HIEU CHINH
				{
					HieuChinhSinhVien(data->danhSachSinhVien, temp, count - 1, line);
					check_Edit = 0;
				}
				else // ENTER khi chua bat thao tac(Xoa, Hieu chinh) -> truy cap vao dsDT
					MENU_DSDT_GV(temp[count - 1]->info, dsmh);

				HienDanhSachSinhVien(temp, data->tenLop, start);
				HienOptionSinhVien(1);
				gotoxy(2, 9 + line * 2); // di chuyen toi vi tri hien con tro vi tri
				cout << ">>";
				gotoxy(116, 29);
				cout << "Page " << page << '/' << maxPage;
				break;
			}
		}
	}
}
void HienDanhSachSinhVien(PtrSV *data, string tenLop, int start)
{
	system("cls");
	SetColor(0, 7);
	VeHeader(2, "DANH SACH SINH VIEN", tenLop);
	VeDanhSach(2);
	HienOptionSinhVien(1);
	int count = 0;

	for (int i = start - 1; i < start + 9 && data[i] != NULL; i++)
	{
		gotoxy(10, 11 + 2 * count);
		cout << data[i]->info.MSSV;
		gotoxy(26, 11 + 2 * count);
		cout << data[i]->info.ho;
		gotoxy(81, 11 + 2 * count);
		cout << data[i]->info.ten;
		gotoxy(107, 11 + 2 * count);
		cout << (data[i]->info.phai ? "NU" : "NAM");
		count++;
	}
	gotoxy(0, 40);
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
// void swapSV(SinhVien &a, SinhVien &b);
void SortDSSV(PtrSV *data, int n, bool &check)
{
	PtrSV temp = NULL;
	if (check)
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (strcmp(data[i]->info.MSSV, data[j]->info.MSSV) > 0)
				{
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
		check = false;
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (strcmp(data[i]->info.ho, data[j]->info.ho) > 0)
				{
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
				}
		check = true;
	}
}
bool ThemSinhVien(PtrSV &dssv, ListMH dsmh)
{
	KhungThem(2);
	char ch;
	int pos = 1, check = 1; // check: kiem tra xem da nhap thong tin toi vi tri nao(1: ho, 2: ten, 3: password, 4:xong)
	bool is_Choosed = 0;
	SinhVien temp;
	KhoiTao_PtrDT(temp.danhSachDiemThi);
	temp.danhSachDiemThi = set_Blank_dsDT_SV(dsmh); // tao dsDT co tat ca cac mon deu CHUA THI
	gotoxy(116, 33);
	SetColor(1, 3);
	cout << " NAM ";
	SetColor(0, 7);
	gotoxy(116, 35);
	cout << " NU  ";
	temp.phai = 0; // gan gioi tinh mac dinh cho SV moi la NAM

	strcpy(temp.MSSV, NhapMa(8, 35, 10).c_str());
	while (is_Existed_MSSV_SV(dssv, temp.MSSV))
	{
		THONGBAO(1, "MSSV DA TON TAI");
		delete_LineOnScreen(8, 35, 10);
		strcpy(temp.MSSV, NhapMa(8, 35, 10).c_str());
	}
	while (is_Empty_CArray(temp.MSSV)) // bat buoc nhap MSSV truoc khi nhap cac thong tin khac
	{
		if (THONGBAO(3, "CHUA NHAP MSSV, HUY THAO TAC?"))
			return 0;
		delete_LineOnScreen(8, 35, 10);
		strcpy(temp.MSSV, NhapMa(8, 35, 10).c_str());
	}
	while (1)
	{
		if ((ch = getch()) == -32)
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
				temp.phai = 0;
				break;
			case DOWN:
				gotoxy(116, 33);
				SetColor(0, 7);
				cout << " NAM ";
				gotoxy(116, 35);
				SetColor(1, 3);
				cout << " NU  ";
				SetColor(0, 7);
				temp.phai = 1;
				break;
			}
		}
		else if (ch == ESC)
		{
			if (THONGBAO(3, "BAN MUON HUY QUA TRINH?"))
				return 0;
		}
		else if (ch == ENTER)
		{
			if (check == 4)
			{
				insert_Order_SV(dssv, temp);
				THONGBAO(1, "DA THEM THANH CONG");
				return 1;
			}
			else
			{
				switch (check)
				{
				case 1: // chua nhap HO
					strcpy(temp.ho, NhapChuoi(26, 35, 51).c_str());
					check++;
					if (is_Empty_CArray(temp.ho))
					{
						THONGBAO(1, "VUI LONG NHAP DU THONG TIN");
						if (check > 1)
						{
							check--;
						}
					}
				case 2: // chua nhap TEN
					strcpy(temp.ten, NhapMa(81, 35, 16).c_str());
					check++;
					if (is_Empty_CArray(temp.ten))
					{
						THONGBAO(1, "VUI LONG NHAP DU THONG TIN");
						if (check > 1)
						{
							check--;
						}
					}
				case 3: // chua nhap PASSWORD
					strcpy(temp.password, NhapMa(101, 35, 12).c_str());
					check++;
					if (is_Empty_CArray(temp.password))
					{
						THONGBAO(1, "VUI LONG NHAP DU THONG TIN");
						if (check > 1)
						{
							check--;
						}
					}
				default:
					break;
				}
			}
		}
	}
}
int XoaSinhVien(PtrSV &dssv, PtrSV *data, int count)
{
	if (data[count - 1] == dssv)
		delete_First_SV(dssv);
	else
	{
		PtrSV p = NULL;
		for (p = dssv; p->next != NULL; p = p->next)
			if (data[count - 1] == p->next)
				delete_After_SV(p);
		for (int i = count - 1; i < 99; i++)
			data[i] = data[i + 1];
	}
	return 1;
}
bool HieuChinhSinhVien(PtrSV dssv, PtrSV *data, int index, int line)
{
	SinhVien tempSV;
	string gioiTinh = "NAM";
	tempSV.phai = 0;
	THONGBAO(1, "NHAP THONG TIN SINH VIEN MOI");
	do // cho nhap MSSV truoc khi nhap thong tin khac
	{
		delete_LineOnScreen(10, 9 + line * 2, 10);
		strcpy(tempSV.MSSV, NhapMa(10, 9 + line * 2, 10).c_str());
		if (is_Existed_MSSV_SV(dssv, tempSV.MSSV))
			THONGBAO(1, "MA SO SINH VIEN DA TON TAI");
		else
			break;
	} while (1);
	if (is_Empty_CArray(tempSV.MSSV)) // neu khong nhap MSSV khac -> dung MSSV cu~
		strcpy(tempSV.MSSV, data[index]->info.MSSV);
	gotoxy(10, 9 + line * 2);
	cout << tempSV.MSSV;

	delete_LineOnScreen(26, 9 + line * 2, 50);
	strcpy(tempSV.ho, NhapChuoi(26, 9 + line * 2, 50).c_str()); // nhap ho
	if (is_Empty_CArray(tempSV.ho))								// neu ENTER khi chua nhap -> dung ho cu~ cua SV
		strcpy(tempSV.ho, data[index]->info.ho);
	gotoxy(26, 9 + line * 2);
	cout << tempSV.ho;

	delete_LineOnScreen(81, 9 + line * 2, 15);
	strcpy(tempSV.ten, NhapChuoi(81, 9 + line * 2, 15).c_str());
	if (is_Empty_CArray(tempSV.ten)) // tuong tu nhu tren
		strcpy(tempSV.ten, data[index]->info.ten);
	gotoxy(81, 9 + line * 2);
	cout << tempSV.ten;

	delete_LineOnScreen(107, 9 + line * 2, 3);
	gioiTinh = NhapChuoi(107, 9 + line * 2, 3); // gan gioi tinh moi(default: NAM)
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
void MENU_DSDT_GV(SinhVien data, ListMH dsmh)
{
	system("cls");

	int numOfSubs = dsmh.n;
	PtrDT temp[MaxOfSubjects] = {NULL};

	PtrDT p = data.danhSachDiemThi;

	for (int i = 0; p != NULL && i < dsmh.n; i++)
	{
		temp[i] = p;
		p = p->next;
	}

	int line = 1, start = 1, count = 1;
	int page = 1, maxPage = (numOfSubs - 1) / 10 + 1;

	HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, start);
	gotoxy(2, 9 + line * 2);
	cout << ">>";
	gotoxy(116, 29);
	cout << "Page " << page << '/' << maxPage;
	// check = 0: sap xep theo maMH, 1: diem thi giam dan, 2: diem thi tang dan
	int checkList = 0;
	char ch;
	while ((ch = getch()) != ESC)
	{
		if (ch == -32)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
				if (line == 1 && start > 10) // truong hop dang o dau trang va ton tai trang truoc thi PgUp
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 10;
					start -= 10;
					count--;
					HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, start);

					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << --page << '/' << maxPage;
				}
				else if (line > 1 && count > 1) // truong hop o vi tri khong phai dau trang
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line--;
					count--;
					gotoxy(2, 9 + line * 2);
					cout << ">>";
				}
				break;
			case DOWN:
				if (line == 10 && count < numOfSubs) // truong hop o cuoi trang va con sinh vien thi PgDn
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 1;
					start += 10;
					count++;
					HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, start);

					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << ++page << '/' << maxPage;
				}
				else if (line < 10 && count < numOfSubs) // truong hop o vi tri khong phai cuoi trang
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line++;
					count++;
					gotoxy(2, 9 + line * 2);
					cout << ">>";
				}
				break;
			case PAGEUP:
				if (page > 1)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 10;
					start -= 10;
					count = (count / 10) * 10;
					HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					page--;
					gotoxy(116, 29);
					cout << "Page " << page << '/' << maxPage;
				}
				break;
			case PAGEDOWN:
				if (page < maxPage)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 1;
					start += 10;
					count = ((count - 1) / 10 + 1) * 10 + 1;
					HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					page++;
					gotoxy(116, 29);
					cout << "Page " << page << '/' << maxPage;
				}
				break;
			}
		}
		else
		{
			switch (ch)
			{
			case F1:
				THONGBAO(1, "HIEN DSMH");
				break;
			case F5: // sap xep theo diem <-> ma mon hoc
				delete_LineOnScreen(2, 9 + line * 2, 2);
				SortDSDT(temp, numOfSubs, checkList);
				start = page = line = count = 1;

				HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, start);
				gotoxy(2, 9 + line * 2);
				cout << ">>";
				gotoxy(116, 29);
				cout << "Page " << page << '/' << maxPage;
				break;
			case ENTER:
				THONGBAO(1, "DIEM < 0 => CHUA THI");
				delete_LineOnScreen(78, 9 + line * 2, 8);
				string newScore = "";
				newScore = NhapMa(78, 9 + line * 2);
				if (newScore[0] == '\0')
				{
					delete_LineOnScreen(78, 9 + line * 2, 8);
					gotoxy(78, 9 + line * 2);
					cout << temp[count - 1]->info.diemThi;
					break;
				}
				else if (THONGBAO(3, "LUU THAY DOI?"))
					temp[count - 1]->info.diemThi = atof(newScore.c_str());

				count = start = line = page = 1;
				HienDanhSachDiemThi(dsmh, temp, data.MSSV, data.ho, data.ten, start);
				gotoxy(2, 9 + line * 2);
				cout << ">>";
				gotoxy(116, 29);
				cout << "Page " << page << '/' << maxPage;
				break;
			}
		}
	}
}
void HienDanhSachDiemThi(ListMH dsmh, PtrDT *data, string MSSV, string ho, string ten, int start)
{
	system("cls");
	SetColor(0, 7);

	VeHeader(3, "DANH SACH DIEM THI", MSSV + " - " + ho + ' ' + ten);
	VeDanhSach(3);
	int count = 1;

	string tenMonHoc;
	for (int i = start - 1; i < start + 9 && data[i] != NULL; i++)
	{
		for (int j = 0; j < dsmh.n; j++)
			if (strcmp(data[i]->info.maMonHoc, dsmh.nodes[j].maMonHoc) == 0)
			{
				tenMonHoc = dsmh.nodes[j].tenMonHoc;
				break;
			}
		gotoxy(6, 9 + count * 2);
		cout << tenMonHoc;
		// cout << data[i]->maMonHoc;
		gotoxy(78, 9 + count * 2);
		if (data[i]->info.diemThi < 0)
			cout << "Chua thi";
		else
			cout << setprecision(2) << fixed << data[i]->info.diemThi;
		count++;
	}
	gotoxy(0, 40);
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
//////////////////////////GV->DANH SACH CAU HOI/////////////////////
void ThemCauHoi(STreeCH &root, char maMH[], char tenMH[])
{
	VeBangCauHoi(tenMH, 1);
	STreeCH NewQuestion = new nodeCauHoi;
	NewQuestion->info.ID = 1;
	char answer;
	strcpy(NewQuestion->info.maMonHoc, maMH);

	do
	{
		strcpy(NewQuestion->info.question, NhapChuoi(21, 10, 188).data());
		if (NewQuestion->info.question[0] == '\0')
			THONGBAO(1, "CAU HOI RONG");
	} while (NewQuestion->info.question[0] == '\0');
	do
	{
		strcpy(NewQuestion->info.ans1, NhapChuoi(21, 13, 94).data());
		if (NewQuestion->info.ans1[0] == '\0')
			THONGBAO(1, "DAP AN 1 RONG");
	} while (NewQuestion->info.ans1[0] == '\0');
	do
	{
		strcpy(NewQuestion->info.ans2, NhapChuoi(21, 16, 94).data());
		if (NewQuestion->info.ans2[0] == '\0')
			THONGBAO(1, "DAP AN 2 RONG");
	} while (NewQuestion->info.ans2[0] == '\0');
	do
	{
		strcpy(NewQuestion->info.ans3, NhapChuoi(21, 19, 94).data());
		if (NewQuestion->info.ans3[0] == '\0')
			THONGBAO(1, "DAP AN 3 RONG");
	} while (NewQuestion->info.ans3[0] == '\0');
	do
	{
		strcpy(NewQuestion->info.ans4, NhapChuoi(21, 22, 94).data());
		if (NewQuestion->info.ans4 == '\0')
			THONGBAO(1, "DAP AN 4 RONG");
	} while (NewQuestion->info.ans4 == '\0');
	gotoxy(21, 25);
	while (1)
	{
		answer = toupper(GetKey());
		if (answer == ENTER)
			break;
		if (answer == 8)
		{
			gotoxy(21, 25);
			cout << " ";
			gotoxy(21, 25);
			answer = 0;
		}
		if (answer >= 'A' && answer <= 'D')
		{
			cout << answer;
		}
	}
	switch (answer)
	{
	case 'A':
	{
		NewQuestion->info.answer = 1;
		break;
	}
	case 'B':
	{
		NewQuestion->info.answer = 2;
		break;
	}
	case 'C':
	{
		NewQuestion->info.answer = 3;
		break;
	}
	case 'D':
	{
		NewQuestion->info.answer = 4;
		break;
	}
	}
	THONGBAO(0, "AN PHIM BAT KY DE THOAT");
	getch();
	InsertQuestion(root, NewQuestion);
}
void XemCauHoi(STreeCH &root, STreeCH &ExsistQuestion, char tenMH[])
{
	int chon, vi_tri_contro = 16, stop = 0;
	char temp[90];
	VeBangCauHoi(tenMH, ExsistQuestion->info.ID);
	//	VEKHUNG_OPTION(2);
	TextColor(20);
	gotoxy(120, 16);
	cout << "     HIEU CHINH         ";
	TextColor(112);
	gotoxy(120, 19);
	cout << "     XOA CAU HOI        ";
	TextColor(7);

	gotoxy(21, 10);
	if (strlen(ExsistQuestion->info.question) < 94)
		cout << ExsistQuestion->info.question;
	else
	{
		strncpy(temp, ExsistQuestion->info.question, 90);
		cout << temp << "...";
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
						cout << "                                                                                             ";
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
							char answer = '\0';
							gotoxy(21, 25);
							while (1)
							{
								chon = toupper(GetKey());
								if (chon == ENTER && answer != '\0')
									break;
								if (chon == 8)
								{
									gotoxy(21, 25);
									cout << " ";
									gotoxy(21, 25);
									answer = '\0';
								}

								if (chon >= 'A' && chon <= 'D')
								{
									gotoxy(21, 25);
									answer = chon;
									cout << answer;
								}
							}
							switch (answer)
							{
							case 'A':
							{
								ExsistQuestion->info.answer = 1;
								break;
							}
							case 'B':
							{
								ExsistQuestion->info.answer = 2;
								break;
							}
							case 'C':
							{
								ExsistQuestion->info.answer = 3;
								break;
							}
							case 'D':
							{
								ExsistQuestion->info.answer = 4;
								break;
							}
							}
							break;
						}
						}
						break;
					}
					case ESC:
					{
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
				if (THONGBAO(3, "BAN CO MUON XOA"))
				{
					DeleteQuestion(root, ExsistQuestion);
					RestoreID();
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
		VeBangDanhSachCauHoi(monHoc.maMonHoc, MaxPage, Page);
		TextColor(20);
		gotoxy(120, 16);
		cout << "     THEM CAU HOI       ";
		TextColor(112);
		gotoxy(120, 19);
		cout << "     XEM CAU HOI        ";
		if (NumberQuestion == 0)
			THONGBAO(0, "KHONG CO CAU HOI");
		else
		{
			wherey = 10; // muon tam wherey de in cau hoi
			for (int i = (Page - 1) * 10; i < (Page * 10 < NumberQuestion ? Page * 10 : NumberQuestion); i++)
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
void InCauHoiDaThi(STreeCH root, MonHoc monHoc, char MSSV[])
{
	STreeCH list[100]; // chua cau hoi
	int ID[100], DapAn[100], NumberQuestion = 0, stop = 0, MaxPage, Page, chon, count = 0, wherey = 10;
	string MaMH;
	char chuoi[90];
	ifstream docfile(("Data/DanhSachSinhVien/DanhSachCauHoiThi/" + string(MSSV) + ".txt").data());

	if (docfile.is_open())
	{
		while (!docfile.eof() && stop != 1)
		{
			getline(docfile, MaMH, '|');
			if (MaMH.compare(string(monHoc.maMonHoc)) == 0)
			{
				docfile >> ID[NumberQuestion];
				docfile.ignore();
				docfile >> DapAn[NumberQuestion++];
				docfile.ignore();
				docfile.ignore();
			}
			else
				getline(docfile, MaMH);
		}
	}
	for (int i = 0; i < NumberQuestion; i++)
		TimCauHoiDaThi(root, list, ID[i], count);

	MaxPage = (NumberQuestion - 1) / 10 + 1, Page = 1;
	while (1)
	{
		// XUAT NOI DUNG

		stop = 0;
		VeBangDanhSachCauHoi(monHoc.maMonHoc, MaxPage, Page);
		if (NumberQuestion == 0)
			THONGBAO(2, "KHONG CO CAU HOI");
		else
		{
			wherey = 10; // muon tam wherey de in cau hoi
			for (int i = (Page - 1) * 10; i < (Page * 10 < NumberQuestion ? Page * 10 : NumberQuestion); i++)
			{
				gotoxy(6, wherey);
				cout << list[i]->info.ID;
				gotoxy(21, wherey);
				if (strlen(list[i]->info.question) < 94)
					cout << list[i]->info.question;
				else
				{
					strncpy(chuoi, list[i]->info.question, 90);
					cout << chuoi << "...";
				}
				wherey += 2;
			}
		}
		// CHON LUA;
		int i = (Page - 1) * 10;
		wherey = 10;
		gotoxy(3, 10);
		cout << ">>";
		while (stop != 1)
		{
			chon = getch();
			switch (chon)
			{
			case ESC:
			{
				if (THONGBAO(3, "BAN CO MUON THOAT KHONG"))
					return;
				break;
			}
			case ENTER:
			{
				VeBangCauHoi(monHoc.tenMonHoc, list[i]->info.ID);
				gotoxy(21, 10);
				if (strlen(list[i]->info.question) < 94)
					cout << list[i]->info.question;
				else
				{
					strncpy(chuoi, list[i]->info.question, 90);
					cout << chuoi << "...";
				} // IN CAU HOI
				gotoxy(21, 13);
				cout << list[i]->info.ans1; // IN CAU A
				gotoxy(21, 16);
				cout << list[i]->info.ans2; // IN CAU B
				gotoxy(21, 19);
				cout << list[i]->info.ans3; // IN CAU C
				gotoxy(21, 22);
				cout << list[i]->info.ans4; // IN CAU D
				gotoxy(21, 25);
				cout << (list[i]->info.answer == 1 ? 'A' : list[i]->info.answer == 2 ? 'B'
													   : list[i]->info.answer == 3	 ? 'C'
													   : list[i]->info.answer == 4	 ? 'D'
																					 : 'E');
				VeKhung(5, 30, 115, 32);
				gotoxy(6, 31);
				cout << "DAP AN BAN CHON LA:";
				if (DapAn[i] == 1)
				{
					switch (list[i]->info.answer)
					{
					case 1:
					{
						cout << 'A';
						break;
					}
					case 2:
					{
						cout << 'B';
						break;
					}
					case 3:
					{
						cout << 'C';
						break;
					}
					case 4:
					{
						cout << 'D';
						break;
					}
					}
				}
				else
					cout << (DapAn[i] == -1 ? "A" : DapAn[i] == -2 ? "B"
												: DapAn[i] == -3   ? "C"
												: DapAn[i] == -4   ? "D"
																   : "chua chon");
				THONGBAO(0, "NHAN ESC DE THOAT");
				while (1)
				{
					chon = getch();
					if (chon == 27)
					{
						stop = 1;
						break;
					}
					else if (chon == 224 || chon == 0)
						getch();
				}
				break;
			}
			case 224:
			{
				chon = getch();
				switch (chon)
				{
				case UP:
				{
					if (wherey != 10)
					{
						gotoxy(3, wherey);
						cout << "  ";
						wherey -= 2;
						gotoxy(3, wherey);
						cout << ">>";
						i--;
					}

					break;
				}
				case DOWN:
				{
					if (wherey != 28)
					{

						gotoxy(3, wherey);
						cout << "  ";
						wherey += 2;
						gotoxy(3, wherey);
						cout << ">>";
						i++;
					}
					break;
				}
				case LEFT:
				{
					if (Page != 1)
					{
						Page--;
						break;
					}
				}
				case RIGHT:
				{
					if (Page != MaxPage)
					{
						Page++;
						break;
					}
				}
				}
			}
			}
		}
	}
}

///////////////////////////GV->DANH SACH LOP HOC/////////////////////
void sortDSLH(LopHoc **dslh, int numOfClass, int &index)
{
	if (index < 1 || index > 3)
		return; // index = 1, 2 hoặc 3 tương ứng với maLop, tenLop hoặc nienKhoa
	for (int i = 0; i < numOfClass - 1; i++)
	{
		for (int j = i + 1; j < numOfClass; j++)
		{
			if (index == 1)
			{ // sắp xếp theo maLop
				if (strcmp(dslh[i]->maLop, dslh[j]->maLop) > 0)
				{
					swap(dslh[i], dslh[j]);
				}
			}
			else if (index == 2)
			{ // sắp xếp theo tenLop
				if (strcmp(dslh[i]->tenLop, dslh[j]->tenLop) > 0)
				{
					swap(dslh[i], dslh[j]);
				}
			}
			else
			{ // sắp xếp theo nienKhoa
				if (dslh[i]->nienKhoa > dslh[j]->nienKhoa)
				{
					swap(dslh[i], dslh[j]);
				}
			}
		}
	}
	switch (index)
	{
	case 1:
		index = 2;
		break;
	case 2:
		index = 3;
		break;
	case 3:
		index = 1;
		break;
	}
}
int HienOptionLopHoc(bool check)
{
	for (int i = 0; i < 11; i++)
		delete_LineOnScreen(120, 15 + i, 40);
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
// hien khung de nhap cac thong tin de them lop
bool ThemLopHoc(ListLH &dslh)
{
	KhungThem(1);
	char ch;
	int check = 1; // check: kiem tra xem da nhap thong tin toi vi tri nao (1:maLop  2: tenLop  3:nienKhoa )
	LopHoc temp;
	do
	{
		delete_LineOnScreen(8, 35, 11);
		strcpy(temp.maLop, NhapMa(8, 35, 11).c_str());
		if (is_Existed_MaLop(dslh, temp.maLop))
			THONGBAO(1, "MA LOP DA TON TAI");
		else if (is_Empty_CArray(temp.maLop))
		{
			if (THONGBAO(3, "MA LOP TRONG, HUY THAO TAC?"))
				return 0;
		}
		else
			break;
	} while (is_Existed_MaLop(dslh, temp.maLop) || is_Empty_CArray(temp.maLop));
	while (1)
	{
		if ((ch = getch()) == ESC)
		{
			if (THONGBAO(3, "BAN MUON HUY QUA TRINH?"))
				return 0;
		}
		else if (ch == ENTER)
		{
			if (check == 3)
			{
				ThemLop(dslh, temp);
				THONGBAO(1, "DA THEM THANH CONG");
				return 1;
			}
			else
			{
				switch (check)
				{
				case 1: // chua nhap tenLOP
					delete_LineOnScreen(26, 35, 50);
					strcpy(temp.tenLop, NhapChuoi(26, 35, 50).c_str());
					check++;
					if (is_Empty_CArray(temp.tenLop))
					{
						if (THONGBAO(3, "BAN MUON HUY QUA TRINH?"))
							return 0;
						else if (check > 1)
							check--;
					}
				case 2: // chua nhap nienKhoa
					delete_LineOnScreen(101, 35, 5);
					temp.nienKhoa = NhapSo(101, 35, 4);
					check++;
				}
			}
		}
	}
}
bool XoaLopHoc(ListLH &dslh, LopHoc **lh, int count)
{
	int i = 0;
	for (i = 0; i < dslh.n; i++)
		if (lh[count] == dslh.lh[i])
			break;
	XoaLop(dslh, i);
	for (int j = count; j < MaxOfClasses - 1; j++)
		lh[j] = lh[j + 1];
	return 1;
}
bool HieuChinhLopHoc(ListLH dslh, LopHoc **data, int index, int line)
{
	LopHoc tempLH;
	THONGBAO(1, "NHAP THONG TIN LOP HOC MOI");
	do // cho nhap maLop truoc khi nhap thong tin khac
	{
		delete_LineOnScreen(10, 9 + line * 2, 12);
		strcpy(tempLH.maLop, NhapMa(10, 9 + line * 2, 11).c_str());
		if (is_Existed_MaLop(dslh, tempLH.maLop))
			THONGBAO(1, "MA LOP HOC DA TON TAI");
		else
			break;
	} while (1);
	if (is_Empty_CArray(tempLH.maLop)) // neu khong nhap ma lop khac -> dung ma lop cu~
	{
		strcpy(tempLH.maLop, data[index]->maLop);
		gotoxy(10, 9 + line * 2);
		cout << tempLH.maLop;
	}

	delete_LineOnScreen(26, 9 + line * 2, 50);
	strcpy(tempLH.tenLop, NhapChuoi(26, 9 + line * 2, 50).c_str()); // nhap ten lop
	if (is_Empty_CArray(tempLH.tenLop))								// neu ENTER khi chua nhap -> dung ten lop cu~
		strcpy(tempLH.tenLop, data[index]->tenLop);
	gotoxy(26, 9 + line * 2);
	cout << tempLH.tenLop;

	// xu ly nienKhoa
	delete_LineOnScreen(101, 9 + line * 2, 10);
	tempLH.nienKhoa = NhapSo(101, 9 + line * 2, 4);
	if (tempLH.nienKhoa == 0)
		tempLH.nienKhoa = data[index]->nienKhoa;
	gotoxy(101, 9 + line * 2);
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
// hien cac thong tin trong dslh
void HienDanhSachLopHoc(LopHoc **data, int start)
{
	system("cls");
	SetColor(0, 7);
	VeHeader(1, "DANH SACH LOP HOC", "");
	VeDanhSach(1);
	HienOptionLopHoc(1);
	int count = 1;

	for (int i = start - 1; i < start + 9 && data[i] != NULL; i++)
	{
		gotoxy(10, 9 + 2 * count);
		cout << data[i]->maLop;
		gotoxy(26, 9 + 2 * count);
		cout << data[i]->tenLop;
		gotoxy(106, 9 + 2 * count);
		cout << data[i]->nienKhoa;
		count++;
	}
	gotoxy(0, 40);
}
void InDSLH_NienKhoa(ListLH dslh, int nienKhoa)
{
	// bat dau ve khung
	system("cls");
	SetColor(0, 7);
	gotoxy(125, 28);
	VeHeader(1, "DANH SACH LOP HOC", "NIEN KHOA " + to_string(nienKhoa));
	VeDanhSach(1);
	// duyet qua cac lop hoc co trong dslh
	int count = 0;
	// nhap thong tin moi cho lop hoc trong loop nay

	for (int i = 0; i < dslh.n; i++)
	{
		// check xem nien khoa co bang nienKhoa yeu cau
		if (dslh.lh[i]->nienKhoa == nienKhoa)
		{
			gotoxy(10, 11 + 2 * count);
			cout << dslh.lh[i]->maLop;
			gotoxy(26, 11 + 2 * count);
			cout << dslh.lh[i]->tenLop;
			gotoxy(106, 11 + 2 * count);
			cout << dslh.lh[i]->nienKhoa;
			count++;
		}
	}
	TextColor(0);
	system("pause");
	TextColor(7);
	// hien so page
	gotoxy(116, 29);
	int maxPage = (count - 1) / 10 + 1;
	cout << "Page " << count << '/' << maxPage;
}
void HienDanhSachDiemThiTheoMon_LopHoc(PtrSV *data, string maLop, string maMon, int numOfStudents, int start, bool check_return)
{
	system("cls");
	SetColor(0, 7);
	VeHeader(2, "DANH SACH DIEM THI", maMon);
	VeDanhSach(2);
	delete_LineOnScreen(101, 9, 14);
	gotoxy(101, 9);
	cout << "    DIEM     ";

	int count = 0;
	PtrDT p;

	for (int i = start - 1; i < start + 9 && data[i] != NULL; i++)
	{
		gotoxy(10, 11 + 2 * count);
		cout << data[i]->info.MSSV;
		gotoxy(26, 11 + 2 * count);
		cout << data[i]->info.ho;
		gotoxy(81, 11 + 2 * count);
		cout << data[i]->info.ten;
		string mssv(data[i]->info.MSSV);
		for (p = data[i]->info.danhSachDiemThi; p != NULL; p = p->next)
		{
			if (strcmp(p->info.maMonHoc, maMon.c_str()) == 0)
			{
				gotoxy(107, 11 + 2 * count);
				cout << setprecision(2) << fixed << p->info.diemThi;
				break;
			}
		}
		count++;
	}
	char ch;
	while (1)
	{
		if (check_return)
			return;
		ch = getch();
		if (ch == -32)
			switch (ch = getch())
			{
			case PAGEUP:
				if (start > 10)
					HienDanhSachDiemThiTheoMon_LopHoc(data, maLop, maMon, numOfStudents, start - 10, check_return);
				break;
			case PAGEDOWN:
				if (start < numOfStudents - 10)
					HienDanhSachDiemThiTheoMon_LopHoc(data, maLop, maMon, numOfStudents, start + 10, check_return);
				break;
			}
		else if (ch == ESC)
			check_return = 1;
	}
}
void MENU_DSLH_GV(ListLH &dslh, ListMH dsmh, STreeCH root)
{
	system("cls");
	int numOfClasses = dslh.n;
	// day thong tin tu dslk sang mang con tro
	LopHoc *temp[MaxOfClasses] = {NULL};
	// copy du lieu tu danh sach con tro ban dau sang danh sach moi
	for (int i = 0; i < dslh.n; i++)
		temp[i] = dslh.lh[i];

	int line = 1, start = 1, count = 1, option = 0;
	int page = 1, maxPage = (numOfClasses - 1) / 10 + 1;
	HienDanhSachLopHoc(temp, start);
	// hien so page va option
	gotoxy(2, 9 + line * 2);
	cout << ">>";
	gotoxy(116, 29);
	cout << "Page " << page << '/' << maxPage;

	bool check_Delete = 0;
	bool check_Edit = 0;

	// kieu sap xep danh sach
	int index = 1;
	char ch;
	while (1)
	{
		if ((ch = getch()) == -32)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
				if (line == 1 && start > 10)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 10;
					start -= 10;
					count--;
					HienDanhSachLopHoc(temp, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << --page << '/' << maxPage;
				}
				else if (line > 1 && count > 1)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line--;
					count--;
					gotoxy(2, 9 + line * 2);
					cout << ">>";
				}
				break;
			case DOWN:
				if (line == 10 && count < numOfClasses)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 1;
					start += 10;
					count++;
					HienDanhSachLopHoc(temp, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << ++page << '/' << maxPage;
				}
				else if (line < 10 && count < numOfClasses)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line++;
					count++;
					gotoxy(2, 9 + line * 2);
					cout << ">>";
				}
				break;
			case RIGHT:
				if (check_Delete || check_Edit)
					break;
				delete_LineOnScreen(2, 9 + line * 2, 2);
				option = HienOptionLopHoc();
				switch (option)
				{
				case 1:
					ThemLopHoc(dslh);
					temp[dslh.n - 1] = dslh.lh[dslh.n - 1];
					numOfClasses = dslh.n;
					maxPage = (numOfClasses - 1) / 10 + 1;

					start = count = line = page = 1;
					HienDanhSachLopHoc(temp, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << page << '/' << maxPage;
					break;
				case 2:
					THONGBAO(1, "CHON LOP MUON XOA");
					check_Delete = 1;
					break;
				case 3:
					THONGBAO(1, "CHON LOP HIEU CHINH");
					check_Edit = 1;
					break;
				case 4:
				{
					THONGBAO(1, "NHAP MA LOP DE XEM DSDT");
					for (int i = 0; i < 11; i++) // xoa options
						delete_LineOnScreen(120, 15 + i, 25);
					VeKhung(120, 16, 145, 18);
					string maLop4;
					maLop4 = NhapMa(121, 17, 11);
					if (!is_Existed_MaLop(dslh, maLop4.c_str()))
					{
						THONGBAO(1, "MA LOP KHONG TON TAI");
						break;
					}
					THONGBAO(1, "NHAP MA MON DE XEM DSDT");
					string maMon4;
					VeKhung(120, 19, 145, 21);
					maMon4 = NhapMa(121, 20, 15);
					if (!is_Existed_MaMH_MH(dsmh, maMon4))
					{
						THONGBAO(1, "MA MON KHONG TON TAI");
						break;
					}
					PtrSV quanLy[100] = {NULL};
					PtrSV p = NULL;
					for (int i = 0; i < dslh.n; i++)
						if (strcmp(dslh.lh[i]->maLop, maLop4.c_str()) == 0)
						{
							p = dslh.lh[i]->danhSachSinhVien;
							break;
						}
					int numOfStudents4 = 0;
					for (int i = 0; p != NULL; i++)
					{
						quanLy[i] = p;
						numOfStudents4++;
						p = p->next;
					}

					HienDanhSachDiemThiTheoMon_LopHoc(quanLy, maLop4, maMon4, numOfStudents4, 1, 0);

					page = line = start = count = 1;
					HienDanhSachLopHoc(temp, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << ++page << '/' << maxPage;
					break;
					break;
				}
				case 5:
				{
					THONGBAO(1, "NHAP NIEN KHOA");
					for (int i = 0; i < 11; i++) // xoa options
						delete_LineOnScreen(120, 15 + i, 25);
					VeKhung(120, 16, 145, 18);
					int year;
					year = NhapSo(121, 17, 4); // nhap nien khoa can xem
					InDSLH_NienKhoa(dslh, year);

					page = line = start = count = 1;
					HienDanhSachLopHoc(temp, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << ++page << '/' << maxPage;
					break;
				}
				default:
					THONGBAO(1, "CO LOI TRONG OPTION LOP HOC");
					break;
				}
				HienOptionLopHoc(1);
				gotoxy(2, 9 + line * 2);
				cout << ">>";
				break;
			case PAGEUP:
				if (page > 1)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 10;
					start -= 10;
					count = (count / 10) * 10;
					HienDanhSachLopHoc(temp, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					page--;
					gotoxy(116, 29);
					cout << "Page " << page << '/' << maxPage;
				}
				break;
			case PAGEDOWN:
				if (page < maxPage)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 1;
					start += 10;
					count = ((count - 1) / 10 + 1) * 10 + 1;
					HienDanhSachLopHoc(temp, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					page++;
					gotoxy(116, 29);
					cout << "Page " << page << '/' << maxPage;
				}
				break;
			}
		}
		else
		{
			switch (ch)
			{
			case F1: // Hien danh sach mon hoc
				THONGBAO(1, "HIEN DANH SACH MON HOC");
				break;
			case F5: // sap xep theo ho <-> ten(mssv)
				sortDSLH(temp, dslh.n, index);

				line = page = count = start = 1;
				break;
			case ESC:
				if (THONGBAO(3, "DANG XUAT?"))
					return;
				else
					break;
			case ENTER:
				if (check_Delete)
				{
					if (THONGBAO(3, "XAC NHAN XOA LOP HOC?"))
					{
						XoaLopHoc(dslh, temp, count - 1);

						numOfClasses--;
						maxPage = (numOfClasses - 1) / 10 + 1;
						start = count = page = line = 1;
						THONGBAO(1, "DA XOA LOP HOC");
					}
					check_Delete = 0;
				}
				else if (check_Edit)
				{
					HieuChinhLopHoc(dslh, temp, count - 1, line);
					check_Edit = 0;
				}
				else
					MENU_DSSV_GV(temp[count - 1], dsmh);

				HienDanhSachLopHoc(temp, start);
				HienOptionLopHoc(1);
				gotoxy(2, 9 + line * 2);
				cout << ">>";
				gotoxy(116, 29);
				cout << "Page " << page << '/' << maxPage;
				break;
			}
		}
	}
}
///////////////////////////GV->DANH SACH MON HOC/////////////////////
void MENU_DSMH_GV(STreeCH &root, ListMH dsmh)
{
	int numOfSubjects = dsmh.n;

	int line = 1, start = 1, count = 1, page = 1;
	int maxPage = (numOfSubjects - 1) / 10 + 1;

	// kiem tra co phai dang o che do XOA MON HOC
	bool check_Delete = 0;
	// Kiem tra co phai dang o che do HIEU CHINH
	bool check_Edit = 0;

	HienDanhSachMonHoc(dsmh, start);
	gotoxy(2, 9 + line * 2);
	cout << ">>";
	gotoxy(116, 29);
	cout << "Page" << page << '/' << maxPage;
	HienOptionMonHoc(1);

	char ch;
	while ((ch = getch()) != ESC)
	{
		if (ch == -32)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
				if (line == 1 && start > 10)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 10;
					start -= 10;
					count--;

					HienDanhSachMonHoc(dsmh, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << --page << '/' << maxPage;
				}
				else if (line > 1 && count > 1)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line--;
					count--;
					gotoxy(2, 9 + line * 2);
					cout << ">>";
				}
				break;
			case DOWN:
				if (line == 10 && count < dsmh.n)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 1;
					start += 10;
					count++;

					HienDanhSachMonHoc(dsmh, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << ++page << '/' << maxPage;
				}
				else if (line < 10 && count < dsmh.n)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line++;
					count++;
					gotoxy(2, 9 + line * 2);
					cout << ">>";
				}
				break;
			case PAGEUP:
				if (page > 1)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 10;
					start -= 10;
					count = (count / 10) * 10;

					HienDanhSachMonHoc(dsmh, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << --page << '/' << maxPage;
				}
				break;
			case PAGEDOWN:
				if (page < maxPage)
				{
					delete_LineOnScreen(2, 9 + line * 2, 2);
					line = 1;
					start += 10;
					count = ((count - 1) / 10 + 1) * 10 + 1;

					HienDanhSachMonHoc(dsmh, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << ++page << '/' << maxPage;
				}
				break;
			case RIGHT:
				if (check_Delete || check_Edit)
					break;

				delete_LineOnScreen(2, 9 + line * 2, 2);
				switch (HienOptionMonHoc())
				{
				case 0:
					break;
				case 1:
					if (ThemMonHoc(dsmh))
						maxPage = (dsmh.n - 1) / 10 + 1;
					else
						THONGBAO(1, "DA HUY THAO TAC THEM");
					start = count = line = page = 1;
					HienDanhSachMonHoc(dsmh, start);
					gotoxy(2, 9 + line * 2);
					cout << ">>";
					gotoxy(116, 29);
					cout << "Page " << page << '/' << maxPage;
					HienOptionMonHoc(1);
					break;
				case 2:
					THONGBAO(1, "CHON MON HOC MUON XOA");
					check_Delete = 1;
					break;
				case 3:
					THONGBAO(1, "CHON MON HOC MUON HIEU CHINH");
					check_Edit = 1;
					break;
				case 4:
					THONGBAO(1, "CHON MON HOC DE XEM DANH SACH CAU HOI");
					break;
				}
			}
		}
		else if (ch == ENTER)
		{
			if (check_Delete)
			{
				if (THONGBAO(3, "XOA MON HOC?"))
				{
					if (XoaMonHoc(dsmh, count - 1))
					{
						maxPage = (dsmh.n - 1) / 10 + 1;
						line = page = count = start = 1;
					}
					check_Delete = 0;
				}
				break;
			}
			else if (check_Edit)
			{
				if (!ThemMonHoc(dsmh))
				{
					THONGBAO(1, "DA HUY THAO TAC HIEU CHINH");
					break;
				}
			}
			else
				MENU_DSCH_GV(root, dsmh.nodes[count - 1]);

			HienDanhSachMonHoc(dsmh, start);
			gotoxy(2, 9 + line * 2);
			cout << ">>";
			gotoxy(116, 29);
			cout << "Page " << --page << '/' << maxPage;
		}
	}
}
void HienDanhSachMonHoc(ListMH dsmh, int start)
{
	system("cls");
	SetColor(0, 7);
	VeHeader(4, "DANH SACH MON HOC");
	VeDanhSach(4);
	HienOptionMonHoc(1);
	int count = 0;
	for (int i = start - 1; i < start + 9 && i < dsmh.n; i++)
	{
		gotoxy(12, 11 + count * 2);
		cout << dsmh.nodes[i].maMonHoc;
		gotoxy(36, 11 + count * 2);
		cout << dsmh.nodes[i].tenMonHoc;
		count++;
	}
	gotoxy(0, 40);
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
		return -1;

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
				}
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
bool XoaMonHoc(ListMH dsmh, int index)
{
	if (is_Empty_MH(dsmh) || index >= dsmh.n)
		return 0;
	for (int i = index; i < MaxOfSubjects; i++)
		dsmh.nodes[i] = dsmh.nodes[i + 1];
	dsmh.n--;
	return 1;
}
bool ThemMonHoc(ListMH dsmh)
{
	KhungThem(4);
	MonHoc newMH;
	char ch;
	// kiem tra da nhap du 2 noi dung hay chua
	int check = 0;
	while (1)
	{
		if ((ch = getch()) == ESC)
			if (THONGBAO(3, "HUY QUA TRINH?"))
				return 0;
			else if (ch == ENTER)
			{
				if (check == 2)
					if (THONGBAO(3, "LUU THONG TIN?"))
					{
						insert_MH(dsmh, newMH);
						THONGBAO(1, "DA THEM MON HOC");
						return 1;
					}
					else
						THONGBAO(1, "HAY NHAP DU THONG TIN");
			}
		while (check == 0)
		{
			strcpy(newMH.maMonHoc, NhapMa(6, 33, 15).c_str());
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
			else
			{
				check++;
				break;
			}
		}
		while (check == 1)
		{
			strcpy(newMH.tenMonHoc, NhapChuoi(26, 33, 50).c_str());
			if (is_Empty_CArray(newMH.tenMonHoc))
			{
				THONGBAO(1, "NHAP TEN MON HOC");
				continue;
			}
			else
			{
				check++;
				break;
			}
		}
	}
}
bool HieuChinhMonHoc(ListMH dsmh, int index, int line)
{
	MonHoc temp;
	int check = 0;
	char ch;
	while (1)
	{
		if ((ch = getch()) == ESC)
		{
			if (THONGBAO(3, "HUY QUA TRINH?"))
				return 0;
		}
		else if (ch == ENTER && check == 2)
		{
			if (THONGBAO(3, "LUU THONG TIN?"))
			{
				insert_MH(dsmh, temp);
				THONGBAO(1, "DA HIEU CHINH MON HOC");
				return 1;
			}
		}
		else if (ch == ENTER)
			THONGBAO(1, "HAY NHAP DU THONG TIN");
		while (check == 0)
		{
			delete_LineOnScreen(6, 9 + line * 2, 15);
			strcpy(temp.maMonHoc, NhapMa(6, 9 + line * 2, 15).c_str());
			if (is_Existed_MaMH_MH(dsmh, temp.maMonHoc))
			{
				THONGBAO(1, "MA MON NAY DA TON TAI");
				continue;
			}
			else if (is_Empty_CArray(temp.maMonHoc))
			{
				strcpy(temp.maMonHoc, dsmh.nodes[index].maMonHoc);
				check++;
				break;
			}
			else
			{
				check++;
				break;
			}
			gotoxy(6, 9 + line * 2);
			cout << temp.maMonHoc;
		}
		while (check == 1)
		{
			delete_LineOnScreen(26, 9 + line * 2, 50);
			strcpy(temp.tenMonHoc, NhapChuoi(26, 9 + line * 2, 50).c_str());
			if (is_Empty_CArray(temp.tenMonHoc))
				strcpy(temp.tenMonHoc, dsmh.nodes[index].tenMonHoc);
			check++;
			break;
			gotoxy(26, 9 + line * 2);
			cout << temp.tenMonHoc;
		}
	}
}
void THEMSINHVIEN(ListLH &dslh, ListMH dsmh)
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
	do
	{
		delete_LineOnScreen(25, 6, 15);
		strcpy(temp.maLop, NhapMa(25, 6, 11).c_str());
		checkMaLH = 1;
		if (is_Empty_CArray(temp.maLop))
		{
			checkMaLH = 0;
			if (THONGBAO(3, "CHUA NHAP MA LOP, HUY THAO TAC?"))
				return;
		}
		else if (is_Existed_MaLop(dslh, temp.maLop))
		{
			checkMaLH = 1;
			break;
		}
		else if (THONGBAO(3, "MA LOP KHONG TON TAI, THEM LOP MOI?"))
		{
			KhungThem(1);
			gotoxy(6, 35);
			cout << temp.maLop;
			while (1)
			{
				delete_LineOnScreen(26, 35, 50);
				strcpy(temp.tenLop, NhapChuoi(26, 35, 50).c_str());
				if (is_Empty_CArray(temp.tenLop))
				{
					if (THONGBAO(3, "TEN LOP RONG, HUY THAO TAC?"))
						return;
				}
				else
					break;
			}
			while (1)
			{
				delete_LineOnScreen(101, 35, 5);
				temp.nienKhoa = NhapSo(101, 35, 4);
				if (temp.nienKhoa == 0)
				{
					if (THONGBAO(3, "SAI NIEN KHOA, HUY THAO TAC?"))
						return;
				}
				else
					break;
			}
			ThemLop(dslh, temp);
			THONGBAO(1, "DA THEM LOP HOC");
		}
	} while (checkMaLH == 0);
	do
	{
		delete_LineOnScreen(25, 9, 6);
		num = NhapSo(25, 9, 5);
		if (num <= 0)
		{
			if (THONGBAO(3, "CHUA NHAP SO LUONG, THOAT?"))
				return;
		}
		else
			break;
	} while (1);
	for (int i = 0; i < dslh.n; i++)
		if (strcmp(dslh.lh[i]->maLop, temp.maLop) == 0)
		{
			lopHoc = dslh.lh[i];
			break;
		}
	for (int i = 0; i < num; i++)
	{
		THONGBAO(1, "NHAP THONG TIN SINH VIEN THU " + to_string(i + 1));
		if (!ThemSinhVien(lopHoc->danhSachSinhVien, dsmh))
		{
			THONGBAO(1, "DA DUNG THAO TAC");
			break;
		}
	}
	THONGBAO(1, "DA XONG");
}
void MainProcessing(ListMH &dsmh, ListLH &dslh, STreeCH &root)
{
	doc_danhSachLopHoc(dslh);
	doc_danhSachMonHoc(dsmh);
	doc_danhSachCauHoi(root);
	// MENU_DSSV_GV(dslh.lh[2], dsmh);

	char ch;
	while (1)
	{
		string login = DANGNHAP();
		if (login == "NONE")
		{
		}
		else if (login == "READ FILE ERROR")
		{
		}
		else if (login == "GV")
		{
			MENU_GV(dsmh, dslh, root);
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
			// p = dslh.lh[1]->danhSachSinhVien;
			MENU_SV(dslh.lh[index]->maLop, p->info);
		}
		if ((ch = getch()) == ESC)
			if (THONGBAO(3, "KET THUC CHUONG TRINH?"))
				return;
	}
}
