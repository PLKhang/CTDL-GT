#include "XuLyChuongTrinh.h"
#include "struct.h"
#include <thread>

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
int THONGBAO(int option, string thongbao)
{
    VeKhung(125, 0, 155, 10);
    gotoxy(126, 1);
    cout << "         THONG BAO           ";
    gotoxy(126, 2);
    cout << "-----------------------------";
    gotoxy(126, 3);
    cout << thongbao;
    if (option == 1) // clear thanh thong bao
    {
        Sleep(600);
        for (int i = 0; i <= 10; i++)
        {
            gotoxy(125, i);
            cout << "                               ";
        }
    }
    else if (option == 2) // xoa noi dung vua thong bao
    {
        for (int i = 3; i <= 9; i++)
        {
            gotoxy(126, i);
            cout << "                              ";
        }
    }
    else if (option == 3) // hien yes no
    {
        int yes_no = 0, option = 0;
        do
        {
            if (option == 224)
            {
                option = getch();
                if (option == 77)
                {
                    gotoxy(135, 8);
                    TextColor(16);
                    cout << "  YES  ";
                    TextColor(64);
                    gotoxy(142, 8);
                    cout << "   NO  ";
                    yes_no = 0;
                    "aaa";
                    continue;
                }
            }

            {
                gotoxy(135, 8);
                TextColor(64);
                cout << "  YES  ";
                TextColor(16);
                gotoxy(142, 8);
                cout << "   NO  ";
                yes_no = 1;
            }
        } while ((option = getch()) != 13);
        TextColor(7);
        return yes_no;
    }
}
void DongHo(int time)
{
	
	int giay;
	while(time>0)
	{
		gotoxy(131,6);
		cout<<time;
		gotoxy(135,6);
		cout<<"00";
		VeKhung(130,5,140,7);
		gotoxy(131,6);cout<<time;
		Sleep(980);
		time--;
		giay=59;
		while(giay>=0)
			{
				VeKhung(130,5,140,7);
				gotoxy(131,6);cout<<"   ";
				gotoxy(131,6);cout<<time;
				gotoxy(135,6);cout<<"   ";
				gotoxy(135,6);cout<<giay--;
				Sleep(980);
				if(stop==1)return;
			}
		
	}
	stop=1;
}
void THI(STreeCH &root,PtrDT& score)
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
	VeKhung(24, 18,28 ,20);
	
	// nhap va kiem tra xem co mon do khong
	do{
		gotoxy(25,11);cout<<"               ";//xoa vung nhap de nhap 
		strcpy(mon, NhapChuoi(25, 11, 15).data());
		if(strcmp(mon,"ESC")==0){
			if(THONGBAO(3,"BAN MUON THOAT KHONG"))return;
		}else {
			soluongcauhoi=DemSoCauHoi(root,mon);
			if(soluongcauhoi==0)THONGBAO(1,"KHONG CO CAU HOI");
		}
	}while(soluongcauhoi==0);
	
	do{
		gotoxy(25,15);cout<<"   ";
		so_cau = NhapSo(25, 15, 3);
		if(so_cau>soluongcauhoi)THONGBAO(1,"NHAP NHIEU HON SO CAU CO SAN");//in so cau ra nua
		if(so_cau==0)THONGBAO(1,"SO CAU =0 KHONG HOP LE");
	}while(so_cau>soluongcauhoi||so_cau==0);
	do{
		thoi_gian = NhapSo(25, 19, 3);
		if(thoi_gian==0)
		{
			THONGBAO(1,"THOI GIAN PHAI LON HON 0");
		}
	}while(thoi_gian==0);
	
	timer=thread(DongHo,thoi_gian);
	STreeCH* Questions=GetQuestion(root,mon,so_cau,soluongcauhoi);
	int so_cau_dung[so_cau],chon, index, wherey;// 10=A 14=B 18=C 22=D
	so_cau_dung[so_cau]={0}; //LUU CAU DA TRA LOI DUNG =1 sai =-1  chua chon =0
	for(int i=0;i<so_cau;i++)so_cau_dung[i]=0;
	for(int i=0;stop!=1;)
	{
		if(i==so_cau)
		{
			stop=THONGBAO(3,"BAN CO MUON THOAT KHONG");
				if(stop==0)
				{
					i--;
					continue;
				}
		}
			index=wherey=10;// GAN TAI VI TRI CAU A
			system("cls");
			VeKhungThi();
			gotoxy(5,27);
			if(so_cau_dung[i]==0)cout<<"BAN CHUA CHON";
			else
			 if(so_cau_dung[i]==1)
				{
					switch(Questions[i]->info.answer)
					{
						case 1:{
							cout<<" BAN CHON A";
							break;
						}
						case 2:{
							cout<<" BAN CHON B";
							break;
						}
						case 3:{
							cout<<" BAN CHON C";
							break;
						}
						case 4:{
							cout<<" BAN CHON D";
							break;
						}
					}
				}
			else 
			{
				switch(so_cau_dung[i])
				{
					case -1:{
						cout<<" BAN CHON A";
						break;
					}
					case -2:{
						cout<<" BAN CHON B";
						break;
					}
					case -3:{
						cout<<" BAN CHON C";
						break;
					}
					case -4:{
						cout<<" BAN CHON D";
						break;
					}
					
				}
			}
			gotoxy(6, 6);
			cout << Questions[i]->info.question;// IN CAU HOI
			gotoxy(16, 10);
			cout << Questions[i]->info.ans1;//IN CAU A
			gotoxy(16, 14);
			cout << Questions[i]->info.ans2;//IN CAU B
			gotoxy(16, 18);
			cout << Questions[i]->info.ans3;//IN CAU C
			gotoxy(16, 22);
			cout << Questions[i]->info.ans4;//IN CAU D
			// XEM LUA CHON
			while (stop!=1)
			{
				chon = getch();//LAY KI TU TU BAN PHIM
				if(chon==27)//NHAN ESC
				{
					stop=THONGBAO(3, "BAN CO MUON THOAT KHONG");//NEU THOAT THI STOP=1 VA THOAT
					THONGBAO(1);	
				}
				else 
					if(chon==13)// PHAT HIEN NHAN ENTER VA KIEM TRA DAP AN
						{
							if((Questions[i]->info.answer==1&&index==10)||(Questions[i]->info.answer==2&&index==14)||(Questions[i]->info.answer==3&&index==18)||(Questions[i]->info.answer==4&&index==22))so_cau_dung[i]=1;
							else
							{
								switch(index)
								{
									case 10:{
										so_cau_dung[i]=-1;//chon sai
										break;
									}
									case 14:{
										so_cau_dung[i]=-2;//chon sai
										break;
									}
									case 18:{
										so_cau_dung[i]=-3;//chon sai
										break;
									}
									case 22:{
										so_cau_dung[i]=-4;//chon sai
										break;
									}
								}
							}
							i++;// qua trang moi
							break;
						}
				else 
					if(chon==224)chon=getch();// NUT MO Rï¿½NG Nï¿½N Lï¿½Y THï¿½M Mï¿½T LAN NUA
						// XU LY DI CHUYEN
						if(chon==72&&index!=10)//KIEM TRA CO NHAN NUT LEN HAY KHONG VA INDEX KHONG O TAI CAU A
						{
							wherey=index;
							index-=4;
						}else if(chon==80&&index!=22)//NUT XUONG VA INDEX KHONG TAI CAU D
						{
							wherey=index;
							index+=4;
						}
						else if(chon==75&&i>0)
						{
							i--;//lui trang
							break;
						}else if(chon==77&&i<so_cau)
						{
							i++;//qua trang
							break;	
						}
						else continue;
						
						//TO LAI MAU TRANG
						SetColor(0,7);
						gotoxy(6,wherey);cout<<"         ";
						gotoxy(6,wherey+1);cout<<"         ";
						gotoxy(6,wherey+2);cout<<"         ";
						//VIET LAI DAP AN
						switch (wherey)
						{
							case 10:
							{
								gotoxy(10,wherey);cout<<"A";
								break;
							}
							case 14:
							{
								gotoxy(10,wherey);cout<<"B";
								break;
							}
							case 18:{
								gotoxy(10,wherey);cout<<"C";
								break;
							}
							case 22:{
								gotoxy(10,wherey);cout<<"D";
								break;
							}
						}
						// TO MAU XANH
						SetColor(2,0);
						gotoxy(6,index);cout<<"         ";
						gotoxy(6,index+1);cout<<"         ";
						gotoxy(6,index+2);cout<<"         ";
						switch (index)//TO MAU XANH
						{
							case 10:
							{
								gotoxy(10,index);cout<<"A";
								break;
							}
							case 14:
							{
								gotoxy(10,index);cout<<"B";
								break;
							}
							case 18:{
								gotoxy(10,index);cout<<"C";
								break;
							}
							case 22:{
								gotoxy(10,index);cout<<"D";
								break;
							}
						}
						SetColor(0,7);// DAT LAI MAU CHU VA Nï¿½N
			}
		}
		
	// TINH DIEM
	for(int i=0;i<so_cau;i++)
		if(so_cau_dung[i]==1)score->info.diemThi+=1;//DEM SO CAU DUNG
		
	score->info.diemThi=(score->info.diemThi/so_cau)*10; //TINH DIEM
	stop=1;
	timer.join(); 
}
