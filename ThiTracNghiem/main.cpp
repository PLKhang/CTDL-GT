#include"XuLyGiaoDien.h"
#include "docGhiFile.h"
void In(STreeCH root){
	if(root!=NULL){
		In(root->left);
		In(root->right);		
		cout<<root->info.maMonHoc<<root->info.question<<endl;
		delete root;
		if(root==NULL)cout<<"duoc"<<endl;
	}
}
int main(){
//	STreeCH root=NULL;
//	doc_danhSachCauHoi(root);
//	In(root);
//	cout << "end\n";
	int *a = NULL;
	cout << a;
	return 0;
}
