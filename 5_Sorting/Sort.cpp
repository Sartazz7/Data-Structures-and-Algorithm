#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll swaps;
ll comp;

double randomd(double dmin, double dmax){
    double t = rand()*1.0/RAND_MAX;
    return dmin*t+dmax*(1-t);
}

int randomi(int imin, int imax){
    int r=imax-imin+1;
    return imin+rand()%r;
}

int partition(double a[], int l, int r){
    double piv=a[l];
    int i=l-1,j=r+1;
    while(true){
        do {
            j--;
            comp++;
        }
        while(a[j]>piv);
        do {
            i++;
            comp++;
        }
        while(a[i]<piv);
        if(i<j){
            comp++;
            swap(a[i],a[j]);
            swaps++;
        }
        else break;
    }
    comp++;
    return j;
}

void QuickSort(double a[], int st, int en){
    if(st<en){
        //cout<<clock()<<"\n";
        int mid = partition(a,st,en);
        QuickSort(a,st,mid);
        QuickSort(a,mid+1,en);
    }
    comp++;
}

int randomPartition(double a[], int l, int r){
    int p=randomi(l,r);
    swap(a[p],a[l]);
    swaps++;
    return partition(a,l,r);
}

void randomQuickSort(double a[], int st, int en){
    if(st<en){
        int mid = randomPartition(a,st,en);
        randomQuickSort(a,st,mid);
        randomQuickSort(a,mid+1,en);
    }
    comp++;
}

void BubbleSort(double a[], int n){
    for(int i=0; i<n-1; i++){
        comp++;
        for(int j=0; j<n-i-1; j++){
            comp++;
            if(a[j]>a[j+1]){
                comp++;
                swap(a[j],a[j+1]);
                swaps++;
            }
            else comp++;
        }
        comp++;
    }
    comp++;
}

void input(double a[], int N, int num){
    for(int i=0; i<N; i++){
        a[i]=randomd(0,1000);
    }
    if(num==1 || num==2){
        sort(a,a+N);
        for(int i=0; i<N/20; i++){
            int c=randomi(0,N-1);
            int b=randomi(0,N-1);
            swap(a[b],a[c]);
        }
    }
    if(num==2){
        for(int i=0; i<N/2-1; i++){
            swap(a[i],a[N-i-1]);
        }
    }
}
/*
int main(){
    int N=1000;
    double a[N];
    int num=0;
    input(a,N,num);
    clock_t st,en;
    st=clock();
    QuickSort(a,0,N-1);
    en=clock();
    for(int i=0; i<N; i++){
        cout<<a[i]<<"\n";
    }
    cout<<(en-st)*1.0/CLOCKS_PER_SEC;
}
*/