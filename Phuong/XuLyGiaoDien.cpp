#include"XuLyGiaoDien.h"
void ChuGV(int x,int y){
	TextColor(1);
	gotoxy(x,y++);
	cout<<"||==================  ====         //\\\\        ||\       ||  ||==================  ";
	gotoxy(x,y++);
	cout<<"||                     ||         //  \\\\       ||\\      ||  ||                    ";
	gotoxy(x,y++);
	cout<<"||                     ||        //    \\\\      || \\     ||  ||                    ";
	gotoxy(x,y++);
	cout<<"||                     ||       //      \\\\     ||  \\    ||  ||                    ";
	gotoxy(x,y++);
	cout<<"||         ========||  ||      // =======\\\\    ||   \\   ||  ||         ========||";
	gotoxy(x,y++);                                      
	cout<<"||                 ||  ||     //          \\\\   ||    \\  ||  ||                 || ";
	gotoxy(x,y++);
	cout<<"||                 ||  ||    //            \\\\  ||     \\ ||  ||                 || ";
	gotoxy(x,y++);
	cout<<"||=================|| ====  //              \\\\ ||      \\||  ||=================|| ";
	gotoxy(x,y++);
	gotoxy(x,y++);  
	cout<<"       \\\\             //  ====    =============   ||\\\\       ||                  ";
	gotoxy(x,y++);
	cout<<"        \\\\          //     ||     ||              || \\\\      ||                  ";
	gotoxy(x,y++);
	cout<<"         \\\\        //      ||     ||              ||  \\\\     ||                  ";
	gotoxy(x,y++); 
	cout<<"          \\\\      //       ||     ||              ||   \\\\    ||                  ";
	gotoxy(x,y++);
	cout<<"           \\\\    //        ||     ||===========   ||    \\\\   ||                  ";         
	gotoxy(x,y++);                     
	cout<<"            \\\\  //         ||     ||              ||     \\\\  ||                  ";
	gotoxy(x,y++);
	cout<<"             \\\\//          ||     ||              ||      \\\\ ||                  ";
	gotoxy(x,y++);
	cout<<"              \\/          ====    ||===========   ||       \\\\||                  ";    
	TextColor(7);        
}
void THONGBAO(string thongbao){
	VeKhung(129,1,149,10,7);
	gotoxy(130,3);
	TextColor(0);
	SetBGColor(7);
	cout<<"     THONG BAO     ";
	gotoxy(130,4);
	cout<<"___________________";
	gotoxy(130,6);
	cout<<thongbao;
	TextColor(7);
	if(thongbao!="")Sleep(1000);
}

void MENU(){
	system("cls");
	VeKhung(0,0,150,38,-1,2);
	gotoxy(1,36);
	THONGBAO();
}
int DANGNHAP(){
	MENU();
	string Name,Password;
	gotoxy(70,4);
	cout<<"THI TRAC NGHIEM";
	gotoxy(60,11);
	cout<<"ACCOUNT";
	VeKhung(68,10,90,12,0,1);
	gotoxy(60,14);
	cout<<"PASSWORD";
	VeKhung(68,13,90,15,0,1);
	do{
	Name=NhapMa(69,11,"TEN");
	if(Name=="")THONGBAO("NAME RONG!");	
	}while(Name=="");
	do{
		Password=NhapMa(69,14,"MATKHAU");
		if(Password=="")THONGBAO("PASSWORD RONG!");
	}while(Password=="");
	return KiemTraTK(Name,Password);
}
int MENUGV(){
	int chon,to=5,len=0;
	MENU();
	ChuGV(40,6);
	VeKhung(5,4,35,6,2);
	gotoxy(6,5);
	SetBGColor(2);
	cout<<"      DANH SACH CAC LOP     ";
	SetBGColor(0);
	VeKhung(5,8,35,10,-1,1,"       THEM SINH VIEN       ");
	VeKhung(5,12,35,14,-1,1,"    DANH SACH MON HOC      ");
	VeKhung(5,16,35,18,-1,1,"        BANG DIEM          ");
	VeKhung(5,20,35,22,-1,1,"          THI THU          ");
	VeKhung(5,24,35,26,-1,1,"           THOAT           ");
	while(true){
		chon=getch();
		len=0;
		if(chon==72&&to!=5){
			len=1;
			to-=4;
		}else if(chon==80&&to!=25){
			to+=4;
			len=-1;
		}else if(chon==13){
			if(to==5)return 1;
		    if(to==9)return 2;
			if(to==13)return 3;
			if(to==17)return 4;
			if(to==21)return 5;
			if(to==25){
				chon=ThongBao(50,30,"BAN CO MUON THOAT KHONG!");
				if(chon==1)return 6;
				else {
					gotoxy(6,25);
					continue;
				}
			}
		}

		if(len==1)gotoxy(6,to+4);
		else if(len==-1)gotoxy(6,to-4);
		else continue;
		// TO lai
		switch(wherey()){
			case 5:{
				cout<<"      DANH SACH CAC LOP      ";
				break;
			}
			case 9:{
				cout<<"       THEM SINH VIEN        ";
				break;
			}
			case 13:{
				cout<<"    DANH SACH MON HOC        ";
				break;
			}
			case 17:{
				cout<<"        BANG DIEM            ";
				break;
			}
			case 21:{
				cout<<"          THI THU            ";
				break;
			}
			case 25:{
				cout<<"           THOAT             ";
				break;
			}
		}
		SetBGColor(2);
		gotoxy(6,to);
		//**********To moi**************
		switch(to){
			case 5:{
				cout<<"      DANH SACH CAC LOP      ";
				break;
			}
			case 9:{
				cout<<"       THEM SINH VIEN        ";
				break; 
			}
			case 13:{
				cout<<"      DANH SACH MON HOC      ";
				break;
			}
			case 17:{
				cout<<"         BANG DIEM           ";
				break;
			}
			case 21:{
				cout<<"          THI THU            ";
				break;
			}
			case 25:{
				cout<<"           THOAT             ";
				break;
			}
		}
		SetBGColor(0);
	}
}
int MENUSV(){
	int chon,vitri=9;
	MENU();
	VeKhung(5,8,35,10,2);
	SetBGColor(2);
	gotoxy(6,9);
	cout<<"          LAM BAI  THI       ";
	SetBGColor(0);
	VeKhung(5,12,35,14,-1,1,"            XEM DIEM         ");
	VeKhung(5,16,35,18,-1,1,"              THOAT          ");
	while(true){
		chon=getch();
		if(chon==13){
			if(vitri==9)return 1;
			else if(vitri==13)return 2;
			else return 3;
		}
		if(chon==80&&vitri==17||chon==72&&vitri==9)continue;
		gotoxy(6,vitri);
		if(chon==80){
			vitri+=4;
		}
		else if(chon==72)vitri-=4;
		switch(wherey()){
			case 9:{
				cout<<"             THI             ";
				break;
			}
			case 13:{
				cout<<"            XEM DIEM         ";
				break;
			}
			case 17:{
				cout<<"              THOAT          ";
				break;
			}
		}
		gotoxy(6,vitri);
		SetBGColor(2);
		switch(vitri){
			case 9:{
				cout<<"             THI             ";
				break;
			}
			case 13:{
				cout<<"            XEM DIEM         ";
				break;
			}
			case 17:{
				cout<<"              THOAT          ";
				break;
			}
		}
		SetBGColor(0);
	}
}

//void Thi(int time,int socau,char mon){
//	
//}
void run(){
	int a,b,stop=0;
	a=DANGNHAP();
	while(stop!=1){
		switch(a){
			case 0:{
				THONGBAO("TAI KHOAN SAI");
				a=DANGNHAP();
				break;
			}
			case 1:{
				MENUSV();
				a=0;
				break;
				}
			case 2:{
				b=MENUGV();
				switch(b){
					case 1:{
						VeBangDSLop();
						break;
					}
					case 6:{
						a=0;
						break;
					}
				}
				break;
			}
		}
	}
}
