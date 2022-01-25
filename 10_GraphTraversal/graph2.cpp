#include<bits/stdc++.h>

using namespace std;

int random(int mn, int mx){
    // random between mn and mx both included
    int size=mx-mn+1;
    return rand()%size+mn;
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

struct Node{
    int data;
    Node *next;
    Node *prev;

    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class container{
    Node *root;
    Node *tail;
    void delete_front(){
        if(root==tail){
            root=NULL;
            return;
        }
        Node *temp=root;
        root=root->next;
        root->prev=NULL;
        delete(temp);
    }
    void delete_back(){
        if(root==tail){
            root=NULL;
            return;
        }
        Node *temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete(temp);
    }
    public:
        container(){
            root=NULL;
            tail=root;
        }
        void insert(int val){
            if(root==NULL){
                root=new Node(val);
                tail=root;
                //cout<<1<<"\n";
                return;
            }
            tail->next=new Node(val);
            tail->next->prev=tail;
            tail=tail->next;
        }
        int head(string type){
            if(type=="BFS")return root->data;
            else if(type=="DFS")return tail->data;
        }
        void pop(string type){
            if(type=="BFS")this->delete_front();
            else if(type=="DFS")this->delete_back();
        }
        bool isempty(){
            return root==NULL;
        }
};
vector<vector<int> > cycles;
void oddcycle(int u, int v, string type, int parent[]){
    vector<int> cycle;
    if(type=="BFS"){
        return;
    }
    else if(type=="DFS"){
        //cout<<"cycle\n";
        while(u!=v){
            cycle.push_back(v);
            //cout<<v<<" ";
            if(parent[v]==-1){
                cout<<"out of index\n";
            }
            v=parent[v];
        }
        cycle.push_back(u);
        //cout<<u<<"\n";
        cycles.push_back(cycle);
    }
}

void traverse(string type, vector<int> adj[], int N, int s){
    container *c=new container();
    int d[N+1];
    int parent[N+1];
    vector<int> backedge[N+1];
    for(int i=0; i<=N; i++){
        d[i]=-1;
        parent[i]=-1;
    }
    d[s]=0;
    c->insert(s);
    parent[s]=0;
    cout<<s<<"("<<0<<")"<<"->";
    while(!c->isempty()){
        int u=c->head(type);
        bool leaf=true;
        int v;
        for(int i=0; i<adj[u].size(); i++){
            v=adj[u][i];
            if(d[v]==-1){
                d[v]=d[u]+1;
                parent[v]=u;
                //cout<<u<<" "<<v<<"\n";
                c->insert(adj[u][i]);
                //cout<<1<<"\n";
                cout<<adj[u][i]<<"("<<d[adj[u][i]]<<")"<<"->";
                leaf=false;
                break;
            }
            if((d[v]-d[u])%2==0)backedge[u].push_back(v);
        }
        if(!leaf)continue;
        c->pop(type);
    }
    cout<<"end\n";
    for(int i=1; i<=N; i++){
        for(int j=0; j<backedge[i].size(); j++){
            //cout<<i<<" "<<backedge[i][j]<<"\n";
            if(d[i]<d[backedge[i][j]])oddcycle(i,backedge[i][j],type,parent);
        }
    }
}