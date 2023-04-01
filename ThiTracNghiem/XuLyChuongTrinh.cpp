#include "XuLyChuongTrinh.h"

int stop = 0; // stop=1 thi dung thi
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
	return 0;
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
	gotoxy(69, 15);
	cout << "                    ";
	gotoxy(69, 18);
	cout << "                    ";
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
void DongHo(int time)
{

	int giay;
	while (time > 0)
	{
		gotoxy(131, 6);
		cout << time;
		gotoxy(135, 6);
		cout << "00";
		VeKhung(130, 5, 140, 7);
		gotoxy(131, 6);
		cout << time;
		Sleep(980);
		time--;
		giay = 59;
		while (giay >= 0)
		{
			VeKhung(130, 5, 140, 7);
			gotoxy(131, 6);
			cout << "   ";
			gotoxy(131, 6);
			cout << time;
			gotoxy(135, 6);
			cout << "   ";
			gotoxy(135, 6);
			cout << giay--;
			Sleep(980);
			if (stop == 1)
				return;
		}
	}
	stop = 1;
}
void Thi(STreeCH &root, PtrDT &score)
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
	so_cau_dung[so_cau] = {0};					  // LUU CAU DA TRA LOI: DUNG = 1,  sai = -1 / -2 / -3 / -4,  chua chon =0
	for (int i = 0; i < so_cau; i++)
		so_cau_dung[i] = 0;
	for (int i = 0; stop != 1;)
	{
		if (i == so_cau)
		{
			stop = THONGBAO(3, "BAN CO MUON THOAT KHONG");
			if (stop == 0)
			{
				i--;
				continue;
			}
		}
		index = wherey = 10; // GAN TAI VI TRI CAU A
		system("cls");
		VeKhungThi();
		gotoxy(5, 27);
		if (so_cau_dung[i] == 0)
			cout << "BAN CHUA CHON";
		else if (so_cau_dung[i] == 1)
		{
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
		cout << Questions[i]->info.question; // IN CAU HOI
		gotoxy(16, 10);
		cout << Questions[i]->info.ans1; // IN CAU A
		gotoxy(16, 14);
		cout << Questions[i]->info.ans2; // IN CAU B
		gotoxy(16, 18);
		cout << Questions[i]->info.ans3; // IN CAU C
		gotoxy(16, 22);
		cout << Questions[i]->info.ans4; // IN CAU D
		// XEM LUA CHON
		while (stop != 1)
		{
			chon = getch(); // LAY KI TU TU BAN PHIM
			if (chon == 27) // NHAN ESC
			{
				stop = THONGBAO(3, "BAN CO MUON THOAT KHONG"); // NEU THOAT THI STOP=1 VA THOAT
				THONGBAO(1);
			}
			else if (chon == 13) // PHAT HIEN NHAN ENTER VA KIEM TRA DAP AN
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
				chon = getch(); // NUT MO Rï¿½NG Nï¿½N Lï¿½Y THï¿½M Mï¿½T LAN NUA
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

	// TINH DIEM
	for (int i = 0; i < so_cau; i++)
		if (so_cau_dung[i] == 1)
			score->info.diemThi += 1; // DEM SO CAU DUNG

	score->info.diemThi = (score->info.diemThi / so_cau) * 10; // TINH DIEM
	stop = 1;
	timer.join();
}
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
					HienDanhSachSinhVien(temp, data->tenLop, start);
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
					HieuChinhSinhVien(data->danhSachSinhVien, temp, count - 1, line, check_Edit);
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

	if (check)
	{
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
		return 0;
	}

	int pos_Y = 15, conTro = 15;

	gotoxy(120, 15);
	TextColor(20);
	cout << option1;
	TextColor(112);
	gotoxy(120, 17);
	cout << option2;
	gotoxy(120, 19);
	cout << option3;
	gotoxy(120, 21);
	cout << option4;
	gotoxy(120, 23);
	cout << option5;

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
		THONGBAO(1, "VUI LONG NHAP MSSV TRUOC");
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
				cout << "ho: " << temp.ho << ";";
				Sleep(5000);
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
					break;
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
					break;
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
					break;
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
bool HieuChinhSinhVien(PtrSV dssv, PtrSV *data, int index, int line, bool &check)
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
	char ch;
	while ((ch = getch()) != ENTER) // nhap thong tin moi cho sinh vien trong loop nay
	{
		if (is_Empty_CArray(tempSV.MSSV)) // neu khong nhap MSSV khac -> dung MSSV cu~
		{
			strcpy(tempSV.MSSV, data[index]->info.MSSV);
			gotoxy(10, 9 + line * 2);
			cout << tempSV.MSSV;
		}
		delete_LineOnScreen(26, 9 + line * 2, 50);
		strcpy(tempSV.ho, NhapChuoi(26, 9 + line * 2, 50).c_str()); // nhap ho
		if (is_Empty_CArray(tempSV.ho))								// neu ENTER khi chua nhap -> dung ho cu~ cua SV
		{
			strcpy(tempSV.ho, data[index]->info.ho);
			gotoxy(26, 9 + line * 2);
			cout << tempSV.ho;
		}
		delete_LineOnScreen(81, 9 + line * 2, 15);
		strcpy(tempSV.ten, NhapChuoi(81, 9 + line * 2, 15).c_str());
		if (is_Empty_CArray(tempSV.ten)) // tuong tu nhu tren
		{
			strcpy(tempSV.ten, data[index]->info.ten);
			gotoxy(81, 9 + line * 2);
			cout << tempSV.ten;
		}
		delete_LineOnScreen(107, 9 + line * 2, 3);
		gioiTinh = NhapChuoi(107, 9 + line * 2, 3); // gan gioi tinh moi(default: NAM)
		if (gioiTinh == "NU")
			tempSV.phai = 1;
		strcpy(tempSV.password, data[index]->info.password); // cap lai mat khau cu~
		KhoiTao_PtrDT(tempSV.danhSachDiemThi);
		tempSV.danhSachDiemThi = data[index]->info.danhSachDiemThi; // cap lai diem thi cu~
	}
	if (THONGBAO(3, "LUU THAY DOI?"))
	{
		changeInfoByPtrArray_SV(data, index, tempSV);
		THONGBAO(1, "DA THAY DOI THONG TIN");
	}
	else
		THONGBAO(1, "DA HUY THAO TAC");
	check = 0; // ket thuc qua trinh HIEU CHINH
}
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
	//	VeKhung(125, 15, 150, 18);
	//	gotoxy(133, 16);
	//	cout << "HIEU CHINH";
}
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
		if (is_Empty_CArray(NewQuestion->info.question))
			THONGBAO(1, "CAU HOI RONG");
	} while (is_Empty_CArray(NewQuestion->info.question));
	do
	{
		strcpy(NewQuestion->info.ans1, NhapChuoi(21, 13, 94).data());
		if (is_Empty_CArray(NewQuestion->info.ans1))
			THONGBAO(1, "DAP AN 1 RONG");
	} while (is_Empty_CArray(NewQuestion->info.ans1));
	do
	{
		strcpy(NewQuestion->info.ans2, NhapChuoi(21, 16, 94).data());
		if (is_Empty_CArray(NewQuestion->info.ans2))
			THONGBAO(1, "DAP AN 2 RONG");
	} while (is_Empty_CArray(NewQuestion->info.ans2));
	do
	{
		strcpy(NewQuestion->info.ans3, NhapChuoi(21, 19, 94).data());
		if (is_Empty_CArray(NewQuestion->info.ans3))
			THONGBAO(1, "DAP AN 3 RONG");
	} while (is_Empty_CArray(NewQuestion->info.ans3));
	do
	{
		strcpy(NewQuestion->info.ans4, NhapChuoi(21, 22, 94).data());
		if (is_Empty_CArray(NewQuestion->info.ans4))
			THONGBAO(1, "DAP AN 4 RONG");
	} while (is_Empty_CArray(NewQuestion->info.ans4));
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
	cout << ExsistQuestion->info.question;
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
					DeleteQuestion(root, ExsistQuestion->info.ID);
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

	//	VEKHUNG_OPTION(2);
	TextColor(20);
	gotoxy(120, 16);
	cout << "     THEM CAU HOI       ";
	TextColor(112);
	gotoxy(120, 19);
	cout << "     XEM CAU HOI        ";

	gotoxy(116, 28);
	SetColor(5, 6);
	cout << "Page " << Page << '/' << MaxPage;
	SetColor(0, 7);
}
int CauHoi1(STreeCH &root, char maMH[], char tenMH[])
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
		PreTraversal(ListQuestion, root, maMH, NumberQuestion);
		MaxPage = NumberQuestion / 11 + 1;
		VeBangDanhSachCauHoi(maMH, MaxPage, Page);
		if (NumberQuestion == 0)
			THONGBAO(2, "KHONG CO CAU HOI");
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
					ThemCauHoi(root, maMH, tenMH);
					NumberQuestion = 0;
					// PreTraversal(ListQuestion,root, maMH,NumberQuestion);
					stop = 1;
					break;
				}
				case 19: // XEM CAU HOI
				{
					wherey = 10;																			  // muon wherey
					for (int i = (Page - 1) * 10; (Page * 10 < NumberQuestion ? Page * 10 : NumberQuestion);) // truong hop khong co cau hoi thi khong co con tro
					{
						gotoxy(3, wherey);
						cout << ">>";
						chon = getch();
						if (chon == 13)
						{
							XemCauHoi(root, ListQuestion[i], tenMH);
							NumberQuestion = 0;
							// PreTraversal(ListQuestion,root, maMH,NumberQuestion);
							stop = 1;
							break;
						}
						if (chon == 27)
						{
							if (THONGBAO(3, "BAN CO MUON THOAT KHONG"))
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
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////
int HienOptionLopHoc(bool check = 0)
{
	string option1 = "   THEM SINH VIEN       ";
	string option2 = "   XOA SINH VIEN        ";
	string option3 = "   HIEU CHINH           ";
	string option4 = "   IN DANH SACH DIEM    ";
	string option5 = "   IN DSLH THEO KHOA    ";
	// hien khung option
	if (check)
	{
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
		return 0;
	}

	int pos_Y = 15, conTro = 15;
	// hien de chon khung option
	gotoxy(120, 15);
	TextColor(20);
	cout << option1;
	TextColor(112);
	gotoxy(120, 17);
	cout << option2;
	gotoxy(120, 19);
	cout << option3;
	gotoxy(120, 21);
	cout << option4;
	gotoxy(120, 23);
	cout << option5;

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
	string maLop = NhapMa(6, 35, 10);
	while (is_Existed_MaLop(dslh, maLop.c_str()))
	{
		THONGBAO(1, "MA LOP DA TON TAI");
		maLop = NhapMa(6, 35, 10);
	}
	string tenLop = NhapChuoi(26, 35, 51);
	string nienKhoa = NhapMa(101, 35);
	LopHoc temp;
	strcpy(temp.maLop, maLop.c_str());
	strcpy(temp.tenLop, tenLop.c_str());
	temp.nienKhoa = atoi(nienKhoa.c_str());
	ThemLop(dslh, temp);
	THONGBAO(1, "DA THEM THANH CONG");
	return 1;
}
// hien cac thong tin trong dslh
void HienDanhSachLopHoc(LopHoc **data, int start)
{
	system("cls");
	SetColor(0, 7);
	VeHeader(1, "DANH SACH LOP HOC", "");
	VeDanhSach(1);
	HienOptionLopHoc(1);
	int count = 0;

	for (int i = start - 1; i < start + 9 && data[i] != NULL; i++)
	{
		gotoxy(10, 11 + 2 * count);
		cout << data[i]->maLop;
		gotoxy(26, 11 + 2 * count);
		cout << data[i]->tenLop;
		gotoxy(106, 11 + 2 * count);
		cout << data[i]->nienKhoa;
		count++;
	}
	gotoxy(0, 40);
}
void MENU_DSLH_GV(ListLH dslh, ListMH dsmh)
{
	system("cls");

	// PtrSV p;

	int numOfClasses = 0;
	for (int i = 0; i < dslh.n; i++)
		numOfClasses++;
	// LopHoc *temp[100] = {NULL};
	// p = data->danhSachSinhVien;
	// day thong tin tu dslk sang mang con tro
	// ListLH dslh;
	LopHoc *temp[MaxOfClasses] = {NULL};
	// copy du lieu tu danh sach con tro ban dau sang danh sach moi
	for (int i = 0; i < dslh.n; i++)
	{
		temp[i] = dslh.lh[i];
	}

	int line = 1, start = 1, count = 1, option = 0;
	int page = 1, maxPage = (numOfClasses - 1) / 10 + 1;
	HienDanhSachLopHoc(temp, start);

	// hien so page va option
	gotoxy(2, 9 + line * 2);
	cout << ">>";
	gotoxy(116, 29);
	cout << "Page " << page << '/' << maxPage;
	HienOptionLopHoc(1);

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
				delete_LineOnScreen(2, 9 + line * 2, 2);
				option = HienOptionLopHoc();
				switch (option)
				{
				case 0:
					THONGBAO(1, "option 0");
					break;
				case 1:
					ThemLopHoc(dslh);
					break;
				case 2:
					THONGBAO(1, "option 2");
					break;
				case 3:
					THONGBAO(1, "option 3");
					break;
				case 4:
					THONGBAO(1, "option 4");
					break;
				case 5:
					THONGBAO(1, "option 5");
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
			case F1:
				cout << "F1";
				break;
			case F5: // sap xep theo ho <-> ten(mssv)
				cout << "F5";
				break;
			case ENTER:
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
