#include"graph.cpp"

int main(){
    int N;
    cin>>N;

    DirectedGraph *G = new DirectedGraph(N,3*N);
    G->RandomGraph();
    
    cout<<"The Adjacency List of the given Directed Graph is :\n";
    G->printAdjList();
    cout<<"\n";

    pair<int,int> not_connected;
    not_connected = G->DFSnotVisited();

    if(not_connected.first!=-1){
        cout<<"The is no path from "<<not_connected.first<<" to "<<not_connected.second<<"\n";
    }
    else {
        DirectedGraph *G_rev = G->ReverseEdge();
        not_connected = G_rev->DFSnotVisited();

        if(not_connected.first==-1)cout<<"The Graph is fully connected.\n";
        else cout<<"The is no path from "<<not_connected.second<<" to "<<not_connected.first<<"\n";
    }

    return 0;
}