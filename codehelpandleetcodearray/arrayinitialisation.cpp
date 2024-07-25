//using fill_n command , we can initialise entire array with any number
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[5];
    //using fill_n command
    fill_n(arr,5,1);
     for(int i=0;i<5;i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;

    //this is normal method 
     for(int i=0;i<5;i++){
        arr[i]={2};
        cout<<arr[i]<<"\t";
    }
}