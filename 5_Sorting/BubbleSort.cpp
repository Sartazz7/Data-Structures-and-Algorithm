#include"Sort.cpp"

void out(int pt, ll sw[], ll cp[], double t[]){
    ofstream output;
    output.open("output.txt", std::ios::app);
    for(int i=0; i<pt; i++){
        output<<sw[i]<<",";
    }
    output<<"\n";
    for(int i=0; i<pt; i++){
        output<<cp[i]<<",";
    }
    output<<"\n";
    for(int i=0; i<pt; i++){
        output<<t[i]<<",";
    }
    output<<"\n";
    output.close();
}


int main(){
    
    int pt = 1000;
    double dmin = 0;
    double dmax = 1000;

    time_t st,en;
    ll sw[pt];
    ll cp[pt];
    double t[pt];
    for(int num=0; num<3; num++){
        for(int k=0; k<pt; k++){
            int N=(k+1);
            double a[N];
            input(a,N,num);
            swaps=0;
            comp=0;
            st=clock();
            BubbleSort(a,N);
            en=clock();
            sw[k]=swaps;
            cp[k]=comp;
            t[k]=(en-st)*1.0;
            //cout<<k+1<<" DONE\n";
        }
        out(pt,sw,cp,t);
        cout<<"Input "<<num+1<<" DONE\n";
    }
    cout<<"See Output\n";
    return 0;
}