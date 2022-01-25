#include<bits/stdc++.h>

using namespace std;

int random(int mn, int mx){
    int s=mx-mn+1;
    return (rand()%s + mn);
}

class DirectedGraph {
    vector<int> *v;
    int n;
    int m;
    void DFS(bool vis[], int k);
    public:

    DirectedGraph(int N, int M);
    void RandomGraph();
    pair<int,int> DFSnotVisited();
    DirectedGraph *ReverseEdge();
    void printAdjList();
};

DirectedGraph::DirectedGraph(int N, int M){
    n=N;
    m=M;
    v = new vector<int> [n+1];
}

void DirectedGraph::DFS(bool vis[], int k){
    vis[k]=true;
    for(int i=0; i<v[k].size(); i++){
        if(!vis[v[k][i]])DFS(vis,v[k][i]);
    }
}

void DirectedGraph::RandomGraph(){
    int i=0;
    while(i<m){
        int a=random(1,n);
        int b=random(1,n);
        if(a==b)continue;
        bool exist=false;
        for(int j=0; j<v[a].size(); j++){
            if(v[a][j]==b){
                exist=true;
                break;
            }
        }
        if(exist)continue;
        v[a].push_back(b);
        i++;
    }
}

pair<int,int> DirectedGraph::DFSnotVisited(){
    int u=random(1,n);
    bool vis[n+1];
    for(int i=0; i<=n; i++){
        vis[i]=false;
    }
    DFS(vis,u);
    for(int i=1; i<=n; i++){
        if(vis[i]==false)return make_pair(u,i);
    }
    return make_pair(-1,-1);
}

DirectedGraph *DirectedGraph::ReverseEdge(){
    DirectedGraph *G = new DirectedGraph(n,m);

    for(int i=1; i<n; i++){
        for(int j=0; j<v[i].size(); j++){
            G->v[this->v[i][j]].push_back(i);
        }
    }
    return G;
}

void DirectedGraph::printAdjList(){
    for(int i=1; i<=n; i++){
        cout<<i<<" : ";
        for(int j=0; j<v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}