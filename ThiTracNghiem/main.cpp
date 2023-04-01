#include "XuLyChuongTrinh.h"
using namespace std;

int main()
{
//char a[]="INT1339";
//	char b[]="c++";
//	STreeCH root=NULL;
//	doc_danhSachCauHoi(root);
//	CauHoi1(root,a,b);	
//	cin.ignore();	
	ListLH dslh;
	ListMH dsmh;
	doc_danhSachLopHoc(dslh);
	doc_danhSachMonHoc(dsmh);
//	system("pause");
//	MENU_DSMH_GV(dsmh);
//	MENU_DSLH_GV(dslh, dsmh);
	 MENU_DSSV_GV(dslh.lh[2], dsmh);
////	STreeCH root=NULL;
////	doc_danhSachCauHoi(root);
////	CauHoi(root,a,b);	
////	cin.ignore();
////	//ThemCauHoi(root,a,a);
////	PtrDT score=new nodeDiemThi;
////	Thi(root,score);
	gotoxy(0, 40);
	cout << "End of program\n";
	return 0;
} 
