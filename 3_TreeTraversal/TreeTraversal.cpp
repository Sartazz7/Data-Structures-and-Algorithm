#include<iostream>
#include"TreeTraversal.h"

using namespace std;

int search(char *in_order, int N, char curr){
    for(int i=0; i<N; i++){
        if(in_order[i]==curr)return i;
    }
    return -1;
}

bool check(char *pre_order, char *in_order, int N){
    int c[256];
    for(int i=0; i<256; i++){
        c[i]=0;
    }
    for(int i=0; i<N; i++){
        c[pre_order[i]]++;
    }
    for(int i=0; i<N; i++){
        c[in_order[i]]--;
    }
    for(int i=0; i<256; i++){
        if(c[i]!=0)return false;
    }
    return true;
}

Node::Node(char val){
    data=val;
    left=NULL;
    right=NULL;
}

Tree::Tree(){
    root=NULL;
}

Node *Tree::deduce_tree(char *pre_order, char *in_order, int N){
    if(N==0)return NULL;
    Node *curr = new Node(pre_order[0]);
    if(N==1)return curr;
    int pos = search(in_order, N, curr->data);

    curr->left = deduce_tree(&pre_order[1],&in_order[0],pos);
    curr->right = deduce_tree(&pre_order[pos+1],&in_order[pos+1],N-pos-1);
    if(!check(pre_order,in_order,N)){
        root=NULL;
        return NULL;
    }
    return curr;
}

void Tree::traverse(TraversalType_e tt, Node *root1){
    if(root1==NULL)return;
    
    left(tt,root1);
    traverse(tt, root1->left);
    below(tt,root1);
    traverse(tt,root1->right);
    right(tt,root1);
}

Node *Tree::get_root(){
    return root;
}

void Tree::external(TraversalType_e tt, Node *root1){
    cout<<root1->data;
}

void Tree::left(TraversalType_e tt, Node *root1){
    if(tt==PRE_ORDER)cout<<root1->data;
}

void Tree::right(TraversalType_e tt, Node *root1){
    if(tt==POST_ORDER)cout<<root1->data;
}

void Tree::below(TraversalType_e tt, Node *root1){
    if(tt==IN_ORDER)cout<<root1->data;
}

int main(){
    Tree T;
    int N;
    char *pre_order;
    pre_order = new char [N];
    char *in_order;
    in_order = new char [N];

    cin>>N>>pre_order>>in_order;
    T = Tree(pre_order,in_order,N);
    T.traverse(POST_ORDER,T.get_root());
    cout<<"\n";

    return 0;
}
