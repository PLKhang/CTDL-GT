#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
#include<cctype>
using namespace std;
void gotoxy(int x,int y);
void TextColor(int color) ;
void SetBGColor(WORD color);
int wherex(void);
int wherey(void);
char GetKey();
int NhapSo(int x,int y);
string NhapChuoi(int x,int y);//xong
string NhapMa(int x,int y,string="NonMatKhau");
void VeKhung(int x1,int y1,int x2,int y2,int =-1,int =1,string="");
void VeBangDSLop(int=3 ,int=2 ,int=100 ,int=30);
void VeBangDSSV(string="",int=3,int=2,int=100,int=30);
void VeBangSV(string="",int=3,int=2,int=100,int=30);
bool ThongBao(int x,int y,string noidung);
