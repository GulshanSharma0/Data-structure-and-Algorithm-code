
#include<bits/stdc++.h>
using namespace std;
class AVLTree{
    public:
    int data;
    AVLTree *left;
    AVLTree *right;
    int hight;
};
int hight(AVLTree* root){
    if(root==nullptr){
        return 0;
    }
    return root->hight;
}
AVLTree* newnode(int data){
    AVLTree* root=new AVLTree();
    root->data=data;
    root->left=nullptr;
    root->right=nullptr;
    root->hight=1;
    return root;
}
int getBalance(AVLTree* root){
    if(root==nullptr){
        return 0;
    }
    return (hight(root->left)-hight(root->right));
}
AVLTree* rightRotate(AVLTree* y){
    AVLTree* x=y->left;
    AVLTree* temp=x->right;
    x->right=y;
    y->left=temp;
    y->hight=max(hight(y->left),hight(y->right))+1;
    x->hight=max(hight(x->left),hight(x->right))+1;
    return x;
}
AVLTree* leftRotate(AVLTree* root){
    AVLTree* y=root->right;
    AVLTree* temp=y->left;

    y->left=root;
    root->right=temp;
    root->hight=1+max(hight(root->left),hight(root->right));
    y->hight=1+max(hight(y->left),hight(y->right));
    return y;

}
AVLTree* insert(AVLTree* root,int data){
    if(root==nullptr){
        return(newnode(data));
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>root->data){
        root->right=insert(root->right,data);
    }
    else{
        return root;
    }
    root->hight=1+max(hight(root->left),hight(root->right));
    int balance=getBalance(root);


    if(balance>1 && data<root->left->data){
        return rightRotate(root);
    }
    if(balance<-1 && data>root->right->data){
        return leftRotate(root);
    }
    if(balance>1 && data>root->left->data){
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1&& data<root->right->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
    
}
void printpreorder(AVLTree* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}
int main(){
   AVLTree* root=nullptr;
   root=insert(root,10);
   root=insert(root,20);
   root=insert(root,30);
   root=insert(root,40);
   root=insert(root,50);
   root=insert(root,25);
   printpreorder(root);
   return 0;
}
