#include"DynamicDequeue.h"
#include<bits/stdc++.h>
#include<fstream>

using namespace std;

int main(){
    DynamicDequeue DD = DynamicDequeue();



    /*string cmd;

    while(true){
        cin>>cmd;

        if(cmd=="q")break;
        else if(cmd=="if"){
            double x;
            cin>>x;
            DD.insertFront(x);
        }
        else if(cmd=="rf"){
            double x;
            if(DD.removeFront(&x))cout<<x<<"\n";
            else cout<<"Empty\n";
        }
        else if(cmd=="ir"){
            double x;
            cin>>x;
            DD.insertRear(x);
        }
        else if(cmd=="rr"){
            double x;
            if(DD.removeRear(&x))cout<<x<<"\n";
            else cout<<"Empty\n";
        }
        else if(cmd=="fr"){
            double x;
            if(DD.front(&x))cout<<x<<"\n";
            else cout<<"Empty\n";
        }
        else if(cmd=="re"){
            double x;
            if(DD.rear(&x))cout<<x<<"\n";
            else cout<<"Empty\n";
        }
        else cout<<"Invalid Command\n";
    }*/
    

    int n=1;
    double tim[20];
    for(int i=0; i<20; i++){
        
        clock_t start,end;

        start = clock();

        for(int j=0; j<n; j++){
            DD.insertFront(1);
            DD.insertRear(2);
        }
        n*=2;
        end = clock();

        double time_taken = double(end-start)/double(CLOCKS_PER_SEC);
        tim[i]=time_taken;
    }
    
    
    ofstream myoutput;
    //myoutput.open("linear.txt");        // output of time using nextSizeLinear()
    myoutput.open("expo.txt");        // output of time using nextSizeExponential()


    for(int i=0; i<20; i++){
        myoutput<<tim[i]<<" ";
    }
    
    myoutput.close();

    return 0;
}