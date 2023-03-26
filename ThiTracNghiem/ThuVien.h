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

#endif //THU_VIEN_H