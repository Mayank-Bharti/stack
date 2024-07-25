//concept: a) always element of last index is less than element of first index
//b)if count<=1 in condition arr[i-1]>arr[i] or arr[arr.size()-1]>arr[0]-----then it always sorted or rotated
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"enter size of vector"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"enter value of array"<< endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count=0;
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            count++;
        }
    }
    if(arr[n-1]>arr[0]){
        count++;
    }
    if(count<=1){
        cout<<"it is rotated and sorted"<<endl;
    }
    else{
        cout<<"it is not rotated and sorted"<<endl;
    }
}