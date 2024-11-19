#include<bits/stdc++.h>
using namespace std;

int count(int dist,vector<int>&arr){
    int cow=1;
    int j=arr[0];
    for(int i=0;i<arr.size();i++){
        if(arr[i]-j>=dist){
           cow++;
           j=arr[i];
        }
    }
    return cow;
}

int main(){
    int n;
    int c;
    cin>>n>>c;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=1;
    int r=arr[n-1]-arr[0];
    while(l<=r){
        int mid=l+(r-l)/2;
        int countcows=count(mid,arr);
        if(countcows>=c){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<r<<endl;
    return 0;
}