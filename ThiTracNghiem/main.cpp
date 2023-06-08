#include "XuLyChuongTrinh.h"
using namespace std;

int main()
{
	FullScreen();
	ListLH dslh;
	ListMH dsmh;
	STreeCH root = NULL;
	MainProcessing(dsmh, dslh, root);
	
	DeleteRoot(root);
	Delete_DSLH(dslh);
	
	gotoxy(0, 40);
	cout << "End of program\n";
	return 0;
}
