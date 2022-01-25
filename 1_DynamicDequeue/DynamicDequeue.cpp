#include<iostream>
#include"DynamicDequeue.h"


DynamicDequeue::DynamicDequeue(){
    N=INIT_SIZE;
    f=0;
    r=0;
    A = new double [N];
}

bool DynamicDequeue::isEmpty(){
    if(f==r)return true;
    return false;
}

bool DynamicDequeue::isFull(){
    if(f==(r+1)%N)return true;
    return false;
}

void DynamicDequeue::grow(){
    r=N;
    //N=nextSizeLinear();
    N=nextSizeExponential();
    double *A_new = new double [N];
    for(int i=0; i<r; i++){
        A_new[i]=A[(i+f)%r];
    }
    f=0;
    delete A;
    A=A_new;
}

unsigned int DynamicDequeue::size(){
    return (r-f+N)%N;
}

void DynamicDequeue::insertFront(double x){
    if(this->isFull())grow();
    if(f==0)f=N-1;
    else f=f-1;
    A[f]=x;
}

void DynamicDequeue::insertRear(double x){
    if(this->isFull())grow();
    A[r]=x;
    if(r==N-1)r=0;
    else r=r+1;
}

bool DynamicDequeue::removeFront(double *x){
    if(this->isEmpty())return false;
    *x = A[f];
    if(f==N-1)f=0;
    else f=f+1;
    return true;
}

bool DynamicDequeue::removeRear(double *x){
    if(this->isEmpty())return false;
    if(r==0)r=N-1;
    else r=r-1;
    *x = A[r];
    return true;
}

bool DynamicDequeue::front(double *x){
    if(this->isEmpty())return false;
    *x = A[f];
    return true;
}

bool DynamicDequeue::rear(double *x){
    if(this->isEmpty())return false;
    if(r==0)x=&A[N-1];
    else *x = A[r-1];
    return true;
}