#include"XuLyChuongTrinh.h"
int KiemTraTK(string Name, string Password){
	if(Name=="GV"&&Password=="GV")return 2;
	fstream DocFileTK("Data/DanhSachTaiKhoan.txt");
	if(!DocFileTK.is_open())return 0;
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
