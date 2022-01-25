#include<bits/stdc++.h>

using namespace std;

int random(int mn, int mx){
    // random between mn and mx both included
    int size=mx-mn+1;
    return rand()%size+mn;
}

class container{
    public:
        virtual int push(int v);
        virtual int pop();
        virtual bool empty();
};

class Stack : public container{
    stack<int> s;
    public:
        int push(int v){
            s.push(v);
        }
        int pop(int v){
            int t=s.top();
            s.pop();
            return t;
        }
        bool empty(){
            return s.empty();
        }
};

class Queue : public container{
    queue<int> q;
    public:
        int push(int v){
            q.push(v);
        }
        int pop(int v){
            int t=q.front();
            q.pop();
            return t;
        }
        bool empty(){
            return q.empty();
        }
};

void traverse(string type, vector<int> adj[], int N, int s){
    container *c;
    if(type=="BFS")c=new Queue;
    else if(type=="DFS")c=new Stack;

    int color[N+1];  // 0=while , 1=grey, 2=black
    for(int i=0; i<=N; i++){
        color[i]=0;
    }

    c->push(s);
    while(!c->empty()){
        int u=c->pop();
        for(auto v:adj[u]){
            if(color[v]==0){
                color[v]=1;
                c->push(v);
            }
        }
        color[u]=2;
        cout<<u<<"->";
    }
    cout<<"\n";
}

void print(vector<int> adj[], int N){
    cout<<"The adjacency list of the graph is :\n";
    for(int i=1; i<=N; i++){
        cout<< i<<" : ";
        for(auto u:adj[i]){
            cout<<u<<" ";
        }
        cout<<"\n";
    }
}