#include "struct.h"

//---------------------------MonHoc--------------------------//
bool is_Empty_MH(ListMH dsmh)
{
    if (dsmh.n == 0)
        return 1;
    return 0;
}
bool is_Full_MH(ListMH dsmh)
{
    if (dsmh.n == MaxOfSubjects - 1)
        return 1;
    return 0;
}
bool is_Existed_MaMH_MH(ListMH dsmh, string maMH)
{
    if (is_Empty_MH(dsmh))
        return 0;
    for (int i = 0; i < dsmh.n; i++)
        if (strcmp(dsmh.nodes[i].maMonHoc, maMH.c_str()) == 0)
            return 1;
    return 0;
}
int insert_MH(ListMH &dsmh, MonHoc info) // ~ insert_Order
{
    if (is_Full_MH(dsmh))
        return 0;
    if (is_Existed_MaMH_MH(dsmh, info.maMonHoc))
        return -1;
    if (is_Empty_MH(dsmh))
    {
        dsmh.nodes[0] = info;
        dsmh.n = 1;
        return 1;
    }

    int i = dsmh.n - 1;
    while (i >= 0 && strcmp(dsmh.nodes[i].maMonHoc, info.maMonHoc) > 0)
    {
        dsmh.nodes[i + 1] = dsmh.nodes[i];
        --i;
    }
    dsmh.nodes[i + 1] = info;
    dsmh.n++;
    return 1;
}
int delete_MH(ListMH &dsmh, unsigned pos)
{
    if (is_Empty_MH(dsmh))
        return 0;
    if (pos >= dsmh.n || pos < 0)
        return -1;
    for (int i = pos; i < dsmh.n; i++)
        dsmh.nodes[i] = dsmh.nodes[i + 1];
    dsmh.n--;
    return 1;
}
void set_Info_MH(ListMH &dsmh, unsigned pos, MonHoc new_MH)
{
    dsmh.nodes[pos] = new_MH;
}
int pos_MaMH_MH(ListMH dsmh, const char *maMH)
{
    for (int i = 0; i < dsmh.n; i++)
        if (dsmh.nodes[i].maMonHoc == maMH)
            return i;
    return -1;
}
//---------------------------CauHoi--------------------------//

//-----TAO ID---------//
struct ID
{
    int id;
    ID *left = NULL;
    ID *right = NULL;
};
typedef ID *createID;

int numNode(ID *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + numNode(root->left) + numNode(root->right);
}
void Insert(ID *&tree, int data)
{
    if (tree == NULL)
    {
        createID p = new ID;
        p->id = data;
        tree = p;
        return;
    }
    else if (tree->id < data)
    {
        Insert(tree->right, data);
    }
    else if (tree->id > data)
    {
        Insert(tree->left, data);
    }
    else
        return;
}
int InsertToBalance(ID *&root, int min, int max, ofstream &file)
{
    if (root == NULL)
    {
        Insert(root, (min + max) / 2);
        file << (min + max) / 2 << endl;
    }
    else
    {
        if (numNode(root->left) == numNode(root->right))
        {
            max = root->id;
            InsertToBalance(root->left, min, max, file);
        }
        else
        {
            min = root->id;
            InsertToBalance(root->right, min, max, file);
        }
    }
}
void TaoFileID()
{
    createID root = NULL;
    int n = 3;
    ofstream file("Data/KeyID.txt");
    file << 1 << endl;
    for (int i = 1; i <= pow(2, n) - 1; i++)
        InsertToBalance(root, 1, pow(2, n), file); // lay can duoi
    file.close();
}
int ReadID()
{
    int number, temp;
    fstream docID("Data/KeyID.txt", ios::in | ios::out);
    if (!docID.is_open())
    {
        TaoFileID();
    }
    docID >> number;
    for (int i = 1; i <= number; i++)
    {
        docID >> temp;
    }
    docID.seekp(ios::beg);
    docID << ++number;
    return temp;
}
void RestoreID()
{
	int number;
    fstream docID("Data/KeyID.txt",ios::in|ios::out);
    docID>>number;
    docID.seekp(ios::beg);
    docID<<--number;
    docID.close();
}
STreeCH newnode(CauHoi CH)
{
    STreeCH p = new nodeCauHoi;
    p->info = CH;
    p->left = NULL;
    p->right = NULL;
}
// ---------them, xoa,sua cau hoi-----//
STreeCH rp;
int InsertQuestion(STreeCH &root, STreeCH question)
{
    if (root == NULL)
    {
        root = question;
        return 1;
    }
    else
    {
        if (root->info.ID > question->info.ID)
            return InsertQuestion(root->left, question);
        else if (root->info.ID < question->info.ID)
            return InsertQuestion(root->right, question);
        else
            return 0;
    }
}
int SoNode(STreeCH root)
{
    if (root == NULL)
         return 0;
             return 1 + SoNode(root->left) + SoNode(root->right);
}
void Delete(STreeCH &root)
{
    if (root->left != NULL)
    {
        Delete(root->left);
    }
    else
    {
        rp->info = root->info;
        rp = root;
        root = rp->right;
    }
}   
int DeleteQuestion(STreeCH &root, STreeCH &Question)
{
    int ID = Question->info.ID;
    if (root->left == NULL && root->right == NULL)
    {
        STreeCH temp;
        if (root == Question) // truong hop nut Question la nut cuoi
        {
            temp = root;
            Question = NULL;
            root = NULL;
            delete temp;
        }
        else // truong hop Question khong phai la nut cuoi
        {
            temp = root;
            Question->info = root->info;
            Question->info.ID = ID;
            root = NULL;
            delete temp;
        }
    }
    else if (SoNode(root->left) > SoNode(root->right))
        DeleteQuestion(root->left, Question);
    else
        DeleteQuestion(root->right, Question);
}
int Modify(STreeCH root, CauHoi question)
{
    if (root != NULL)
    {
        if (root->info.ID > question.ID)
            return Modify(root->left, question);
        else if (root->info.ID < question.ID)
            return Modify(root->right, question);
        else
        {
            root->info = question;
            return 1;
        }
    }
    return 0;
}
//---------can bang cay------
void Store(STreeCH root, vector<STreeCH> &nodes)
{
    if (root != NULL)
    {
        Store(root->left, nodes);
        nodes.push_back(root);
        Store(root->right, nodes);
    }
}
STreeCH Convert(vector<STreeCH> &nodes, int max, int min)
{
    if (max < min)
        return NULL;
    int mid = (max + min) / 2;
    STreeCH root = nodes[mid];
    root->left = Convert(nodes, mid - 1, min);
    root->right = Convert(nodes, max, mid + 1);
    return root;
}
STreeCH Balance(STreeCH root)
{
    vector<STreeCH> nodes;
    Store(root, nodes);
    return Convert(nodes, nodes.size() - 1, 0);
}
//--------LAY CAU HOI--------
void PreTraversal(STreeCH *AllQuestions, STreeCH root, char maMH[], int &count)
{
    if (root != NULL)
    {
        if ((string(root->info.maMonHoc) == string(maMH)))
            AllQuestions[count++] = root;
        PreTraversal(AllQuestions, root->left, maMH, count);
        PreTraversal(AllQuestions, root->right, maMH, count);
    }
}
STreeCH *GetQuestion(STreeCH &root, char maMH[], int number_question, int tong_so_cau_hoi)
{
    int index, count = 0;
    STreeCH *AllQuestions = new STreeCH[tong_so_cau_hoi]; // con tro all tro toi mang cac con tro STreeCH
    STreeCH *Questions = new STreeCH[number_question];

    PreTraversal(AllQuestions, root, maMH, count);
    srand(time(0));
    for (int i = 0; i < number_question; i++)
    {
        index = rand() % (count - i) + i;
        swap(AllQuestions[i], AllQuestions[index]);
        Questions[i] = AllQuestions[i];
    }
    delete[] AllQuestions; // xoa vung nho chua cac con tro
    return Questions;
}
int DemSoCauHoi(STreeCH root, char maMH[])
{
    if (root != NULL)
    {
        if (string(root->info.maMonHoc) == string(maMH))
        {
            return 1 + DemSoCauHoi(root->left, maMH) + DemSoCauHoi(root->right, maMH);
        }
        else
            return DemSoCauHoi(root->left, maMH) + DemSoCauHoi(root->right, maMH);
    }
    else
        return 0;
}
void TimCauHoiDaThi(STreeCH root, STreeCH list[], int ID, int &count)
{
    if (root != NULL)
    {
        if (root->info.ID == ID)
            list[count++] = root;
        else if (root->info.ID > ID)
            TimCauHoiDaThi(root->left, list, ID, count);
        else
            TimCauHoiDaThi(root->right, list, ID, count);
    }
}
//---------------------------DiemThi--------------------------//
void KhoiTao_PtrDT(PtrDT &first)
{
    first = NULL;
}
bool is_Empty_DT(PtrDT first)
{
    if (first == NULL)
        return 1;
    return 0;
}
bool is_Full_DT(PtrDT first)
{
    if (is_Empty_DT(first))
        return 0;
    int count = 0;
    PtrDT p;
    for (p = first; p != NULL; p = p->next)
        if (p->info.diemThi < 0)
            return 0;
    return 1;
}
bool is_Existed_DT(PtrDT first, string maMon)
{
    if (is_Empty_DT(first))
        return 0;
    PtrDT p;
    for (p = first; p != NULL; p = p->next)
        if (strcmp(p->info.maMonHoc, maMon.c_str()) == 0)
            if (p->info.diemThi >= 0)
                return 1;
    return 0;
}
bool is_Existed_MaMH_DT(PtrDT first, string maMon)
{
    if (is_Empty_DT(first))
        return 0;
    PtrDT p;
    for (p = first; p != NULL; p = p->next)
        if (strcmp(p->info.maMonHoc, maMon.c_str()) == 0)
            return 1;
    return 0;
}
bool insert_First_DT(PtrDT &first, DiemThi x)
{
    PtrDT p = new nodeDiemThi;
    p->info = x;
    p->next = first;
    first = p;
    return 1;
}
bool insert_After_DT(PtrDT p, DiemThi x)
{
    if (p == NULL)
        return 0;
    PtrDT q = new nodeDiemThi;
    q->info = x;
    q->next = p->next;
    p->next = q;
    return 1;
}
bool insert_Order_DT(PtrDT &first, DiemThi x)
{
    PtrDT u = first, v = NULL;
    while (u != NULL && strcmp(u->info.maMonHoc, x.maMonHoc) < 0)
    {
        v = u;
        u = u->next;
    }
    if (u == first)
        insert_First_DT(first, x);
    else if (!insert_After_DT(v, x))
        return false;
    return true;
}
bool delete_First_DT(PtrDT &first)
{
    if (is_Empty_DT(first))
        return 0;
    PtrDT p = first;
    first = p->next;
    delete p;
    return 1;
}
bool delete_After_DT(PtrDT p)
{
    if (p == NULL || p->next == NULL)
        return 0;
    PtrDT q = p->next;
    p->next = q->next;
    delete q;
    return 1;
}
bool delete_Pos_DT(PtrDT &first, string maMon)
{
    if (is_Empty_DT(first) || !is_Existed_MaMH_DT(first, maMon))
        return 0;
    PtrDT pos = pos_MaMH_DT(first, maMon);
    pos->info.diemThi = -1;
    return 1;
}
bool delete_List_DT(PtrDT &first)
{
    while (first != NULL)
        if (!delete_First_DT(first))
            return 0;
    return 1;
}
bool set_DiemThi_DT(PtrDT p, float x)
{
    if (p == NULL)
        return 0;
    p->info.diemThi = x;
    return 1;
}
bool set_DiemThi(PtrDT first,char maMH[],float x)
{
	while(first!=NULL)
	{
		if(strcmp(first->info.maMonHoc,maMH)==0)
		{
			first->info.diemThi=x;
			return 1;
		}
		else first=first->next;
	}
	return 0;
}
PtrDT pos_MaMH_DT(PtrDT first, string maMon)
{
    if (is_Empty_DT(first))
        return NULL;
    PtrDT p = first;

    while (strcmp(p->info.maMonHoc, maMon.c_str()) != 0 && p != NULL)
    {
        p = p->next;
    }
    return p;
	
}
//---------------------------SinhVien--------------------------//
void KhoiTao_PtrSV(PtrSV &first)
{
    first = NULL;
}
bool is_Empty_SV(PtrSV first)
{
    if (first == NULL)
        return 1;
    return 0;
}
bool is_Existed_MSSV_SV(PtrSV first, string mssv)
{
    if (is_Empty_SV(first))
        return 0;
    PtrSV p = NULL;
    for (p = first; p != NULL; p = p->next)
        if (strcmp(p->info.MSSV, mssv.c_str()) == 0)
            return 1;
    return 0;
}
void insert_First_SV(PtrSV &first, SinhVien sv)
{
    PtrSV p = new nodeSinhVien;
    p->info = sv;
    p->next = first;
    first = p;
}
bool insert_After_SV(PtrSV p, SinhVien sv)
{
    if (p == NULL)
        return false;
    PtrSV q = new nodeSinhVien;
    q->info = sv;
    q->next = p->next;
    p->next = q;
    return true;
}
bool insert_Order_SV(PtrSV &first, SinhVien sv)
{
    PtrSV u = first, v = NULL;
    while (u != NULL && strcmp(u->info.MSSV, sv.MSSV) < 0)
    {
        v = u;
        u = u->next;
    }
    if (u == first)
        insert_First_SV(first, sv);
    else if (!insert_After_SV(v, sv))
        return false;
    return true;
}
bool delete_First_SV(PtrSV &first)
{
    if (is_Empty_SV(first))
        return 0;
    PtrSV p = first;
    first = p->next;
    delete_List_DT(p->info.danhSachDiemThi);
    delete p;
    return 1;
}
bool delete_After_SV(PtrSV p)
{
    if (p == NULL)
        return 0;
    PtrSV q = p->next;
    p->next = q->next;
    delete_List_DT(q->info.danhSachDiemThi);
    delete q;
    return 1;
}
void delete_List_SV(PtrSV &first)
{
    while (!is_Empty_SV(first))
        delete_First_SV(first);
}
PtrDT set_Blank_dsDT_SV(ListMH dsmh)
{
    if (dsmh.n == 0)
        return NULL;
    PtrDT first, cur;
    KhoiTao_PtrDT(first);
    DiemThi info;
    info.diemThi = -1;
    for (int i = 0; i < dsmh.n; i++)
    {
        strcpy(info.maMonHoc, dsmh.nodes[i].maMonHoc);
        insert_Order_DT(first, info);
    }
    return first;
}
PtrSV pos_MSSV_SV(PtrSV first, const char *mssv)
{
    if (first == NULL)
        return NULL;
    for (PtrSV cur = first; cur != NULL; cur = cur->next)
        if (cur->info.MSSV == mssv)
            return cur;
    return NULL;
}
// thay doi thong tin cua node thong qua mang con tro(HIEU CHINH SINH VIEN)
void changeInfoByPtrArray_SV(PtrSV *nodePtrArray, int index, SinhVien newData)
{
    PtrSV cur = nodePtrArray[index];

    cur->info = newData;
}

//---------------------------LopHoc--------------------------//
bool is_Empty_LH(ListLH ListLH)
{
    return (ListLH.n == 0);
}
bool is_Full_LH(ListLH ListLH)
{
    return (ListLH.n == MaxOfClasses);
}
bool is_Existed_MaLop(ListLH ListLH, const char * maLop)
{
    for (int i = 0; i < ListLH.n; i++)
    {
        if (strcmp(ListLH.lh[i]->maLop, maLop) == 0)
            return true;
    }
    return false;
}
int ThemLop(ListLH &ListLH, LopHoc lh)
{
    if (is_Full_LH(ListLH))
        return 0;
    if (is_Existed_MaLop(ListLH, lh.maLop))
        return 0;
    // bat dau them lop hoc
    ListLH.lh[ListLH.n] = new LopHoc; // Khoi tao vung nho cho con tro
    *ListLH.lh[ListLH.n] = lh;        // Them mon hoc vao vung nho cua con tro, sau khi them vao thi tang so luong phan tu cua danh sach len 1
    ListLH.n++;
    return 1;
}
int pos_MaLH_LH(ListLH ListLH, int i, char maLop[])
{
    if (is_Empty_LH(ListLH))
        return 0;
    for (int vitri = i; vitri < ListLH.n; vitri++)
    {
        if (strcmp(ListLH.lh[vitri]->maLop, maLop) == 0)
            return vitri;
    }
    return 0;
}
int XoaLop(ListLH &ListLH, int pos)
{
    if (pos < 0 || pos >= ListLH.n || ListLH.n == 0)
        return 0;
    // for(int j = pos; j < ListLH.n - 1; j++)
    //      ListLH.lh[j] = ListLH.lh[j+1];
    //      delete_List_SV(ListLH.lh[i]->First);
    LopHoc *P = ListLH.lh[pos];
    for (int i = pos; i < ListLH.n; i++)
        ListLH.lh[i] = ListLH.lh[i + 1];
    delete_List_SV(P->danhSachSinhVien);
    delete P;
    ListLH.n--;
    return 1;
}
// int delete_LH(ListLH &dslh, int pos)
//{
// if(is_Empty(dslh))
// return 0;
// if(pos >= dslh.n || p < 0)
// return -1;
// LopHoc *P = &dslh.nodes[pos];
// for(int i = p; i < n; i++)
// dslh.nodes[i] = dslh.nodes[i + 1];
// delete_List_SV(P.danhSachSinhVien);
// delete P;
// dslh.n--;
// return 1;
//  }
void SuaLop(ListLH &ListLH, int i, LopHoc lh)
{
    if (i < 0 || i >= ListLH.n || ListLH.n == 0)
    {
        return; // vị trí i không hợp lệ
    }
    for (int j = 0; j < strlen(lh.maLop); j++)
    {
        if (lh.maLop[j] != ListLH.lh[i]->maLop[j])
        {
            return; // mã lớp không khớp
        }
    }
    // cập nhật thông tin lớp học
    strcpy(ListLH.lh[i]->tenLop, lh.tenLop);
    ListLH.lh[i]->nienKhoa = lh.nienKhoa;
}
