#ifndef THU_VIEN_H
#define THU_VIEN_H

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
void SetWindowSize(SHORT width, SHORT height);
void SetColor(int backgound_color, int text_color);
void DisableCtrButton(bool Close=0, bool Min=0, bool Max=1);
char GetKey();
int NhapSo(int x,int y);
string NhapChuoi(int x,int y);//xong
string NhapMa(int x,int y,string="");
void VeKhung(int x1,int y1,int x2,int y2,int =-1,int =1,string="");
void VeBangDSLop(int=3 ,int=2 ,int=100 ,int=30);
void VeBangDSSV(string="",int=3,int=2,int=100,int=30);
void VeBangSV(string="",int=3,int=2,int=100,int=30);
bool ThongBao(int x,int y,string noidung);

#endif //THU_VIEN_H