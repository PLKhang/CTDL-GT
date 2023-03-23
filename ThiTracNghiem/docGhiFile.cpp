#include "docGhiFile.h"
template<typename T>
struct node{
    T info;
    node<T>*next;
};
template<typename T> class Queue{
    private:
        node<T>* front=NULL;
        node<T>* rear=NULL;
    public:
        void Push(T data)
        {
            node<T>* temp=new node<T>;
            temp->info=data;
            if(front==NULL) front=temp;
            else rear->next=temp;
            rear=temp;
        }
        T pop(){
            if(!this->empty())
            {
            node<T> *run=front;
            T data=front->info;
            if(front==rear&&front!=NULL)front=rear=NULL;
            else front=front->next;
            delete run;
            return data;
            }
        }
        bool empty(){
            if(front==NULL)return true;
            else return false;
        }
};
int doc_danhSachLopHoc(ListLH &dslh)
{
    
}
int doc_danhSachSinhVien(PtrSV &dssv, string maLH)
{
    KhoiTao_PtrSV(dssv);
    string fileLocation = "Data/DanhSachSinhVien/" + maLH + ".txt";

    ifstream file(fileLocation);
    if (!file)
        return 0;

    string line;
    SinhVien info;

    int pos = 0;
    int field_Num = 1;
    string field;

    while (getline(file, line))
    {
        pos = 0;
        field_Num = 1;
        while ((pos = line.find("|")) != string::npos)
        {
            field = line.substr(0, pos);
            line.erase(0, pos + 1);
            switch (field_Num)
            {
            case 1:
                strcpy(info.MSSV, field.c_str());
                break;
            case 2:
                strcpy(info.password, field.c_str());
                break;
            case 3:
                strcpy(info.ho, field.c_str());
                break;
            case 4:
                strcpy(info.ten, field.c_str());
                break;
            case 5:
                if (atoi(field.c_str()) == 1)
                    info.phai = true;
                else
                    info.phai = false;
                break;
            default:
                return -1;
            }
            field_Num++;
        }
        doc_danhSachDiemThi(info.danhSachDiemThi, maLH, info.MSSV);
        insert_Order_SV(dssv, info);
    }
    return 1;
}
int doc_danhSachDiemThi(PtrDT &dsdt, string maLH, string mssv)
{
    KhoiTao_PtrDT(dsdt);
    string fileLocation = "Data/DanhSachSinhVien/DanhSachDiemThi/" + maLH + '/' + mssv + ".txt";

    ifstream file(fileLocation);
    if (!file)
        return 0;

    string line;
    DiemThi info;

    int pos = 0;
    int field_Num = 1;
    string field;

    while (getline(file, line))
    {
        pos = 0;
        field_Num = 1;
        while ((pos = line.find("|")) != string::npos)
        {
            field = line.substr(0, pos);
            line.erase(0, pos + 1);
            switch (field_Num)
            {
            case 1:
                strcpy(info.maMonHoc, field.c_str());
                break;
            case 2:
                info.diemThi = atof(field.c_str());
                break;
            default:
                return -1;
            }
            field_Num++;
        }
        insert_Order_DT(dsdt, info);
    }
    return 1;
}
int doc_danhSachMonHoc(ListMH &dsmh);
int doc_danhSachCauHoi(STreeCH &dsch){
    ifstream docfile("Data/DanhSachCauHoi.txt");
    STreeCH question;
    string temp;
    if(!docfile)return 0;
    while(!docfile.eof()){
        question=new nodeCauHoi;
        docfile.getline(question->info.maMonHoc,16);
        docfile>>question->info.ID;
        docfile.ignore();
        docfile.getline(question->info.question,200);
        docfile.getline(question->info.ans1,100);
        docfile.getline(question->info.ans2,100);
        docfile.getline(question->info.ans3,100);
        docfile.getline(question->info.ans4,100);
        docfile>>question->info.answer;
        docfile.ignore();
        InsertQuestion(dsch,question);
    }
    docfile.close();
}

int ghi_danhSachLopHoc(ListLH dslh);
int ghi_danhSachSinhVien(PtrSV dssv);
int ghi_danhSachDiemThi(PtrDT dsdt);
int ghi_danhSachMonHoc(ListMH dsmh);
int ghi_danhSachCauHoi(STreeCH dsch){
    ofstream ghifile("Data/DanhSachCauHoi.txt");

    Queue<STreeCH>q;
    STreeCH temp;

    if(!ghifile)return 0;
    q.Push(dsch);
    while(!q.empty())
    {
        temp=q.pop();
        if(temp->left!=NULL)q.Push(temp->left);
        if(temp->right!=NULL)q.Push(temp->right);
        ghifile<<temp->info.maMonHoc<<endl<<temp->info.ID<<endl<<temp->info.question<<endl<<temp->info.ans1<<endl
        <<temp->info.ans2<<endl<<temp->info.ans3<<endl<<temp->info.ans4<<temp->info.answer;
        if(!q.empty())ghifile<<endl;
    }
    ghifile.close();
}