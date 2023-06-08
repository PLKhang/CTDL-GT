#include "struct.h"

//---------------------------MonHoc--------------------------//
bool is_Empty_MH(ListMH dsmh)
{
    return dsmh.n == 0;
}
bool is_Full_MH(ListMH dsmh)
{
    return (dsmh.n == MaxOfSubjects);
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
bool is_existed_tenMH(ListMH dsmh, string tenMH)
{
    if (is_Empty_MH(dsmh))
        return 0;
    for (int i = 0; i < dsmh.n; i++)
        if (strcmp(dsmh.nodes[i].tenMonHoc, tenMH.c_str()) == 0)
            return 1;
    return 0;
}
int insert_MH(ListMH &dsmh, MonHoc info) // ~ insert_Order
{
    if (is_Full_MH(dsmh))
        return 0;
    if (is_Existed_MaMH_MH(dsmh, info.maMonHoc) || is_existed_tenMH(dsmh, info.tenMonHoc))
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
int pos_MaMH_MH(ListMH dsmh, const char *maMH)
{
    for (int i = 0; i < dsmh.n; i++)
        if (dsmh.nodes[i].maMonHoc == maMH)
            return i;
    return -1;
}
string FindName(ListMH dsmh, char maMH[])
{
    for (int i = 0; i < dsmh.n; i++)
    {
        if (strcmp(dsmh.nodes[i].maMonHoc, maMH) == 0)
            return dsmh.nodes[i].tenMonHoc;
    }
}
//---------------------------CauHoi--------------------------//

//-----TAO ID---------//
int NumberOfNode(ID *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + NumberOfNode(root->left) + NumberOfNode(root->right);
}
void InsertID(ID*& tree, int data)
{
    if (tree == NULL)
    {
        createID p = new ID;
        p->id = data;
        p->left=NULL;
        p->right=NULL;
        tree = p;
        return;
    }
    else
    {
        ID* temp=tree;
        while(1)
        {
            if(temp->id>data)
            {
                if(temp->left==NULL)
                {
                    createID p = new ID;
                    p->id = data;
                    p->left=NULL;
                    p->right=NULL;
                    temp->left = p;
                    return ;
                }
                temp=temp->left;
            }
            else if(temp->id<data)
            {
                if(temp->right==NULL)
                {
                    createID p = new ID;
                    p->id = data;
                    p->left=NULL;
                    p->right=NULL;
                    temp->right = p;
                    return ;
                }
                temp=temp->right;
            }
            else return ;
        }
    }
}
int InsertToBalance(ID *&root, int min, int max, int &temp, ofstream &file)
{
    if (root == NULL)
    {
        InsertID(root, (min + max) / 2);
        temp = (min + max) / 2;
        file.write(reinterpret_cast<char *>(&temp), sizeof(int));
    }
    else
    {
        if (NumberOfNode(root->left) == NumberOfNode(root->right))
        {
            max = root->id;
            InsertToBalance(root->left, min, max, temp, file);
        }
        else
        {
            min = root->id;
            InsertToBalance(root->right, min, max, temp, file);
        }
    }
}
void DeleteAllID(ID *root)
{
    if (root != NULL)
    {
        DeleteAllID(root->left);
        DeleteAllID(root->right);
        delete root;
    }
}
void TaoFileID()
{
    ifstream check("Data/FileOldID.bin", ios::binary);
    if (check.is_open())
        return;
    int n = 14, temp = 0;
    createID root = NULL;
    ofstream FileOldKey("Data/FileOldID.bin", ios::binary);
    FileOldKey.write(reinterpret_cast<char *>(&temp), sizeof(temp));
    FileOldKey.close();
    ofstream FileNewID("Data/FileNewID.bin", ios::binary);
    temp = 1;
    FileNewID.write(reinterpret_cast<char *>(&temp), sizeof(int));
    for (int i = 1; i <= pow(2, n) - 1; i++)
        InsertToBalance(root, 1, pow(2, n), temp, FileNewID); // lay can duoi
    DeleteAllID(root);
    FileNewID.close();
}
int ReadID(int &ExistID, int option)
{
    //option =0 lay ID de chen ID !=0 Lay ID de xem
    int number, ID;
    fstream FileOldID("Data/FileOldID.bin", ios::binary | ios::in | ios::out);
    fstream FileNewID("Data/FileNewID.bin", ios::binary | ios::in | ios::out);
    FileOldID.read(reinterpret_cast<char *>(&number), sizeof(number));
    if (number != 0)
    {
        FileOldID.seekg(number * sizeof(int), ios::beg);
        FileOldID.read(reinterpret_cast<char *>(&ID), sizeof(int));
        if (option == 0)
        {
            number--;
            FileOldID.seekg(ios::beg);
            FileOldID.write(reinterpret_cast<char *>(&number), sizeof(int));
        }
        ExistID = ID;
        FileNewID.close();
        FileOldID.close();
        if (number == 0)
            return 1; // phục hồi lại cây ban đầu để sử dụng file key
        else
            return 2; // cần cân bằng lại cây
    }
    else
    {

        FileNewID.read(reinterpret_cast<char *>(&number), sizeof(int));
        FileNewID.seekg(number * sizeof(int), ios::beg);
        FileNewID.read(reinterpret_cast<char *>(&ID), sizeof(int));
        if (option == 0)
        {
            ++number;
            FileNewID.seekp(ios::beg);
            FileNewID.write(reinterpret_cast<char *>(&number), sizeof(int));
        }
        ExistID = ID;
        FileNewID.close();
        FileOldID.close();
        return 0; // không cần cân bằng lại cây
    }
}

void RestoreID()
{
    int number;
    fstream FileID("Data/FileNewID.bin", ios::in | ios::out);
    FileID.read(reinterpret_cast<char *>(&number), sizeof(int));
    FileID.seekp(ios::beg);
    --number;
    FileID.write(reinterpret_cast<char *>(&number), sizeof(int));
    FileID.close();
}
int Insert(STreeCH &root, STreeCH &question)
{
    if (root == NULL)
    {
        root = question;
        return 1;
    }
    else
    {
        STreeCH temp = root;
        while (1)
        {
            if (temp->info.ID > question->info.ID)
            {
                if (temp->left == NULL)
                {
                    temp->left = question;
                    question->left = NULL;
                    question->right = NULL;
                    return 1;
                }
                temp = temp->left;
            }
            else if (temp->info.ID < question->info.ID)
            {
                if (temp->right == NULL)
                {
                    temp->right = question;
                    question->left = NULL;
                    question->right = NULL;
                    return 1;
                }
                temp = temp->right;
            }
            else
                return 0;
        }
    }
}
//---------can bang cay------
void Store(STreeCH root, Array<STreeCH> &nodes)// chua cay trong arr theo thu tu tang dan
{
    if (root != NULL)
    {
        Store(root->left, nodes);
        nodes.push(root);
        Store(root->right, nodes);
    }
}
STreeCH Convert(Array<STreeCH> &nodes, int max, int min)// tao cay can bang
{
    if (max < min)
        return NULL;
    int mid = (max + min) / 2;
    STreeCH root = nodes[mid];
    root->left = Convert(nodes, mid - 1, min);
    root->right = Convert(nodes, max, mid + 1);
    return root;
}
STreeCH Balance(STreeCH root)//tra ve cay can bang
{
    Array<STreeCH> nodes;
    STreeCH NewRoot;
    Store(root, nodes);
    NewRoot = Convert(nodes, nodes.GetIndexLast(), 0);
    nodes.destroy();
    return NewRoot;
}
// tim nut trong cay
STreeCH BinarySearch(STreeCH root, int ID)
{
    if (root == NULL)
        return NULL;
    STreeCH temp = root;
    while (1)
    {
        if (temp->info.ID > ID)
            temp = temp->left;
        else if (temp->info.ID < ID)
            temp = temp->right;
        else
            return temp;
    }
    return temp;
}
// Phuc hồi cây
STreeCH OriginRoot(STreeCH root)
{
    int number, ID;
    STreeCH p = NULL;
    fstream FileNewID("Data/FileNewID.bin", ios::binary | ios::in | ios::out);
    FileNewID.read(reinterpret_cast<char *>(&number), sizeof(int));
    Array<STreeCH> Arr(number); // number lớn hơn tổng số câu là 1
    for (int i = 1; i < number; i++)
    {
        FileNewID.seekg((i) * sizeof(int), ios::beg);
        FileNewID.read(reinterpret_cast<char *>(&ID), sizeof(int));
        Arr[i] = BinarySearch(root, ID);
    }
    for (int i = 1; i < number; i++)
    {
        Arr[i]->left = NULL;
        Arr[i]->right == NULL;
    }
    for (int i = 1; i < number; i++)
        Insert(p, Arr[i]);
    return p;
}
// ---------them, xoa,sua cau hoi-----//
STreeCH rp;
STreeCH newnode()
{
    STreeCH p = new nodeCauHoi;
    p->info.ID = 0;
    p->left = NULL;
    p->right = NULL;
    return p;
}
int InsertNewQuestion(STreeCH &root, STreeCH &question)
{
    int check = ReadID(question->info.ID);//lay ID trong file
    if (Insert(root, question) == 0)
        return 0;
    if (check == 2) // cân bằng lại cây
        root = Balance(root);
    if (check == 1)
        root = OriginRoot(root); // phục hồi lại cây ban đầu để in lần sau không cần cân băng nữa
    return 1;
}
void SubDelete(STreeCH &root)
{
    if (root->left != NULL)
        SubDelete(root->left);
    else
    {
        rp->info = root->info;
        rp = root;
        root = rp->right;
    }
}
int Delete(STreeCH &root, int ID)
{
    if (root == NULL)
        return 0;
    else
    {
        if (root->info.ID > ID)
            return Delete(root->left, ID);
        else if (root->info.ID < ID)
            return Delete(root->right, ID);
        else
        {
            rp = root;
            if (root->right == NULL)//Nút phải NULL nên nối nút trái
                root = rp->left;
            else if (root->left == NULL)//nút trái NULL nên nối nút phải
                root = rp->right;
            else// hai nút ko NULL nên tìm nút trái cùng của cây bên phải
                SubDelete(rp->right);
            delete rp;
            return 1;
        }
    }
}
int DeleteQuestion(STreeCH &root, STreeCH &Question)
{
    int number, ID = Question->info.ID;
    if (root == NULL)
        return 0;
    Delete(root, Question->info.ID);
    root = Balance(root);
    //cất ID vừa xóa vào file old ID
    fstream FileOldKey("Data/FileOldID.bin", ios::binary | ios::in | ios::out);
    FileOldKey.read(reinterpret_cast<char *>(&number), sizeof(int));
    number++;
    FileOldKey.seekp(number * 4, ios::beg);
    FileOldKey.write(reinterpret_cast<char *>(&ID), sizeof(int));
    FileOldKey.seekp(ios::beg);
    FileOldKey.write(reinterpret_cast<char *>(&number), sizeof(int));
    FileOldKey.close();
}
int SoNode(STreeCH root)
{
    if (root == NULL)
        return 0;
    return 1 + SoNode(root->left) + SoNode(root->right);
}
void DeleteRoot(STreeCH &root)
{
    if (root == NULL)
        return;
    Queue<STreeCH> q;
    STreeCH temp;
    q.Push(root);
    while (!q.empty())
    {
        temp = q.pop();
        if (temp->left != NULL)
            q.Push(temp->left);
        if (temp->right != NULL)
            q.Push(temp->right);
        delete temp;
    }
    q.Destroy();
}
//--------LAY CAU HOI--------
void InTraversal(Array<STreeCH> &AllQuestions, STreeCH root, char maMH[])
{
    STreeCH temp=root;
    Stack<STreeCH>stack;
    do 
    {
        while(temp!=NULL)
        {
            stack.Push(temp);
            temp=temp->left;
        }
        if(!stack.Empty())
        {
            temp=stack.Pop();
            if(strcmp(temp->info.maMonHoc,maMH)==0)AllQuestions.push(temp);
            temp=temp->right;
        }else break;
    }while(1);
}

STreeCH *GetQuestion(STreeCH &root, char maMH[], int number_question, int tong_so_cau_hoi)
{
    Array<STreeCH>AllQuestions(tong_so_cau_hoi);
    STreeCH *Questions = new STreeCH[number_question];
    InTraversal(AllQuestions,root,maMH);
    srand(time(0));
    for (int i = 0,index; i < number_question; i++)
    {
        index = rand() % (tong_so_cau_hoi - i) + i;// random từ i đến number_question-1
        swap(AllQuestions[i], AllQuestions[index]);
        Questions[i] = AllQuestions[i];
    }
    AllQuestions.destroy(); // giai phong vung nho chua cac con tro
    return Questions;
}
int DemSoCauHoi(STreeCH root, char maMH[])
{
    if (root != NULL)
    {
        if (strcmp(root->info.maMonHoc, maMH) == 0)
        {
            return 1 + DemSoCauHoi(root->left, maMH) + DemSoCauHoi(root->right, maMH);
        }
        else
            return DemSoCauHoi(root->left, maMH) + DemSoCauHoi(root->right, maMH);
    }
    else
        return 0;
}
void Sort(Array<STreeCH> &Arr, int first, int last)
{
    int mid, i, j;
    STreeCH temp;
    mid = (first + last) / 2, i = first, j = last;
    do
    {
        while (Arr[i]->info.ID < Arr[mid]->info.ID)
            i++;
        while (Arr[j]->info.ID > Arr[mid]->info.ID)
            j--;
        if (i <= j)
        {
            temp = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);
    if (i < last)
        Sort(Arr, i, last);
    if (j > first)
        Sort(Arr, first, j);
}
//---------------------------DiemThi--------------------------//
void KhoiTao_PtrDT(PtrDT &first)
{
    first = NULL;
}
PtrDT create_Node_DT(DiemThi info)
{
    PtrDT p = new nodeDiemThi;
    p->info = info;
    p->next = NULL;
    return p;
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
bool delete_List_DT(PtrDT &first)
{
    while (!is_Empty_DT(first))
        if (!delete_First_DT(first))
            return 0;
    return 1;
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
bool is_Existed_MSSV_SV(ListLH dslh, string MSSV)
{
    if (is_Empty_LH(dslh))
        return false;
    for (int i = 0; i < dslh.n; i++)
    {
        PtrSV currentSV = dslh.lh[i]->danhSachSinhVien;
        while (currentSV != NULL)
        {
            if (strcmp(currentSV->info.MSSV, MSSV.c_str()) == 0)
                return true;
            currentSV = currentSV->next;
        }
    }
    return false;
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
bool delete_List_SV(PtrSV &first)
{
    while (!is_Empty_SV(first))
        if (!delete_First_SV(first))
            return 0;
    return 1;
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
bool is_Existed_MaLop(ListLH ListLH, const char *maLop)
{
    for (int i = 0; i < ListLH.n; i++)
    {
        if (strcmp(ListLH.lh[i]->maLop, maLop) == 0)
            return true;
    }
    return false;
}
int ThemLop(ListLH &ListLH, LopHoc info)
{
    if (is_Full_LH(ListLH))
        return 0;
    if (is_Existed_MaLop(ListLH, info.maLop))
        return -1;
    // bat dau them lop hoc
    ListLH.lh[ListLH.n] = new LopHoc; // Khoi tao vung nho cho con tro
    *ListLH.lh[ListLH.n] = info;      // Them mon hoc vao vung nho cua con tro, sau khi them vao thi tang so luong phan tu cua danh sach len 1
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

    LopHoc *P = ListLH.lh[pos];
    for (int i = pos; i < ListLH.n - 1; i++)
        ListLH.lh[i] = ListLH.lh[i + 1];

    delete_List_SV(P->danhSachSinhVien);
    delete P;

    ListLH.n--;
    return 1;
}
void Delete_DSLH(ListLH &dslh)
{
    for (int i = dslh.n - 1; i >= 0; i--)
    {
        XoaLop(dslh, i);
    }
}
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
