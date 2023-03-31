void VeBangCauHoi(char tenMH[],int ID)
{
	system("cls");
	VeKhung(5, 5, 115, 27);
	int x = 5, y = 7;
	while (y <= 25)
	{
		x = 5;
		while (x <= 115)
		{
			gotoxy(x, y);
			if (x == 5)
				cout << char(195);
			else if (x == 115)
				cout << char(180);
			else
				cout << char(196);
			x++;
		}
		if (y == 7)
			y += 2;
		else
			y += 3;
	}
	x = 20, y = 7;
	while (y <= 27)
	{
		gotoxy(x, y);
		if (y == 7)
			cout << char(194);
		else if (y == 27)
			cout << char(193);
		else if (y == 9 || y == 12 || y == 15 || y == 18 || y == 21 || y == 24)
			cout << char(197);
		else
			cout << char(179);
		y++;
	}
	gotoxy(45,6);cout<<"NOI DUNG CAU HOI-"<<ID;
	gotoxy(45,8);cout<<tenMH;
	gotoxy(6, 8);cout << "TEN MON HOC";
	gotoxy(6, 10);cout << "NOI DUNG";
	gotoxy(6, 13);cout << "LUA CHON 1";
	gotoxy(6, 16);cout << "LUA CHON 2";
	gotoxy(6, 19);cout << "LUA CHON 3";
	gotoxy(6, 22);cout << "LUA CHON 4";
	gotoxy(6, 25);cout << "DAP AN";
//	VeKhung(125, 15, 150, 18);
//	gotoxy(133, 16);
//	cout << "HIEU CHINH";
}
void ThemCauHoi(STreeCH &root,char maMH[],char tenMH[])
{
	VeBangCauHoi(tenMH,1);
	STreeCH NewQuestion=new nodeCauHoi;
	NewQuestion->info.ID=1;
	char answer;
	strcpy(NewQuestion->info.maMonHoc,maMH);
	
	do{
		strcpy(NewQuestion->info.question,NhapChuoi(21,10,188).data());
		if(NewQuestion->info.question[0]=='\0')THONGBAO(1,"CAU HOI RONG");
	}while(NewQuestion->info.question[0]=='\0');
	do{
		strcpy(NewQuestion->info.ans1,NhapChuoi(21,13,94).data());
		if(NewQuestion->info.ans1[0]=='\0')THONGBAO(1,"DAP AN 1 RONG");
	}while(NewQuestion->info.ans1[0]=='\0');
	do{
		strcpy(NewQuestion->info.ans2,NhapChuoi(21,16,94).data());
		if(NewQuestion->info.ans2[0]=='\0')THONGBAO(1,"DAP AN 2 RONG");
	}while(NewQuestion->info.ans2[0]=='\0');
	do{
		strcpy(NewQuestion->info.ans3,NhapChuoi(21,19,94).data());
		if(NewQuestion->info.ans3[0]=='\0')THONGBAO(1,"DAP AN 3 RONG");
	}while(NewQuestion->info.ans3[0]=='\0');
	do{
		strcpy(NewQuestion->info.ans4,NhapChuoi(21,22,94).data());
		if(NewQuestion->info.ans4=='\0')THONGBAO(1,"DAP AN 4 RONG");
	}while(NewQuestion->info.ans4=='\0');
	gotoxy(21,25);
	while(1){
		answer=toupper(GetKey());
		if(answer==ENTER)break;
		if(answer==8)
		{
			gotoxy(21,25);
			cout<<" ";
			gotoxy(21,25);
			answer=0;
		}
		if(answer>='A'&&answer<='D')
		{
			cout<<answer;
		}
	}
	switch(answer)
	{
		case 'A':{
			NewQuestion->info.answer=1;
			break;
		}
		case 'B':{
			NewQuestion->info.answer=2;
			break;
		}
		case 'C':{
			NewQuestion->info.answer=3;
			break;
		}
		case 'D':{
			NewQuestion->info.answer=4;
			break;
		}
	}
	THONGBAO(0,"AN PHIM BAT KY DE THOAT");
	getch();
	InsertQuestion(root,NewQuestion);
}
void XemCauHoi(STreeCH &root,STreeCH &ExsistQuestion,char tenMH[])
{
	int chon,vi_tri_contro=16,stop=0;
	VeBangCauHoi(tenMH,ExsistQuestion->info.ID);
//	VEKHUNG_OPTION(2);
	TextColor(20);
	gotoxy(120,16);cout<<"     HIEU CHINH         ";
	TextColor(112);
	gotoxy(120,19);cout<<"     XOA CAU HOI        ";
	TextColor(7);
	
	gotoxy(21,10);
	cout<<ExsistQuestion->info.question;
	gotoxy(21,13);
	cout<<ExsistQuestion->info.ans1;
	gotoxy(21,16);
	cout<<ExsistQuestion->info.ans2;
	gotoxy(21,19);
	cout<<ExsistQuestion->info.ans3;
	gotoxy(21,22);
	cout<<ExsistQuestion->info.ans4;
	gotoxy(21,25);
	cout<<ExsistQuestion->info.answer;
	
	while(stop!=1)
	{
		chon=getch();
		switch(chon)
		{
			case ENTER:{
				if(vi_tri_contro==16)
				{
					int contro=10;
					gotoxy(3,10);
					cout<<">>";
					while(stop!=1)
					{
						chon=getch();
						switch(chon){
							case ENTER:{
								gotoxy(21,contro);cout<<"                                                                                             ";
								switch(contro)
								{
									case 10:{
										gotoxy(21,11);
										cout<<"                                                                                              ";
										strcpy(ExsistQuestion->info.question,NhapChuoi(21,10,188).data());
										break;
									}
									case 13:{
										strcpy(ExsistQuestion->info.ans1,NhapChuoi(21,13,94).data());
										break;
									}
									case 16:{
										strcpy(ExsistQuestion->info.ans2,NhapChuoi(21,16,94).data());
										break;
									}
									case 19:{
										strcpy(ExsistQuestion->info.ans3,NhapChuoi(21,19,94).data());
										break;
									}
									case 22:{
										strcpy(ExsistQuestion->info.ans4,NhapChuoi(21,22,94).data());
										break;
									}
									case 25:{
										char answer='\0';
										gotoxy(21,25);
										while(1){
											chon=toupper(GetKey());
											if(chon==ENTER&&answer!='\0')break;
											if(chon==8)
											{
												gotoxy(21,25);
												cout<<" ";
												gotoxy(21,25);
												answer='\0';
											}
											
											if(chon>='A'&&chon<='D')
											{
												gotoxy(21,25);
												answer=chon;
												cout<<answer;
											}
										}
										switch(answer)
										{
											case 'A':{
												ExsistQuestion->info.answer=1;
												break;
											}
											case 'B':{
												ExsistQuestion->info.answer=2;
												break;
											}
											case 'C':{
												ExsistQuestion->info.answer=3;
												break;
											}
											case 'D':{
												ExsistQuestion->info.answer=4;
												break;
											}
										}
										break;
									}
								}
								break;
							}
							case ESC:{
								stop=1;
								break;
							}
							case 0:
							case 224:{
								chon=getch();
								if(chon==UP&&contro!=10){
									gotoxy(3,contro);cout<<"  ";
									contro-=3;
									gotoxy(3,contro);cout<<">>";
								}
								if(chon==DOWN&&contro!=25){
									gotoxy(3,contro);cout<<"  ";
									contro+=3;
									gotoxy(3,contro);cout<<">>";
								}
								break;
							}
						}
					}
					stop=0;
				}
				else
				{
					if(THONGBAO(3,"BAN CO MUON XOA")){
						DeleteQuestion(root,ExsistQuestion->info.ID);
						return;
					}
					
				}
				break;
			}
			case ESC:{
				if(THONGBAO(3,"BAN CO MUON THOAT KHONG"))stop=1;
				break;
			}
			case 0:
			case 224:{
				chon=getch();
				if(chon==UP&&vi_tri_contro!=16)
				{
					TextColor(20);
					gotoxy(120,16);cout<<"     HIEU CHINH         ";
					TextColor(112);
					gotoxy(120,19);cout<<"     XOA CAU HOI        ";
					vi_tri_contro=16;
				}
				else if(chon==DOWN&&vi_tri_contro!=19)
				{
					TextColor(112);
					gotoxy(120,16);cout<<"     HIEU CHINH         ";
					TextColor(20);
					gotoxy(120,19);cout<<"     XOA CAU HOI        ";
					vi_tri_contro=19;
				}
				TextColor(7);
				break;
			}
		}
	}
}
void VeBangDanhSachCauHoi(char maMH[],int MaxPage,int Page)
{
	system("cls");
	VeKhung(5, 5, 115, 29);
	int x = 5, y = 7;
	while (y <= 27)
	{
		x = 5;
		while (x <= 115)
		{
			gotoxy(x, y);
			if (x == 5)
				cout << char(195);
			else if (x == 115)
				cout << char(180);
			else
				cout << char(196);
			x++;
		}
		y+=2;
	}
	x = 20, y = 7;
	while (y <= 29)
	{
		gotoxy(x, y);
		if (y == 7)
			cout << char(194);
		else if (y == 29)
			cout << char(193);
		else if (y == 9 || y == 11 || y == 13 || y == 15 || y == 17 || y == 19||y==21||y==23||y==25||y==27)
			cout << char(197);
		else
			cout << char(179);
		y++;
	}
	gotoxy(12, 8);cout << "ID";
	gotoxy(55,8);cout<<"NOI DUNG";
	gotoxy(45,6);cout<<"DANH SACH CAU HOI - ";
	gotoxy(65,6);cout<<maMH;
	
//	VEKHUNG_OPTION(2);
	TextColor(20);
	gotoxy(120,16);cout<<"     THEM CAU HOI       ";
	TextColor(112);
	gotoxy(120,19);cout<<"     XEM CAU HOI        ";
	
	gotoxy(116, 28);
	SetColor(5, 6);
	cout << "Page " << Page << '/' << MaxPage;
	SetColor(0, 7);
}
int CauHoi(STreeCH &root,char maMH[],char tenMH[])
{
	int NumberQuestion=0,vi_tri_contro,wherey,chon,MaxPage,Page,stop;
	char chuoi[90];
	STreeCH* ListQuestion=new STreeCH[300];
	Page=1;
	while(1)
	{
		// XUAT NOI DUNG
		
		stop=0,vi_tri_contro=16;NumberQuestion=0;
		PreTraversal(ListQuestion,root, maMH,NumberQuestion);
		MaxPage=NumberQuestion/11 +1;
		VeBangDanhSachCauHoi(maMH,MaxPage,Page);	
		if(NumberQuestion==0)THONGBAO(2,"KHONG CO CAU HOI");
		else
		{
			wherey=10;//muon tam wherey de in cau hoi
			for(int i=(Page-1)*10;i<(Page*10<NumberQuestion?Page*10:NumberQuestion);i++)
			{
				gotoxy(6,wherey);cout<<ListQuestion[i]->info.ID;
				gotoxy(21,wherey);
				if(strlen(ListQuestion[i]->info.question)<94)cout<<ListQuestion[i]->info.question;
				else 
				{
					strncpy(chuoi,ListQuestion[i]->info.question,91);
					cout<<chuoi<<"...";
				}
				wherey+=2;
			}
		}
		// CHON LUA
		while(stop!=1)
		{
			chon=getch();
			switch(chon)
			{
				case ENTER:{
					switch(vi_tri_contro)
					{
						case 16:
						{
							ThemCauHoi(root,maMH,tenMH);
							NumberQuestion=0;
							//PreTraversal(ListQuestion,root, maMH,NumberQuestion);
							stop=1;
							break;
						}
						case 19://XEM CAU HOI
						{
							wherey=10;//muon wherey
							for(int i=(Page-1)*10;(Page*10<NumberQuestion?Page*10:NumberQuestion);)// truong hop khong co cau hoi thi khong co con tro
							{
								gotoxy(3,wherey);cout<<">>";
								chon=getch();
								if(chon==13){
									XemCauHoi(root,ListQuestion[i],tenMH);
									NumberQuestion=0;
									//PreTraversal(ListQuestion,root, maMH,NumberQuestion);
									stop=1;
									break;
								}
								if(chon==27){
									if(THONGBAO(3,"BAN CO MUON THOAT KHONG"))break;
								}
								if(chon==224)
								{
									chon=getch();
									if(chon==UP&&wherey!=10)
									{
										gotoxy(3,wherey);cout<<"  ";
										wherey-=2;
										gotoxy(3,wherey);
										i--;
									}
									if(chon==DOWN&&wherey!=28&&i<(Page*10<NumberQuestion?Page*10:NumberQuestion)-1)
									{
										gotoxy(3,wherey);cout<<"  ";
										wherey+=2;
										gotoxy(3,wherey);
										i++;
									}
								}
							}
							break;
						}
					}
					//stop=1;
					break;
				}
				case 224:{
					chon=getch();
					switch(chon)
					{
						case UP:{
							if(vi_tri_contro!=16)
							{
								gotoxy(120,16);
								TextColor(20);
								cout<<"     THEM CAU HOI       ";
								gotoxy(120,19);
								TextColor(112);		
								cout<<"     XEM CAU HOI        ";
								vi_tri_contro=16;
							}
							break;
						}
						case DOWN:{
							if(vi_tri_contro!=19)
							{
								gotoxy(120,16);
								TextColor(112);
								cout<<"     THEM CAU HOI       ";
								gotoxy(120,19);
								TextColor(20);		
								cout<<"     XEM CAU HOI        ";
								vi_tri_contro=19;
							}
							break;
						}
						case LEFT:{
							if(Page!=1){
								Page--;
								stop=1;
							}
							break;
						}
						case RIGHT:{
							if(Page!=MaxPage){
								Page++;
								stop=1;
							}
							break;
						}
					}
					TextColor(7);
				}
			}
		}	
	}
}