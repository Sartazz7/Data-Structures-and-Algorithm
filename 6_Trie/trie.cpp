#include<bits/stdc++.h>

using namespace std;

struct Node{
    int index,left,right;
    bool dollar;
    Node *next[26];
    Node *parent;
    Node(){
        index=-1;
        left=-1;
        right=-1;
        dollar=false;
        for(int i=0; i<26; i++){
            next[i]=NULL;
        }
        parent=NULL;
    }
    Node(int i, int l, int r, bool d){
        index=i;
        left=l;
        right=r;
        dollar=d;
        for(int i=0; i<26; i++){
            next[i]=NULL;
        }
    }
};

int com(string s1, int l1, int r1, string s2, int l2, int r2){
    int i=0;
    while(true){
        if(l1+i>r1 || l2+i>r2 || s1[l1+i]!=s2[l2+i])return i;
        i++;
    }
}

class Trie {
    vector<string> vs;
    Node *root;

    public:

    Trie(){
        root = new Node();
    }

    void insert(string s);

    string search(string s);
};

void Trie::insert(string s){
    vs.push_back(s);

    Node *it=root->next[s[0]-'a'], *pit=root;
    int i=0;
    while(i<s.size()){
        if(it==NULL){
            Node *n = new Node(vs.size()-1,i,s.size()-1,true);
            n->parent=pit;
            pit->next[s[i]-'a']=n;
            return;
        }
        int p=com(vs[it->index], it->left, it->right, s, i, s.size()-1);
        if(it->left + p > it->right){
            i+=p; 
            if(i==s.size()){
                it->dollar=true;
                return;
            }
            else {
                pit=it;
                it=it->next[s[i]-'a'];
            }
        }
        else {
            i+=p;
            Node *n = new Node(it->index,it->left,it->left+p-1,false);
            n->parent=pit;
            pit->next[vs[n->index][n->left]-'a']=n;
            it->left+=p;
            it->parent=n;
            n->next[vs[it->index][it->left]-'a']=it;
            if(i==s.size()){
                n->dollar=true;
                return;
            }
            n->next[s[i]-'a']= new Node(vs.size()-1,i,s.size()-1,true);
            return;
        }
    }
}

string Trie::search(string s){
    int i=0;
    Node *it=root->next[s[i]-'a'];
    while(i<s.size()){
        if(it==NULL)return s.substr(0,i);
        int p=com(vs[it->index], it->left,it->right,s,i,s.size()-1);
        i+=p;
        if(it->left + p > it->right){
            if(i==s.size()){
                if(it->dollar)return s.substr(0,i);
                return s.substr(0,i);
            }
            else {
                it=it->next[s[i]-'a'];
            }
        }
        else {
            return s.substr(0,i);
        }
    }
}