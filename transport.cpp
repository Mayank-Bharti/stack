#include <bits/stdc++.h>
using namespace std;

bool predicate(vector<int>&arr,int mid,int n,int bus,int cap){
  int req_bus=1;
  int i=0,curr_cap=1,f=arr[0];
  while(i<n){
    if(curr_cap>cap||arr[i]-f>mid){
      req_bus++;
      curr_cap=1;
      f=arr[i];
    }
    curr_cap++;
    i++;
  }
  if(req_bus>bus){
    return 1;
  }
  else{
    return 0;
  }
}

int main() {
  int n,bus,cap;
  cin>>n>>bus>>cap;
  vector<int>arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  sort(arr.begin(),arr.end());
   int l=-1,r=*max_element(arr.begin(),arr.end());
   while(l+1<r){
     int mid=l+(r-l)/2;
     if(predicate(arr,mid,n,bus,cap)){
       l=mid;
     }
     else{
       r=mid;
     }
   }
   cout<<r;
   

  return 0;

}