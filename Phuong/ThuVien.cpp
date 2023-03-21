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
//////////////////////////////////////////////////////////////////////////
char GetKey()
{
	char key;
	key = getch();
	if (key == -32 || key == 0)
		return -getch();
	else return key;
}
void VeKhung(int x1, int y1,int x2,int y2,int mau_nen,int loai_khung,string content) {
	int khung_ngang=196,khung_doc=179,goc1=218,goc2=191,goc3=192,goc4=217;
	int nen=1;
	//*****************TO MAU**************************
	if(loai_khung==0)nen=0;
	if(mau_nen!=-1)
	{
		SetBGColor(mau_nen);
		for (int ix = x1+nen; ix < x2; ix++) 
		{
			for (int iy = y1+nen; iy <y2; iy++)
			{
				gotoxy(ix,iy);
				cout<<" ";
			}
		}
	}
	//*********IN NOI DUNG*********
	gotoxy(x1+1,y1+1);
	cout<<content;
	SetBGColor(0);
	if(loai_khung==0)return;
	if(loai_khung==2)
	{
		khung_ngang=205;khung_doc=186;
		goc1=201;goc2=187;goc3=200;goc4=188;
	}
	for (int ix = x1+1; ix < x2; ix++) 
	{
		gotoxy(ix, y1);
		cout << char(khung_ngang);
		gotoxy(ix, y2 );
		cout << char(khung_ngang);
	}
	for (int iy = y1+1; iy < y2; iy++) 
	{
		gotoxy(x1, iy);
		cout << char(khung_doc);
		gotoxy(x2, iy);
		cout << char(khung_doc);
	}
	//*****************VE GOC************************** 
	gotoxy(x1, y1); cout << char(goc1);
	gotoxy(x2 , y1); cout << char(goc2);
	gotoxy(x1, y2 ); cout << char(goc3);
	gotoxy(x2 , y2); cout << char(goc4);
}
void VeBangDSLop(int x1,int y1,int x2,int y2){
	VeKhung(x1,y1,x2,y2,0);
	gotoxy((x1+x2)/2-15,y1+1);
	cout<<"DANH SACH CAC LOP";
	for(int j=y1+2;j<=y2-2;j+=2){
		for(int i=x1+1;i<x2;i++){
			gotoxy(i,j);
		    cout<<char(196);
		}
	}
	for(int j=y1+3;j<y2;j++){
		gotoxy(20,j);
		cout<<char(179);
	}
}
void VeBangDSSV(string content,int x1,int y1,int x2,int y2){
	VeKhung(x1,y1,x2,y2,0);
	gotoxy((x1+x2)/2-15,y1+1);
	cout<<content;
	for(int j=y1+2;j<=y2-2;j+=2){
		for(int i=x1+1;i<x2;i++){
			gotoxy(i,j);
		    cout<<char(196);
		}
	}
	for(int j=y1+3;j<y2;j++){
		gotoxy(20,j);
		cout<<char(179);
	}
	
	for(int j=y1+3;j<y2;j++){
	gotoxy(60,j);
	cout<<char(179);
   	}
   	for(int j=y1+3;j<y2;j++){
	gotoxy(80,j);
	cout<<char(179);
    }
    gotoxy(x1+6,y1+3);cout<<"MSSV";
    gotoxy(x1+35,y1+3);cout<<"HO";
    gotoxy(x1+68,y1+3);cout<<"TEN";
    gotoxy(x1+85,y1+3);cout<<"PHAI";
}
void VeBangSV(string content,int x1,int y1,int x2,int y2){
	VeKhung(x1,y1,x2,y2,0);
	gotoxy((x1+x2)/2-15,y1+1);
	cout<<content;
	for(int j=y1+2;j<=y2-2;j+=2){
		for(int i=x1+1;i<x2;i++){
			gotoxy(i,j);
		    cout<<char(196);
		}
	}
	for(int j=y1+3;j<y2;j++){
		gotoxy(50,j);
		cout<<char(179);
	}
    gotoxy(x1+20,y1+3);cout<<"MON HOC";
    gotoxy(x1+70,y1+3);cout<<"DIEM THI";
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
bool ThongBao(int x,int y,string noidung)
{
	char ki_tu,vi_tri='t';
	VeKhung(x,y,x+30,y+3,3,1);
	gotoxy(x+5,y+1);
	SetBGColor(3);
	cout<<noidung;
	gotoxy(x+12,y+2);
    SetBGColor(5);
	cout<<"YES ";
	SetBGColor(1);
	cout<<"| NO";
	while((ki_tu=getch())!=13)
	{
		gotoxy(x+12,y+2);
		if(ki_tu==75)
		{
	    SetBGColor(5);
	    cout<<"YES ";
	    SetBGColor(1);
	    cout<<"| NO";
		vi_tri='t';
		}
		if(ki_tu==77)
		{
	    SetBGColor(1);
	    cout<<"YES ";
	    SetBGColor(5);
	    cout<<"| NO";
	    vi_tri='p';
		}
	}
	SetBGColor(0);
	gotoxy(x,y);
	cout<<"                                 ";
	gotoxy(x,y+1);
	cout<<"                                 ";
	gotoxy(x,y+2);
	cout<<"                                 ";
	gotoxy(x,y+3);
	cout<<"                                 ";
	if(vi_tri=='t')return true;
	else return false;
}