#include<iostream>
#include<stack>
using namespace std;
class twostack {
    int *arr;
    int top1;
    int top2;
    int size;
public:
//initialize two stack
twostack(int s){
    this ->size =s;
    top1=-1;
    top2=s;
    arr = new int[s];
}
//push in stack 1

void push1(int num){
    if(top2-top1>1){
        top1++;
        arr[top1]=num;
    }
    else{
        cout<<"stack over flow";
    }

}
//push in stack 2
void push2(int num){
     if(top2-top1>1){
        top2--;
        arr[top2]=num;
    }
    else{
        cout<<"stack over flow";
    }

}
//pop in stack 1
int  pop1(){
    if(top1>-1){
        int ans=arr[top1];
        top1--;
        return ans;
    }
    else{
        cout<<"stack under flow";
    }
}
//pop in stack 2
int pop2(){
      if(top1<size){
        int ans=arr[top2];
        top2++;
        return ans;
    }
    else{
        cout<<"stack under flow";
    }

}
   ~twostack() {
        delete[] arr;
    }
};
int main() {
    // Create a two-stack instance with size 10
    twostack ts(10);
    for(int i=0;i<5;i++){
        ts.push1(i);
    }
     for(int i=10;i>1;i--){
        ts.push2(i);
    }
    cout << "Popped from stack 1: " << ts.pop1() << endl; // Should print 6 or show overflow message
    cout << "Popped from stack 2: " << ts.pop2() << endl; // Should print 25

    return 0;
}