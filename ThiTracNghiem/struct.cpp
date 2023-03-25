#include "struct.h"
using namespace std;

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
bool is_Existed_MaMH_MH(ListMH dsmh, const char *maMH)
{
    if (is_Empty_MH(dsmh))
        return 0;
    for (int i = 0; i < dsmh.n; i++)
        if (dsmh.nodes[i].maMonHoc == maMH)
            return 1;
    return 0;
}
int insert_MH(ListMH &dsmh, MonHoc info)
{
    if (is_Full_MH(dsmh))
        return 0;
    if (is_Existed_MaMH_MH(dsmh, info.maMonHoc))
        return -1;
    for (int i = dsmh.n - 1; i >= 0; i--)
    {
        if (dsmh.nodes[i].maMonHoc > info.maMonHoc)
            continue;
        for (int j = dsmh.n; j > i + 1; j--)
            dsmh.nodes[j] = dsmh.nodes[j - 1];
        dsmh.nodes[i + 1] = info;
        break;
    }
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
int CreateID(int Number[], int &i)
{
    int index;
    srand(time(0));
    index = rand() % (10000 - i) + i;
    swap(Number[index], Number[i]);
    i++;
    return Number[i - 1];
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
int DeleteQuestion(STreeCH &root, int ID)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        if (root->info.ID > ID)
            return DeleteQuestion(root->left, ID);
        else if (root->info.ID < ID)
            return DeleteQuestion(root->right, ID);
        else
        {
            rp = root;
            if (root->right == NULL)
                root = rp->left;
            else if (root->left == NULL)
                root = rp->right;
            else
                Delete(rp->right);
            delete rp;
            return 1;
        }
    }
}
void DeleteAllQuestion(STreeCH &root, char maMH[])
{
    if (root != NULL)
    {
        DeleteAllQuestion(root->left, maMH);
        DeleteAllQuestion(root->right, maMH);
        if (string(root->info.maMonHoc) == string(maMH))
        {
            cout << root->info.ID << '|' << root->info.maMonHoc << endl;
            DeleteQuestion(root, root->info.ID);
        }
    }
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
void PreTraversal(Queue<STreeCH> &q, STreeCH root, char maMH[], int &i, int number_question)
{
    if (root != NULL)
    {
        if ((string(root->info.maMonHoc) == string(maMH)) && i++ < number_question)
            q.Push(root);
        PreTraversal(q, root->left, maMH, i, number_question);
        PreTraversal(q, root->right, maMH, i, number_question);
    }
}
Queue<STreeCH> GetQuestion(STreeCH &root, char maMH[], int number_question)
{
    int index = 0, count = 0;
    Queue<STreeCH> q;
    if (root != NULL)
        PreTraversal(q, root, maMH, count, number_question);
    STreeCH Quesions[number_question];
    while (!q.empty())
        Quesions[index++] = q.pop();
    srand(time(0));
    for (int i = 0; i < number_question; i++)
    {
        count = rand() % (number_question - i) + i;
        cout << count << endl;
        swap(Quesions[i], Quesions[count]);
        q.Push(Quesions[i]);
    }
    return q;
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
bool is_Existed_DT(PtrDT first, char *maMon)
{
    if (is_Empty_DT(first))
        return 0;
    PtrDT p;
    for (p = first; p != NULL; p = p->next)
        if (p->info.maMonHoc == maMon)
            if (p->info.diemThi >= 0)
                return 1;
    return 0;
}
bool is_Existed_MaMH_DT(PtrDT first, char *maMon)
{
    if (is_Empty_DT(first))
        return 0;
    PtrDT p;
    for (p = first; p != NULL; p = p->next)
        if (p->info.maMonHoc == maMon)
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
    PtrDT u, v;
    for (u = first; u->info.maMonHoc > x.maMonHoc; v = u, u = u->next)
        ;
    if (u == first)
        insert_First_DT(first, x);
    else
        insert_After_DT(v, x);
    return 1;
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
bool delete_Pos_DT(PtrDT &first, char *maMon)
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
bool set_DiemThi_DT(PtrDT &p, float x)
{
    if (p == NULL)
        return 0;
    p->info.diemThi = x;
    return 1;
}
PtrDT pos_MaMH_DT(PtrDT first, char *maMon)
{
    if (is_Empty_DT(first))
        return NULL;
    PtrDT p = NULL;

    while (p->info.maMonHoc != maMon && p != NULL)
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
bool is_Existed_MSSV_SV(PtrSV first, const char *mssv)
{
    if (is_Empty_SV(first))
        return 0;
    PtrSV p = NULL;
    for (p = first; p != NULL; p = p->next)
        if (p->info.MSSV == mssv)
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
        return 0;
    PtrSV q = new nodeSinhVien;
    q->info = sv;
    q->next = p->next;
    p->next = q;
    return 1;
}
bool insert_Order_SV(PtrSV first, SinhVien sv)
{
    PtrSV u, v;
    for (u = first; u->info.MSSV < sv.MSSV; v = u, u = u->next)
        ;
    if (u == first)
        insert_First_SV(first, sv);
    else if (!insert_After_SV(v, sv))
        return 0;
    return 1;
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
    strcpy(info.maMonHoc, dsmh.nodes[0].maMonHoc);
    insert_First_DT(first, info);
    cur = first;
    for (int i = 1; i < dsmh.n; i++)
    {
        strcpy(info.maMonHoc, dsmh.nodes[i].maMonHoc);
        insert_After_DT(cur, info);
        cur = cur->next;
    }
    return first;
}
SinhVien create_New_SV(const char *mssv, ListMH dsmh)
{
    SinhVien sv;
    strcpy(sv.MSSV, mssv);
    sv.danhSachDiemThi = set_Blank_dsDT_SV(dsmh);
}
bool set_MSSV_SV(PtrSV p, const char *mssv)
{
    if (p == NULL)
        return 0;
    strcpy(p->info.MSSV, mssv);
    return 1;
}
bool set_ho_SV(PtrSV p, const char *ho)
{
    if (p == NULL)
        return 0;
    strcpy(p->info.ho, ho);
    return 1;
}
bool set_ten_SV(PtrSV p, const char *ten)
{
    if (p == NULL)
        return 0;
    strcpy(p->info.ten, ten);
    return 1;
}
bool set_phai_SV(PtrSV p, bool gioiTinh)
{
    if (p == NULL)
        return 0;
    p->info.phai = gioiTinh;
    return 1;
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

//---------------------------LopHoc--------------------------//
bool is_Empty_LH(ListLH ListLH)
{
    return (ListLH.n == 0);
}
bool is_Full_LH(ListLH ListLH)
{
    return (ListLH.n == MaxOfClasses);
}
bool is_Existed_MaLop(ListLH ListLH, char maLop[])
{
    for (int i = 0; i < ListLH.n; i++)
    {
        if (strcmp(maLop, ListLH.lh[i]->maLop) == 0)
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
int XoaLop(ListLH &ListLH, int i, int pos, LopHoc lh)
{
    if (i < 0 || i >= ListLH.n || ListLH.n == 0)
        return 0;
    // int pos = pos_MaLH_LH(ListLH, i, lh.maLop);
    if (pos > 0 || pos <= ListLH.n)
        return -1;
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
    // ListLH.n--;
    // return 1;
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
    strcpy(ListLH.lh[i]->nienKhoa, lh.nienKhoa);
}