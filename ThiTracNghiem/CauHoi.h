#include <iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>
#include<string>
#include<vector>
using namespace std;
#ifndef DANH_SACH_CAU_HOI
#define DANH_SACH_CAU_HOI
struct CauHoi
{
    int ID;
    char maMonHoc[16];
    unsigned short answer;
    char ans1[100], ans2[100], ans3[100], ans4[100], question[200]; 

};
typedef CauHoi*ptrCauHoi;
struct nodeCauHoi
{
    CauHoi info; //key = info.ID;
    nodeCauHoi *left=NULL;
    nodeCauHoi *right=NULL;
};

typedef nodeCauHoi *STreeCH;
int CreateID(int Number[],int &i);
void PreTraversal(CauHoi save[],STreeCH root,int &i);
void InsertQuestion(STreeCH &root,STreeCH question);
STreeCH balance(STreeCH root);
CauHoi* GetQuestion(STreeCH &root,int number_question);
//void Read(STreeCH &root);
#endif
/////////////////////////////////////////
