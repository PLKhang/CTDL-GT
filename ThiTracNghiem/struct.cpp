#include "struct.h"

//---------------------------MonHoc--------------------------//

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
void PreTraversal(CauHoi save[], STreeCH root, int &i)
{
    if (root != NULL)
    {
        save[i++] = root->info;
        PreTraversal(save, root->left, i);
        PreTraversal(save, root->right, i);
    }
}
CauHoi *GetQuestion(STreeCH &root, int number_question)
{
    if (root == NULL)
        return NULL;
    int index = 0, count = 0;
    CauHoi *temp = new CauHoi[number_question];
    CauHoi *save = new CauHoi[300];
    PreTraversal(save, root, count);
    srand(time(0));

    while (index < number_question)
    {
        count = rand() % (number_question - index) + index;
        swap(save[count], save[index]);
        temp[index] = save[index];
        index++;
    }
    delete[] save;
    return temp;
}
//---------------------------DiemThi--------------------------//
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
