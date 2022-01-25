#include<bits/stdc++.h>

using namespace std;

bool isedge(map<pair<int,int>, vector<pair<int,int> > > adj, int a, int b, int c, int d){
    pair<int,int> p=make_pair(a,b);
    int k=adj[p].size();
    for(int i=0; i<k; i++){
        if(adj[p][i].first==c && adj[p][i].second==d)return true;
    }
    return false;
}

int main(){
    int N,M;
    cin>>N>>M;
    
    // Graph of grid
    map<pair<int,int>, vector<pair<int,int> > > adj;

    // Horizontal walls
    cout<<"Horizontal walls : \n";
    for(int i=0; i<N; i++){
        for(int j=0; j<M-1; j++){
            int k;
            cin>>k;
            if(k==1){
                adj[make_pair(i,j)].push_back(make_pair(i,j+1));
                adj[make_pair(i,j+1)].push_back(make_pair(i,j));
            }
        }
    }

    // Vertical walls
    cout<<"Vertical walls : \n";
    for(int i=0; i<N-1; i++){
        for(int j=0; j<M; j++){
            int k;
            cin>>k;
            if(k==1){
                adj[make_pair(i,j)].push_back(make_pair(i+1,j));
                adj[make_pair(i+1,j)].push_back(make_pair(i,j));
            }
        }
    }

    // Graph of cells
    map<pair<int,int>, vector<pair<int,int> > > cells;

    for(int i=0; i<N-1; i++){
        for(int j=0; j<M-1; j++){
            if(j!=M-2 && !isedge(adj,i,j+1,i+1,j+1)){
                cells[make_pair(i,j)].push_back(make_pair(i,j+1));
                cells[make_pair(i,j+1)].push_back(make_pair(i,j));
            }
            if(i!=N-2 && !isedge(adj,i+1,j,i+1,j+1)){
                cells[make_pair(i,j)].push_back(make_pair(i+1,j));
                cells[make_pair(i+1,j)].push_back(make_pair(i,j));
            }
        }
    }
    cout<<"Cells made\n";
    
    // Getting the parent using BFS
    pair<int,int> parent[N-1][M-1];
    for(int i=0; i<N-1; i++){
        for(int j=0; j<M-1; j++){
            parent[i][j]=make_pair(-1,-1);
        }
    }
    queue<pair<int,int> > q;
    q.push(make_pair(0,0));

    while(!q.empty()){
        pair<int,int> p=q.front();
        q.pop();
        int k=cells[p].size();
        for(int i=0; i<k; i++){
            if(parent[cells[p][i].first][cells[p][i].second].first==-1){
                parent[cells[p][i].first][cells[p][i].second]=p;
                q.push(cells[p][i]);
            }
        }
    }
    parent[0][0]=make_pair(-1,-1);
    cout<<"Assigned parent\n";
    
    // Getting the shortest path
    stack<pair<int,int> > ans;
    int i=N-2,j=M-2;
    do{
        ans.push(make_pair(i,j));
        int a=parent[i][j].first, b=parent[i][j].second;
        i=a;
        j=b;
    }   
    while(i!=-1 && j!=-1);

    // Printing ans
    while(!ans.empty()){
        cout<<"("<<ans.top().first<<","<<ans.top().second<<") ";
        ans.pop();
    }
    cout<<"\n";
}