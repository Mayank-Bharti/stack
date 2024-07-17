#include<iostream>
#include<vector>
using namespace std;
bool found(vector<int> &arr,int key){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;

}
int main(){
    int n;
    cout<<"enter size of vector"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"enter value of array"<< endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter key to find:"<<endl;
    int key;
    cin>>key;
    
    if(found(arr,key)){
        cout<<"key is found"<<endl;
    }
    else{
        cout<<"key is not found"<<endl;
    }
}