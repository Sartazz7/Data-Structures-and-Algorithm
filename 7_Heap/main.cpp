#include"heap.cpp"
#include <sys/time.h>

int random(int n){
    return rand()%n;
}

int main(){
    /*
    int N;
    cin>>N;
    Heap *H;
    H = new Heap();

    for(int i=0; i<N; i++){
        int a;
        cin>>a;
        H->insert(a);
        cout<<a<<" inserted\n";
    }
    H->print();
    int a;
    while(true){
        cin>>a;
        if(a==0)break;
        else if(a==1){
            int b;
            cin>>b;
            H->insert(b);
            H->print();
        }
        else if(a==2){
            H->delete_min();
            H->print();
        }
        else if(a==3){
            cout<<H->min()<<"\n";
        }
    }
    */

    int minN = 1000;
    int maxN = 100000;

    // Variables to store the output
    double insert_T[maxN/10];
    double insert_S[maxN/10];
    double delete_T[maxN/10];
    double delete_S[maxN/10];

    cout<<fixed<<setprecision(9);
    for(int N=minN; N<maxN; N+=10){
        Heap *H;
        H=new Heap();
        clock_t start, end;
        
        // Build Heap with N elements
        swaps=0;
        for(int i=0; i<N; i++){
            H->insert(random(MAXN));
        }
        // Insert N/5 elements;
        swaps=0;
        start = clock();
        for(int i=0; i<N/5; i++){
            H->insert(random(MAXN));
        }
        end = clock();

        insert_T[N/10] = double(end - start)*5.0/N/double(CLOCKS_PER_SEC);
        insert_S[N/10] = swaps*5.0/N;

        // Delete_min N/5 elements;
        swaps=0;
        start=clock();
        for(int i=0; i<N/5; i++){
            H->delete_min();
        }
        end=clock();

        delete_T[N/10] = double(end - start)*5.0/N/double(CLOCKS_PER_SEC);
        delete_S[N/10] = swaps*5.0/N;

        // Checking
        if(N%1000==0)cout<<N<<" DONE\n";
        delete H;
    }

    // Taking output

    ofstream output;
    output.open("heap_data.csv");
    output<<fixed<<setprecision(9);
    for(int i=minN/10; i<maxN/10; i++){
        output<<i*10<<","<<insert_T[i]<<","<<insert_S[i]<<","<<delete_T[i]<<","<<delete_S[i]<<"\n";
    }
    output.close();
    return 0;
}