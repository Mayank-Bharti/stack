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
    int k;
    cout<<"enter any index from which want to  rotate"<<endl;
    cin>>k;
     cout<<"left rotated array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[(i+k)%n]<<"\t";
    }
      cout<<endl<<"right rotated array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[(n+i-k)%n]<<"\t";
    }
}