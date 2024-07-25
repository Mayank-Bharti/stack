#include<iostream>
#include<vector>
using namespace std;
void minimax(vector<int> &arr){
    int mini=arr[0];
    int maxi=arr[arr.size()-1];
    for(int i=0;i<arr.size();i++){
        if(mini>arr[i]){
            mini=arr[i];
        }
        if(maxi<arr[i]){
            maxi=arr[i];
        }
    }
    cout<<"minimum and maximum: "<<mini<<" "<<maxi<<endl;
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
    minimax(arr);
}