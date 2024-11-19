#include<bits/stdc++.h>
using namespace std;

int func(vector<int>&arr,int target,int n){
    int count=0;
    int sum=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(sum<=target){
            sum+=arr[i];
            count++;
        }
    }
    return count;



}
int main(){
    int n,target;
    cin>>n>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result=func(arr,target,n);
    cout<<"result is:"<<result;

}