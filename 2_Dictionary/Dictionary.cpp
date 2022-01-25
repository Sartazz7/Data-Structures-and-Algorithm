#include "Dictionary.h"
#include<bits/stdc++.h>

using namespace std;

bool compare(char *s1, char *s2){
    for(int i=0; s1[i]!=0; i++){
        if(s1[i]!=s2[i])return false;
    }
    for(int i=0; s2[i]!=0; i++){
        if(s1[i]!=s2[i])return false;
    }
    return true;
}


Dictionary::Dictionary(){
    N=ARRAY_SIZE;
    A = new Entry [N];
    for(int i=0; i<N; i++){
        A[i].key=NULL;
        A[i].tombstone=false;
        A[i].freq=0;
    }
}

int Dictionary::hashValue(char *key){
    double a=(sqrt(5.0)-1)/2;
    int x=41;
    double poly=0;
    for(int i=0; key[i]!='\0'; i++){
        poly = x*poly+key[i]*a;
        poly = poly - int(poly);
    }

    return int(N*poly);
}

int Dictionary::findFreeIndex(char *key){
    int hash = hashValue(key);
    for(int i=0; i<N; i++){
        if(A[(i+hash)%N].key==NULL)return (i+hash)%N;
    }
    return -1;
}

struct Entry* Dictionary::get(char *key){
    int hash=hashValue(key);
    cout<<key<<"'s hash value : "<<hash<<"\n";
    for(int i=0; i<N; i++){
        if(A[(i+hash)%N].freq==0 && A[(i+hash)%N].tombstone==false)return NULL;
        else if(compare(A[(i+hash)%N].key,key))return &A[(i+hash)%N];
    }
    return NULL;
}

bool Dictionary::put(struct Entry e){
    struct Entry *present = this->get(e.key);
    if(present!=NULL){
        present->freq++;
        return true;
    }
    int i=findFreeIndex(e.key);
    if(i==-1)return false;
    A[i].key=e.key;
    A[i].tombstone=false;
    A[i].freq=1;
    return true;
}

bool Dictionary::remove(char *key){
    struct Entry *e = get(key);
    if(e==NULL)return false;
    e->key=NULL;
    e->tombstone=true;
    e->freq=0;
    return true;
}