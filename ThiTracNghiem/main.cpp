#include "XuLyChuongTrinh.h"
using namespace std;

int main()
{
	ListLH dslh;
	ListMH dsmh;
	STreeCH root = NULL;
	cout << "Goto main processing\n";
	MainProcessing(dsmh, dslh, root);
	
	gotoxy(0, 40);
	cout << "End of program\n";
	return 0;
}
