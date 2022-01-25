#include<bits/stdc++.h>

using namespace std;

#define MAXN 1048576   // 2^20=1048576

int swaps;

class Heap{
    int N;
    int a[MAXN];

    int parent(int i){
        return (i-1)/2;
    }

    int left(int i){
        return 2*i+1;
    }

    int right(int i){
        return 2*i+2;
    }

    public:
    Heap(){
        N = 0;
    }

    void insert(int v){
        a[N]=v;
        N++;
        int i=N-1;
        while(i>0 && a[i]<a[parent(i)]){
            swap(a[i],a[parent(i)]);
            swaps++;
            i=parent(i);
        }
    }

    int min(){
        if(N==0)return -1;
        return a[0];
    }

    void heapify(int i){
        if(left(i)<N){
            if(right(i)<N){
                if(a[i]<=a[left(i)] && a[i]<=a[right(i)])return;
                if(a[left(i)]<a[right(i)]){
                    swap(a[i],a[left(i)]);
                    swaps++;
                    return heapify(left(i));
                }
                else {
                    swap(a[i],a[right(i)]);
                    swaps++;
                    return heapify(right(i));
                }
            }
            else {
                if(a[i]>a[left(i)]){
                    swap(a[i],a[left(i)]);
                    swaps++;
                }
                return;
            }
        }
    }

    void delete_min(){
        swap(a[0],a[N-1]);
        swaps++;
        N--;
        heapify(0);
    }

    void print(){
        for(int i=0; i<N; i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }

};