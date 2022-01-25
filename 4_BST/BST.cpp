#include<bits/stdc++.h>
#include"BST.h"
#include<time.h>
#include<fstream>

using namespace std;

void height(Node *root){
    if(root==NULL)return;
    if(root->left==NULL && root->right==NULL)root->h=0;
    else if(root->left==NULL)root->h=root->right->h+1;
    else if(root->right==NULL)root->h=root->left->h+1;
    else root->h = max(root->left->h,root->right->h)+1;
    height(root->parent);
}

Node::Node(){
    data=NULL;
    left=NULL;
    right=NULL;
    parent=NULL;
    h=0;
}
Node::Node(char *s){
    data=s;
    left=NULL;
    right=NULL;
    parent=NULL;
    h=0;
}

BST::BST(){
    root=NULL;
}

void BST::traverse(TraversalType_e tt, Node *root1){
    if(root1==NULL)return;
    
    left(tt,root1);
    traverse(tt, root1->left);
    below(tt,root1);
    traverse(tt,root1->right);
    right(tt,root1);
}

void BST::external(TraversalType_e tt, Node *root1){
    cout<<root1->data<<" "<<root1->h<<"\n";
}

void BST::left(TraversalType_e tt, Node *root1){
    if(tt==PRE_ORDER)cout<<root1->data<<" "<<root1->h<<"\n";
}

void BST::right(TraversalType_e tt, Node *root1){
    if(tt==POST_ORDER)cout<<root1->data<<" "<<root1->h<<"\n";
}

void BST::below(TraversalType_e tt, Node *root1){
    if(tt==IN_ORDER)cout<<root1->data<<" "<<root1->h<<"\n";
}

struct Node *BST::min(){
    if(root==NULL)return NULL;
    Node *temp = root;
    while(temp->left!=NULL)temp=temp->left;
    return temp;
}

struct Node *BST::max(){
    if(root==NULL)return NULL;
    Node *temp = root;
    while(temp->right!=NULL)temp=temp->right;
    return temp;
}

struct Node *BST::search(char *s){
    Node *temp=root;
    while(temp!=NULL){
        if(strcmp(s,temp->data)==0)return temp;
        else if(strcmp(s,temp->data)>0)temp=temp->right;
        else temp=temp->left;
    }
    return NULL;
}

bool BST::insert(struct Node n){
    Node *temp=root;
    if(root==NULL){
        //cout<<n.data<<"\n";
        root = new Node(n.data);
        //cout<<root->data<<"\n";
        height(root);
        return true;
    }
    while(temp!=NULL){
        //cout<<n.data<<temp->data<<"\n";
        if(strcmp(n.data,temp->data)==0)return false;
        if(strcmp(n.data,temp->data)>0){
            if(temp->right==NULL){
                Node *node = new Node(n.data);
                temp->right=node;
                node->parent=temp;
                //cout<<node->data<<"\n";
                height(node);
                break;
            }
            temp=temp->right;
        }
        else {
            if(temp->left==NULL){
                Node *node = new Node(n.data);
                temp->left=node;
                node->parent=temp;
                //cout<<node->data<<"\n";
                height(node);
                break;
            }
            temp=temp->left;
        }
    }
    return true;
}

bool BST::remove(char *s){
    Node *n = search(s);
    if(n==NULL)return false;
    if(n->left==NULL && n->right==NULL){
        //cout<<0<<"\n";
        if(n->parent!=NULL){
            if(n->parent->right!=NULL && n->parent->right==n)n->parent->right=NULL;
            else n->parent->left=NULL;
            height(n->parent);
        }
        else root=NULL;
        delete n;
    }
    else if(n->left==NULL){
        n->right->parent=n->parent;
        //cout<<1<<"\n";
        if(n->parent!=NULL){
            if(n->parent->right!=NULL && n->parent->right==n)n->parent->right=n->right;
            else n->parent->left=n->right;
            height(n->parent);
        }
        else root=n->right;
        delete n;
    }
    else if(n->right==NULL){
        //cout<<2<<"\n";
        n->left->parent=n->parent;
        if(n->parent!=NULL){
            if(n->parent->right!=NULL && n->parent->right==n)n->parent->right=n->left;
            else n->parent->left=n->left;
            height(n->parent);
        }
        else root=n->left;
        delete n;
    }
    else {
        Node *temp = successor(n);
        if(temp->parent==n){
            temp->parent=n->parent;
            temp->left=n->left;
            n->left->parent=temp;
            if(n->parent!=NULL){
                if(n->parent->right!=NULL && n->parent->right==n)n->parent->right=temp;
                else n->parent->left=temp;
            }
            height(temp);
        }
        else {
            temp->parent->left=NULL;
            height(temp->parent);
            temp->parent=n->parent;
            if(n->parent!=NULL){
                if(n->parent->right!=NULL && n->parent->right==n)n->parent->right=temp;
                else n->parent->left=temp;
            }
            temp->right=n->right;
            n->right->parent=temp;
            temp->left=n->left;
            n->left->parent=temp;
            temp->h=n->h;
        }
        if(temp->parent==NULL)root=temp;
        delete n;
    }
    //height(root);
    return true;
}

struct Node *BST::successor(struct Node *n){
    if(n->right==NULL){
        Node *temp=n;
        Node *temp2=n->parent;
        while(temp2!=NULL){
            if(temp2->left==temp)return temp2;
            temp=temp->parent;
            temp2=temp2->parent;
        }
        return NULL;
    }
    Node *temp=n->right;
    while(temp->left!=NULL)temp=temp->left;
    return temp;
}

struct Node *BST::predecessor(struct Node *n){
    if(n->left==NULL){
        Node *temp=n;
        Node *temp2=n->parent;
        while(temp2!=NULL){
            if(temp2->right==temp)return temp2;
            temp2=temp2->parent;
            temp=temp->parent;
        }
        return NULL;
    }
    Node *temp=n->left;
    while(temp->right!=NULL)temp=temp->right;
    return temp;
}

struct Node *BST::get_tree(){
    return root;
}

#define LENGTH 32
void randomString(char* input)
{
    char alphabet[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };
 
    for (int i = 0; i < LENGTH; i++)
        input[i] = alphabet[rand() % 26];
    input[LENGTH] = 0;
    return;
}

int main(){
    /*
    
    BST *T = new BST();
    int N;
    cin>>N;
    char str[N][32];
    for(int i=0; i<N; i++){
        cin>>str[i];
        Node n;
        n.data=str[i];
        T->insert(n);
    }
    T->traverse(IN_ORDER,T->get_tree());
    cout<<T->min()->data<<" "<<T->max()->data<<"\n\n";
    for(int i=0; i<N; i++){
        T->remove(str[i]);
        cout<<"\n";
        T->traverse(IN_ORDER,T->get_tree());
    }
    cout<<"all removed\n";
    */
    
    
    BST *T = new BST();
    int N=100000;
    char **str = (char **)malloc(N * sizeof(char *));
    for (int i=0; i<N; i++)str[i] = (char *)malloc(32 * sizeof(char));

    srand(time(0));
    for(int i=0; i<N; i++){
        for(int j=0; j<5; j++){
            str[i][j]=(rand()%26)+97;
        }
        str[i][5]='\0';
    }

    double Time[N];
    clock_t t;

    t=clock();
    for(int i=0; i<N; i++){
        Node n;
        n.data = str[i];
        T->insert(n);
        Time[i] = (clock()-t)*1.0/CLOCKS_PER_SEC;
    }

    ofstream time_output;
    time_output.open("time.txt");

    for(int i=0; i<N; i++){
        if(i%25==0)time_output<<"\n";
        time_output<<Time[i]<<fixed<<setprecision(5)<<",";
    }

    /*
    T->traverse(IN_ORDER,T->get_tree());
    for(int i=0; i<N; i++){
        T->remove(str[i]);
        cout<<"Removed :"<<str[i]<<"\n";
    }
    */
    cout<<"DONE\n";
    
}