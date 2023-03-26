#ifndef THU_VIEN_H
#define THU_VIEN_H

#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <cctype>

using namespace std;

void gotoxy(int x, int y);
void TextColor(int color);
void SetBGColor(WORD color);
int wherex(void);
int wherey(void);
void SetColor(int backgound_color, int text_color);
char GetKey();
string NhapChuoi(int x, int y, int chieudai);
string NhapMa(int x, int y, int chieudai = 21, string = "");

#endif // THU_VIEN_H