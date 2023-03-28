#include "XuLyChuongTrinh.h"
using namespace std;

int main()
{
	MENU_GV();
	MENU_SV();
	system("cls");
	VeHeader(2, "DANH SACH SINH VIEN", "D21CQCN01-N CONG NGHE 1 KHOA 2021");
	VeDanhSach(2);
	gotoxy(6, 9); cout << "  MA SO SINH VIEN  ";
	gotoxy(26, 9); cout << "                     HO                       ";
	gotoxy(81, 9); cout << "     TEN      ";
	gotoxy(101, 9); cout << "  GIOI TINH  ";
	gotoxy(0,40); 
	
	
	return 0;
}
