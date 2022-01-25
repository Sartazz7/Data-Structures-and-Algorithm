#include"packets.cpp"

int main(){
    int N,T;
    cin>>N>>T;

    Heap *H = new Heap(T);
    srand(time(0));
    for(int i=0; i<N; i++){
        int r = random(0,T*1.0/100);
        H->insert(r,1);
        cout<<r<<"\n";
    }
    H->insert(T,-1);
    int e;
    do{
        e = H->delete_min();
    }
    while(e!=-1);
    cout<<"DONE\n";
}