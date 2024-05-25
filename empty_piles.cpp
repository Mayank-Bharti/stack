#include <bits/stdc++.h>
using namespace std;

bool predicate(int mid,int h,vector<int>&coins){
  int moves=0;
  for(int i=0;i<coins.size();i++){
    if(coins[i]%mid==0){
      moves+=coins[i]/mid;
    }
    else{
      moves+=coins[i]/mid+1;
    }
  }
  if(moves>h){
    return true;
  }
  else{
    return false;
  }
}

int main() {
  int n,h;
  cin>>n>>h;
  vector<int>coins(n);
  for(int i=0;i<n;i++){
    cin>>coins[i];
  }
  int l=0;
  int r=*max_element(coins.begin(),coins.end());
  while(l+1<r){
    int mid=l+(r-l)/2;
    if(predicate(mid,h,coins)){
      l=mid;
    }
    else{
      r=mid;
    }
  }
  cout<<r;

 
  return 0;

}