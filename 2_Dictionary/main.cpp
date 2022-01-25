

#include<bits/stdc++.h>
#include "Dictionary.h"
#include "Dictionary.cpp"

using namespace std;


int main(){
    Dictionary D;
    int n;
    cin>>n;
    char word[n][32];
    for(int i = 0; i<n; i++){
        cin>>word[i];
        Entry temp;
        temp.key = word[i];
        D.put(temp);
    }

    vector<char*> distinct;
    for(int i=0; i<n; i++){
        bool found=false;
        for(int j=0; j<i && !found; j++){
            if(compare(word[i],word[j]))found=true;
        }
        if(!found)distinct.push_back(word[i]);
    }
    for(int i=0; i<distinct.size(); i++){
        struct Entry *e;
        e = D.get(distinct[i]);
        if(e==NULL)cout<<0<<"\n";
        else cout<<(distinct[i])<<"'s frequency : "<<e->freq<<"\n";
    }
}