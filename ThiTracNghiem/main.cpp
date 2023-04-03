#include "XuLyChuongTrinh.h"
using namespace std;

int main()
{
	ListLH dslh;
	ListMH dsmh;
	STreeCH root = NULL;

	MainProcessing(dsmh, dslh, root);
	//	MENU_DSMH_GV(dsch, dsmh);
	//	MENU_DSLH_GV(dslh, dsmh, dsch);
	//	MENU_DSSV_GV(dslh.lh[2], dsmh);
	// THEMSINHVIEN(dslh, dsmh);
	// MENU_DSLH_GV(dslh, dsmh, dsch);

	//	STreeCH root=NULL;
	//	doc_danhSachCauHoi(root);
	//	CauHoi(root,a,b);
	//	cin.ignore();
	// ThemCauHoi(root,a,a);
	//	PtrDT score=new nodeDiemThi;
	//	Thi(root,score);
	gotoxy(0, 40);
	cout << "End of program\n";
	return 0;
}
