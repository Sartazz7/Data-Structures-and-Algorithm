#include"graph2.cpp"

int main(){
    int N;
    cin>>N;
    vector<int> adj[N+1];
    //srand(time(0));
    int i=0;
    while(i<2*N){
        int a=random(1,N);
        int b=random(1,N);
        bool exist=false;
        for(int j=0; j<adj[a].size(); j++){
            if(adj[a][j]==b){
                exist=true;
                break;
            }
        }
        if(exist || a==b)continue;
        adj[a].push_back(b);
        adj[b].push_back(a);
        i++;
    }
    print(adj,N);
    traverse("BFS",adj,N,1);
    traverse("DFS",adj,N,1);

    for(int i=0; i<cycles.size(); i++){
        cout<<"Vertices forming odd cycles : ";
        for(int j=0; j<cycles[i].size(); j++){
            cout<<cycles[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}