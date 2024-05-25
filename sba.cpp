#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int>arr(n);
   for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

  int l=-1;
  int r=n;
  while(l+1<r){
    int mid=l+(r-l)/2;
      if(arr[mid]==0){
        l=mid;
      }
      else{
        r=mid;
      }
  }
  cout<<r<<"\t"<<l<<endl;


  return 0;

}