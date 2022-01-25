#include<bits/stdc++.h>

using namespace std;

#define MAXN 1048576   // 2^20=1048576

double random(int a, int b){
    return (b - a) * ( (double)rand() / (double)RAND_MAX ) + a;
}

int swaps;

class Heap{
    int N;
    double a[MAXN];
    int event[MAXN];
    priority_queue<pair<double,int> , vector<pair<double,int> >, greater<pair<double,int> > > packets;
    int T;

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
    Heap(int t){
        N = 0;
        T = t;
    }

    bool empty(){
        return N==0;
    }

    void insert(double v, int e){
        a[N]=v;
        event[N]=e;
        N++;
        int i=N-1;
        while(i>0 && a[i]<a[parent(i)]){
            swap(a[i],a[parent(i)]);
            swap(event[i],event[parent(i)]);
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
                    swap(event[i],event[left(i)]);
                    return heapify(left(i));
                }
                else {
                    swap(a[i],a[right(i)]);
                    swap(event[i],event[right(i)]);
                    return heapify(right(i));
                }
            }
            else {
                if(a[i]>a[left(i)]){
                    swap(a[i],a[left(i)]);
                    swap(event[i],event[left(i)]);
                }
                return;
            }
        }
    }

    int delete_min(){
        swap(a[0],a[N-1]);
        swap(event[0],event[N-1]);
        int e=event[N-1];
        double t=a[N-1];
        N--;
        heapify(0);
        if(e==1){
            double receive = t+random(50,1000)/1000.0;
            insert(receive,0);
            double next = t+T*1.0/100;
            insert(next,1);
            if(packets.size()==0)packets.push(make_pair(receive,1));
            else packets.push(make_pair(receive,0));
        }
        else if(e==0){
            //if(packets.top().first==t)cout<<1<<"\n";
            if(packets.size()>1){
                cout<<"Received with ERROR :( at time "<<packets.top().first<<"\n";
                packets.pop();
            }
            else {
                if(packets.top().second==1)cout<<"Received without ERROR :) at time "<<packets.top().first<<"\n";
                else cout<<"Received with ERROR :( at time "<<packets.top().first<<"\n";
                packets.pop();
            }
        }
        else {
            cout<<"Simulation END event at time "<<t<<"\n";
        }
        //cout<<N<<"\n";
        return e;
    }

    void print(){
        for(int i=0; i<N; i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }

};