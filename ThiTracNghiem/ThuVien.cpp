#include"ThuVien.h"
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void TextColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
int wherex()
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.X;
}
int wherey(void)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	return screen_buffer_info.dwCursorPosition.Y;
}
void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;
 
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

void DisableCtrButton(bool Close, bool Min, bool Max)
{
    HWND hWnd = GetConsoleWindow();
    HMENU hMenu = GetSystemMenu(hWnd, false);
    
    if (Close == 1)
    {
        DeleteMenu(hMenu, SC_CLOSE, MF_BYCOMMAND);
    }
    if (Min == 1)
    {
        DeleteMenu(hMenu, SC_MINIMIZE, MF_BYCOMMAND);
    }
    if (Max == 1)
    {
        DeleteMenu(hMenu, SC_MAXIMIZE, MF_BYCOMMAND);
    }
}
//////////////////////////////////////////////////////////////////////////
char GetKey()
{
	char key;
	key = getch();
	if (key == -32 || key == 0)
		return -getch();
	else return key;
}
int NhapSo(int x, int y)// x va y la dia chi de hien ki tu vua nhap
{
    char so=getch();
	if(so>='0'&&so<='9')
	{
		gotoxy(x,y);
		cout<<so-'0';
		return so-'0';
	}
	else return -1;
}
string NhapChuoi(int x,int y)// x va y la dia chi de hien ki tu vua nhap
{
	gotoxy(x,y);
	char chuoi[51];
	int index=0;
	char ki_tu;
	while((ki_tu=GetKey())!=13)
	{
	 if(index==51)continue;
	 if((ki_tu>='A'&&ki_tu<='Z')||(ki_tu>='a'&&ki_tu<='z')||(ki_tu==' '&&index!=0)||ki_tu=='-'||ki_tu=='_'||(ki_tu>='0'&&ki_tu<='9'))
	 {
	 	if(ki_tu==32&&index>0&&chuoi[index-1]==32)continue;
		chuoi[index]=ki_tu;
		gotoxy(x+index,y);
		cout<<ki_tu;
		index++;
	 }
	 if(ki_tu==8&&index>0)
	 {
	 	index--;
		chuoi[index]='\0';
	 	gotoxy(x+index,y);
	    cout<<" ";	
	    gotoxy(x+index,y);
	 }
	}
	chuoi[index]='\0';
	return string(chuoi);
}
string NhapMa(int x,int y,string loai)
{
	gotoxy(x,y);
	char Ma[21] ,ki_tu;
	int index=0;
	while((ki_tu=GetKey())!=13)
	{
		if(index==21)continue;
		if((index==0&&(ki_tu==' '))||ki_tu==-32||ki_tu==0)continue;
		if((ki_tu>='A'&&ki_tu<='Z')||(ki_tu>='a'&&ki_tu<='z')||(ki_tu>='0'&&ki_tu<='9')||ki_tu=='_'||ki_tu=='-')
		{
			Ma[index]=toupper(ki_tu);
			gotoxy(x+index,y);
			if(loai=="MATKHAU")cout<<'*';
			else cout<<Ma[index];
			index++;
		}
		if(ki_tu==8&&index>0)
	    {
	 	index--;
		Ma[index]='\0';
	 	gotoxy(x+index,y);
	    cout<<" ";	
	    gotoxy(x+index,y);
	   }
	}
	Ma[index]='\0';
	return Ma;
}