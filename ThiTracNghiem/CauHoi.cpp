#include"CauHoi.h"
int CreateID(int Number[],int &i){
    int temp,index;
    if(i==299)return 0;
    srand(time(0));
    index=rand()%(299-i+1)+i; 
    temp=Number[index];
    Number[index]=Number[i];
    Number[i]=temp;
    i++;
    return temp;  
}
void InsertQuestion(STreeCH &root,STreeCH question){
    STreeCH run=root;
    if(root==NULL){
        root=question;
        return;
    }
    while(run!=NULL)
    {
        if(run->info.ID<question->info.ID)
        {
            if(run->right==NULL){
                run->right=question;
                return;
            }
            run=run->right;
        }
        else 
        {
            if(run->left==NULL)
            {
                run->left=question;
                return;
            }
            run=run->left;
        }
    }
}
void Store(STreeCH root,vector<STreeCH>&nodes){
    if(root!=NULL){
        Store(root->left,nodes);
        nodes.push_back(root);
        Store(root->right,nodes);
    }
}
STreeCH tree_balance(vector<STreeCH>&nodes,int max,int min){
    if(max<min)return NULL;
    int mid=(max+min)/2;
    STreeCH root=nodes[mid];
    root->left=tree_balance(nodes,mid-1,min);
    root->right=tree_balance(nodes,max,mid+1);
    return root;
}
STreeCH balance(STreeCH root){
    vector<STreeCH>nodes;
    Store(root,nodes);
    return tree_balance(nodes,nodes.size()-1,0); 
}
void PreTraversal(CauHoi save[],STreeCH root,int &i){
    if(root!=NULL){
        save[i++]=root->info;
        PreTraversal(save,root->left,i);
        PreTraversal(save,root->right,i);
    }
}
CauHoi* GetQuestion(STreeCH &root,int number_question){
    if(root==NULL)return NULL;
    int index=0,count=0;
    STreeCH run=root;
    CauHoi* temp=new CauHoi[number_question];
    CauHoi* save=new CauHoi[300],swap;
    PreTraversal(save,root,count);
    srand(time(0));
    while(index!=number_question){
        swap=temp[rand()%(number_question-index)+index];
        temp[rand()%(number_question-index)+index]=temp[index];
        temp[index]=swap;
        save[index]=temp[index];
        index++;
    }
    return temp;
}
// void Read(STreeCH &root){
//     ifstream FILE("DanhSachCauHoi.txt");
//     string a;
//     while(!FILE.eof()){
//         STreeCH question=new nodeCauHoi;
//        // question->info.ID=CreateID(A,index);
//         strcpy(question->info.maMonHoc,"*BAS1224");
//       //  getline(FILE,a,'|');
//         if(a=="")break;
//         else strcpy(question->info.question,a.data());
//         FILE.getline(question->info.ans1,101,'|');
//         FILE.getline(question->info.ans2,101,'|');
//         FILE.getline(question->info.ans3,101,'|');
//         FILE.getline(question->info.ans4,101,'|');
//         FILE>>question->info.answer;
//         FILE.ignore();
//         FILE.ignore();//XUONG DONG
//         InsertQuestion(root,question);
//     }
// }